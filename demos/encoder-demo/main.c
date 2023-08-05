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
#include <delay.h>
#include <advpwm-hal.h>
#include <gpio-hal.h>

#include <uart-hal.h>
#include <serial-console.h>
#include <stdio.h>

static volatile __bit countDir = 0; // 0 = count up, 1 = count down
static __bit previousDir = 0;
static volatile __bit ready = 0;

// For PWM_COUNTER_A, we use PWM1P and PWM2P on P1.0 and P1.2 (pin switch = 0).
#define ENCODER_COUNTER PWM_COUNTER_A
#define ENCODER_SWITCH  0
#define ENCODER_CHANNEL PWM_Channel0

/*
// For PWM_COUNTER_B, we use PWM5 and PWM6 on P1.7 and P5.4 (pin switch = 1).
#define ENCODER_COUNTER PWM_COUNTER_B
#define ENCODER_SWITCH  1
#define ENCODER_CHANNEL PWM_Channel4
*/

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pwmOnCounterInterrupt(PWM_Counter counter, PWM_CounterInterrupt HAL_PWM_SEGMENT event) {
}

void pwmOnChannelInterrupt(PWM_Channel channel, uint16_t HAL_PWM_SEGMENT counterValue) {
	// The if statement is not really needed in our case because
	// pwmOnChannelInterrupt() will be called only on the encoder
	// interrupt. However, it would be necessary if we also used 
	// the other counter for other purposes.
	if (channel == ENCODER_CHANNEL) {
		// In quadrature encoder mode, counterValue is 0 when
		// counting up (encoder rotates clockwise), and non-zero
		// when counting down (encoder rotates counter-clockwise).
		countDir = counterValue;
		ready = 1;
	}
}
#pragma restore

GpioConfig redLED = GPIO_PIN_CONFIG(GPIO_PORT3, GPIO_PIN6, GPIO_OPEN_DRAIN_MODE);
GpioConfig greenLED = GPIO_PIN_CONFIG(GPIO_PORT3, GPIO_PIN7, GPIO_OPEN_DRAIN_MODE);

void main() {
	INIT_EXTENDED_SFR()
	
	serialConsoleInitialise(
		UART1, 
		115200UL, 
		0
	);
	
	// Configure GPIO --------------------------------------------------
	
	gpioConfigure(&redLED);
	gpioWrite(&redLED, 1);
	
	gpioConfigure(&greenLED);
	gpioWrite(&greenLED, 1);
	
	// Test LEDs -------------------------------------------------------
	
	for (uint8_t i = 2; i; i--) {
		gpioToggle(&redLED);
		delay1ms(250);
		gpioToggle(&redLED);
		gpioToggle(&greenLED);
		delay1ms(250);
		gpioToggle(&greenLED);
	}

	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Configure encoder -----------------------------------------------
	
	pwmInitialiseQuadratureEncoder(
		ENCODER_COUNTER, 
		ENCODER_SWITCH,
		PWM_CAPTURE_ON_RISING_EDGE, 
		PWM_FILTER_4_CLOCKS
	);
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		if (ready) {
			ready = 0;
			
			// Turn off previous LED whenever direction changes.
			if (countDir != previousDir) {
				previousDir = countDir;
				
				if (countDir) {
					gpioWrite(&greenLED, 1);
				} else {
					gpioWrite(&redLED, 1);
				}
			}
			
			if (countDir) {
				gpioToggle(&redLED);
			} else {
				gpioToggle(&greenLED);
			}
		}
	}
}
