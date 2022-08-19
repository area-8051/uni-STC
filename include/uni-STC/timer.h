/**
 * @file uni-STC/timer.h
 * 
 * Register, bit and macro definitions for timers, including watchdog
 * and power-off wake-up timers.
 */

#ifndef _UNISTC_TIMER_H
#define _UNISTC_TIMER_H

/**
 * When using an STC15W4K32S4:
 *     The TIMERS_HAS_T3_T4 macro must be defined.
 * 
 * When using an STC8A8K64D4:
 *     The MCU_HAS_DMA macro must be defined.
 */

// All MCU have T0, T2 and WDT. Other timers might be available 
// depending on the number of pins and MCU family.

#ifndef NB_TIMERS
	#error "NB_TIMER must be defined in the MCU configuration header."
#endif

#if NB_TIMERS > 2
	#define TIMER_HAS_T1
#endif

#if NB_TIMERS >= 5
	#define TIMER_HAS_T3_T4
#endif

#if MCU_FAMILY == 12
	#define TIMER_HAS_BRT
#else
	#define TIMER_HAS_T2
#endif // MCU_FAMILY == 12

#if MCU_FAMILY == 8
	#define TIMER_HAS_AUXINTIF
	
	#if MCU_SERIES == 'G'
		#define TIMER_HAS_PRESCALERS
	#endif // MCU_SERIES == 'G'
	
	#if MCU_SERIES == 'H' || (MCU_SERIES == 'A' && defined(MCU_HAS_DMA))
		#define TIMER_HAS_PRESCALERS
		#define TIMER_HAS_T3_T4_PIN_SWITCH
	#endif // MCU_SERIES == 'H'
#endif // MCU_FAMILY == 8

// SFR TCON: Timer control
SFR(TCON, 0x88);
SBIT(T0R, 0x88, 4);
SBIT(T0IF, 0x88, 5);

#define M_T0R 0x10
#define P_T0R 4

#define M_T0IF 0x20
#define P_T0IF 5

#ifdef TIMER_HAS_T1
	SBIT(T1R, 0x88, 6);
	SBIT(T1IF, 0x88, 7);
	
	#define M_T1R 0x40
	#define P_T1R 6
	
	#define M_T1IF 0x80
	#define P_T1IF 7
#endif // TIMER_HAS_T1

// SFR TMOD: Timer mode
SFR(TMOD, 0x89);

#define M_T0_M 0x03
#define P_T0_M 0

#define M_T0_C_T 0x4
#define P_T0_C_T 2

#define M_T0_GATE 0x8
#define P_T0_GATE 3

#ifdef TIMER_HAS_T1
	#define M_T1_M 0x30
	#define P_T1_M 4
	
	#define M_T1_C_T 0x40
	#define P_T1_C_T 6
	
	#define M_T1_GATE 0x80
	#define P_T1_GATE 7
#endif // TIMER_HAS_T1

// SFR TL0: Timer 0 low
SFR(T0L, 0x8A);
// SFR TH0: Timer 0 high
SFR(T0H, 0x8C);

// Timer 0 as an int
SFR16E(T0, 0x8C8A);

// Timer 0 interrupt
#define TIMER0_INTERRUPT 1
#define TIMER0_VECTOR_ADDR 0x0B

// Bit mask for use with IE1
#define M_ET0 0x02
#define P_ET0 1

// Bit mask for use with IP1L and IP1H
#define M_PT0 0x02
#define P_PT0 1

#ifdef TIMER_HAS_T1
	// SFR TL1: Timer 1 low
	SFR(T1L, 0x8B);
	// SFR TH1: Timer 1 high
	SFR(T1H, 0x8D);
	
	// Timer 1 as an int
	SFR16E(T1, 0x8D8B);
	
	// Timer 1 interrupt
	#define TIMER1_INTERRUPT 3
	#define TIMER1_VECTOR_ADDR 0x1B
	
	// Bit mask for use with IE1
	#define M_ET1 0x08
	#define P_ET1 3
	
	// Bit mask for use with IP1L and IP1H
	#define M_PT1 0x08
	#define P_PT1 3
#endif // TIMER_HAS_T1

#ifdef TIMER_HAS_T2
	// SFR TL2: Timer 2 low
	SFR(T2L, 0xD7);
	// SFR TH2: Timer 2 high
	SFR(T2H, 0xD6);
	
	// Timer 2 as an int
	SFR16E(T2, 0xD6D7);
#endif // TIMER_HAS_T2

#ifdef TIMER_HAS_BRT
	SFR(BRT, 0x9C);
#endif // TIMER_HAS_BRT

// Bit masks for use with INT_CLKO (and WAKE_CLKO for STC12)
#define M_T0CLKO 0x1
#define P_T0CLKO 0

#ifdef TIMER_HAS_T1
	#define M_T1CLKO 0x2
	#define P_T1CLKO 1
#endif // TIMER_HAS_T1

#define M_T2CLKO 0x4
#define P_T2CLKO 2

#if MCU_FAMILY == 12
	// Bit mask for use with WAKE_CLKO
	// Alias of M_T2CLKO / P_T2CLKO
	#define M_BRTCLKO 0x4
	#define P_BRTCLKO 2
#endif // MCU_FAMILY == 12

// SFR AUXR: Auxiliary register
SFR(AUXR, 0x8E);
#define M_T0x12 0x80
#define P_T0x12 7

