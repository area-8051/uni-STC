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
#include "spi-hal.h"
#include "gpio-hal.h"
#include <string.h>

/**
 * @file spi-hal.c
 * 
 * SPI abstraction implementation.
 */

#ifndef SPI_SEGMENT
	#define SPI_SEGMENT __idata
#endif

#define SPI_PIN_SWITCH 0
#define SPI_SS_PIN 1
#define SPI_MOSI_PIN 2
#define SPI_MISO_PIN 3
#define SPI_SCLK_PIN 4
#define SPI_ROW_SIZE 5

static const __code uint8_t __pinConfigurations[][SPI_ROW_SIZE] = {
#if MCU_FAMILY == 8
	#if MCU_PINS == 8
		{ 0, 0x55, 0x54, 0x33, 0x32 },
	#elif !(defined(GPIO_NO_P13) || defined(GPIO_NO_P14) || defined(GPIO_NO_P15))
		#if MCU_SERIES == 'H' && defined(GPIO_NO_P12)
			{ 0, 0x54, 0x13, 0x14, 0x15 },
		#elif MCU_PINS >= 20
			{ 0, 0x12, 0x13, 0x14, 0x15 },
		#endif // MCU_SERIES == 'H' && defined(GPIO_NO_P12)
	#endif // MCU_PINS == 8
	
	#if MCU_PINS >= 28
		{ 1, 0x22, 0x23, 0x24, 0x25 },
	#endif // MCU_PINS >= 28
	
	#if (MCU_SERIES == 'G' || MCU_SERIES == 'H') && MCU_PINS >= 44
		{ 2, 0x54, 0x40, 0x41, 0x43 },
	#endif // (MCU_SERIES == 'G' || MCU_SERIES == 'H') && MCU_PINS >= 44
	
	#if MCU_SERIES == 'A' && MCU_PINS == 64
		{ 2, 0x74, 0x75, 0x76, 0x77 },
	#endif // MCU_SERIES == 'A' && MCU_PINS == 64
	
	#if MCU_PINS > 8
		{ 3, 0x35, 0x34, 0x33, 0x32 },
	#endif // MCU_PINS > 8
#endif // MCU_FAMILY == 8

#if MCU_FAMILY == 15
	{ 0, 0x12, 0x13, 0x14, 0x15 },
	
	#if MCU_PINS >= 28
		{ 1, 0x24, 0x23, 0x22, 0x21 },
	#endif // MCU_PINS >= 28
	
	#if MCU_PINS >= 44
		{ 2, 0x54, 0x40, 0x41, 0x43 },
	#endif // MCU_PINS >= 44
#endif // MCU_FAMILY == 15

#if MCU_FAMILY == 12
	{ 0, 0x14, 0x15, 0x16, 0x17 },
	
	#if MCU_PINS >= 44
		{ 1, 0x40, 0x41, 0x42, 0x43 },
	#endif // MCU_PINS >= 44
#endif // MCU_FAMILY == 12
};

// On all STC8G, STC8H and the STC8A8K64D4, GPIO ports are configured
// in high-impedance mode by default, so configuring the output pins
// mode is *REQUIRED*.
static void __spi_configurePins(SpiMode spiMode, uint8_t pinSwitch, GpioPinMode outputPinMode) {
	for (uint8_t i = 0; i < (sizeof(__pinConfigurations) / SPI_ROW_SIZE); i++) {
		if (__pinConfigurations[i][SPI_PIN_SWITCH] == pinSwitch) {
			P_SW1 = (P_SW1 & ~M_SPI_S) | ((pinSwitch << P_SPI_S) & M_SPI_S);
			GpioConfig pinConfig = GPIO_PIN_CONFIG(GPIO_PORT3, GPIO_PIN0, outputPinMode);
			uint8_t pinDefinition;
			
			switch (spiMode) {
			case SPI_MASTER:
				// Configure outputs
				pinDefinition = __pinConfigurations[i][SPI_MOSI_PIN];
				pinConfig.port = (GpioPort) (pinDefinition >> 4);
				pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
				gpioConfigure(&pinConfig);
				
				pinDefinition = __pinConfigurations[i][SPI_SCLK_PIN];
				pinConfig.port = (GpioPort) (pinDefinition >> 4);
				pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
				gpioConfigure(&pinConfig);
				
				// Configure input
				pinConfig.pinMode = GPIO_BIDIRECTIONAL_MODE;
				
				pinDefinition = __pinConfigurations[i][SPI_MISO_PIN];
				pinConfig.port = (GpioPort) (pinDefinition >> 4);
				pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
				gpioConfigure(&pinConfig);
				break;
			
			case SPI_SLAVE:
				// Configure output
				pinDefinition = __pinConfigurations[i][SPI_MISO_PIN];
				pinConfig.port = (GpioPort) (pinDefinition >> 4);
				pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
				gpioConfigure(&pinConfig);
				
				// Configure inputs
				pinConfig.pinMode = GPIO_BIDIRECTIONAL_MODE;
				
				pinDefinition = __pinConfigurations[i][SPI_MOSI_PIN];
				pinConfig.port = (GpioPort) (pinDefinition >> 4);
				pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
				gpioConfigure(&pinConfig);
				
				pinDefinition = __pinConfigurations[i][SPI_SCLK_PIN];
				pinConfig.port = (GpioPort) (pinDefinition >> 4);
				pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
				gpioConfigure(&pinConfig);
				break;
			}
			break;
		}
	}
}

