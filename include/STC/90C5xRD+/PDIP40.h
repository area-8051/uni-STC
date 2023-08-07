/*
 * Copyright (c) 2022 Vincent DEFERT. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright 
 * notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN 
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file STC/90C5xRD/PDIP40.h
 * 
 * Register, bit and macro definitions for the STC90
 */

#ifndef _STC90C5xRD_PDIP40_H
#define _STC90C5xRD_PDIP40_H

#include <compiler.h>

#define MCU_FAMILY 90
#define MCU_SERIES 'C'
#define MCU_PINS 40

#define MCU_CYCLES 12

// SFR P0: Port 0
SFR(P0, 0x80);
SBIT(P0_0, 0x80, 0);
SBIT(P0_1, 0x80, 1);
SBIT(P0_2, 0x80, 2);
SBIT(P0_3, 0x80, 3);
SBIT(P0_4, 0x80, 4);
SBIT(P0_5, 0x80, 5);
SBIT(P0_6, 0x80, 6);
SBIT(P0_7, 0x80, 7);

// SFR SP: Stack Pointer
SFR(SP, 0x81);

// SFR DPL: Data Pointer (DPTR) low
SFR(DPL, 0x82);
// SFR DPH: Data Pointer (DPTR) high
SFR(DPH, 0x83);

// SFR PCON: Power control
SFR(PCON, 0x87);
#define M_IDL 0x1
#define M_PD 0x2
#define M_GF0 0x4
#define M_GF1 0x8
#define M_POF 0x10
#define M_SMOD0 0x40
#define M_SMOD 0x80

// SFR TCON: Timer control
SFR(TCON, 0x88);
SBIT(IT0, 0x88, 0);
SBIT(INT0IF, 0x88, 1);
SBIT(IT1, 0x88, 2);
SBIT(INT1IF, 0x88, 3);
SBIT(TR0, 0x88, 4);
SBIT(TF0, 0x88, 5);
SBIT(TR1, 0x88, 6);
SBIT(TF1, 0x88, 7);

// SFR TMOD: Timer mode
SFR(TMOD, 0x89);
#define M_T0_M0 0x1
#define M_T0_M1 0x2
#define M_T0_C_T 0x4
#define M_T0_GATE 0x8
#define M_T1_M0 0x10
#define M_T1_M1 0x20
#define M_T1_C_T 0x40
#define M_T1_GATE 0x80

// SFR TL0: Timer 0 low
SFR(TL0, 0x8A);
// SFR TH0: Timer 0 high
SFR(TH0, 0x8C);

// SFR TL1: Timer 1 low
SFR(TL1, 0x8B);
// SFR TH1: Timer 1 high
SFR(TH1, 0x8D);

// SFR AUXR: Auxiliary register
SFR(AUXR, 0x8E);
#define M_ALEOFF 0x1
#define M_EXTRAM 0x2

// SFR P1: Port 1
SFR(P1, 0x90);
SBIT(P1_0, 0x90, 0);
SBIT(P1_1, 0x90, 1);
SBIT(P1_2, 0x90, 2);
SBIT(P1_3, 0x90, 3);
SBIT(P1_4, 0x90, 4);
SBIT(P1_5, 0x90, 5);
SBIT(P1_6, 0x90, 6);
SBIT(P1_7, 0x90, 7);

// SFR SCON: Serial control
SFR(SCON, 0x98);
SBIT(RI, 0x98, 0);
SBIT(TI, 0x98, 1);
SBIT(RB8, 0x98, 2);
SBIT(TB8, 0x98, 3);
SBIT(REN, 0x98, 4);
SBIT(SM2, 0x98, 5);
SBIT(SM1, 0x98, 6);
SBIT(SM0_FE, 0x98, 7);

// SFR SBUF: Serial buffer
SFR(SBUF, 0x99);

// SFR P2: Port 2
SFR(P2, 0xA0);
SBIT(P2_0, 0xA0, 0);
SBIT(P2_1, 0xA0, 1);
SBIT(P2_2, 0xA0, 2);
SBIT(P2_3, 0xA0, 3);
SBIT(P2_4, 0xA0, 4);
SBIT(P2_5, 0xA0, 5);
SBIT(P2_6, 0xA0, 6);
SBIT(P2_7, 0xA0, 7);

// SFR AUXR1: Auxiliary register 1
SFR(AUXR1, 0xA2);
#define M_DPSEL 0x1
#define M_GF2 0x8

// SFR DPS: Alias of AUXR1 used by SDCC
SFR(DPS, 0xA2);

// SFR IE1: Interrupt enable 1
SFR(IE1, 0xA8);
SBIT(EX0, 0xA8, 0);
SBIT(ET0, 0xA8, 1);
SBIT(EX1, 0xA8, 2);
SBIT(ET1, 0xA8, 3);
SBIT(ES, 0xA8, 4);
SBIT(ET2, 0xA8, 5);
SBIT(EA, 0xA8, 7);

// SFR SADDR: Slave address
SFR(SADDR, 0xA9);

