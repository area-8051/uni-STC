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
#include "uart-hal.h"

#ifndef UART_BUFFER_SIZE
	#define UART_BUFFER_SIZE 32
#endif

#define FIFO_BUFFER_SIZE UART_BUFFER_SIZE
#include "fifo-buffer.h"
#include <stdlib.h>

/**
 * @file uart-hal.c
 * 
 * UART abstraction layer implementation for STC12, STC15 and STC8.
 * 
 * TODO: 9-bit modes (parity & multi-machine) support.
 */

#define STATUS_CLEAR   0
#define STATUS_SENDING 1

FifoBuffer UART1_inputBuffer;
FifoBuffer UART1_outputBuffer;
UartMode UART1_mode;

#if HAL_UARTS >= 2
	FifoBuffer UART2_inputBuffer;
	FifoBuffer UART2_outputBuffer;
	UartMode UART2_mode;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	FifoBuffer UART3_inputBuffer;
	FifoBuffer UART3_outputBuffer;
	UartMode UART3_mode;

	FifoBuffer UART4_inputBuffer;
	FifoBuffer UART4_outputBuffer;
	UartMode UART4_mode;
#endif // HAL_UARTS >= 3

static FifoBuffer *inputBuffer(Uart uart) {
	FifoBuffer *result = NULL;
	
	switch (uart) {
	case UART1:
		result = &UART1_inputBuffer;
		break;
	
#if HAL_UARTS >= 2
	case UART2:
		result = &UART2_inputBuffer;
		break;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	case UART3:
		result = &UART3_inputBuffer;
		break;
	
	case UART4:
		result = &UART4_inputBuffer;
		break;
#endif // HAL_UARTS >= 3
	}
	
	return result;
}

static FifoBuffer *outputBuffer(Uart uart) {
	FifoBuffer *result = NULL;
	
	switch (uart) {
	case UART1:
		result = &UART1_outputBuffer;
		break;
	
#if HAL_UARTS >= 2
	case UART2:
		result = &UART2_outputBuffer;
		break;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	case UART3:
		result = &UART3_outputBuffer;
		break;
	
	case UART4:
		result = &UART4_outputBuffer;
		break;
#endif // HAL_UARTS >= 3
	}
	
	return result;
}

static UartMode uartMode(Uart uart) {
	UartMode result = UART_8N1;
	
	switch (uart) {
	case UART1:
		result = UART1_mode;
		break;
	
#if HAL_UARTS >= 2
	case UART2:
		result = UART2_mode;
		break;
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	case UART3:
		result = UART3_mode;
		break;
	
	case UART4:
		result = UART4_mode;
		break;
#endif // HAL_UARTS >= 3
	}
	
	return result;
}

uint8_t uartReceiveBufferEmpty(Uart uart) {
	return fifoLength(inputBuffer(uart)) == 0;
}

uint8_t uartReceiveBufferFull(Uart uart) {
	return fifoLength(inputBuffer(uart)) == FIFO_BUFFER_SIZE;
}

uint8_t uartReceiveBufferBytesUsed(Uart uart) {
	return fifoLength(inputBuffer(uart));
}

uint8_t uartReceiveBufferBytesFree(Uart uart) {
	FifoBuffer *buffer = inputBuffer(uart);
	return buffer->size - fifoLength(buffer);
}

uint8_t uartTransmitBufferEmpty(Uart uart) {
	return fifoLength(outputBuffer(uart)) == 0;
}

uint8_t uartTransmitBufferFull(Uart uart) {
	return fifoLength(outputBuffer(uart)) == FIFO_BUFFER_SIZE;
}

uint8_t uartTransmitBufferBytesUsed(Uart uart) {
	return fifoLength(outputBuffer(uart));
}

uint8_t uartTransmitBufferBytesFree(Uart uart) {
	FifoBuffer *buffer = outputBuffer(uart);
	return buffer->size - fifoLength(buffer);
}

