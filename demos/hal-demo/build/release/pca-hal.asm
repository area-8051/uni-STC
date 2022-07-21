;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.2.0 #13081 (Linux)
;--------------------------------------------------------
	.module pca_hal
	.optsdcc -mmcs51 --model-medium
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _pcaOnInterrupt
	.globl _gpioConfigure
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
	.globl _pcaStartTimer_PARM_4
	.globl _pcaStartTimer_PARM_3
	.globl _pcaStartTimer_PARM_2
	.globl _pcaSetPwmDutyCycle_PARM_2
	.globl _pcaStartPwm_PARM_5
	.globl _pcaStartPwm_PARM_4
	.globl _pcaStartPwm_PARM_3
	.globl _pcaStartPwm_PARM_2
	.globl _pcaStartCapture_PARM_5
	.globl _pcaStartCapture_PARM_4
	.globl _pcaStartCapture_PARM_3
	.globl _pcaStartCapture_PARM_2
	.globl _pcaInitialise_PARM_4
	.globl _pcaInitialise_PARM_3
	.globl _pcaInitialise_PARM_2
	.globl _pcaInitialise
	.globl _pcaStartCapture
	.globl _pcaStartPwm
	.globl _pcaSetPwmDutyCycle
	.globl _pcaStartTimer
	.globl ___pca_isr
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
___pca_isr_sloc0_1_0:
	.ds 4
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
___pcaConfigurePWM_sloc0_1_0:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
___pca_pinConfigurations:
	.ds 6
___pca_pinSwitch:
	.ds 1
___pca_captureStartCount:
	.ds 8
___pca_captureEndCount:
	.ds 8
___pca_timerPeriod:
	.ds 4
___pca_timerValue:
	.ds 4
___pca_captureOverflowCounter:
	.ds 2
___pca_captureShiftBits:
	.ds 2
___pca_captureMode:
	.ds 2
___pca_channelMode:
	.ds 2
___pca_configureChannelOutput_PARM_2:
	.ds 1
___pca_configureChannelOutput_pinConfig_65536_12:
	.ds 6
_pcaInitialise_PARM_2:
	.ds 1
_pcaInitialise_PARM_3:
	.ds 1
_pcaInitialise_PARM_4:
	.ds 1
_pcaStartCapture_PARM_2:
	.ds 1
_pcaStartCapture_PARM_3:
	.ds 1
_pcaStartCapture_PARM_4:
	.ds 1
_pcaStartCapture_PARM_5:
	.ds 1
___pcaConfigurePWM_PARM_2:
	.ds 1
___pcaConfigurePWM_PARM_3:
	.ds 1
___pcaConfigurePWM_PARM_4:
	.ds 1
___pcaConfigurePWM_PARM_5:
	.ds 1
___pcaConfigurePWM_PARM_6:
	.ds 2
_pcaStartPwm_PARM_2:
	.ds 1
_pcaStartPwm_PARM_3:
	.ds 1
_pcaStartPwm_PARM_4:
	.ds 1
_pcaStartPwm_PARM_5:
	.ds 2
_pcaSetPwmDutyCycle_PARM_2:
	.ds 2
_pcaStartTimer_PARM_2:
	.ds 1
_pcaStartTimer_PARM_3:
	.ds 1
_pcaStartTimer_PARM_4:
	.ds 2
___pca_isr_ccaph_65536_44:
	.ds 1
___pca_isr_channel_65536_44:
	.ds 1
___pca_isr_width_65536_44:
	.ds 4
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
;	pca-hal.c:39: static uint8_t __pca_pinConfigurations[][PCA_CHANNELS + 1] = {
	mov	r0,#___pca_pinConfigurations
	mov	a,#0x13
	movx	@r0,a
	mov	r0,#(___pca_pinConfigurations + 0x0001)
	inc	a
	movx	@r0,a
	mov	r0,#(___pca_pinConfigurations + 0x0002)
	mov	a,#0x12
	movx	@r0,a
	mov	r0,#(___pca_pinConfigurations + 0x0003)
	mov	a,#0x42
	movx	@r0,a
	mov	r0,#(___pca_pinConfigurations + 0x0004)
	inc	a
	movx	@r0,a
	mov	r0,#(___pca_pinConfigurations + 0x0005)
	mov	a,#0x41
	movx	@r0,a
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
;Allocation info for local variables in function '__pca_configureChannelOutput'
;------------------------------------------------------------
;	pca-hal.c:127: static void __pca_configureChannelOutput(PCA_Channel channel, GpioPortMode pinMode) {
;	-----------------------------------------
;	 function __pca_configureChannelOutput
;	-----------------------------------------
___pca_configureChannelOutput:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7,dpl
;	pca-hal.c:128: uint8_t channelPin = __pca_pinConfigurations[__pca_pinSwitch][channel];
	mov	r0,#___pca_pinSwitch
	movx	a,@r0
	mov	b,#0x03
	mul	ab
	add	a,#___pca_pinConfigurations
	add	a,r7
	mov	r1,a
	movx	a,@r1
;	pca-hal.c:129: GpioPort port = (GpioPort) (channelPin >> 4);
	mov	r7,a
	swap	a
	anl	a,#0x0f
	mov	r6,a
;	pca-hal.c:130: GpioPin pin = (GpioPin) (channelPin & 0x0f);
	anl	ar7,#0x0f
;	pca-hal.c:131: GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, pinMode);
	mov	r0,#___pca_configureChannelOutput_pinConfig_65536_12
	mov	a,r6
	movx	@r0,a
	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0001)
	mov	a,r7
	movx	@r0,a
	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0002)
	mov	a,#0x01
	movx	@r0,a
	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0003)
	mov	r1,#___pca_configureChannelOutput_PARM_2
	movx	a,@r1
	movx	@r0,a
	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0004)
	clr	a
	movx	@r0,a
	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0005)
	movx	@r0,a
