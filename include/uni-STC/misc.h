/**
 * @file uni-STC/misc.h
 * 
 * Register, bit and macro definitions (pin switching, power control,
 * and a few other SFR).
 */

#ifndef _UNISTC_MISC_H
#define _UNISTC_MISC_H

/**
 * When using an STC15W4K32S4:
 *     The MCU_HAS_EAXSFR macro must be defined.
 */

// SFR SP: Stack pointer
SFR(SP, 0x81);

// SFR PSW: Program status word
SFR(PSW, 0xD0);
SBIT(P, 0xD0, 0);
SBIT(F1, 0xD0, 1);
SBIT(OV, 0xD0, 2);
SBIT(RS0, 0xD0, 3);
SBIT(RS1, 0xD0, 4);
SBIT(F0, 0xD0, 5);
SBIT(AC, 0xD0, 6);
SBIT(CY, 0xD0, 7);

#define M_RS 0x18
#define P_RS 3

// SFR ACC: Accumulator
SFR(ACC, 0xE0);

// SFR B: B register
SFR(B, 0xF0);

// SFR PCON: Power control
SFR(PCON, 0x87);

#define M_IDL 0x1
#define P_IDL 0

#define M_PD 0x2
#define P_PD 1

#define M_GF 0x0c
#define P_GF 2

#define M_POF 0x10
#define P_POF 4

#if MCU_FAMILY == 90
	#define M_SMOD0 0x40
	#define P_SMOD0 6
	#define M_SMOD 0x80
	#define P_SMOD 7
#else
	#define M_LVDF 0x20
	#define P_LVDF 5
#endif // MCU_FAMILY == 90

#if MCU_FAMILY == 8
	// SFR RSTCFG: Reset configuration register
	SFR(RSTCFG, 0xFF);
	
	#define M_LVDS 0x03
	#define P_LVDS 0
	
	#define M_P54RST 0x10
	#define P_P54RST 4
	
	#define M_ENLVR 0x40
	#define P_ENLVR 6

	#define MCU_HAS_EAXSFR

	#if MCU_SERIES == 'G'
		#define MCU_HAS_3BIT_BUS_SPEED
	#elif MCU_SERIES == 'H'
		#define MCU_HAS_3BIT_BUS_SPEED
	#elif defined(STC8A8KxxD4)
		#define MCU_HAS_3BIT_BUS_SPEED
	#else
		// STC8A and STC8F but not STC8A8KxxD4
		
		// SFR AUXR2: Auxiliary register 2
		SFR(AUXR2, 0x97);
		
		#define M_TXLNRX 0x10
		#define P_TXLNRX 4

		// SFR VOCTRL: Voltage control register
		SFR(VOCTRL, 0xBB);
		#define M_SCC 0x80
		#define P_SCC 7
	#endif
#endif // MCU_FAMILY == 8

#if MCU_FAMILY == 12
	// SFR WAKE_CLKO: CLK output power-down wake-up control
	SFR(WAKE_CLKO, 0x8F);
	
	#define M_LVD_WAKE 0x8
	#define P_LVD_WAKE 3
	
	#define M_T0_PIN_IE 0x10
	#define P_T0_PIN_IE 4
	
	#define M_T1_PIN_IE 0x20
	#define P_T1_PIN_IE 5
	
	#define M_RXD_PIN_IE 0x40
	#define P_RXD_PIN_IE 6
	
	#define M_PCAWAKEUP 0x80
	#define P_PCAWAKEUP 7
#endif // MCU_FAMILY == 12

// SFR P_SW1: Peripheral function switch register 1
SFR(P_SW1, 0xA2);

#if MCU_FAMILY == 15 || MCU_FAMILY == 8
	// Bit masks for use with P_SW1
	#define M_SPI_S 0x0c
	#define P_SPI_S 2
	
	#define M_CCP_S 0x30
	#define P_CCP_S 4
	
	#define M_S1_S 0xc0
	#define P_S1_S 6

	// SFR P_SW2: Peripheral function switch register 2
	SFR(P_SW2, 0xBA);
	
	#define M_S2_S 0x1
	#define P_S2_S 0
	
	#define M_S3_S 0x2
	#define P_S3_S 1
	
	#define M_S4_S 0x4
	#define P_S4_S 2
	
	#define M_CMPO_S 0x8
	#define P_CMPO_S 3
	
	#if MCU_FAMILY == 15
		#define M_PWM2345_S 0x10
		#define P_PWM2345_S 4
		
		#define M_PWM67_S 0x20
		#define P_PWM67_S 5
	#endif
	
	#if MCU_FAMILY == 8
		#define M_I2C_S 0x30
		#define P_I2C_S 4
	#endif
	
	#ifdef MCU_HAS_EAXSFR
		#define M_EAXSFR 0x80
		#define P_EAXSFR 7
	#endif
