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
#include <uart-hal.h>

#ifndef UART_DEFAULT_BUFFER_SIZE
	#define UART_DEFAULT_BUFFER_SIZE 16
#endif

#ifndef UART_DEFAULT_SEGMENT
	#if HAL_UARTS > 1
		// __data and __idata are too small to be used as default values:
		// default values should "just work", even when using all UART
		// simultaneously.
		// __xdata uses more flash but takes 1 cycle less than __pdata,
		// that seems a good trade off.
		#define UART_DEFAULT_SEGMENT __xdata
	#else
		// With just one UART, __idata is a sound default, especially
		// when using small buffers and/or a small stack.
		#define UART_DEFAULT_SEGMENT __idata
	#endif // HAL_UARTS > 1
#endif

/**
 * @file uart-hal.c
 * 
 * UART abstraction layer implementation for STC12, STC15 and STC8.
 * 
 * TODO: 9-bit modes (parity & multi-machine) support.
 */

#define STATUS_CLEAR   0
#define STATUS_SENDING 1

#ifndef UART1_TX_BUFFER_SIZE
	#define UART1_TX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
#endif

#ifndef UART1_RX_BUFFER_SIZE
	#define UART1_RX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
#endif

#ifndef UART1_SEGMENT
	#define UART1_SEGMENT UART_DEFAULT_SEGMENT
#endif

FIFO_BUFFER(UART1_receiveBuffer, UART1_RX_BUFFER_SIZE, UART1_SEGMENT)
FIFO_BUFFER(UART1_transmitBuffer, UART1_TX_BUFFER_SIZE, UART1_SEGMENT)

#if HAL_UARTS >= 2
	#ifndef UART2_TX_BUFFER_SIZE
		#define UART2_TX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
	#endif

	#ifndef UART2_RX_BUFFER_SIZE
		#define UART2_RX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
	#endif

	#ifndef UART2_SEGMENT
		#define UART2_SEGMENT UART_DEFAULT_SEGMENT
	#endif

	FIFO_BUFFER(UART2_receiveBuffer, UART2_RX_BUFFER_SIZE, UART2_SEGMENT)
	FIFO_BUFFER(UART2_transmitBuffer, UART2_TX_BUFFER_SIZE, UART2_SEGMENT)
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	#ifndef UART3_TX_BUFFER_SIZE
		#define UART3_TX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
	#endif

	#ifndef UART3_RX_BUFFER_SIZE
		#define UART3_RX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
	#endif

	#ifndef UART3_SEGMENT
		#define UART3_SEGMENT UART_DEFAULT_SEGMENT
	#endif

	FIFO_BUFFER(UART3_receiveBuffer, UART3_RX_BUFFER_SIZE, UART3_SEGMENT)
	FIFO_BUFFER(UART3_transmitBuffer, UART3_TX_BUFFER_SIZE, UART3_SEGMENT)

	#ifndef UART4_TX_BUFFER_SIZE
		#define UART4_TX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
	#endif

	#ifndef UART4_RX_BUFFER_SIZE
		#define UART4_RX_BUFFER_SIZE UART_DEFAULT_BUFFER_SIZE
	#endif

	#ifndef UART4_SEGMENT
		#define UART4_SEGMENT UART_DEFAULT_SEGMENT
	#endif

	FIFO_BUFFER(UART4_receiveBuffer, UART4_RX_BUFFER_SIZE, UART4_SEGMENT)
	FIFO_BUFFER(UART4_transmitBuffer, UART4_TX_BUFFER_SIZE, UART4_SEGMENT)
#endif // HAL_UARTS >= 3

static FifoState *uartReceiveBuffer(Uart uart) {
	FifoState *result = NULL;
	
	switch (uart) {
	case UART1:
		result = &UART1_receiveBuffer;
		break;
	
#if HAL_UARTS >= 2
	case UART2:
		result = &UART2_receiveBuffer;
		break;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	case UART3:
		result = &UART3_receiveBuffer;
		break;
	
	case UART4:
		result = &UART4_receiveBuffer;
		break;
#endif // HAL_UARTS >= 3
	}
	
	return result;
}

static FifoState *uartTransmitBuffer(Uart uart) {
	FifoState *result = NULL;
	
	switch (uart) {
	case UART1:
		result = &UART1_transmitBuffer;
		break;
	
#if HAL_UARTS >= 2
	case UART2:
		result = &UART2_transmitBuffer;
		break;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	case UART3:
		result = &UART3_transmitBuffer;
		break;
	
	case UART4:
		result = &UART4_transmitBuffer;
		break;
#endif // HAL_UARTS >= 3
	}
	
	return result;
}

bool uartIsTransmissionComplete(Uart uart) {
	FifoState *buffer = uartTransmitBuffer(uart);
	
	return buffer->status == STATUS_CLEAR;
}

bool uartTransmitBufferHasBytesFree(Uart uart, uint8_t bytes) {
	return fifoBytesFree(uartTransmitBuffer(uart)) >= bytes;
}

