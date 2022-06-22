/**
 * @file uni-STC/interrupt.h
 * 
 * Register, bit and macro definitions
 */

#ifndef _UNISTC_INTERRUPT_H
#define _UNISTC_INTERRUPT_H

#if MCU_FAMILY == 8
	#if MCU_SERIES == 'G'
		#define MCU_HAS_IP3
	#elif MCU_SERIES == 'H'
		#define MCU_HAS_IP3
	#elif MCU_SERIES == 'A' && defined(MCU_HAS_DMA)
		// STC8A8K64D4
		#define MCU_HAS_IP3
	#endif
#endif // MCU_FAMILY == 8

// Bits in the TCON SFR
// ITn => interrupt triggers on falling edge only if set,
// or both rising and falling edges if cleared.
// INTnIF => external interrupt request flag.
SBIT(IT0, 0x88, 0);
SBIT(INT0IF, 0x88, 1);
SBIT(IT1, 0x88, 2);
SBIT(INT1IF, 0x88, 3);

// Bit masks for use with TCON
#define M_IT0 0x01
#define P_IT0 0

#define M_INT0IF 0x02
#define P_INT0IF 1

#define M_IT1 0x04
#define P_IT1 2

#define M_INT1IF 0x08
#define P_INT1IF 3

// Bit masks for use with AUXINTIF
#define M_INT2IF 0x10
#define P_INT2IF 4

#define M_INT3IF 0x20
#define P_INT3IF 5

#define M_INT4IF 0x40
#define P_INT4IF 6

#if MCU_FAMILY == 15 || MCU_FAMILY == 8
	// SFR INT_CLKO: CLK output and external interrupt enable register
	SFR(INT_CLKO, 0x8F);
	
	#define M_EX2 0x10
	#define P_EX2 4
	
	#define M_EX3 0x20
	#define P_EX3 5
	
	#define M_EX4 0x40
	#define P_EX4 6
#endif // MCU_FAMILY == 15 || MCU_FAMILY == 8

/**
 * Note: there are no M_PX2 and M_PX3 constants.
 * INT2 and INT3 always have the lowest priority.
 */

// SFR IE1: Interrupt enable
SFR(IE1, 0xA8);
SBIT(EA, 0xA8, 7);

#define M_EX0 0x01
#define P_EX0 0

#define M_EX1 0x04
#define P_EX1 2

#define M_ELVD 0x40
#define P_ELVD 6

// SFR IE2: Interrupt enable 2
SFR(IE2, 0xAF);

// SFR IP1L: Interrupt priority register low
SFR(IP1L, 0xB8);

#define M_PX0 0x01
#define P_PX0 0

#define M_PX1 0x04
#define P_PX1 2

#define M_PLVD 0x40
#define P_PLVD 6

// SFR IP1H: Interrupt priority register high
SFR(IP1H, 0xB7);

// SFR IP2L: Interrupt priority register 2 low
SFR(IP2L, 0xB5);

#define M_PX4 0x10
#define P_PX4 4

// SFR IP2H: Interrupt priority register 2 high
SFR(IP2H, 0xB6);

#ifdef MCU_HAS_IP3
	// SFR IP3L: Interrupt priority register 3 low
	SFR(IP3L, 0xDF);
	
	// SFR IP3H: Interrupt priority register 3 high
	SFR(IP3H, 0xEE);
#endif // MCU_HAS_IP3

// External interrupt 0
#define EXTINT0_INTERRUPT 0
#define EXTINT0_VECTOR_ADDR 0x03

// External interrupt 1
#define EXTINT1_INTERRUPT 2
#define EXTINT1_VECTOR_ADDR 0x13

// External interrupt 2 (falling edge only)
#define EXTINT2_INTERRUPT 10
#define EXTINT2_VECTOR_ADDR 0x53

// External interrupt 3 (falling edge only)
#define EXTINT3_INTERRUPT 11
#define EXTINT3_VECTOR_ADDR 0x5B

// External interrupt 4 (falling edge only)
#define EXTINT4_INTERRUPT 16
#define EXTINT4_VECTOR_ADDR 0x83

// Low-voltage detector interrupt
#define LVD_INTERRUPT 6
#define LVD_VECTOR_ADDR 0x33

#endif // _UNISTC_INTERRUPT_H
