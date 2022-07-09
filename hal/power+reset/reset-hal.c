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
#include "reset-hal.h"

/**
 * @file reset-hal.c
 * 
 * System reset abstraction implementation.
 */

WatchdogPrescaler millisecondsToWatchdogPrescaler(uint16_t overflowTime) {
	uint16_t divisor = (uint16_t) (((uint32_t) overflowTime) * (MCU_FREQ / 1000UL) / (12UL * 32768UL));
	WatchdogPrescaler result = WDT_SYSCLCK_DIV_24;
	
	if (divisor >= 256) {
		result = WDT_SYSCLCK_DIV_3072;
	} else if (divisor > 2) {
		// Determine magnitude of the divisor
		uint16_t n = divisor;
		uint8_t p = 0;
		
		while (n) {
			p++;
			n >>= 1;
		}
		
		// Round to closest power of 2
		if ((divisor + (1 << (p - 1))) >= (1 << (p + 1))) {
			p++;
		}
		
		result = (WatchdogPrescaler) (p - 1);
	}
	
	return result;
}

uint16_t watchdogPrescalerToMilliseconds(WatchdogPrescaler prescaler) {
	return ((uint16_t) (12UL * 32768UL / (MCU_FREQ / 1000UL))) << (prescaler + 1);
}

void startWatchdog(WatchdogPrescaler prescaler, WatchdogIdleMode idleMode) {
#if MCU_FAMILY == 15
	// Ensure the STC15 behaves consistently with STC12 and STC8
	IAP_CONTR &= ~M_SWBS;
#endif // MCU_FAMILY == 15

	WDT_CONTR = M_EN_WDT | (prescaler << P_WDT_PS)
		| (idleMode == WDT_enabledInIdleMode ? M_IDL_WDT : 0);
}

void clearWatchdog() {
	WDT_CONTR |= M_CLR_WDT;
}

void softwareReset(SWRST_ResetEntryPoint entryPoint) {
	IAP_CONTR = (entryPoint << P_SWBS) | M_SWRST;
}

#if MCU_FAMILY == 8
void enableLowVoltageDetector(LVD_Threshold threshold, LVD_Action action) {
	// Make sure the flag is cleared (might be set due to prior LVD reset)
	PCON &= ~M_LVDF;
	RSTCFG = (RSTCFG & M_P54RST) | (action << P_ENLVR) | threshold;
	
	if (action == LVD_Action_Interrupt) {
		IE1 |= M_ELVD;
	}
}
#endif // MCU_FAMILY == 8

ResetOrigin getResetOrigin() {
	ResetOrigin result = PowerOnReset;
	
	if (PCON & M_POF) {
		PCON &= ~M_POF;
	} else if (PCON & M_LVDF) {
		PCON &= ~M_LVDF;
		result = LowVoltageDetected;
	} else {
		result = OtherReset;
	}
	
	return result;
}