#ifndef M_S1_S
// Suppress warning "unreferenced function argument"
// when using STC12 with HAL_UARTS set to 1.
#pragma disable_warning 85
#endif // M_S1_S
TimerStatus uartInitialise(Uart uart, uint32_t baudRate, UartBaudRateTimer baudRateTimer, UartMode mode, uint8_t pinSwitch) {
	TimerStatus rc = TIMER_FREQUENCY_OK;
	
	// UART1 is somewhat peculiar: when mode != UART_8N1, baudRate is
	// expected to be of type Uart1_9BitMode_Clock and is derived from
	// sysclk instead of a timer.
	if (uart != UART1 || mode == UART_8N1) {
		Timer timer;
		
#ifdef TIMER_HAS_T1
		timer = (baudRateTimer == UART_USE_TIMER2)
			? TIMER2
			: ((Timer) uart);
			// There's a reason why UART numbers start at 1
			// while timer numbers start at 0!  :)
#else
		// If the target MCU doesn't have timer 1, the only possible
		// baud rate generator is timer 2.
		timer = TIMER2;
#endif // TIMER_HAS_T1
		
		// Note: on the STC12, TIMER2 is the BRT timer.
		// The timer HAL makes this transparent for the developer.
		rc = startTimer(
			timer, 
			baudRateToSysclkDivisor(baudRate), 
			DISABLE_OUTPUT, 
			DISABLE_INTERRUPT, 
			FREE_RUNNING
		);
	}
	
	if (rc == TIMER_FREQUENCY_OK) {
		uint8_t operationMode = 0;
		
		switch (mode) {
		case UART_8N1:
			if (uart == UART1) {
				operationMode = 1;
			}
			break;
		
		case UART_8E1:
		case UART_8O1:
		case UART_MULTI_MACHINE:
			if (uart == UART1) {
				operationMode = 2 | ((baudRate & 2) >> 1);
			} else {
				operationMode = 1;
			}
			break;
		}
		
		uint8_t scon = ((mode == UART_MULTI_MACHINE) ? M_SM2 : 0)
			| ((operationMode & 2) ? M_SM0 : 0) | M_REN;
		
		switch (uart) {
		case UART1:
			// Configure UART clock source
			switch (operationMode) {
			case 1:
				if (baudRateTimer == UART_USE_TIMER2) {
					AUXR |= M_S1ST2;
				} else {
					AUXR &= ~M_S1ST2;
				}
				break;
			
			case 2:
				// Remember baudRate is of type Uart1_9BitMode_Clock.
				if (baudRate & 1) {
					PCON |= M_SMOD;
				} else {
					PCON &= ~M_SMOD;
				}
				break;
			
			case 3:
				// Remember baudRate is of type Uart1_9BitMode_Clock.
				if (baudRate & 1) {
					AUXR |= M_UART_M0x6;
				} else {
					AUXR &= ~M_UART_M0x6;
				}
				break;
			}
			
#ifdef M_S1_S
			// Set pin configuration
			P_SW1 = (P_SW1 & ~M_S1_S) | ((pinSwitch << P_S1_S) & M_S1_S);
#endif // M_S1_S
			
			// Set UART mode and clear interrupt flag
			S1CON = scon | ((operationMode & 1) ? M_SM1 : 0);
			
			// Enable serial port interrupt
			IE1 |= M_ES1;
			break;
		
#if HAL_UARTS >= 2
		case UART2:
			// For UART2, OWM_TIMER == TIMER2, so no need to 
			// configure UART clock source.
			
	#if MCU_FAMILY == 8 || MCU_FAMILY == 15
			// Set pin configuration
			P_SW2 = (P_SW2 & ~M_S2_S) | ((pinSwitch << P_S2_S) & M_S2_S);
			
			// Set UART mode and clear interrupt flag
			S2CON = scon;
	#endif // MCU_FAMILY == 8 || MCU_FAMILY == 15

	#if MCU_FAMILY == 12
			// Set pin configuration
			P_SW1 = (P_SW1 & ~M_S2_S) | ((pinSwitch << P_S2_S) & M_S2_S);
			
			S2CON = scon | M_SM1; // Yes, that's not a mistake, see TRM.
	#endif // MCU_FAMILY == 12
			
			// Enable serial port interrupt
			IE2 |= M_ES2;
			break;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
		case UART3:
			// Configure UART clock source
			if (baudRateTimer == UART_USE_OWN_TIMER) {
				S3CON |= M_S3ST3;
			} else {
				S3CON &= ~M_S3ST3;
			}
			
			// Set pin configuration
			P_SW2 = (P_SW2 & ~M_S3_S) | ((pinSwitch << P_S3_S) & M_S3_S);
			
			// Set UART mode and clear interrupt flag
			S3CON = scon;
			
			// Enable serial port interrupt
			IE2 |= M_ES3;
			break;

		case UART4:
			// Configure UART clock source
			if (baudRateTimer == UART_USE_OWN_TIMER) {
				S4CON |= M_S4ST4;
			} else {
				S4CON &= ~M_S4ST4;
			}
			
			// Set pin configuration
			P_SW2 = (P_SW2 & ~M_S4_S) | ((pinSwitch << P_S4_S) & M_S4_S);
			
			// Set UART mode and clear interrupt flag
			S4CON = scon;
			
			// Enable serial port interrupt
			IE2 |= M_ES4;
			break;
#endif // HAL_UARTS >= 3
		}
		
		uartTransmitBuffer(uart)->status = STATUS_CLEAR;
	}
	
	return rc;
}

