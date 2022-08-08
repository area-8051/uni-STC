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
#include "project-defs.h"

#ifndef MCU_HAS_WAKE_UP_TIMER
	// Shouldn't happen, unless using an STC12.
	#error "The selected MCU doesn't have a power-down wake-up timer."
#endif // MCU_HAS_WAKE_UP_TIMER

#include <gpio-hal.h>
#include <power-hal.h>

// All STC MCU have P5.4
static GpioConfig ledPin = GPIO_PIN_CONFIG(GPIO_PORT5, GPIO_PIN4, GPIO_BIDIRECTIONAL_MODE);

void main() {
	gpioConfigure(&ledPin);
	gpioWrite(&ledPin, 1);
	
	// An LED connected to P5.4 will blink every second.
	enablePowerDownWakeUpTimer(millisecondsToWakeUpCount(500));

	// Main loop -------------------------------------------------------
	while (1) {
		configureUnusedGpioPins(GPIO_PORT3, M_ALL_PINS);
		configureUnusedGpioPins(GPIO_PORT5, 0xef);
		enterPowerDownMode();
		gpioWrite(&ledPin, !gpioRead(&ledPin));
	}
}
