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
#include <advpwm-hal.h>
#include <gpio-hal.h>

static volatile __bit countDir; // 0 = count up, 1 = count down
static volatile __bit ready = 0;

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pwmOnCounterInterrupt(PWM_Counter counter, PWM_CounterInterrupt event) USING(1) {
}

void pwmOnChannelInterrupt(PWM_Channel channel, uint16_t counterValue, uint8_t countDown) USING(1) {
	if (channel == PWM_Channel4) {
		countDir = countDown;
		ready = 1;
	}
}
#pragma restore

GpioConfig redLED = GPIO_PIN_CONFIG(GPIO_PORT0, GPIO_PIN0, GPIO_OPEN_DRAIN_MODE);
GpioConfig greenLED = GPIO_PIN_CONFIG(GPIO_PORT0, GPIO_PIN1, GPIO_OPEN_DRAIN_MODE);

void main() {
	INIT_EXTENDED_SFR()
	
	// Configure GPIO --------------------------------------------------
	
	gpioConfigure(&redLED);
	gpioWrite(&redLED, 1);
	
	gpioConfigure(&greenLED);
	gpioWrite(&greenLED, 1);
	
	// Configure encoder -----------------------------------------------
	
	// Use PWM5 and PWM6 on P2.0 and P2.1
	pwmInitialiseQuadratureEncoder(
		PWM_Channel4, 
		0, // pin switch, 
		PWM_ACTIVE_LOW, 
		PWM_FILTER_4_CLOCKS
	);

	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		if (ready) {
			ready = 0;
			
			if (countDir) {
				gpioToggle(&redLED);
			} else {
				gpioToggle(&greenLED);
			}
		}
	}
}
