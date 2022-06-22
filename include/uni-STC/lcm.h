/**
 * @file uni-STC/lcm.h
 * 
 * Register, bit and macro definitions for the Liquid Crystal Module
 * (e.g. parallel interface TFT display) interface.
 */

#ifndef _UNISTC_LCM_H
#define _UNISTC_LCM_H

#ifdef MCU_HAS_LCM
	// SFR LCMIFCFG: LCM interface configuration register
	SFRX(LCMIFCFG, 0xFE50);
	
	#define M_M68_I80 0x1
	#define P_M68_I80 0
	
	#define M_D16_D8 0x2
	#define P_D16_D8 1
	
	#define M_LCMIFDPS 0x0c
	#define P_LCMIFDPS 2
	
	#define M_LCMIFIP 0x30
	#define P_LCMIFIP 4
	
	#define M_LCMIFIE 0x80
	#define P_LCMIFIE 7

	// SFR LCMIFCFG2: LCM interface configuration register 2
	SFRX(LCMIFCFG2, 0xFE51);
	
	#define M_HOLDT 0x03
	#define P_HOLDT 0
	
	#define M_SETUPT 0x1c
	#define P_SETUPT 2
	
	#define M_LCMIFCPS 0x60
	#define P_LCMIFCPS 5

	// SFR LCMIFCR: LCM interface control register
	SFRX(LCMIFCR, 0xFE52);
	
	#define M_LCMCMD 0x07
	#define P_LCMCMD 0
	
	#define M_ENLCMIF 0x80
	#define P_ENLCMIF 7

	// SFR LCMIFSTA: LCM interface status register
	SFRX(LCMIFSTA, 0xFE53);
	
	#define M_LCMIFIF 0x1
	#define P_LCMIFIF 0

	// SFR LCMIDDATL: LCM interface data low
	SFRX(LCMIDDATL, 0xFE54);

	// SFR LCMIDDATH: LCM interface data high
	SFRX(LCMIDDATH, 0xFE55);
	
	// LCD module interface interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define LCM_INTERRUPT 59
	#define LCM_VECTOR_ADDR 0x01DB
	
	// SFR DMA_LCM_CFG: LCD module DMA configuration register
	SFRX(DMA_LCM_CFG, 0xFA70);

	// SFR DMA_LCM_CR: LCD module DMA control register
	SFRX(DMA_LCM_CR, 0xFA71);
	
	#define M_TRIGRD 0x8
	#define P_TRIGRD 3
	
	#define M_TRIGRC 0x10
	#define P_TRIGRC 4
	
	#define M_TRIGWD 0x20
	#define P_TRIGWD 5
	
	#define M_TRIGWC 0x40
	#define P_TRIGWC 6

	// SFR DMA_LCM_STA: LCD module DMA status register
	SFRX(DMA_LCM_STA, 0xFA72);
	
	#define M_LCM_TXOVW 0x2
	#define P_LCM_TXOVW 1

	// SFR DMA_LCM_AMT: LCD module DMA total bytes to be transferred
	SFRX(DMA_LCM_AMT, 0xFA73);

	// SFR DMA_LCM_DONE: LCD module DMA transfer completed bytes
	SFRX(DMA_LCM_DONE, 0xFA74);

	// SFR DMA_LCM_TXAH: LCD module DMA send address high
	SFRX(DMA_LCM_TXAH, 0xFA75);
	// SFR DMA_LCM_TXAL: LCD module DMA send address low
	SFRX(DMA_LCM_TXAL, 0xFA76);

	// SFR DMA_LCM_RXAH: LCD module DMA receive address high
	SFRX(DMA_LCM_RXAH, 0xFA77);
	// SFR DMA_LCM_RXAL: LCD module DMA receive address low
	SFRX(DMA_LCM_RXAL, 0xFA78);
	
	// LCD module DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define DMA_LCM_INTERRUPT 58
	#define DMA_LCM_VECTOR_ADDR 0x01D3
#endif // MCU_HAS_LCM

#endif // _UNISTC_LCM_H
