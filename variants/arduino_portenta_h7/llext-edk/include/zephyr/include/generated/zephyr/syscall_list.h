/* auto-generated by gen_syscalls.py, don't edit */

#ifndef ZEPHYR_SYSCALL_LIST_H
#define ZEPHYR_SYSCALL_LIST_H

#define K_SYSCALL_CHARGER_CHARGE_ENABLE 0
#define K_SYSCALL_CHARGER_GET_PROP 1
#define K_SYSCALL_CHARGER_SET_PROP 2
#define K_SYSCALL_DEVICE_GET_BINDING 3
#define K_SYSCALL_DEVICE_GET_BY_DT_NODELABEL 4
#define K_SYSCALL_DEVICE_INIT 5
#define K_SYSCALL_DEVICE_IS_READY 6
#define K_SYSCALL_ENTROPY_GET_ENTROPY 7
#define K_SYSCALL_FLASH_ERASE 8
#define K_SYSCALL_FLASH_EX_OP 9
#define K_SYSCALL_FLASH_FILL 10
#define K_SYSCALL_FLASH_FLATTEN 11
#define K_SYSCALL_FLASH_GET_PAGE_COUNT 12
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_IDX 13
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_OFFS 14
#define K_SYSCALL_FLASH_GET_PARAMETERS 15
#define K_SYSCALL_FLASH_GET_WRITE_BLOCK_SIZE 16
#define K_SYSCALL_FLASH_READ 17
#define K_SYSCALL_FLASH_READ_JEDEC_ID 18
#define K_SYSCALL_FLASH_SFDP_READ 19
#define K_SYSCALL_FLASH_WRITE 20
#define K_SYSCALL_GPIO_GET_PENDING_INT 21
#define K_SYSCALL_GPIO_PIN_CONFIGURE 22
#define K_SYSCALL_GPIO_PIN_GET_CONFIG 23
#define K_SYSCALL_GPIO_PIN_INTERRUPT_CONFIGURE 24
#define K_SYSCALL_GPIO_PORT_CLEAR_BITS_RAW 25
#define K_SYSCALL_GPIO_PORT_GET_DIRECTION 26
#define K_SYSCALL_GPIO_PORT_GET_RAW 27
#define K_SYSCALL_GPIO_PORT_SET_BITS_RAW 28
#define K_SYSCALL_GPIO_PORT_SET_MASKED_RAW 29
#define K_SYSCALL_GPIO_PORT_TOGGLE_BITS 30
#define K_SYSCALL_HWINFO_CLEAR_RESET_CAUSE 31
#define K_SYSCALL_HWINFO_GET_DEVICE_EUI64 32
#define K_SYSCALL_HWINFO_GET_DEVICE_ID 33
#define K_SYSCALL_HWINFO_GET_RESET_CAUSE 34
#define K_SYSCALL_HWINFO_GET_SUPPORTED_RESET_CAUSE 35
#define K_SYSCALL_I2C_CONFIGURE 36
#define K_SYSCALL_I2C_GET_CONFIG 37
#define K_SYSCALL_I2C_RECOVER_BUS 38
#define K_SYSCALL_I2C_TARGET_DRIVER_REGISTER 39
#define K_SYSCALL_I2C_TARGET_DRIVER_UNREGISTER 40
#define K_SYSCALL_I2C_TRANSFER 41
#define K_SYSCALL_K_BUSY_WAIT 42
#define K_SYSCALL_K_CONDVAR_BROADCAST 43
#define K_SYSCALL_K_CONDVAR_INIT 44
#define K_SYSCALL_K_CONDVAR_SIGNAL 45
#define K_SYSCALL_K_CONDVAR_WAIT 46
#define K_SYSCALL_K_EVENT_CLEAR 47
#define K_SYSCALL_K_EVENT_INIT 48
#define K_SYSCALL_K_EVENT_POST 49
#define K_SYSCALL_K_EVENT_SET 50
#define K_SYSCALL_K_EVENT_SET_MASKED 51
#define K_SYSCALL_K_EVENT_WAIT 52
#define K_SYSCALL_K_EVENT_WAIT_ALL 53
#define K_SYSCALL_K_FLOAT_DISABLE 54
#define K_SYSCALL_K_FLOAT_ENABLE 55
#define K_SYSCALL_K_FUTEX_WAIT 56
#define K_SYSCALL_K_FUTEX_WAKE 57
#define K_SYSCALL_K_IS_PREEMPT_THREAD 58
#define K_SYSCALL_K_MSGQ_ALLOC_INIT 59
#define K_SYSCALL_K_MSGQ_GET 60
#define K_SYSCALL_K_MSGQ_GET_ATTRS 61
#define K_SYSCALL_K_MSGQ_NUM_FREE_GET 62
#define K_SYSCALL_K_MSGQ_NUM_USED_GET 63
#define K_SYSCALL_K_MSGQ_PEEK 64
#define K_SYSCALL_K_MSGQ_PEEK_AT 65
#define K_SYSCALL_K_MSGQ_PURGE 66
#define K_SYSCALL_K_MSGQ_PUT 67
#define K_SYSCALL_K_MUTEX_INIT 68
#define K_SYSCALL_K_MUTEX_LOCK 69
#define K_SYSCALL_K_MUTEX_UNLOCK 70
#define K_SYSCALL_K_OBJECT_ACCESS_GRANT 71
#define K_SYSCALL_K_OBJECT_ALLOC 72
#define K_SYSCALL_K_OBJECT_ALLOC_SIZE 73
#define K_SYSCALL_K_OBJECT_RELEASE 74
#define K_SYSCALL_K_PIPE_ALLOC_INIT 75
#define K_SYSCALL_K_PIPE_BUFFER_FLUSH 76
#define K_SYSCALL_K_PIPE_FLUSH 77
#define K_SYSCALL_K_PIPE_GET 78
#define K_SYSCALL_K_PIPE_PUT 79
#define K_SYSCALL_K_PIPE_READ_AVAIL 80
#define K_SYSCALL_K_PIPE_WRITE_AVAIL 81
#define K_SYSCALL_K_POLL 82
#define K_SYSCALL_K_POLL_SIGNAL_CHECK 83
#define K_SYSCALL_K_POLL_SIGNAL_INIT 84
#define K_SYSCALL_K_POLL_SIGNAL_RAISE 85
#define K_SYSCALL_K_POLL_SIGNAL_RESET 86
#define K_SYSCALL_K_QUEUE_ALLOC_APPEND 87
#define K_SYSCALL_K_QUEUE_ALLOC_PREPEND 88
#define K_SYSCALL_K_QUEUE_CANCEL_WAIT 89
#define K_SYSCALL_K_QUEUE_GET 90
#define K_SYSCALL_K_QUEUE_INIT 91
#define K_SYSCALL_K_QUEUE_IS_EMPTY 92
#define K_SYSCALL_K_QUEUE_PEEK_HEAD 93
#define K_SYSCALL_K_QUEUE_PEEK_TAIL 94
#define K_SYSCALL_K_SCHED_CURRENT_THREAD_QUERY 95
#define K_SYSCALL_K_SEM_COUNT_GET 96
#define K_SYSCALL_K_SEM_GIVE 97
#define K_SYSCALL_K_SEM_INIT 98
#define K_SYSCALL_K_SEM_RESET 99
#define K_SYSCALL_K_SEM_TAKE 100
#define K_SYSCALL_K_SLEEP 101
#define K_SYSCALL_K_STACK_ALLOC_INIT 102
#define K_SYSCALL_K_STACK_POP 103
#define K_SYSCALL_K_STACK_PUSH 104
#define K_SYSCALL_K_STR_OUT 105
#define K_SYSCALL_K_THREAD_ABORT 106
#define K_SYSCALL_K_THREAD_CREATE 107
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_GET 108
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_SET 109
#define K_SYSCALL_K_THREAD_DEADLINE_SET 110
#define K_SYSCALL_K_THREAD_JOIN 111
#define K_SYSCALL_K_THREAD_NAME_COPY 112
#define K_SYSCALL_K_THREAD_NAME_SET 113
#define K_SYSCALL_K_THREAD_PRIORITY_GET 114
#define K_SYSCALL_K_THREAD_PRIORITY_SET 115
#define K_SYSCALL_K_THREAD_RESUME 116
#define K_SYSCALL_K_THREAD_STACK_ALLOC 117
#define K_SYSCALL_K_THREAD_STACK_FREE 118
#define K_SYSCALL_K_THREAD_STACK_SPACE_GET 119
#define K_SYSCALL_K_THREAD_START 120
#define K_SYSCALL_K_THREAD_SUSPEND 121
#define K_SYSCALL_K_THREAD_TIMEOUT_EXPIRES_TICKS 122
#define K_SYSCALL_K_THREAD_TIMEOUT_REMAINING_TICKS 123
#define K_SYSCALL_K_TIMER_EXPIRES_TICKS 124
#define K_SYSCALL_K_TIMER_REMAINING_TICKS 125
#define K_SYSCALL_K_TIMER_START 126
#define K_SYSCALL_K_TIMER_STATUS_GET 127
#define K_SYSCALL_K_TIMER_STATUS_SYNC 128
#define K_SYSCALL_K_TIMER_STOP 129
#define K_SYSCALL_K_TIMER_USER_DATA_GET 130
#define K_SYSCALL_K_TIMER_USER_DATA_SET 131
#define K_SYSCALL_K_UPTIME_TICKS 132
#define K_SYSCALL_K_USLEEP 133
#define K_SYSCALL_K_WAKEUP 134
#define K_SYSCALL_K_YIELD 135
#define K_SYSCALL_LLEXT_GET_FN_TABLE 136
#define K_SYSCALL_LOG_BUFFERED_CNT 137
#define K_SYSCALL_LOG_FILTER_SET 138
#define K_SYSCALL_LOG_FRONTEND_FILTER_SET 139
#define K_SYSCALL_LOG_PANIC 140
#define K_SYSCALL_LOG_PROCESS 141
#define K_SYSCALL_NET_ADDR_NTOP 142
#define K_SYSCALL_NET_ADDR_PTON 143
#define K_SYSCALL_NET_ETH_GET_PTP_CLOCK_BY_INDEX 144
#define K_SYSCALL_NET_IF_GET_BY_INDEX 145
#define K_SYSCALL_NET_IF_IPV4_ADDR_ADD_BY_INDEX 146
#define K_SYSCALL_NET_IF_IPV4_ADDR_LOOKUP_BY_INDEX 147
#define K_SYSCALL_NET_IF_IPV4_ADDR_RM_BY_INDEX 148
#define K_SYSCALL_NET_IF_IPV4_SET_GW_BY_INDEX 149
#define K_SYSCALL_NET_IF_IPV4_SET_NETMASK_BY_ADDR_BY_INDEX 150
#define K_SYSCALL_NET_IF_IPV4_SET_NETMASK_BY_INDEX 151
#define K_SYSCALL_NET_IF_IPV6_ADDR_ADD_BY_INDEX 152
#define K_SYSCALL_NET_IF_IPV6_ADDR_LOOKUP_BY_INDEX 153
#define K_SYSCALL_NET_IF_IPV6_ADDR_RM_BY_INDEX 154
#define K_SYSCALL_RESET_LINE_ASSERT 155
#define K_SYSCALL_RESET_LINE_DEASSERT 156
#define K_SYSCALL_RESET_LINE_TOGGLE 157
#define K_SYSCALL_RESET_STATUS 158
#define K_SYSCALL_SPI_RELEASE 159
#define K_SYSCALL_SPI_TRANSCEIVE 160
#define K_SYSCALL_SYS_CACHE_DATA_FLUSH_AND_INVD_RANGE 161
#define K_SYSCALL_SYS_CACHE_DATA_FLUSH_RANGE 162
#define K_SYSCALL_SYS_CACHE_DATA_INVD_RANGE 163
#define K_SYSCALL_SYS_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET 164
#define K_SYSCALL_SYS_CSRAND_GET 165
#define K_SYSCALL_SYS_RAND_GET 166
#define K_SYSCALL_UART_CONFIGURE 167
#define K_SYSCALL_UART_CONFIG_GET 168
#define K_SYSCALL_UART_DRV_CMD 169
#define K_SYSCALL_UART_ERR_CHECK 170
#define K_SYSCALL_UART_IRQ_ERR_DISABLE 171
#define K_SYSCALL_UART_IRQ_ERR_ENABLE 172
#define K_SYSCALL_UART_IRQ_IS_PENDING 173
#define K_SYSCALL_UART_IRQ_RX_DISABLE 174
#define K_SYSCALL_UART_IRQ_RX_ENABLE 175
#define K_SYSCALL_UART_IRQ_TX_DISABLE 176
#define K_SYSCALL_UART_IRQ_TX_ENABLE 177
#define K_SYSCALL_UART_IRQ_UPDATE 178
#define K_SYSCALL_UART_LINE_CTRL_GET 179
#define K_SYSCALL_UART_LINE_CTRL_SET 180
#define K_SYSCALL_UART_POLL_IN 181
#define K_SYSCALL_UART_POLL_IN_U16 182
#define K_SYSCALL_UART_POLL_OUT 183
#define K_SYSCALL_UART_POLL_OUT_U16 184
#define K_SYSCALL_UART_RX_DISABLE 185
#define K_SYSCALL_UART_RX_ENABLE 186
#define K_SYSCALL_UART_RX_ENABLE_U16 187
#define K_SYSCALL_UART_TX 188
#define K_SYSCALL_UART_TX_ABORT 189
#define K_SYSCALL_UART_TX_U16 190
#define K_SYSCALL_ZEPHYR_FPUTC 191
#define K_SYSCALL_ZEPHYR_FWRITE 192
#define K_SYSCALL_ZEPHYR_READ_STDIN 193
#define K_SYSCALL_ZEPHYR_WRITE_STDOUT 194
#define K_SYSCALL_ZSOCK_ACCEPT 195
#define K_SYSCALL_ZSOCK_BIND 196
#define K_SYSCALL_ZSOCK_CLOSE 197
#define K_SYSCALL_ZSOCK_CONNECT 198
#define K_SYSCALL_ZSOCK_FCNTL_IMPL 199
#define K_SYSCALL_ZSOCK_GETHOSTNAME 200
#define K_SYSCALL_ZSOCK_GETPEERNAME 201
#define K_SYSCALL_ZSOCK_GETSOCKNAME 202
#define K_SYSCALL_ZSOCK_GETSOCKOPT 203
#define K_SYSCALL_ZSOCK_GET_CONTEXT_OBJECT 204
#define K_SYSCALL_ZSOCK_INET_PTON 205
#define K_SYSCALL_ZSOCK_IOCTL_IMPL 206
#define K_SYSCALL_ZSOCK_LISTEN 207
#define K_SYSCALL_ZSOCK_POLL 208
#define K_SYSCALL_ZSOCK_RECVFROM 209
#define K_SYSCALL_ZSOCK_RECVMSG 210
#define K_SYSCALL_ZSOCK_SELECT 211
#define K_SYSCALL_ZSOCK_SENDMSG 212
#define K_SYSCALL_ZSOCK_SENDTO 213
#define K_SYSCALL_ZSOCK_SETSOCKOPT 214
#define K_SYSCALL_ZSOCK_SHUTDOWN 215
#define K_SYSCALL_ZSOCK_SOCKET 216
#define K_SYSCALL_ZSOCK_SOCKETPAIR 217
#define K_SYSCALL_Z_LOG_MSG_SIMPLE_CREATE_0 218
#define K_SYSCALL_Z_LOG_MSG_SIMPLE_CREATE_1 219
#define K_SYSCALL_Z_LOG_MSG_SIMPLE_CREATE_2 220
#define K_SYSCALL_Z_LOG_MSG_STATIC_CREATE 221
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_LOCK 222
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_UNLOCK 223
#define K_SYSCALL_Z_ZSOCK_GETADDRINFO_INTERNAL 224
#define K_SYSCALL___POSIX_CLOCK_GET_BASE 225
#define K_SYSCALL_BAD 226
#define K_SYSCALL_LIMIT 227


