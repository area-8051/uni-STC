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
#ifndef _DS12B20_H
#define _DS12B20_H

#include <gpio-hal.h>

/**
 * @file DS18B20.h
 * 
 * Driver for the DS18B20 temperature sensor: definitions.
 * 
 * **IMPORTANT:** this driver assumes there's only one DS18B20 on the 
 * 1-Wire bus, that it's powered through its VDD pin, and that a 4.7k 
 * pull-up resistor is connected to its 1-Wire pin.
 */

/**
 * Precision of the conversion.
 * 
 * The higher the precision, the more accurate the result, and the longer 
 * the conversion.
 */
typedef enum {
	DS18B20_9bit = 0,  /*!< Max. conv. time = 93.75ms, Accuracy = 0.5°C */
	DS18B20_10bit = 1, /*!< Max. conv. time = 187.5ms, Accuracy = 0.25°C */
	DS18B20_11bit = 2, /*!< Max. conv. time = 375ms,   Accuracy = 0.125°C */
	DS18B20_12bit = 3, /*!< Max. conv. time = 750ms,   Accuracy = 0.0625°C */
} DS18B20Precision;

/**
 * Sensor configuration and state.
 * 
 * **IMPORTANT:** symbols whose names beginning with 2 underscores are 
 * used internally by the driver.
 */
typedef struct {
	GpioConfig oneWirePin;	/*!< GPIO port and pin of the 1-Wire bus. 
								MUST be initialised by the caller. */
	unsigned char __romCode[8];
	unsigned char __buffer[9];
} DS18B20Sensor;

/**
 * Initialisation status codes.
 */
typedef enum {
	DS18B20_InitOK = 0,
	DS18B20_InvalidOneWirePin,
	DS18B20_NoOneWireSlave,
} DS18B20StatusCode;

/**
 * Configures the GPIO pin, checks the presence of the sensor and sets 
 * its conversion precision.
 * 
 * **IMPORTANT:** sensor->gpioConfig MUST reference a single GPIO pin 
 * configured in open-drain mode.
 */
DS18B20StatusCode ds18b20Initialise(DS18B20Sensor *sensor, DS18B20Precision precision);

/**
 * Starts a conversion and returns the temperature in Celsius as a 
 * fixed-point number, with the decimal point is between bits 4 and 3.
 * 
 * If you only want the integral part of the number, you need to divide 
 * it by 16.
 */
int16_t ds18b20ReadTemperature(DS18B20Sensor *sensor);

#endif // _DS12B20_H
