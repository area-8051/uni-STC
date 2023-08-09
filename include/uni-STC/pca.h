/**
 * @file uni-STC/pca.h
 * 
 * Register, bit and mask definitions related to the PCA
 */

#ifndef _UNISTC_PCA_H
#define _UNISTC_PCA_H

/**
 * When using an STC15W10x/STC15W20xS/STC15W40xS:
 *     The PCA_CHANNELS macro must be set to 0.
 * 
 * When using an STC15W40xAS:
 *     The PCA_CHANNELS macro must be set to 3.
 * 
 * When using an STC8G1KxxA:
 *     The MCU_HAS_PCA macro must be defined.
 */

// On MCU without PCA whereas their family normally supports it,
// PCA_CHANNELS must be defined to 0.
#if !defined(PCA_CHANNELS) || PCA_CHANNELS > 0
	#if MCU_FAMILY == 12
		#define MCU_HAS_PCA
		#define PCA_CHANNELS 2
	#endif

	#if MCU_FAMILY == 15
		#define MCU_HAS_PCA
		#define PCA_HAS_67BIT_PWM
		
		#ifndef PCA_CHANNELS
			#define PCA_CHANNELS 2
		#endif // PCA_CHANNELS
	#endif

	#if MCU_FAMILY == 8 && MCU_SERIES != 'H'
		#if MCU_PINS > 8
			#define MCU_HAS_PCA
		#endif
		
		#define PCA_HAS_67BIT_PWM
		#define PCA_HAS_10BIT_PWM

		#if MCU_SERIES == 'A'
			#define PCA_CHANNELS 4

			#ifdef STC8A8KxxD4
				#define PCA_CHANNEL3_XSFR
			#endif // STC8A8KxxD4
		#endif // MCU_SERIES == 'A'

		#if MCU_SERIES == 'G'
			#define PCA_CHANNELS 3
		#endif // MCU_SERIES == 'G'
	#endif
#endif // !defined(PCA_CHANNELS) || PCA_CHANNELS > 0