#ifdef TIMER_HAS_T1
	#define M_T1x12 0x40
	#define P_T1x12 6
#endif // TIMER_HAS_T1

#ifdef TIMER_HAS_T2
	#define M_T2_C_T 0x8
	#define P_T2_C_T 3
#endif // TIMER_HAS_T2

// Defining these macros also for STC12 facilitates MCU-independent
// coding (BRT is nothing more than an 8-bit timer 2, so all T2
// macros apply, only the counter SFR differs.)
#define M_T2x12 0x4
#define P_T2x12 2

#define M_T2R 0x10
#define P_T2R 4

#ifdef TIMER_HAS_BRT
	#define M_BRTx12 0x4
	#define P_BRTx12 2

	#define M_BRTR 0x10
	#define P_BRTR 4
#endif // TIMER_HAS_BRT

// SFR WDT_CONTR: Watchdog timer control
SFR(WDT_CONTR, 0xC1);

#define M_WDT_PS 0x07
#define P_WDT_PS 0

#define M_IDL_WDT 0x8
#define P_IDL_WDT 3

#define M_CLR_WDT 0x10
#define P_CLR_WDT 4

#define M_EN_WDT 0x20
#define P_EN_WDT 5

#define M_WDT_FLAG 0x80
#define P_WDT_FLAG 7

#ifdef TIMER_HAS_T3_T4
	// SFR T4T3M: T4 and T3 mode register
	SFR(T4T3M, 0xD1);

	#define M_T3CLKO 0x1
	#define P_T3CLKO 0
	
	#define M_T3x12 0x2
	#define P_T3x12 1
	
	#define M_T3_C_T 0x4
	#define P_T3_C_T 2
	
	#define M_T3R 0x8
	#define P_T3R 3
	
	#define M_T4CLKO 0x10
	#define P_T4CLKO 4
	
	#define M_T4x12 0x20
	#define P_T4x12 5
	
	#define M_T4_C_T 0x40
	#define P_T4_C_T 6
	
	#define M_T4R 0x80
	#define P_T4R 7

	// SFR T4H: Timer 4 high
	SFR(T4H, 0xD2);
	// SFR T4L: Timer 4 low
	SFR(T4L, 0xD3);
	
	// Timer 4 as an int
	SFR16E(T4, 0xD2D3);

	// SFR T3H: Timer 3 high
	SFR(T3H, 0xD4);
	// SFR T3L: Timer 3 low
	SFR(T3L, 0xD5);
	
	// Timer 3 as an int
	SFR16E(T3, 0xD4D5);

	// Timer 3 interrupt
	#define TIMER3_INTERRUPT 19
	#define TIMER3_VECTOR_ADDR 0x9B
	
	// Timer 4 interrupt
	#define TIMER4_INTERRUPT 20
	#define TIMER4_VECTOR_ADDR 0xA3
	
	// Bit masks for use with IE2
	#define M_ET3 0x40
	#define P_ET3 6
	
	#define M_ET4 0x80
	#define P_ET4 7
#endif // TIMER_HAS_T3_T4

#ifdef TIMER_HAS_T2
	// Timer 2 interrupt
	#define TIMER2_INTERRUPT 12
	#define TIMER2_VECTOR_ADDR 0x63
	
	// Bit mask for use with IE2
	#define M_ET2 0x04
	#define P_ET2 2
#endif // TIMER_HAS_T2

#ifdef TIMER_HAS_AUXINTIF
	// SFR AUXINTIF: Extended external interrupt flag register
	SFR(AUXINTIF, 0xEF);

	#ifdef TIMER_HAS_T2
		#define M_T2IF 0x1
		#define P_T2IF 0
	#endif // TIMERS_HAS_T2

	#ifdef TIMER_HAS_T3_T4
		#define M_T3IF 0x2
		#define P_T3IF 1
		
		#define M_T4IF 0x4
		#define P_T4IF 2
	#endif // TIMER_HAS_T3_T4
#endif // TIMER_HAS_AUXINTIF

#ifdef TIMER_HAS_PRESCALERS
	#ifdef TIMER_HAS_T2
		// SFR TM2PS: Timer 2 clock prescaler register
		SFRX(TM2PS, 0xFEA2);
	#endif // TIMER_HAS_T2

	#ifdef TIMER_HAS_T3_T4
		// SFR TM3PS: Timer 3 clock prescaler register
		SFRX(TM3PS, 0xFEA3);
		// SFR TM4PS: Timer 4 clock prescaler register
		SFRX(TM4PS, 0xFEA4);
	#endif // TIMER_HAS_T3_T4
#endif // TIMER_HAS_PRESCALERS

#ifdef TIMER_HAS_T3_T4_PIN_SWITCH
	// SFR T3T4PIN: T3/T4 pin configuration switch
	SFRX(T3T4PIN, 0xFEAC);
	
	#define M_T3T4SEL 0x1
	#define P_T3T4SEL 0
#endif // TIMER_HAS_T3_T4

typedef enum {
	TIMER0 = 0,
#ifdef TIMER_HAS_T1
	TIMER1 = 1,
#endif // TIMER_HAS_T1
	TIMER2 = 2,
#ifdef TIMER_HAS_T3_T4
	TIMER3,
	TIMER4,
#endif // TIMER_HAS_T3_T4
} Timer;

#endif // _UNISTC_TIMER_H
