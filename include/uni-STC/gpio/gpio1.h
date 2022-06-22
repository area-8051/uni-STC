/**
 * @file uni-STC/gpio/gpio1.h
 * 
 * Register, bit and macro definitions for GPIO port 1
 */

#ifndef _UNISTC_GPIO_GPIO1_H
#define _UNISTC_GPIO_GPIO1_H

// SFR P1: Port 1
SFR(P1, 0x90);
SBIT(P1_0, 0x90, 0);
SBIT(P1_1, 0x90, 1);
SBIT(P1_2, 0x90, 2);
SBIT(P1_3, 0x90, 3);
SBIT(P1_4, 0x90, 4);
SBIT(P1_5, 0x90, 5);
SBIT(P1_6, 0x90, 6);
SBIT(P1_7, 0x90, 7);

// SFR P1M1: Port 1 Configuration 1
SFR(P1M1, 0x91);

// SFR P1M0: Port 1 Configuration 0
SFR(P1M0, 0x92);

#ifdef GPIO_HAS_INT_WK
	// SFR P1INTE: Port 1 interrupt enable register
	SFRX(P1INTE, 0xFD01);

	// SFR P1INTF: Port 1 interrupt flag register
	SFRX(P1INTF, 0xFD11);

	// SFR P1IM0: Port 1 interrupt mode register 0
	SFRX(P1IM0, 0xFD21);

	// SFR P1IM1: Port 1 interrupt mode register 1
	SFRX(P1IM1, 0xFD31);

	// SFR P1WKUE: Port 1 interrupt wake-up enable register
	SFRX(P1WKUE, 0xFD41);
	
	// GPIO port 1 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P1_INTERRUPT 38
	#define P1_VECTOR_ADDR 0x0133
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P1PU: Port 1 pull-up resistor control register
	SFRX(P1PU, 0xFE11);

	// SFR P1NCS: Port 1 Schmidt trigger control register
	SFRX(P1NCS, 0xFE19);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P1SR: Port 1 slew rate control register
	SFRX(P1SR, 0xFE21);

	// SFR P1DR: Port 1 drive current control register
	SFRX(P1DR, 0xFE29);

	// SFR P1IE: Port 1 input enable control register
	SFRX(P1IE, 0xFE31);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO1_H
