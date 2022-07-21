                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-medium
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _stuffToDoWhileTheLedBlinks
                                     13 	.globl _echoCharactersReceived
                                     14 	.globl _pcaUpdateGlowingDutyCycle
                                     15 	.globl _pcaSetPwmDutyCycle
                                     16 	.globl _pcaStartPwm
                                     17 	.globl _pcaInitialise
                                     18 	.globl _serialConsoleInitialise
                                     19 	.globl _uartSendCharacter
                                     20 	.globl _uartGetCharacter
                                     21 	.globl _startTimer
                                     22 	.globl _frequencyToSysclkDivisor
                                     23 	.globl _gpioWrite
                                     24 	.globl _gpioConfigure
                                     25 	.globl _delay1ms
                                     26 	.globl _S1SM0_FE
                                     27 	.globl _T1IF
                                     28 	.globl _T1R
                                     29 	.globl _T0IF
                                     30 	.globl _T0R
                                     31 	.globl _CF
                                     32 	.globl _CR
                                     33 	.globl _CCF1
                                     34 	.globl _CCF0
                                     35 	.globl _CY
                                     36 	.globl _AC
                                     37 	.globl _F0
                                     38 	.globl _RS1
                                     39 	.globl _RS0
                                     40 	.globl _OV
                                     41 	.globl _F1
                                     42 	.globl _P
                                     43 	.globl _EA
                                     44 	.globl _INT1IF
                                     45 	.globl _IT1
                                     46 	.globl _INT0IF
                                     47 	.globl _IT0
                                     48 	.globl _P5_5
                                     49 	.globl _P5_4
                                     50 	.globl _P5_3
                                     51 	.globl _P5_2
                                     52 	.globl _P5_1
                                     53 	.globl _P5_0
                                     54 	.globl _P4_7
                                     55 	.globl _P4_6
                                     56 	.globl _P4_5
                                     57 	.globl _P4_4
                                     58 	.globl _P4_3
                                     59 	.globl _P4_2
                                     60 	.globl _P4_1
                                     61 	.globl _P4_0
                                     62 	.globl _P3_7
                                     63 	.globl _P3_6
                                     64 	.globl _P3_5
                                     65 	.globl _P3_4
                                     66 	.globl _P3_3
                                     67 	.globl _P3_2
                                     68 	.globl _P3_1
                                     69 	.globl _P3_0
                                     70 	.globl _P2_7
                                     71 	.globl _P2_6
                                     72 	.globl _P2_5
                                     73 	.globl _P2_4
                                     74 	.globl _P2_3
                                     75 	.globl _P2_2
                                     76 	.globl _P2_1
                                     77 	.globl _P2_0
                                     78 	.globl _P1_7
                                     79 	.globl _P1_6
                                     80 	.globl _P1_5
                                     81 	.globl _P1_4
                                     82 	.globl _P1_3
                                     83 	.globl _P1_2
                                     84 	.globl _P1_1
                                     85 	.globl _P1_0
                                     86 	.globl _P0_7
                                     87 	.globl _P0_6
                                     88 	.globl _P0_5
                                     89 	.globl _P0_4
                                     90 	.globl _P0_3
                                     91 	.globl _P0_2
                                     92 	.globl _P0_1
                                     93 	.globl _P0_0
                                     94 	.globl _S2BUF
                                     95 	.globl _S2CON
                                     96 	.globl _S1BUF
                                     97 	.globl _S1CON
                                     98 	.globl _SADEN
                                     99 	.globl _SADDR
                                    100 	.globl _WDT_CONTR
                                    101 	.globl _AUXR
                                    102 	.globl _BRT
                                    103 	.globl _T1
                                    104 	.globl _T1H
                                    105 	.globl _T1L
                                    106 	.globl _T0
                                    107 	.globl _T0H
                                    108 	.globl _T0L
                                    109 	.globl _TMOD
                                    110 	.globl _TCON
                                    111 	.globl _CLKDIV
                                    112 	.globl _SPDAT
                                    113 	.globl _SPCTL
                                    114 	.globl _SPSTAT
                                    115 	.globl _PCA_PWM1
                                    116 	.globl _PCA_PWM0
                                    117 	.globl _CCAP1
                                    118 	.globl _CCAP0
                                    119 	.globl _CCAP1H
                                    120 	.globl _CCAP0H
                                    121 	.globl _CCAP1L
                                    122 	.globl _CCAP0L
                                    123 	.globl _PCA_CTR
                                    124 	.globl _CH
                                    125 	.globl _CL
                                    126 	.globl _CCAPM1
                                    127 	.globl _CCAPM0
                                    128 	.globl _CMOD
                                    129 	.globl _CCON
                                    130 	.globl _BUS_SPEED
                                    131 	.globl _P4SW
                                    132 	.globl _P1ASF
                                    133 	.globl _P_SW1
                                    134 	.globl _WAKE_CLKO
                                    135 	.globl _PCON
                                    136 	.globl _B
                                    137 	.globl _ACC
                                    138 	.globl _PSW
                                    139 	.globl _SP
                                    140 	.globl _IP2H
                                    141 	.globl _IP2L
                                    142 	.globl _IP1H
                                    143 	.globl _IP1L
                                    144 	.globl _IE2
                                    145 	.globl _IE1
                                    146 	.globl _IAP_CONTR
                                    147 	.globl _IAP_TRIG
                                    148 	.globl _IAP_CMD
                                    149 	.globl _IAP_ADDR
                                    150 	.globl _IAP_ADDRL
                                    151 	.globl _IAP_ADDRH
                                    152 	.globl _IAP_DATA
                                    153 	.globl _P5M0
                                    154 	.globl _P5M1
                                    155 	.globl _P5
                                    156 	.globl _P4M0
                                    157 	.globl _P4M1
                                    158 	.globl _P4
                                    159 	.globl _P3M0
                                    160 	.globl _P3M1
                                    161 	.globl _P3
                                    162 	.globl _P2M0
                                    163 	.globl _P2M1
                                    164 	.globl _P2
                                    165 	.globl _P1M0
                                    166 	.globl _P1M1
                                    167 	.globl _P1
                                    168 	.globl _P0M0
                                    169 	.globl _P0M1
                                    170 	.globl _P0
                                    171 	.globl _DPS
                                    172 	.globl _DP
                                    173 	.globl _DPH
                                    174 	.globl _DPL
                                    175 	.globl _ADC_RESL
                                    176 	.globl _ADC_RESH
                                    177 	.globl _ADC_CONTR
                                    178 	.globl _pcaOnInterrupt_PARM_2
                                    179 	.globl _pcaOnInterrupt
                                    180 ;--------------------------------------------------------
                                    181 ; special function registers
                                    182 ;--------------------------------------------------------
                                    183 	.area RSEG    (ABS,DATA)
      000000                        184 	.org 0x0000
                           0000BC   185 _ADC_CONTR	=	0x00bc
                           0000BD   186 _ADC_RESH	=	0x00bd
                           0000BE   187 _ADC_RESL	=	0x00be
                           000082   188 _DPL	=	0x0082
                           000083   189 _DPH	=	0x0083
                           008382   190 _DP	=	0x8382
                           0000A2   191 _DPS	=	0x00a2
                           000080   192 _P0	=	0x0080
                           000093   193 _P0M1	=	0x0093
                           000094   194 _P0M0	=	0x0094
                           000090   195 _P1	=	0x0090
                           000091   196 _P1M1	=	0x0091
                           000092   197 _P1M0	=	0x0092
                           0000A0   198 _P2	=	0x00a0
                           000095   199 _P2M1	=	0x0095
                           000096   200 _P2M0	=	0x0096
                           0000B0   201 _P3	=	0x00b0
                           0000B1   202 _P3M1	=	0x00b1
                           0000B2   203 _P3M0	=	0x00b2
                           0000C0   204 _P4	=	0x00c0
                           0000B3   205 _P4M1	=	0x00b3
                           0000B4   206 _P4M0	=	0x00b4
                           0000C8   207 _P5	=	0x00c8
                           0000C9   208 _P5M1	=	0x00c9
                           0000CA   209 _P5M0	=	0x00ca
                           0000C2   210 _IAP_DATA	=	0x00c2
                           0000C3   211 _IAP_ADDRH	=	0x00c3
                           0000C4   212 _IAP_ADDRL	=	0x00c4
                           00C3C4   213 _IAP_ADDR	=	0xc3c4
                           0000C5   214 _IAP_CMD	=	0x00c5
                           0000C6   215 _IAP_TRIG	=	0x00c6
                           0000C7   216 _IAP_CONTR	=	0x00c7
                           0000A8   217 _IE1	=	0x00a8
                           0000AF   218 _IE2	=	0x00af
                           0000B8   219 _IP1L	=	0x00b8
                           0000B7   220 _IP1H	=	0x00b7
                           0000B5   221 _IP2L	=	0x00b5
                           0000B6   222 _IP2H	=	0x00b6
                           000081   223 _SP	=	0x0081
                           0000D0   224 _PSW	=	0x00d0
                           0000E0   225 _ACC	=	0x00e0
                           0000F0   226 _B	=	0x00f0
                           000087   227 _PCON	=	0x0087
                           00008F   228 _WAKE_CLKO	=	0x008f
                           0000A2   229 _P_SW1	=	0x00a2
                           00009D   230 _P1ASF	=	0x009d
                           0000BB   231 _P4SW	=	0x00bb
                           0000A1   232 _BUS_SPEED	=	0x00a1
                           0000D8   233 _CCON	=	0x00d8
                           0000D9   234 _CMOD	=	0x00d9
                           0000DA   235 _CCAPM0	=	0x00da
                           0000DB   236 _CCAPM1	=	0x00db
                           0000E9   237 _CL	=	0x00e9
                           0000F9   238 _CH	=	0x00f9
                           00F9E9   239 _PCA_CTR	=	0xf9e9
                           0000EA   240 _CCAP0L	=	0x00ea
                           0000EB   241 _CCAP1L	=	0x00eb
                           0000FA   242 _CCAP0H	=	0x00fa
                           0000FB   243 _CCAP1H	=	0x00fb
                           00FAEA   244 _CCAP0	=	0xfaea
                           00FBEB   245 _CCAP1	=	0xfbeb
                           0000F2   246 _PCA_PWM0	=	0x00f2
                           0000F3   247 _PCA_PWM1	=	0x00f3
                           0000CD   248 _SPSTAT	=	0x00cd
                           0000CE   249 _SPCTL	=	0x00ce
                           0000CF   250 _SPDAT	=	0x00cf
                           000097   251 _CLKDIV	=	0x0097
                           000088   252 _TCON	=	0x0088
                           000089   253 _TMOD	=	0x0089
                           00008A   254 _T0L	=	0x008a
                           00008C   255 _T0H	=	0x008c
                           008C8A   256 _T0	=	0x8c8a
                           00008B   257 _T1L	=	0x008b
                           00008D   258 _T1H	=	0x008d
                           008D8B   259 _T1	=	0x8d8b
                           00009C   260 _BRT	=	0x009c
                           00008E   261 _AUXR	=	0x008e
                           0000C1   262 _WDT_CONTR	=	0x00c1
                           0000A9   263 _SADDR	=	0x00a9
                           0000B9   264 _SADEN	=	0x00b9
                           000098   265 _S1CON	=	0x0098
                           000099   266 _S1BUF	=	0x0099
                           00009A   267 _S2CON	=	0x009a
                           00009B   268 _S2BUF	=	0x009b
                                    269 ;--------------------------------------------------------
                                    270 ; special function bits
                                    271 ;--------------------------------------------------------
                                    272 	.area RSEG    (ABS,DATA)
      000000                        273 	.org 0x0000
                           000080   274 _P0_0	=	0x0080
                           000081   275 _P0_1	=	0x0081
                           000082   276 _P0_2	=	0x0082
                           000083   277 _P0_3	=	0x0083
                           000084   278 _P0_4	=	0x0084
                           000085   279 _P0_5	=	0x0085
                           000086   280 _P0_6	=	0x0086
                           000087   281 _P0_7	=	0x0087
                           000090   282 _P1_0	=	0x0090
                           000091   283 _P1_1	=	0x0091
                           000092   284 _P1_2	=	0x0092
                           000093   285 _P1_3	=	0x0093
                           000094   286 _P1_4	=	0x0094
                           000095   287 _P1_5	=	0x0095
                           000096   288 _P1_6	=	0x0096
                           000097   289 _P1_7	=	0x0097
                           0000A0   290 _P2_0	=	0x00a0
                           0000A1   291 _P2_1	=	0x00a1
                           0000A2   292 _P2_2	=	0x00a2
                           0000A3   293 _P2_3	=	0x00a3
                           0000A4   294 _P2_4	=	0x00a4
                           0000A5   295 _P2_5	=	0x00a5
                           0000A6   296 _P2_6	=	0x00a6
                           0000A7   297 _P2_7	=	0x00a7
                           0000B0   298 _P3_0	=	0x00b0
                           0000B1   299 _P3_1	=	0x00b1
                           0000B2   300 _P3_2	=	0x00b2
                           0000B3   301 _P3_3	=	0x00b3
                           0000B4   302 _P3_4	=	0x00b4
                           0000B5   303 _P3_5	=	0x00b5
                           0000B6   304 _P3_6	=	0x00b6
                           0000B7   305 _P3_7	=	0x00b7
                           0000C0   306 _P4_0	=	0x00c0
                           0000C1   307 _P4_1	=	0x00c1
                           0000C2   308 _P4_2	=	0x00c2
                           0000C3   309 _P4_3	=	0x00c3
                           0000C4   310 _P4_4	=	0x00c4
                           0000C5   311 _P4_5	=	0x00c5
                           0000C6   312 _P4_6	=	0x00c6
                           0000C7   313 _P4_7	=	0x00c7
                           0000C8   314 _P5_0	=	0x00c8
                           0000C9   315 _P5_1	=	0x00c9
                           0000CA   316 _P5_2	=	0x00ca
                           0000CB   317 _P5_3	=	0x00cb
                           0000CC   318 _P5_4	=	0x00cc
                           0000CD   319 _P5_5	=	0x00cd
                           000088   320 _IT0	=	0x0088
                           000089   321 _INT0IF	=	0x0089
                           00008A   322 _IT1	=	0x008a
                           00008B   323 _INT1IF	=	0x008b
                           0000AF   324 _EA	=	0x00af
                           0000D0   325 _P	=	0x00d0
                           0000D1   326 _F1	=	0x00d1
                           0000D2   327 _OV	=	0x00d2
                           0000D3   328 _RS0	=	0x00d3
                           0000D4   329 _RS1	=	0x00d4
                           0000D5   330 _F0	=	0x00d5
                           0000D6   331 _AC	=	0x00d6
                           0000D7   332 _CY	=	0x00d7
                           0000D8   333 _CCF0	=	0x00d8
                           0000D9   334 _CCF1	=	0x00d9
                           0000DE   335 _CR	=	0x00de
                           0000DF   336 _CF	=	0x00df
                           00008C   337 _T0R	=	0x008c
                           00008D   338 _T0IF	=	0x008d
                           00008E   339 _T1R	=	0x008e
                           00008F   340 _T1IF	=	0x008f
                           00009F   341 _S1SM0_FE	=	0x009f
                                    342 ;--------------------------------------------------------
                                    343 ; overlayable register banks
                                    344 ;--------------------------------------------------------
                                    345 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        346 	.ds 8
                                    347 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        348 	.ds 8
                                    349 ;--------------------------------------------------------
                                    350 ; internal ram data
                                    351 ;--------------------------------------------------------
                                    352 	.area DSEG    (DATA)
                                    353 ;--------------------------------------------------------
                                    354 ; overlayable items in internal ram
                                    355 ;--------------------------------------------------------
                                    356 ;--------------------------------------------------------
                                    357 ; Stack segment in internal ram
                                    358 ;--------------------------------------------------------
                                    359 	.area	SSEG
      000022                        360 __start__stack:
      000022                        361 	.ds	1
                                    362 
                                    363 ;--------------------------------------------------------
                                    364 ; indirectly addressable internal ram data
                                    365 ;--------------------------------------------------------
                                    366 	.area ISEG    (DATA)
                                    367 ;--------------------------------------------------------
                                    368 ; absolute internal ram data
                                    369 ;--------------------------------------------------------
                                    370 	.area IABS    (ABS,DATA)
                                    371 	.area IABS    (ABS,DATA)
                                    372 ;--------------------------------------------------------
                                    373 ; bit data
                                    374 ;--------------------------------------------------------
                                    375 	.area BSEG    (BIT)
      000003                        376 _main_sloc0_1_0:
      000003                        377 	.ds 1
                                    378 ;--------------------------------------------------------
                                    379 ; paged external ram data
                                    380 ;--------------------------------------------------------
                                    381 	.area PSEG    (PAG,XDATA)
      0000BE                        382 _blinkingPin:
      0000BE                        383 	.ds 6
      0000C4                        384 _blinkingState:
      0000C4                        385 	.ds 1
      0000C5                        386 _pcaGlowingStep:
      0000C5                        387 	.ds 1
      0000C6                        388 _pcaGlowingIncrement:
      0000C6                        389 	.ds 1
      0000C7                        390 _pcaOnInterrupt_PARM_2:
      0000C7                        391 	.ds 2
                                    392 ;--------------------------------------------------------
                                    393 ; external ram data
                                    394 ;--------------------------------------------------------
                                    395 	.area XSEG    (XDATA)
                                    396 ;--------------------------------------------------------
                                    397 ; absolute external ram data
                                    398 ;--------------------------------------------------------
                                    399 	.area XABS    (ABS,XDATA)
                                    400 ;--------------------------------------------------------
                                    401 ; external initialized ram data
                                    402 ;--------------------------------------------------------
                                    403 	.area XISEG   (XDATA)
                                    404 	.area HOME    (CODE)
                                    405 	.area GSINIT0 (CODE)
                                    406 	.area GSINIT1 (CODE)
                                    407 	.area GSINIT2 (CODE)
                                    408 	.area GSINIT3 (CODE)
                                    409 	.area GSINIT4 (CODE)
                                    410 	.area GSINIT5 (CODE)
                                    411 	.area GSINIT  (CODE)
                                    412 	.area GSFINAL (CODE)
                                    413 	.area CSEG    (CODE)
                                    414 ;--------------------------------------------------------
                                    415 ; interrupt vector
                                    416 ;--------------------------------------------------------
                                    417 	.area HOME    (CODE)
      000000                        418 __interrupt_vect:
      000000 02 00 49         [24]  419 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  420 	reti
      000004                        421 	.ds	7
      00000B 32               [24]  422 	reti
      00000C                        423 	.ds	7
      000013 32               [24]  424 	reti
      000014                        425 	.ds	7
      00001B 32               [24]  426 	reti
      00001C                        427 	.ds	7
      000023 02 0F E4         [24]  428 	ljmp	___uart1_isr
      000026                        429 	.ds	5
      00002B 32               [24]  430 	reti
      00002C                        431 	.ds	7
      000033 32               [24]  432 	reti
      000034                        433 	.ds	7
      00003B 02 0B 31         [24]  434 	ljmp	___pca_isr
      00003E                        435 	.ds	5
      000043 02 10 72         [24]  436 	ljmp	___uart2_isr
                                    437 ;--------------------------------------------------------
                                    438 ; global & static initialisations
                                    439 ;--------------------------------------------------------
                                    440 	.area HOME    (CODE)
                                    441 	.area GSINIT  (CODE)
                                    442 	.area GSFINAL (CODE)
                                    443 	.area GSINIT  (CODE)
                                    444 	.globl __sdcc_gsinit_startup
                                    445 	.globl __sdcc_program_startup
                                    446 	.globl __start__stack
                                    447 	.globl __mcs51_genXINIT
                                    448 	.globl __mcs51_genXRAMCLEAR
                                    449 	.globl __mcs51_genRAMCLEAR
                                    450 ;	main.c:51: static GpioConfig blinkingPin = GPIO_PIN_CONFIG(GPIO_PORT3, BLINKING_PIN, GPIO_BIDIRECTIONAL);
      0000BD 78 BE            [12]  451 	mov	r0,#_blinkingPin
      0000BF 74 03            [12]  452 	mov	a,#0x03
      0000C1 F2               [24]  453 	movx	@r0,a
      0000C2 78 BF            [12]  454 	mov	r0,#(_blinkingPin + 0x0001)
      0000C4 F2               [24]  455 	movx	@r0,a
      0000C5 78 C0            [12]  456 	mov	r0,#(_blinkingPin + 0x0002)
      0000C7 74 01            [12]  457 	mov	a,#0x01
      0000C9 F2               [24]  458 	movx	@r0,a
      0000CA 78 C1            [12]  459 	mov	r0,#(_blinkingPin + 0x0003)
      0000CC E4               [12]  460 	clr	a
      0000CD F2               [24]  461 	movx	@r0,a
                                    462 ;	main.c:52: static uint8_t blinkingState = 0;
      0000CE 78 C4            [12]  463 	mov	r0,#_blinkingState
      0000D0 F2               [24]  464 	movx	@r0,a
                                    465 ;	main.c:63: static int8_t pcaGlowingStep = 0;
      0000D1 78 C5            [12]  466 	mov	r0,#_pcaGlowingStep
      0000D3 F2               [24]  467 	movx	@r0,a
                                    468 ;	main.c:64: static int8_t pcaGlowingIncrement = 1;
      0000D4 78 C6            [12]  469 	mov	r0,#_pcaGlowingIncrement
      0000D6 04               [12]  470 	inc	a
      0000D7 F2               [24]  471 	movx	@r0,a
                                    472 	.area GSFINAL (CODE)
      0000D8 02 00 46         [24]  473 	ljmp	__sdcc_program_startup
                                    474 ;--------------------------------------------------------
                                    475 ; Home
                                    476 ;--------------------------------------------------------
                                    477 	.area HOME    (CODE)
                                    478 	.area HOME    (CODE)
      000046                        479 __sdcc_program_startup:
      000046 02 14 86         [24]  480 	ljmp	_main
                                    481 ;	return from main will return to caller
                                    482 ;--------------------------------------------------------
                                    483 ; code
                                    484 ;--------------------------------------------------------
                                    485 	.area CSEG    (CODE)
                                    486 ;------------------------------------------------------------
                                    487 ;Allocation info for local variables in function 'pcaOnInterrupt'
                                    488 ;------------------------------------------------------------
                                    489 ;	main.c:71: void pcaOnInterrupt(PCA_Channel channel, uint16_t pulseLength) USE_BANK(1) {
                                    490 ;	-----------------------------------------
                                    491 ;	 function pcaOnInterrupt
                                    492 ;	-----------------------------------------
      0013EB                        493 _pcaOnInterrupt:
                           00000F   494 	ar7 = 0x0f
                           00000E   495 	ar6 = 0x0e
                           00000D   496 	ar5 = 0x0d
                           00000C   497 	ar4 = 0x0c
                           00000B   498 	ar3 = 0x0b
                           00000A   499 	ar2 = 0x0a
                           000009   500 	ar1 = 0x09
                           000008   501 	ar0 = 0x08
                                    502 ;	main.c:72: }
      0013EB 22               [24]  503 	ret
                                    504 ;------------------------------------------------------------
                                    505 ;Allocation info for local variables in function 'pcaUpdateGlowingDutyCycle'
                                    506 ;------------------------------------------------------------
                                    507 ;	main.c:74: void pcaUpdateGlowingDutyCycle() {
                                    508 ;	-----------------------------------------
                                    509 ;	 function pcaUpdateGlowingDutyCycle
                                    510 ;	-----------------------------------------
      0013EC                        511 _pcaUpdateGlowingDutyCycle:
                           000007   512 	ar7 = 0x07
                           000006   513 	ar6 = 0x06
                           000005   514 	ar5 = 0x05
                           000004   515 	ar4 = 0x04
                           000003   516 	ar3 = 0x03
                           000002   517 	ar2 = 0x02
                           000001   518 	ar1 = 0x01
                           000000   519 	ar0 = 0x00
                                    520 ;	main.c:75: pcaSetPwmDutyCycle(PCA_GLOWING_CHANNEL, 255 - PCA_GLOWING_GRADIENT[pcaGlowingStep]);
      0013EC 78 C5            [12]  521 	mov	r0,#_pcaGlowingStep
      0013EE E2               [24]  522 	movx	a,@r0
      0013EF FE               [12]  523 	mov	r6,a
      0013F0 E2               [24]  524 	movx	a,@r0
      0013F1 33               [12]  525 	rlc	a
      0013F2 95 E0            [12]  526 	subb	a,acc
      0013F4 FF               [12]  527 	mov	r7,a
      0013F5 EE               [12]  528 	mov	a,r6
      0013F6 24 0D            [12]  529 	add	a,#_PCA_GLOWING_GRADIENT
      0013F8 F5 82            [12]  530 	mov	dpl,a
      0013FA EF               [12]  531 	mov	a,r7
      0013FB 34 16            [12]  532 	addc	a,#(_PCA_GLOWING_GRADIENT >> 8)
      0013FD F5 83            [12]  533 	mov	dph,a
      0013FF E4               [12]  534 	clr	a
      001400 93               [24]  535 	movc	a,@a+dptr
      001401 FF               [12]  536 	mov	r7,a
      001402 7E 00            [12]  537 	mov	r6,#0x00
      001404 74 FF            [12]  538 	mov	a,#0xff
      001406 C3               [12]  539 	clr	c
      001407 9F               [12]  540 	subb	a,r7
      001408 FF               [12]  541 	mov	r7,a
      001409 E4               [12]  542 	clr	a
      00140A 9E               [12]  543 	subb	a,r6
      00140B FE               [12]  544 	mov	r6,a
      00140C 78 54            [12]  545 	mov	r0,#_pcaSetPwmDutyCycle_PARM_2
      00140E EF               [12]  546 	mov	a,r7
      00140F F2               [24]  547 	movx	@r0,a
      001410 EE               [12]  548 	mov	a,r6
      001411 08               [12]  549 	inc	r0
      001412 F2               [24]  550 	movx	@r0,a
      001413 75 82 00         [24]  551 	mov	dpl,#0x00
      001416 12 0A AC         [24]  552 	lcall	_pcaSetPwmDutyCycle
                                    553 ;	main.c:76: int8_t newStep = pcaGlowingStep + pcaGlowingIncrement;
      001419 78 C5            [12]  554 	mov	r0,#_pcaGlowingStep
      00141B 79 C6            [12]  555 	mov	r1,#_pcaGlowingIncrement
      00141D E3               [24]  556 	movx	a,@r1
      00141E C5 F0            [12]  557 	xch	a,b
      001420 E2               [24]  558 	movx	a,@r0
      001421 25 F0            [12]  559 	add	a,b
                                    560 ;	main.c:78: if (newStep < 0 || newStep >= PCA_GLOWING_STEPS) {
      001423 FF               [12]  561 	mov	r7,a
      001424 20 E7 08         [24]  562 	jb	acc.7,00101$
      001427 C3               [12]  563 	clr	c
      001428 EF               [12]  564 	mov	a,r7
      001429 64 80            [12]  565 	xrl	a,#0x80
      00142B 94 94            [12]  566 	subb	a,#0x94
      00142D 40 08            [24]  567 	jc	00102$
      00142F                        568 00101$:
                                    569 ;	main.c:79: pcaGlowingIncrement = -pcaGlowingIncrement;
      00142F 78 C6            [12]  570 	mov	r0,#_pcaGlowingIncrement
      001431 E2               [24]  571 	movx	a,@r0
      001432 D3               [12]  572 	setb	c
      001433 F4               [12]  573 	cpl	a
      001434 34 00            [12]  574 	addc	a,#0x00
      001436 F2               [24]  575 	movx	@r0,a
      001437                        576 00102$:
                                    577 ;	main.c:82: pcaGlowingStep += pcaGlowingIncrement;
      001437 78 C5            [12]  578 	mov	r0,#_pcaGlowingStep
      001439 79 C6            [12]  579 	mov	r1,#_pcaGlowingIncrement
      00143B E3               [24]  580 	movx	a,@r1
      00143C C5 F0            [12]  581 	xch	a,b
      00143E E2               [24]  582 	movx	a,@r0
      00143F 25 F0            [12]  583 	add	a,b
      001441 F2               [24]  584 	movx	@r0,a
                                    585 ;	main.c:83: }
      001442 22               [24]  586 	ret
                                    587 ;------------------------------------------------------------
                                    588 ;Allocation info for local variables in function 'echoCharactersReceived'
                                    589 ;------------------------------------------------------------
                                    590 ;	main.c:139: void echoCharactersReceived() {
                                    591 ;	-----------------------------------------
                                    592 ;	 function echoCharactersReceived
                                    593 ;	-----------------------------------------
      001443                        594 _echoCharactersReceived:
                                    595 ;	main.c:142: while (c = uartGetCharacter(CONSOLE_UART)) {
      001443                        596 00103$:
      001443 75 82 01         [24]  597 	mov	dpl,#0x01
      001446 12 11 00         [24]  598 	lcall	_uartGetCharacter
      001449 E5 82            [12]  599 	mov	a,dpl
      00144B FE               [12]  600 	mov	r6,a
      00144C 60 1E            [24]  601 	jz	00106$
                                    602 ;	main.c:143: if (c == '\n') {
      00144E BE 0A 0F         [24]  603 	cjne	r6,#0x0a,00102$
                                    604 ;	main.c:144: uartSendCharacter(CONSOLE_UART, '\r');
      001451 78 BB            [12]  605 	mov	r0,#_uartSendCharacter_PARM_2
      001453 74 0D            [12]  606 	mov	a,#0x0d
      001455 F2               [24]  607 	movx	@r0,a
      001456 75 82 01         [24]  608 	mov	dpl,#0x01
      001459 C0 06            [24]  609 	push	ar6
      00145B 12 11 30         [24]  610 	lcall	_uartSendCharacter
      00145E D0 06            [24]  611 	pop	ar6
      001460                        612 00102$:
                                    613 ;	main.c:147: uartSendCharacter(CONSOLE_UART, c);
      001460 78 BB            [12]  614 	mov	r0,#_uartSendCharacter_PARM_2
      001462 EE               [12]  615 	mov	a,r6
      001463 F2               [24]  616 	movx	@r0,a
      001464 75 82 01         [24]  617 	mov	dpl,#0x01
      001467 12 11 30         [24]  618 	lcall	_uartSendCharacter
      00146A 80 D7            [24]  619 	sjmp	00103$
      00146C                        620 00106$:
                                    621 ;	main.c:149: }
      00146C 22               [24]  622 	ret
                                    623 ;------------------------------------------------------------
                                    624 ;Allocation info for local variables in function 'stuffToDoWhileTheLedBlinks'
                                    625 ;------------------------------------------------------------
                                    626 ;	main.c:151: void stuffToDoWhileTheLedBlinks(uint16_t delay) {
                                    627 ;	-----------------------------------------
                                    628 ;	 function stuffToDoWhileTheLedBlinks
                                    629 ;	-----------------------------------------
      00146D                        630 _stuffToDoWhileTheLedBlinks:
      00146D AE 82            [24]  631 	mov	r6,dpl
      00146F AF 83            [24]  632 	mov	r7,dph
                                    633 ;	main.c:154: pcaUpdateGlowingDutyCycle();
      001471 C0 07            [24]  634 	push	ar7
      001473 C0 06            [24]  635 	push	ar6
      001475 12 13 EC         [24]  636 	lcall	_pcaUpdateGlowingDutyCycle
                                    637 ;	main.c:166: echoCharactersReceived();
      001478 12 14 43         [24]  638 	lcall	_echoCharactersReceived
      00147B D0 06            [24]  639 	pop	ar6
      00147D D0 07            [24]  640 	pop	ar7
                                    641 ;	main.c:169: delay1ms(delay);
      00147F 8E 82            [24]  642 	mov	dpl,r6
      001481 8F 83            [24]  643 	mov	dph,r7
                                    644 ;	main.c:170: }
      001483 02 03 04         [24]  645 	ljmp	_delay1ms
                                    646 ;------------------------------------------------------------
                                    647 ;Allocation info for local variables in function 'main'
                                    648 ;------------------------------------------------------------
                                    649 ;	main.c:172: void main() {
                                    650 ;	-----------------------------------------
                                    651 ;	 function main
                                    652 ;	-----------------------------------------
      001486                        653 _main:
                                    654 ;	main.c:176: CONSOLE_PIN_CONFIG
      001486 78 61            [12]  655 	mov	r0,#_serialConsoleInitialise_PARM_2
      001488 E4               [12]  656 	clr	a
      001489 F2               [24]  657 	movx	@r0,a
      00148A 74 E1            [12]  658 	mov	a,#0xe1
      00148C 08               [12]  659 	inc	r0
      00148D F2               [24]  660 	movx	@r0,a
      00148E E4               [12]  661 	clr	a
      00148F 08               [12]  662 	inc	r0
      001490 F2               [24]  663 	movx	@r0,a
      001491 08               [12]  664 	inc	r0
      001492 F2               [24]  665 	movx	@r0,a
      001493 78 65            [12]  666 	mov	r0,#_serialConsoleInitialise_PARM_3
      001495 F2               [24]  667 	movx	@r0,a
      001496 75 82 01         [24]  668 	mov	dpl,#0x01
      001499 12 0D 29         [24]  669 	lcall	_serialConsoleInitialise
                                    670 ;	main.c:179: gpioConfigure(&blinkingPin);
      00149C 90 00 BE         [24]  671 	mov	dptr,#_blinkingPin
      00149F 75 F0 60         [24]  672 	mov	b,#0x60
      0014A2 12 03 D2         [24]  673 	lcall	_gpioConfigure
                                    674 ;	main.c:184: frequencyToSysclkDivisor(PCA_GLOWING_COUNTER_FREQ), 
      0014A5 90 64 00         [24]  675 	mov	dptr,#0x6400
      0014A8 E4               [12]  676 	clr	a
      0014A9 F5 F0            [12]  677 	mov	b,a
      0014AB 12 01 2D         [24]  678 	lcall	_frequencyToSysclkDivisor
      0014AE AC 82            [24]  679 	mov	r4,dpl
      0014B0 AD 83            [24]  680 	mov	r5,dph
      0014B2 AE F0            [24]  681 	mov	r6,b
      0014B4 FF               [12]  682 	mov	r7,a
                                    683 ;	main.c:187: TIMER_FREE_RUNNING
      0014B5 78 00            [12]  684 	mov	r0,#_startTimer_PARM_2
      0014B7 EC               [12]  685 	mov	a,r4
      0014B8 F2               [24]  686 	movx	@r0,a
      0014B9 ED               [12]  687 	mov	a,r5
      0014BA 08               [12]  688 	inc	r0
      0014BB F2               [24]  689 	movx	@r0,a
      0014BC EE               [12]  690 	mov	a,r6
      0014BD 08               [12]  691 	inc	r0
      0014BE F2               [24]  692 	movx	@r0,a
      0014BF EF               [12]  693 	mov	a,r7
      0014C0 08               [12]  694 	inc	r0
      0014C1 F2               [24]  695 	movx	@r0,a
      0014C2 78 04            [12]  696 	mov	r0,#_startTimer_PARM_3
      0014C4 E4               [12]  697 	clr	a
      0014C5 F2               [24]  698 	movx	@r0,a
      0014C6 78 05            [12]  699 	mov	r0,#_startTimer_PARM_4
      0014C8 F2               [24]  700 	movx	@r0,a
      0014C9 78 06            [12]  701 	mov	r0,#_startTimer_PARM_5
      0014CB F2               [24]  702 	movx	@r0,a
      0014CC 75 82 00         [24]  703 	mov	dpl,#0x00
      0014CF 12 01 4B         [24]  704 	lcall	_startTimer
                                    705 ;	main.c:194: PCA_GLOWING_PIN_CONFIG
      0014D2 78 42            [12]  706 	mov	r0,#_pcaInitialise_PARM_2
      0014D4 E4               [12]  707 	clr	a
      0014D5 F2               [24]  708 	movx	@r0,a
      0014D6 78 43            [12]  709 	mov	r0,#_pcaInitialise_PARM_3
      0014D8 F2               [24]  710 	movx	@r0,a
      0014D9 78 44            [12]  711 	mov	r0,#_pcaInitialise_PARM_4
      0014DB F2               [24]  712 	movx	@r0,a
      0014DC 75 82 02         [24]  713 	mov	dpl,#0x02
      0014DF 12 09 3B         [24]  714 	lcall	_pcaInitialise
                                    715 ;	main.c:202: 255 - PCA_GLOWING_GRADIENT[0]
      0014E2 90 16 0D         [24]  716 	mov	dptr,#_PCA_GLOWING_GRADIENT
      0014E5 E4               [12]  717 	clr	a
      0014E6 93               [24]  718 	movc	a,@a+dptr
      0014E7 FF               [12]  719 	mov	r7,a
      0014E8 7E 00            [12]  720 	mov	r6,#0x00
      0014EA 74 FF            [12]  721 	mov	a,#0xff
      0014EC C3               [12]  722 	clr	c
      0014ED 9F               [12]  723 	subb	a,r7
      0014EE FF               [12]  724 	mov	r7,a
      0014EF E4               [12]  725 	clr	a
      0014F0 9E               [12]  726 	subb	a,r6
      0014F1 FE               [12]  727 	mov	r6,a
      0014F2 78 52            [12]  728 	mov	r0,#_pcaStartPwm_PARM_5
      0014F4 EF               [12]  729 	mov	a,r7
      0014F5 F2               [24]  730 	movx	@r0,a
      0014F6 EE               [12]  731 	mov	a,r6
      0014F7 08               [12]  732 	inc	r0
      0014F8 F2               [24]  733 	movx	@r0,a
      0014F9 78 4F            [12]  734 	mov	r0,#_pcaStartPwm_PARM_2
      0014FB E4               [12]  735 	clr	a
      0014FC F2               [24]  736 	movx	@r0,a
      0014FD 78 50            [12]  737 	mov	r0,#_pcaStartPwm_PARM_3
      0014FF F2               [24]  738 	movx	@r0,a
      001500 78 51            [12]  739 	mov	r0,#_pcaStartPwm_PARM_4
      001502 F2               [24]  740 	movx	@r0,a
      001503 75 82 00         [24]  741 	mov	dpl,#0x00
      001506 12 0A 84         [24]  742 	lcall	_pcaStartPwm
                                    743 ;	main.c:226: EA = 1;
                                    744 ;	assignBit
      001509 D2 AF            [12]  745 	setb	_EA
                                    746 ;	main.c:230: while (1) {
      00150B                        747 00102$:
                                    748 ;	main.c:232: gpioWrite(&blinkingPin, blinkingState);
      00150B 78 C4            [12]  749 	mov	r0,#_blinkingState
      00150D 79 10            [12]  750 	mov	r1,#_gpioWrite_PARM_2
      00150F E2               [24]  751 	movx	a,@r0
      001510 F3               [24]  752 	movx	@r1,a
      001511 90 00 BE         [24]  753 	mov	dptr,#_blinkingPin
      001514 75 F0 60         [24]  754 	mov	b,#0x60
      001517 12 07 81         [24]  755 	lcall	_gpioWrite
                                    756 ;	main.c:233: blinkingState = !blinkingState;
      00151A 78 C4            [12]  757 	mov	r0,#_blinkingState
      00151C E2               [24]  758 	movx	a,@r0
      00151D B4 01 00         [24]  759 	cjne	a,#0x01,00110$
      001520                        760 00110$:
      001520 92 03            [24]  761 	mov	_main_sloc0_1_0,c
      001522 78 C4            [12]  762 	mov	r0,#_blinkingState
      001524 E4               [12]  763 	clr	a
      001525 33               [12]  764 	rlc	a
      001526 F2               [24]  765 	movx	@r0,a
                                    766 ;	main.c:236: stuffToDoWhileTheLedBlinks(BLINKING_HALF_PERIOD / 2);
      001527 90 00 7D         [24]  767 	mov	dptr,#0x007d
      00152A 12 14 6D         [24]  768 	lcall	_stuffToDoWhileTheLedBlinks
                                    769 ;	main.c:237: stuffToDoWhileTheLedBlinks(BLINKING_HALF_PERIOD / 2);
      00152D 90 00 7D         [24]  770 	mov	dptr,#0x007d
      001530 12 14 6D         [24]  771 	lcall	_stuffToDoWhileTheLedBlinks
                                    772 ;	main.c:239: }
      001533 80 D6            [24]  773 	sjmp	00102$
                                    774 	.area CSEG    (CODE)
                                    775 	.area CONST   (CODE)
      00160D                        776 _PCA_GLOWING_GRADIENT:
      00160D 01                     777 	.db #0x01	; 1
      00160E 03                     778 	.db #0x03	; 3
      00160F 05                     779 	.db #0x05	; 5
      001610 07                     780 	.db #0x07	; 7
      001611 0A                     781 	.db #0x0a	; 10
      001612 0F                     782 	.db #0x0f	; 15
      001613 14                     783 	.db #0x14	; 20
      001614 1B                     784 	.db #0x1b	; 27
      001615 22                     785 	.db #0x22	; 34
      001616 2C                     786 	.db #0x2c	; 44
      001617 36                     787 	.db #0x36	; 54	'6'
      001618 43                     788 	.db #0x43	; 67	'C'
      001619 51                     789 	.db #0x51	; 81	'Q'
      00161A 61                     790 	.db #0x61	; 97	'a'
      00161B 72                     791 	.db #0x72	; 114	'r'
      00161C 86                     792 	.db #0x86	; 134
      00161D 9D                     793 	.db #0x9d	; 157
      00161E B5                     794 	.db #0xb5	; 181
      00161F D0                     795 	.db #0xd0	; 208
      001620 ED                     796 	.db #0xed	; 237
                                    797 	.area XINIT   (CODE)
                                    798 	.area CABS    (ABS,CODE)
