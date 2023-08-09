/**
 * @file uni-STC/spi.h
 * 
 * Register, bit and macro definitions for SPI.
 */

#ifndef _UNISTC_SPI_H
#define _UNISTC_SPI_H

// Most STC MCU have an SPI peripheral, so not having one is an exception.
#ifndef MCU_HAS_NO_SPI
	// SFR SPSTAT: SPI status register
	SFR(SPSTAT, 0xCD);

	#define M_WCOL 0x40
	#define P_WCOL 6

	// Interrupt flag
	#define M_SPIIF 0x80
	#define P_SPIIF 7

	// SFR SPCTL: SPI control register
	SFR(SPCTL, 0xCE);

	#define M_SPR 0x03
	#define P_SPR 0

	#define M_CPHA 0x4
	#define P_CPHA 2

	#define M_CPOL 0x8
	#define P_CPOL 3

	#define M_MSTR 0x10
	#define P_MSTR 4

	#define M_DORD 0x20
	#define P_DORD 5

	// Enable SPI peripheral
	#define M_ENSPI 0x40
	#define P_ENSPI 6

	#define M_SSIG 0x80
	#define P_SSIG 7

	// SFR SPDAT: SPI data register
	SFR(SPDAT, 0xCF);

	// Bit mask for use with IE2
	#define M_SPIEN 0x02
	#define P_SPIEN 1

	// Bit mask for use with IP2L and IP2H
	#define M_SPIPR 0x02
	#define P_SPIPR 1

	// SPI interrupt
	#define SPI_INTERRUPT 9
	#define SPI_VECTOR_ADDR 0x4B

	#ifdef MCU_HAS_DMA
		// SFR DMA_SPI_CFG: SPI DMA configuration register
		SFRX(DMA_SPI_CFG, 0xFA20);
		
		#define M_ACT_RX 0x20
		#define P_ACT_RX 5
		
		#define M_ACT_TX 0x40
		#define P_ACT_TX 6

		// SFR DMA_SPI_CR: SPI DMA control register
		SFRX(DMA_SPI_CR, 0xFA21);
		
		#define M_CLRFIFO 0x1
		#define P_CLRFIFO 0
		
		#define M_TRIG_SLAVE 0x20
		#define P_TRIG_SLAVE 5
		
		#define M_TRIG_MASTER 0x40
		#define P_TRIG_MASTER 6

		// SFR DMA_SPI_STA: SPI DMA status register
		SFRX(DMA_SPI_STA, 0xFA22);
		
		#define M_SPI_RXLOSS 0x2
		#define P_SPI_RXLOSS 1
		
		#define M_SPI_TXOVW 0x4
		#define P_SPI_TXOVW 2

		// SFR DMA_SPI_AMT: SPI DMA total bytes to be transferred
		SFRX(DMA_SPI_AMT, 0xFA23);

		// SFR DMA_SPI_DONE: SPI DMA transfer completed bytes
		SFRX(DMA_SPI_DONE, 0xFA24);

		// SFR DMA_SPI_TXAH: SPI DMA send address high
		SFRX(DMA_SPI_TXAH, 0xFA25);
		// SFR DMA_SPI_TXAL: SPI DMA send address low
		SFRX(DMA_SPI_TXAL, 0xFA26);

		// SFR DMA_SPI_RXAH: SPI DMA receive address high
		SFRX(DMA_SPI_RXAH, 0xFA27);
		// SFR DMA_SPI_RXAL: SPI DMA receive address low
		SFRX(DMA_SPI_RXAL, 0xFA28);

		// SFR DMA_SPI_CFG2: SPI DMA configuration register 2
		SFRX(DMA_SPI_CFG2, 0xFA29);
		
		#define M_SS_S 0x03
		#define P_SS_S 0
		
		#define M_WRPSS 0x4
		#define P_WRPSS 2
		
		// SPI DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_SPI_INTERRUPT 49
		#define DMA_SPI_VECTOR_ADDR 0x018B
	#endif // MCU_HAS_DMA
#endif // MCU_HAS_NO_SPI

#endif // _UNISTC_SPI_H