#ifndef M_S1_S
// Suppress warning "unreferenced function argument"
// when using STC12 with HAL_UARTS set to 1.
#pragma disable_warning 85
#endif // M_S1_S
Timer_Status uartInitialise(Uart uart, uint32_t baudRate, UartBaudRateTimer baudRateTimer, UartMode mode, uint8_t pinSwitch) {
	Timer_Status rc = TIMER_FREQUENCY_OK;
	
	// UART1 is somewhat peculiar: when mode != UART_8N1, baudRate is
	// expected to be of type Uart1_9BitMode_Clock and is derived from
	// sysclk instead of a timer.
	if (uart != UART1 || mode == UART_8N1) {
		Timer timer = (baudRateTimer == UART_USE_TIMER2)
			? TIMER2
			: ((Timer) uart);
			// There's a reason why UART numbers start at 1
			// while timer numbers start at 0!  :)
		rc = startTimer(
			timer, 
			baudRateToSysclkDivisor(baudRate), 
			TIMER_OUTPUT_DISABLE, 
			TIMER_INTERRUPT_DISABLE, 
			TIMER_FREE_RUNNING
		);
	}
	
	if (rc == TIMER_FREQUENCY_OK) {
		fifoInitialise(inputBuffer(uart));
		fifoInitialise(outputBuffer(uart));
		
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
			
			// Save mode for ISR
			UART1_mode = mode;
			
			// Set UART mode and clear interrupt flag
			S1CON = scon | ((operationMode & 1) ? M_SM1 : 0);
			
			// Enable serial port interrupt
			IE1 |= M_ES1;
			break;
		
#if HAL_UARTS >= 2
		case UART2:
			// For UART2, OWM_TIMER == TIMER2, so no need to 
			// configure UART clock source.
			
			// Save mode for ISR
			UART2_mode = mode;

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
			
			// Save mode for ISR
			UART3_mode = mode;
			
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
			
			// Save mode for ISR
			UART4_mode = mode;
			
			// Set pin configuration
			P_SW2 = (P_SW2 & ~M_S4_S) | ((pinSwitch << P_S4_S) & M_S4_S);
			
			// Set UART mode and clear interrupt flag
			S4CON = scon;
			
			// Enable serial port interrupt
			IE2 |= M_ES4;
			break;
#endif // HAL_UARTS >= 3
		}
	}
	
	return rc;
}

INTERRUPT_USING(__uart1_isr, UART1_INTERRUPT, 1) CRITICAL {
	if (S1CON & M_TI) {
		S1CON &= ~M_TI;
		
		if (fifoLength(&UART1_outputBuffer) > 0) {
			S1BUF = fifoRead(&UART1_outputBuffer);
		} else {
			UART1_outputBuffer.status = STATUS_CLEAR;
		}
	}

	if (S1CON & M_RI) {
		S1CON &= ~M_RI;
		fifoWrite(&UART1_inputBuffer, S1BUF);
	}
}

#if HAL_UARTS >= 2
	INTERRUPT_USING(__uart2_isr, UART2_INTERRUPT, 1) CRITICAL {
		if (S2CON & M_TI) {
			S2CON &= ~M_TI;
			
			if (fifoLength(&UART2_outputBuffer) > 0) {
				S2BUF = fifoRead(&UART2_outputBuffer);
			} else {
				UART2_outputBuffer.status = STATUS_CLEAR;
			}
		}

		if (S2CON & M_RI) {
			S2CON &= ~M_RI;
			fifoWrite(&UART2_inputBuffer, S2BUF);
		}
	}
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	INTERRUPT_USING(__uart3_isr, UART3_INTERRUPT, 1) CRITICAL {
		if (S3CON & M_TI) {
			S3CON &= ~M_TI;
			
			if (fifoLength(&UART3_outputBuffer) > 0) {
				S3BUF = fifoRead(&UART3_outputBuffer);
			} else {
				UART3_outputBuffer.status = STATUS_CLEAR;
			}
		}

		if (S3CON & M_RI) {
			S3CON &= ~M_RI;
			fifoWrite(&UART3_inputBuffer, S3BUF);
		}
	}

	INTERRUPT_USING(__uart4_isr, UART4_INTERRUPT, 1) CRITICAL {
		if (S4CON & M_TI) {
			S4CON &= ~M_TI;
			
			if (fifoLength(&UART4_outputBuffer) > 0) {
				S4BUF = fifoRead(&UART4_outputBuffer);
			} else {
				UART4_outputBuffer.status = STATUS_CLEAR;
			}
		}

		if (S4CON & M_RI) {
			S4CON &= ~M_RI;
			fifoWrite(&UART4_inputBuffer, S4BUF);
		}
	}
#endif // HAL_UARTS >= 3


uint8_t uartGetCharacter(Uart uart) {
	uint8_t result = 0;
	FifoBuffer *buffer = inputBuffer(uart);
	
	if (fifoLength(buffer) > 0) {
		result = fifoRead(buffer);
	}
	
	return result;
}

uint8_t uartSendCharacter(Uart uart, uint8_t c) {
	FifoBuffer *buffer = outputBuffer(uart);
	uint8_t result = fifoWrite(buffer, c);
	
	if (fifoLength(buffer) > 0 && buffer->status == STATUS_CLEAR) {
		buffer->status = STATUS_SENDING;
		
		switch (uart) {
		case UART1:
			S1BUF = fifoRead(buffer);
			break;
		
#if HAL_UARTS >= 2
		case UART2:
			S2BUF = fifoRead(buffer);
			break;
#endif // HAL_UARTS >= 2
		
#if HAL_UARTS >= 3
		case UART3:
			S3BUF = fifoRead(buffer);
			break;
		
		case UART4:
			S4BUF = fifoRead(buffer);
			break;
#endif // HAL_UARTS >= 3
		}
	}
	
	return result;
}
