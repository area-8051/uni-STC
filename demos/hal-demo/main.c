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
	#include <timer-hal.h>
	#include <pca-hal.h>
#endif // MCU_HAS_PCA

#ifdef MCU_HAS_ENHANCED_PWM
	#include <enhpwm-hal.h>
#endif // MCU_HAS_ENHANCED_PWM

#ifdef MCU_HAS_ADVANCED_PWM
	#include <advpwm-hal.h>
#endif // MCU_HAS_ADVANCED_PWM

static GpioConfig blinkingPin = GPIO_PIN_CONFIG(GPIO_PORT3, BLINKING_PIN, GPIO_BIDIRECTIONAL_MODE);
static uint8_t blinkingState = 0;

#ifdef MCU_HAS_PCA
#define PCA_COUNTER_VALUE 255U

// Luminance as per CIELAB scaled to 256 (8-bit PWM)
static const uint8_t PCA_GLOWING_GRADIENT[] = {
	1, 3, 5, 7, 10, 15, 20, 27, 34, 44, 54, 
	67, 81, 97, 114, 134, 157, 181, 208, 237,
};

#define PCA_GLOWING_STEPS (sizeof(PCA_GLOWING_GRADIENT) / sizeof(PCA_GLOWING_GRADIENT[0]))

static int8_t pcaGlowingStep = 0;
static int8_t pcaGlowingIncrement = 1;

/*
 * @see pca.h
 */
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pcaOnInterrupt(PCA_Channel channel, uint16_t HAL_PCA_SEGMENT pulseLength) USING(1) {
}

void pcaUpdateGlowingDutyCycle() {
	pcaSetDutyCycle(PCA_GLOWING_CHANNEL, PCA_COUNTER_VALUE - PCA_GLOWING_GRADIENT[pcaGlowingStep]);
	int8_t newStep = pcaGlowingStep + pcaGlowingIncrement;
	
	if (newStep < 0 || newStep >= PCA_GLOWING_STEPS) {
		pcaGlowingIncrement = -pcaGlowingIncrement;
	}
	
	pcaGlowingStep += pcaGlowingIncrement;
}
#endif // MCU_HAS_PCA

// ---------------------------------------------------------------------

#ifdef MCU_HAS_ENHANCED_PWM
#define PWM_COUNTER_VALUE 32767U

static const uint16_t PWM_GLOWING_GRADIENT[] = {
	181, 342, 579, 907, 1340, 1893, 2579, 3415, 4414, 5590, 6960, 
	8536, 10334, 12368, 14653, 17204, 20034, 23159, 26594, 30352, 
};

#define PWM_GLOWING_STEPS (sizeof(PWM_GLOWING_GRADIENT) / sizeof(PWM_GLOWING_GRADIENT[0]))

static int8_t pwmGlowingStep = 0;
static int8_t pwmGlowingIncrement = 1;

void pwmUpdateGlowingDutyCycle() {
	pwmSetFlipPoints(PWM_GLOWING_CHANNEL, 0, PWM_COUNTER_VALUE - PWM_GLOWING_GRADIENT[pwmGlowingStep]);
	int8_t newStep = pwmGlowingStep + pwmGlowingIncrement;
	
	if (newStep < 0 || newStep >= PWM_GLOWING_STEPS) {
		pwmGlowingIncrement = -pwmGlowingIncrement;
	}
	
	pwmGlowingStep += pwmGlowingIncrement;
}
#endif // MCU_HAS_ENHANCED_PWM

// ---------------------------------------------------------------------

#ifdef MCU_HAS_ADVANCED_PWM

static const uint16_t PWM_GLOWING_GRADIENT[] = {
	363, 684, 1159, 1814, 2680, 3785, 5159, 6830, 8827, 11181, 13919, 
	17072, 20668, 24736, 29306, 34407, 40069, 46319, 53187, 60703, 
};

#define PWM_GLOWING_STEPS (sizeof(PWM_GLOWING_GRADIENT) / sizeof(PWM_GLOWING_GRADIENT[0]))

static int8_t pwmGlowingStep = 0;
static int8_t pwmGlowingIncrement = 1;

void pwmUpdateGlowingDutyCycle() {
	pwmSetDutyCycle(PWM_GLOWING_CHANNEL, PWM_GLOWING_GRADIENT[pwmGlowingStep]);
	int8_t newStep = pwmGlowingStep + pwmGlowingIncrement;
	
	if (newStep < 0 || newStep >= PWM_GLOWING_STEPS) {
		pwmGlowingIncrement = -pwmGlowingIncrement;
	}
	
	pwmGlowingStep += pwmGlowingIncrement;
}

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pwmOnCounterInterrupt(PWM_Counter counter, PWM_CounterInterrupt event) USING(1) {
}

