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
#include <onewire/onewire.h>
#include <delay.h>

/**
 * @file onewire.c
 * 
 * Driver for the Dallas 1-Wire protocol: implementation.
 */

OneWire_StatusCode onewireInitialise(GpioConfig *gpioConfig) {
	OneWire_StatusCode result = OneWire_InitOK;
	
	if (gpioConfig == NULL) {
		result = OneWire_NullGpioConfig;
	} else if(gpioConfig->count != 1) {
		result = OneWire_NotSinglePin;
	} else if (gpioConfig->pinMode != GPIO_OPEN_DRAIN_MODE) {
		result = OneWire_NotOpenDrain;
	} else {
		gpioConfigure(gpioConfig);
		// Set 1-Wire bus in idle state
		gpioWrite(gpioConfig, 1);
	}
	
	return result;
}

uint8_t onewireReset(GpioConfig *gpioConfig) {
	gpioWrite(gpioConfig, 0);
	// datasheet says "at least 480us" to reset slaves
	delay1us(480);
	gpioWrite(gpioConfig, 1);
	// datasheet says "15 to 60us" before slave pulls line low for 60-240us,
	// so sampling after a bit more than 70us should be ok il all cases,
	// that is both within 15+60 (fastest slave) and 60+240 (slowest slave).
	delay1us(70);
	// Bus should now be low if a slave is present and working
	uint8_t result = gpioRead(gpioConfig);
	// datasheet says "at least 480us" from the moment master goes high
	// and we have already waited for 70us.
	delay1us(410);
	
	return result;
}

static void __onewireWriteBit(GpioConfig *gpioConfig, uint8_t bit) {
	// Begin write slot
	gpioWrite(gpioConfig, 0);
	// Datasheet says master pulls low "at least 1us",
	// which is the case due to the use of a GPIO abstraction.
	// Now send the data bit to the slave
	gpioWrite(gpioConfig, bit);
	// End write slot, which datasheet says should last "at least 60us"
	delay1us(60);
	gpioWrite(gpioConfig, 1);
}

static uint8_t __onewireReadBit(GpioConfig *gpioConfig) {
	// Begin read slot
	gpioWrite(gpioConfig, 0);
	// Datasheet says master pulls low "at least 1us",
	// which is the case due to the use of a GPIO abstraction.
	// Now, let the slave talk
	gpioWrite(gpioConfig, 1);
	// Master should sample input within 15us
	delay1us(10);
	uint8_t result = gpioRead(gpioConfig);
	// End read slot, which datasheet says should last "at least 60us",
	// taking into account we've already waited 10us.
	delay1us(50);
	
	return result;
}

void onewireSendBytes(GpioConfig *gpioConfig, uint8_t *buffer, uint8_t count) {
	for (uint8_t n = 0; n < count; n++) {
		uint8_t byte = buffer[n];
		
		for (uint8_t bit = 8; bit; bit --) {
			// Bytes are sent LSB first
			__onewireWriteBit(gpioConfig, byte & 1);
			byte = byte >> 1;
		} 
	}
}

void onewireReceiveBytes(GpioConfig *gpioConfig, uint8_t *buffer, uint8_t count) {
	for (uint8_t n = 0; n < count; n++) {
		uint8_t byte = 0;
		
		for (uint8_t bit = 8; bit; bit --) {
			// Bytes are received LSB first, hence the 0x80
			byte = byte >> 1;
			byte |= __onewireReadBit(gpioConfig) ? 0x80 : 0;
		}
		
		buffer[n] = byte;
	}
}

void onewireWaitForCompletion(GpioConfig *gpioConfig) {
	while (!__onewireReadBit(gpioConfig));
}
