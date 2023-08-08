/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2022 Vincent DEFERT. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef _GPIO_HAL_H
#define _GPIO_HAL_H

/**
 * @file gpio-hal.h
 * 
 * GPIO abstraction layer definitions.
 * 
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8*
 * 
 * Dependencies:
 * 
 *     none
 * 
 * Optional macros:
 * 
 *     BASIC_GPIO_HAL (default: undefined). When defined, removes
 *     support for enhanced GPIO features available on STC8 MCU series.
 *     Greatly helps reduce flash footprint on STC8, but has no effect
 *     on other MCU series.
 */

#ifdef BASIC_GPIO_HAL
	// Useful to save on flash space when advanced features aren't used.
	#ifdef GPIO_HAS_PU_NCS
		#undef GPIO_HAS_PU_NCS
	#endif
	#ifdef GPIO_HAS_SR_DR_IE
		#undef GPIO_HAS_SR_DR_IE
	#endif
	#ifdef GPIO_HAS_INT_WK
		#undef GPIO_HAS_INT_WK
	#endif
#endif

#ifdef GPIO_HAS_PU_NCS
	typedef enum {
		DISABLE_SCHMIDT_TRIGGER = 0,
		ENABLE_SCHMIDT_TRIGGER = 1,
	} GpioSchmidtTrigger;

	typedef enum {
		DISABLE_INTERNAL_PULL_UP = 0,
		ENABLE_INTERNAL_PULL_UP = 1,
	} GpioInternalPullUp;
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_INT_WK
	typedef enum {
		DISABLE_GPIO_PIN_INTERRUPT = 0,
		ENABLE_GPIO_PIN_INTERRUPT = 1,
	} GpioInterrupt;

	typedef enum {
		DISABLE_GPIO_PIN_WAKE_UP = 0,
		ENABLE_GPIO_PIN_WAKE_UP = 1,
	} GpioWakeUp;
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_SR_DR_IE
	typedef enum {
		DISABLE_GPIO_DIGITAL_INPUT = 0,
		ENABLE_GPIO_DIGITAL_INPUT = 1,
	} GpioDigitalInput;

	// More developer-friendly than dealing with SR and DR separately.
	typedef enum {
		// SR = 0 DR = 0
		GPIO_SPEED_FASTEST = 0,
		// SR = 0 DR = 1
		GPIO_SPEED_FAST = 1,
		// SR = 1 DR = 0
		GPIO_SPEED_SLOW = 2,
		// SR = 1 DR = 1
		GPIO_SPEED_SLOWEST = 3,
	} GpioSpeed;
#endif // GPIO_HAS_SR_DR_IE


/**
 * Configuration details of a GPIO pin, or series of consecutive pins.
 * 
 * **IMPORTANT:** symbols whose names beginning with 2 underscores are 
 * used internally by the driver.
 */
typedef struct {
	GpioPort port;			/*!< GPIO port number. */
	GpioPin pin;			/*!< Index of the first pin used on the port. */
	uint8_t count;	/*!< Number of consecutive pins used on the port, 
							starting with .pin and counting up. */
	GpioPinMode pinMode;			/*!< GPIO pins mode of operation. */
#ifdef GPIO_HAS_PU_NCS
	GpioSchmidtTrigger schmidtTrigger;	/*!< Enable Schmidt trigger. */
	GpioInternalPullUp internalPullUp;	/*!< Enable internal 4.1k pull-up resistor. */
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	GpioSpeed speed;	/*!< Used to derive DR (output drive capacity) and SR (slew rate). */
	GpioDigitalInput digitalInput;	/*!< Enable line(s) as digital input(s). Reduces power draw when pin is either not used, or used by another peripheral (e.g. ADC). */
#endif // GPIO_HAS_SR_DR_IE

#ifdef GPIO_HAS_INT_WK
	GpioInterrupt pinInterrupt;	/*!< Enable interrupts when interruptTrigger occurs. */
	GpioInterruptTrigger interruptTrigger;	/*!< Type of event triggering an interrupt. */
	GpioWakeUp wakeUpInterrupt;	/*!< Enable wake-up interrupt. */
#endif // GPIO_HAS_INT_WK
	
	uint8_t __setMask;
	uint8_t __clearMask;
} GpioConfig;

/**
 * Convenience macros to configure an entire port and a single GPIO pin.
 */
#ifdef GPIO_HAS_PU_NCS
	#define DEFAULTS_PU_NCS \
		.schmidtTrigger = DISABLE_SCHMIDT_TRIGGER, \
		.internalPullUp = DISABLE_INTERNAL_PULL_UP,
#else
	#define DEFAULTS_PU_NCS
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	#define DEFAULTS_SR_DR_IE \
		.speed = GPIO_SPEED_SLOWEST, \
		.digitalInput = ENABLE_GPIO_DIGITAL_INPUT,
#else
	#define DEFAULTS_SR_DR_IE
#endif // GPIO_HAS_SR_DR_IE

#ifdef GPIO_HAS_INT_WK
	#define DEFAULTS_INT_WK \
		.pinInterrupt = DISABLE_GPIO_PIN_INTERRUPT, \
		.interruptTrigger = GPIO_FALLING_EDGE, \
		.wakeUpInterrupt = DISABLE_GPIO_PIN_WAKE_UP,
#else
	#define DEFAULTS_INT_WK
#endif // GPIO_HAS_INT_WK

#define GPIO_PORT_CONFIG(gpioPort, gpioMode) { .port = gpioPort, .pin = 0, .count = 8, .pinMode = gpioMode, \
	DEFAULTS_PU_NCS  DEFAULTS_SR_DR_IE  DEFAULTS_INT_WK }

#define GPIO_PIN_CONFIG(gpioPort, gpioPin, gpioMode) { .port = gpioPort, .pin = gpioPin, .count = 1, .pinMode = gpioMode, \
	DEFAULTS_PU_NCS  DEFAULTS_SR_DR_IE  DEFAULTS_INT_WK }

#define GPIO_PINS_CONFIG(gpioPort, gpioFirstPin, gpioPinCount, gpioMode) { .port = gpioPort, .pin = gpioFirstPin, .count = gpioPinCount, .pinMode = gpioMode, \
	DEFAULTS_PU_NCS  DEFAULTS_SR_DR_IE  DEFAULTS_INT_WK }

/**
 * Configures a GPIO pin, or series of consecutive pins.
 */
void gpioConfigure(GpioConfig *config);

/**
 * Reads a GPIO pin, or series of consecutive pins.
 * 
 * When reading a series of pins, the resulting value will be shifted
 * so that bit 0 of the result corresponds to .pin in GpioConfig.
 * Bits outside of the scope defined by GpioConfig are masked off.
 */
uint8_t gpioRead(GpioConfig *config);

/**
 * Sets a GPIO pin, or series of consecutive pins.
 * 
 * When setting a series of pins, 'value' will be shifted so that its 
 * bit 0 corresponds to .pin in GpioConfig.
 * Bits outside of the scope defined by GpioConfig are masked off.
 */
void gpioWrite(GpioConfig *config, uint8_t value);

INLINE void gpioToggle(GpioConfig *config) {
	gpioWrite(config, !gpioRead(config));
}

#endif // _GPIO_HAL_H
