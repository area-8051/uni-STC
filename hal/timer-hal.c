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
#include <timer-hal.h>

/**
 * @file timer-hal.c
 * 
 * Timer abstraction implementation for STC12, STC15 and STC8.
 */

#if MCU_FAMILY == 12
	#define COUNTER_MAX 256UL
#else
	#define COUNTER_MAX 65536UL
#endif // MCU_FAMILY == 12

uint32_t baudRateToSysclkDivisor(uint32_t baudRate) {
	uint32_t divisor;
	
#if MCU_FAMILY == 12
	// STC12 timers seem to work as documented only in 8-bit mode.
	// This is only an issue for T0 and T1 since BRT is 8-bit only.
	divisor = (MCU_FREQ / baudRate / 32UL);
#elif MCU_FAMILY == 8 && MCU_SERIES == 'A' && !defined(MCU_HAS_DMA)
	// A peculiarity of the STC8A8K64S4A12...
	divisor = ((MCU_FREQ / 2UL) / baudRate / 4UL);
#else
	// All others behave as described in their data sheet.
	divisor = (MCU_FREQ / baudRate / 4UL);
#endif

	return divisor;
}

uint32_t frequencyToSysclkDivisor(uint32_t frequency) {
	return MCU_FREQ / frequency;
}

TimerStatus startTimer(Timer timer, uint32_t sysclkDivisor, OutputEnable enableOutput, InterruptEnable enableInterrupt, CounterControl timerControl) {
	TimerStatus rc = TIMER_FREQUENCY_OK;
	uint8_t sysclkDiv1 = 1;
	
	if (sysclkDivisor == 0) {
		// Too high
		rc = TIMER_FREQUENCY_TOO_HIGH;
	} else if (sysclkDivisor > (COUNTER_MAX * 12UL)) {
#ifdef TIMER_HAS_PRESCALERS
		uint8_t prescaler;
		
		switch (timer) {
		case TIMER0:
		case TIMER1:
			// Too low: T0 and T1 don't have a prescaler.
			rc = TIMER_FREQUENCY_TOO_LOW;
			break;
		
		default:
			// Prescalers are 8-bit counters, so PRESCALER_MAX = 256.
			// For sysclkDivisor to excede COUNTER_MAX * PRESCALER_MAX * 12UL,
			// sysclk should be greater than 201MHz, so no need to test that.
			prescaler = sysclkDivisor / (COUNTER_MAX * 12UL);
			
			if (sysclkDivisor % (COUNTER_MAX * 12UL)) {
				prescaler++;
			}
			
			sysclkDivisor /= prescaler;
			setTimerPrescaler(timer, prescaler);
			break;
		}
#else
		// Too low
		rc = TIMER_FREQUENCY_TOO_LOW;
#endif // TIMER_HAS_PRESCALERS
	}

	if (rc == TIMER_FREQUENCY_OK) {
		if (sysclkDivisor > COUNTER_MAX) {
			// sysclkDiv1 = 0 => pre-divide sysclk by 12
			sysclkDiv1 = 0;
			sysclkDivisor /= 12UL;
		}
		
		uint16_t reloadValue = (uint16_t) (COUNTER_MAX - sysclkDivisor);
		
		switch (timer) {
		case TIMER0:
			// Set prescaler
			AUXR = (AUXR & ~M_T0x12) | ((sysclkDiv1 << P_T0x12) & M_T0x12);
			
			// Configure T0 as a 16-bit auto-reload timer (mode 0).
			TMOD &= 0xf0;
			
			// Configure timer control
			TMOD = (TMOD & ~M_T0_GATE) | ((timerControl << P_T0_GATE) & M_T0_GATE);
			
#if MCU_FAMILY == 12
			// On the STC12, we'll use mode 2 (8-bit auto-reload timer).
			TMOD |= 2;
			
			if (enableOutput == ENABLE_OUTPUT) {
				WAKE_CLKO |= M_T0CLKO;
			} else {
				WAKE_CLKO &= ~M_T0CLKO;
			}
			
			T0H = T0L = reloadValue;
#else
			if (enableOutput == ENABLE_OUTPUT) {
				INT_CLKO |= M_T0CLKO;
			} else {
				INT_CLKO &= ~M_T0CLKO;
			}
			
			T0 = reloadValue;
#endif
			
			if (enableInterrupt == ENABLE_INTERRUPT) {
				IE1 |= M_ET0;
			} else {
				IE1 &= ~M_ET0;
			}
			
			// Clear interrupt flag and start timer
			TCON = (TCON & ~M_T0IF) | M_T0R;
			break;
		
#ifdef TIMER_HAS_T1
		case TIMER1:
	#if MCU_FAMILY == 12
			// Configure T1 as an 8-bit auto-reload timer (mode 2)
			TMOD = (TMOD & 0x0f) | (2 << P_T1_M);
			
			if (enableOutput == ENABLE_OUTPUT) {
				WAKE_CLKO |= M_T1CLKO;
			} else {
				WAKE_CLKO &= ~M_T1CLKO;
			}
			
			// Set reload value
			T1H = T1L = reloadValue;
	#else
			// Configure T1 as a 16-bit auto-reload timer (mode 0)
			TMOD &= 0x0f;
			
			if (enableOutput == ENABLE_OUTPUT) {
				INT_CLKO |= M_T1CLKO;
			} else {
				INT_CLKO &= ~M_T1CLKO;
			}
			
			// Set reload value
			T1 = reloadValue;
	#endif // MCU_FAMILY == 12
			
			// Configure timer control
			TMOD = (TMOD & ~M_T1_GATE) | ((timerControl << P_T1_GATE) & M_T1_GATE);

			// Configure prescaling
			AUXR = (sysclkDiv1) ? (AUXR | M_T1x12) : (AUXR & ~M_T1x12);
			
			if (enableInterrupt == ENABLE_INTERRUPT) {
				IE1 |= M_ET1;
			} else {
				IE1 &= ~M_ET1;
			}
			
			// Clear interrupt flag and start timer
			TCON = (TCON & ~M_T1IF) | M_T1R;
			break;
#endif // TIMER_HAS_T1
	
		case TIMER2:
#ifdef TIMER_HAS_T2
			// Configure T2 in timer mode
			AUXR &= ~M_T2_C_T;
			
			if (enableOutput == ENABLE_OUTPUT) {
				INT_CLKO |= M_T2CLKO;
			} else {
				INT_CLKO &= ~M_T2CLKO;
			}
			
			// Set reload value
			T2 = reloadValue;
#endif // TIMER_HAS_T2

#ifdef TIMER_HAS_BRT
			if (enableOutput == ENABLE_OUTPUT) {
				WAKE_CLKO |= M_BRTCLKO;
			} else {
				WAKE_CLKO &= ~M_BRTCLKO;
			}
			
			// Set reload value
			BRT =  reloadValue;
#endif // TIMER_HAS_BRT

			// Configure prescaling
			AUXR = (sysclkDiv1) ? (AUXR | M_T2x12) : (AUXR & ~M_T2x12);
			
#ifdef TIMER_HAS_T2
			if (enableInterrupt == ENABLE_INTERRUPT) {
				IE2 |= M_ET2;
			} else {
				IE2 &= ~M_ET2;
			}
			
	#ifdef TIMER_HAS_AUXINTIF
			// Clear interrupt flag
			AUXINTIF &= ~M_T2IF;
	#endif // TIMER_HAS_AUXINTIF
#endif // TIMER_HAS_T2
			
			// Start timer
			AUXR |= M_T2R;
			break;
	
#ifdef TIMER_HAS_T3_T4
		case TIMER3:
			// Configure T3 in timer mode
			T4T3M &= ~M_T3_C_T;
			
			if (enableOutput == ENABLE_OUTPUT) {
				T4T3M |= M_T3CLKO;
			} else {
				T4T3M &= ~M_T3CLKO;
			}
			
			// Configure prescaling
			T4T3M = (sysclkDiv1) ? (T4T3M | M_T3x12) : (T4T3M & ~M_T3x12);
			
			// Set reload value
			T3 = reloadValue;
			
			if (enableInterrupt == ENABLE_INTERRUPT) {
				IE2 |= M_ET3;
			} else {
				IE2 &= ~M_ET3;
			}
			
#ifdef TIMER_HAS_AUXINTIF
			// Clear interrupt flag
			AUXINTIF &= ~M_T3IF;
#endif // TIMER_HAS_AUXINTIF
			
			// Start timer
			T4T3M |= M_T3R;
			break;
		
		case TIMER4:
			// Configure T4 in timer mode
			T4T3M &= ~M_T4_C_T;
			
			if (enableOutput == ENABLE_OUTPUT) {
				T4T3M |= M_T4CLKO;
			} else {
				T4T3M &= ~M_T4CLKO;
			}
			
			// Configure prescaling
			T4T3M = (sysclkDiv1) ? (T4T3M | M_T4x12) : (T4T3M & ~M_T4x12);
			
			// Set reload value
			T4 = reloadValue;
			
			if (enableInterrupt == ENABLE_INTERRUPT) {
				IE2 |= M_ET4;
			} else {
				IE2 &= ~M_ET4;
			}
			
#ifdef TIMER_HAS_AUXINTIF
			// Clear interrupt flag
			AUXINTIF &= ~M_T4IF;
#endif // TIMER_HAS_AUXINTIF
			
			// Start timer
			T4T3M |= M_T4R;
			break;
#endif // TIMER_HAS_T3_T4
		}
	}
	
	return rc;
}


