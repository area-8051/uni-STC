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
#ifndef _ONEWIRE_H
#define _ONEWIRE_H

#include <gpio-hal.h>

/**
 * @file onewire.h
 * 
 * Driver for the Dallas 1-Wire protocol: definitions.
 */

/**
 * Initialisation status codes.
 */
typedef enum {
	OneWire_InitOK = 0,
	OneWire_NullGpioConfig,
	OneWire_NotSinglePin,
	OneWire_NotOpenDrain,
} OneWire_StatusCode;

/**
 * Configures the GPIO pin connected to the 1-Wire bus.
 * 
 * **IMPORTANT:** gpioConfig MUST reference a single GPIO pin 
 * configured in open-drain mode.
 */
OneWire_StatusCode onewireInitialise(GpioConfig *gpioConfig);

/**
 * Resets all peripherals connected to the 1-Wire bus.
 * 
 * @returns zero in case of success, non-zero if no slave is present.
 */
uint8_t onewireReset(GpioConfig *gpioConfig);

/**
 * Sends a sequence of bytes.
 */
void onewireSendBytes(GpioConfig *gpioConfig, uint8_t *buffer, uint8_t count);

/**
 * Receives a sequence of bytes.
 */
void onewireReceiveBytes(GpioConfig *gpioConfig, uint8_t *buffer, uint8_t count);


/**
 * Waits until the last command completes.
 * 
 * **NOTE** only required by a few commands.
 */
void onewireWaitForCompletion(GpioConfig *gpioConfig);

#endif // _ONEWIRE_H
