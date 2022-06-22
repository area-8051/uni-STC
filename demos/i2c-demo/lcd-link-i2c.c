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
#include "lcd-link-impl.h"
#include "lcd-link-i2c.h"
#include "i2c-hal.h"

/**
 * @file lcd-link-i2c.c
 * 
 * LCD I2C communication implementation.
 */

/*
 * PCF8574 pin assignments
 * 
 * P7 = D7
 * P6 = D6
 * P5 = D5
 * P4 = D4
 * P3 = Backlight Enable
 * P2 = E
 * P1 = RW
 * P0 = RS
 */

#define MASK_BL 0x08
#define MASK_EN 0x04
#define MASK_RW 0x02
#define MASK_RS 0x01

static void __sendByte(LCD_I2CLinkConfig *config, uint8_t byte) {
	i2cStartCommand(config->slaveAddress, I2C_WRITE);
	i2cSendByte(byte);
	i2cStop();
}

static uint8_t __readByte(LCD_I2CLinkConfig *config) {
	i2cStartCommand(config->slaveAddress, I2C_READ);
	uint8_t result = i2cReadByteSendAck(I2C_ACK);
	i2cStop();
	
	return result;
}

void lcdLink_initialise(LCD_Interface *interface) {
	LCD_I2CLinkConfig *config = (LCD_I2CLinkConfig *) interface->linkConfig;
	i2cInitialiseMaster(config->pinSwitch, I2C_CLOCK_100kHz);
	__sendByte(config, 0);
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
uint8_t lcdLink_getDataWidth(LCD_Interface *interface) {
	return 4;
}

// Suppress warning "unreferenced function argument"
#pragma disable_warning 85
uint8_t lcdLink_isParallel(LCD_Interface *interface) {
	return 1;
}

void lcdLink_dataOut(LCD_Interface *interface, LCD_DataType dataType, uint8_t byteValue) {
	LCD_I2CLinkConfig *config = (LCD_I2CLinkConfig *) interface->linkConfig;
	uint8_t data = (byteValue & 0xf0) | MASK_BL | MASK_EN | (LCD_Write << 1) | dataType;
	__sendByte(config, data);

	if (interface->__controllerLinkConfigured) {
		__sendByte(config, data & ~MASK_EN);
		data = (byteValue << 4) | MASK_BL | MASK_EN | (LCD_Write << 1) | dataType;
		__sendByte(config, data);
	}
	
	__sendByte(config, data & ~MASK_EN);
}

uint8_t lcdLink_dataIn(LCD_Interface *interface, LCD_DataType dataType) {
	// Read operations are NOT supported through I2C.
	return 0;
}
