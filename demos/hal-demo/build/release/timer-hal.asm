;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module timer_hal
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
	.globl _startWatchdog_PARM_2
	.globl _startTimer_PARM_5
	.globl _startTimer_PARM_4
	.globl _startTimer_PARM_3
	.globl _startTimer_PARM_2
	.globl _baudRateToSysclkDivisor
	.globl _frequencyToSysclkDivisor
	.globl _startTimer
	.globl _startWatchdog
	.globl _clearWatchdog
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
_startTimer_PARM_2:
	.ds 4
_startTimer_PARM_3:
	.ds 1
_startTimer_PARM_4:
	.ds 1
_startTimer_PARM_5:
	.ds 1
_startTimer_rc_65536_10:
	.ds 1
_startWatchdog_PARM_2:
	.ds 1
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
;Allocation info for local variables in function 'baudRateToSysclkDivisor'
;------------------------------------------------------------
;	timer-hal.c:47: uint32_t baudRateToSysclkDivisor(uint32_t baudRate) {
;	-----------------------------------------
;	 function baudRateToSysclkDivisor
;	-----------------------------------------
_baudRateToSysclkDivisor:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
;	timer-hal.c:53: divisor = (MCU_FREQ / baudRate / 32UL);
	mov	r0,#__divulong_PARM_2
	mov	a,r4
	movx	@r0,a
	mov	a,r5
	inc	r0
	movx	@r0,a
	mov	a,r6
	inc	r0
	movx	@r0,a
	mov	a,r7
	inc	r0
	movx	@r0,a
	mov	dptr,#0xc000
	mov	b,#0xa8
	clr	a
	lcall	__divulong
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	mov	a,r5
	swap	a
	rr	a
	xch	a,r4
	swap	a
	rr	a
	anl	a,#0x07
	xrl	a,r4
	xch	a,r4
	anl	a,#0x07
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	mov	r5,a
	mov	a,r6
	swap	a
	rr	a
	anl	a,#0xf8
	orl	a,r5
	mov	r5,a
	mov	a,r7
	swap	a
	rr	a
	xch	a,r6
	swap	a
	rr	a
	anl	a,#0x07
	xrl	a,r6
	xch	a,r6
	anl	a,#0x07
	xch	a,r6
	xrl	a,r6
	xch	a,r6
;	timer-hal.c:62: return divisor;
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
;	timer-hal.c:63: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'frequencyToSysclkDivisor'
;------------------------------------------------------------
;	timer-hal.c:65: uint32_t frequencyToSysclkDivisor(uint32_t frequency) {
;	-----------------------------------------
;	 function frequencyToSysclkDivisor
;	-----------------------------------------
_frequencyToSysclkDivisor:
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
;	timer-hal.c:66: return MCU_FREQ / frequency;
	mov	r0,#__divulong_PARM_2
	mov	a,r4
	movx	@r0,a
	mov	a,r5
	inc	r0
	movx	@r0,a
	mov	a,r6
	inc	r0
	movx	@r0,a
	mov	a,r7
	inc	r0
	movx	@r0,a
	mov	dptr,#0xc000
	mov	b,#0xa8
	clr	a
;	timer-hal.c:67: }
	ljmp	__divulong
;------------------------------------------------------------
;Allocation info for local variables in function 'startTimer'
;------------------------------------------------------------
;	timer-hal.c:69: Timer_Status startTimer(Timer timer, uint32_t sysclkDivisor, Timer_Output enableOutput, Timer_Interrupt enableInterrupt, Timer_Control timerControl) {
;	-----------------------------------------
;	 function startTimer
;	-----------------------------------------
_startTimer:
	mov	r7,dpl
;	timer-hal.c:70: Timer_Status rc = TIMER_FREQUENCY_OK;
	mov	r0,#_startTimer_rc_65536_10
	clr	a
	movx	@r0,a
;	timer-hal.c:71: uint8_t sysclkDiv1 = 1;
	mov	r5,#0x01
;	timer-hal.c:73: if (sysclkDivisor == 0) {
	mov	r0,#_startTimer_PARM_2
	movx	a,@r0
	mov	b,a
	inc	r0
	movx	a,@r0
	orl	b,a
	inc	r0
	movx	a,@r0
	orl	b,a
	inc	r0
	movx	a,@r0
	orl	a,b
	jnz	00107$
;	timer-hal.c:75: rc = TIMER_FREQUENCY_TOO_HIGH;
	mov	r0,#_startTimer_rc_65536_10
	mov	a,#0x01
	movx	@r0,a
	ljmp	00108$
00107$:
;	timer-hal.c:76: } else if (sysclkDivisor >= (COUNTER_MAX * 12UL)) {
	mov	r0,#_startTimer_PARM_2
	clr	c
	inc	r0
	movx	a,@r0
	subb	a,#0x0c
	inc	r0
	movx	a,@r0
	subb	a,#0x00
	inc	r0
	movx	a,@r0
	subb	a,#0x00
	jc	00104$
;	timer-hal.c:78: rc = TIMER_FREQUENCY_TOO_LOW;
	mov	r0,#_startTimer_rc_65536_10
	mov	a,#0x02
	movx	@r0,a
	sjmp	00108$
00104$:
;	timer-hal.c:80: if (sysclkDivisor > COUNTER_MAX) {
	mov	r0,#_startTimer_PARM_2
	clr	c
	movx	a,@r0
	mov	b,a
	clr	a
	subb	a,b
	inc	r0
	movx	a,@r0
	mov	b,a
	mov	a,#0x01
	subb	a,b
	inc	r0
	movx	a,@r0
	mov	b,a
	clr	a
	subb	a,b
	inc	r0
	movx	a,@r0
	mov	b,a
	clr	a
	subb	a,b
	jnc	00108$
;	timer-hal.c:82: sysclkDiv1 = 0;
	mov	r5,#0x00
;	timer-hal.c:83: sysclkDivisor /= 12UL;
	mov	r0,#__divulong_PARM_2
	mov	a,#0x0c
	movx	@r0,a
	clr	a
	inc	r0
	movx	@r0,a
	inc	r0
	movx	@r0,a
	inc	r0
	movx	@r0,a
	mov	r0,#_startTimer_PARM_2
	movx	a,@r0
	mov	dpl,a
	inc	r0
	movx	a,@r0
	mov	dph,a
	inc	r0
	movx	a,@r0
	mov	b,a
	inc	r0
	movx	a,@r0
	push	ar7
	push	ar5
	lcall	__divulong
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r6,a
	pop	ar5
	pop	ar7
	mov	r0,#_startTimer_PARM_2
	mov	a,r2
	movx	@r0,a
	mov	a,r3
	inc	r0
	movx	@r0,a
	mov	a,r4
	inc	r0
	movx	@r0,a
	mov	a,r6
	inc	r0
	movx	@r0,a
00108$:
;	timer-hal.c:87: if (rc == TIMER_FREQUENCY_OK) {
	mov	r0,#_startTimer_rc_65536_10
	movx	a,@r0
	jz	00195$
	ljmp	00129$
00195$:
;	timer-hal.c:88: uint16_t reloadValue = (uint16_t) (COUNTER_MAX - sysclkDivisor);
	mov	r0,#_startTimer_PARM_2
	movx	a,@r0
	mov	r4,a
	inc	r0
	movx	a,@r0
	mov	r6,a
	clr	a
	clr	c
	subb	a,r4
	mov	r4,a
	mov	a,#0x01
	subb	a,r6
	mov	r6,a
;	timer-hal.c:90: switch (timer) {
	cjne	r7,#0x00,00196$
	sjmp	00109$
00196$:
	cjne	r7,#0x01,00197$
	sjmp	00116$
00197$:
	cjne	r7,#0x02,00198$
	ljmp	00123$
00198$:
	ljmp	00129$
;	timer-hal.c:91: case TIMER0:
00109$:
;	timer-hal.c:93: AUXR = (AUXR & ~M_T0x12) | ((sysclkDiv1 << P_T0x12) & M_T0x12);
	mov	a,#0x7f
	anl	a,_AUXR
	mov	r7,a
	mov	ar3,r5
	mov	a,r3
	rr	a
	anl	a,#0x80
	mov	r3,a
	mov	a,#0x80
	anl	a,r3
	orl	a,r7
	mov	_AUXR,a
;	timer-hal.c:96: TMOD &= 0xf0;
	anl	_TMOD,#0xf0
;	timer-hal.c:99: TMOD = (TMOD & ~M_T0_GATE) | ((timerControl << P_T0_GATE) & M_T0_GATE);
	mov	a,#0xf7
	anl	a,_TMOD
	mov	r7,a
	mov	r0,#_startTimer_PARM_5
	movx	a,@r0
	swap	a
	rr	a
	anl	a,#0xf8
	mov	r3,a
	mov	a,#0x08
	anl	a,r3
	orl	a,r7
	mov	_TMOD,a
;	timer-hal.c:103: TMOD |= 2;
	orl	_TMOD,#0x02
;	timer-hal.c:105: if (enableOutput == TIMER_OUTPUT_ENABLE) {
	mov	r0,#_startTimer_PARM_3
	movx	a,@r0
	cjne	a,#0x01,00111$
;	timer-hal.c:106: WAKE_CLKO |= M_T0CLKO;
	orl	_WAKE_CLKO,#0x01
	sjmp	00112$
00111$:
;	timer-hal.c:108: WAKE_CLKO &= ~M_T0CLKO;
	anl	_WAKE_CLKO,#0xfe
00112$:
;	timer-hal.c:111: T0H = T0L = reloadValue;
	mov	ar7,r4
	mov	_T0L,r7
	mov	_T0H,r7
;	timer-hal.c:122: if (enableInterrupt == TIMER_INTERRUPT_ENABLE) {
	mov	r0,#_startTimer_PARM_4
	movx	a,@r0
	cjne	a,#0x01,00114$
;	timer-hal.c:123: IE1 |= M_ET0;
	orl	_IE1,#0x02
	sjmp	00115$
00114$:
;	timer-hal.c:125: IE1 &= ~M_ET0;
	anl	_IE1,#0xfd
00115$:
;	timer-hal.c:129: TCON = (TCON & ~M_T0IF) | M_T0R;
	mov	a,#0xdf
	anl	a,_TCON
	orl	a,#0x10
	mov	_TCON,a
;	timer-hal.c:130: break;
	ljmp	00129$
;	timer-hal.c:133: case TIMER1:
00116$:
;	timer-hal.c:136: TMOD = (TMOD & 0x0f) | (2 << P_T1_M);
	mov	a,_TMOD
	anl	a,#0x0f
	orl	a,#0x20
	mov	_TMOD,a
;	timer-hal.c:138: if (enableOutput == TIMER_OUTPUT_ENABLE) {
	mov	r0,#_startTimer_PARM_3
	movx	a,@r0
	cjne	a,#0x01,00118$
;	timer-hal.c:139: WAKE_CLKO |= M_T1CLKO;
	orl	_WAKE_CLKO,#0x02
	sjmp	00119$
00118$:
;	timer-hal.c:141: WAKE_CLKO &= ~M_T1CLKO;
	anl	_WAKE_CLKO,#0xfd
00119$:
;	timer-hal.c:145: T1H = T1L = reloadValue;
	mov	ar7,r4
	mov	_T1L,r7
	mov	_T1H,r7
;	timer-hal.c:161: TMOD = (TMOD & ~M_T1_GATE) | ((timerControl << P_T1_GATE) & M_T1_GATE);
	mov	a,#0x7f
	anl	a,_TMOD
	mov	r7,a
	mov	r0,#_startTimer_PARM_5
	movx	a,@r0
	rr	a
	anl	a,#0x80
	mov	r3,a
	mov	a,#0x80
	anl	a,r3
	orl	a,r7
	mov	_TMOD,a
;	timer-hal.c:164: AUXR = (sysclkDiv1) ? (AUXR | M_T1x12) : (AUXR & ~M_T1x12);
	mov	a,r5
	jz	00132$
	mov	a,#0x40
	orl	a,_AUXR
	mov	r7,a
	sjmp	00133$
00132$:
	mov	a,#0xbf
	anl	a,_AUXR
	mov	r7,a
00133$:
	mov	_AUXR,r7
;	timer-hal.c:166: if (enableInterrupt == TIMER_INTERRUPT_ENABLE) {
	mov	r0,#_startTimer_PARM_4
	movx	a,@r0
	cjne	a,#0x01,00121$
;	timer-hal.c:167: IE1 |= M_ET1;
	orl	_IE1,#0x08
	sjmp	00122$
00121$:
;	timer-hal.c:169: IE1 &= ~M_ET1;
	anl	_IE1,#0xf7
00122$:
;	timer-hal.c:173: TCON = (TCON & ~M_T1IF) | M_T1R;
	mov	a,#0x7f
	anl	a,_TCON
	orl	a,#0x40
	mov	_TCON,a
;	timer-hal.c:174: break;
;	timer-hal.c:177: case TIMER2:
	sjmp	00129$
00123$:
;	timer-hal.c:193: if (enableOutput == TIMER_OUTPUT_ENABLE) {
	mov	r0,#_startTimer_PARM_3
	movx	a,@r0
	cjne	a,#0x01,00125$
;	timer-hal.c:194: WAKE_CLKO |= M_BRTCLKO;
	orl	_WAKE_CLKO,#0x04
	sjmp	00126$
00125$:
;	timer-hal.c:196: WAKE_CLKO &= ~M_BRTCLKO;
	anl	_WAKE_CLKO,#0xfb
00126$:
;	timer-hal.c:200: BRT =  reloadValue;
	mov	_BRT,r4
;	timer-hal.c:204: AUXR = (sysclkDiv1) ? (AUXR | M_T2x12) : (AUXR & ~M_T2x12);
	mov	a,r5
	jz	00134$
	mov	a,#0x04
	orl	a,_AUXR
	mov	r7,a
	sjmp	00135$
00134$:
	mov	a,#0xfb
	anl	a,_AUXR
	mov	r7,a
00135$:
	mov	_AUXR,r7
;	timer-hal.c:220: AUXR |= M_T2R;
	orl	_AUXR,#0x10
;	timer-hal.c:282: }
00129$:
;	timer-hal.c:285: return rc;
	mov	r0,#_startTimer_rc_65536_10
	movx	a,@r0
	mov	dpl,a
;	timer-hal.c:286: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'startWatchdog'
;------------------------------------------------------------
;	timer-hal.c:288: void startWatchdog(WatchdogPrescaler prescaler, WatchdogIdleMode idleMode) {
;	-----------------------------------------
;	 function startWatchdog
;	-----------------------------------------
_startWatchdog:
	mov	r7,dpl
;	timer-hal.c:289: WDT_CONTR = M_EN_WDT | (prescaler << P_WDT_PS)
	orl	ar7,#0x20
;	timer-hal.c:290: | (idleMode == WDT_ENABLED_IN_IDLE_MODE ? M_IDL_WDT : 0);
	mov	r0,#_startWatchdog_PARM_2
	movx	a,@r0
	cjne	a,#0x01,00103$
	mov	r5,#0x08
	mov	r6,#0x00
	sjmp	00104$
00103$:
	mov	r5,#0x00
	mov	r6,#0x00
00104$:
	mov	a,r5
	orl	a,r7
	mov	_WDT_CONTR,a
;	timer-hal.c:291: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'clearWatchdog'
;------------------------------------------------------------
;	timer-hal.c:293: void clearWatchdog() {
;	-----------------------------------------
;	 function clearWatchdog
;	-----------------------------------------
_clearWatchdog:
;	timer-hal.c:294: WDT_CONTR |= M_CLR_WDT;
	orl	_WDT_CONTR,#0x10
;	timer-hal.c:295: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
