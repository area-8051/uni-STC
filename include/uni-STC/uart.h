/**
 * @file uni-STC/uart.h
 * 
 * Register, bit and macro definitions for UART.
 */

#ifndef _UNISTC_UART_H
#define _UNISTC_UART_H

/**
 * When using an MCU with 4 serial ports:
 *     The NB_UARTS macro must be set to 4.
 * Otherwise, the number of UART will be given by the numer of pins.
 */

#ifndef NB_UARTS
	#if MCU_FAMILY == 12
		#define NB_UARTS 2
	#endif // MCU_FAMILY == 12

	#if MCU_FAMILY == 15
		#define NB_UARTS 1
	#endif // MCU_FAMILY == 15

	#if MCU_FAMILY == 8
		#if MCU_PINS > 8
			#define NB_UARTS 2
		#else
			#define NB_UARTS 1
		#endif // MCU_PINS > 8
	#endif // MCU_FAMILY == 8
#endif // !defined(NB_UARTS)

// SFR SADDR: Slave address
SFR(SADDR, 0xA9);
// SFR SADEN: Slave address mask
SFR(SADEN, 0xB9);

// SFR S1CON: UART1 control register
SFR(S1CON, 0x98);
SBIT(S1SM0_FE, 0x98, 7);

#define M_RI 0x1
#define P_RI 0

#define M_TI 0x2
#define P_TI 1

#define M_RB8 0x4
#define P_RB8 2

#define M_TB8 0x8
#define P_TB8 3

#define M_REN 0x10
#define P_REN 4

#define M_SM2 0x20
#define P_SM2 5

#define M_SM0 0x80
#define P_SM0 7

// Only for S1CON. UART1 is the only one with 4 modes of operation.
#define M_SM1 0x40
#define P_SM1 6
// Note: the bit at this position is not used in S2CON.
// In S3CON and S4CON, it becomes M_S3ST3 and M_S4ST4 respectively.

#if defined(TIMER_HAS_T2) || defined(TIMER_HAS_BRT)
	// Bit mask for use with AUXR
	
	// Defining these macros also for STC12 facilitates MCU-independent
	// coding (BRT is nothing more than an 8-bit timer 2, so all T2
	// macros apply, only the counter SFR differs.)
	#define M_S1ST2 0x01
	#define P_S1ST2 0
#endif // defined(TIMER_HAS_T2) || defined(TIMER_HAS_BRT)

#ifdef TIMER_HAS_BRT
	// Bit mask for use with AUXR
	#define M_S1BRS 0x1
	#define P_S1BRS 0
#endif // TIMER_HAS_BRT

// SFR S1BUF: UART1 data register
SFR(S1BUF, 0x99);

// Bit mask for use with AUXR
#define M_UART_M0x6 0x20
#define P_UART_M0x6 5

// Bit mask for use with PCON
#define M_SMOD0 0x40
#define P_SMOD0 6

#define M_SMOD 0x80
#define P_SMOD 7

// Bit mask for use with IE1
#define M_ES1 0x10
#define P_ES1 4

// Bit mask for use with IP1L and IP1H
#define M_PS1 0x10
#define P_PS1 4

// UART 1 interrupt
#define UART1_INTERRUPT 4
#define UART1_VECTOR_ADDR 0x23

#if NB_UARTS >= 2
	// SFR S2CON: UART2 control register
	SFR(S2CON, 0x9A);

	// SFR S2BUF: UART2 data register
	SFR(S2BUF, 0x9B);

	#ifdef TIMER_HAS_BRT
		// Bit mask for use with AUXR
		#define M_S2SMOD 0x8
		#define P_S2SMOD 3
	#endif // TIMER_HAS_BRT

	// Bit mask for use with IE2
	#define M_ES2 0x01
	#define P_ES2 0

	// Bit mask for use with IP2L and IP2H
	#define M_PS2 0x01
	#define P_PS2 0

	#if MCU_FAMILY == 15
		// For use with INT_CLKO
		#define M_MCKO_S2 0x8
		#define P_MCKO_S2 3
	#endif // MCU_FAMILY == 15

	// UART 2 interrupt
	#define UART2_INTERRUPT 8
	#define UART2_VECTOR_ADDR 0x43
