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
#include <gpio-hal.h>

/**
 * @file gpio-hal.c
 * 
 * GPIO abstraction layer implementation.
 */

static uint8_t __gpio_setBits(uint8_t portValue, uint8_t cfgValue, GpioConfig *gpioConfig) {
	return cfgValue ? (portValue | gpioConfig->__setMask) : (portValue & gpioConfig->__clearMask);
}

static uint8_t __isOutput(GpioConfig *gpioConfig) {
	return gpioConfig->pinMode == GPIO_BIDIRECTIONAL_MODE || gpioConfig->pinMode == GPIO_PUSH_PULL_MODE || gpioConfig->pinMode == GPIO_OPEN_DRAIN_MODE;
}

static uint8_t __isInput(GpioConfig *gpioConfig) {
	return gpioConfig->pinMode == GPIO_BIDIRECTIONAL_MODE || gpioConfig->pinMode == GPIO_HIGH_IMPEDANCE_MODE;
}

void gpioConfigure(GpioConfig *gpioConfig) {
	// Pre-generate bit masks for read/write operations
	uint8_t mask = 0;
	
	for (uint8_t n = gpioConfig->count; n > 0; n--) {
		mask = mask << 1;
		mask |= 1;
	}
	
	gpioConfig->__setMask = mask << gpioConfig->pin;
	gpioConfig->__clearMask = ~gpioConfig->__setMask;
	
	uint8_t pm1 = 0;
	uint8_t pm0 = 0;

#ifdef GPIO_HAS_PU_NCS
	uint8_t pncs = 0;
	uint8_t ppu = 0;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
	uint8_t pdr = 0;
	uint8_t psr = 0;
	uint8_t pie = 0;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
	uint8_t pim1 = 0;
	uint8_t pim0 = 0;
	uint8_t pintf = 0;
	uint8_t pinte = 0;
	uint8_t pwkue = 0;
#endif // GPIO_HAS_INT_WK
	
	switch (gpioConfig->port) {
// -- P0 ----------------------------------

#ifdef GPIO_HAS_P0
	case GPIO_PORT0:
		pm1 = P0M1;
		pm0 = P0M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P0NCS;
		ppu = P0PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P0DR;
		psr = P0SR;
		pie = P0IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P0IM1;
		pim0 = P0IM0;
		pintf = P0INTF;
		pinte = P0INTE;
		pwkue = P0WKUE;
#endif // GPIO_HAS_INT_WK
	
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P0

// -- P1 ----------------------------------

#ifdef GPIO_HAS_P1
	case GPIO_PORT1:
		pm1 = P1M1;
		pm0 = P1M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P1NCS;
		ppu = P1PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P1DR;
		psr = P1SR;
		pie = P1IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P1IM1;
		pim0 = P1IM0;
		pintf = P1INTF;
		pinte = P1INTE;
		pwkue = P1WKUE;
#endif // GPIO_HAS_INT_WK
	
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P1

// -- P2 ----------------------------------

#ifdef GPIO_HAS_P2
	case GPIO_PORT2:
		pm1 = P2M1;
		pm0 = P2M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P2NCS;
		ppu = P2PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P2DR;
		psr = P2SR;
		pie = P2IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P2IM1;
		pim0 = P2IM0;
		pintf = P2INTF;
		pinte = P2INTE;
		pwkue = P2WKUE;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P2

// -- P3 ----------------------------------

	case GPIO_PORT3:
		pm1 = P3M1;
		pm0 = P3M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P3NCS;
		ppu = P3PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P3DR;
		psr = P3SR;
		pie = P3IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P3IM1;
		pim0 = P3IM0;
		pintf = P3INTF;
		pinte = P3INTE;
		pwkue = P3WKUE;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;

// -- P4 ----------------------------------

#ifdef GPIO_HAS_P4
	case GPIO_PORT4:
		pm1 = P4M1;
		pm0 = P4M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P4NCS;
		ppu = P4PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P4DR;
		psr = P4SR;
		pie = P4IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P4IM1;
		pim0 = P4IM0;
		pintf = P4INTF;
		pinte = P4INTE;
		pwkue = P4WKUE;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P4

// -- P5 ----------------------------------

#ifdef GPIO_HAS_P5
	case GPIO_PORT5:
		pm1 = P5M1;
		pm0 = P5M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P5NCS;
		ppu = P5PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P5DR;
		psr = P5SR;
		pie = P5IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P5IM1;
		pim0 = P5IM0;
		pintf = P5INTF;
		pinte = P5INTE;
		pwkue = P5WKUE;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P5

// -- P6 ----------------------------------

#ifdef GPIO_HAS_P6
	case GPIO_PORT6:
		pm1 = P6M1;
		pm0 = P6M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P6NCS;
		ppu = P6PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P6DR;
		psr = P6SR;
		pie = P6IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P6IM1;
		pim0 = P6IM0;
		pintf = P6INTF;
		pinte = P6INTE;
		pwkue = P6WKUE;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P6

// -- P7 ----------------------------------

#ifdef GPIO_HAS_P7
	case GPIO_PORT7:
		pm1 = P7M1;
		pm0 = P7M0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		pncs = P7NCS;
		ppu = P7PU;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		pdr = P7DR;
		psr = P7SR;
		pie = P7IE;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		pim1 = P7IM1;
		pim0 = P7IM0;
		pintf = P7INTF;
		pinte = P7INTE;
		pwkue = P7WKUE;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P7
	}
	
	pm1 = __gpio_setBits(pm1, gpioConfig->pinMode & 2, gpioConfig);
	pm0 = __gpio_setBits(pm0, gpioConfig->pinMode & 1, gpioConfig);
	
#ifdef GPIO_HAS_PU_NCS
	pncs = __gpio_setBits(pncs, gpioConfig->schmidtTrigger, gpioConfig);
	ppu = __gpio_setBits(ppu, gpioConfig->internalPullUp, gpioConfig);
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
	if (__isOutput(gpioConfig)) {
		pdr = __gpio_setBits(pdr, gpioConfig->currentDrive, gpioConfig);
		psr = __gpio_setBits(psr, gpioConfig->slewRate, gpioConfig);
	}
	
	if (__isInput(gpioConfig)) {
		pie = __gpio_setBits(pie, gpioConfig->digitalInput, gpioConfig);
	}
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
	pim1 = __gpio_setBits(pim1, gpioConfig->interruptTrigger & 2, gpioConfig);
	pim0 = __gpio_setBits(pim0, gpioConfig->interruptTrigger & 1, gpioConfig);
	pintf &= gpioConfig->__clearMask;
	pinte = __gpio_setBits(pinte, gpioConfig->pinInterrupt, gpioConfig);
	pwkue = __gpio_setBits(pwkue, gpioConfig->wakeUpInterrupt, gpioConfig);
#endif // GPIO_HAS_INT_WK
	
	switch (gpioConfig->port) {
// -- P0 ----------------------------------

#ifdef GPIO_HAS_P0
	case GPIO_PORT0:
		P0M1 = pm1;
		P0M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P0NCS = pncs;
		P0PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P0DR = pdr;
		P0SR = psr;
		P0IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P0IM1 = pim1;
		P0IM0 = pim0;
		P0INTF = pintf;
		P0INTE = pinte;
		P0WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
	
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P0

// -- P1 ----------------------------------

#ifdef GPIO_HAS_P1
	case GPIO_PORT1:
		P1M1 = pm1;
		P1M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P1NCS = pncs;
		P1PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P1DR = pdr;
		P1SR = psr;
		P1IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P1IM1 = pim1;
		P1IM0 = pim0;
		P1INTF = pintf;
		P1INTE = pinte;
		P1WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
	
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P1

// -- P2 ----------------------------------

#ifdef GPIO_HAS_P2
	case GPIO_PORT2:
		P2M1 = pm1;
		P2M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P2NCS = pncs;
		P2PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P2DR = pdr;
		P2SR = psr;
		P2IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P2IM1 = pim1;
		P2IM0 = pim0;
		P2INTF = pintf;
		P2INTE = pinte;
		P2WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P2

// -- P3 ----------------------------------

	case GPIO_PORT3:
		P3M1 = pm1;
		P3M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P3NCS = pncs;
		P3PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P3DR = pdr;
		P3SR = psr;
		P3IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P3IM1 = pim1;
		P3IM0 = pim0;
		P3INTF = pintf;
		P3INTE = pinte;
		P3WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;

// -- P4 ----------------------------------

#ifdef GPIO_HAS_P4
	case GPIO_PORT4:
		P4M1 = pm1;
		P4M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P4NCS = pncs;
		P4PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P4DR = pdr;
		P4SR = psr;
		P4IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P4IM1 = pim1;
		P4IM0 = pim0;
		P4INTF = pintf;
		P4INTE = pinte;
		P4WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P4

// -- P5 ----------------------------------

#ifdef GPIO_HAS_P5
	case GPIO_PORT5:
		P5M1 = pm1;
		P5M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P5NCS = pncs;
		P5PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P5DR = pdr;
		P5SR = psr;
		P5IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P5IM1 = pim1;
		P5IM0 = pim0;
		P5INTF = pintf;
		P5INTE = pinte;
		P5WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P5

// -- P6 ----------------------------------

#ifdef GPIO_HAS_P6
	case GPIO_PORT6:
		P6M1 = pm1;
		P6M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P6NCS = pncs;
		P6PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P6DR = pdr;
		P6SR = psr;
		P6IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P6IM1 = pim1;
		P6IM0 = pim0;
		P6INTF = pintf;
		P6INTE = pinte;
		P6WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P6

// -- P7 ----------------------------------

#ifdef GPIO_HAS_P7
	case GPIO_PORT7:
		P7M1 = pm1;
		P7M0 = pm0;
		ENABLE_EXTENDED_SFR();
	
#ifdef GPIO_HAS_PU_NCS
		P7NCS = pncs;
		P7PU = ppu;
#endif // GPIO_HAS_PU_NCS
		
#ifdef GPIO_HAS_SR_DR_IE
		P7DR = pdr;
		P7SR = psr;
		P7IE = pie;
#endif // GPIO_HAS_SR_DR_IE
		
#ifdef GPIO_HAS_INT_WK
		P7IM1 = pim1;
		P7IM0 = pim0;
		P7INTF = pintf;
		P7INTE = pinte;
		P7WKUE = pwkue;
#endif // GPIO_HAS_INT_WK
		
		DISABLE_EXTENDED_SFR();
		break;
#endif // GPIO_HAS_P7
	}
}

