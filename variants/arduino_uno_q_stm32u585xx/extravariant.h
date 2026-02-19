#define SERIAL2_TOKEN Serial2

// Helper macros
#define CAT_(a,b) a##b
#define CAT(a,b) CAT_(a,b)
#define IS_SERIAL2(x) CAT(IS_SERIAL2_, x)

// Marker for the allowed token
#define IS_SERIAL2_Serial2 1

#if defined(ARDUINO_LIBRARY_DISCOVERY_PHASE) && (ARDUINO_LIBRARY_DISCOVERY_PHASE == 0)
#if __has_include("Arduino_RouterBridge.h")
#include "Arduino_RouterBridge.h"
#if defined(UNO_Q_SERIAL_RPC) && !IS_SERIAL2(UNO_Q_SERIAL_RPC)
#error Please update Arduino_RouterBridge
#endif
#endif
#else
#include "Arduino_RouterBridge.h"
#endif

#ifndef ZEPHYR_INCLUDE_DRIVERS_UART_H_
#define Serial Monitor
#endif