#endif // NB_UARTS >= 2

#if NB_UARTS >= 3
	// SFR S3CON: UART3 control register
	SFR(S3CON, 0xAC);

	// Bit mask for use with S3CON
	#define M_S3ST3 0x01
	#define P_S3ST3 0

	// SFR S3BUF: UART3 data register
	SFR(S3BUF, 0xAD);

	// Bit mask for use with IE2
	#define M_ES3 0x08
	#define P_ES3 3
	
	#ifdef MCU_HAS_IP3
		// Bit mask for use with IP3L and IP3H
		#define M_PS3 0x01
		#define P_PS3 0
	#endif // MCU_HAS_IP3

	// UART 3 interrupt
	#define UART3_INTERRUPT 17
	#define UART3_VECTOR_ADDR 0x8B

	// SFR S4CON: UART4 control register
	SFR(S4CON, 0x84);

	// Bit mask for use with S4CON
	#define M_S4ST4 0x01
	#define P_S4ST4 0

	// SFR S4BUF: UART4 data register
	SFR(S4BUF, 0x85);

	// Bit mask for use with IE2
	#define M_ES4 0x10
	#define P_ES4 4
	
	#ifdef MCU_HAS_IP3
		// Bit mask for use with IP3L and IP3H
		#define M_PS4 0x02
		#define P_PS4 1
	#endif // MCU_HAS_IP3

	// UART 4 interrupt
	#define UART4_INTERRUPT 18
	#define UART4_VECTOR_ADDR 0x93
#endif // NB_UARTS >= 3