// SFR P3: Port 3
SFR(P3, 0xB0);
SBIT(P3_0, 0xB0, 0);
SBIT(P3_1, 0xB0, 1);
SBIT(P3_2, 0xB0, 2);
SBIT(P3_3, 0xB0, 3);
SBIT(P3_4, 0xB0, 4);
SBIT(P3_5, 0xB0, 5);
SBIT(P3_6, 0xB0, 6);
SBIT(P3_7, 0xB0, 7);

// SFR IP1H: Interrupt priority register high
SFR(IP1H, 0xB7);
#define M_PX0 0x1
#define M_PT0 0x2
#define M_PX1 0x4
#define M_PT1 0x8
#define M_PS1 0x10
#define M_PT2 0x20
#define M_PX2 0x40
#define M_PX3 0x80

// SFR IP1L: Interrupt priority register low
SFR(IP1L, 0xB8);

// SFR SADEN: Slave address mask
SFR(SADEN, 0xB9);

// SFR XICON: Auxiliary interrupt control
SFR(XICON, 0xC0);
SBIT(IT2, 0xC0, 0);
SBIT(IE2, 0xC0, 1);
SBIT(EX2, 0xC0, 2);
SBIT(PX2, 0xC0, 3);
SBIT(IT3, 0xC0, 4);
SBIT(IE3, 0xC0, 5);
SBIT(EX3, 0xC0, 6);
SBIT(PX3, 0xC0, 7);

// SFR T2CON: Timer/counter 2 control
SFR(T2CON, 0xC8);
SBIT(CP_RL2, 0xC8, 0);
SBIT(C_T2, 0xC8, 1);
SBIT(TR2, 0xC8, 2);
SBIT(EXEN2, 0xC8, 3);
SBIT(TCLK, 0xC8, 4);
SBIT(RCLK, 0xC8, 5);
SBIT(EXF2, 0xC8, 6);
SBIT(TF2, 0xC8, 7);

// SFR T2MOD: Timer/counter 2 mode
SFR(T2MOD, 0xC9);
#define M_DCEN 0x1
#define M_T2OE 0x2

// SFR RCAP2L: Timer/counter 2 reload/capture low
SFR(RCAP2L, 0xCA);
// SFR RCAP2H: Timer/counter 2 reload/capture high
SFR(RCAP2H, 0xCB);

// SFR TL2: Timer/counter 2 low
SFR(TL2, 0xCC);
// SFR TH2: Timer/counter 2 high
SFR(TH2, 0xCD);

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

// SFR ACC: Accumulator
SFR(ACC, 0xE0);

// SFR WDT_CONR: Watchdog timer control register
SFR(WDT_CONR, 0xE1);
#define M_PS 0x07
#define M_IDLE_WDT 0x8
#define M_CLR_WDT 0x10
#define M_EN_WDT 0x20

// SFR ISP_DATA: 
SFR(ISP_DATA, 0xE2);

// SFR ISP_ADDRH: 
SFR(ISP_ADDRH, 0xE3);
// SFR ISP_ADDRL: 
SFR(ISP_ADDRL, 0xE4);

// SFR ISP_CMD: 
SFR(ISP_CMD, 0xE5);
#define M_MS 0x07

// SFR ISP_TRIG: 
SFR(ISP_TRIG, 0xE6);

// SFR ISP_CONTR: 
SFR(ISP_CONTR, 0xE7);
#define M_WT 0x07
#define M_SWRST 0x20
#define M_SWBS 0x40
#define M_ISPEN 0x80

// SFR P4: Port 4
SFR(P4, 0xE8);
SBIT(P4_0, 0xE8, 0);
SBIT(P4_1, 0xE8, 1);
SBIT(P4_2, 0xE8, 2);
SBIT(P4_3, 0xE8, 3);

// SFR B: B register
SFR(B, 0xF0);
// External interrupt 0
#define EXTINT0_INTERRUPT 0
#define EXTINT0_VECTOR_ADDR 0x03
// Timer 0 interrupt
#define TIMER0_INTERRUPT 1
#define TIMER0_VECTOR_ADDR 0x0B
// External interrupt 1
#define EXTINT1_INTERRUPT 2
#define EXTINT1_VECTOR_ADDR 0x13
// Timer 1 interrupt
#define TIMER1_INTERRUPT 3
#define TIMER1_VECTOR_ADDR 0x1B
// UART 1 interrupt
#define UART1_INTERRUPT 4
#define UART1_VECTOR_ADDR 0x23
// Timer 2 interrupt
#define TIMER2_INTERRUPT 5
#define TIMER2_VECTOR_ADDR 0x2B
// External interrupt 2 (falling edge only)
#define EXTINT2_INTERRUPT 6
#define EXTINT2_VECTOR_ADDR 0x33
// External interrupt 3 (falling edge only)
#define EXTINT3_INTERRUPT 7
#define EXTINT3_VECTOR_ADDR 0x3B

#endif // _STC90C5xRD_PDIP40_H
