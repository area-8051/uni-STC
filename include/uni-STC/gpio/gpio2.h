/**
 * @file uni-STC/gpio/gpio2.h
 * 
 * Register, bit and macro definitions for GPIO port 2
 */

#ifndef _UNISTC_GPIO_GPIO2_H
#define _UNISTC_GPIO_GPIO2_H

// SFR P2: Port 2
SFR(P2, 0xA0);
SBIT(P2_0, 0xA0, 0);
SBIT(P2_1, 0xA0, 1);
SBIT(P2_2, 0xA0, 2);
SBIT(P2_3, 0xA0, 3);
SBIT(P2_4, 0xA0, 4);
SBIT(P2_5, 0xA0, 5);
SBIT(P2_6, 0xA0, 6);
SBIT(P2_7, 0xA0, 7);

// SFR P2M1: Port 2 Configuration 1
SFR(P2M1, 0x95);

// SFR P2M0: Port 2 Configuration 0
SFR(P2M0, 0x96);

#ifdef GPIO_HAS_INT_WK
	// SFR P2INTE: Port 2 interrupt enable register
	SFRX(P2INTE, 0xFD02);

	// SFR P2INTF: Port 2 interrupt flag register
	SFRX(P2INTF, 0xFD12);

	// SFR P2IM0: Port 2 interrupt mode register 0
	SFRX(P2IM0, 0xFD22);

	// SFR P2IM1: Port 2 interrupt mode register 1
	SFRX(P2IM1, 0xFD32);

	// SFR P2WKUE: Port 2 interrupt wake-up enable register
	SFRX(P2WKUE, 0xFD42);

	// GPIO port 2 interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define P2_INTERRUPT 39
	#define P2_VECTOR_ADDR 0x013B
#endif // GPIO_HAS_INT_WK

#ifdef GPIO_HAS_PU_NCS
	// SFR P2PU: Port 2 pull-up resistor control register
	SFRX(P2PU, 0xFE12);

	// SFR P2NCS: Port 2 Schmidt trigger control register
	SFRX(P2NCS, 0xFE1A);
#endif // GPIO_HAS_PU_NCS

#ifdef GPIO_HAS_SR_DR_IE
	// SFR P2SR: Port 2 slew rate control register
	SFRX(P2SR, 0xFE22);

	// SFR P2DR: Port 2 drive current control register
	SFRX(P2DR, 0xFE2A);

	// SFR P2IE: Port 2 input enable control register
	SFRX(P2IE, 0xFE32);
#endif // GPIO_HAS_SR_DR_IE

#endif // _UNISTC_GPIO_GPIO2_H
