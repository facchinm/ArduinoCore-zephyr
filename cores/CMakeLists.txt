# SPDX-License-Identifier: Apache-2.0

add_subdirectory(arduino)

zephyr_include_directories(../../ArduinoCore-API/)

if(NOT DEFINED ARDUINO_BUILD_PATH)
zephyr_sources(../../ArduinoCore-API/api/CanMsg.cpp)
zephyr_sources(../../ArduinoCore-API/api/CanMsgRingbuffer.cpp)
zephyr_sources(../../ArduinoCore-API/api/Common.cpp)
zephyr_sources(../../ArduinoCore-API/api/IPAddress.cpp)
zephyr_sources(../../ArduinoCore-API/api/Print.cpp)
zephyr_sources(../../ArduinoCore-API/api/Stream.cpp)
zephyr_sources(../../ArduinoCore-API/api/String.cpp)
endif()
