#!/usr/bin/env python3

# Copyright (c) Arduino s.r.l. and/or its affiliated companies
# SPDX-License-Identifier: Apache-2.0

# Live viewer for the CameraSerialStream example sketch.
#
# Reads framed camera frames from the board's USB serial port and shows them
# in a window. The frame rate, throughput, dropped frame count and resync
# count are shown in the window title. The resolution and pixel format are
# read from each frame header, so switching the sketch to a different mode
# needs no change here.
#
# Usage:
#   pip install -r requirements.txt
#   ./CameraSerialViewer.py [-p PORT] [-c CREDITS] [-s SCALE] [-b]
#
# Press q or ESC in the window to quit.

import argparse
import array
import struct
import sys
import time
import tkinter as tk

import serial
import serial.tools.list_ports
from PIL import Image, ImageTk

SYNC = b"\xd5\xaa\x96\x5a"
HEADER = struct.Struct("<4sBBBBHHII")
VERSION = 1

FMT_RGB565 = 0
FMT_GRAYSCALE = 1
BYTES_PER_PIXEL = {FMT_RGB565: 2, FMT_GRAYSCALE: 1}

FLAG_LITTLE_ENDIAN = 1 << 0

CMD_REQUEST = b"R"

ARDUINO_VID = 0x2341

# Short port timeout so the window stays responsive between reads, and a
# longer deadline, reset on every byte, before we re-request. It only expires
# when the stream stalls completely, so it does not need to cover a frame.
READ_TIMEOUT = 0.05
IDLE_TIMEOUT = 1.0

SEQ_MASK = 0xFFFFFFFF


class Quit(Exception):
    """Raised from the read path when the user closes the window."""


def find_port():
    """Pick the board's CDC port, never some other USB device on the bus."""
    ports = list(serial.tools.list_ports.comports())
    arduino = [p for p in ports if p.vid == ARDUINO_VID]

    if not arduino:
        print("No Arduino board found on the USB bus.", file=sys.stderr)
        print("The CDC port only appears once a sketch calls Serial.begin(), so "
              "check that CameraSerialStream is uploaded and running.", file=sys.stderr)
        if ports:
            print("\nPorts that are present:", file=sys.stderr)
            for p in ports:
                vid = f"{p.vid:04x}:{p.pid:04x}" if p.vid else "no USB id"
                print(f"  {p.device}  ({vid})  {p.description}", file=sys.stderr)
        sys.exit("\nPass one explicitly with -p if you know which it is.")

    if len(arduino) > 1:
        print(f"Multiple Arduino boards found, using {arduino[0].device} "
              f"(override with -p)")
    return arduino[0].device


def read_exactly(port, size, pump):
    """Read exactly size bytes, pumping the UI while waiting for them."""
    chunks = []
    remaining = size
    deadline = time.monotonic() + IDLE_TIMEOUT

    while remaining:
        data = port.read(remaining)
        if data:
            chunks.append(data)
            remaining -= len(data)
            deadline = time.monotonic() + IDLE_TIMEOUT
        elif time.monotonic() >= deadline:
            raise TimeoutError(f"wanted {size} bytes, got {size - remaining}")
        pump()

    return b"".join(chunks)


def read_header(port, stats, pump):
    """Scan for the sync word, then return a validated frame header."""
    window = b""
    while True:
        window = (window + read_exactly(port, 1, pump))[-len(SYNC):]
        if window != SYNC:
            # Only count bytes discarded once the window is primed.
            if len(window) == len(SYNC):
                stats["skipped"] += 1
            continue

        fields = HEADER.unpack(SYNC + read_exactly(port, HEADER.size - len(SYNC), pump))
        _, version, fmt, flags, _, width, height, length, seq = fields
        bpp = BYTES_PER_PIXEL.get(fmt)
        if version == VERSION and bpp and length == width * height * bpp:
            return fmt, flags, width, height, length, seq

        # A sync word that turned up inside pixel data. Keep scanning.
        stats["resyncs"] += 1
        window = b""


