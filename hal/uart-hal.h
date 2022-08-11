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
#ifndef _UART_HAL_H
#define _UART_HAL_H

/**
 * @file uart-hal.h
 * 
 * UART abstraction layer definitions.
 * 
 * Supported MCU:
 * 
 *     STC12*
 *     STC15*
 *     STC8*
 * 
 * Dependencies:
 * 
 *     timer-hal
 *     fifo-buffer
 * 
 * Optional global macros:
 * 
 *     UART_DEFAULT_SEGMENT (default: __pdata) defines where the HAL's 
 *     state information will be stored, unless overridden per-UART.
 *     Impacts ISR execution time.
 * 
 *     HAL_UARTS (default: NB_UARTS) defines how many UART will be 
 *     supported by the HAL. Useful to reduce both flash and RAM 
 *     footprint.
 * 
 *     UART_DEFAULT_BUFFER_SIZE (default: 16) defines the default size
 *     for UART RX and TX buffers. Impacts RAM footprint.
 * 
 * Optional per-UART macros, with <n> in [1, HAL_UARTS]:
 * 
 *     UART<n>_TX_BUFFER_SIZE (default: UART_DEFAULT_BUFFER_SIZE)
 *     defines the size of UART<n>'s transmit buffer.
 * 
 *     UART<n>_RX_BUFFER_SIZE (default: UART_DEFAULT_BUFFER_SIZE)
 *     defines the size of UART<n>'s receive buffer.
 * 
 *     UART<n>_SEGMENT (default: UART_DEFAULT_SEGMENT) defines where
 *     the HAL's state information for UART<n> will be stored.
 * 
 * **IMPORTANT:** In order to satisfy SDCC's requirements for ISR 
 * handling, this header file **MUST** be included in the C source 
 * file where main() is defined.
 */

/*
 * By default, all available UARTs are exposed through the HAL.
 * However, should you need to reduce your application's RAM or
 * flash usage, you can define the HAL_UARTS macro to expose less
 * UARTs, e.g. setting HAL_UARTS to 2 on an MCU with 4 UARTs would
 * only expose UART1 and UART2.
 */
#ifdef HAL_UARTS
	#if HAL_UARTS < 1 || HAL_UARTS > NB_UARTS
		#error "Macro HAL_UARTS out of range"
	#endif // HAL_UARTS < 1 || HAL_UARTS > NB_UARTS
#else
	#define HAL_UARTS NB_UARTS
#endif

#include <hal-defs.h>
#include <timer-hal.h>

typedef enum {
	UART_USE_TIMER2 = 0,
	UART_USE_OWN_TIMER,
} UartBaudRateTimer;

typedef enum {
	UART_8N1 = 0,
	UART_8E1,
	UART_8O1,
	UART_MULTI_MACHINE,
} UartMode;

typedef enum {
	UART1_SYSCLK_DIV_64 = 0,
	UART1_SYSCLK_DIV_32,
	UART1_SYSCLK_DIV_12,
	UART1_SYSCLK_DIV_2,
} Uart1_9BitMode_Clock;

/**
 * UART1 pin configurations for all STC8 and STC15 > 8 pins.
 * 
 * Value | RxD  | TxD
 * ------+------+------
 *   0   | P3.0 | P3.1
 *   1   | P3.6 | P3.7
 *   2   | P1.6 | P1.7
 *   3   | P4.3 | P4.4  (Invalid on STC15)
 * 
 * UART1 pin configurations for 8-pin STC8.
 * 
 * Value | RxD  | TxD
 * ------+------+------
 *   0   | P3.0 | P3.1
 *   1   | P3.2 | P3.3
 *   2   | P5.4 | P5.5
 *   3   |  --  |  --   (Invalid)
 * 
 * UART1 on STC12 can only use P3.0 & P3.1.
 * 
 * UART2 pin configurations for STC8G, STC8H and STC15.
 * 
 * Value | RxD2 | TxD2
 * ------+------+------
 *   0   | P1.0 | P1.1
 *   1   | P4.6 | P4.7
 * 
 * UART2 pin configurations for STC8A.
 * 
 * Value | RxD2 | TxD2
 * ------+------+------
 *   0   | P1.0 | P1.1
 *   1   | P4.0 | P4.2
 * 
 * UART2 pin configurations for STC12.
 * 
 * Value | RxD2 | TxD2
 * ------+------+------
 *   0   | P1.2 | P1.3
 *   1   | P4.2 | P4.3
 * 
 * UART3 pin configurations.
 * 
 * Value | RxD3 | TxD3
 * ------+------+------
 *   0   | P0.0 | P0.1
 *   1   | P5.0 | P5.1
 * 
 * UART4 pin configurations.
 * 
 * Value | RxD4 | TxD4
 * ------+------+------
 *   0   | P0.2 | P0.3
 *   1   | P5.2 | P5.3
 * 
 */
#include <fifo-buffer.h>

bool uartTransmitBufferHasBytesFree(Uart uart, uint8_t bytes);

TimerStatus uartInitialise(Uart uart, uint32_t baudRate, UartBaudRateTimer baudRateTimer, UartMode mode, uint8_t pinSwitch);

uint8_t uartGetCharacter(Uart uart, BlockingOperation blocking);

bool uartGetBlock(Uart uart, uint8_t *data, uint8_t size, BlockingOperation blocking);

bool uartSendCharacter(Uart uart, uint8_t c, BlockingOperation blocking);

bool uartSendBlock(Uart uart, uint8_t *data, uint8_t size, BlockingOperation blocking);

INTERRUPT_USING(__uart1_isr, UART1_INTERRUPT, 1);

#if HAL_UARTS >= 2
	INTERRUPT_USING(__uart2_isr, UART2_INTERRUPT, 1);
#endif // HAL_UARTS >= 2

#if HAL_UARTS >= 3
	INTERRUPT_USING(__uart3_isr, UART3_INTERRUPT, 1);
	INTERRUPT_USING(__uart4_isr, UART4_INTERRUPT, 1);
#endif // HAL_UARTS >= 3

#endif // _UART_HAL_H
