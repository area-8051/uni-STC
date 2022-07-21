;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module uart_hal
	.optsdcc -mmcs51 --model-medium
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _uartBufferRead
	.globl _uartBufferWrite
	.globl _uartBufferLength
	.globl _uartBufferInitialise
	.globl _startTimer
	.globl _baudRateToSysclkDivisor
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
	.globl _uartSendCharacter_PARM_2
	.globl _uartInitialise_PARM_5
	.globl _uartInitialise_PARM_4
	.globl _uartInitialise_PARM_3
	.globl _uartInitialise_PARM_2
	.globl _UART2_mode
	.globl _UART2_outputBuffer
	.globl _UART2_inputBuffer
	.globl _UART1_mode
	.globl _UART1_outputBuffer
	.globl _UART1_inputBuffer
	.globl _uartReceiveBufferEmpty
	.globl _uartReceiveBufferFull
	.globl _uartTransmitBufferEmpty
	.globl _uartTransmitBufferFull
	.globl _uartInitialise
	.globl ___uart1_isr
	.globl ___uart2_isr
	.globl _uartGetCharacter
	.globl _uartSendCharacter
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
	.area REG_BANK_1	(REL,OVR,DATA)
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
_uartInitialise_sloc0_1_0:
	.ds 2
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
_UART1_inputBuffer::
	.ds 19
_UART1_outputBuffer::
	.ds 19
_UART1_mode::
	.ds 1
_UART2_inputBuffer::
	.ds 19
_UART2_outputBuffer::
	.ds 19
_UART2_mode::
	.ds 1
_uartInitialise_PARM_2:
	.ds 4
_uartInitialise_PARM_3:
	.ds 1
_uartInitialise_PARM_4:
	.ds 1
_uartInitialise_PARM_5:
	.ds 1
_uartSendCharacter_PARM_2:
	.ds 1
_uartSendCharacter_uart_65536_97:
	.ds 1
