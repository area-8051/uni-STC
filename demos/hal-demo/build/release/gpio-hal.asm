;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module gpio_hal
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
	.globl _gpioWrite_PARM_2
	.globl _gpioConfigure
	.globl _gpioRead
	.globl _gpioWrite
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
_gpioConfigure_sloc0_1_0:
	.ds 3
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
___isOutput_sloc0_1_0:
	.ds 1
___isInput_sloc0_1_0:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
___gpio_setBits_PARM_2:
	.ds 1
___gpio_setBits_PARM_3:
	.ds 3
_gpioConfigure_gpioConfig_65536_10:
	.ds 3
_gpioWrite_PARM_2:
	.ds 1
_gpioWrite_gpioConfig_65536_18:
	.ds 3
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
;Allocation info for local variables in function '__gpio_setBits'
;------------------------------------------------------------
;	gpio-hal.c:39: static uint8_t __gpio_setBits(uint8_t portValue, uint8_t cfgValue, GpioConfig *gpioConfig) {
;	-----------------------------------------
;	 function __gpio_setBits
;	-----------------------------------------
___gpio_setBits:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7,dpl
;	gpio-hal.c:40: return cfgValue ? (portValue | gpioConfig->__setMask) : (portValue & gpioConfig->__clearMask);
	mov	r0,#___gpio_setBits_PARM_2
	movx	a,@r0
	jz	00103$
	mov	r0,#___gpio_setBits_PARM_3
	movx	a,@r0
	add	a,#0x04
	mov	r4,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r5,a
	inc	r0
	movx	a,@r0
	mov	r6,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r4,a
	orl	a,r7
	mov	r6,a
	sjmp	00104$
00103$:
	mov	r0,#___gpio_setBits_PARM_3
	movx	a,@r0
	add	a,#0x05
	mov	r3,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r4,a
	inc	r0
	movx	a,@r0
	mov	r5,a
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r3,a
	anl	a,r7
	mov	r6,a
00104$:
	mov	dpl,r6
;	gpio-hal.c:41: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__isOutput'
;------------------------------------------------------------
;	gpio-hal.c:43: static uint8_t __isOutput(GpioConfig *gpioConfig) {
;	-----------------------------------------
;	 function __isOutput
;	-----------------------------------------
___isOutput:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	gpio-hal.c:44: return gpioConfig->portMode == GPIO_BIDIRECTIONAL || gpioConfig->portMode == GPIO_PUSH_PULL || gpioConfig->portMode == GPIO_OPEN_DRAIN;
	mov	a,#0x03
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r7,a
	jz	00104$
	cjne	r7,#0x01,00122$
	sjmp	00104$
00122$:
	cjne	r7,#0x03,00123$
	sjmp	00104$
00123$:
;	assignBit
	clr	___isOutput_sloc0_1_0
	sjmp	00105$
00104$:
;	assignBit
	setb	___isOutput_sloc0_1_0
00105$:
	mov	c,___isOutput_sloc0_1_0
	clr	a
	rlc	a
	mov	dpl,a
;	gpio-hal.c:45: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__isInput'
;------------------------------------------------------------
;	gpio-hal.c:47: static uint8_t __isInput(GpioConfig *gpioConfig) {
;	-----------------------------------------
;	 function __isInput
;	-----------------------------------------
___isInput:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	gpio-hal.c:48: return gpioConfig->portMode == GPIO_BIDIRECTIONAL || gpioConfig->portMode == GPIO_HIGH_IMPEDANCE;
	mov	a,#0x03
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r7,a
	jz	00104$
	cjne	r7,#0x02,00115$
	sjmp	00104$
00115$:
;	assignBit
	clr	___isInput_sloc0_1_0
	sjmp	00105$
00104$:
;	assignBit
	setb	___isInput_sloc0_1_0
00105$:
	mov	c,___isInput_sloc0_1_0
	clr	a
	rlc	a
	mov	dpl,a
;	gpio-hal.c:49: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'gpioConfigure'
;------------------------------------------------------------
;sloc0                     Allocated with name '_gpioConfigure_sloc0_1_0'
;------------------------------------------------------------
;	gpio-hal.c:51: void gpioConfigure(GpioConfig *gpioConfig) {
;	-----------------------------------------
;	 function gpioConfigure
;	-----------------------------------------
_gpioConfigure:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	@r0,a
	mov	a,r6
	inc	r0
	movx	@r0,a
	mov	a,r7
	inc	r0
	movx	@r0,a
;	gpio-hal.c:53: uint8_t mask = 0;
	mov	r4,#0x00
;	gpio-hal.c:55: for (uint8_t n = gpioConfig->count; n > 0; n--) {
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x02
	mov	r2,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r7,a
00110$:
	mov	a,r7
	jz	00101$
;	gpio-hal.c:56: mask = mask << 1;
	mov	ar6,r4
	mov	a,r6
	add	a,r6
	mov	r6,a
;	gpio-hal.c:57: mask |= 1;
	mov	a,#0x01
	orl	a,r6
	mov	r4,a
;	gpio-hal.c:55: for (uint8_t n = gpioConfig->count; n > 0; n--) {
	dec	r7
	sjmp	00110$
00101$:
;	gpio-hal.c:60: gpioConfig->__setMask = mask << gpioConfig->pin;
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x04
	mov	_gpioConfigure_sloc0_1_0,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	(_gpioConfigure_sloc0_1_0 + 1),a
	inc	r0
	movx	a,@r0
	mov	(_gpioConfigure_sloc0_1_0 + 2),a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x01
	mov	r2,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	mov	b,r2
	inc	b
	mov	a,r4
	sjmp	00135$
00133$:
	add	a,acc
00135$:
	djnz	b,00133$
	mov	r2,a
	mov	dpl,_gpioConfigure_sloc0_1_0
	mov	dph,(_gpioConfigure_sloc0_1_0 + 1)
	mov	b,(_gpioConfigure_sloc0_1_0 + 2)
	lcall	__gptrput
;	gpio-hal.c:61: gpioConfig->__clearMask = ~gpioConfig->__setMask;
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	a,r2
	cpl	a
	mov	r2,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
;	gpio-hal.c:63: switch (gpioConfig->port) {
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	mov	dpl,a
	inc	r0
	movx	a,@r0
	mov	dph,a
	inc	r0
	movx	a,@r0
	mov	b,a
	lcall	__gptrget
	mov  r7,a
	add	a,#0xff - 0x05
	jnc	00136$
	ret
00136$:
	mov	a,r7
	add	a,r7
	add	a,r7
	mov	dptr,#00137$
	jmp	@a+dptr
00137$:
	ljmp	00102$
	ljmp	00103$
	ljmp	00104$
	ljmp	00105$
	ljmp	00106$
	ljmp	00107$
;	gpio-hal.c:68: case GPIO_PORT0:
00102$:
;	gpio-hal.c:69: P0M1 = __gpio_setBits(P0M1, gpioConfig->portMode & 2, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x02
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P0M1
	lcall	___gpio_setBits
	mov	_P0M1,dpl
;	gpio-hal.c:70: P0M0 = __gpio_setBits(P0M0, gpioConfig->portMode & 1, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x01
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P0M0
	lcall	___gpio_setBits
	mov	_P0M0,dpl
;	gpio-hal.c:98: break;
	ret
;	gpio-hal.c:104: case GPIO_PORT1:
00103$:
;	gpio-hal.c:105: P1M1 = __gpio_setBits(P1M1, gpioConfig->portMode & 2, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x02
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P1M1
	lcall	___gpio_setBits
	mov	_P1M1,dpl
;	gpio-hal.c:106: P1M0 = __gpio_setBits(P1M0, gpioConfig->portMode & 1, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x01
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P1M0
	lcall	___gpio_setBits
	mov	_P1M0,dpl
;	gpio-hal.c:134: break;
	ret
;	gpio-hal.c:140: case GPIO_PORT2:
00104$:
;	gpio-hal.c:141: P2M1 = __gpio_setBits(P2M1, gpioConfig->portMode & 2, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x02
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P2M1
	lcall	___gpio_setBits
	mov	_P2M1,dpl
;	gpio-hal.c:142: P2M0 = __gpio_setBits(P2M0, gpioConfig->portMode & 1, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x01
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P2M0
	lcall	___gpio_setBits
	mov	_P2M0,dpl
;	gpio-hal.c:170: break;
	ret
;	gpio-hal.c:175: case GPIO_PORT3:
00105$:
;	gpio-hal.c:176: P3M1 = __gpio_setBits(P3M1, gpioConfig->portMode & 2, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x02
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P3M1
	lcall	___gpio_setBits
	mov	_P3M1,dpl
;	gpio-hal.c:177: P3M0 = __gpio_setBits(P3M0, gpioConfig->portMode & 1, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x01
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P3M0
	lcall	___gpio_setBits
	mov	_P3M0,dpl
;	gpio-hal.c:205: break;
	ret
;	gpio-hal.c:210: case GPIO_PORT4:
00106$:
;	gpio-hal.c:211: P4M1 = __gpio_setBits(P4M1, gpioConfig->portMode & 2, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x02
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P4M1
	lcall	___gpio_setBits
	mov	_P4M1,dpl
;	gpio-hal.c:212: P4M0 = __gpio_setBits(P4M0, gpioConfig->portMode & 1, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x01
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P4M0
	lcall	___gpio_setBits
	mov	_P4M0,dpl
;	gpio-hal.c:240: break;
;	gpio-hal.c:245: case GPIO_PORT5:
	ret
00107$:
;	gpio-hal.c:246: P5M1 = __gpio_setBits(P5M1, gpioConfig->portMode & 2, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x02
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P5M1
	lcall	___gpio_setBits
	mov	_P5M1,dpl
;	gpio-hal.c:247: P5M0 = __gpio_setBits(P5M0, gpioConfig->portMode & 1, gpioConfig);
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	movx	a,@r0
	add	a,#0x03
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	r0,#___gpio_setBits_PARM_2
	mov	a,#0x01
	anl	a,r5
	movx	@r0,a
	mov	r0,#_gpioConfigure_gpioConfig_65536_10
	mov	r1,#___gpio_setBits_PARM_3
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,_P5M0
	lcall	___gpio_setBits
	mov	_P5M0,dpl
;	gpio-hal.c:348: }
;	gpio-hal.c:349: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'gpioRead'
;------------------------------------------------------------
;	gpio-hal.c:351: uint8_t gpioRead(GpioConfig *gpioConfig) {
;	-----------------------------------------
;	 function gpioRead
;	-----------------------------------------
_gpioRead:
;	gpio-hal.c:352: uint8_t value = 0;
;	gpio-hal.c:354: switch (gpioConfig->port) {
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	mov	r4,#0x00
	lcall	__gptrget
	mov  r3,a
	add	a,#0xff - 0x05
	jc	00107$
	mov	a,r3
	add	a,r3
;	gpio-hal.c:359: case GPIO_PORT0:
	mov	dptr,#00115$
	jmp	@a+dptr
00115$:
	sjmp	00101$
	sjmp	00102$
	sjmp	00103$
	sjmp	00104$
	sjmp	00105$
	sjmp	00106$
00101$:
;	gpio-hal.c:360: value = P0;
	mov	r4,_P0
;	gpio-hal.c:361: break;
;	gpio-hal.c:367: case GPIO_PORT1:
	sjmp	00107$
00102$:
;	gpio-hal.c:368: value = P1;
	mov	r4,_P1
;	gpio-hal.c:369: break;
;	gpio-hal.c:375: case GPIO_PORT2:
	sjmp	00107$
00103$:
;	gpio-hal.c:376: value = P2;
	mov	r4,_P2
;	gpio-hal.c:377: break;
;	gpio-hal.c:382: case GPIO_PORT3:
	sjmp	00107$
00104$:
;	gpio-hal.c:383: value = P3;
	mov	r4,_P3
;	gpio-hal.c:384: break;
;	gpio-hal.c:389: case GPIO_PORT4:
	sjmp	00107$
00105$:
;	gpio-hal.c:390: value = P4;
	mov	r4,_P4
;	gpio-hal.c:391: break;
;	gpio-hal.c:396: case GPIO_PORT5:
	sjmp	00107$
00106$:
;	gpio-hal.c:397: value = P5;
	mov	r4,_P5
;	gpio-hal.c:415: }
00107$:
;	gpio-hal.c:417: return (value & gpioConfig->__setMask) >> gpioConfig->pin;
	mov	a,#0x04
	add	a,r5
	mov	r1,a
	clr	a
	addc	a,r6
	mov	r2,a
	mov	ar3,r7
	mov	dpl,r1
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	anl	ar4,a
	inc	r5
	cjne	r5,#0x00,00116$
	inc	r6
00116$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	b,r5
	inc	b
	mov	a,r4
	sjmp	00118$
00117$:
	clr	c
	rrc	a
00118$:
	djnz	b,00117$
	mov	dpl,a
;	gpio-hal.c:418: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'gpioWrite'
;------------------------------------------------------------
;	gpio-hal.c:420: void gpioWrite(GpioConfig *gpioConfig, uint8_t value) {
;	-----------------------------------------
;	 function gpioWrite
;	-----------------------------------------
_gpioWrite:
	mov	r7,b
	mov	r6,dph
	mov	a,dpl
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	@r0,a
	mov	a,r6
	inc	r0
	movx	@r0,a
	mov	a,r7
	inc	r0
	movx	@r0,a
;	gpio-hal.c:421: if (gpioConfig->count == 1) {
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x02
	mov	r2,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	cjne	r2,#0x01,00102$
;	gpio-hal.c:425: value = value ? 1 : 0;
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	jz	00112$
	mov	r3,#0x01
	mov	r4,#0x00
	sjmp	00113$
00112$:
	mov	r3,#0x00
	mov	r4,#0x00
00113$:
	mov	r0,#_gpioWrite_PARM_2
	mov	a,r3
	movx	@r0,a
00102$:
;	gpio-hal.c:428: value = (value << gpioConfig->pin) & gpioConfig->__setMask;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x01
	mov	r2,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r4,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	b,r2
	inc	b
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	sjmp	00131$
00129$:
	add	a,acc
00131$:
	djnz	b,00129$
	mov	r2,a
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x04
	mov	r3,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r4,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r3
	mov	dph,r4
	mov	b,r7
	lcall	__gptrget
	mov	r3,a
	anl	a,r2
	mov	r0,#_gpioWrite_PARM_2
	movx	@r0,a
;	gpio-hal.c:430: switch (gpioConfig->port) {
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	mov	dpl,a
	inc	r0
	movx	a,@r0
	mov	dph,a
	inc	r0
	movx	a,@r0
	mov	b,a
	lcall	__gptrget
	mov  r7,a
	add	a,#0xff - 0x05
	jnc	00132$
	ret
00132$:
	mov	a,r7
	add	a,r7
	add	a,r7
	mov	dptr,#00133$
	jmp	@a+dptr
00133$:
	ljmp	00103$
	ljmp	00104$
	ljmp	00105$
	ljmp	00106$
	ljmp	00107$
	ljmp	00108$
;	gpio-hal.c:435: case GPIO_PORT0:
00103$:
;	gpio-hal.c:436: P0 = (P0 & gpioConfig->__clearMask) | value;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,_P0
	anl	ar5,a
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	orl	a,r5
	mov	_P0,a
;	gpio-hal.c:437: break;
	ret
;	gpio-hal.c:443: case GPIO_PORT1:
00104$:
;	gpio-hal.c:444: P1 = (P1 & gpioConfig->__clearMask) | value;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,_P1
	anl	ar5,a
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	orl	a,r5
	mov	_P1,a
;	gpio-hal.c:445: break;
	ret
;	gpio-hal.c:451: case GPIO_PORT2:
00105$:
;	gpio-hal.c:452: P2 = (P2 & gpioConfig->__clearMask) | value;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,_P2
	anl	ar5,a
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	orl	a,r5
	mov	_P2,a
;	gpio-hal.c:453: break;
;	gpio-hal.c:458: case GPIO_PORT3:
	ret
00106$:
;	gpio-hal.c:459: P3 = (P3 & gpioConfig->__clearMask) | value;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,_P3
	anl	ar5,a
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	orl	a,r5
	mov	_P3,a
;	gpio-hal.c:460: break;
;	gpio-hal.c:465: case GPIO_PORT4:
	ret
00107$:
;	gpio-hal.c:466: P4 = (P4 & gpioConfig->__clearMask) | value;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,_P4
	anl	ar5,a
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	orl	a,r5
	mov	_P4,a
;	gpio-hal.c:467: break;
;	gpio-hal.c:472: case GPIO_PORT5:
	ret
00108$:
;	gpio-hal.c:473: P5 = (P5 & gpioConfig->__clearMask) | value;
	mov	r0,#_gpioWrite_gpioConfig_65536_18
	movx	a,@r0
	add	a,#0x05
	mov	r5,a
	inc	r0
	movx	a,@r0
	addc	a,#0x00
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,_P5
	anl	ar5,a
	mov	r0,#_gpioWrite_PARM_2
	movx	a,@r0
	orl	a,r5
	mov	_P5,a
;	gpio-hal.c:491: }
;	gpio-hal.c:492: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
