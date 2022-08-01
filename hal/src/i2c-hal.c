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
#include "i2c-hal.h"

/**
 * @file i2c-hal.c
 * 
 * I2C abstraction implementation.
 */

#define I2C_PIN_SWITCH 0
#define I2C_SCL_PIN 1
#define I2C_SDA_PIN 2
#define I2C_ROW_SIZE 3

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

static uint8_t __pinConfigurations[][I2C_ROW_SIZE] = {
#if MCU_PINS == 8
	{ 0, 0x32, 0x33 },
	{ 1, 0x54, 0x55 },
#else
	#if MCU_PINS >= 20
		{ 0, 0x15, 0x14 },
	#endif // MCU_PINS >= 28
	
	#if MCU_PINS >= 28
		{ 1, 0x25, 0x24 },
	#endif // MCU_PINS >= 28
	
	#if MCU_PINS == 64
		{ 2, 0x77, 0x76 },
	#endif // MCU_PINS >= 28
	{ 3, 0x32, 0x33 },
#endif // MCU_PINS == 8
};

// On all STC8G, STC8H and the STC8A8K64D4, GPIO ports are configured
// in high-impedance mode by default, so configuring the output pins
// mode is *REQUIRED*.
static void __i2c_configurePins(uint8_t pinSwitch) {
	for (uint8_t i = 0; i < (sizeof(__pinConfigurations) / I2C_ROW_SIZE); i++) {
		if (__pinConfigurations[i][I2C_PIN_SWITCH] == pinSwitch) {
			P_SW2 = (P_SW2 & ~M_I2C_S) | ((pinSwitch << P_I2C_S) & M_I2C_S);
			GpioConfig pinConfig = GPIO_PIN_CONFIG(GPIO_PORT3, GPIO_PIN0, GPIO_OPEN_DRAIN);
			uint8_t pinDefinition;
			
			pinDefinition = __pinConfigurations[i][I2C_SDA_PIN];
			pinConfig.port = (GpioPort) (pinDefinition >> 4);
			pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
			gpioConfigure(&pinConfig);
			
			pinDefinition = __pinConfigurations[i][I2C_SCL_PIN];
			pinConfig.port = (GpioPort) (pinDefinition >> 4);
			pinConfig.pin = (GpioPin) (pinDefinition & 0x0f);
#ifdef I2C_IS_SLAVE
			pinConfig.portMode = GPIO_BIDIRECTIONAL
#endif // I2C_IS_SLAVE
			gpioConfigure(&pinConfig);
			break;
		}
	}
}

#ifdef I2C_IS_SLAVE
	// == SLAVE mode ===================================================
	
	static uint8_t __i2c_startReceived = 0;
	
	void i2cInitialiseSlave(uint8_t pinSwitch, uint8_t slaveIdX2) {
		__i2c_configurePins(pinSwitch);
		__i2c_startReceived = 0;
		ENABLE_EXTENDED_SFR();
		// Set slave address (or "promiscuous" mode, i.e. bit 0 = 1)
		I2CSLADR = slaveIdX2;
		// Clear interrupt flags and SLACKO
		I2CSLST = 0;
		// Enable interrupts
		I2CSLCR = M_ESTOI | M_ETXI | M_ERXI | M_ESTAI;
		// Enable I2C in SLAVE mode
		I2CCFG = M_ENI2C;
		DISABLE_EXTENDED_SFR();
	}
	
	void i2cSendData(uint8_t byte) {
		ENABLE_EXTENDED_SFR()
		I2CTXD = byte;
		DISABLE_EXTENDED_SFR();
	}
	
	void i2cSendAck(I2C_AckNak value) {
		ENABLE_EXTENDED_SFR()
		
		if (value) {
			I2CSLST |= M_SLACKO;
		} else {
			I2CSLST &= ~M_SLACKO;
		}
		
		DISABLE_EXTENDED_SFR();
	}

	INTERRUPT_USING(__i2c_isr, I2C_INTERRUPT, 1) {
		uint8_t p_sw2 = P_SW2;
		ENABLE_EXTENDED_SFR();
		uint8_t flags = I2CSLST;
		
		if (flags & M_STOIF) {
			I2CSLST &= ~M_STOIF;
			P_SW2 = p_sw2;
			__i2c_startReceived = 0;
			i2cOnStop();
		} else if (flags & M_TXIF) {
			I2CSLST &= ~M_TXIF;
			I2C_AckNak ack = (I2C_AckNak) ((I2CSLST & M_SLACKI) >> P_SLACKI);
			P_SW2 = p_sw2;
			i2cOnDataSent(ack);
		} else if (flags & M_RXIF) {
			I2CSLST &= ~M_RXIF;
			uint8_t byte = I2CRXD;
			P_SW2 = p_sw2;
			
			if (__i2c_startReceived) {
				__i2c_startReceived = 0;
				i2cOnCommandReceived(byte >> 1, (I2C_Command) (byte & 1));
			} else {
				i2cOnDataReceived(byte);
			}
		} else if (flags & M_STAIF) {
			I2CSLST &= ~M_STAIF;
			P_SW2 = p_sw2;
			__i2c_startReceived = 1;
		}
	}
