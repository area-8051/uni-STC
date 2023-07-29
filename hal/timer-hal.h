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
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8*
 * 
 * Dependencies:
 * 
 *     none
 * 
 * **IMPORTANT:** Some functionalities need to be individually enabled
 * via the following macros when needed:
 * 
 * HAL_TIMER_API_STOP_TIMER     stopTimer
 */

#include <hal-defs.h>

typedef enum {
	// Frequency or Baud rate, of course.
	TIMER_FREQUENCY_OK = 0,
	TIMER_FREQUENCY_TOO_HIGH,
	TIMER_FREQUENCY_TOO_LOW,
} TimerStatus;

uint32_t baudRateToSysclkDivisor(uint32_t baudRate);

uint32_t frequencyToSysclkDivisor(uint32_t frequency);

// timerControl affects Timers 0 & 1 only (ignored for the others).
TimerStatus startTimer(Timer timer, uint32_t sysclkDivisor, OutputEnable enableOutput, InterruptEnable enableInterrupt, CounterControl timerControl);

#ifdef HAL_TIMER_API_STOP_TIMER
// Returns the value of the counter once stopped (useful to measure elapsed time).
uint16_t stopTimer(Timer timer);
#endif // HAL_TIMER_API_STOP_TIMER

/*
 * The prototype of timer <n>'s ISR is:
 * 
 * INTERRUPT(timer<n>_isr, TIMER<n>_INTERRUPT);
 * 
 * Remember that when ISR are defined in a separate source file,
 * they MUST also be declared in the source file defining main()
 * for SDCC to properly make their vector point at their address.
 */

#endif // _TIMER_HAL_H