_uartSendCharacter_result_65536_98:
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
;Allocation info for local variables in function 'inputBuffer'
;------------------------------------------------------------
;	uart-hal.c:63: static UartBuffer *inputBuffer(Uart uart) {
;	-----------------------------------------
;	 function inputBuffer
;	-----------------------------------------
_inputBuffer:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7,dpl
;	uart-hal.c:64: UartBuffer *result = NULL;
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
;	uart-hal.c:66: switch (uart) {
	cjne	r7,#0x01,00114$
	sjmp	00101$
00114$:
;	uart-hal.c:67: case UART1:
	cjne	r7,#0x02,00103$
	sjmp	00102$
00101$:
;	uart-hal.c:68: result = &UART1_inputBuffer;
	mov	r4,#_UART1_inputBuffer
	mov	r5,#0x00
	mov	r6,#0x60
;	uart-hal.c:69: break;
;	uart-hal.c:72: case UART2:
	sjmp	00103$
00102$:
;	uart-hal.c:73: result = &UART2_inputBuffer;
	mov	r4,#_UART2_inputBuffer
	mov	r5,#0x00
	mov	r6,#0x60
;	uart-hal.c:86: }
00103$:
;	uart-hal.c:88: return result;
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
;	uart-hal.c:89: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'outputBuffer'
;------------------------------------------------------------
;	uart-hal.c:91: static UartBuffer *outputBuffer(Uart uart) {
;	-----------------------------------------
;	 function outputBuffer
;	-----------------------------------------
_outputBuffer:
	mov	r7,dpl
;	uart-hal.c:92: UartBuffer *result = NULL;
	mov	r4,#0x00
	mov	r5,#0x00
	mov	r6,#0x00
;	uart-hal.c:94: switch (uart) {
	cjne	r7,#0x01,00114$
	sjmp	00101$
00114$:
;	uart-hal.c:95: case UART1:
	cjne	r7,#0x02,00103$
	sjmp	00102$
00101$:
;	uart-hal.c:96: result = &UART1_outputBuffer;
	mov	r4,#_UART1_outputBuffer
	mov	r5,#0x00
	mov	r6,#0x60
;	uart-hal.c:97: break;
;	uart-hal.c:100: case UART2:
	sjmp	00103$
00102$:
;	uart-hal.c:101: result = &UART2_outputBuffer;
	mov	r4,#_UART2_outputBuffer
	mov	r5,#0x00
	mov	r6,#0x60
;	uart-hal.c:114: }
00103$:
;	uart-hal.c:116: return result;
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
;	uart-hal.c:117: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartMode'
;------------------------------------------------------------
;	uart-hal.c:119: static UartMode uartMode(Uart uart) {
;	-----------------------------------------
;	 function uartMode
;	-----------------------------------------
_uartMode:
	mov	r7,dpl
;	uart-hal.c:120: UartMode result = UART_8N1;
	mov	r6,#0x00
;	uart-hal.c:122: switch (uart) {
	cjne	r7,#0x01,00114$
	sjmp	00101$
00114$:
;	uart-hal.c:123: case UART1:
	cjne	r7,#0x02,00103$
	sjmp	00102$
00101$:
;	uart-hal.c:124: result = UART1_mode;
	mov	r0,#_UART1_mode
	movx	a,@r0
	mov	r6,a
;	uart-hal.c:125: break;
;	uart-hal.c:128: case UART2:
	sjmp	00103$
00102$:
;	uart-hal.c:129: result = UART2_mode;
	mov	r0,#_UART2_mode
	movx	a,@r0
	mov	r6,a
;	uart-hal.c:142: }
00103$:
;	uart-hal.c:144: return result;
	mov	dpl,r6
;	uart-hal.c:145: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartReceiveBufferEmpty'
;------------------------------------------------------------
;	uart-hal.c:147: uint8_t uartReceiveBufferEmpty(Uart uart) {
;	-----------------------------------------
;	 function uartReceiveBufferEmpty
;	-----------------------------------------
_uartReceiveBufferEmpty:
;	uart-hal.c:148: return uartBufferLength(inputBuffer(uart)) == 0;
	lcall	_inputBuffer
	lcall	_uartBufferLength
	mov	r7,dpl
	clr	a
	cjne	r7,#0x00,00103$
	inc	a
00103$:
	mov	dpl,a
;	uart-hal.c:149: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartReceiveBufferFull'
;------------------------------------------------------------
;	uart-hal.c:151: uint8_t uartReceiveBufferFull(Uart uart) {
;	-----------------------------------------
;	 function uartReceiveBufferFull
;	-----------------------------------------
_uartReceiveBufferFull:
;	uart-hal.c:152: return uartBufferLength(inputBuffer(uart)) == UART_BUFFER_SIZE;
	lcall	_inputBuffer
	lcall	_uartBufferLength
	mov	r7,dpl
	clr	a
	cjne	r7,#0x10,00103$
	inc	a
00103$:
	mov	dpl,a
;	uart-hal.c:153: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartTransmitBufferEmpty'
;------------------------------------------------------------
;	uart-hal.c:155: uint8_t uartTransmitBufferEmpty(Uart uart) {
;	-----------------------------------------
;	 function uartTransmitBufferEmpty
;	-----------------------------------------
_uartTransmitBufferEmpty:
;	uart-hal.c:156: return uartBufferLength(outputBuffer(uart)) == 0;
	lcall	_outputBuffer
	lcall	_uartBufferLength
	mov	r7,dpl
	clr	a
	cjne	r7,#0x00,00103$
	inc	a
00103$:
	mov	dpl,a
;	uart-hal.c:157: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartTransmitBufferFull'
;------------------------------------------------------------
;	uart-hal.c:159: uint8_t uartTransmitBufferFull(Uart uart) {
;	-----------------------------------------
;	 function uartTransmitBufferFull
;	-----------------------------------------
_uartTransmitBufferFull:
;	uart-hal.c:160: return uartBufferLength(outputBuffer(uart)) == UART_BUFFER_SIZE;
	lcall	_outputBuffer
	lcall	_uartBufferLength
	mov	r7,dpl
	clr	a
	cjne	r7,#0x10,00103$
	inc	a
00103$:
	mov	dpl,a
;	uart-hal.c:161: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartInitialise'
;------------------------------------------------------------
;sloc0                     Allocated with name '_uartInitialise_sloc0_1_0'
;------------------------------------------------------------
;	uart-hal.c:168: Timer_Status uartInitialise(Uart uart, uint32_t baudRate, UartBaudRateTimer baudRateTimer, UartMode mode, uint8_t pinSwitch) {
;	-----------------------------------------
;	 function uartInitialise
;	-----------------------------------------
_uartInitialise:
	mov	r7,dpl
;	uart-hal.c:169: Timer_Status rc = TIMER_FREQUENCY_OK;
	mov	r6,#0x00
;	uart-hal.c:174: if (uart != UART1 || mode == UART_8N1) {
	cjne	r7,#0x01,00101$
	mov	r0,#_uartInitialise_PARM_4
	movx	a,@r0
	jnz	00102$
00101$:
;	uart-hal.c:175: Timer timer = (baudRateTimer == UART_USE_TIMER2)
	mov	r0,#_uartInitialise_PARM_3
	movx	a,@r0
	jnz	00134$
	mov	r4,#0x02
	mov	r5,a
	sjmp	00135$
00134$:
	mov	ar4,r7
	mov	r5,#0x00
00135$:
	push	ar7
;	uart-hal.c:182: baudRateToSysclkDivisor(baudRate), 
	mov	r0,#_uartInitialise_PARM_2
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
	push	ar4
	lcall	_baudRateToSysclkDivisor
	mov	r2,dpl
	mov	r3,dph
	mov	r5,b
	mov	r7,a
	pop	ar4
;	uart-hal.c:185: TIMER_FREE_RUNNING
	mov	r0,#_startTimer_PARM_2
	mov	a,r2
	movx	@r0,a
	mov	a,r3
	inc	r0
	movx	@r0,a
	mov	a,r5
	inc	r0
	movx	@r0,a
	mov	a,r7
	inc	r0
	movx	@r0,a
	mov	r0,#_startTimer_PARM_3
	clr	a
	movx	@r0,a
	mov	r0,#_startTimer_PARM_4
	movx	@r0,a
	mov	r0,#_startTimer_PARM_5
	movx	@r0,a
	mov	dpl,r4
	push	ar7
	lcall	_startTimer
	mov	r6,dpl
	pop	ar7
;	uart-hal.c:336: return rc;
	pop	ar7
;	uart-hal.c:185: TIMER_FREE_RUNNING
00102$:
;	uart-hal.c:189: if (rc == TIMER_FREQUENCY_OK) {
	mov	a,r6
	jz	00214$
	ljmp	00131$
00214$:
;	uart-hal.c:190: uartBufferInitialise(inputBuffer(uart));
	mov	dpl,r7
	push	ar7
	push	ar6
	lcall	_inputBuffer
	lcall	_uartBufferInitialise
	pop	ar6
	pop	ar7
;	uart-hal.c:191: uartBufferInitialise(outputBuffer(uart));
	mov	dpl,r7
	push	ar7
	push	ar6
	lcall	_outputBuffer
	lcall	_uartBufferInitialise
	pop	ar6
	pop	ar7
;	uart-hal.c:193: uint8_t operationMode = 0;
	mov	r5,#0x00
;	uart-hal.c:195: switch (mode) {
	mov	r0,#_uartInitialise_PARM_4
	clr	c
	movx	a,@r0
	mov	b,a
	mov	a,#0x03
	subb	a,b
	jc	00113$
	mov	r0,#_uartInitialise_PARM_4
	movx	a,@r0
	mov	b,#0x03
	mul	ab
	mov	dptr,#00216$
	jmp	@a+dptr
00216$:
	ljmp	00104$
	ljmp	00109$
	ljmp	00109$
	ljmp	00109$
;	uart-hal.c:196: case UART_8N1:
00104$:
;	uart-hal.c:197: if (uart == UART1) {
	cjne	r7,#0x01,00113$
;	uart-hal.c:198: operationMode = 1;
	mov	r5,#0x01
;	uart-hal.c:200: break;
;	uart-hal.c:204: case UART_MULTI_MACHINE:
	sjmp	00113$
00109$:
;	uart-hal.c:205: if (uart == UART1) {
	cjne	r7,#0x01,00111$
;	uart-hal.c:206: operationMode = 2 | ((baudRate & 2) >> 1);
	mov	r0,#_uartInitialise_PARM_2
	movx	a,@r0
	mov	r3,a
	inc	r0
	movx	a,@r0
	anl	ar3,#0x02
	clr	a
	clr	c
	rrc	a
	xch	a,r3
	rrc	a
	xch	a,r3
	mov	r4,a
	mov	a,#0x02
	orl	a,r3
	mov	r5,a
	sjmp	00113$
00111$:
;	uart-hal.c:208: operationMode = 1;
	mov	r5,#0x01
;	uart-hal.c:211: }
00113$:
;	uart-hal.c:213: uint8_t scon = ((mode == UART_MULTI_MACHINE) ? M_SM2 : 0)
	mov	r0,#_uartInitialise_PARM_4
	movx	a,@r0
	cjne	a,#0x03,00136$
	mov	r3,#0x20
	mov	r4,#0x00
	sjmp	00137$
00136$:
	mov	r3,#0x00
	mov	r4,#0x00
00137$:
	mov	a,r5
	jnb	acc.1,00138$
	mov	_uartInitialise_sloc0_1_0,#0x80
	mov	(_uartInitialise_sloc0_1_0 + 1),#0x00
	sjmp	00139$
00138$:
	clr	a
	mov	_uartInitialise_sloc0_1_0,a
	mov	(_uartInitialise_sloc0_1_0 + 1),a
00139$:
	mov	a,_uartInitialise_sloc0_1_0
	orl	a,r3
	orl	a,#0x10
	mov	r4,a
;	uart-hal.c:216: switch (uart) {
	cjne	r7,#0x01,00224$
	sjmp	00114$
00224$:
	cjne	r7,#0x02,00225$
	ljmp	00128$
00225$:
	ljmp	00131$
;	uart-hal.c:217: case UART1:
00114$:
;	uart-hal.c:219: switch (operationMode) {
	cjne	r5,#0x01,00226$
	sjmp	00115$
00226$:
	cjne	r5,#0x02,00227$
	sjmp	00119$
00227$:
;	uart-hal.c:220: case 1:
	cjne	r5,#0x03,00127$
	sjmp	00123$
00115$:
;	uart-hal.c:221: if (baudRateTimer == UART_USE_TIMER2) {
	mov	r0,#_uartInitialise_PARM_3
	movx	a,@r0
	jnz	00117$
;	uart-hal.c:222: AUXR |= M_S1ST2;
	orl	_AUXR,#0x01
	sjmp	00127$
00117$:
;	uart-hal.c:224: AUXR &= ~M_S1ST2;
	anl	_AUXR,#0xfe
;	uart-hal.c:226: break;
;	uart-hal.c:228: case 2:
	sjmp	00127$
00119$:
;	uart-hal.c:230: if (baudRate & 1) {
	mov	r0,#_uartInitialise_PARM_2
	movx	a,@r0
	anl	a,#0x01
	jnz	00230$
	inc	r0
	movx	a,@r0
	anl	a,#0x00
	jnz	00230$
	inc	r0
	movx	a,@r0
	anl	a,#0x00
	jnz	00230$
	inc	r0
	movx	a,@r0
	anl	a,#0x00
	jz	00121$
00230$:
;	uart-hal.c:231: PCON |= M_SMOD;
	orl	_PCON,#0x80
	sjmp	00127$
00121$:
;	uart-hal.c:233: PCON &= ~M_SMOD;
	anl	_PCON,#0x7f
;	uart-hal.c:235: break;
;	uart-hal.c:237: case 3:
	sjmp	00127$
00123$:
;	uart-hal.c:239: if (baudRate & 1) {
	mov	r0,#_uartInitialise_PARM_2
	movx	a,@r0
	anl	a,#0x01
	jnz	00231$
	inc	r0
	movx	a,@r0
	anl	a,#0x00
	jnz	00231$
	inc	r0
	movx	a,@r0
	anl	a,#0x00
	jnz	00231$
	inc	r0
	movx	a,@r0
	anl	a,#0x00
	jz	00125$
00231$:
;	uart-hal.c:240: AUXR |= M_UART_M0x6;
	orl	_AUXR,#0x20
	sjmp	00127$
00125$:
;	uart-hal.c:242: AUXR &= ~M_UART_M0x6;
	anl	_AUXR,#0xdf
;	uart-hal.c:245: }
00127$:
;	uart-hal.c:253: UART1_mode = mode;
	mov	r0,#_uartInitialise_PARM_4
	movx	a,@r0
	mov	r0,#_UART1_mode
	movx	@r0,a
;	uart-hal.c:256: S1CON = scon | ((operationMode & 1) ? M_SM1 : 0);
	mov	a,r5
	jnb	acc.0,00140$
	mov	r5,#0x40
	mov	r7,#0x00
	sjmp	00141$
00140$:
	mov	r5,#0x00
	mov	r7,#0x00
00141$:
	mov	a,r5
	orl	a,r4
	mov	_S1CON,a
;	uart-hal.c:259: IE1 |= M_ES1;
	orl	_IE1,#0x10
;	uart-hal.c:260: break;
;	uart-hal.c:263: case UART2:
	sjmp	00131$
00128$:
;	uart-hal.c:268: UART2_mode = mode;
	mov	r0,#_uartInitialise_PARM_4
	movx	a,@r0
	mov	r0,#_UART2_mode
	movx	@r0,a
;	uart-hal.c:280: P_SW1 = (P_SW1 & ~M_S2_S) | ((pinSwitch << P_S2_S) & M_S2_S);
	mov	a,#0xef
	anl	a,_P_SW1
	mov	r7,a
	mov	r0,#_uartInitialise_PARM_5
	movx	a,@r0
	swap	a
	anl	a,#0xf0
	mov	r5,a
	mov	a,#0x10
	anl	a,r5
	orl	a,r7
	mov	_P_SW1,a
;	uart-hal.c:282: S2CON = scon | M_SM1; // Yes, that's not a mistake, see TRM.
	mov	a,#0x40
	orl	a,r4
	mov	_S2CON,a
;	uart-hal.c:286: IE2 |= M_ES2;
	orl	_IE2,#0x01
;	uart-hal.c:333: }
00131$:
;	uart-hal.c:336: return rc;
	mov	dpl,r6
;	uart-hal.c:337: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__uart1_isr'
;------------------------------------------------------------
;	uart-hal.c:339: INTERRUPT_USING(__uart1_isr, UART1_INTERRUPT, 1) CRITICAL {
;	-----------------------------------------
;	 function __uart1_isr
;	-----------------------------------------
___uart1_isr:
	ar7 = 0x0f
	ar6 = 0x0e
	ar5 = 0x0d
	ar4 = 0x0c
	ar3 = 0x0b
	ar2 = 0x0a
	ar1 = 0x09
	ar0 = 0x08
	clr	ea
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x08
;	uart-hal.c:340: if (S1CON & M_TI) {
	mov	a,_S1CON
	jnb	acc.1,00105$
;	uart-hal.c:341: S1CON &= ~M_TI;
	anl	_S1CON,#0xfd
;	uart-hal.c:343: if (uartBufferLength(&UART1_outputBuffer) > 0) {
	mov	dptr,#_UART1_outputBuffer
	mov	b,#0x60
	mov	psw,#0x00
	lcall	_uartBufferLength
	mov	psw,#0x08
	mov	a,dpl
	jz	00102$
;	uart-hal.c:344: S1BUF = uartBufferRead(&UART1_outputBuffer);
	mov	dptr,#_UART1_outputBuffer
	mov	b,#0x60
	mov	psw,#0x00
	lcall	_uartBufferRead
	mov	psw,#0x08
	mov	_S1BUF,dpl
	sjmp	00105$
00102$:
;	uart-hal.c:346: UART1_outputBuffer.busy = 0;
	mov	r0,#(_UART1_outputBuffer + 0x0012)
	clr	a
	movx	@r0,a
00105$:
;	uart-hal.c:350: if (S1CON & M_RI) {
	mov	a,_S1CON
	jnb	acc.0,00108$
;	uart-hal.c:351: S1CON &= ~M_RI;
	anl	_S1CON,#0xfe
;	uart-hal.c:352: uartBufferWrite(&UART1_inputBuffer, S1BUF);
	push	_S1BUF
	mov	dptr,#_UART1_inputBuffer
	mov	b,#0x60
	mov	psw,#0x00
	lcall	_uartBufferWrite
	mov	psw,#0x08
	dec	sp
00108$:
;	uart-hal.c:354: }
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	setb	ea
	reti
;------------------------------------------------------------
;Allocation info for local variables in function '__uart2_isr'
;------------------------------------------------------------
;	uart-hal.c:357: INTERRUPT_USING(__uart2_isr, UART2_INTERRUPT, 1) CRITICAL {
;	-----------------------------------------
;	 function __uart2_isr
;	-----------------------------------------
___uart2_isr:
	clr	ea
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x08
;	uart-hal.c:358: if (S2CON & M_TI) {
	mov	a,_S2CON
	jnb	acc.1,00105$
;	uart-hal.c:359: S2CON &= ~M_TI;
	anl	_S2CON,#0xfd
;	uart-hal.c:361: if (uartBufferLength(&UART2_outputBuffer) > 0) {
	mov	dptr,#_UART2_outputBuffer
	mov	b,#0x60
	mov	psw,#0x00
	lcall	_uartBufferLength
	mov	psw,#0x08
	mov	a,dpl
	jz	00102$
;	uart-hal.c:362: S2BUF = uartBufferRead(&UART2_outputBuffer);
	mov	dptr,#_UART2_outputBuffer
	mov	b,#0x60
	mov	psw,#0x00
	lcall	_uartBufferRead
	mov	psw,#0x08
	mov	_S2BUF,dpl
	sjmp	00105$
00102$:
;	uart-hal.c:364: UART2_outputBuffer.busy = 0;
	mov	r0,#(_UART2_outputBuffer + 0x0012)
	clr	a
	movx	@r0,a
00105$:
;	uart-hal.c:368: if (S2CON & M_RI) {
	mov	a,_S2CON
	jnb	acc.0,00108$
;	uart-hal.c:369: S2CON &= ~M_RI;
	anl	_S2CON,#0xfe
;	uart-hal.c:370: uartBufferWrite(&UART2_inputBuffer, S2BUF);
	push	_S2BUF
	mov	dptr,#_UART2_inputBuffer
	mov	b,#0x60
	mov	psw,#0x00
	lcall	_uartBufferWrite
	mov	psw,#0x08
	dec	sp
00108$:
;	uart-hal.c:372: }
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	setb	ea
	reti
;------------------------------------------------------------
;Allocation info for local variables in function 'uartGetCharacter'
;------------------------------------------------------------
;	uart-hal.c:412: uint8_t uartGetCharacter(Uart uart) {
;	-----------------------------------------
;	 function uartGetCharacter
;	-----------------------------------------
_uartGetCharacter:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
;	uart-hal.c:413: uint8_t result = 0;
	mov	r7,#0x00
;	uart-hal.c:414: UartBuffer *buffer = inputBuffer(uart);
	push	ar7
	lcall	_inputBuffer
;	uart-hal.c:416: if (uartBufferLength(buffer) > 0) {
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	push	ar6
	push	ar5
	push	ar4
	lcall	_uartBufferLength
	mov	a,dpl
	pop	ar4
	pop	ar5
	pop	ar6
	pop	ar7
	jz	00102$
;	uart-hal.c:417: result = uartBufferRead(buffer);
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	_uartBufferRead
	mov	r7,dpl
00102$:
;	uart-hal.c:420: return result;
	mov	dpl,r7
;	uart-hal.c:421: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'uartSendCharacter'
;------------------------------------------------------------
;	uart-hal.c:423: uint8_t uartSendCharacter(Uart uart, uint8_t c) {
;	-----------------------------------------
;	 function uartSendCharacter
;	-----------------------------------------
_uartSendCharacter:
	mov	a,dpl
	mov	r0,#_uartSendCharacter_uart_65536_97
	movx	@r0,a
;	uart-hal.c:424: UartBuffer *buffer = outputBuffer(uart);
	mov	r0,#_uartSendCharacter_uart_65536_97
	movx	a,@r0
	mov	dpl,a
	lcall	_outputBuffer
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
;	uart-hal.c:425: uint8_t result = uartBufferWrite(buffer, c);
	push	ar6
	push	ar5
	push	ar4
	mov	r0,#_uartSendCharacter_PARM_2
	movx	a,@r0
	push	acc
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	_uartBufferWrite
	mov	r0,#_uartSendCharacter_result_65536_98
	mov	a,dpl
	movx	@r0,a
	dec	sp
	pop	ar4
	pop	ar5
	pop	ar6
;	uart-hal.c:427: if (uartBufferLength(buffer) > 0 && !buffer->busy) {
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	push	ar6
	push	ar5
	push	ar4
	lcall	_uartBufferLength
	mov	a,dpl
	pop	ar4
	pop	ar5
	pop	ar6
	jz	00105$
	mov	a,#0x12
	add	a,r4
	mov	r2,a
	clr	a
	addc	a,r5
	mov	r3,a
	mov	ar7,r6
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	lcall	__gptrget
	jnz	00105$
;	uart-hal.c:428: buffer->busy = 1;
	mov	dpl,r2
	mov	dph,r3
	mov	b,r7
	mov	a,#0x01
	lcall	__gptrput
;	uart-hal.c:430: switch (uart) {
	mov	r0,#_uartSendCharacter_uart_65536_97
	movx	a,@r0
	cjne	a,#0x01,00127$
	sjmp	00101$
00127$:
	mov	r0,#_uartSendCharacter_uart_65536_97
	movx	a,@r0
;	uart-hal.c:431: case UART1:
	cjne	a,#0x02,00105$
	sjmp	00102$
00101$:
;	uart-hal.c:432: S1BUF = uartBufferRead(buffer);
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	_uartBufferRead
	mov	_S1BUF,dpl
;	uart-hal.c:433: break;
;	uart-hal.c:436: case UART2:
	sjmp	00105$
00102$:
;	uart-hal.c:437: S2BUF = uartBufferRead(buffer);
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	_uartBufferRead
	mov	_S2BUF,dpl
;	uart-hal.c:450: }
00105$:
;	uart-hal.c:453: return result;
	mov	r0,#_uartSendCharacter_result_65536_98
	movx	a,@r0
	mov	dpl,a
;	uart-hal.c:454: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
