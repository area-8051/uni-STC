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
#ifndef _LCD_LINK_IMPL_H
#define _LCD_LINK_IMPL_H

#include "lcd-interface.h"

/**
 * @file lcd-link-impl.h
 * 
 * LCD communication link abstraction: definitions.
 */

typedef enum {
	LCD_Instruction = 0,
	LCD_Data = 1,
} LCD_DataType;

typedef enum {
	LCD_Write = 0,
	LCD_Read = 1,
} LCD_TransferOperation;

void lcdLink_initialise(LCD_Interface *interface);
uint8_t lcdLink_getDataWidth(LCD_Interface *interface);
uint8_t lcdLink_isParallel(LCD_Interface *interface);
void lcdLink_dataOut(LCD_Interface *interface, LCD_DataType dataType, uint8_t byteValue);
uint8_t lcdLink_dataIn(LCD_Interface *interface, LCD_DataType dataType);

#endif // _LCD_LINK_IMPL_H
