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
#include <lcd/links/lcd-link-serial.h>

/**
 * @file lcd-link-serial.c
 * 
 * LCD serial communication implementation.
 */

static void __sendByte(LCDSerialLinkConfig *config, uint8_t byteValue) {
	// Note: bytes are sent MSB first
	uint8_t byte = byteValue;
	
	for (uint8_t bit = 8; bit; bit --) {
		// SCLK must stay high for at least 200 ns
		gpioWrite(&config->sclkOutput, 1);
		
		// Data bit must be sent at least 40 ns before SCLK goes low,
		// and remain stable at least 40 ns after SCLK went low
		gpioWrite(&config->dataInOut, byte & 0x80);
		byte = byte << 1;
		
		// SCLK must stay low for at least 200 ns
		gpioWrite(&config->sclkOutput, 0);
		
		// On an MCS-51 operating at 24 MHz, those timing requirements 
		// are easily satisfied, but it's a good idea to check they're 
		// still satisfied when porting to a faster MCU.
	}
}

static void __beginCommunication(LCDSerialLinkConfig *config, LCDDataType dataType, LCDTransferOperation operation) {
	gpioWrite(&config->csOutput, 1);
	__sendByte(config, 0xf8 | (operation << 2) | (dataType << 1));
}

static void __endCommunication(LCDSerialLinkConfig *config) {
	gpioWrite(&config->csOutput, 0);
	gpioWrite(&config->sclkOutput, 0);
}

void lcdLinkInitialise(LCDInterface *interface) {
	LCDSerialLinkConfig *config = (LCDSerialLinkConfig *) interface->linkConfig;
	gpioConfigure(&config->dataInOut);
	gpioConfigure(&config->csOutput);
	gpioConfigure(&config->sclkOutput);
	
	gpioWrite(&config->dataInOut, 0);
	gpioWrite(&config->csOutput, 0);
	gpioWrite(&config->sclkOutput, 0);
}

// Suppress warning "unreferenced function argument"
#pragma save
#pragma disable_warning 85

uint8_t lcdLinkGetDataWidth(LCDInterface *interface) {
	return 8;
}

uint8_t lcdLinkIsParallel(LCDInterface *interface) {
	return 0;
}

#pragma restore

void lcdLinkDataOut(LCDInterface *interface, LCDDataType dataType, uint8_t byteValue) {
	LCDSerialLinkConfig *config = (LCDSerialLinkConfig *) interface->linkConfig;
	__beginCommunication(config, dataType, LCD_Write);
	__sendByte(config, byteValue & 0xf0);
	__sendByte(config, byteValue << 4);
	__endCommunication(config);
}

// Suppress warning "unreferenced function argument"
#pragma save
#pragma disable_warning 85

uint8_t lcdLinkDataIn(LCDInterface *interface, LCDDataType dataType) {
	/*
	 * Data sheet says read operations are NOT supported in serial mode, 
	 * even though the timing diagram shows the position of the RW bit 
	 * in the packet. I tested and confirm reads don't work.
	 */
	return 0;
}

#pragma restore
