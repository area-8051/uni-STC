/**
 * @file uni-STC/gpio/gpio0.h
 * 
 * Register, bit and macro definitions for GPIO port 0
 */

#ifndef _UNISTC_GPIO_GPIO0_H
#define _UNISTC_GPIO_GPIO0_H

// SFR P0: Port 0
SFR(P0, 0x80);
SBIT(P0_0, 0x80, 0);
SBIT(P0_1, 0x80, 1);
SBIT(P0_2, 0x80, 2);
SBIT(P0_3, 0x80, 3);
SBIT(P0_4, 0x80, 4);
SBIT(P0_5, 0x80, 5);
SBIT(P0_6, 0x80, 6);
SBIT(P0_7, 0x80, 7);

// SFR P0M1: Port 0 Configuration 1
SFR(P0M1, 0x93);

// SFR P0M0: Port 0 Configuration 0
SFR(P0M0, 0x94);

#ifdef GPIO_HAS_INT_WK
	// SFR P0INTE: Port 0 interrupt enable register
	SFRX(P0INTE, 0xFD00);

	// SFR P0INTF: Port 0 interrupt flag register
	SFRX(P0INTF, 0xFD10);

	// SFR P0IM0: Port 0 interrupt mode register 0
	SFRX(P0IM0, 0xFD20);

	// SFR P0IM1: Port 0 interrupt mode register 1
	SFRX(P0IM1, 0xFD30);

	// SFR P0WKUE: Port 0 interrupt wake-up enable register
	SFRX(P0WKUE, 0xFD40);
	
	// GPIO port 0 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P0_INTERRUPT 37
	#define P0_VECTOR_ADDR 0x012B
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P0PU: Port 0 pull-up resistor control register
	SFRX(P0PU, 0xFE10);

	// SFR P0NCS: Port 0 Schmidt trigger control register
	SFRX(P0NCS, 0xFE18);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P0SR: Port 0 slew rate control register
	SFRX(P0SR, 0xFE20);

	// SFR P0DR: Port 0 drive current control register
	SFRX(P0DR, 0xFE28);

	// SFR P0IE: Port 0 input enable control register
	SFRX(P0IE, 0xFE30);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO0_H