static uint8_t __getPort(GpioPort port) REENTRANT {
	uint8_t value = 0;
	
	switch (port) {
// -- P0 ----------------------------------
#ifdef GPIO_HAS_P0
	case GPIO_PORT0:
		value = P0;
		break;
#endif // GPIO_HAS_P0

// -- P1 ----------------------------------
#ifdef GPIO_HAS_P1
	case GPIO_PORT1:
		value = P1;
		break;
#endif // GPIO_HAS_P1

// -- P2 ----------------------------------
#ifdef GPIO_HAS_P2
	case GPIO_PORT2:
		value = P2;
		break;
#endif // GPIO_HAS_P2

// -- P3 ----------------------------------
	case GPIO_PORT3:
		value = P3;
		break;

// -- P4 ----------------------------------
#ifdef GPIO_HAS_P4
	case GPIO_PORT4:
		value = P4;
		break;
#endif // GPIO_HAS_P4

// -- P5 ----------------------------------
#ifdef GPIO_HAS_P5
	case GPIO_PORT5:
		value = P5;
		break;
#endif // GPIO_HAS_P5

// -- P6 ----------------------------------
#ifdef GPIO_HAS_P6
	case GPIO_PORT6:
		value = P6;
		break;
#endif // GPIO_HAS_P6

// -- P7 ----------------------------------

#ifdef GPIO_HAS_P7
	case GPIO_PORT7:
		value = P7;
		break;
#endif // GPIO_HAS_P7
	}
	
	return value;
}

