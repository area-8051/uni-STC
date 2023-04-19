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
#ifndef _SPI_HAL_H
#define _SPI_HAL_H

/**
 * @file spi-hal.h
 * 
 * SPI abstraction definitions.
 * 
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8*
 * 
 * Dependencies:
 * 
 *     gpio-hal
 * 
 * Optional macros:
 * 
 *     SPI_SEGMENT (default: __idata) defines where the HAL's state
 *     information will be stored. Impacts ISR execution time.
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 */

#ifndef SPI_SEGMENT
	#define SPI_SEGMENT __idata
#endif

/*
 * SPI pin configurations for STC8H
 * 
 *  Value |  SS  | MOSI | MISO | SCLK | Comments
 * -------+------+------+------+------+------------------------
 *    0   | P5.4 | P1.3 | P1.4 | P1.5 | defined(GPIO_NO_P12)
 * -------+------+------+------+------+------------------------
 *    0   | P1.2 | P1.3 | P1.4 | P1.5 | !defined(GPIO_NO_P13..15) && !defined(GPIO_NO_P12)
 *    1   | P2.2 | P2.3 | P2.4 | P2.5 | MCU_PINS >= 28
 *    2   | P5.4 | P4.0 | P4.1 | P4.3 | MCU_PINS >= 44
 *    3   | P3.5 | P3.4 | P3.3 | P3.2 |
 * 
 * Note 1: STC8H8, STC8H4 and STC8H1K08TR do NOT have pin P1.2.
 * Note 2: STC8H3 do NOT have P1.3, P1.4 and P1.5.
 * 
 * SPI pin configurations for STC8G
 * 
 *  Value |  SS  | MOSI | MISO | SCLK | Comments
 * -------+------+------+------+------+----------------
 *    0   | P5.5 | P5.4 | P3.3 | P3.2 | MCU_PINS == 8
 * -------+------+------+------+------+----------------
 *    0   | P1.2 | P1.3 | P1.4 | P1.5 | MCU_PINS >= 20
 *    1   | P2.2 | P2.3 | P2.4 | P2.5 | MCU_PINS >= 28
 *    2   | P5.4 | P4.0 | P4.1 | P4.3 | MCU_PINS >= 44
 *    3   | P3.5 | P3.4 | P3.3 | P3.2 | MCU_PINS > 8
 * 
 * SPI pin configurations for STC8A
 * 
 *  Value |  SS  | MOSI | MISO | SCLK | Comments
 * -------+------+------+------+------+----------------
 *    0   | P1.2 | P1.3 | P1.4 | P1.5 |
 *    1   | P2.2 | P2.3 | P2.4 | P2.5 | MCU_PINS >= 28
 *    2   | P7.4 | P7.5 | P7.6 | P7.7 | MCU_PINS == 64
 *    3   | P3.5 | P3.4 | P3.3 | P3.2 |
 * 
 * SPI pin configurations for STC15
 * 
 *  Value |  SS  | MOSI | MISO | SCLK | Comments
 * -------+------+------+------+------+----------------
 *    0   | P1.2 | P1.3 | P1.4 | P1.5 |
 *    1   | P2.4 | P2.3 | P2.2 | P2.1 | MCU_PINS >= 28
 *    2   | P5.4 | P4.0 | P4.1 | P4.3 | MCU_PINS >= 44
 * 
 * SPI pin configurations for STC12
 * 
 *  Value |  SS  | MOSI | MISO | SCLK | Comments
 * -------+------+------+------+------+----------------
 *    0   | P1.4 | P1.5 | P1.6 | P1.7 |
 *    1   | P4.0 | P4.1 | P4.2 | P4.3 | MCU_PINS >= 44
 * 
 */

typedef enum {
	SPI_DISABLE = 0,
	SPI_MASTER = 0xd4,
	// Slave is enabled when SS pin is low.
	SPI_SLAVE = 0x40,
} SpiMode;

typedef enum {
	SPI_MSB_FIRST = 0,
	SPI_LSB_FIRST = 0x20,
} SpiBitOrder;

typedef enum {
	SPI_CLK_IDLE_LOW = 0,
	SPI_CLK_IDLE_HIGH = 8,
} SpiPolarity;

// Used only when SpiMode == SPI_SLAVE, ignored otherwise.
typedef enum {
	// Data changes on trailing edge, and is sampled on leading edge of SCLK.
	SPI_SAMPLE_ON_LEADING_EDGE = 0,
	// Data changes on leading edge, and is sampled on trailing edge of SCLK.
	SPI_SAMPLE_ON_TRAILING_EDGE = 4,
} SpiPhase;

typedef enum {
	SPI_SYSCLK_DIV_4 = 0,
	
	#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		SPI_SYSCLK_DIV_16 = 1,
		SPI_SYSCLK_DIV_64 = 2,
		SPI_SYSCLK_DIV_128 = 3,
	#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
	
	#if MCU_FAMILY == 8
		SPI_SYSCLK_DIV_8 = 1,
		SPI_SYSCLK_DIV_16 = 2,
		
		#ifdef SPI_HAS_HIGH_SPEED
			// STC8H3 (B version), STC8H8 (B version), STC8H4
			SPI_SYSCLK_DIV_2 = 3,
		#else
			// All other STC8
			SPI_SYSCLK_DIV_32 = 3,
		#endif // SPI_HAS_HIGH_SPEED
	#endif // MCU_FAMILY == 8
} SpiSpeed;

SpiSpeed spiSelectSpeed(uint32_t maxDeviceRate);
void spiConfigure(SpiMode spiMode, SpiBitOrder bitOrder, SpiPolarity polarity, SpiPhase phase, SpiSpeed speed, uint8_t pinSwitch, GpioPinMode outputPinMode);
void spiSend(uint8_t *buffer, size_t bufferSize, bool *readyFlag);
void spiReceive(uint8_t *buffer, size_t bufferSize, bool *readyFlag);

INTERRUPT_USING(__spi_isr, SPI_INTERRUPT, 1);

#endif // _SPI_HAL_H
