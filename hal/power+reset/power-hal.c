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
#include "power-hal.h"

/**
 * @file power-hal.c
 * 
 * Power management abstraction implementation for STC12, STC15 and STC8.
 * 
 * TODO: add clock control.
 */

void enterIdleMode() {
	PCON |= M_IDL;
	NOP();
	NOP();
}

void enterPowerDownMode() {
	PCON |= M_PD;
	NOP();
	NOP();
}

void configureUnusedGpioPins(GpioPort port, uint8_t mask) {
	switch (port) {
#ifdef GPIO_HAS_P0
	case GPIO_PORT0:
		P0M1 &= ~mask;
		P0M0 &= ~mask;
		P0 |= mask;
		break;
#endif // GPIO_HAS_P0

#ifdef GPIO_HAS_P1
	case GPIO_PORT1:
		P1M1 &= ~mask;
		P1M0 &= ~mask;
		P1 |= mask;
		break;
#endif // GPIO_HAS_P1

#ifdef GPIO_HAS_P2
	case GPIO_PORT2:
		P2M1 &= ~mask;
		P2M0 &= ~mask;
		P2 |= mask;
		break;
#endif // GPIO_HAS_P2

#ifdef GPIO_HAS_P3
	case GPIO_PORT3:
		P3M1 &= ~mask;
		P3M0 &= ~mask;
		P3 |= mask;
		break;
#endif // GPIO_HAS_P3

#ifdef GPIO_HAS_P4
	case GPIO_PORT4:
		P4M1 &= ~mask;
		P4M0 &= ~mask;
		P4 |= mask;
		break;
#endif // GPIO_HAS_P4

#ifdef GPIO_HAS_P5
	case GPIO_PORT5:
		P5M1 &= ~mask;
		P5M0 &= ~mask;
		P5 |= mask;
		break;
#endif // GPIO_HAS_P5

#ifdef GPIO_HAS_P06
	case GPIO_PORT6:
		P6M1 &= ~mask;
		P6M0 &= ~mask;
		P6 |= mask;
		break;
#endif // GPIO_HAS_P6

#ifdef GPIO_HAS_P7
	case GPIO_PORT7:
		P7M1 &= ~mask;
		P7M0 &= ~mask;
		P7 |= mask;
		break;
#endif // GPIO_HAS_P7
	}
}

#ifdef MCU_HAS_WAKE_UP_TIMER
	// The TRM says the exact frequency can be obtained from memory
	// locations 0xf8 and 0xf9, but their content is always 0, so...
	#define WAKE_UP_TIMER_CLOCK_FREQ 32000UL
	
	uint16_t millisecondsToWakeUpCount(uint16_t msTime) {
		uint32_t divisor = WAKE_UP_TIMER_CLOCK_FREQ * ((uint32_t) msTime) / 16000UL;
		
		return divisor // equivalent to: divisor > 0
			? (divisor & 0xffff8000UL // equivalent to: divisor > 32767
				? 32767
				: (((uint16_t) (divisor)) - 1)
			)
			: 0;
	}

	void enablePowerDownWakeUpTimer(uint16_t wakeUpCount) {
		// Set the WKTEN bit
		wakeUpCount |= 0x8000;
		
		WKTC = wakeUpCount;
	}
#endif // MCU_HAS_WAKE_UP_TIMER
