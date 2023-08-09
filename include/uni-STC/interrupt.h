/**
 * @file uni-STC/interrupt.h
 * 
 * Register, bit and macro definitions
 */

#ifndef _UNISTC_INTERRUPT_H
#define _UNISTC_INTERRUPT_H

/**
 * uni-STC naming convention for interrupt settings:
 * 
 * <source>IE = Interrupt Enable
 * <source>IF = Interrupt Flag
 * <source>PR = interrupt PRiority
 * <source>TR = interrupt TRigger mode (for INT0 and INT1)
 * 
 * with <source> in:
 * 
 * INT<n> = external interrupt
 * T<n> = timer
 * S<n> = serial port
 */

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
SBIT(INT0TR, 0x88, 0);
SBIT(INT1TR, 0x88, 2);

/**
 * Note: bits INT0IF and INT1IF are not defined because they are
 * automatically cleared by the CPU upon ISR entry, and each
 * interrupt has its own ISR, so there's no need to check or
 * set these flags.
*/

// Constants for use with INT0TR and INT1TR
#define INTxTR_BOTH_EDGES 0
#define INTxTR_FALLING_EDGE 1

// Bit masks for use with TCON
#define M_INT0TR 0x01
#define P_INT0TR 0

#define M_INT0IF 0x02
#define P_INT0IF 1

#define M_INT1TR 0x04
#define P_INT1TR 2

#define M_INT1IF 0x08
#define P_INT1IF 3

#if MCU_FAMILY != 90
	// Bit masks for use with AUXINTIF
	#define M_INT2IF 0x10
	#define P_INT2IF 4

	#define M_INT3IF 0x20
	#define P_INT3IF 5

	#define M_INT4IF 0x40
	#define P_INT4IF 6
#endif

// Note: the STC12 has only INT0 and INT1

#if MCU_FAMILY == 15 || MCU_FAMILY == 8
	// SFR INT_CLKO: CLK output and external interrupt enable register
	SFR(INT_CLKO, 0x8F);
	
	#define M_INT2IE 0x10
	#define P_INT2IE 4
	
	#define M_INT3IE 0x20
	#define P_INT3IE 5
	
	#define M_INT4IE 0x40
	#define P_INT4IE 6
#endif // MCU_FAMILY == 15 || MCU_FAMILY == 8

/**
 * Note: there are no M_PX2 and M_PX3 constants.
 * INT2 and INT3 always have the lowest priority.
 */

// SFR IE1: Interrupt enable
SFR(IE1, 0xA8);
SBIT(INT0IE, 0xA8, 0);
SBIT(INT1IE, 0xA8, 2);
SBIT(EA, 0xA8, 7);

#define M_INT0IE 0x01
#define P_INT0IE 0

#define M_INT1IE 0x04
#define P_INT1IE 2

#if MCU_FAMILY != 90
	#define M_LVDIE 0x40
	#define P_LVDIE 6
#endif

// SFR IP1L: Interrupt priority register low
SFR(IP1L, 0xB8);

#define M_INT0PR 0x01
#define P_INT0PR 0

#define M_INT1PR 0x04
#define P_INT1PR 2

#if MCU_FAMILY != 90
	#define M_LVDPR 0x40
	#define P_LVDPR 6
#endif

// SFR IP1H: Interrupt priority register high
SFR(IP1H, 0xB7);

#if MCU_FAMILY == 90
	// SFR XICON: Auxiliary interrupt control
	SFR(XICON, 0xE8);
	SBIT(INT2TR, 0xE8, 0);
	SBIT(INT2IF, 0xE8, 1);
	SBIT(INT2IE, 0xE8, 2);
	SBIT(INT3TR, 0xE8, 4);
	SBIT(INT3IF, 0xE8, 5);
	SBIT(INT3IE, 0xE8, 6);
	
	// External interrupts 2 and 3
	// INTnTR => interrupt triggers on falling edge only if set,
	// or both rising and falling edges if cleared.
	// INTnIF => external interrupt request flag.
	#define M_INT2TR 0x01
	#define P_INT2TR 0
	#define M_INT2IF 0x02
	#define P_INT2IF 1
	#define M_INT2IE 0x04
	#define P_INT2IE 2

	#define M_INT3TR 0x10
	#define P_INT3TR 4
	#define M_INT3IF 0x20
	#define P_INT3IF 5
	#define M_INT3IE 0x40
	#define P_INT3IE 6
	
	SBIT(INT2PRL, 0xE8, 3); // in XICON
	SBIT(INT2PRH, 0xB7, 6); // in IP1H
	SBIT(INT3PRL, 0xE8, 7); // in XICON
	SBIT(INT3PRH, 0xB7, 7); // in IP1H
	
	// Timer 2
	SBIT(ET2, 0xA8, 5); // in IE1
#else
	// SFR IE2: Interrupt enable 2
	SFR(IE2, 0xAF);
	
	// SFR IP2L: Interrupt priority register 2 low
	SFR(IP2L, 0xB5);

	#define M_INT4PR 0x10
	#define P_INT4PR 4

	// SFR IP2H: Interrupt priority register 2 high
	SFR(IP2H, 0xB6);

	#ifdef MCU_HAS_IP3
		// SFR IP3L: Interrupt priority register 3 low
		SFR(IP3L, 0xDF);
		
		// SFR IP3H: Interrupt priority register 3 high
		SFR(IP3H, 0xEE);
	#endif // MCU_HAS_IP3
#endif // MCU_FAMILY == 90

// External interrupt 0
#define EXTINT0_INTERRUPT 0
#define EXTINT0_VECTOR_ADDR 0x03

// External interrupt 1
#define EXTINT1_INTERRUPT 2
#define EXTINT1_VECTOR_ADDR 0x13

#if MCU_FAMILY == 90
	// External interrupt 2 (falling edge only)
	#define EXTINT2_INTERRUPT 6
	#define EXTINT2_VECTOR_ADDR 0x33

	// External interrupt 3 (falling edge only)
	#define EXTINT3_INTERRUPT 7
	#define EXTINT3_VECTOR_ADDR 0x3B
#else
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
#endif

#endif // _UNISTC_INTERRUPT_H
