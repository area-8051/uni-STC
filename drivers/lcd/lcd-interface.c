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
#include <lcd/lcd-interface.h>
#include <lcd/lcd-link-impl.h>

/**
 * @file lcd-interface.c
 * 
 * LCD communication interface abstraction: implementation.
 */

void lcdInitialiseInterface(LCDInterface *interface) {
	interface->__controllerLinkConfigured = 0;
	lcdLinkInitialise(interface);
	
	if (interface->resetOutput.count) {
		gpioConfigure(&interface->resetOutput);
		gpioWrite(&interface->resetOutput, 0);
	}
}

void lcdLinkConfigurationBegins(LCDInterface *interface) {
	interface->__controllerLinkConfigured = 0;
}

void lcdLinkConfigurationComplete(LCDInterface *interface) {
	interface->__controllerLinkConfigured = 1;
}

uint8_t lcdGetLinkWidth(LCDInterface *interface) {
	return lcdLinkGetDataWidth(interface);
}

uint8_t lcdIsLinkParallel(LCDInterface *interface) {
	return lcdLinkIsParallel(interface);
}

void lcdSendCommand(LCDInterface *interface, uint8_t command) {
	lcdLinkDataOut(interface, LCD_Instruction, command);
}

void lcdSendData(LCDInterface *interface, uint8_t data) {
	lcdLinkDataOut(interface, LCD_Data, data);
}

uint8_t lcdReadStatus(LCDInterface *interface) {
	return lcdLinkDataIn(interface, LCD_Instruction);
}

uint8_t lcdReadData(LCDInterface *interface) {
	return lcdLinkDataIn(interface, LCD_Data);
}
