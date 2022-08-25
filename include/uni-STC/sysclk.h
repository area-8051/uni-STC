/**
 * @file uni-STC/sysclk.h
 * 
 * Register, bit and macro definitions for system clocks.
 */

#ifndef _UNISTC_SYSCLK_H
#define _UNISTC_SYSCLK_H

#if MCU_FAMILY == 12
	// SFR CLKDIV: Clock divider
	SFR(CLKDIV, 0x97);
	
	#define M_CLKS 0x07
	#define P_CLKS 0
#endif // MCU_FAMILY == 12

#if MCU_FAMILY == 15
	#define MCU_HAS_IRCO
	#define IRCO_MAX_FREQ 35000000UL
	
	// SFR CLKDIV: Clock divider
	SFR(CLKDIV, 0x97);
	
	#define M_MCLKO_2 0x8
	#define P_MCLKO_2 3
	
	#define M_Tx_Rx 0x10
	#define P_Tx_Rx 4
	
	#define M_ADRJ 0x20
	#define P_ADRJ 5
	
	#define M_MCKO_S 0xC0
	#define P_MCKO_S 6
#endif // MCU_FAMILY == 15

#if MCU_FAMILY == 8
	#define MCU_HAS_IRCO
	
	#if MCU_SERIES == 'G'
		#define MCU_HAS_IRC_TRIM
		#define MCU_HAS_MCLKOCR
		// Theoretical max. is 42 MHz, but practical is 39 MHz and
		// recommended is 35 MHz
		#define IRCO_MAX_FREQ 39000000UL
		#define IRCO_REC_FREQ 35000000UL
	#elif MCU_SERIES == 'H'
		#define MCU_HAS_IRC_TRIM
		#define MCU_HAS_MCLKOCR
		
		// Theoretical max. is 47 MHz, but practical is 39 MHz and 
		// recommended is 35 MHz, except for STC8H8K64U (45 MHz)
		#ifdef MCU_HAS_USB
			#define IRCO_MAX_FREQ 45000000UL
		#else
			#define IRCO_MAX_FREQ 39000000UL
			#define IRCO_REC_FREQ 35000000UL
		#endif // MCU_HAS_USB
	#elif defined(STC8A8KxxD4)
		#define MCU_HAS_IRC_TRIM
		#define MCU_HAS_MCLKOCR
		// Theoretical max. is 55 MHz, but practical and
		// recommended are 45 MHz
		#define IRCO_MAX_FREQ 45000000UL
	#else
		// STC8A and STC8F but not STC8A8KxxD4
		#define IRCO_MAX_FREQ 24000000UL
	#endif
#endif // MCU_FAMILY == 8

#if defined(IRCO_MAX_FREQ) && !defined(IRCO_REC_FREQ)
	#define IRCO_REC_FREQ IRCO_MAX_FREQ
#endif // defined(IRCO_MAX_FREQ) && !defined(IRCO_REC_FREQ)

#ifdef MCU_HAS_IRC_TRIM
	// SFR IRCBAND: IRC band selection detection
	SFR(IRCBAND, 0x9D);
	
	// SFR LIRTRIM: IRC frequency trim register
	SFR(LIRTRIM, 0x9E);
	
	// SFR IRTRIM: IRC frequency adjustment register
	SFR(IRTRIM, 0x9F);

	#if MCU_SERIES == 'A'
		// This test is only true for STC8A8K64D4
		
		// For use with IRCBAND
		#define M_BANDSEL 0x03
		#define P_BANDSEL 0
		
		// For use with LIRTRIM
		#define M_LIRTRIM 0x01
		#define P_LIRTRIM 0
	#else
		// Remaining cases are STC8G and STC8H
		
		// For use with IRCBAND
		#define M_BANDSEL 0x01
		#define P_BANDSEL 0
		
		// For use with LIRTRIM
		#define M_LIRTRIM 0x03
		#define P_LIRTRIM 0
	#endif // MCU_SERIES == 'A'
#endif // MCU_HAS_IRC_TRIM

#if MCU_FAMILY == 8
	// SFR CLKDIV: Clock frequency division register
	SFRX(CLKDIV, 0xFE01);

	// SFR HIRCCR: Internal high-speed RC oscillator control register
	SFRX(HIRCCR, 0xFE02);
	
	#define M_HIRCST 0x1
	#define P_HIRCST 0
	
	#define M_ENHIRC 0x80
	#define P_ENHIRC 7

	// SFR XOSCCR: External oscillator control register
	SFRX(XOSCCR, 0xFE03);
	#define M_XOSCST 0x1
	#define P_XOSCST 0
	
	#define M_XITYPE 0x40
	#define P_XITYPE 6
	
	#define M_ENXOSC 0x80
	#define P_ENXOSC 7

	// SFR IRC32KCR: Internal 32kHz oscillator control register
	SFRX(IRC32KCR, 0xFE04);
	
	#define M_IRC32KST 0x1
	#define P_IRC32KST 0
	
	#define M_ENIRC32K 0x80
	#define P_ENIRC32K 7

	// SFR CKSEL: Clock selection register
	SFRX(CKSEL, 0xFE00);
	
	#define M_MCKSEL 0x03
	#define P_MCKSEL 0
	
	#ifdef MCU_HAS_MCLKOCR
		// SFR MCLKOCR: Main clock output control register
		SFRX(MCLKOCR, 0xFE05);
		
		#define M_MCLKODIV 0x7f
		#define P_MCLKODIV 0
		
		#define M_MCLKO_S 0x80
		#define P_MCLKO_S 7

		// SFR IRCDB: Internal high-speed oscillator debounce control
		SFRX(IRCDB, 0xFE06);
	#else
		// For use with CKSEL
		#define M_MCLKODIV 0xf0
		#define P_MCLKODIV 4
		
		#define M_MCLKO_S 0x08
		#define P_MCLKO_S 3
	#endif // MCU_HAS_MCLKOCR
	
	#if MCU_SERIES == 'H'
		// SFR IRC48MCR: Internal 48MHz RC oscillator control register
		SFRX(IRC48MCR, 0xFE07);
		#define M_IRC48MST 0x1
		#define P_IRC48MST 0
		
		#define M_ENIRC48M 0x80
		#define P_ENIRC48M 7
	#endif // MCU_SERIES == 'H'
#endif //MCU_FAMILY == 8

#endif // _UNISTC_SYSCLK_H