static SPI_SEGMENT struct {
	uint8_t mode;
	uint8_t *buffer;
	size_t index;
	size_t bufferSize;
	bool *readyFlag;
} __spiState;

SpiSpeed spiSelectSpeed(uint32_t maxDeviceRate) {
	SpiSpeed result = SPI_SYSCLK_DIV_4;
	uint8_t divisor = (uint8_t) (MCU_FREQ / maxDeviceRate);
	uint8_t pot = 0;
	uint8_t n = divisor;
	
	// Determine the power of two ("pot") equal or immediately greater
	// to the value of the divisor.
	for (uint8_t i = 7; n && i; n = n >> 1, pot++, i--);
	
	n = 1;
	
	for (uint8_t i = pot - 2; i; n = (n << 1) | 1, i--);
	
	if (divisor & n) {
		pot++;
	}
	
	// Determine SPI clock equal or immediately greater to "pot".
	
#if MCU_FAMILY == 12 || MCU_FAMILY == 15
	if (pot > 2 && pot <= 4) {
		result = SPI_SYSCLK_DIV_16;
	} else if (pot > 4 && pot <= 6) {
		result = SPI_SYSCLK_DIV_64;
	} else if (pot > 6) {
		result = SPI_SYSCLK_DIV_128;
	}
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
	
#if MCU_FAMILY == 8
	if (pot > 2 && pot <= 3) {
		result = SPI_SYSCLK_DIV_8;
	
	#ifdef SPI_HAS_HIGH_SPEED
		// STC8H3 (B version), STC8H8 (B version), STC8H4
		} else if (pot < 2) {
			result = SPI_SYSCLK_DIV_2;
		} else if (pot > 3) {
			result = SPI_SYSCLK_DIV_16;
	#else
		// All other STC8
		} else if (pot == 4) {
			result = SPI_SYSCLK_DIV_16;
		} else if (pot > 4) {
			result = SPI_SYSCLK_DIV_32;
	#endif // SPI_HAS_HIGH_SPEED
	}
#endif // MCU_FAMILY == 8
	
	return result;
}

void spiConfigure(SpiMode spiMode, SpiBitOrder bitOrder, SpiPolarity polarity, SpiSpeed speed, uint8_t pinSwitch, GpioPinMode outputPinMode) {
	__spi_configurePins(spiMode, pinSwitch, outputPinMode);
	__spiState.mode = spiMode;
	SPCTL = spiMode | bitOrder | polarity | speed;
	IE2 = (spiMode == SPI_DISABLE)
		? (IE2 & ~M_ESPI)
		: (IE2 | M_ESPI);
}

void spiSend(uint8_t *buffer, size_t bufferSize, bool *readyFlag) {
	__spiState.buffer = buffer;
	__spiState.bufferSize = bufferSize;
	__spiState.readyFlag = readyFlag;
	*__spiState.readyFlag = false;
	__spiState.index = 0;
	
	if (__spiState.mode == SPI_MASTER) {
		SPDAT = __spiState.buffer[__spiState.index];
	}
}

void spiReceive(uint8_t *buffer, size_t bufferSize, bool *readyFlag) {
	memset(buffer, 0, bufferSize);
	spiSend(buffer, bufferSize, readyFlag);
}

INTERRUPT_USING(__spi_isr, SPI_INTERRUPT, 1) {
	SPSTAT |= M_SPIF | M_WCOL;
	uint8_t data;
	
	switch (__spiState.mode) {
	case SPI_MASTER:
		// Replace master's data with slave's in buffer
		__spiState.buffer[__spiState.index] = SPDAT;
		__spiState.index++;
		
		if (__spiState.index < __spiState.bufferSize) {
			// Send next byte to slave
			SPDAT = __spiState.buffer[__spiState.index];
		} else {
			// We're done
			*__spiState.readyFlag = true;
		}
		break;
	
	case SPI_SLAVE:
		// Take data from master
		data = SPDAT;
		// Reply with slave's
		SPDAT = __spiState.buffer[__spiState.index];
		// Replace slave's data with master's in buffer
		__spiState.buffer[__spiState.index] = data;
		__spiState.index++;
		
		if (__spiState.index == __spiState.bufferSize) {
			*__spiState.readyFlag = true;
		}
		break;
	}
}
