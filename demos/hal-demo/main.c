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
#include "uart-hal.h"
#include "serial-console.h"
#include <stdio.h>

#ifdef MCU_HAS_PCA
	#include "timer-hal.h"
	#include "pca-hal.h"
#endif // MCU_HAS_PCA

static GpioConfig blinkingPin = GPIO_PIN_CONFIG(GPIO_PORT3, BLINKING_PIN, GPIO_BIDIRECTIONAL);
static uint8_t blinkingState = 0;

#ifdef MCU_HAS_PCA
static int16_t glowingDutyCycle = GLOWING_DUTY_CYCLE_MIN;
static int8_t glowingIncrement = GLOWING_DUTY_CYCLE_INCREMENT;

/*
 * @see pca.h
 */
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pcaOnInterrupt(PCA_Channel channel, uint16_t pulseLength) USE_BANK(1) {
}

void updateGlowingDutyCycle() {
	pcaSetPwmDutyCycle(GLOWING_CCP_CHANNEL, glowingDutyCycle);
	int16_t newDutyCycle = glowingDutyCycle + glowingIncrement;
	
	if (newDutyCycle <= GLOWING_DUTY_CYCLE_MIN || newDutyCycle > GLOWING_DUTY_CYCLE_MAX) {
		glowingIncrement = -glowingIncrement;
	}
	
	glowingDutyCycle += glowingIncrement;
}
#endif // MCU_HAS_PCA

void echoCharactersReceived() {
	uint8_t c;
	
	while (c = uartGetCharacter(CONSOLE_UART)) {
		if (c == '\n') {
			uartSendCharacter(CONSOLE_UART, '\r');
		}
		
		uartSendCharacter(CONSOLE_UART, c);
	}
}

void stuffToDoWhileTheLedBlinks(uint16_t delay) {
#ifdef MCU_HAS_PCA
		// Glow that other LED
		updateGlowingDutyCycle();
#endif // MCU_HAS_PCA
		
		// Echo characters typed on the host
		echoCharactersReceived();
		
		// Leave time for the blinking LED to be perceptible.
		delay1ms(delay);
}

void main() {
	serialConsoleInitialise(
		CONSOLE_UART, 
		CONSOLE_SPEED, 
		CONSOLE_PIN_CONFIG
	);
	
	gpioConfigure(&blinkingPin);
	
#ifdef MCU_HAS_PCA
	startTimer(
		TIMER0, 
		frequencyToSysclkDivisor(GLOWING_COUNTER_FREQ), 
		TIMER_OUTPUT_DISABLE, 
		TIMER_INTERRUPT_DISABLE, 
		TIMER_FREE_RUNNING
	);
	
	pcaInitialise(
		PCA_TIMER0, 
		PCA_FREE_RUNNING, 
		PCA_INTERRUPT_DISABLE, 
		GLOWING_PIN_CONFIG
	);
	
	pcaStartPwm(
		GLOWING_CCP_CHANNEL, 
		GPIO_BIDIRECTIONAL, 
		MAKE_PCA_PWM_BITS(GLOWING_PWM_BITS), 
		PCA_EDGE_NONE, 
		glowingDutyCycle
	);
#endif // MCU_HAS_PCA
	
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		// Blink that LED
		gpioWrite(&blinkingPin, blinkingState);
		blinkingState = !blinkingState;
		
		// Splitting the job makes it smoother, at least visually.
		stuffToDoWhileTheLedBlinks(BLINKING_HALF_PERIOD / 2);
		stuffToDoWhileTheLedBlinks(BLINKING_HALF_PERIOD / 2);
	}
}
