# SPDX-License-Identifier: Apache-2.0
zephyr_include_directories(.)
zephyr_include_directories(../../variants)

if(NOT DEFINED ARDUINO_BUILD_PATH)

zephyr_sources(zephyrSerial.cpp)
zephyr_sources(zephyrCommon.cpp)
zephyr_sources(USB.cpp)
zephyr_sources(itoa.cpp)

if(DEFINED CONFIG_ARDUINO_ENTRY)
zephyr_sources(main.cpp)
zephyr_sources(threads.cpp)
endif()

endif()

