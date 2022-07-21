;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module uart_buffer
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
	.globl _uartBufferInitialise
	.globl _uartBufferLength
	.globl _uartBufferWrite
	.globl _uartBufferRead
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
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
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
;Allocation info for local variables in function 'uartBufferInitialise'
;------------------------------------------------------------
;buffer                    Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	uart-buffer.c:39: void uartBufferInitialise(UartBuffer *buffer) REENTRANT {
;	-----------------------------------------
;	 function uartBufferInitialise
;	-----------------------------------------
_uartBufferInitialise:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	uart-buffer.c:40: buffer->first = UART_BUFFER_SIZE;
	mov	a,#0x10
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,#0x10
	lcall	__gptrput
;	uart-buffer.c:41: buffer->last = UART_BUFFER_SIZE;
	inc	a
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,#0x10
	lcall	__gptrput
;	uart-buffer.c:42: buffer->busy = 0;
	mov	a,#0x12
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
;	uart-buffer.c:43: }
	ljmp	__gptrput
;------------------------------------------------------------
;Allocation info for local variables in function 'uartBufferLength'
;------------------------------------------------------------
;buffer                    Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	uart-buffer.c:45: uint8_t uartBufferLength(UartBuffer *buffer) REENTRANT {
;	-----------------------------------------
;	 function uartBufferLength
;	-----------------------------------------
_uartBufferLength:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	uart-buffer.c:46: return (buffer->last >= buffer->first)
	mov	a,#0x11
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r4,a
	mov	a,#0x10
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
	clr	c
	mov	a,r4
	subb	a,r7
	mov	b0,c
	jc	00103$
;	uart-buffer.c:47: ? (buffer->last == UART_BUFFER_SIZE
	cjne	r4,#0x10,00105$
;	uart-buffer.c:48: ? 0
	mov	r5,#0x00
	mov	r6,#0x00
	sjmp	00104$
00105$:
;	uart-buffer.c:49: : (buffer->last - buffer->first + 1)
	mov	a,r4
	clr	c
	subb	a,r7
	mov	r3,a
	inc	r3
	mov	a,r3
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
	sjmp	00104$
00103$:
;	uart-buffer.c:51: : (UART_BUFFER_SIZE - (buffer->first - buffer->last - 1));
	mov	a,r7
	clr	c
	subb	a,r4
	mov	r4,a
	dec	a
	setb	c
	subb	a,#0x10
	cpl	a
	mov	r7,a
	mov	r5,a
	rlc	a
	subb	a,acc
	mov	r6,a
00104$:
	mov	dpl,r5
;	uart-buffer.c:52: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartBufferWrite'
;------------------------------------------------------------
;data                      Allocated to stack - _bp -3
;buffer                    Allocated to stack - _bp +1
;rc                        Allocated to registers r4 
;sloc0                     Allocated to stack - _bp +4
;------------------------------------------------------------
;	uart-buffer.c:54: uint8_t uartBufferWrite(UartBuffer *buffer, uint8_t data) REENTRANT {
;	-----------------------------------------
;	 function uartBufferWrite
;	-----------------------------------------
_uartBufferWrite:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	inc	sp
	inc	sp
	inc	sp
;	uart-buffer.c:55: uint8_t rc = 0;
	mov	r4,#0x00
;	uart-buffer.c:57: if (uartBufferLength(buffer) < UART_BUFFER_SIZE) {
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	push	ar4
	lcall	_uartBufferLength
	mov	r3,dpl
	pop	ar4
	cjne	r3,#0x10,00121$
00121$:
	jc	00122$
	ljmp	00106$
00122$:
;	uart-buffer.c:58: buffer->last++;
	mov	r0,_bp
	inc	r0
	mov	a,#0x11
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r3,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r6,a
	inc	r6
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	mov	a,r6
	lcall	__gptrput
;	uart-buffer.c:60: if (buffer->last >= UART_BUFFER_SIZE) {
	cjne	r6,#0x10,00123$
00123$:
	jc	00102$
;	uart-buffer.c:62: buffer->last = 0;
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	clr	a
	lcall	__gptrput
00102$:
;	uart-buffer.c:65: if (buffer->first == UART_BUFFER_SIZE) {
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x10
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r6,a
	cjne	r6,#0x10,00104$
;	uart-buffer.c:67: buffer->first = 0;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	clr	a
	lcall	__gptrput
00104$:
;	uart-buffer.c:70: buffer->data[buffer->last] = data;
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	mov	r0,_bp
	inc	r0
	mov	a,r2
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r7,a
	inc	r0
	mov	ar6,@r0
	mov	dpl,r2
	mov	dph,r7
	mov	b,r6
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	lcall	__gptrput
;	uart-buffer.c:71: rc = 1;
	mov	r4,#0x01
00106$:
;	uart-buffer.c:74: return rc;
	mov	dpl,r4
;	uart-buffer.c:75: }
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartBufferRead'
;------------------------------------------------------------
;buffer                    Allocated to stack - _bp +1
;result                    Allocated to registers r4 
;sloc0                     Allocated to stack - _bp +4
;------------------------------------------------------------
;	uart-buffer.c:77: uint8_t uartBufferRead(UartBuffer *buffer) REENTRANT {
;	-----------------------------------------
;	 function uartBufferRead
;	-----------------------------------------
_uartBufferRead:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	inc	sp
	inc	sp
	inc	sp
;	uart-buffer.c:78: uint8_t result = 0;
	mov	r4,#0x00
;	uart-buffer.c:80: if (buffer->first != UART_BUFFER_SIZE) {
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x04
	mov	r1,a
	mov	a,#0x10
	add	a,@r0
	mov	@r1,a
	clr	a
	inc	r0
	addc	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r3,a
	cjne	r3,#0x10,00122$
	ljmp	00107$
00122$:
;	uart-buffer.c:82: result = buffer->data[buffer->first];
	mov	r0,_bp
	inc	r0
	mov	a,r3
	add	a,@r0
	mov	r2,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
;	uart-buffer.c:84: if (buffer->first == buffer->last) {
	mov	r0,_bp
	inc	r0
	mov	a,#0x11
	add	a,@r0
	mov	r5,a
	clr	a
	inc	r0
	addc	a,@r0
	mov	r6,a
	inc	r0
	mov	ar7,@r0
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r2,a
	mov	a,r3
	cjne	a,ar2,00104$
;	uart-buffer.c:86: buffer->first = UART_BUFFER_SIZE;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,#0x10
	lcall	__gptrput
;	uart-buffer.c:87: buffer->last = UART_BUFFER_SIZE;
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
	sjmp	00107$
00104$:
;	uart-buffer.c:89: buffer->first++;
	inc	r3
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r3
	lcall	__gptrput
;	uart-buffer.c:91: if (buffer->first == UART_BUFFER_SIZE) {
	cjne	r3,#0x10,00107$
;	uart-buffer.c:92: buffer->first = 0;
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	clr	a
	lcall	__gptrput
00107$:
;	uart-buffer.c:97: return result;
	mov	dpl,r4
;	uart-buffer.c:98: }
	mov	sp,_bp
	pop	_bp
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
