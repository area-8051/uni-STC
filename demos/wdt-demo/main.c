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

#include "delay.h"
#include "gpio-hal.h"
#include "reset-hal.h"

// All STC MCU have P5.4
static GpioConfig ledPin = GPIO_PIN_CONFIG(GPIO_PORT5, GPIO_PIN4, GPIO_BIDIRECTIONAL_MODE);

// We want a time out of about 2 seconds.
#define WD_TIMEOUT 2000
// We want 4 long flashes and a maximum of 4 short flashes
#define NB_FLASHES 4

void main() {
	gpioConfigure(&ledPin);
	gpioWrite(&ledPin, 1);
	
	WatchdogPrescaler prescaler = millisecondsToWatchdogPrescaler(WD_TIMEOUT);
	uint16_t exactOverflowTime = watchdogPrescalerToMilliseconds(prescaler);
	uint16_t t2_8 = exactOverflowTime >> 2;
	uint16_t t1_8 = t2_8 >> 1;
	uint16_t t3_8 = t1_8 + t2_8;
	
	startWatchdog(prescaler, WDT_disabledInIdleMode);
	
	// 1 Hz, 75% duty cycle flashes
	for (uint8_t i = NB_FLASHES; i; i--) {
		gpioWrite(&ledPin, 0);
		delay1ms(t2_8);
		clearWatchdog();
		delay1ms(t1_8);
		gpioWrite(&ledPin, 1);
		delay1ms(t1_8);
	}
	
	// 1 Hz, 25% duty cycle flashes => should see only 2
	for (uint8_t i = NB_FLASHES; i; i--) {
		gpioWrite(&ledPin, 0);
		delay1ms(t1_8);
		gpioWrite(&ledPin, 1);
		delay1ms(t3_8);
	}

	// End of test
	while (1);
}