void pwmOnChannelInterrupt(PWM_Channel channel, uint16_t counterValue, uint8_t countDown) USING(1) {
}
#pragma restore

#endif // MCU_HAS_ADVANCED_PWM

// ---------------------------------------------------------------------

#if NB_UARTS > 0
void echoCharactersReceived() {
	uint8_t c;
	
	while (c = uartGetCharacter(CONSOLE_UART, NON_BLOCKING)) {
		if (c == '\n') {
			uartSendCharacter(CONSOLE_UART, '\r', BLOCKING);
		}
		
		uartSendCharacter(CONSOLE_UART, c, BLOCKING);
	}
}
#endif

void stuffToDoWhileTheLedBlinks(uint16_t delay) {
#ifdef MCU_HAS_PCA
	// Glow that other LED
	pcaUpdateGlowingDutyCycle();
#endif // MCU_HAS_PCA

#ifdef MCU_HAS_ENHANCED_PWM
	pwmUpdateGlowingDutyCycle();
#endif // MCU_HAS_ENHANCED_PWM

#ifdef MCU_HAS_ADVANCED_PWM
	pwmUpdateGlowingDutyCycle();
#endif // MCU_HAS_ADVANCED_PWM
	
#if NB_UARTS > 0
	// Echo characters typed on the host
	echoCharactersReceived();
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
	
	gpioConfigure(&blinkingPin);
	
#ifdef MCU_HAS_PCA
	startTimer(
		TIMER0, 
		frequencyToSysclkDivisor(PCA_GLOWING_COUNTER_FREQ), 
		DISABLE_OUTPUT, 
		DISABLE_INTERRUPT, 
		FREE_RUNNING
	);
	
	pcaStartCounter(
		PCA_TIMER0, 
		FREE_RUNNING, 
		DISABLE_INTERRUPT, 
		PCA_GLOWING_PIN_CONFIG
	);
	pcaConfigureChannel(
		PCA_GLOWING_CHANNEL, 
		GPIO_BIDIRECTIONAL_MODE
	);
	pcaStartPwm(
		PCA_GLOWING_CHANNEL, 
		MAKE_PCA_PWM_BITS(PCA_GLOWING_PWM_BITS), 
		PCA_EDGE_NONE, 
		PCA_COUNTER_VALUE - PCA_GLOWING_GRADIENT[0]
	);
#endif // MCU_HAS_PCA

// ---------------------------------------------------------------------

#ifdef MCU_HAS_ENHANCED_PWM
	pwmStartCounter(
		PWM_SYSCLK_DIV_7, 
		PWM_COUNTER_VALUE, 
		DISABLE_INTERRUPT
	);
	pwmConfigureChannel(
		PWM_GLOWING_CHANNEL, 
		PWM_GLOWING_PIN_CONFIG, 
		GPIO_BIDIRECTIONAL_MODE
	);
	pwmStartChannel(
		PWM_GLOWING_CHANNEL, 
		OUTPUT_LOW, 
		PWM_INTERRUPT_EVENT_NONE, 
		0,
		PWM_COUNTER_VALUE - PWM_GLOWING_GRADIENT[0]
	);
#endif // MCU_HAS_ENHANCED_PWM

// ---------------------------------------------------------------------

#ifdef MCU_HAS_ADVANCED_PWM
	pwmConfigureCounter(
		PWM_GLOWING_COUNTER, 
		PWM_GLOWING_SIGNAL_FREQ * 65535UL, 
		PWM_GLOWING_SIGNAL_FREQ, 
		PWM_FREE_RUNNING, 
		PWM_NO_TRIGGER,
		0, 
		PWM_BUFFERED_UPDATE,
		PWM_CONTINUOUS,
		PWM_EDGE_ALIGNED_UP,
		PWM_DISABLE_ALL_UE,
		DISABLE_INTERRUPT
	);
	
	pwmInitialisePWM(
		PWM_Channel0, 
		OUTPUT_HIGH, 
		DISABLE_INTERRUPT, 
		PWM_IMMEDIATE_UPDATE,
		PWM_GLOWING_GRADIENT[0]
	);
	
	pwmConfigureOutput(
		PWM_GLOWING_CHANNEL, 
		PWM_GLOWING_PIN_CONFIG, 
		GPIO_BIDIRECTIONAL_MODE,
		PWM_ACTIVE_LOW, 
		PWM_DISABLE_FAULT_CONTROL, 
		OUTPUT_HIGH,
		PWM_OUTPUT_P_ONLY
	);
	
	pwmEnableMainOutput(PWM_GLOWING_COUNTER);
	pwmEnableCounter(PWM_GLOWING_COUNTER);
#endif // MCU_HAS_ENHANCED_PWM

// ---------------------------------------------------------------------

#ifdef MCU_HAS_ADVANCED_PWM
#endif // MCU_HAS_ADVANCED_PWM
	
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
