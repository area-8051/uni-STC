/**
 * @file uni-STC/adc.h
 * 
 * Register, bit and macro definitions for ADC.
 */

#ifndef _UNISTC_ADC_H
#define _UNISTC_ADC_H

#if defined(ADC_CHANNELS) && ADC_CHANNELS > 0
	#ifndef ADC_BITS
		#if MCU_FAMILY == 12
			#define ADC_BITS 10
		#endif // MCU_FAMILY == 12
		
		#if MCU_FAMILY == 15
			#define ADC_BITS 10
		#endif // MCU_FAMILY == 15
		
		#if MCU_FAMILY == 8
			#if MCU_SERIES == 'G'
				#define ADC_BITS 10
			#else
				#define ADC_BITS 12
			#endif // MCU_SERIES == 'G'
		#endif // MCU_FAMILY == 8
	#endif // ADC_BITS
	
	#ifndef ADC_MAX_SAMPLE_RATE
		#if MCU_FAMILY == 12
			#define ADC_MAX_SAMPLE_RATE 250000UL
		#endif // MCU_FAMILY == 12
		
		#if MCU_FAMILY == 15
			#define ADC_MAX_SAMPLE_RATE 300000UL
		#endif // MCU_FAMILY == 15
		
		#if MCU_FAMILY == 8
			#if ADC_BITS == 10
				#define ADC_MAX_SAMPLE_RATE 500000UL
			#else
				#define ADC_MAX_SAMPLE_RATE 800000UL
			#endif // ADC_BITS == 10
		#endif // MCU_FAMILY == 8
	#endif // ADC_MAX_SAMPLE_RATE
	
	// SFR ADC_CONTR: ADC control
	SFR(ADC_CONTR, 0xBC);
	
	#if MCU_FAMILY == 12 || MCU_FAMILY == 15
		#define M_ADC_CHS 0x07
		#define P_ADC_CHS 0
		
		#define M_ADC_START 0x08
		#define P_ADC_START 3
		
		// Called ADC_FLAG in the documentation, but must be
		// cleared by software, so calling it ADCIF acts as
		// a reminder of this necessity.
		#define M_ADCIF 0x10
		#define P_ADCIF 4
		
		#define M_ADC_SPEED 0x60
		#define P_ADC_SPEED 5
	#endif // MCU_FAMILY == 12 || MCU_FAMILY == 15
	
	#if MCU_FAMILY == 12
		// Bit mask for use with P_SW1
		#define M_RESFMT 0x4
		#define P_RESFMT 2
	#endif // MCU_FAMILY == 12
	
	#if MCU_FAMILY == 15
		// Bit mask for use with CLK_DIV
		#define M_RESFMT 0x20
		#define P_RESFMT 5
	#endif // MCU_FAMILY == 15
	
	#if MCU_FAMILY == 8
		#define M_ADC_CHS 0x0f
		#define P_ADC_CHS 0
		
		#if MCU_SERIES == 'G' || MCU_SERIES == 'H' || defined(STC8A8KxxD4)
			#define M_ADC_EPWMT 0x10
			#define P_ADC_EPWMT 4
		#endif // MCU_SERIES == 'G' || MCU_SERIES == 'H' || defined(STC8A8KxxD4)
		
		// Called ADC_FLAG in the documentation, but must be
		// cleared by software, so calling it ADCIF acts as
		// a reminder of this necessity.
		#define M_ADCIF 0x20
		#define P_ADCIF 5
		
		#define M_ADC_START 0x40
		#define P_ADC_START 6
	#endif // MCU_FAMILY == 8
	
	#define M_ADC_POWER 0x80
	#define P_ADC_POWER 7

	// SFR ADC_RES: ADC result high
	SFR(ADC_RESH, 0xBD);
	// SFR ADC_RESL: ADC result low
	SFR(ADC_RESL, 0xBE);
	SFR16E(ADC_RES, 0xBDBE);

	#if MCU_FAMILY == 8
		// SFR ADCCFG: ADC configuration register
		SFR(ADCCFG, 0xDE);
		
		#define M_ADC_SPEED 0x0f
		#define P_ADC_SPEED 0
		
		#define M_RESFMT 0x20
		#define P_RESFMT 5
		
		#if MCU_SERIES == 'G'
			#define MCU_HAS_ADCTIM
		#endif // MCU_SERIES == 'G'

		#if MCU_SERIES == 'H' || defined(STC8A8KxxD4)
			#define MCU_HAS_ADCTIM
			#define MCU_HAS_ADCEXCFG
		#endif // MCU_SERIES == 'H' || defined(STC8A8KxxD4)

		#ifdef MCU_HAS_ADCTIM
			// SFR ADCTIM: ADC timing control register
			SFRX(ADCTIM, 0xFEA8);
			
			#define M_SMPDUTY 0x1f
			#define P_SMPDUTY 0
			
			#define M_CSHOLD 0x60
			#define P_CSHOLD 5
			
			#define M_CSSETUP 0x80
			#define P_CSSETUP 7
		#endif // MCU_HAS_ADCTIM

		#ifdef MCU_HAS_ADCEXCFG
			// SFR ADCEXCFG: ADC extended configuration register
			SFRX(ADCEXCFG, 0xFEAD);
			
			#define M_ADCETRS 0x30
			#define P_ADCETRS 4
		#endif // MCU_HAS_ADCEXCFG
	#endif // MCU_FAMILY == 8

	// Bit mask for use with IE1
	#define M_ADCIE 0x20
	#define P_ADCIE 5

	// Bit mask for use with IP1L and IP1H
	#define M_ADCPR 0x20
	#define P_ADCPR 5

	// ADC interrupt
	#define ADC_INTERRUPT 5
	#define ADC_VECTOR_ADDR 0x002B

	#ifdef MCU_HAS_DMA
		// SFR DMA_ADC_CFG: ADC DMA configuration register
		SFRX(DMA_ADC_CFG, 0xFA10);

		// SFR DMA_ADC_CR: ADC DMA control register
		SFRX(DMA_ADC_CR, 0xFA11);

		// SFR DMA_ADC_STA: ADC DMA status register
		SFRX(DMA_ADC_STA, 0xFA12);

		// SFR DMA_ADC_AMT: ADC DMA total bytes to be transferred
		SFR(DMA_ADC_AMT, 0xFA);

		// SFR DMA_ADC_RXAH: ADC DMA receive address high
		SFRX(DMA_ADC_RXAH, 0xFA17);
		// SFR DMA_ADC_RXAL: ADC DMA receive address low
		SFRX(DMA_ADC_RXAL, 0xFA18);

		// SFR DMA_ADC_CFG2: ADC DMA configuration register 2
		SFRX(DMA_ADC_CFG2, 0xFA19);
		
		#define M_CVTIMESEL 0x0f
		#define P_CVTIMESEL 0

		// SFR DMA_ADC_CHSW0: ADC DMA channel enable 0
		SFRX(DMA_ADC_CHSW0, 0xFA1A);
		
		#define M_CH8 0x1
		#define P_CH8 0
		
		#define M_CH9 0x2
		#define P_CH9 1
		
		#define M_CH10 0x4
		#define P_CH10 2
		
		#define M_CH11 0x8
		#define P_CH11 3
		
		#define M_CH12 0x10
		#define P_CH12 4
		
		#define M_CH13 0x20
		#define P_CH13 5
		
		#define M_CH14 0x40
		#define P_CH14 6
		
		#define M_CH15 0x80
		#define P_CH15 7

		// SFR DMA_ADC_CHSW1: ADC DMA channel enable 0
		SFRX(DMA_ADC_CHSW1, 0xFA1B);
		
		#define M_CH0 0x1
		#define P_CH0 0
		
		#define M_CH1 0x2
		#define P_CH1 1
		
		#define M_CH2 0x4
		#define P_CH2 2
		
		#define M_CH3 0x8
		#define P_CH3 3
		
		#define M_CH4 0x10
		#define P_CH4 4
		
		#define M_CH5 0x20
		#define P_CH5 5
		
		#define M_CH6 0x40
		#define P_CH6 6
		
		#define M_CH7 0x80
		#define P_CH7 7
		
		// ADC DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_ADC_INTERRUPT 48
		#define DMA_ADC_VECTOR_ADDR 0x0183
	#endif // MCU_HAS_DMA
#endif // defined(ADC_CHANNELS) && ADC_CHANNELS > 0

#endif // _UNISTC_ADC_H