INTERRUPT_USING(__uart1_isr, UART1_INTERRUPT, 1) {
	uint8_t c;
	
	if (S1CON & M_TI) {
		S1CON &= ~M_TI;
		
		if (fifoRead(&UART1_transmitBuffer, &c, 1)) {
			S1BUF = c;
		} else {
			UART1_transmitBuffer.status = STATUS_CLEAR;
		}
	}

	if (S1CON & M_RI) {
		S1CON &= ~M_RI;
		c = S1BUF;
		fifoWrite(&UART1_receiveBuffer, &c, 1);
	}
}

#if HAL_UARTS >= 2
	INTERRUPT_USING(__uart2_isr, UART2_INTERRUPT, 1) {
		uint8_t c;
		
		if (S2CON & M_TI) {
			S2CON &= ~M_TI;
			
			if (fifoRead(&UART2_transmitBuffer, &c, 1)) {
				S2BUF = c;
			} else {
				UART2_transmitBuffer.status = STATUS_CLEAR;
			}
		}

		if (S2CON & M_RI) {
			S2CON &= ~M_RI;
			c = S2BUF;
			fifoWrite(&UART2_receiveBuffer, &c, 1);
		}
	}
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	INTERRUPT_USING(__uart3_isr, UART3_INTERRUPT, 1) {
		uint8_t c;
		
		if (S3CON & M_TI) {
			S3CON &= ~M_TI;
			
			if (fifoRead(&UART3_transmitBuffer, &c, 1)) {
				S3BUF = c;
			} else {
				UART3_transmitBuffer.status = STATUS_CLEAR;
			}
		}

		if (S3CON & M_RI) {
			S3CON &= ~M_RI;
			c = S3BUF;
			fifoWrite(&UART3_receiveBuffer, &c, 1);
		}
	}

	INTERRUPT_USING(__uart4_isr, UART4_INTERRUPT, 1) {
		uint8_t c;
		
		if (S4CON & M_TI) {
			S4CON &= ~M_TI;
			
			if (fifoRead(&UART4_transmitBuffer, &c, 1)) {
				S4BUF = c;
			} else {
				UART4_transmitBuffer.status = STATUS_CLEAR;
			}
		}

		if (S4CON & M_RI) {
			S4CON &= ~M_RI;
			c = S4BUF;
			fifoWrite(&UART4_receiveBuffer, &c, 1);
		}
	}
#endif // HAL_UARTS >= 3

uint8_t uartGetCharacter(Uart uart, BlockingOperation blocking) {
	uint8_t result = 0;
	FifoState *buffer = uartReceiveBuffer(uart);
	
	if (blocking == BLOCKING) {
		while (!fifoRead(buffer, &result, 1));
	} else {
		fifoRead(buffer, &result, 1);
	}
	
	return result;
}

bool uartGetBlock(Uart uart, uint8_t *data, uint8_t size, BlockingOperation blocking) {
	bool rc = true;
	FifoState *buffer = uartReceiveBuffer(uart);
	
	if (blocking == BLOCKING) {
		while (!fifoRead(buffer, data, size));
	} else {
		fifoRead(buffer, data, size);
	}
	
	return rc;
}

static void __uartStartSending(Uart uart, FifoState *buffer) {
	buffer->status = STATUS_SENDING;
	uint8_t data;
	fifoRead(buffer, &data, 1);
	
	switch (uart) {
	case UART1:
		S1BUF = data;
		break;
	
#if HAL_UARTS >= 2
	case UART2:
		S2BUF = data;
		break;
#endif // HAL_UARTS >= 2
	
#if HAL_UARTS >= 3
	case UART3:
		S3BUF = data;
		break;
	
	case UART4:
		S4BUF = data;
		break;
#endif // HAL_UARTS >= 3
	}
}

bool uartSendCharacter(Uart uart, uint8_t c, BlockingOperation blocking) {
	FifoState *buffer = uartTransmitBuffer(uart);
	bool rc = true;
	
	if (blocking == BLOCKING) {
		while (!fifoWrite(buffer, &c, 1));
	} else {
		rc = fifoWrite(buffer, &c, 1);
	}
	
	if (rc && buffer->status == STATUS_CLEAR) {
		__uartStartSending(uart, buffer);
	}
	
	return rc;
}

bool uartSendBlock(Uart uart, const uint8_t *data, uint8_t size, BlockingOperation blocking) {
	FifoState *buffer = uartTransmitBuffer(uart);
	bool rc = true;
	
	if (blocking == BLOCKING) {
		while (!fifoWrite(buffer, data, size));
	} else {
		rc = fifoWrite(buffer, data, size);
	}
	
	if (rc && buffer->status == STATUS_CLEAR) {
		__uartStartSending(uart, buffer);
	}
	
	return rc;
}
