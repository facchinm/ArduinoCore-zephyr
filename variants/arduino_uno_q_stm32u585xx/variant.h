/*
 * Copyright (c) 2022 Dhruva Gole
 *
 * SPDX-License-Identifier: Apache-2.0
 */

// TODO: correctly handle these legacy defines
#define MOSI    0
#define MISO    0
#define SCK     0
#define SS      0
#define SDA     0
#define SCL     0

#define AR_DEFAULT          0
#define AR_INTERNAL2V5      1
#define AR_INTERNAL2V05     2
#define AR_INTERNAL1V5      3
#define AR_INTERNAL1V8      4
#define AR_EXTERNAL         5
#define AR_INTERNAL         AR_INTERNAL2V5

// RGB LEDs Pin Map
#define LED3_R DIGITAL_PIN_GPIOS_FIND_NODE(DT_NODELABEL(led3_red))
#define LED3_G DIGITAL_PIN_GPIOS_FIND_NODE(DT_NODELABEL(led3_green))
#define LED3_B DIGITAL_PIN_GPIOS_FIND_NODE(DT_NODELABEL(led3_blue))

#define LED4_R DIGITAL_PIN_GPIOS_FIND_NODE(DT_NODELABEL(led4_red))
#define LED4_G DIGITAL_PIN_GPIOS_FIND_NODE(DT_NODELABEL(led4_green))
#define LED4_B DIGITAL_PIN_GPIOS_FIND_NODE(DT_NODELABEL(led4_blue))

#include <stm32u5xx_ll_gpio.h>

struct gpio_stm32_config {
	/* gpio_driver_config needs to be first */
	struct gpio_driver_config common;
	/* port base address */
	uint32_t *base;
};

#define digitalPinToPort(x)    (GPIO_TypeDef *)(((struct gpio_stm32_config *)(digitalPinToPortDevice(x)->config))->base)
#define digitalPinToPinName(x) (digitalPinToPinNumber(x))
#define STM_LL_GPIO_PIN(x)     (1U << x)

#define digitalPinToBitMask(x) STM_LL_GPIO_PIN(x)
#define portOutputRegister(x)  (digitalPinToPort(x)->ODR)
#define portInputRegister(x)   (digitalPinToPort(x)->IDR)