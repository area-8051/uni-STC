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
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/**
 * @file lcd-interface.h
 * 
 * LCD communication interface abstraction: definitions.
 */

typedef struct {
	void *linkConfig;
	uint8_t __controllerLinkConfigured;
} LCD_Interface;

void lcd_initialiseInterface(LCD_Interface *interface);
void lcd_linkConfigurationBegins(LCD_Interface *interface);
void lcd_linkConfigurationComplete(LCD_Interface *interface);
void lcd_sendCommand(LCD_Interface *interface, uint8_t command);
void lcd_sendData(LCD_Interface *interface, uint8_t data);
uint8_t lcd_readStatus(LCD_Interface *interface);
uint8_t lcd_readData(LCD_Interface *interface);
uint8_t lcd_getLinkWidth(LCD_Interface *interface);
uint8_t lcd_isLinkParallel(LCD_Interface *interface);

#endif // _LCD_INTERFACE_H
