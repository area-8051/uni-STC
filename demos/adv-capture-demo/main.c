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
#include <timer-hal.h>
#include <uart-hal.h>
#include <serial-console.h>
#include <stdio.h>

/*
 * Test setup ==========================================================
 * 
 * This test uses an STC8H1K28-36I-LQFP32.
 * An USB-to-serial adapter must be connected to P3.0 and P3.1.
 * A signal generator must be connected to P1.0.
 * 
 * The program will print the measured frequency and duty cycle to the 
 * serial console every second.
 * 
 * Start with a 1kHz signal with a 50% duty cycle, then vary the 
 * frequency (max. range: 1Hz-100kHz) and the duty cycle.
 * =====================================================================
 */

#define PWM_COUNTER_FREQ 100000UL
#define PRINT_AFTER_N_TIMER_TICKS 10

static volatile uint8_t ready = PRINT_AFTER_N_TIMER_TICKS;
static volatile uint16_t lastPeriod = 0;
static volatile uint16_t lastUptime = 0;

#pragma save
// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
void pwmOnCounterInterrupt(PWM_Counter counter, PWM_CounterInterrupt event) {
}

void pwmOnChannelInterrupt(PWM_Channel channel, uint16_t counterValue) {
	switch (channel) {
	case PWM_Channel0:
		lastPeriod = counterValue;
		break;
	
	case PWM_Channel1:
		lastUptime = counterValue;
		break;
	}
}
#pragma restore

INTERRUPT(timer2_isr, TIMER2_INTERRUPT) {
	if (ready) {
		ready--;
	}
}

void main() {
	INIT_EXTENDED_SFR()
	
	// Configure serial console ========================================
	serialConsoleInitialise(
		UART1, 
		115200UL, 
		0
	);
	
	// Configure capture ===============================================
	pwmConfigureCounter(
		PWM_COUNTER_A, 
		MCU_FREQ, 
		PWM_COUNTER_FREQ,
		PWM_FREE_RUNNING, 
		PWM_NO_TRIGGER,
		0, // Repeat count
		PWM_BUFFERED_UPDATE,
		PWM_CONTINUOUS,
		PWM_EDGE_ALIGNED_UP,
		// IMPORTANT: the following 2 parameters are needed to record
		// the number of counter overflows, used to calculate elapsed
		// times in the PWM ISR.
		PWM_ENABLE_WRAP_UE_ONLY,
		ENABLE_INTERRUPT
	);
	
	// Channel 0 (P1.0 / pin 1) measures the frequency
	pwmInitialiseCapture(
		PWM_Channel0, 
		0, // Pin switch
		PWM_CAPTURE_ON_RISING_EDGE, 
		PWM_CAPTURE_SAME_PIN, 
		PWM_FILTER_1_CLOCK,
		PWM_REFERENCE_SAME_PIN
	);
	
	pwmEnableCounter(PWM_COUNTER_A);
	
	// Channel 1 measures the duty cycle
	pwmInitialiseCapture(
		PWM_Channel1, 
		0, // Pin switch
		PWM_CAPTURE_ON_FALLING_EDGE, 
		PWM_CAPTURE_OTHER_PIN, 
		PWM_FILTER_1_CLOCK,
		PWM_REFERENCE_OTHER_PIN
	);
	
	// Configure print timer ===========================================
	startTimer(
		TIMER2, 
		// Using a 10Hz timer tick works whatever MCU_FREQ,
		// and allows to print the measurements at intervals
		// greater than 1s if need be.
		frequencyToSysclkDivisor(10UL),
		DISABLE_OUTPUT, 
		ENABLE_INTERRUPT, 
		FREE_RUNNING
	);
	
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		if (ready == 0) {
			ready = PRINT_AFTER_N_TIMER_TICKS;
			uint16_t frequency = PWM_COUNTER_FREQ / lastPeriod;
			uint16_t dutyCycle = lastUptime * 100 / lastPeriod;
			printf("F=%uHz, D=%u%%\n", frequency, dutyCycle);
		}
	}
}
