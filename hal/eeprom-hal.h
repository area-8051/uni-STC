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
#ifndef _EEPROM_HAL_H
#define _EEPROM_HAL_H

/**
 * @file eeprom-hal.h
 * 
 * EEPROM abstraction layer definitions.
 * 
 * Supported MCU families: STC12, STC15, STC8.
 * 
 * Dependencies: none.
 */

#define EEPROM_UNINITIALISED 0xff
#define EEPROM_PAGE_SIZE ((uint16_t) 512)

// Preferred
void eepromReadBlock(uint16_t address, uint8_t *data, uint16_t byteCount);
void eepromWriteBlock(uint16_t address, const uint8_t *data, uint16_t byteCount);

// For specific use cases only
uint8_t eepromReadByte(uint16_t address);
void eepromWriteByte(uint16_t address, uint8_t value);
void eepromErasePage(uint16_t addressWithinPage);

#endif // _EEPROM_HAL_H