uint8_t gpioRead(GpioConfig *gpioConfig) REENTRANT {
	return (__getPort(gpioConfig->port) & gpioConfig->__setMask) >> gpioConfig->pin;
}

void gpioWrite(GpioConfig *gpioConfig, uint8_t value) REENTRANT {
	if (gpioConfig->count == 1) {
		// In case the caller wants to set a single bit and expects
		// any non-zero value will be treated as a logical one (which
		// makes sense in C), let's make sure we do.
		value = value ? 1 : 0;
	}
	
	value = (value << gpioConfig->pin) & gpioConfig->__setMask;
	value |= __getPort(gpioConfig->port) & gpioConfig->__clearMask;
	
	switch (gpioConfig->port) {
// -- P0 ----------------------------------
#ifdef GPIO_HAS_P0
	case GPIO_PORT0:
		P0 = value;
		break;
#endif // GPIO_HAS_P0

// -- P1 ----------------------------------
#ifdef GPIO_HAS_P1
	case GPIO_PORT1:
		P1 = value;
		break;
#endif // GPIO_HAS_P1

// -- P2 ----------------------------------
#ifdef GPIO_HAS_P2
	case GPIO_PORT2:
		P2 = value;
		break;
#endif // GPIO_HAS_P2

// -- P3 ----------------------------------
	case GPIO_PORT3:
		P3 = value;
		break;

// -- P4 ----------------------------------
#ifdef GPIO_HAS_P4
	case GPIO_PORT4:
		P4 = value;
		break;
#endif // GPIO_HAS_P4

// -- P5 ----------------------------------
#ifdef GPIO_HAS_P5
	case GPIO_PORT5:
		P5 = value;
		break;
#endif // GPIO_HAS_P5

// -- P6 ----------------------------------
#ifdef GPIO_HAS_P6
	case GPIO_PORT6:
		P6 = value;
		break;
#endif // GPIO_HAS_P6

// -- P7 ----------------------------------
#ifdef GPIO_HAS_P7
	case GPIO_PORT7:
		P7 = value;
		break;
#endif // GPIO_HAS_P7
	}
}
