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
 * Supported MCU families: STC12, STC15, STC8A, STC8F, STC8G, STC8H.
 */

typedef enum {
	GPIO_DISABLED = 0,
	GPIO_ENABLED = 1,
} GpioBoolean;

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
	GpioPortMode portMode;			/*!< GPIO pins mode of operation. */
#ifdef GPIO_HAS_PU_NCS
	GpioBoolean schmidtTrigger;	/*!< Enable Schmidt trigger. */
	GpioBoolean internalPullUp;	/*!< Enable internal 4.1k pull-up resistor. */
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	GpioCurrentDrive currentDrive;	/*!< Control output drive capacity. */
	GpioSlewRate slewRate;	/*!< Control output slew rate. */
	GpioBoolean digitalInput;	/*!< Enable line(s) as digital inputs. */
#endif // GPIO_HAS_SR_DR_IE

#ifdef GPIO_HAS_INT_WK
	GpioBoolean interrupts;	/*!< Enable interrupts. */
	GpioInterruptMode interruptMode;	/*!< Type of event triggering an interrupt. */
	GpioBoolean wakeUp;	/*!< Enable wake-up interrupt. */
#endif // GPIO_HAS_INT_WK
	
	uint8_t __setMask;
	uint8_t __clearMask;
} GpioConfig;

/**
 * Convenience macros to configure an entire port and a single GPIO pin.
 */
#ifdef GPIO_HAS_PU_NCS
	#define DEFAULTS_PU_NCS \
		.schmidtTrigger = GPIO_DISABLED, \
		.internalPullUp = GPIO_DISABLED,
#else
	#define DEFAULTS_PU_NCS /**/
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	#define DEFAULTS_SR_DR_IE \
		.currentDrive = GPIO_STANDARD_DRIVE, \
		.slewRate = GPIO_SLOW_TRANSITIONS, \
		.digitalInput = GPIO_ENABLED,
#else
	#define DEFAULTS_SR_DR_IE /**/
#endif // GPIO_HAS_SR_DR_IE

#ifdef GPIO_HAS_INT_WK
	#define DEFAULTS_INT_WK \
		.interrupts = GPIO_DISABLED, \
		.interruptMode = GPIO_FALLING_EDGE, \
		.wakeUp = GPIO_DISABLED,
#else
	#define DEFAULTS_INT_WK /**/
#endif // GPIO_HAS_INT_WK

#define GPIO_PORT_CONFIG(gpioPort, gpioMode) { .port = gpioPort, .pin = 0, .count = 8, .portMode = gpioMode, \
	DEFAULTS_PU_NCS  DEFAULTS_SR_DR_IE  DEFAULTS_INT_WK }

#define GPIO_PIN_CONFIG(gpioPort, gpioPin, gpioMode) { .port = gpioPort, .pin = gpioPin, .count = 1, .portMode = gpioMode, \
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

#endif // _GPIO_HAL_H
