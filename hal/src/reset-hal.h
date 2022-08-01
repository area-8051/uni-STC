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
#ifndef _RESET_HAL_H
#define _RESET_HAL_H

/**
 * @file reset-hal.h
 * 
 * System reset abstraction definitions.
 * 
 * Supported MCU families: STC12, STC15, STC8.
 * 
 * Dependencies: none.
 */

// Watchdog ------------------------------------------------------------

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
	WDT_disabledInIdleMode = 0,
	WDT_enabledInIdleMode,
} WatchdogIdleMode;

WatchdogPrescaler millisecondsToWatchdogPrescaler(uint16_t overflowTimeMilliseconds);

uint16_t watchdogPrescalerToMilliseconds(WatchdogPrescaler prescaler);

void startWatchdog(WatchdogPrescaler prescaler, WatchdogIdleMode idleMode);

void clearWatchdog();

// Software reset ------------------------------------------------------

typedef enum {
	SWRST_FlashMemory = 0,
	SWRST_EEPROM = 1,
} SWRST_ResetEntryPoint;

void softwareReset(SWRST_ResetEntryPoint entryPoint);

// Low-voltage detector ------------------------------------------------

#if MCU_FAMILY == 8
// The LVD of the STC12 and STC15 is very different and much less
// convenient than the STC8's, so only the STC8 is supported.

typedef enum {
	LVD_Action_Interrupt = 0,
	LVD_Action_Reset,
} LVD_Action;

typedef enum {
	LVD_Threshold_2V0 = 0, // 2.2V on the STC8A8KxxS4A12 only.
	LVD_Threshold_2V4,
	LVD_Threshold_2V7,
	LVD_Threshold_3V0,
} LVD_Threshold;

/**
 * When using LVD_Action_Interrupt, you have to provide an ISR with the
 * following prototype: INTERRUPT_USING(__lvd_isr, LVD_INTERRUPT, 1);
 */
void enableLowVoltageDetector(LVD_Threshold threshold, LVD_Action action);
#endif // MCU_FAMILY == 8

typedef enum {
	PowerOnReset = 0,
	LowVoltageDetected,
	OtherReset,
} ResetOrigin;

ResetOrigin getResetOrigin();

#endif // _RESET_HAL_H