/* Following syscalls are not used in image */
#define K_SYSCALL_ADC_CHANNEL_SETUP 228
#define K_SYSCALL_ADC_READ 229
#define K_SYSCALL_ADC_READ_ASYNC 230
#define K_SYSCALL_ATOMIC_ADD 231
#define K_SYSCALL_ATOMIC_AND 232
#define K_SYSCALL_ATOMIC_CAS 233
#define K_SYSCALL_ATOMIC_NAND 234
#define K_SYSCALL_ATOMIC_OR 235
#define K_SYSCALL_ATOMIC_PTR_CAS 236
#define K_SYSCALL_ATOMIC_PTR_SET 237
#define K_SYSCALL_ATOMIC_SET 238
#define K_SYSCALL_ATOMIC_SUB 239
#define K_SYSCALL_ATOMIC_XOR 240
#define K_SYSCALL_AUXDISPLAY_BACKLIGHT_GET 241
#define K_SYSCALL_AUXDISPLAY_BACKLIGHT_SET 242
#define K_SYSCALL_AUXDISPLAY_BRIGHTNESS_GET 243
#define K_SYSCALL_AUXDISPLAY_BRIGHTNESS_SET 244
#define K_SYSCALL_AUXDISPLAY_CAPABILITIES_GET 245
#define K_SYSCALL_AUXDISPLAY_CLEAR 246
#define K_SYSCALL_AUXDISPLAY_CURSOR_POSITION_GET 247
#define K_SYSCALL_AUXDISPLAY_CURSOR_POSITION_SET 248
#define K_SYSCALL_AUXDISPLAY_CURSOR_SET_ENABLED 249
#define K_SYSCALL_AUXDISPLAY_CURSOR_SHIFT_SET 250
#define K_SYSCALL_AUXDISPLAY_CUSTOM_CHARACTER_SET 251
#define K_SYSCALL_AUXDISPLAY_CUSTOM_COMMAND 252
#define K_SYSCALL_AUXDISPLAY_DISPLAY_OFF 253
#define K_SYSCALL_AUXDISPLAY_DISPLAY_ON 254
#define K_SYSCALL_AUXDISPLAY_DISPLAY_POSITION_GET 255
#define K_SYSCALL_AUXDISPLAY_DISPLAY_POSITION_SET 256
#define K_SYSCALL_AUXDISPLAY_IS_BUSY 257
#define K_SYSCALL_AUXDISPLAY_POSITION_BLINKING_SET_ENABLED 258
#define K_SYSCALL_AUXDISPLAY_WRITE 259
#define K_SYSCALL_BBRAM_CHECK_INVALID 260
#define K_SYSCALL_BBRAM_CHECK_POWER 261
#define K_SYSCALL_BBRAM_CHECK_STANDBY_POWER 262
#define K_SYSCALL_BBRAM_GET_SIZE 263
#define K_SYSCALL_BBRAM_READ 264
#define K_SYSCALL_BBRAM_WRITE 265
#define K_SYSCALL_BC12_SET_RESULT_CB 266
#define K_SYSCALL_BC12_SET_ROLE 267
#define K_SYSCALL_CAN_ADD_RX_FILTER_MSGQ 268
#define K_SYSCALL_CAN_CALC_TIMING 269
#define K_SYSCALL_CAN_CALC_TIMING_DATA 270
#define K_SYSCALL_CAN_GET_BITRATE_MAX 271
#define K_SYSCALL_CAN_GET_BITRATE_MIN 272
#define K_SYSCALL_CAN_GET_CAPABILITIES 273
#define K_SYSCALL_CAN_GET_CORE_CLOCK 274
#define K_SYSCALL_CAN_GET_MAX_FILTERS 275
#define K_SYSCALL_CAN_GET_MODE 276
#define K_SYSCALL_CAN_GET_STATE 277
#define K_SYSCALL_CAN_GET_TIMING_DATA_MAX 278
#define K_SYSCALL_CAN_GET_TIMING_DATA_MIN 279
#define K_SYSCALL_CAN_GET_TIMING_MAX 280
#define K_SYSCALL_CAN_GET_TIMING_MIN 281
#define K_SYSCALL_CAN_GET_TRANSCEIVER 282
#define K_SYSCALL_CAN_RECOVER 283
#define K_SYSCALL_CAN_REMOVE_RX_FILTER 284
#define K_SYSCALL_CAN_SEND 285
#define K_SYSCALL_CAN_SET_BITRATE 286
#define K_SYSCALL_CAN_SET_BITRATE_DATA 287
#define K_SYSCALL_CAN_SET_MODE 288
#define K_SYSCALL_CAN_SET_TIMING 289
#define K_SYSCALL_CAN_SET_TIMING_DATA 290
#define K_SYSCALL_CAN_START 291
#define K_SYSCALL_CAN_STATS_GET_ACK_ERRORS 292
#define K_SYSCALL_CAN_STATS_GET_BIT0_ERRORS 293
#define K_SYSCALL_CAN_STATS_GET_BIT1_ERRORS 294
#define K_SYSCALL_CAN_STATS_GET_BIT_ERRORS 295
#define K_SYSCALL_CAN_STATS_GET_CRC_ERRORS 296
#define K_SYSCALL_CAN_STATS_GET_FORM_ERRORS 297
#define K_SYSCALL_CAN_STATS_GET_RX_OVERRUNS 298
#define K_SYSCALL_CAN_STATS_GET_STUFF_ERRORS 299
#define K_SYSCALL_CAN_STOP 300
#define K_SYSCALL_COUNTER_CANCEL_CHANNEL_ALARM 301
#define K_SYSCALL_COUNTER_GET_FREQUENCY 302
#define K_SYSCALL_COUNTER_GET_GUARD_PERIOD 303
#define K_SYSCALL_COUNTER_GET_MAX_TOP_VALUE 304
#define K_SYSCALL_COUNTER_GET_NUM_OF_CHANNELS 305
#define K_SYSCALL_COUNTER_GET_PENDING_INT 306
#define K_SYSCALL_COUNTER_GET_TOP_VALUE 307
#define K_SYSCALL_COUNTER_GET_VALUE 308
#define K_SYSCALL_COUNTER_GET_VALUE_64 309
#define K_SYSCALL_COUNTER_IS_COUNTING_UP 310
#define K_SYSCALL_COUNTER_SET_CHANNEL_ALARM 311
#define K_SYSCALL_COUNTER_SET_GUARD_PERIOD 312
#define K_SYSCALL_COUNTER_SET_TOP_VALUE 313
#define K_SYSCALL_COUNTER_START 314
#define K_SYSCALL_COUNTER_STOP 315
#define K_SYSCALL_COUNTER_TICKS_TO_US 316
#define K_SYSCALL_COUNTER_US_TO_TICKS 317
#define K_SYSCALL_DAC_CHANNEL_SETUP 318
#define K_SYSCALL_DAC_WRITE_VALUE 319
#define K_SYSCALL_DEVMUX_SELECT_GET 320
#define K_SYSCALL_DEVMUX_SELECT_SET 321
#define K_SYSCALL_DMA_CHAN_FILTER 322
#define K_SYSCALL_DMA_RELEASE_CHANNEL 323
#define K_SYSCALL_DMA_REQUEST_CHANNEL 324
#define K_SYSCALL_DMA_RESUME 325
#define K_SYSCALL_DMA_START 326
#define K_SYSCALL_DMA_STOP 327
#define K_SYSCALL_DMA_SUSPEND 328
#define K_SYSCALL_EEPROM_GET_SIZE 329
#define K_SYSCALL_EEPROM_READ 330
#define K_SYSCALL_EEPROM_WRITE 331
#define K_SYSCALL_EMUL_FUEL_GAUGE_IS_BATTERY_CUTOFF 332
#define K_SYSCALL_EMUL_FUEL_GAUGE_SET_BATTERY_CHARGING 333
#define K_SYSCALL_ESPI_CONFIG 334
#define K_SYSCALL_ESPI_FLASH_ERASE 335
#define K_SYSCALL_ESPI_GET_CHANNEL_STATUS 336
#define K_SYSCALL_ESPI_READ_FLASH 337
#define K_SYSCALL_ESPI_READ_LPC_REQUEST 338
#define K_SYSCALL_ESPI_READ_REQUEST 339
#define K_SYSCALL_ESPI_RECEIVE_OOB 340
#define K_SYSCALL_ESPI_RECEIVE_VWIRE 341
#define K_SYSCALL_ESPI_SAF_ACTIVATE 342
#define K_SYSCALL_ESPI_SAF_CONFIG 343
#define K_SYSCALL_ESPI_SAF_FLASH_ERASE 344
#define K_SYSCALL_ESPI_SAF_FLASH_READ 345
#define K_SYSCALL_ESPI_SAF_FLASH_UNSUCCESS 346
#define K_SYSCALL_ESPI_SAF_FLASH_WRITE 347
#define K_SYSCALL_ESPI_SAF_GET_CHANNEL_STATUS 348
#define K_SYSCALL_ESPI_SAF_SET_PROTECTION_REGIONS 349
#define K_SYSCALL_ESPI_SEND_OOB 350
#define K_SYSCALL_ESPI_SEND_VWIRE 351
#define K_SYSCALL_ESPI_WRITE_FLASH 352
#define K_SYSCALL_ESPI_WRITE_LPC_REQUEST 353
#define K_SYSCALL_ESPI_WRITE_REQUEST 354
#define K_SYSCALL_FLASH_SIMULATOR_GET_MEMORY 355
#define K_SYSCALL_FUEL_GAUGE_BATTERY_CUTOFF 356
#define K_SYSCALL_FUEL_GAUGE_GET_BUFFER_PROP 357
#define K_SYSCALL_FUEL_GAUGE_GET_PROP 358
#define K_SYSCALL_FUEL_GAUGE_GET_PROPS 359
#define K_SYSCALL_FUEL_GAUGE_SET_PROP 360
#define K_SYSCALL_FUEL_GAUGE_SET_PROPS 361
#define K_SYSCALL_GNSS_GET_ENABLED_SYSTEMS 362
#define K_SYSCALL_GNSS_GET_FIX_RATE 363
#define K_SYSCALL_GNSS_GET_NAVIGATION_MODE 364
#define K_SYSCALL_GNSS_GET_PERIODIC_CONFIG 365
#define K_SYSCALL_GNSS_GET_SUPPORTED_SYSTEMS 366
#define K_SYSCALL_GNSS_SET_ENABLED_SYSTEMS 367
#define K_SYSCALL_GNSS_SET_FIX_RATE 368
#define K_SYSCALL_GNSS_SET_NAVIGATION_MODE 369
#define K_SYSCALL_GNSS_SET_PERIODIC_CONFIG 370
#define K_SYSCALL_HWSPINLOCK_GET_MAX_ID 371
#define K_SYSCALL_HWSPINLOCK_LOCK 372
#define K_SYSCALL_HWSPINLOCK_TRYLOCK 373
#define K_SYSCALL_HWSPINLOCK_UNLOCK 374
#define K_SYSCALL_I2S_BUF_READ 375
#define K_SYSCALL_I2S_BUF_WRITE 376
#define K_SYSCALL_I2S_CONFIGURE 377
#define K_SYSCALL_I2S_TRIGGER 378
#define K_SYSCALL_I3C_DO_CCC 379
#define K_SYSCALL_I3C_TRANSFER 380
#define K_SYSCALL_IPM_COMPLETE 381
#define K_SYSCALL_IPM_MAX_DATA_SIZE_GET 382
#define K_SYSCALL_IPM_MAX_ID_VAL_GET 383
#define K_SYSCALL_IPM_SEND 384
#define K_SYSCALL_IPM_SET_ENABLED 385
#define K_SYSCALL_IVSHMEM_ENABLE_INTERRUPTS 386
#define K_SYSCALL_IVSHMEM_GET_ID 387
#define K_SYSCALL_IVSHMEM_GET_MAX_PEERS 388
#define K_SYSCALL_IVSHMEM_GET_MEM 389
#define K_SYSCALL_IVSHMEM_GET_OUTPUT_MEM_SECTION 390
#define K_SYSCALL_IVSHMEM_GET_PROTOCOL 391
#define K_SYSCALL_IVSHMEM_GET_RW_MEM_SECTION 392
#define K_SYSCALL_IVSHMEM_GET_STATE 393
#define K_SYSCALL_IVSHMEM_GET_VECTORS 394
#define K_SYSCALL_IVSHMEM_INT_PEER 395
#define K_SYSCALL_IVSHMEM_REGISTER_HANDLER 396
#define K_SYSCALL_IVSHMEM_SET_STATE 397
#define K_SYSCALL_KSCAN_CONFIG 398
#define K_SYSCALL_KSCAN_DISABLE_CALLBACK 399
#define K_SYSCALL_KSCAN_ENABLE_CALLBACK 400
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_IN_GET 401
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_OUT_GET 402
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_EVICTION_GET 403
#define K_SYSCALL_K_MEM_PAGING_STATS_GET 404
#define K_SYSCALL_K_MEM_PAGING_THREAD_STATS_GET 405
#define K_SYSCALL_LED_BLINK 406
#define K_SYSCALL_LED_GET_INFO 407
#define K_SYSCALL_LED_OFF 408
#define K_SYSCALL_LED_ON 409
#define K_SYSCALL_LED_SET_BRIGHTNESS 410
#define K_SYSCALL_LED_SET_CHANNEL 411
#define K_SYSCALL_LED_SET_COLOR 412
#define K_SYSCALL_LED_WRITE_CHANNELS 413
#define K_SYSCALL_MAXIM_DS3231_GET_SYNCPOINT 414
#define K_SYSCALL_MAXIM_DS3231_REQ_SYNCPOINT 415
#define K_SYSCALL_MBOX_MAX_CHANNELS_GET 416
#define K_SYSCALL_MBOX_MTU_GET 417
#define K_SYSCALL_MBOX_SEND 418
#define K_SYSCALL_MBOX_SET_ENABLED 419
#define K_SYSCALL_MDIO_BUS_DISABLE 420
#define K_SYSCALL_MDIO_BUS_ENABLE 421
#define K_SYSCALL_MDIO_READ 422
#define K_SYSCALL_MDIO_READ_C45 423
#define K_SYSCALL_MDIO_WRITE 424
#define K_SYSCALL_MDIO_WRITE_C45 425
#define K_SYSCALL_MSPI_CONFIG 426
#define K_SYSCALL_MSPI_DEV_CONFIG 427
#define K_SYSCALL_MSPI_GET_CHANNEL_STATUS 428
#define K_SYSCALL_MSPI_SCRAMBLE_CONFIG 429
#define K_SYSCALL_MSPI_TIMING_CONFIG 430
#define K_SYSCALL_MSPI_TRANSCEIVE 431
#define K_SYSCALL_MSPI_XIP_CONFIG 432
#define K_SYSCALL_NET_SOCKET_SERVICE_REGISTER 433
#define K_SYSCALL_NRF_QSPI_NOR_XIP_ENABLE 434
#define K_SYSCALL_PECI_CONFIG 435
#define K_SYSCALL_PECI_DISABLE 436
#define K_SYSCALL_PECI_ENABLE 437
#define K_SYSCALL_PECI_TRANSFER 438
#define K_SYSCALL_PS2_CONFIG 439
#define K_SYSCALL_PS2_DISABLE_CALLBACK 440
#define K_SYSCALL_PS2_ENABLE_CALLBACK 441
#define K_SYSCALL_PS2_READ 442
#define K_SYSCALL_PS2_WRITE 443
#define K_SYSCALL_PTP_CLOCK_GET 444
#define K_SYSCALL_PWM_CAPTURE_CYCLES 445
#define K_SYSCALL_PWM_DISABLE_CAPTURE 446
#define K_SYSCALL_PWM_ENABLE_CAPTURE 447
#define K_SYSCALL_PWM_GET_CYCLES_PER_SEC 448
#define K_SYSCALL_PWM_SET_CYCLES 449
#define K_SYSCALL_RETAINED_MEM_CLEAR 450
#define K_SYSCALL_RETAINED_MEM_READ 451
#define K_SYSCALL_RETAINED_MEM_SIZE 452
#define K_SYSCALL_RETAINED_MEM_WRITE 453
#define K_SYSCALL_RTC_ALARM_GET_SUPPORTED_FIELDS 454
#define K_SYSCALL_RTC_ALARM_GET_TIME 455
#define K_SYSCALL_RTC_ALARM_IS_PENDING 456
#define K_SYSCALL_RTC_ALARM_SET_CALLBACK 457
#define K_SYSCALL_RTC_ALARM_SET_TIME 458
#define K_SYSCALL_RTC_GET_CALIBRATION 459
#define K_SYSCALL_RTC_GET_TIME 460
#define K_SYSCALL_RTC_SET_CALIBRATION 461
#define K_SYSCALL_RTC_SET_TIME 462
#define K_SYSCALL_RTC_UPDATE_SET_CALLBACK 463
#define K_SYSCALL_RTIO_CQE_COPY_OUT 464
#define K_SYSCALL_RTIO_CQE_GET_MEMPOOL_BUFFER 465
#define K_SYSCALL_RTIO_RELEASE_BUFFER 466
#define K_SYSCALL_RTIO_SQE_CANCEL 467
#define K_SYSCALL_RTIO_SQE_COPY_IN_GET_HANDLES 468
#define K_SYSCALL_RTIO_SUBMIT 469
#define K_SYSCALL_SDHC_CARD_BUSY 470
#define K_SYSCALL_SDHC_CARD_PRESENT 471
#define K_SYSCALL_SDHC_DISABLE_INTERRUPT 472
#define K_SYSCALL_SDHC_ENABLE_INTERRUPT 473
#define K_SYSCALL_SDHC_EXECUTE_TUNING 474
#define K_SYSCALL_SDHC_GET_HOST_PROPS 475
#define K_SYSCALL_SDHC_HW_RESET 476
#define K_SYSCALL_SDHC_REQUEST 477
#define K_SYSCALL_SDHC_SET_IO 478
#define K_SYSCALL_SENSOR_ATTR_GET 479
#define K_SYSCALL_SENSOR_ATTR_SET 480
#define K_SYSCALL_SENSOR_CHANNEL_GET 481
#define K_SYSCALL_SENSOR_GET_DECODER 482
#define K_SYSCALL_SENSOR_RECONFIGURE_READ_IODEV 483
#define K_SYSCALL_SENSOR_SAMPLE_FETCH 484
#define K_SYSCALL_SENSOR_SAMPLE_FETCH_CHAN 485
#define K_SYSCALL_SIP_SUPERVISORY_CALL 486
#define K_SYSCALL_SIP_SVC_PLAT_ASYNC_RES_REQ 487
#define K_SYSCALL_SIP_SVC_PLAT_ASYNC_RES_RES 488
#define K_SYSCALL_SIP_SVC_PLAT_FORMAT_TRANS_ID 489
#define K_SYSCALL_SIP_SVC_PLAT_FREE_ASYNC_MEMORY 490
#define K_SYSCALL_SIP_SVC_PLAT_FUNC_ID_VALID 491
#define K_SYSCALL_SIP_SVC_PLAT_GET_ERROR_CODE 492
#define K_SYSCALL_SIP_SVC_PLAT_GET_TRANS_IDX 493
#define K_SYSCALL_SIP_SVC_PLAT_UPDATE_TRANS_ID 494
#define K_SYSCALL_SMBUS_BLOCK_PCALL 495
#define K_SYSCALL_SMBUS_BLOCK_READ 496
#define K_SYSCALL_SMBUS_BLOCK_WRITE 497
#define K_SYSCALL_SMBUS_BYTE_DATA_READ 498
#define K_SYSCALL_SMBUS_BYTE_DATA_WRITE 499
#define K_SYSCALL_SMBUS_BYTE_READ 500
#define K_SYSCALL_SMBUS_BYTE_WRITE 501
#define K_SYSCALL_SMBUS_CONFIGURE 502
#define K_SYSCALL_SMBUS_GET_CONFIG 503
#define K_SYSCALL_SMBUS_HOST_NOTIFY_REMOVE_CB 504
#define K_SYSCALL_SMBUS_PCALL 505
#define K_SYSCALL_SMBUS_QUICK 506
#define K_SYSCALL_SMBUS_SMBALERT_REMOVE_CB 507
#define K_SYSCALL_SMBUS_WORD_DATA_READ 508
#define K_SYSCALL_SMBUS_WORD_DATA_WRITE 509
#define K_SYSCALL_SYSCON_GET_BASE 510
#define K_SYSCALL_SYSCON_GET_SIZE 511
#define K_SYSCALL_SYSCON_READ_REG 512
#define K_SYSCALL_SYSCON_WRITE_REG 513
#define K_SYSCALL_TEE_CANCEL 514
#define K_SYSCALL_TEE_CLOSE_SESSION 515
#define K_SYSCALL_TEE_GET_VERSION 516
#define K_SYSCALL_TEE_INVOKE_FUNC 517
#define K_SYSCALL_TEE_OPEN_SESSION 518
#define K_SYSCALL_TEE_SHM_ALLOC 519
#define K_SYSCALL_TEE_SHM_FREE 520
#define K_SYSCALL_TEE_SHM_REGISTER 521
#define K_SYSCALL_TEE_SHM_UNREGISTER 522
#define K_SYSCALL_TEE_SUPPL_RECV 523
#define K_SYSCALL_TEE_SUPPL_SEND 524
#define K_SYSCALL_TGPIO_PIN_CONFIG_EXT_TIMESTAMP 525
#define K_SYSCALL_TGPIO_PIN_DISABLE 526
#define K_SYSCALL_TGPIO_PIN_PERIODIC_OUTPUT 527
#define K_SYSCALL_TGPIO_PIN_READ_TS_EC 528
#define K_SYSCALL_TGPIO_PORT_GET_CYCLES_PER_SECOND 529
#define K_SYSCALL_TGPIO_PORT_GET_TIME 530
#define K_SYSCALL_UPDATEHUB_AUTOHANDLER 531
#define K_SYSCALL_UPDATEHUB_CONFIRM 532
#define K_SYSCALL_UPDATEHUB_PROBE 533
#define K_SYSCALL_UPDATEHUB_REBOOT 534
#define K_SYSCALL_UPDATEHUB_UPDATE 535
#define K_SYSCALL_USER_FAULT 536
#define K_SYSCALL_W1_CHANGE_BUS_LOCK 537
#define K_SYSCALL_W1_CONFIGURE 538
#define K_SYSCALL_W1_GET_SLAVE_COUNT 539
#define K_SYSCALL_W1_READ_BIT 540
#define K_SYSCALL_W1_READ_BLOCK 541
#define K_SYSCALL_W1_READ_BYTE 542
#define K_SYSCALL_W1_RESET_BUS 543
#define K_SYSCALL_W1_SEARCH_BUS 544
#define K_SYSCALL_W1_WRITE_BIT 545
#define K_SYSCALL_W1_WRITE_BLOCK 546
#define K_SYSCALL_W1_WRITE_BYTE 547
#define K_SYSCALL_WDT_DISABLE 548
#define K_SYSCALL_WDT_FEED 549
#define K_SYSCALL_WDT_SETUP 550
#define K_SYSCALL_XTENSA_USER_FAULT 551
#define K_SYSCALL_Z_ERRNO 552


#ifndef _ASMLANGUAGE

#include <stdarg.h>
#include <stdint.h>

#endif /* _ASMLANGUAGE */

#endif /* ZEPHYR_SYSCALL_LIST_H */
