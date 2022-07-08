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
#include "eeprom-hal.h"

/**
 * @file eeprom-hal.c
 * 
 * EEPROM abstraction layer implementation.
 */

#ifdef MCU_HAS_IAP_TPS
	#define EEPROM_TIMING ((MCU_FREQ + 500000UL) / 1000000UL)
#else
	#if MCU_FREQ >= 30000000UL
		#define EEPROM_TIMING 0
	#elif MCU_FREQ >= 24000000UL
		#define EEPROM_TIMING 1
	#elif MCU_FREQ >= 20000000UL
		#define EEPROM_TIMING 2
	#elif MCU_FREQ >= 12000000UL
		#define EEPROM_TIMING 3
	#elif MCU_FREQ >= 6000000UL
		#define EEPROM_TIMING 4
	#elif MCU_FREQ >= 3000000UL
		#define EEPROM_TIMING 5
	#elif MCU_FREQ >= 2000000UL
		#define EEPROM_TIMING 6
	#else
		#define EEPROM_TIMING 7
	#endif
#endif // MCU_HAS_IAP_TPS

#define EEPROM_PAGE_ADDR_MASK (~(EEPROM_PAGE_SIZE - 1))

typedef enum {
	IAP_setWaitTime = 0,
	IAP_byteRead = 1,
	IAP_byteWrite = 2,
	IAP_pageErase = 3,
} IAPCommand;

static void iapExecute(uint16_t address, IAPCommand command) {
	IAP_ADDRH = address >> 8;
	IAP_ADDRL = address & 0xff;
	IAP_CMD = command;
	IAP_TRIG = 0x5a;
	IAP_TRIG = 0xa5;
	NOP();
}

static void iapEnable() {
#ifdef MCU_HAS_IAP_TPS
	IAP_TPS = EEPROM_TIMING;
#else
	IAP_CONTR = EEPROM_TIMING;
#endif // MCU_HAS_IAP_TPS
	IAP_CONTR |= M_IAPEN;
}

static void iapDisable() {
	IAP_CONTR = 0;
	IAP_CMD = 0;
	IAP_TRIG = 0;
	IAP_ADDRH = 0xff;
	IAP_ADDRL = 0xff;
}

void eepromReadBlock(uint16_t address, uint8_t *data, uint16_t byteCount) {
	iapEnable();
	
	for (uint16_t byteIndex = 0; byteIndex < byteCount; byteIndex++) {
		iapExecute(address + byteIndex, IAP_byteRead);
		data[byteIndex] = IAP_DATA;
	}
	
	iapDisable();
}

void eepromWriteBlock(uint16_t address, const uint8_t *data, uint16_t byteCount) {
	iapEnable();
	
	uint16_t startPageAddress = address & EEPROM_PAGE_ADDR_MASK;
	uint16_t endPageAddress = (address + byteCount - 1) & EEPROM_PAGE_ADDR_MASK;
	
	for (uint16_t pageToErase = startPageAddress; pageToErase <= endPageAddress; pageToErase += EEPROM_PAGE_SIZE) {
		iapExecute(pageToErase, IAP_pageErase);
	}
	
	for (uint16_t byteIndex = 0; byteIndex < byteCount; byteIndex++) {
		IAP_DATA = data[byteIndex];
		iapExecute(address + byteIndex, IAP_byteWrite);
	}
	
	iapDisable();
}

void eepromWriteByte(uint16_t address, uint8_t value) {
	iapEnable();
	IAP_DATA = value;
	iapExecute(address, IAP_byteWrite);
	iapDisable();
}

uint8_t eepromReadByte(uint16_t address) {
	iapEnable();
	iapExecute(address, IAP_byteRead);
	uint8_t result = IAP_DATA;
	iapDisable();
	
	return result;
}

void eepromErasePage(uint16_t addressWithinPage) {
	iapEnable();
	uint16_t pageStartAddress = addressWithinPage & EEPROM_PAGE_ADDR_MASK;
	iapExecute(pageStartAddress, IAP_pageErase);
	iapDisable();
}
