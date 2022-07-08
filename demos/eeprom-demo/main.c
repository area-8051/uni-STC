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
#include "delay.h"

#include "eeprom-hal.h"
#include "uart-hal.h"
#include "serial-console.h"

#include <stdio.h>
#include <string.h>

static uint8_t buffer[26];

static void printStatus(const char *message) {
	printf("%s\r\n", message);
	printf("Error indicator: %hhx\r\n", IAP_CONTR & M_CMD_FAIL);
}
	
static void printBuffer(const char *message) {
	printStatus(message);
	
	for (size_t i = 0; i < sizeof(buffer); i++) {
		if (i) {
			printf(" ");
		}
		
		printf("%02hhx", buffer[i]);
	}
	
	printf("\r\nText: ");
	
	if (buffer[0] != EEPROM_UNINITIALISED) {
		printf("%s", buffer);
	}
	
	printf("\r\n");
}

void main() {
	serialConsoleInitialise(
		CONSOLE_UART, 
		CONSOLE_SPEED, 
		CONSOLE_PIN_CONFIG
	);
	
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	delay1ms(10000);
	
	const uint16_t eepromAddress = 0;
	
	eepromReadBlock(eepromAddress, buffer, sizeof(buffer));
	printBuffer("Read uninitialised EEPROM");
	
	strcpy(buffer, "A somewhat long string.");
	eepromWriteBlock(eepromAddress, buffer, sizeof(buffer));
	printStatus("Write long string into EEPROM");
	
	eepromReadBlock(eepromAddress, buffer, sizeof(buffer));
	printBuffer("Read long string from EEPROM");
	
	memset(buffer, EEPROM_UNINITIALISED, sizeof(buffer));
	strcpy(buffer, "A shorter string.");
	eepromWriteBlock(eepromAddress, buffer, sizeof(buffer));
	printStatus("Write short string into EEPROM");
	
	eepromReadBlock(eepromAddress, buffer, sizeof(buffer));
	printBuffer("Read short string from EEPROM");
	
	eepromErasePage(eepromAddress);
	printStatus("Erase EEPROM page");
	
	eepromReadBlock(eepromAddress, buffer, sizeof(buffer));
	printBuffer("Read erased EEPROM");
	
	printf("Test complete.\r\n");
	
	while (1);
}
