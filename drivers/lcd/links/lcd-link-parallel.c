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
#include <lcd/lcd-link-impl.h>
#include <lcd/links/lcd-link-parallel.h>

/**
 * @file lcd-link-parallel.c
 * 
 * LCD parallel communication implementation.
 */

void lcdLinkInitialise(LCDInterface *interface) {
	LCDParallelLinkConfig *config = (LCDParallelLinkConfig *) interface->linkConfig;
	gpioConfigure(&config->dataBus);
	gpioConfigure(&config->enOutput);
	gpioConfigure(&config->rwOutput);
	gpioConfigure(&config->rsOutput);
	
	gpioWrite(&config->enOutput, 0);
	gpioWrite(&config->rwOutput, 0);
	gpioWrite(&config->rsOutput, 0);
}

uint8_t lcdLinkGetDataWidth(LCDInterface *interface) {
	// From the client code's perspective, the data link is 8 bits wide, 
	// how they are physically (serial or parallel) sent doesn't matter. 
	// The only situation when it has an impact is when initialising an 
	// LCD device over a 4-bit parallel interface.
	return ((LCDParallelLinkConfig *) interface->linkConfig)->dataBus.count;
}

// Suppress warning "unreferenced function argument"
#pragma save
#pragma disable_warning 85

uint8_t lcdLinkIsParallel(LCDInterface *interface) {
	return 1;
}

#pragma restore

void lcdLinkDataOut(LCDInterface *interface, LCDDataType dataType, uint8_t byteValue) {
	LCDParallelLinkConfig *config = (LCDParallelLinkConfig *) interface->linkConfig;
	gpioWrite(&config->rsOutput, dataType);
	gpioWrite(&config->rwOutput, LCD_Write);
	gpioWrite(&config->enOutput, 1);

	if (config->dataBus.count == 8) {
		gpioWrite(&config->dataBus, byteValue);
	} else {
		gpioWrite(&config->dataBus, byteValue >> 4);

		if (interface->__controllerLinkConfigured) {
			gpioWrite(&config->enOutput, 0);
			gpioWrite(&config->enOutput, 1);
			gpioWrite(&config->dataBus, byteValue & 0x0f);
        }
	}

	gpioWrite(&config->enOutput, 0);
}

uint8_t lcdLinkDataIn(LCDInterface *interface, LCDDataType dataType) {
	uint8_t result = 0;
	LCDParallelLinkConfig *config = (LCDParallelLinkConfig *) interface->linkConfig;
	gpioWrite(&config->rsOutput, dataType);
	gpioWrite(&config->rwOutput, LCD_Read);
	gpioWrite(&config->enOutput, 1);
	result = gpioRead(&config->dataBus);

	if (config->dataBus.count != 8) {
		gpioWrite(&config->enOutput, 0);
		gpioWrite(&config->enOutput, 1);
		result = (result << 4) | gpioRead(&config->dataBus);
	}

	gpioWrite(&config->enOutput, 0);

	return result;
}