#ifdef MCU_HAS_DMA
	// SFR DMA_UR1T_CFG: UART1 Transmit DMA configuration register
	SFRX(DMA_UR1T_CFG, 0xFA30);

	// SFR DMA_UR1T_CR: UART1 Transmit DMA control register
	SFRX(DMA_UR1T_CR, 0xFA31);
	
	#define M_TRIG_TX 0x40
	#define P_TRIG_TX 6

	// SFR DMA_UR1T_STA: UART1 Transmit DMA status register
	SFRX(DMA_UR1T_STA, 0xFA32);

	// SFR DMA_UR1T_AMT: UART1 Transmit DMA total bytes to be transferred
	SFRX(DMA_URTX_AMT, 0xFA33);

	// SFR DMA_UR1T_DONE: UART1 Transmit DMA transfer completed bytes
	SFRX(DMA_UR1T_DONE, 0xFA34);

	// SFR DMA_UR1T_TXAH: UART1 Transmit DMA send address high
	SFRX(DMA_UR1T_TXAH, 0xFA35);
	// SFR DMA_UR1T_TXAL: UART1 Transmit DMA send address low
	SFRX(DMA_UR1T_TXAL, 0xFA36);

	// UART1 transmit DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define DMA_UR1T_INTERRUPT 50
	#define DMA_UR1T_VECTOR_ADDR 0x0193

	// SFR DMA_UR1R_CFG: UART1 Receive DMA configuration register
	SFRX(DMA_UR1R_CFG, 0xFA38);

	// SFR DMA_UR1R_CR: UART1 Receive DMA control register
	SFRX(DMA_UR1R_CR, 0xFA39);
	
	#define M_TRIG_RX 0x20
	#define P_TRIG_RX 5

	// SFR DMA_UR1R_STA: UART1 Receive DMA status register
	SFRX(DMA_UR1R_STA, 0xFA3A);

	// SFR DMA_UR1R_AMT: UART1 Receive DMA total bytes to be transferred
	SFRX(DMA_UR1R_AMT, 0xFA3B);

	// SFR DMA_UR1R_DONE: UART1 Receive DMA transfer completed bytes
	SFRX(DMA_UR1R_DONE, 0xFA3C);

	// SFR DMA_UR1R_TXAH: UART1 Receive DMA send address high
	SFRX(DMA_UR1R_TXAH, 0xFA3D);
	// SFR DMA_UR1R_TXAL: UART1 Receive DMA send address low
	SFRX(DMA_UR1R_TXAL, 0xFA3E);
	
	// UART1 receive DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
	#define DMA_UR1R_INTERRUPT 51
	#define DMA_UR1R_VECTOR_ADDR 0x019B

	#if NB_UARTS >= 2
		// SFR DMA_UR2T_CFG: UART2 Transmit DMA configuration register
		SFRX(DMA_UR2T_CFG, 0xFA30);

		// SFR DMA_UR2T_CR: UART2 Transmit DMA control register
		SFRX(DMA_UR2T_CR, 0xFA31);

		// SFR DMA_UR2T_STA: UART2 Transmit DMA status register
		SFRX(DMA_UR2T_STA, 0xFA32);

		// SFR DMA_UR2T_AMT: UART2 Transmit DMA total bytes to be transferred
		SFRX(DMA_UR2T_AMT, 0xFA33);

		// SFR DMA_UR2T_DONE: UART2 Transmit DMA transfer completed bytes
		SFRX(DMA_UR2T_DONE, 0xFA34);

		// SFR DMA_UR2T_TXAH: UART2 Transmit DMA send address high
		SFRX(DMA_UR2T_TXAH, 0xFA35);
		// SFR DMA_UR2T_TXAL: UART2 Transmit DMA send address low
		SFRX(DMA_UR2T_TXAL, 0xFA36);

		// UART2 transmit DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_UR2T_INTERRUPT 52
		#define DMA_UR2T_VECTOR_ADDR 0x01A3

		// SFR DMA_UR2R_CFG: UART2 Receive DMA configuration register
		SFRX(DMA_UR2R_CFG, 0xFA38);

		// SFR DMA_UR2R_CR: UART2 Receive DMA control register
		SFRX(DMA_UR2R_CR, 0xFA39);

		// SFR DMA_UR2R_STA: UART2 Receive DMA status register
		SFRX(DMA_UR2R_STA, 0xFA3A);

		// SFR DMA_UR2R_AMT: UART2 Receive DMA total bytes to be transferred
		SFRX(DMA_UR2R_AMT, 0xFA3B);

		// SFR DMA_UR2R_DONE: UART2 Receive DMA transfer completed bytes
		SFRX(DMA_UR2R_DONE, 0xFA3C);

		// SFR DMA_UR2R_TXAH: UART2 Receive DMA send address high
		SFRX(DMA_UR2R_TXAH, 0xFA3D);
		// SFR DMA_UR2R_TXAL: UART2 Receive DMA send address low
		SFRX(DMA_UR2R_TXAL, 0xFA3E);
		
		// UART2 receive DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_UR2R_INTERRUPT 53
		#define DMA_UR2R_VECTOR_ADDR 0x01AB
	#endif // NB_UARTS >= 2

	#if NB_UARTS >= 3
		// SFR DMA_UR3T_CFG: UART3 Transmit DMA configuration register
		SFRX(DMA_UR3T_CFG, 0xFA30);

		// SFR DMA_UR3T_CR: UART3 Transmit DMA control register
		SFRX(DMA_UR3T_CR, 0xFA31);

		// SFR DMA_UR3T_STA: UART3 Transmit DMA status register
		SFRX(DMA_UR3T_STA, 0xFA32);

		// SFR DMA_UR3T_AMT: UART3 Transmit DMA total bytes to be transferred
		SFRX(DMA_UR3T_AMT, 0xFA33);

		// SFR DMA_UR3T_DONE: UART3 Transmit DMA transfer completed bytes
		SFRX(DMA_UR3T_DONE, 0xFA34);

		// SFR DMA_UR3T_TXAH: UART3 Transmit DMA send address high
		SFRX(DMA_UR3T_TXAH, 0xFA35);
		// SFR DMA_UR3T_TXAL: UART3 Transmit DMA send address low
		SFRX(DMA_UR3T_TXAL, 0xFA36);

		// UART3 transmit DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_UR3T_INTERRUPT 54
		#define DMA_UR3T_VECTOR_ADDR 0x01B3

		// SFR DMA_UR3R_CFG: UART3 Receive DMA configuration register
		SFRX(DMA_UR3R_CFG, 0xFA38);

		// SFR DMA_UR3R_CR: UART3 Receive DMA control register
		SFRX(DMA_UR3R_CR, 0xFA39);

		// SFR DMA_UR3R_STA: UART3 Receive DMA status register
		SFRX(DMA_UR3R_STA, 0xFA3A);

		// SFR DMA_UR3R_AMT: UART3 Receive DMA total bytes to be transferred
		SFRX(DMA_UR3R_AMT, 0xFA3B);

		// SFR DMA_UR3R_DONE: UART3 Receive DMA transfer completed bytes
		SFRX(DMA_UR3R_DONE, 0xFA3C);

		// SFR DMA_UR3R_TXAH: UART3 Receive DMA send address high
		SFRX(DMA_UR3R_TXAH, 0xFA3D);
		// SFR DMA_UR3R_TXAL: UART3 Receive DMA send address low
		SFRX(DMA_UR3R_TXAL, 0xFA3E);
		
		// UART3 receive DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_UR3R_INTERRUPT 55
		#define DMA_UR3R_VECTOR_ADDR 0x01BB

		// SFR DMA_UR4T_CFG: UART4 Transmit DMA configuration register
		SFRX(DMA_UR4T_CFG, 0xFA30);

		// SFR DMA_UR4T_CR: UART4 Transmit DMA control register
		SFRX(DMA_UR4T_CR, 0xFA31);

		// SFR DMA_UR4T_STA: UART4 Transmit DMA status register
		SFRX(DMA_UR4T_STA, 0xFA32);

		// SFR DMA_UR4T_AMT: UART4 Transmit DMA total bytes to be transferred
		SFRX(DMA_UR4T_AMT, 0xFA33);

		// SFR DMA_UR4T_DONE: UART4 Transmit DMA transfer completed bytes
		SFRX(DMA_UR4T_DONE, 0xFA34);

		// SFR DMA_UR4T_TXAH: UART4 Transmit DMA send address high
		SFRX(DMA_UR4T_TXAH, 0xFA35);
		// SFR DMA_UR4T_TXAL: UART4 Transmit DMA send address low
		SFRX(DMA_UR4T_TXAL, 0xFA36);

		// UART4 transmit DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_UR4T_INTERRUPT 56
		#define DMA_UR4T_VECTOR_ADDR 0x01C3

		// SFR DMA_UR4R_CFG: UART4 Receive DMA configuration register
		SFRX(DMA_UR4R_CFG, 0xFA38);

		// SFR DMA_UR4R_CR: UART4 Receive DMA control register
		SFRX(DMA_UR4R_CR, 0xFA39);

		// SFR DMA_UR4R_STA: UART4 Receive DMA status register
		SFRX(DMA_UR4R_STA, 0xFA3A);

		// SFR DMA_UR4R_AMT: UART4 Receive DMA total bytes to be transferred
		SFRX(DMA_UR4R_AMT, 0xFA3B);

		// SFR DMA_UR4R_DONE: UART4 Receive DMA transfer completed bytes
		SFRX(DMA_UR4R_DONE, 0xFA3C);

		// SFR DMA_UR4R_TXAH: UART4 Receive DMA send address high
		SFRX(DMA_UR4R_TXAH, 0xFA3D);
		// SFR DMA_UR4R_TXAL: UART4 Receive DMA send address low
		SFRX(DMA_UR4R_TXAL, 0xFA3E);
		
		// UART4 receive DMA interrupt (usage in C => see STC8H TRM appendix R or STC8A8K64D4 TRM appendix P)
		#define DMA_UR4R_INTERRUPT 57
		#define DMA_UR4R_VECTOR_ADDR 0x01CB
	#endif // NB_UARTS >= 3
#endif // MCU_HAS_DMA

typedef enum {
	UART1 = 1,
#if NB_UARTS >= 2
	UART2 = 2,
#endif // NB_UARTS >= 2
#if NB_UARTS >= 3
	UART3,
	UART4,
#endif // NB_UARTS >= 3
} Uart;

#endif // _UNISTC_UART_H