#else
	// == MASTER mode ==================================================
	enum  I2C_Operations {
		I2C_standby = 0,
		I2C_start = 1,
		I2C_sendData = 2,
		I2C_receiveAck = 3,
		I2C_receiveData = 4,
		// Sends the value of MSACKO (0 = ACK, 1 = NAK)
		I2C_sendAck = 5,
		I2C_stop = 6,
		I2C_start_sendData_receiveAck = 9,
		I2C_sendData_receiveAck = 10,
		// Always sends an ACK, does not use MSACKO
		I2C_receiveData_sendAck0 = 11,
		// Always sends a NAK, does not use MSACKO
		I2C_receiveData_sendAck1 = 12,
	};

	void i2cInitialiseMaster(uint8_t pinSwitch, uint32_t i2cFreq) {
		__i2c_configurePins(pinSwitch);
		
		uint8_t msSpeed = MCU_FREQ / i2cFreq / 4 - 2;
		
		if (msSpeed > 63) {
			msSpeed = 63;
		}
		
		ENABLE_EXTENDED_SFR();
		// Initialise command register
		I2CMSCR = I2C_standby;
		// Clear flags
		I2CMSST = 0;
		// Enable I2C in MASTER mode
		I2CCFG = M_ENI2C | M_MSSL | msSpeed;
		DISABLE_EXTENDED_SFR();
	}
	
	static void __waitForCompletion() {
		while (!(I2CMSST & M_MSIF));
		
		I2CMSST &= ~M_MSIF;
	}

	void i2cStart() {
		ENABLE_EXTENDED_SFR()
		I2CMSCR = I2C_start;
		__waitForCompletion();
		DISABLE_EXTENDED_SFR();
	}
	
	void i2cStop() {
		ENABLE_EXTENDED_SFR()
		I2CMSCR = I2C_stop;
		__waitForCompletion();
		DISABLE_EXTENDED_SFR();
	}
	
	void i2cSendAck(I2C_AckNak value) {
		ENABLE_EXTENDED_SFR()
		
		if (value) {
			I2CMSST |= M_MSACKO;
		} else {
			I2CMSST &= ~M_MSACKO;
		}
		
		I2CMSCR = I2C_sendAck;
		__waitForCompletion();
		DISABLE_EXTENDED_SFR();
	}
	
	void i2cSendData(uint8_t byte) {
		ENABLE_EXTENDED_SFR()
		I2CTXD = byte;
		I2CMSCR = I2C_sendData;
		__waitForCompletion();
		DISABLE_EXTENDED_SFR();
	}
	
	I2C_AckNak i2cReceiveAck() {
		ENABLE_EXTENDED_SFR()
		I2CMSCR = I2C_receiveAck;
		__waitForCompletion();
		I2C_AckNak result = (I2C_AckNak) ((I2CMSST & M_MSACKI) >> P_MSACKI);
		DISABLE_EXTENDED_SFR();
		
		return result;
	}
	
	uint8_t i2cReceiveData() {
		ENABLE_EXTENDED_SFR()
		I2CMSCR = I2C_receiveData;
		__waitForCompletion();
		uint8_t result = I2CRXD;
		DISABLE_EXTENDED_SFR();
		
		return result;
	}
	
	I2C_AckNak i2cStartCommand(uint8_t slaveAddress, I2C_Command command) {
		ENABLE_EXTENDED_SFR()
		I2CTXD = (slaveAddress << 1) | command;
		I2CMSCR = I2C_start_sendData_receiveAck;
		__waitForCompletion();
		I2C_AckNak result = (I2C_AckNak) ((I2CMSST & M_MSACKI) >> P_MSACKI);
		DISABLE_EXTENDED_SFR();
		
		return result;
	}
	
	I2C_AckNak i2cSendByte(uint8_t byte) {
		ENABLE_EXTENDED_SFR()
		I2CTXD = byte;
		I2CMSCR = I2C_sendData_receiveAck;
		__waitForCompletion();
		I2C_AckNak result = (I2C_AckNak) ((I2CMSST & M_MSACKI) >> P_MSACKI);
		DISABLE_EXTENDED_SFR();
		
		return result;
	}
	
	uint8_t i2cReadByteSendAck(I2C_AckNak value) {
		ENABLE_EXTENDED_SFR()
		I2CMSCR = value ? I2C_receiveData_sendAck1 : I2C_receiveData_sendAck0;
		__waitForCompletion();
		uint8_t result = I2CRXD;
		DISABLE_EXTENDED_SFR();
		
		return result;
	}
#endif // I2C_IS_SLAVE
