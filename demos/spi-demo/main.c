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
#include <delay.h>
#include <gpio-hal.h>
#include <spi-hal.h>
#include <uart-hal.h>
#include <serial-console.h>
#include <stdio.h>

static GpioConfig csPin = GPIO_PIN_CONFIG(GPIO_PORT1, GPIO_PIN6, GPIO_BIDIRECTIONAL_MODE);
#define MAX6675_MAX_SPEED 4300000UL

uint16_t readTemperature() {
	uint16_t result = 0;
	volatile bool dataReady = 0;
	union {
		uint16_t word;
		uint8_t byte[2];
	} data;
	
	gpioWrite(&csPin, 0);
	
	spiReceive(data.byte, 2, &dataReady);
	
	while (!dataReady);
	
	gpioWrite(&csPin, 1);
	
	// MSB is sent first, so we need to swap bytes,
	// MCS-51 being little-endian MCU.
	uint8_t n = data.byte[0];
	data.byte[0] = data.byte[1];
	data.byte[1] = n;
	
	// If bit 2 is 0, thermocouple is connected.
	if (!(data.byte[0] & 4)) {
		// result is 12-bit wide with a resolution of 0.25°C,
		// i.e. result ranges between 0 and 1023.75 °C, or stated
		// otherwise, result >> 2 is the temperature in °C.
		result = (data.word >> 3) & 0x0fff;
	}
	
	return result;
}

void main() {
	INIT_EXTENDED_SFR()
	
	serialConsoleInitialise(
		CONSOLE_UART, 
		CONSOLE_SPEED, 
		CONSOLE_PIN_CONFIG
	);
	
	gpioConfigure(&csPin);
	gpioWrite(&csPin, 1);
	
	spiConfigure(
		SPI_MASTER, 
		SPI_MSB_FIRST, 
		SPI_CLK_IDLE_LOW, 
		SPI_SAMPLE_ON_TRAILING_EDGE, 
		spiSelectSpeed(MAX6675_MAX_SPEED), 
		SPI_PIN_CONFIG, 
		GPIO_BIDIRECTIONAL_MODE
	);
	
	// Enable interrupts -----------------------------------------------
	EA = 1;
	
	// Main loop -------------------------------------------------------
	
	while (1) {
		delay1ms(10000);
		uint16_t temp = readTemperature() >> 2;
		printf("Temperature = %d\r\n", temp);
	}
}