#elif MCU_FAMILY == 12
	// Bit masks for use with P_SW1
	#define M_GF2 0x8
	#define P_GF2 3
	
	#define M_S2_S 0x10
	#define P_S2_S 4
	
	#define M_SPI_S 0x20
	#define P_SPI_S 5
	
	#define M_CCP_S 0x40
	#define P_CCP_S 6
#endif

// Bit mask for use with AUXR
#define M_EXTRAM 0x2
#define P_EXTRAM 1

#if MCU_FAMILY == 12 || MCU_FAMILY == 15
	// SFR P1ASF: P1 analog special function
	SFR(P1ASF, 0x9D);

	// SFR P4SW: P4 function switch
	SFR(P4SW, 0xBB);
	
	#define M_NA_P4_4 0x10
	#define P_NA_P4_4 4
	
	#define M_ALE_P4_5 0x20
	#define P_ALE_P4_5 5
	
	#define M_LVD_P4_6 0x40
	#define P_LVD_P4_6 6
#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15

// SFR BUS_SPEED: Bus speed control
SFR(BUS_SPEED, 0xA1);

#if MCU_FAMILY == 8
	// Bit mask for use with BUS_SPEED
	#ifdef MCU_HAS_3BIT_BUS_SPEED
		#define M_BUS_SPEED 0x07
	#else
		#define M_BUS_SPEED 0x03
	#endif // MCU_HAS_3BIT_BUS_SPEED
	
	#define P_BUS_SPEED 0
	
	#define M_RW_S 0xC0
	#define P_RW_S 6
#elif MCU_FAMILY == 15
	// Bit mask for use with BUS_SPEED
	#define M_EXRTS 0x03
	#define P_EXRTS 0
#elif MCU_FAMILY == 12
	// Bit masks for use with BUS_SPEED
	#define M_RWS 0x07
	#define P_RWS 0
	
	#define M_ALES 0x30
	#define P_ALES 4
#endif

#if MCU_FAMILY == 8 && MCU_SERIES == 'H'
	// SFR SPFUNC: Special function control register
	SFRX(SPFUNC, 0xFE08);
	
	#define M_BKSWR 0x1
	#define P_BKSWR 0

	// SFR RSTFLAG: Reset flag register
	SFRX(RSTFLAG, 0xFE09);
	#define M_EXRST 0x1
	#define P_EXRST 0
	
	#define M_ROMOV 0x2
	#define P_ROMOV 1
	
	#define M_SWR 0x4
	#define P_SWR 2
#endif // MCU_FAMILY == 8 && MCU_SERIES == 'H'

#if MCU_FAMILY == 15 || MCU_FAMILY == 8
	#define MCU_HAS_WAKE_UP_TIMER
#endif // MCU_FAMILY == 15 || MCU_FAMILY == 8

#ifdef MCU_HAS_WAKE_UP_TIMER
	// SFR WKTCL: Power-down wake-up timer control register low
	SFR(WKTCL, 0xAA);
	// SFR WKTCH: Power-down wake-up timer control register high
	SFR(WKTCH, 0xAB);
	
	// WKTC as an int
	SFR16(WKTC, 0xAA);
	
	#define M_WKTEN 0x80
	#define P_WKTEN 7
#endif // MCU_HAS_WAKE_UP_TIMER

/**
 * We enable extended SFR at the very beginning of main() and never 
 * disable them.
 * 
 * In order to do this, you ***MUST*** place the INIT_EXTENDED_SFR()
 * immediately after the opening curly brace of main().
 * 
 * Note: doing so even with an MCU which doesn't have extended SFR will
 * make porting your code more straightforward if you ever need to.
 */

#if defined(MCU_HAS_EAXSFR)
	#define INIT_EXTENDED_SFR()  P_SW2 |= M_EAXSFR;
#else
	#define INIT_EXTENDED_SFR() 
#endif

#endif // _UNISTC_MISC_H
