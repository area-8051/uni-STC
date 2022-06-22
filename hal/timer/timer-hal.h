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
#ifndef _TIMER_HAL_H
#define _TIMER_HAL_H

/**
 * @file timer-hal.h
 * 
 * Timer abstraction definitions.
 * 
 * Supported MCU families: STC12, STC15, STC8.
 * 
 * Dependencies: none.
 */

typedef enum {
	// Frequency or Baud rate, of course.
	TIMER_FREQUENCY_OK = 0,
	TIMER_FREQUENCY_TOO_HIGH,
	TIMER_FREQUENCY_TOO_LOW,
} Timer_Status;

typedef enum {
	TIMER_OUTPUT_DISABLE = 0,
	TIMER_OUTPUT_ENABLE,
} Timer_Output;

typedef enum {
	TIMER_INTERRUPT_DISABLE = 0,
	TIMER_INTERRUPT_ENABLE,
} Timer_Interrupt;

// Timers 0 & 1 only (ignored for the others).
typedef enum {
	TIMER_FREE_RUNNING = 0,
	TIMER_GATE_CONTROL
} Timer_Control;

uint32_t baudRateToSysclkDivisor(uint32_t baudRate);

uint32_t frequencyToSysclkDivisor(uint32_t frequency);

Timer_Status startTimer(Timer timer, uint32_t sysclkDivisor, Timer_Output enableOutput, Timer_Interrupt enableInterrupt, Timer_Control timerControl);

/*
 * The prototype of timer <n>'s ISR is:
 * 
 * void __timer<n>_isr() ISR_PARAM(TIMER<n>_INTERRUPT, 1);
 * 
 * Remember that when ISR are defined in a separate source file,
 * they MUST also be declared in the source file defining main()
 * for SDCC to properly make their vector point at their address.
 */

typedef enum {
	WDT_SYSCLCK_DIV_24 = 0,
	WDT_SYSCLCK_DIV_48,
	WDT_SYSCLCK_DIV_96,
	WDT_SYSCLCK_DIV_192,
	WDT_SYSCLCK_DIV_384,
	WDT_SYSCLCK_DIV_768,
	WDT_SYSCLCK_DIV_1536,
	WDT_SYSCLCK_DIV_3072,
} WatchdogPrescaler;

typedef enum {
	WDT_DISABLED_IN_IDLE_MODE = 0,
	WDT_ENABLED_IN_IDLE_MODE,
} WatchdogIdleMode;

// The WDT uses a 15-bit timer, so WDT time-out in seconds is:
// (prescaler * 32768) / Fsysclk.
void startWatchdog(WatchdogPrescaler prescaler, WatchdogIdleMode idleMode);

void clearWatchdog();

#endif // _TIMER_HAL_H