;	pca-hal.c:132: gpioConfigure(&pinConfig);
	mov	dptr,#___pca_configureChannelOutput_pinConfig_65536_12
	mov	b,#0x60
;	pca-hal.c:133: }
	ljmp	_gpioConfigure
;------------------------------------------------------------
;Allocation info for local variables in function 'pcaInitialise'
;------------------------------------------------------------
;	pca-hal.c:149: void pcaInitialise(PCA_ClockSource clockSource, PCA_CounterMode counterMode, PCA_InterruptEnable overflowInterrupt, uint8_t pinSwitch) {
;	-----------------------------------------
;	 function pcaInitialise
;	-----------------------------------------
_pcaInitialise:
	mov	r7,dpl
;	pca-hal.c:150: __pca_pinSwitch = pinSwitch;
	mov	r0,#_pcaInitialise_PARM_4
	movx	a,@r0
	mov	r6,a
	mov	r0,#___pca_pinSwitch
	movx	@r0,a
;	pca-hal.c:151: P_SW1 = (P_SW1 & ~M_CCP_S) | ((pinSwitch << P_CCP_S) & M_CCP_S);
	mov	a,#0xbf
	anl	a,_P_SW1
	mov	r5,a
	mov	a,r6
	rr	a
	rr	a
	anl	a,#0xc0
	mov	r6,a
	mov	a,#0x40
	anl	a,r6
	orl	a,r5
	mov	_P_SW1,a
;	pca-hal.c:153: for (uint8_t channel = 0; channel < PCA_CHANNELS; channel++) {
	mov	r6,#0x00
00103$:
	cjne	r6,#0x02,00116$
00116$:
	jnc	00101$
;	pca-hal.c:154: __pca_channelMode[channel] = PCA_UNUSED;
	mov	a,r6
	add	a,#___pca_channelMode
	mov	r0,a
	clr	a
	movx	@r0,a
;	pca-hal.c:153: for (uint8_t channel = 0; channel < PCA_CHANNELS; channel++) {
	inc	r6
	sjmp	00103$
00101$:
;	pca-hal.c:157: CMOD = (counterMode << P_CIDL) | (clockSource << P_CPS) | (overflowInterrupt << P_ECF);
	mov	r0,#_pcaInitialise_PARM_2
	movx	a,@r0
	rr	a
	anl	a,#0x80
	mov	r6,a
	mov	a,r7
	add	a,r7
	orl	ar6,a
	mov	r0,#_pcaInitialise_PARM_3
	movx	a,@r0
	orl	a,r6
	mov	_CMOD,a
;	pca-hal.c:158: CCON = 0;
;	pca-hal.c:159: PCA_CTR = 0;
	clr	a
	mov	_CCON,a
	mov	((_PCA_CTR >> 0) & 0xFF),a
	mov	((_PCA_CTR >> 8) & 0xFF),a
;	pca-hal.c:160: CR = 1;
;	assignBit
	setb	_CR
;	pca-hal.c:161: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'pcaStartCapture'
;------------------------------------------------------------
;	pca-hal.c:163: void pcaStartCapture(PCA_Channel channel, GpioPortMode pinMode, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits) {
;	-----------------------------------------
;	 function pcaStartCapture
;	-----------------------------------------
_pcaStartCapture:
	mov	r7,dpl
;	pca-hal.c:164: CR = 0;
;	assignBit
	clr	_CR
;	pca-hal.c:165: __pca_configureChannelOutput(channel, pinMode);
	mov	r0,#_pcaStartCapture_PARM_2
	mov	r1,#___pca_configureChannelOutput_PARM_2
	movx	a,@r0
	movx	@r1,a
	mov	dpl,r7
	push	ar7
	lcall	___pca_configureChannelOutput
	pop	ar7
;	pca-hal.c:167: __pca_captureOverflowCounter[channel] = 0;
	mov	a,r7
	add	a,#___pca_captureOverflowCounter
	mov	r0,a
	clr	a
	movx	@r0,a
;	pca-hal.c:168: __pca_captureStartCount[channel].count = 0;
	mov	a,r7
	add	a,r7
	add	a,acc
	mov	r6,a
	add	a,#___pca_captureStartCount
	mov	r1,a
	clr	a
	movx	@r1,a
	inc	r1
	movx	@r1,a
	inc	r1
	movx	@r1,a
	inc	r1
	movx	@r1,a
;	pca-hal.c:169: __pca_captureEndCount[channel].count = 0;
	mov	a,r6
	add	a,#___pca_captureEndCount
	mov	r1,a
	clr	a
	movx	@r1,a
	inc	r1
	movx	@r1,a
	inc	r1
	movx	@r1,a
	inc	r1
	movx	@r1,a
;	pca-hal.c:170: __pca_captureShiftBits[channel] = shiftBits;
	mov	a,r7
	add	a,#___pca_captureShiftBits
	mov	r0,a
	mov	r1,#_pcaStartCapture_PARM_5
	movx	a,@r1
	movx	@r0,a
;	pca-hal.c:171: __pca_captureMode[channel] = captureMode;
	mov	a,r7
	add	a,#___pca_captureMode
	mov	r0,a
	mov	r1,#_pcaStartCapture_PARM_4
	movx	a,@r1
	movx	@r0,a
;	pca-hal.c:172: __pca_channelMode[channel] = PCA_CAPTURE;
	mov	a,r7
	add	a,#___pca_channelMode
	mov	r0,a
	mov	a,#0x40
	movx	@r0,a
;	pca-hal.c:174: uint8_t ccapMode = __pca_ccapMode(PCA_CAPTURE, trigger);
	mov	r0,#_pcaStartCapture_PARM_3
	movx	a,@r0
	mov	r6,a
	mov	r5,a
	mov	a,r5
	swap	a
	anl	a,#0xf0
	mov	r5,a
	orl	ar5,#0x40
	mov	a,r6
	jz	00107$
	mov	r4,#0x01
	mov	r6,#0x00
	sjmp	00108$
00107$:
	mov	r4,#0x00
	mov	r6,#0x00
00108$:
	mov	a,r4
	orl	a,r5
	mov	r6,a
;	pca-hal.c:176: switch (channel) {
	cjne	r7,#0x00,00122$
	sjmp	00101$
00122$:
;	pca-hal.c:177: case PCA_CHANNEL0:
	cjne	r7,#0x01,00103$
	sjmp	00102$
00101$:
;	pca-hal.c:178: CCAPM0 = ccapMode;
	mov	_CCAPM0,r6
;	pca-hal.c:179: CCAP0 = 0;
	clr	a
	mov	((_CCAP0 >> 0) & 0xFF),a
	mov	((_CCAP0 >> 8) & 0xFF),a
;	pca-hal.c:180: break;
;	pca-hal.c:183: case PCA_CHANNEL1:
	sjmp	00103$
00102$:
;	pca-hal.c:184: CCAPM1 = ccapMode;
	mov	_CCAPM1,r6
;	pca-hal.c:185: CCAP1 = 0;
	clr	a
	mov	((_CCAP1 >> 0) & 0xFF),a
	mov	((_CCAP1 >> 8) & 0xFF),a
;	pca-hal.c:210: }
00103$:
;	pca-hal.c:212: PCA_CTR = 0;
	clr	a
	mov	((_PCA_CTR >> 0) & 0xFF),a
	mov	((_PCA_CTR >> 8) & 0xFF),a
;	pca-hal.c:213: CR = 1;
;	assignBit
	setb	_CR
;	pca-hal.c:214: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__pcaConfigurePWM'
;------------------------------------------------------------
;	pca-hal.c:220: static void __pcaConfigurePWM(uint8_t initialise, PCA_Channel channel, GpioPortMode pinMode, PCA_PWM_Bits pwmBits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
;	-----------------------------------------
;	 function __pcaConfigurePWM
;	-----------------------------------------
___pcaConfigurePWM:
	mov	r7,dpl
;	pca-hal.c:221: __pca_channelMode[channel] = PCA_PWM;
	mov	r0,#___pcaConfigurePWM_PARM_2
	movx	a,@r0
	add	a,#___pca_channelMode
	mov	r0,a
	mov	a,#0x42
	movx	@r0,a
;	pca-hal.c:290: uint16_t reloadValue = maxValue - ((clocksHigh >= maxValue) ? (maxValue - 1) : clocksHigh);
	mov	r0,#___pcaConfigurePWM_PARM_6
	clr	c
	inc	r0
	movx	a,@r0
	subb	a,#0x01
	mov	___pcaConfigurePWM_sloc0_1_0,c
	jc	00111$
	mov	r5,#0xff
	mov	r6,#0x00
	sjmp	00112$
00111$:
	mov	r0,#___pcaConfigurePWM_PARM_6
	movx	a,@r0
	mov	r5,a
	inc	r0
	movx	a,@r0
	mov	r6,a
00112$:
	clr	a
	clr	c
	subb	a,r5
	mov	r5,a
	mov	a,#0x01
	subb	a,r6
;	pca-hal.c:291: uint8_t xccap = (reloadValue >> 8) & 3;
;	pca-hal.c:292: uint8_t ccap = reloadValue;
;	pca-hal.c:296: uint8_t pcaPwm = (bits << P_EBS) | (xccap << P_XCCAPH) | (xccap << P_XCCAPL);
	anl	a,#0x03
	mov	r4,a
	swap	a
	anl	a,#0xf0
	mov	r6,a
	mov	a,r4
	add	a,r4
	add	a,acc
	orl	ar6,a
;	pca-hal.c:297: uint8_t ccapMode = __pca_ccapMode(PCA_PWM, interruptTrigger);
	mov	r0,#___pcaConfigurePWM_PARM_5
	movx	a,@r0
	mov	r4,a
	mov	r3,a
	mov	a,r3
	swap	a
	anl	a,#0xf0
	mov	r3,a
	orl	ar3,#0x42
	mov	a,r4
	jz	00113$
	mov	r2,#0x01
	mov	r4,#0x00
	sjmp	00114$
00113$:
	mov	r2,#0x00
	mov	r4,#0x00
00114$:
	mov	a,r2
	orl	a,r3
	mov	r4,a
;	pca-hal.c:299: switch (channel) {
	mov	r0,#___pcaConfigurePWM_PARM_2
	movx	a,@r0
	jz	00101$
	mov	r0,#___pcaConfigurePWM_PARM_2
	movx	a,@r0
;	pca-hal.c:300: case PCA_CHANNEL0:
	cjne	a,#0x01,00109$
	sjmp	00104$
00101$:
;	pca-hal.c:301: PCA_PWM0 = pcaPwm;
	mov	_PCA_PWM0,r6
;	pca-hal.c:303: if (initialise) {
	mov	a,r7
	jz	00103$
;	pca-hal.c:304: CCAPM0 = ccapMode;
	mov	_CCAPM0,r4
;	pca-hal.c:305: CCAP0L = ccap;
	mov	_CCAP0L,r5
00103$:
;	pca-hal.c:308: CCAP0H = ccap;
	mov	_CCAP0H,r5
;	pca-hal.c:309: break;
;	pca-hal.c:312: case PCA_CHANNEL1:
	ret
00104$:
;	pca-hal.c:313: PCA_PWM1 = pcaPwm;
	mov	_PCA_PWM1,r6
;	pca-hal.c:315: if (initialise) {
	mov	a,r7
	jz	00106$
;	pca-hal.c:316: CCAPM1 = ccapMode;
	mov	_CCAPM1,r4
;	pca-hal.c:317: CCAP1L = ccap;
	mov	_CCAP1L,r5
00106$:
;	pca-hal.c:320: CCAP1H = ccap;
	mov	_CCAP1H,r5
;	pca-hal.c:357: }
00109$:
;	pca-hal.c:358: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'pcaStartPwm'
;------------------------------------------------------------
;	pca-hal.c:360: void pcaStartPwm(PCA_Channel channel, GpioPortMode pinMode, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
;	-----------------------------------------
;	 function pcaStartPwm
;	-----------------------------------------
_pcaStartPwm:
	mov	r7,dpl
;	pca-hal.c:361: __pcaConfigurePWM(1, channel, pinMode, bits, interruptTrigger, clocksHigh);
	mov	r0,#___pcaConfigurePWM_PARM_2
	mov	a,r7
	movx	@r0,a
	mov	r0,#_pcaStartPwm_PARM_2
	mov	r1,#___pcaConfigurePWM_PARM_3
	movx	a,@r0
	movx	@r1,a
	mov	r0,#_pcaStartPwm_PARM_3
	mov	r1,#___pcaConfigurePWM_PARM_4
	movx	a,@r0
	movx	@r1,a
	mov	r0,#_pcaStartPwm_PARM_4
	mov	r1,#___pcaConfigurePWM_PARM_5
	movx	a,@r0
	movx	@r1,a
	mov	r0,#_pcaStartPwm_PARM_5
	mov	r1,#___pcaConfigurePWM_PARM_6
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,#0x01
;	pca-hal.c:362: }
	ljmp	___pcaConfigurePWM
;------------------------------------------------------------
;Allocation info for local variables in function 'pcaSetPwmDutyCycle'
;------------------------------------------------------------
;	pca-hal.c:364: void pcaSetPwmDutyCycle(PCA_Channel channel, uint16_t clocksHigh) {
;	-----------------------------------------
;	 function pcaSetPwmDutyCycle
;	-----------------------------------------
_pcaSetPwmDutyCycle:
	mov	r7,dpl
;	pca-hal.c:365: __pcaConfigurePWM(0, channel, GPIO_BIDIRECTIONAL, 0, PCA_EDGE_NONE, clocksHigh);
	mov	r0,#___pcaConfigurePWM_PARM_2
	mov	a,r7
	movx	@r0,a
	mov	r0,#___pcaConfigurePWM_PARM_3
	clr	a
	movx	@r0,a
	mov	r0,#___pcaConfigurePWM_PARM_4
	movx	@r0,a
	mov	r0,#___pcaConfigurePWM_PARM_5
	movx	@r0,a
	mov	r0,#_pcaSetPwmDutyCycle_PARM_2
	mov	r1,#___pcaConfigurePWM_PARM_6
	movx	a,@r0
	movx	@r1,a
	inc	r0
	movx	a,@r0
	inc	r1
	movx	@r1,a
	mov	dpl,#0x00
;	pca-hal.c:366: }
	ljmp	___pcaConfigurePWM
;------------------------------------------------------------
;Allocation info for local variables in function 'pcaStartTimer'
;------------------------------------------------------------
;	pca-hal.c:368: void pcaStartTimer(PCA_Channel channel, GpioPortMode pinMode, PCA_OutputEnable pulseOutput, uint16_t timerPeriod) {
;	-----------------------------------------
;	 function pcaStartTimer
;	-----------------------------------------
_pcaStartTimer:
	mov	r7,dpl
;	pca-hal.c:369: __pca_configureChannelOutput(channel, pinMode);
	mov	r0,#_pcaStartTimer_PARM_2
	mov	r1,#___pca_configureChannelOutput_PARM_2
	movx	a,@r0
	movx	@r1,a
	mov	dpl,r7
	push	ar7
	lcall	___pca_configureChannelOutput
	pop	ar7
;	pca-hal.c:371: __pca_timerPeriod[channel] = timerPeriod;
	mov	a,r7
	add	a,r7
	mov	r6,a
	add	a,#___pca_timerPeriod
	mov	r0,a
	mov	r1,#_pcaStartTimer_PARM_4
	movx	a,@r1
	movx	@r0,a
	inc	r0
	inc	r1
	movx	a,@r1
	movx	@r0,a
;	pca-hal.c:372: __pca_timerValue[channel] = __pca_timerPeriod[channel];
	mov	a,r6
	add	a,#___pca_timerValue
	mov	r1,a
	mov	r0,#_pcaStartTimer_PARM_4
	movx	a,@r0
	movx	@r1,a
	inc	r1
	inc	r0
	movx	a,@r0
	movx	@r1,a
	dec	r1
;	pca-hal.c:373: uint8_t ccapMode = (pulseOutput == PCA_OUTPUT_ENABLE) ? PCA_PULSE : PCA_TIMER;
	mov	r0,#_pcaStartTimer_PARM_3
	movx	a,@r0
	cjne	a,#0x01,00106$
	mov	r5,#0x4d
	mov	r6,#0x00
	sjmp	00107$
00106$:
	mov	r5,#0x49
	mov	r6,#0x00
00107$:
;	pca-hal.c:374: __pca_channelMode[channel] = ccapMode;
	mov	a,r7
	add	a,#___pca_channelMode
	mov	r0,a
	mov	a,r5
	movx	@r0,a
;	pca-hal.c:376: switch (channel) {
	cjne	r7,#0x00,00122$
	sjmp	00101$
00122$:
;	pca-hal.c:377: case PCA_CHANNEL0:
	cjne	r7,#0x01,00104$
	sjmp	00102$
00101$:
;	pca-hal.c:378: CCAPM0 = ccapMode;
	mov	_CCAPM0,r5
;	pca-hal.c:379: CCAP0 = __pca_timerValue[channel];
	movx	a,@r1
	mov	r6,a
	inc	r1
	movx	a,@r1
	mov	r7,a
	dec	r1
	mov	((_CCAP0 >> 0) & 0xFF),r6
	mov	((_CCAP0 >> 8) & 0xFF),r7
;	pca-hal.c:380: break;
;	pca-hal.c:383: case PCA_CHANNEL1:
	ret
00102$:
;	pca-hal.c:384: CCAPM1 = ccapMode;
	mov	_CCAPM1,r5
;	pca-hal.c:385: CCAP1 = __pca_timerValue[channel];
	movx	a,@r1
	mov	r6,a
	inc	r1
	movx	a,@r1
	mov	r7,a
	mov	((_CCAP1 >> 0) & 0xFF),r6
	mov	((_CCAP1 >> 8) & 0xFF),r7
;	pca-hal.c:410: }
00104$:
;	pca-hal.c:411: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function '__pca_isr'
;------------------------------------------------------------
;sloc0                     Allocated with name '___pca_isr_sloc0_1_0'
;------------------------------------------------------------
;	pca-hal.c:413: INTERRUPT_USING(__pca_isr, PCA_INTERRUPT, 1) CRITICAL {
;	-----------------------------------------
;	 function __pca_isr
;	-----------------------------------------
___pca_isr:
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
	push	psw
	mov	psw,#0x08
;	pca-hal.c:414: uint8_t ccapl = 0;
	mov	r5,#0x00
;	pca-hal.c:415: uint8_t ccaph = 0;
	mov	r0,#___pca_isr_ccaph_65536_44
	clr	a
	movx	@r0,a
;	pca-hal.c:416: uint8_t channel = HAL_PCA_CHANNELS;
	mov	r0,#___pca_isr_channel_65536_44
	mov	a,#0x02
	movx	@r0,a
;	pca-hal.c:420: if (CF) {
;	pca-hal.c:421: CF = 0;
;	assignBit
	jbc	_CF,00193$
	sjmp	00102$
00193$:
;	pca-hal.c:422: __pca_captureOverflowCounter[PCA_CHANNEL0]++;
	mov	r0,#___pca_captureOverflowCounter
	movx	a,@r0
	inc	a
	mov	r0,#___pca_captureOverflowCounter
	movx	@r0,a
;	pca-hal.c:425: __pca_captureOverflowCounter[PCA_CHANNEL1]++;
	mov	r0,#(___pca_captureOverflowCounter + 0x0001)
	movx	a,@r0
	mov	r4,a
	inc	a
	mov	r0,#(___pca_captureOverflowCounter + 0x0001)
	movx	@r0,a
00102$:
;	pca-hal.c:437: if (CCF0) {
;	pca-hal.c:438: CCF0 = 0;
;	assignBit
	jbc	_CCF0,00194$
	sjmp	00110$
00194$:
;	pca-hal.c:439: channel = PCA_CHANNEL0;
	mov	r0,#___pca_isr_channel_65536_44
	clr	a
	movx	@r0,a
;	pca-hal.c:441: switch (__pca_channelMode[channel]) {
	mov	r0,#___pca_channelMode
	movx	a,@r0
	mov	r4,a
	cjne	r4,#0x40,00195$
	sjmp	00103$
00195$:
	cjne	r4,#0x49,00196$
	sjmp	00107$
00196$:
;	pca-hal.c:442: case PCA_CAPTURE:
	cjne	r4,#0x4d,00110$
	sjmp	00107$
00103$:
;	pca-hal.c:443: ccapl = CCAP0L;
	mov	r5,_CCAP0L
;	pca-hal.c:444: ccaph = CCAP0H;
	mov	r0,#___pca_isr_ccaph_65536_44
	mov	a,_CCAP0H
	movx	@r0,a
;	pca-hal.c:446: if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
	mov	r0,#___pca_captureMode
	movx	a,@r0
	mov	r4,a
	cjne	r4,#0x01,00110$
;	pca-hal.c:447: CCAPM0 = 0;
	mov	_CCAPM0,#0x00
;	pca-hal.c:448: __pca_channelMode[channel] = PCA_UNUSED;
	mov	r0,#___pca_channelMode
	clr	a
	movx	@r0,a
;	pca-hal.c:450: break;
;	pca-hal.c:453: case PCA_PULSE:
	sjmp	00110$
00107$:
;	pca-hal.c:454: __pca_timerValue[channel] += __pca_timerPeriod[channel];
	mov	r0,#___pca_timerValue
	movx	a,@r0
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r4,a
	mov	r0,#___pca_timerPeriod
	movx	a,@r0
	mov	r2,a
	inc	r0
	movx	a,@r0
	mov	r6,a
	mov	a,r2
	add	a,r3
	mov	r3,a
	mov	a,r6
	addc	a,r4
	mov	r4,a
	mov	r0,#___pca_timerValue
	mov	a,r3
	movx	@r0,a
	inc	r0
	mov	a,r4
	movx	@r0,a
;	pca-hal.c:455: CCAP0 = __pca_timerValue[channel];
	mov	((_CCAP0 >> 0) & 0xFF),r3
	mov	((_CCAP0 >> 8) & 0xFF),r4
;	pca-hal.c:563: }
;	pca-hal.c:457: }
00110$:
;	pca-hal.c:461: if (CCF1) {
;	pca-hal.c:462: CCF1 = 0;
;	assignBit
	jbc	_CCF1,00200$
	sjmp	00118$
00200$:
;	pca-hal.c:463: channel = PCA_CHANNEL1;
	mov	r0,#___pca_isr_channel_65536_44
	mov	a,#0x01
	movx	@r0,a
;	pca-hal.c:465: switch (__pca_channelMode[channel]) {
	mov	r0,#(___pca_channelMode + 0x0001)
	movx	a,@r0
	mov	r4,a
	cjne	r4,#0x40,00201$
	sjmp	00111$
00201$:
	cjne	r4,#0x49,00202$
	sjmp	00115$
00202$:
;	pca-hal.c:466: case PCA_CAPTURE:
	cjne	r4,#0x4d,00118$
	sjmp	00115$
00111$:
;	pca-hal.c:467: ccapl = CCAP1L;
	mov	r5,_CCAP1L
;	pca-hal.c:468: ccaph = CCAP1H;
	mov	r0,#___pca_isr_ccaph_65536_44
	mov	a,_CCAP1H
	movx	@r0,a
;	pca-hal.c:470: if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
	mov	r0,#(___pca_captureMode + 0x0001)
	movx	a,@r0
	mov	r4,a
	cjne	r4,#0x01,00118$
;	pca-hal.c:471: CCAPM1 = 0;
	mov	_CCAPM1,#0x00
;	pca-hal.c:472: __pca_channelMode[channel] = PCA_UNUSED;
	mov	r0,#(___pca_channelMode + 0x0001)
	clr	a
	movx	@r0,a
;	pca-hal.c:474: break;
;	pca-hal.c:477: case PCA_PULSE:
	sjmp	00118$
00115$:
;	pca-hal.c:478: __pca_timerValue[channel] += __pca_timerPeriod[channel];
	mov	r0,#(___pca_timerValue + 0x0002)
	movx	a,@r0
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r4,a
	mov	r0,#(___pca_timerPeriod + 0x0002)
	movx	a,@r0
	mov	r2,a
	inc	r0
	movx	a,@r0
	mov	r6,a
	mov	a,r2
	add	a,r3
	mov	r3,a
	mov	a,r6
	addc	a,r4
	mov	r4,a
	mov	r0,#(___pca_timerValue + 0x0002)
	mov	a,r3
	movx	@r0,a
	inc	r0
	mov	a,r4
	movx	@r0,a
;	pca-hal.c:479: CCAP1 = __pca_timerValue[channel];
	mov	((_CCAP1 >> 0) & 0xFF),r3
	mov	((_CCAP1 >> 8) & 0xFF),r4
;	pca-hal.c:563: }
;	pca-hal.c:481: }
00118$:
;	pca-hal.c:543: if (channel < HAL_PCA_CHANNELS) {
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	cjne	a,#0x02,00206$
00206$:
	jc	00207$
	ljmp	00125$
00207$:
;	pca-hal.c:544: switch (__pca_channelMode[channel]) {
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	add	a,#___pca_channelMode
	mov	r1,a
	movx	a,@r1
	mov	r4,a
	cjne	r4,#0x40,00208$
	sjmp	00119$
00208$:
	cjne	r4,#0x42,00209$
	ljmp	00121$
00209$:
	cjne	r4,#0x49,00210$
	ljmp	00121$
00210$:
	ljmp	00125$
;	pca-hal.c:545: case PCA_CAPTURE:
00119$:
;	pca-hal.c:546: __pca_captureStartCount[channel].count = __pca_captureEndCount[channel].count;
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	add	a,acc
	add	a,acc
	mov	r4,a
	add	a,#___pca_captureStartCount
	mov	r1,a
	mov	a,r4
	add	a,#___pca_captureEndCount
	mov	r0,a
	movx	a,@r0
	mov	r2,a
	inc	r0
	movx	a,@r0
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r6,a
	inc	r0
	movx	a,@r0
	mov	r7,a
	mov	a,r2
	movx	@r1,a
	inc	r1
	mov	a,r3
	movx	@r1,a
	inc	r1
	mov	a,r6
	movx	@r1,a
	inc	r1
	mov	a,r7
	movx	@r1,a
	dec	r1
	dec	r1
	dec	r1
;	pca-hal.c:547: __pca_captureEndCount[channel].fields.ccapl = ccapl;
	mov	a,r4
	add	a,#___pca_captureEndCount
	mov	r0,a
	mov	a,r5
	movx	@r0,a
;	pca-hal.c:548: __pca_captureEndCount[channel].fields.ccaph = ccaph;
	mov	a,r0
	inc	a
	mov	r7,a
	push	ar0
	mov	r0,ar7
	push	ar1
	mov	r1,#___pca_isr_ccaph_65536_44
	movx	a,@r1
	movx	@r0,a
	pop	ar0
	pop	ar1
;	pca-hal.c:549: __pca_captureEndCount[channel].fields.cnt = __pca_captureOverflowCounter[channel];
	mov	a,#0x02
	add	a,r0
	mov	r7,a
	push	ar0
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	add	a,#___pca_captureOverflowCounter
	mov	r6,a
	mov	r0,ar6
	movx	a,@r0
	mov	r0,ar7
	movx	@r0,a
	pop	ar0
;	pca-hal.c:550: __pca_captureEndCount[channel].fields.zero = 0;
	inc	r0
	inc	r0
	inc	r0
	clr	a
	movx	@r0,a
;	pca-hal.c:552: width.count = (__pca_captureEndCount[channel].count - __pca_captureStartCount[channel].count) >> __pca_captureShiftBits[channel];
	mov	a,r4
	add	a,#___pca_captureEndCount
	mov	r0,a
	movx	a,@r0
	mov	___pca_isr_sloc0_1_0,a
	inc	r0
	movx	a,@r0
	mov	(___pca_isr_sloc0_1_0 + 1),a
	inc	r0
	movx	a,@r0
	mov	(___pca_isr_sloc0_1_0 + 2),a
	inc	r0
	movx	a,@r0
	mov	(___pca_isr_sloc0_1_0 + 3),a
	movx	a,@r1
	mov	r2,a
	inc	r1
	movx	a,@r1
	mov	r5,a
	inc	r1
	movx	a,@r1
	mov	r6,a
	inc	r1
	movx	a,@r1
	mov	r7,a
	mov	a,___pca_isr_sloc0_1_0
	clr	c
	subb	a,r2
	mov	r2,a
	mov	a,(___pca_isr_sloc0_1_0 + 1)
	subb	a,r5
	mov	r5,a
	mov	a,(___pca_isr_sloc0_1_0 + 2)
	subb	a,r6
	mov	r6,a
	mov	a,(___pca_isr_sloc0_1_0 + 3)
	subb	a,r7
	mov	r7,a
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	add	a,#___pca_captureShiftBits
	mov	r1,a
	movx	a,@r1
	mov	r4,a
	mov	b,r4
	inc	b
	sjmp	00212$
00211$:
	clr	c
	mov	a,r7
	rrc	a
	mov	r7,a
	mov	a,r6
	rrc	a
	mov	r6,a
	mov	a,r5
	rrc	a
	mov	r5,a
	mov	a,r2
	rrc	a
	mov	r2,a
00212$:
	djnz	b,00211$
	mov	r0,#___pca_isr_width_65536_44
	mov	a,r2
	movx	@r0,a
	inc	r0
	mov	a,r5
	movx	@r0,a
	inc	r0
	mov	a,r6
	movx	@r0,a
	inc	r0
	mov	a,r7
	movx	@r0,a
;	pca-hal.c:554: duration = width.fields.cnt ? 0xffff : ((uint16_t) width.count);
	mov	r0,#(___pca_isr_width_65536_44 + 0x0002)
	movx	a,@r0
	jz	00127$
	mov	r6,#0xff
	mov	r7,#0xff
	sjmp	00128$
00127$:
	mov	r0,#___pca_isr_width_65536_44
	movx	a,@r0
	mov	r2,a
	inc	r0
	movx	a,@r0
	mov	r3,a
	inc	r0
	movx	a,@r0
	mov	r4,a
	inc	r0
	movx	a,@r0
	mov	r5,a
	mov	ar6,r2
	mov	ar7,r3
00128$:
;	pca-hal.c:556: pcaOnInterrupt(channel, duration);
	mov	r0,#_pcaOnInterrupt_PARM_2
	mov	a,r6
	movx	@r0,a
	mov	a,r7
	inc	r0
	movx	@r0,a
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	mov	dpl,a
	lcall	_pcaOnInterrupt
;	pca-hal.c:557: break;
;	pca-hal.c:560: case PCA_TIMER:
	sjmp	00125$
00121$:
;	pca-hal.c:561: pcaOnInterrupt(channel, duration);
	mov	r0,#_pcaOnInterrupt_PARM_2
	clr	a
	movx	@r0,a
	inc	r0
	movx	@r0,a
	mov	r0,#___pca_isr_channel_65536_44
	movx	a,@r0
	mov	dpl,a
	lcall	_pcaOnInterrupt
;	pca-hal.c:563: }
00125$:
;	pca-hal.c:565: }
	pop	psw
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	setb	ea
	reti
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