#ifdef MCU_HAS_PCA
	// SFR CCON: PCA control register
	SFR(CCON, 0xD8);
	SBIT(CCIF0, 0xD8, 0);
	SBIT(CCIF1, 0xD8, 1);
	
	#if PCA_CHANNELS >= 3
		SBIT(CCIF2, 0xD8, 2);
	#endif // PCA_CHANNELS >= 3
	
	#if PCA_CHANNELS >= 4
		SBIT(CCIF3, 0xD8, 3);
	#endif // PCA_CHANNELS >= 4
	
	SBIT(CR, 0xD8, 6);
	SBIT(CF, 0xD8, 7);

	// SFR CMOD: PCA mode register
	SFR(CMOD, 0xD9);
	
	// Called ECF in the documentation, enables overflow interrupt
	#define M_CFIE 0x1
	#define P_CFIE 0
	
	#define M_CPS 0x0e
	#define P_CPS 1
	
	#define M_CIDL 0x80
	#define P_CIDL 7

	// SFR CCAPM0: PCA module 0 mode register
	SFR(CCAPM0, 0xDA);

	// Bit masks common to all PCA mode registers
	// Called ECCF in the documentation, enables PWM interrupt.
	#define M_CCIE 0x1
	#define P_CCIE 0
	
	#define M_PWM 0x2
	#define P_PWM 1
	
	#define M_TOG 0x4
	#define P_TOG 2
	
	#define M_MAT 0x8
	#define P_MAT 3
	
	#define M_CAPN 0x10
	#define P_CAPN 4
	
	#define M_CAPP 0x20
	#define P_CAPP 5
	
	// To manipulate both CAPN & CAPP in a single operation.
	#define M_CAP 0x30
	#define P_CAP 4
	
	// Called ECOM in the documentation, enables output compare.
	#define M_ENCOM 0x40
	#define P_ENCOM 6

	// SFR CCAPM1: PCA module 1 mode register
	SFR(CCAPM1, 0xDB);

	#if PCA_CHANNELS > 2
		// SFR CCAPM2: PCA module 2 mode register
		SFR(CCAPM2, 0xDC);
	#endif // PCA_CHANNELS > 2

	#if PCA_CHANNELS > 3
		// SFR CCAPM3: PCA module 3 mode register
		#ifdef PCA_CHANNEL3_XSFR
			SFRX(CCAPM3, 0xFD54);
		#else
			SFR(CCAPM3, 0xDD);
		#endif // PCA_CHANNEL3_XSFR
	#endif // PCA_CHANNELS > 3

	// SFR CL: PCA base timer low
	SFR(CL, 0xE9);

	// SFR CH: PCA base timer high
	SFR(CH, 0xF9);

	// PCA base timer as an int
	SFR16E(PCA_CTR, 0xF9E9);

	// SFR CCAP0L: PCA module 0 capture register low
	SFR(CCAP0L, 0xEA);

	// SFR CCAP1L: PCA module 1 capture register low
	SFR(CCAP1L, 0xEB);

	#if PCA_CHANNELS >= 3
		// SFR CCAP2L: PCA module 2 capture register low
		SFR(CCAP2L, 0xEC);
	#endif // PCA_CHANNELS >= 3

	#if PCA_CHANNELS >= 4
		// SFR CCAP3L: PCA module 3 capture register low
		#ifdef PCA_CHANNEL3_XSFR
			SFRX(CCAP3L, 0xFD55);
		#else
			SFR(CCAP3L, 0xED);
		#endif // PCA_CHANNEL3_XSFR
	#endif // PCA_CHANNELS >= 4

	// SFR CCAP0H: PCA module 0 capture register high
	SFR(CCAP0H, 0xFA);

	// SFR CCAP1H: PCA module 1 capture register high
	SFR(CCAP1H, 0xFB);

	#if PCA_CHANNELS >= 3
		// SFR CCAP2H: PCA module 2 capture register high
		SFR(CCAP2H, 0xFC);
	#endif // PCA_CHANNELS >= 3

	#if PCA_CHANNELS >= 4
		// SFR CCAP3H: PCA module 3 capture register high
		#ifdef PCA_CHANNEL3_XSFR
			SFRX(CCAP3H, 0xFD56);
		#else
			SFR(CCAP3H, 0xFD);
		#endif // PCA_CHANNEL3_XSFR
	#endif // PCA_CHANNELS >= 4

	// CCAP0 as an int
	SFR16E(CCAP0, 0xFAEA);
	// CCAP1 as an int
	SFR16E(CCAP1, 0xFBEB);

	#if PCA_CHANNELS >= 3
		// CCAP2 as an int
		SFR16E(CCAP2, 0xFCEC);
	#endif // PCA_CHANNELS >= 3

	#if PCA_CHANNELS >= 4
		// CCAP3 as an int
		#ifdef PCA_CHANNEL3_XSFR
			SFR16LEX(CCAP3, 0xFD55);
		#else
			SFR16E(CCAP3, 0xFDED);
		#endif // PCA_CHANNEL3_XSFR
	#endif // PCA_CHANNELS >= 4

	// SFR PCA_PWM0: PCA module 0 PWM mode register
	SFR(PCA_PWM0, 0xF2);

	// Bit masks common to all PWM mode registers
	#define M_EPCL 0x1
	#define P_EPCL 0
	
	#define M_EPCH 0x2
	#define P_EPCH 1

	// To manipulate both EPCL & EPCH in a single operation.
	#define M_EPC 0x3
	#define P_EPC 0
	
	#define M_XCCAPL 0x0c
	#define P_XCCAPL 2
	
	#define M_XCCAPH 0x30
	#define P_XCCAPH 4

	#define M_EBS 0xc0
	#define P_EBS 6

	// SFR PCA_PWM1: PCA module 1 PWM mode register
	SFR(PCA_PWM1, 0xF3);

	#if PCA_CHANNELS > 2
		// SFR PCA_PWM2: PCA module 2 PWM mode register
		SFR(PCA_PWM2, 0xF4);
	#endif // PCA_CHANNELS > 2

	#if PCA_CHANNELS > 3
		// SFR PCA_PWM3: PCA module 3 PWM mode register
		#ifdef PCA_CHANNEL3_XSFR
			SFRX(PCA_PWM3, 0xFD57);
		#else
			SFR(PCA_PWM3, 0xF5);
		#endif // PCA_CHANNEL3_XSFR
	#endif // PCA_CHANNELS > 3

	// Pin switch bit masks
	#ifdef PCA_HAS_67BIT_PWM
		// STC15 and above: for use with P_SW1
		#define M_CCP_S 0x30
		#define P_CCP_S 4
	#else
		// STC12 only: for use with AUXR1
		#define M_PCA_P4 0x40
		#define P_PCA_P4 6
	#endif // PCA_HAS_67BIT_PWM

	typedef enum {
		PCA_SYSCLK_DIV12 = 0,
		PCA_SYSCLK_DIV2 = 1,
		PCA_TIMER0 = 2,
		PCA_ECI = 3,
		PCA_SYSCLK = 4,
		PCA_SYSCLK_DIV4 = 5,
		PCA_SYSCLK_DIV6 = 6,
		PCA_SYSCLK_DIV8 = 7,
	} PCA_ClockSource;

	typedef enum {
		PCA_EDGE_RISING = 2,
		PCA_EDGE_FALLING = 1,
		PCA_EDGE_BOTH = 3,
		PCA_EDGE_NONE = 0,
	} PCA_EdgeTrigger;

	typedef enum {
		PCA_CHANNEL0 = 0,
		PCA_CHANNEL1 = 1,
	#if PCA_CHANNELS > 2
		PCA_CHANNEL2 = 2,
	#endif // PCA_CHANNELS > 2
	#if PCA_CHANNELS > 3
		PCA_CHANNEL3 = 3,
	#endif // PCA_CHANNELS > 3
	} PCA_Channel;

	typedef enum {
		PCA_FREE_RUNNING = 0,
		PCA_ECI_ENABLED = 1,
	} PCA_CounterMode;

	typedef enum {
		PCA_8BIT_PWM = 0,
	#ifdef PCA_HAS_67BIT_PWM
		PCA_7BIT_PWM = 1,
		PCA_6BIT_PWM = 2,
	#endif // PCA_HAS_67BIT_PWM
	#ifdef PCA_HAS_10BIT_PWM
		PCA_10BIT_PWM = 3,
	#endif // PCA_HAS_10BIT_PWM
	} PCA_PWM_Bits;

	// For use by MAKE_PCA_PWM_BITS(b) only.
	#define __MAKE_PCA_PWM_BITS(b) PCA_##b##BIT_PWM

	/**
	 * builds the name of the constant corresponding to the number of bits 
	 * given as argument. Mind it HAS to be valid, as no check is made.
	 * Supported values are [ 6, 7, 8, 10 ], but depend on the MCU family.
	 */
	#define MAKE_PCA_PWM_BITS(b) __MAKE_PCA_PWM_BITS(b)

	// PCA interrupt priority bit mask to use with IP1L and IP1H
	#define M_PCAPR 0x80
	#define P_PCAPR 7

	// PCA interrupt
	#define PCA_INTERRUPT 7
	#define PCA_VECTOR_ADDR 0x3B
#endif // MCU_HAS_PCA

#endif // _UNISTC_PCA_H
