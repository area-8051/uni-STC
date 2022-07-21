;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module delay
	.optsdcc -mmcs51 --model-medium
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _S1SM0_FE
	.globl _T1IF
	.globl _T1R
	.globl _T0IF
	.globl _T0R
	.globl _CF
	.globl _CR
	.globl _CCF1
	.globl _CCF0
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _EA
	.globl _INT1IF
	.globl _IT1
	.globl _INT0IF
	.globl _IT0
	.globl _P5_5
	.globl _P5_4
	.globl _P5_3
	.globl _P5_2
	.globl _P5_1
	.globl _P5_0
	.globl _P4_7
	.globl _P4_6
	.globl _P4_5
	.globl _P4_4
	.globl _P4_3
	.globl _P4_2
	.globl _P4_1
	.globl _P4_0
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _S2BUF
	.globl _S2CON
	.globl _S1BUF
	.globl _S1CON
	.globl _SADEN
	.globl _SADDR
	.globl _WDT_CONTR
	.globl _AUXR
	.globl _BRT
	.globl _T1
	.globl _T1H
	.globl _T1L
	.globl _T0
	.globl _T0H
	.globl _T0L
	.globl _TMOD
	.globl _TCON
	.globl _CLKDIV
	.globl _SPDAT
	.globl _SPCTL
	.globl _SPSTAT
	.globl _PCA_PWM1
	.globl _PCA_PWM0
	.globl _CCAP1
	.globl _CCAP0
	.globl _CCAP1H
	.globl _CCAP0H
	.globl _CCAP1L
	.globl _CCAP0L
	.globl _PCA_CTR
	.globl _CH
	.globl _CL
	.globl _CCAPM1
	.globl _CCAPM0
	.globl _CMOD
	.globl _CCON
	.globl _BUS_SPEED
	.globl _P4SW
	.globl _P1ASF
	.globl _P_SW1
	.globl _WAKE_CLKO
	.globl _PCON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _SP
	.globl _IP2H
	.globl _IP2L
	.globl _IP1H
	.globl _IP1L
	.globl _IE2
	.globl _IE1
	.globl _IAP_CONTR
	.globl _IAP_TRIG
	.globl _IAP_CMD
	.globl _IAP_ADDR
	.globl _IAP_ADDRL
	.globl _IAP_ADDRH
	.globl _IAP_DATA
	.globl _P5M0
	.globl _P5M1
	.globl _P5
	.globl _P4M0
	.globl _P4M1
	.globl _P4
	.globl _P3M0
	.globl _P3M1
	.globl _P3
	.globl _P2M0
	.globl _P2M1
	.globl _P2
	.globl _P1M0
	.globl _P1M1
	.globl _P1
	.globl _P0M0
	.globl _P0M1
	.globl _P0
	.globl _DPS
	.globl _DP
	.globl _DPH
	.globl _DPL
	.globl _ADC_RESL
	.globl _ADC_RESH
	.globl _ADC_CONTR
	.globl _delay1ms
	.globl _delay10us
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_ADC_CONTR	=	0x00bc
_ADC_RESH	=	0x00bd
_ADC_RESL	=	0x00be
_DPL	=	0x0082
_DPH	=	0x0083
_DP	=	0x8382
_DPS	=	0x00a2
_P0	=	0x0080
_P0M1	=	0x0093
_P0M0	=	0x0094
_P1	=	0x0090
_P1M1	=	0x0091
_P1M0	=	0x0092
_P2	=	0x00a0
_P2M1	=	0x0095
_P2M0	=	0x0096
_P3	=	0x00b0
_P3M1	=	0x00b1
_P3M0	=	0x00b2
_P4	=	0x00c0
_P4M1	=	0x00b3
_P4M0	=	0x00b4
_P5	=	0x00c8
_P5M1	=	0x00c9
_P5M0	=	0x00ca
_IAP_DATA	=	0x00c2
_IAP_ADDRH	=	0x00c3
_IAP_ADDRL	=	0x00c4
_IAP_ADDR	=	0xc3c4
_IAP_CMD	=	0x00c5
_IAP_TRIG	=	0x00c6
_IAP_CONTR	=	0x00c7
_IE1	=	0x00a8
_IE2	=	0x00af
_IP1L	=	0x00b8
_IP1H	=	0x00b7
_IP2L	=	0x00b5
_IP2H	=	0x00b6
_SP	=	0x0081
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_PCON	=	0x0087
_WAKE_CLKO	=	0x008f
_P_SW1	=	0x00a2
_P1ASF	=	0x009d
_P4SW	=	0x00bb
_BUS_SPEED	=	0x00a1
_CCON	=	0x00d8
_CMOD	=	0x00d9
_CCAPM0	=	0x00da
_CCAPM1	=	0x00db
_CL	=	0x00e9
_CH	=	0x00f9
_PCA_CTR	=	0xf9e9
_CCAP0L	=	0x00ea
_CCAP1L	=	0x00eb
_CCAP0H	=	0x00fa
_CCAP1H	=	0x00fb
_CCAP0	=	0xfaea
_CCAP1	=	0xfbeb
_PCA_PWM0	=	0x00f2
_PCA_PWM1	=	0x00f3
_SPSTAT	=	0x00cd
_SPCTL	=	0x00ce
_SPDAT	=	0x00cf
_CLKDIV	=	0x0097
_TCON	=	0x0088
_TMOD	=	0x0089
_T0L	=	0x008a
_T0H	=	0x008c
_T0	=	0x8c8a
_T1L	=	0x008b
_T1H	=	0x008d
_T1	=	0x8d8b
_BRT	=	0x009c
_AUXR	=	0x008e
_WDT_CONTR	=	0x00c1
_SADDR	=	0x00a9
_SADEN	=	0x00b9
_S1CON	=	0x0098
_S1BUF	=	0x0099
_S2CON	=	0x009a
_S2BUF	=	0x009b
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_P4_0	=	0x00c0
_P4_1	=	0x00c1
_P4_2	=	0x00c2
_P4_3	=	0x00c3
_P4_4	=	0x00c4
_P4_5	=	0x00c5
_P4_6	=	0x00c6
_P4_7	=	0x00c7
_P5_0	=	0x00c8
_P5_1	=	0x00c9
_P5_2	=	0x00ca
_P5_3	=	0x00cb
_P5_4	=	0x00cc
_P5_5	=	0x00cd
_IT0	=	0x0088
_INT0IF	=	0x0089
_IT1	=	0x008a
_INT1IF	=	0x008b
_EA	=	0x00af
_P	=	0x00d0
_F1	=	0x00d1
_OV	=	0x00d2
_RS0	=	0x00d3
_RS1	=	0x00d4
_F0	=	0x00d5
_AC	=	0x00d6
_CY	=	0x00d7
_CCF0	=	0x00d8
_CCF1	=	0x00d9
_CR	=	0x00de
_CF	=	0x00df
_T0R	=	0x008c
_T0IF	=	0x008d
_T1R	=	0x008e
_T1IF	=	0x008f
_S1SM0_FE	=	0x009f
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'delay1ms'
;------------------------------------------------------------
;	delay.c:158: void delay1ms(uint16_t ms) {
;	-----------------------------------------
;	 function delay1ms
;	-----------------------------------------
_delay1ms:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6,dpl
	mov	r7,dph
;	delay.c:159: for (uint16_t i = ms; i; i--) {
00107$:
	mov	a,r6
	orl	a,r7
	jz	00109$
;	delay.c:160: for (uint16_t n = DELAY_1ms; n; n--) {
	mov	r4,#0x64
	mov	r5,#0x02
00104$:
	mov	a,r4
	orl	a,r5
	jz	00108$
;	delay.c:161: NOP();
	NOP	
;	delay.c:162: NOP();
	NOP	
;	delay.c:163: NOP();
	NOP	
;	delay.c:160: for (uint16_t n = DELAY_1ms; n; n--) {
	dec	r4
	cjne	r4,#0xff,00131$
	dec	r5
00131$:
	sjmp	00104$
00108$:
;	delay.c:159: for (uint16_t i = ms; i; i--) {
	dec	r6
	cjne	r6,#0xff,00132$
	dec	r7
00132$:
	sjmp	00107$
00109$:
;	delay.c:166: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'delay10us'
;------------------------------------------------------------
;	delay.c:167: void delay10us(uint8_t us) {
;	-----------------------------------------
;	 function delay10us
;	-----------------------------------------
_delay10us:
	mov	r7,dpl
;	delay.c:168: for (uint8_t i = us; i; i--) {
00107$:
	mov	a,r7
	jz	00109$
;	delay.c:169: for (uint8_t n = DELAY_10us; n; n--) {
	mov	r6,#0x08
00104$:
	mov	a,r6
	jz	00108$
	dec	r6
	sjmp	00104$
00108$:
;	delay.c:168: for (uint8_t i = us; i; i--) {
	dec	r7
	sjmp	00107$
00109$:
;	delay.c:172: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
