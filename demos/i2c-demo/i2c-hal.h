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
#ifndef _I2C_HAL_H
#define _I2C_HAL_H

/**
 * @file i2c-hal.h
 * 
 * I2C abstraction definitions.
 * 
 * Supported MCU families: all STC8.
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 */

#include "gpio-hal.h"

/*
 * I2C pin configurations (STC8 only)
 * 
 *  Value | SCL  | SDA  | Comment
 * -------+------+------+---------------
 *    0   | P3.2 | P3.3 | MCU_PINS == 8
 *    1   | P5.4 | P5.5 | MCU_PINS == 8
 * -------+------+------+---------------
 *    0   | P1.5 | P1.4 | MCU_PINS >= 20
 *    1   | P2.5 | P2.4 | MCU_PINS >= 28
 *    2   | P7.7 | P7.6 | MCU_PINS == 64
 *    3   | P3.2 | P3.3 | 
 */

typedef enum {
	I2C_ACK = 0,
	I2C_NAK = 1,
} I2C_AckNak;

typedef enum {
	I2C_WRITE = 0,
	I2C_READ = 1,
} I2C_Command;

/**
 * The most common case is to use I2C to communicate with peripherals,
 * so we assume MASTER mode by default.
 * 
 * If we want to implement a peripheral instead, we just need to
 * #define I2C_IS_SLAVE to use SLAVE mode.
 */
#ifdef I2C_IS_SLAVE
	// == SLAVE mode ===================================================
	
	#define I2C_MATCH_ANY_ID 1
	
	/**
	 * slaveIdX2 must be either I2C_MATCH_ANY_ID, or a 7-bit ID
	 * shifted left one bit.
	 */
	void i2cInitialiseSlave(uint8_t pinSwitch, uint8_t slaveIdX2);

	void i2cSendData(uint8_t byte);
	
	/**
	 * Must be called BEFORE receiving the expected byte, because our
	 * state machine knows beforehand whether the next byte will be 
	 * welcome or not.
	 */
	void i2cSendAck(I2C_AckNak value);
	
	/**
	 * The following event handlers MUST be implemented,
	 * even when not used.
	 */
	void i2cOnCommandReceived(uint8_t slaveAddress, I2C_Command command) USE_BANK(1);
	void i2cOnDataReceived(uint8_t byte) USE_BANK(1);
	void i2cOnDataSent(I2C_AckNak ack) USE_BANK(1);
	void i2cOnStop() USE_BANK(1);

	void __i2c_isr() ISR_PARAM(I2C_INTERRUPT, 1);
#else
	// == MASTER mode ==================================================
	
	#define I2C_CLOCK_100kHz 100000UL
	#define I2C_CLOCK_400kHz 400000UL
	
	void i2cInitialiseMaster(uint8_t pinSwitch, uint32_t i2cFreq);
	
	I2C_AckNak i2cStartCommand(uint8_t slaveAddress, I2C_Command command);
	I2C_AckNak i2cSendByte(uint8_t byte);
	uint8_t i2cReadByteSendAck(I2C_AckNak value);
	void i2cStop();
	
	// Low-level functions, just in case.
	void i2cStart();
	void i2cSendAck(I2C_AckNak value);
	void i2cSendData(uint8_t byte);
	I2C_AckNak i2cReceiveAck();
	uint8_t i2cReceiveData();
#endif // I2C_IS_SLAVE

#endif // _I2C_HAL_H
