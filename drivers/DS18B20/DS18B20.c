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
#include <DS18B20/DS18B20.h>
#include <onewire/onewire.h>

/**
 * @file DS18B20.c
 * 
 * Driver for the DS18B20 temperature sensor: implementation.
 */

typedef enum {
	DS18B20_readROM = 0x33,
	DS18B20_matchROM = 0x55,
	DS18B20_searchROM = 0xf0,
	DS18B20_skipROM = 0xcc,
	DS18B20_alarmSearch = 0xec,
	DS18B20_convertT = 0x44,
	DS18B20_writeScratchpad = 0x4e,
	DS18B20_readScratchpad = 0xbe,
	DS18B20_copyScratchpad = 0x48,
	DS18B20_recallE2 = 0xb8,
	DS18B20_readPowerSupply = 0xb4,
} DS18B20Command;

static void ds18b20SendCommand(DS18B20Sensor *sensor, DS18B20Command command) {
	onewireSendBytes(&sensor->oneWirePin, &command, 1);
}

DS18B20StatusCode ds18b20Initialise(DS18B20Sensor *sensor, DS18B20Precision precision) {
	DS18B20StatusCode result = DS18B20_InitOK;
	
	if (onewireInitialise(&sensor->oneWirePin)) {
		result = DS18B20_InvalidOneWirePin;
	}
	
	if (result == DS18B20_InitOK) {
		if (onewireReset(&sensor->oneWirePin)) {
			result = DS18B20_NoOneWireSlave;
		}
	}
	
	if (result == DS18B20_InitOK) {
		// At least one DS18B20 is present on the 1-wire bus
		ds18b20SendCommand(sensor, DS18B20_readROM);
		onewireReceiveBytes(&sensor->oneWirePin, sensor->__romCode, sizeof(sensor->__romCode));
		
		sensor->__buffer[0] = 0;
		sensor->__buffer[1] = 0;
		sensor->__buffer[2] = 0x1f | (precision << 5);
		ds18b20SendCommand(sensor, DS18B20_writeScratchpad);
		onewireSendBytes(&sensor->oneWirePin, sensor->__buffer, 3);
	}
	
	return result;
}

int16_t ds18b20ReadTemperature(DS18B20Sensor *sensor) {
	onewireReset(&sensor->oneWirePin);
	
	ds18b20SendCommand(sensor, DS18B20_matchROM);
	onewireSendBytes(&sensor->oneWirePin, sensor->__romCode, sizeof(sensor->__romCode));
	
	ds18b20SendCommand(sensor, DS18B20_convertT);
	onewireWaitForCompletion(&sensor->oneWirePin);
	
	onewireReset(&sensor->oneWirePin);
	
	ds18b20SendCommand(sensor, DS18B20_matchROM);
	onewireSendBytes(&sensor->oneWirePin, sensor->__romCode, sizeof(sensor->__romCode));
	
	ds18b20SendCommand(sensor, DS18B20_readScratchpad);
	onewireReceiveBytes(&sensor->oneWirePin, sensor->__buffer, sizeof(sensor->__buffer));
	
	// Temperature is in the first 2 bytes, LSB first, represented in
	// fixed-point format with the decimal point between bits 4 and 3.
	return (int16_t) (((uint16_t) sensor->__buffer[1]) << 8 | sensor->__buffer[0]);
}