def decode(payload, fmt, flags, width, height):
    if fmt == FMT_GRAYSCALE:
        return Image.frombuffer("L", (width, height), payload, "raw", "L", 0, 1)

    if not flags & FLAG_LITTLE_ENDIAN:
        # The sensor emits big-endian RGB565; Pillow expects little-endian.
        pixels = array.array("H", payload)
        pixels.byteswap()
        payload = pixels.tobytes()

    # "BGR;16" is Pillow's name for packed 565 with red in the high bits.
    return Image.frombuffer("RGB", (width, height), payload, "raw", "BGR;16", 0, 1)


def main():
    parser = argparse.ArgumentParser(
        description="Live viewer for the CameraSerialStream example sketch.")
    parser.add_argument("-p", "--port", help="serial port (default: autodetect)")
    parser.add_argument("-c", "--credits", type=int, default=2,
                        help="frame requests kept outstanding (default: 2)")
    parser.add_argument("-s", "--scale", type=float, default=2.0,
                        help="display scale factor (default: 2.0)")
    parser.add_argument("-b", "--bench", action="store_true",
                        help="measure the link only: no decode, no display")
    args = parser.parse_args()

    if args.credits < 1:
        sys.exit("--credits must be at least 1, or the board is never asked for a frame.")

    port_name = args.port or find_port()

    root = tk.Tk()
    root.title("Arduino Camera - waiting for frames")
    label = tk.Label(root)
    label.pack()

    running = True

    def stop(event=None):
        nonlocal running
        running = False

    root.protocol("WM_DELETE_WINDOW", stop)
    root.bind("<Key-q>", stop)
    root.bind("<Escape>", stop)

    def pump():
        """Service the window; raise Quit once the user has asked to leave."""
        nonlocal running
        try:
            root.update()
        except tk.TclError:
            running = False
        if not running:
            raise Quit

    stats = {"frames": 0, "bytes": 0, "dropped": 0, "resyncs": 0, "skipped": 0,
             "read_s": 0.0, "render_s": 0.0}
    last_seq = None
    tick, shown = time.monotonic(), 0
    width = height = 0

    with serial.Serial(port_name, baudrate=115200, timeout=READ_TIMEOUT) as port:
        print(f"Connected to {port_name}, press q to quit")
        port.reset_input_buffer()
        port.write(CMD_REQUEST * args.credits)

        while True:
            frame_start = time.monotonic()
            try:
                fmt, flags, width, height, length, seq = read_header(port, stats, pump)
                payload = read_exactly(port, length, pump)
            except Quit:
                break
            except TimeoutError as e:
                print(f"Timed out ({e}), re-requesting")
                port.reset_input_buffer()
                port.write(CMD_REQUEST * args.credits)
                continue

            port.write(CMD_REQUEST)

            if last_seq is not None:
                stats["dropped"] += (seq - last_seq - 1) & SEQ_MASK
            last_seq = seq

            stats["frames"] += 1
            stats["bytes"] += length + HEADER.size
            stats["read_s"] += time.monotonic() - frame_start
            shown += 1

            if not args.bench:
                render_start = time.monotonic()

                image = decode(payload, fmt, flags, width, height)
                if args.scale != 1.0:
                    image = image.resize((int(width * args.scale),
                                          int(height * args.scale)), Image.NEAREST)

                # The reference on the label keeps tkinter from collecting it.
                photo = ImageTk.PhotoImage(image)
                label.configure(image=photo)
                label.image = photo

                stats["render_s"] += time.monotonic() - render_start

            elapsed = time.monotonic() - tick
            if elapsed >= 1.0:
                title = (f"Arduino Camera - {shown / elapsed:.1f} fps  "
                         f"{stats['bytes'] / elapsed / 1e6:.2f} MB/s  "
                         f"{width}x{height}  "
                         f"drop {stats['dropped']}  resync {stats['resyncs']}")
                split = (f"  read {stats['read_s'] / shown * 1e3:.0f} ms/frame, "
                         f"render {stats['render_s'] / shown * 1e3:.0f} ms/frame")
                root.title(title)
                print(title + split)
                tick, shown = time.monotonic(), 0
                stats["bytes"] = stats["read_s"] = stats["render_s"] = 0

            try:
                pump()
            except Quit:
                break

    print(f"Received {stats['frames']} frames, {stats['dropped']} dropped, "
          f"{stats['resyncs']} resyncs, {stats['skipped']} stray bytes skipped")


if __name__ == "__main__":
    main()