uint16_t stopTimer(Timer timer) {
	uint16_t counterValue = 0;
	
	switch (timer) {
	case TIMER0:
		TCON &= ~M_T0R;
#if MCU_FAMILY == 12
		counterValue = T0L;
#else
		counterValue = T0;
#endif
		break;
	
#ifdef TIMER_HAS_T1
	case TIMER1:
		TCON &= ~M_T1R;
#if MCU_FAMILY == 12
		counterValue = T1L;
#else
		counterValue = T1;
#endif
		break;
#endif // TIMER_HAS_T1

	case TIMER2:
		AUXR &= ~M_T2R;
#ifdef TIMER_HAS_T2
		counterValue = T2;
#endif
#ifdef TIMER_HAS_BRT
		counterValue = BRT;
#endif
		break;

#ifdef TIMER_HAS_T3_T4
	case TIMER3:
		T4T3M &= ~M_T3R;
		counterValue = T3;
		break;
	
	case TIMER4:
		T4T3M &= ~M_T4R;
		counterValue = T4;
		break;
#endif // TIMER_HAS_T3_T4
	}
	
	return counterValue;
}


#ifdef TIMER_HAS_PRESCALERS

	void setTimerPrescaler(Timer timer, uint8_t divisor) {
		// sysclk is divided by (TMxPS + 1)
		divisor--;
		
		switch (timer) {
	#ifdef TIMER_HAS_T2
		case TIMER2:
			TM2PS = divisor;
			break;
	#endif

	#ifdef TIMER_HAS_T3_T4
		case TIMER3:
			TM3PS = divisor;
			break;
		
		case TIMER4:
			TM4PS = divisor;
			break;
	#endif // TIMER_HAS_T3_T4
		}
	}

#endif // TIMER_HAS_PRESCALERS
