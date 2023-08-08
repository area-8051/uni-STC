/*
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

/**
 * @file STC/90C5xRD/PDIP40.h
 * 
 * Register, bit and macro definitions for the STC90
 */

#ifndef _STC90C5xRD_PDIP40_H
#define _STC90C5xRD_PDIP40_H

#define MCU_FAMILY 90
#define MCU_SERIES 'C'
#define MCU_PINS 40

#define MCU_CYCLES 12

#define MCU_HAS_NO_P5
#define NB_TIMERS 3
#define MCU_HAS_DUAL_DPTR

// Thanks to these includes, the STC90 can benefit from a small subset
// of the HAL: gpio-hal, timer-hal, uart-hal, delay, fifo-buffer,
// serial-console, crtxinit, and possibly eeprom-hal.

#include <compiler.h>
#include <uni-STC/uni-STC.h>
#include <uni-STC/dptr.h>
#include <uni-STC/gpio/gpio.h>
#include <uni-STC/iap.h>
#include <uni-STC/interrupt.h>
#include <uni-STC/misc.h>
#include <uni-STC/timer.h>
#include <uni-STC/uart.h>

#endif // _STC90C5xRD_PDIP40_H
