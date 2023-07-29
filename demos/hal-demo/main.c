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
#include <gpio-hal.h>

#if NB_UARTS > 0
	#include <uart-hal.h>
	#include <serial-console.h>
	#include <stdio.h>
#endif

#ifdef MCU_HAS_PCA
	#include "glow-pca.h"
#endif // MCU_HAS_PCA

#ifdef MCU_HAS_ENHANCED_PWM
	#include "glow-enhpwm.h"
#endif // MCU_HAS_ENHANCED_PWM

#ifdef MCU_HAS_ADVANCED_PWM
	#include "glow-advpwm.h"
#endif // MCU_HAS_ADVANCED_PWM

static GpioConfig blinkPin = GPIO_PIN_CONFIG(GPIO_PORT3, BLINK_PIN, GPIO_BIDIRECTIONAL_MODE);
static uint8_t blinkState = 0;

void stuffToDoWhileTheLedBlinks(uint16_t delay) {
#ifdef MCU_HAS_PCA
	// Glow that other LED
	pcaGlowUpdateDutyCycle();
#endif // MCU_HAS_PCA

#ifdef MCU_HAS_ENHANCED_PWM
	pwmGlowUpdateDutyCycle();
#endif // MCU_HAS_ENHANCED_PWM

#ifdef MCU_HAS_ADVANCED_PWM
	pwmGlowUpdateDutyCycle();
#endif // MCU_HAS_ADVANCED_PWM
	
#if NB_UARTS > 0
	// Echo characters typed on the host
	uint8_t c;
	
	while (c = uartGetCharacter(CONSOLE_UART, NON_BLOCKING)) {
		if (c == '\n') {
			uartSendCharacter(CONSOLE_UART, '\r', BLOCKING);
		}
		
		uartSendCharacter(CONSOLE_UART, c, BLOCKING);
	}
#endif
	
	// Leave time for the blinking LED to be perceptible.
	delay1ms(delay);
}

void main() {
	INIT_EXTENDED_SFR()
	
#if NB_UARTS > 0
	serialConsoleInitialise(
		CONSOLE_UART, 
		CONSOLE_SPEED, 
		CONSOLE_PIN_CONFIG
	);
#endif
	
	gpioConfigure(&blinkPin);
	
#ifdef MCU_HAS_PCA
	pcaGlowInitialise();
#endif // MCU_HAS_PCA

#ifdef MCU_HAS_ENHANCED_PWM
	pwmGlowInitialise();
#endif // MCU_HAS_ENHANCED_PWM

#ifdef MCU_HAS_ADVANCED_PWM
	pwmGlowInitialise();
#endif // MCU_HAS_ENHANCED_PWM
	
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		// Blink that LED
		gpioWrite(&blinkPin, blinkState);
		blinkState = !blinkState;
		
		// Splitting the job makes it smoother, at least visually.
		stuffToDoWhileTheLedBlinks(BLINK_HALF_PERIOD / 4);
		stuffToDoWhileTheLedBlinks(BLINK_HALF_PERIOD / 4);
		stuffToDoWhileTheLedBlinks(BLINK_HALF_PERIOD / 4);
		stuffToDoWhileTheLedBlinks(BLINK_HALF_PERIOD / 4);
	}
}
