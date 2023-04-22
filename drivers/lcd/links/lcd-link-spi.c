/*
 * SPDX-License-Identifier: BSD-2-Clause
 * 
 * Copyright (c) 2023 Vincent DEFERT. All rights reserved.
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
#include <lcd/links/lcd-link-spi.h>
#include <spi-hal.h>

/**
 * @file lcd-link-spi.c
 * 
 * LCD "4-line" SPI communication implementation.
 */

void lcdLinkInitialise(LCDInterface *interface) {
	LCDSPILinkConfig *config = (LCDSPILinkConfig *) interface->linkConfig;
	
	gpioConfigure(&config->csOutput);
	gpioWrite(&config->csOutput, 1);
	
	gpioConfigure(&config->commandDataOutput);
	gpioWrite(&config->commandDataOutput, 0);
	
	spiConfigure(
		SPI_MASTER, 
		SPI_MSB_FIRST, 
		SPI_CLK_IDLE_HIGH, 
		SPI_SAMPLE_ON_TRAILING_EDGE, 
		spiSelectSpeed(config->spiClockFrequency), 
		config->spiPinSwitch, 
		GPIO_BIDIRECTIONAL_MODE
	);
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
	LCDSPILinkConfig *config = (LCDSPILinkConfig *) interface->linkConfig;
	
	gpioWrite(&config->commandDataOutput, dataType);
	gpioWrite(&config->csOutput, 0);
	
	volatile bool readyFlag = false;
	
	spiSend(&byteValue, 1, &readyFlag);
	
	while (!readyFlag);
	
	gpioWrite(&config->csOutput, 1);
}

// Suppress warning "unreferenced function argument"
#pragma save
#pragma disable_warning 85
uint8_t lcdLinkDataIn(LCDInterface *interface, LCDDataType dataType) {
	return 0;
}

#pragma restore
