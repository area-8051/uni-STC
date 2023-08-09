/**
 * @file uni-STC/dma.h
 * 
 * Register, bit and macro definitions for memory-to-memory DMA.
 */

#ifndef _UNISTC_DMA_H
#define _UNISTC_DMA_H

#ifdef MCU_HAS_DMA
	// For use with all DMA_XXX_CFG
	#define M_DMA_BUS_PRIORITY 0x03
	#define P_DMA_BUS_PRIORITY 0
	
	// Interrupt priority
	#define M_DMAPR 0x0c
	#define P_DMAPR 2
	
	// Interrupt enable
	#define M_DMAIE 0x80
	#define P_DMAIE 7
	
	// For use with all DMA_XXX_CR
	#define M_DMA_CHANNEL_ENABLE 0x80
	#define P_DMA_CHANNEL_ENABLE 7
	
	// For use with all DMA_XXX_STA
	// Interrupt flag
	#define M_DMAIF 0x1
	#define P_DMAIF 0
	
	
	// SFR DMA_M2M_CFG: Memory-to-memory DMA configuration register
	SFRX(DMA_M2M_CFG, 0xFA00);
	
	#define M_RXACO 0x10
	#define P_RXACO 4
	
	#define M_TXACO 0x20
	#define P_TXACO 5

	// SFR DMA_M2M_CR: Memory-to-memory DMA control register
	SFRX(DMA_M2M_CR, 0xFA01);
	
	#define M_TRIG 0x40
	#define P_TRIG 6

	// SFR DMA_M2M_STA: Memory-to-memory DMA status register
	SFRX(DMA_M2M_STA, 0xFA02);

	// SFR DMA_M2M_AMT: Memory-to-memory DMA total bytes to be transferred
	SFRX(DMA_M2M_AMT, 0xFA03);

	// SFR DMA_M2M_DONE: Memory-to-memory DMA transfer completed bytes
	SFRX(DMA_M2M_DONE, 0xFA04);

	// SFR DMA_M2M_TXAH: Memory-to-memory DMA send address high
	SFRX(DMA_M2M_TXAH, 0xFA05);
	// SFR DMA_M2M_TXAL: Memory-to-memory DMA send address low
	SFRX(DMA_M2M_TXAL, 0xFA06);

	// SFR DMA_M2M_RXAH: Memory-to-memory DMA receive address high
	SFRX(DMA_M2M_RXAH, 0xFA07);
	// SFR DMA_M2M_RXAL: Memory-to-memory DMA receive address low
	SFRX(DMA_M2M_RXAL, 0xFA08);
	
	// Memory-to-memory DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define DMA_M2M_INTERRUPT 47
	#define DMA_M2M_VECTOR_ADDR 0x017B
#endif // MCU_HAS_DMA

#endif // _UNISTC_DMA_H
