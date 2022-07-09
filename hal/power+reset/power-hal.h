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
#ifndef _POWER_HAL_H
#define _POWER_HAL_H

/**
 * @file power-hal.h
 * 
 * Power management abstraction definitions.
 * 
 * Supported MCU families: STC12, STC15, STC8.
 * 
 * Dependencies: none.
 */

// Only stops CPU
void enterIdleMode();

// Stops both CPU and peripherals
void enterPowerDownMode();

#ifdef MCU_HAS_WAKE_UP_TIMER
	/*
	 * The clock of this timer is distinct from SYSCLK, and is about 32 kHz.
	 * wakeUpCount must be < 32768 (15-bit timer). This clock is pre-divided
	 * by 16 before reaching the counter. The division factor is 1 + the 
	 * reload value of the counter.
	 * 
	 * The timer starts automatically when entering power-down or stop mode.
	 */

	uint16_t millisecondsToWakeUpCount(uint16_t msTime);

	void enablePowerDownWakeUpTimer(uint16_t wakeUpCount);
#endif // MCU_HAS_WAKE_UP_TIMER

#endif // _POWER_HAL_H
