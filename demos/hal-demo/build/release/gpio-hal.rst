                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module gpio_hal
                                      6 	.optsdcc -mmcs51 --model-medium
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _S1SM0_FE
                                     12 	.globl _T1IF
                                     13 	.globl _T1R
                                     14 	.globl _T0IF
                                     15 	.globl _T0R
                                     16 	.globl _CF
                                     17 	.globl _CR
                                     18 	.globl _CCF1
                                     19 	.globl _CCF0
                                     20 	.globl _CY
                                     21 	.globl _AC
                                     22 	.globl _F0
                                     23 	.globl _RS1
                                     24 	.globl _RS0
                                     25 	.globl _OV
                                     26 	.globl _F1
                                     27 	.globl _P
                                     28 	.globl _EA
                                     29 	.globl _INT1IF
                                     30 	.globl _IT1
                                     31 	.globl _INT0IF
                                     32 	.globl _IT0
                                     33 	.globl _P5_5
                                     34 	.globl _P5_4
                                     35 	.globl _P5_3
                                     36 	.globl _P5_2
                                     37 	.globl _P5_1
                                     38 	.globl _P5_0
                                     39 	.globl _P4_7
                                     40 	.globl _P4_6
                                     41 	.globl _P4_5
                                     42 	.globl _P4_4
                                     43 	.globl _P4_3
                                     44 	.globl _P4_2
                                     45 	.globl _P4_1
                                     46 	.globl _P4_0
                                     47 	.globl _P3_7
                                     48 	.globl _P3_6
                                     49 	.globl _P3_5
                                     50 	.globl _P3_4
                                     51 	.globl _P3_3
                                     52 	.globl _P3_2
                                     53 	.globl _P3_1
                                     54 	.globl _P3_0
                                     55 	.globl _P2_7
                                     56 	.globl _P2_6
                                     57 	.globl _P2_5
                                     58 	.globl _P2_4
                                     59 	.globl _P2_3
                                     60 	.globl _P2_2
                                     61 	.globl _P2_1
                                     62 	.globl _P2_0
                                     63 	.globl _P1_7
                                     64 	.globl _P1_6
                                     65 	.globl _P1_5
                                     66 	.globl _P1_4
                                     67 	.globl _P1_3
                                     68 	.globl _P1_2
                                     69 	.globl _P1_1
                                     70 	.globl _P1_0
                                     71 	.globl _P0_7
                                     72 	.globl _P0_6
                                     73 	.globl _P0_5
                                     74 	.globl _P0_4
                                     75 	.globl _P0_3
                                     76 	.globl _P0_2
                                     77 	.globl _P0_1
                                     78 	.globl _P0_0
                                     79 	.globl _S2BUF
                                     80 	.globl _S2CON
                                     81 	.globl _S1BUF
                                     82 	.globl _S1CON
                                     83 	.globl _SADEN
                                     84 	.globl _SADDR
                                     85 	.globl _WDT_CONTR
                                     86 	.globl _AUXR
                                     87 	.globl _BRT
                                     88 	.globl _T1
                                     89 	.globl _T1H
                                     90 	.globl _T1L
                                     91 	.globl _T0
                                     92 	.globl _T0H
                                     93 	.globl _T0L
                                     94 	.globl _TMOD
                                     95 	.globl _TCON
                                     96 	.globl _CLKDIV
                                     97 	.globl _SPDAT
                                     98 	.globl _SPCTL
                                     99 	.globl _SPSTAT
                                    100 	.globl _PCA_PWM1
                                    101 	.globl _PCA_PWM0
                                    102 	.globl _CCAP1
                                    103 	.globl _CCAP0
                                    104 	.globl _CCAP1H
                                    105 	.globl _CCAP0H
                                    106 	.globl _CCAP1L
                                    107 	.globl _CCAP0L
                                    108 	.globl _PCA_CTR
                                    109 	.globl _CH
                                    110 	.globl _CL
                                    111 	.globl _CCAPM1
                                    112 	.globl _CCAPM0
                                    113 	.globl _CMOD
                                    114 	.globl _CCON
                                    115 	.globl _BUS_SPEED
                                    116 	.globl _P4SW
                                    117 	.globl _P1ASF
                                    118 	.globl _P_SW1
                                    119 	.globl _WAKE_CLKO
                                    120 	.globl _PCON
                                    121 	.globl _B
                                    122 	.globl _ACC
                                    123 	.globl _PSW
                                    124 	.globl _SP
                                    125 	.globl _IP2H
                                    126 	.globl _IP2L
                                    127 	.globl _IP1H
                                    128 	.globl _IP1L
                                    129 	.globl _IE2
                                    130 	.globl _IE1
                                    131 	.globl _IAP_CONTR
                                    132 	.globl _IAP_TRIG
                                    133 	.globl _IAP_CMD
                                    134 	.globl _IAP_ADDR
                                    135 	.globl _IAP_ADDRL
                                    136 	.globl _IAP_ADDRH
                                    137 	.globl _IAP_DATA
                                    138 	.globl _P5M0
                                    139 	.globl _P5M1
                                    140 	.globl _P5
                                    141 	.globl _P4M0
                                    142 	.globl _P4M1
                                    143 	.globl _P4
                                    144 	.globl _P3M0
                                    145 	.globl _P3M1
                                    146 	.globl _P3
                                    147 	.globl _P2M0
                                    148 	.globl _P2M1
                                    149 	.globl _P2
                                    150 	.globl _P1M0
                                    151 	.globl _P1M1
                                    152 	.globl _P1
                                    153 	.globl _P0M0
                                    154 	.globl _P0M1
                                    155 	.globl _P0
                                    156 	.globl _DPS
                                    157 	.globl _DP
                                    158 	.globl _DPH
                                    159 	.globl _DPL
                                    160 	.globl _ADC_RESL
                                    161 	.globl _ADC_RESH
                                    162 	.globl _ADC_CONTR
                                    163 	.globl _gpioWrite_PARM_2
                                    164 	.globl _gpioConfigure
                                    165 	.globl _gpioRead
                                    166 	.globl _gpioWrite
                                    167 ;--------------------------------------------------------
                                    168 ; special function registers
                                    169 ;--------------------------------------------------------
                                    170 	.area RSEG    (ABS,DATA)
      000000                        171 	.org 0x0000
                           0000BC   172 _ADC_CONTR	=	0x00bc
                           0000BD   173 _ADC_RESH	=	0x00bd
                           0000BE   174 _ADC_RESL	=	0x00be
                           000082   175 _DPL	=	0x0082
                           000083   176 _DPH	=	0x0083
                           008382   177 _DP	=	0x8382
                           0000A2   178 _DPS	=	0x00a2
                           000080   179 _P0	=	0x0080
                           000093   180 _P0M1	=	0x0093
                           000094   181 _P0M0	=	0x0094
                           000090   182 _P1	=	0x0090
                           000091   183 _P1M1	=	0x0091
                           000092   184 _P1M0	=	0x0092
                           0000A0   185 _P2	=	0x00a0
                           000095   186 _P2M1	=	0x0095
                           000096   187 _P2M0	=	0x0096
                           0000B0   188 _P3	=	0x00b0
                           0000B1   189 _P3M1	=	0x00b1
                           0000B2   190 _P3M0	=	0x00b2
                           0000C0   191 _P4	=	0x00c0
                           0000B3   192 _P4M1	=	0x00b3
                           0000B4   193 _P4M0	=	0x00b4
                           0000C8   194 _P5	=	0x00c8
                           0000C9   195 _P5M1	=	0x00c9
                           0000CA   196 _P5M0	=	0x00ca
                           0000C2   197 _IAP_DATA	=	0x00c2
                           0000C3   198 _IAP_ADDRH	=	0x00c3
                           0000C4   199 _IAP_ADDRL	=	0x00c4
                           00C3C4   200 _IAP_ADDR	=	0xc3c4
                           0000C5   201 _IAP_CMD	=	0x00c5
                           0000C6   202 _IAP_TRIG	=	0x00c6
                           0000C7   203 _IAP_CONTR	=	0x00c7
                           0000A8   204 _IE1	=	0x00a8
                           0000AF   205 _IE2	=	0x00af
                           0000B8   206 _IP1L	=	0x00b8
                           0000B7   207 _IP1H	=	0x00b7
                           0000B5   208 _IP2L	=	0x00b5
                           0000B6   209 _IP2H	=	0x00b6
                           000081   210 _SP	=	0x0081
                           0000D0   211 _PSW	=	0x00d0
                           0000E0   212 _ACC	=	0x00e0
                           0000F0   213 _B	=	0x00f0
                           000087   214 _PCON	=	0x0087
                           00008F   215 _WAKE_CLKO	=	0x008f
                           0000A2   216 _P_SW1	=	0x00a2
                           00009D   217 _P1ASF	=	0x009d
                           0000BB   218 _P4SW	=	0x00bb
                           0000A1   219 _BUS_SPEED	=	0x00a1
                           0000D8   220 _CCON	=	0x00d8
                           0000D9   221 _CMOD	=	0x00d9
                           0000DA   222 _CCAPM0	=	0x00da
                           0000DB   223 _CCAPM1	=	0x00db
                           0000E9   224 _CL	=	0x00e9
                           0000F9   225 _CH	=	0x00f9
                           00F9E9   226 _PCA_CTR	=	0xf9e9
                           0000EA   227 _CCAP0L	=	0x00ea
                           0000EB   228 _CCAP1L	=	0x00eb
                           0000FA   229 _CCAP0H	=	0x00fa
                           0000FB   230 _CCAP1H	=	0x00fb
                           00FAEA   231 _CCAP0	=	0xfaea
                           00FBEB   232 _CCAP1	=	0xfbeb
                           0000F2   233 _PCA_PWM0	=	0x00f2
                           0000F3   234 _PCA_PWM1	=	0x00f3
                           0000CD   235 _SPSTAT	=	0x00cd
                           0000CE   236 _SPCTL	=	0x00ce
                           0000CF   237 _SPDAT	=	0x00cf
                           000097   238 _CLKDIV	=	0x0097
                           000088   239 _TCON	=	0x0088
                           000089   240 _TMOD	=	0x0089
                           00008A   241 _T0L	=	0x008a
                           00008C   242 _T0H	=	0x008c
                           008C8A   243 _T0	=	0x8c8a
                           00008B   244 _T1L	=	0x008b
                           00008D   245 _T1H	=	0x008d
                           008D8B   246 _T1	=	0x8d8b
                           00009C   247 _BRT	=	0x009c
                           00008E   248 _AUXR	=	0x008e
                           0000C1   249 _WDT_CONTR	=	0x00c1
                           0000A9   250 _SADDR	=	0x00a9
                           0000B9   251 _SADEN	=	0x00b9
                           000098   252 _S1CON	=	0x0098
                           000099   253 _S1BUF	=	0x0099
                           00009A   254 _S2CON	=	0x009a
                           00009B   255 _S2BUF	=	0x009b
                                    256 ;--------------------------------------------------------
                                    257 ; special function bits
                                    258 ;--------------------------------------------------------
                                    259 	.area RSEG    (ABS,DATA)
      000000                        260 	.org 0x0000
                           000080   261 _P0_0	=	0x0080
                           000081   262 _P0_1	=	0x0081
                           000082   263 _P0_2	=	0x0082
                           000083   264 _P0_3	=	0x0083
                           000084   265 _P0_4	=	0x0084
                           000085   266 _P0_5	=	0x0085
                           000086   267 _P0_6	=	0x0086
                           000087   268 _P0_7	=	0x0087
                           000090   269 _P1_0	=	0x0090
                           000091   270 _P1_1	=	0x0091
                           000092   271 _P1_2	=	0x0092
                           000093   272 _P1_3	=	0x0093
                           000094   273 _P1_4	=	0x0094
                           000095   274 _P1_5	=	0x0095
                           000096   275 _P1_6	=	0x0096
                           000097   276 _P1_7	=	0x0097
                           0000A0   277 _P2_0	=	0x00a0
                           0000A1   278 _P2_1	=	0x00a1
                           0000A2   279 _P2_2	=	0x00a2
                           0000A3   280 _P2_3	=	0x00a3
                           0000A4   281 _P2_4	=	0x00a4
                           0000A5   282 _P2_5	=	0x00a5
                           0000A6   283 _P2_6	=	0x00a6
                           0000A7   284 _P2_7	=	0x00a7
                           0000B0   285 _P3_0	=	0x00b0
                           0000B1   286 _P3_1	=	0x00b1
                           0000B2   287 _P3_2	=	0x00b2
                           0000B3   288 _P3_3	=	0x00b3
                           0000B4   289 _P3_4	=	0x00b4
                           0000B5   290 _P3_5	=	0x00b5
                           0000B6   291 _P3_6	=	0x00b6
                           0000B7   292 _P3_7	=	0x00b7
                           0000C0   293 _P4_0	=	0x00c0
                           0000C1   294 _P4_1	=	0x00c1
                           0000C2   295 _P4_2	=	0x00c2
                           0000C3   296 _P4_3	=	0x00c3
                           0000C4   297 _P4_4	=	0x00c4
                           0000C5   298 _P4_5	=	0x00c5
                           0000C6   299 _P4_6	=	0x00c6
                           0000C7   300 _P4_7	=	0x00c7
                           0000C8   301 _P5_0	=	0x00c8
                           0000C9   302 _P5_1	=	0x00c9
                           0000CA   303 _P5_2	=	0x00ca
                           0000CB   304 _P5_3	=	0x00cb
                           0000CC   305 _P5_4	=	0x00cc
                           0000CD   306 _P5_5	=	0x00cd
                           000088   307 _IT0	=	0x0088
                           000089   308 _INT0IF	=	0x0089
                           00008A   309 _IT1	=	0x008a
                           00008B   310 _INT1IF	=	0x008b
                           0000AF   311 _EA	=	0x00af
                           0000D0   312 _P	=	0x00d0
                           0000D1   313 _F1	=	0x00d1
                           0000D2   314 _OV	=	0x00d2
                           0000D3   315 _RS0	=	0x00d3
                           0000D4   316 _RS1	=	0x00d4
                           0000D5   317 _F0	=	0x00d5
                           0000D6   318 _AC	=	0x00d6
                           0000D7   319 _CY	=	0x00d7
                           0000D8   320 _CCF0	=	0x00d8
                           0000D9   321 _CCF1	=	0x00d9
                           0000DE   322 _CR	=	0x00de
                           0000DF   323 _CF	=	0x00df
                           00008C   324 _T0R	=	0x008c
                           00008D   325 _T0IF	=	0x008d
                           00008E   326 _T1R	=	0x008e
                           00008F   327 _T1IF	=	0x008f
                           00009F   328 _S1SM0_FE	=	0x009f
                                    329 ;--------------------------------------------------------
                                    330 ; overlayable register banks
                                    331 ;--------------------------------------------------------
                                    332 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        333 	.ds 8
                                    334 ;--------------------------------------------------------
                                    335 ; internal ram data
                                    336 ;--------------------------------------------------------
                                    337 	.area DSEG    (DATA)
      000010                        338 _gpioConfigure_sloc0_1_0:
      000010                        339 	.ds 3
                                    340 ;--------------------------------------------------------
                                    341 ; overlayable items in internal ram
                                    342 ;--------------------------------------------------------
                                    343 ;--------------------------------------------------------
                                    344 ; indirectly addressable internal ram data
                                    345 ;--------------------------------------------------------
                                    346 	.area ISEG    (DATA)
                                    347 ;--------------------------------------------------------
                                    348 ; absolute internal ram data
                                    349 ;--------------------------------------------------------
                                    350 	.area IABS    (ABS,DATA)
                                    351 	.area IABS    (ABS,DATA)
                                    352 ;--------------------------------------------------------
                                    353 ; bit data
                                    354 ;--------------------------------------------------------
                                    355 	.area BSEG    (BIT)
      000000                        356 ___isOutput_sloc0_1_0:
      000000                        357 	.ds 1
      000001                        358 ___isInput_sloc0_1_0:
      000001                        359 	.ds 1
                                    360 ;--------------------------------------------------------
                                    361 ; paged external ram data
                                    362 ;--------------------------------------------------------
                                    363 	.area PSEG    (PAG,XDATA)
      000009                        364 ___gpio_setBits_PARM_2:
      000009                        365 	.ds 1
      00000A                        366 ___gpio_setBits_PARM_3:
      00000A                        367 	.ds 3
      00000D                        368 _gpioConfigure_gpioConfig_65536_10:
      00000D                        369 	.ds 3
      000010                        370 _gpioWrite_PARM_2:
      000010                        371 	.ds 1
      000011                        372 _gpioWrite_gpioConfig_65536_18:
      000011                        373 	.ds 3
                                    374 ;--------------------------------------------------------
                                    375 ; external ram data
                                    376 ;--------------------------------------------------------
                                    377 	.area XSEG    (XDATA)
                                    378 ;--------------------------------------------------------
                                    379 ; absolute external ram data
                                    380 ;--------------------------------------------------------
                                    381 	.area XABS    (ABS,XDATA)
                                    382 ;--------------------------------------------------------
                                    383 ; external initialized ram data
                                    384 ;--------------------------------------------------------
                                    385 	.area XISEG   (XDATA)
                                    386 	.area HOME    (CODE)
                                    387 	.area GSINIT0 (CODE)
                                    388 	.area GSINIT1 (CODE)
                                    389 	.area GSINIT2 (CODE)
                                    390 	.area GSINIT3 (CODE)
                                    391 	.area GSINIT4 (CODE)
                                    392 	.area GSINIT5 (CODE)
                                    393 	.area GSINIT  (CODE)
                                    394 	.area GSFINAL (CODE)
                                    395 	.area CSEG    (CODE)
                                    396 ;--------------------------------------------------------
                                    397 ; global & static initialisations
                                    398 ;--------------------------------------------------------
                                    399 	.area HOME    (CODE)
                                    400 	.area GSINIT  (CODE)
                                    401 	.area GSFINAL (CODE)
                                    402 	.area GSINIT  (CODE)
                                    403 ;--------------------------------------------------------
                                    404 ; Home
                                    405 ;--------------------------------------------------------
                                    406 	.area HOME    (CODE)
                                    407 	.area HOME    (CODE)
                                    408 ;--------------------------------------------------------
                                    409 ; code
                                    410 ;--------------------------------------------------------
                                    411 	.area CSEG    (CODE)
                                    412 ;------------------------------------------------------------
                                    413 ;Allocation info for local variables in function '__gpio_setBits'
                                    414 ;------------------------------------------------------------
                                    415 ;	gpio-hal.c:39: static uint8_t __gpio_setBits(uint8_t portValue, uint8_t cfgValue, GpioConfig *gpioConfig) {
                                    416 ;	-----------------------------------------
                                    417 ;	 function __gpio_setBits
                                    418 ;	-----------------------------------------
      000337                        419 ___gpio_setBits:
                           000007   420 	ar7 = 0x07
                           000006   421 	ar6 = 0x06
                           000005   422 	ar5 = 0x05
                           000004   423 	ar4 = 0x04
                           000003   424 	ar3 = 0x03
                           000002   425 	ar2 = 0x02
                           000001   426 	ar1 = 0x01
                           000000   427 	ar0 = 0x00
      000337 AF 82            [24]  428 	mov	r7,dpl
                                    429 ;	gpio-hal.c:40: return cfgValue ? (portValue | gpioConfig->__setMask) : (portValue & gpioConfig->__clearMask);
      000339 78 09            [12]  430 	mov	r0,#___gpio_setBits_PARM_2
      00033B E2               [24]  431 	movx	a,@r0
      00033C 60 1C            [24]  432 	jz	00103$
      00033E 78 0A            [12]  433 	mov	r0,#___gpio_setBits_PARM_3
      000340 E2               [24]  434 	movx	a,@r0
      000341 24 04            [12]  435 	add	a,#0x04
      000343 FC               [12]  436 	mov	r4,a
      000344 08               [12]  437 	inc	r0
      000345 E2               [24]  438 	movx	a,@r0
      000346 34 00            [12]  439 	addc	a,#0x00
      000348 FD               [12]  440 	mov	r5,a
      000349 08               [12]  441 	inc	r0
      00034A E2               [24]  442 	movx	a,@r0
      00034B FE               [12]  443 	mov	r6,a
      00034C 8C 82            [24]  444 	mov	dpl,r4
      00034E 8D 83            [24]  445 	mov	dph,r5
      000350 8E F0            [24]  446 	mov	b,r6
      000352 12 15 ED         [24]  447 	lcall	__gptrget
      000355 FC               [12]  448 	mov	r4,a
      000356 4F               [12]  449 	orl	a,r7
      000357 FE               [12]  450 	mov	r6,a
      000358 80 1A            [24]  451 	sjmp	00104$
      00035A                        452 00103$:
      00035A 78 0A            [12]  453 	mov	r0,#___gpio_setBits_PARM_3
      00035C E2               [24]  454 	movx	a,@r0
      00035D 24 05            [12]  455 	add	a,#0x05
      00035F FB               [12]  456 	mov	r3,a
      000360 08               [12]  457 	inc	r0
      000361 E2               [24]  458 	movx	a,@r0
      000362 34 00            [12]  459 	addc	a,#0x00
      000364 FC               [12]  460 	mov	r4,a
      000365 08               [12]  461 	inc	r0
      000366 E2               [24]  462 	movx	a,@r0
      000367 FD               [12]  463 	mov	r5,a
      000368 8B 82            [24]  464 	mov	dpl,r3
      00036A 8C 83            [24]  465 	mov	dph,r4
      00036C 8D F0            [24]  466 	mov	b,r5
      00036E 12 15 ED         [24]  467 	lcall	__gptrget
      000371 FB               [12]  468 	mov	r3,a
      000372 5F               [12]  469 	anl	a,r7
      000373 FE               [12]  470 	mov	r6,a
      000374                        471 00104$:
      000374 8E 82            [24]  472 	mov	dpl,r6
                                    473 ;	gpio-hal.c:41: }
      000376 22               [24]  474 	ret
                                    475 ;------------------------------------------------------------
                                    476 ;Allocation info for local variables in function '__isOutput'
                                    477 ;------------------------------------------------------------
                                    478 ;	gpio-hal.c:43: static uint8_t __isOutput(GpioConfig *gpioConfig) {
                                    479 ;	-----------------------------------------
                                    480 ;	 function __isOutput
                                    481 ;	-----------------------------------------
      000377                        482 ___isOutput:
      000377 AD 82            [24]  483 	mov	r5,dpl
      000379 AE 83            [24]  484 	mov	r6,dph
      00037B AF F0            [24]  485 	mov	r7,b
                                    486 ;	gpio-hal.c:44: return gpioConfig->portMode == GPIO_BIDIRECTIONAL || gpioConfig->portMode == GPIO_PUSH_PULL || gpioConfig->portMode == GPIO_OPEN_DRAIN;
      00037D 74 03            [12]  487 	mov	a,#0x03
      00037F 2D               [12]  488 	add	a,r5
      000380 FD               [12]  489 	mov	r5,a
      000381 E4               [12]  490 	clr	a
      000382 3E               [12]  491 	addc	a,r6
      000383 FE               [12]  492 	mov	r6,a
      000384 8D 82            [24]  493 	mov	dpl,r5
      000386 8E 83            [24]  494 	mov	dph,r6
      000388 8F F0            [24]  495 	mov	b,r7
      00038A 12 15 ED         [24]  496 	lcall	__gptrget
      00038D FF               [12]  497 	mov	r7,a
      00038E 60 0E            [24]  498 	jz	00104$
      000390 BF 01 02         [24]  499 	cjne	r7,#0x01,00122$
      000393 80 09            [24]  500 	sjmp	00104$
      000395                        501 00122$:
      000395 BF 03 02         [24]  502 	cjne	r7,#0x03,00123$
      000398 80 04            [24]  503 	sjmp	00104$
      00039A                        504 00123$:
                                    505 ;	assignBit
      00039A C2 00            [12]  506 	clr	___isOutput_sloc0_1_0
      00039C 80 02            [24]  507 	sjmp	00105$
      00039E                        508 00104$:
                                    509 ;	assignBit
      00039E D2 00            [12]  510 	setb	___isOutput_sloc0_1_0
      0003A0                        511 00105$:
      0003A0 A2 00            [12]  512 	mov	c,___isOutput_sloc0_1_0
      0003A2 E4               [12]  513 	clr	a
      0003A3 33               [12]  514 	rlc	a
      0003A4 F5 82            [12]  515 	mov	dpl,a
                                    516 ;	gpio-hal.c:45: }
      0003A6 22               [24]  517 	ret
                                    518 ;------------------------------------------------------------
                                    519 ;Allocation info for local variables in function '__isInput'
                                    520 ;------------------------------------------------------------
                                    521 ;	gpio-hal.c:47: static uint8_t __isInput(GpioConfig *gpioConfig) {
                                    522 ;	-----------------------------------------
                                    523 ;	 function __isInput
                                    524 ;	-----------------------------------------
      0003A7                        525 ___isInput:
      0003A7 AD 82            [24]  526 	mov	r5,dpl
      0003A9 AE 83            [24]  527 	mov	r6,dph
      0003AB AF F0            [24]  528 	mov	r7,b
                                    529 ;	gpio-hal.c:48: return gpioConfig->portMode == GPIO_BIDIRECTIONAL || gpioConfig->portMode == GPIO_HIGH_IMPEDANCE;
      0003AD 74 03            [12]  530 	mov	a,#0x03
      0003AF 2D               [12]  531 	add	a,r5
      0003B0 FD               [12]  532 	mov	r5,a
      0003B1 E4               [12]  533 	clr	a
      0003B2 3E               [12]  534 	addc	a,r6
      0003B3 FE               [12]  535 	mov	r6,a
      0003B4 8D 82            [24]  536 	mov	dpl,r5
      0003B6 8E 83            [24]  537 	mov	dph,r6
      0003B8 8F F0            [24]  538 	mov	b,r7
      0003BA 12 15 ED         [24]  539 	lcall	__gptrget
      0003BD FF               [12]  540 	mov	r7,a
      0003BE 60 09            [24]  541 	jz	00104$
      0003C0 BF 02 02         [24]  542 	cjne	r7,#0x02,00115$
      0003C3 80 04            [24]  543 	sjmp	00104$
      0003C5                        544 00115$:
                                    545 ;	assignBit
      0003C5 C2 01            [12]  546 	clr	___isInput_sloc0_1_0
      0003C7 80 02            [24]  547 	sjmp	00105$
      0003C9                        548 00104$:
                                    549 ;	assignBit
      0003C9 D2 01            [12]  550 	setb	___isInput_sloc0_1_0
      0003CB                        551 00105$:
      0003CB A2 01            [12]  552 	mov	c,___isInput_sloc0_1_0
      0003CD E4               [12]  553 	clr	a
      0003CE 33               [12]  554 	rlc	a
      0003CF F5 82            [12]  555 	mov	dpl,a
                                    556 ;	gpio-hal.c:49: }
      0003D1 22               [24]  557 	ret
                                    558 ;------------------------------------------------------------
                                    559 ;Allocation info for local variables in function 'gpioConfigure'
                                    560 ;------------------------------------------------------------
                                    561 ;sloc0                     Allocated with name '_gpioConfigure_sloc0_1_0'
                                    562 ;------------------------------------------------------------
                                    563 ;	gpio-hal.c:51: void gpioConfigure(GpioConfig *gpioConfig) {
                                    564 ;	-----------------------------------------
                                    565 ;	 function gpioConfigure
                                    566 ;	-----------------------------------------
      0003D2                        567 _gpioConfigure:
      0003D2 AF F0            [24]  568 	mov	r7,b
      0003D4 AE 83            [24]  569 	mov	r6,dph
      0003D6 E5 82            [12]  570 	mov	a,dpl
      0003D8 78 0D            [12]  571 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0003DA F2               [24]  572 	movx	@r0,a
      0003DB EE               [12]  573 	mov	a,r6
      0003DC 08               [12]  574 	inc	r0
      0003DD F2               [24]  575 	movx	@r0,a
      0003DE EF               [12]  576 	mov	a,r7
      0003DF 08               [12]  577 	inc	r0
      0003E0 F2               [24]  578 	movx	@r0,a
                                    579 ;	gpio-hal.c:53: uint8_t mask = 0;
      0003E1 7C 00            [12]  580 	mov	r4,#0x00
                                    581 ;	gpio-hal.c:55: for (uint8_t n = gpioConfig->count; n > 0; n--) {
      0003E3 78 0D            [12]  582 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0003E5 E2               [24]  583 	movx	a,@r0
      0003E6 24 02            [12]  584 	add	a,#0x02
      0003E8 FA               [12]  585 	mov	r2,a
      0003E9 08               [12]  586 	inc	r0
      0003EA E2               [24]  587 	movx	a,@r0
      0003EB 34 00            [12]  588 	addc	a,#0x00
      0003ED FB               [12]  589 	mov	r3,a
      0003EE 08               [12]  590 	inc	r0
      0003EF E2               [24]  591 	movx	a,@r0
      0003F0 FF               [12]  592 	mov	r7,a
      0003F1 8A 82            [24]  593 	mov	dpl,r2
      0003F3 8B 83            [24]  594 	mov	dph,r3
      0003F5 8F F0            [24]  595 	mov	b,r7
      0003F7 12 15 ED         [24]  596 	lcall	__gptrget
      0003FA FF               [12]  597 	mov	r7,a
      0003FB                        598 00110$:
      0003FB EF               [12]  599 	mov	a,r7
      0003FC 60 0C            [24]  600 	jz	00101$
                                    601 ;	gpio-hal.c:56: mask = mask << 1;
      0003FE 8C 06            [24]  602 	mov	ar6,r4
      000400 EE               [12]  603 	mov	a,r6
      000401 2E               [12]  604 	add	a,r6
      000402 FE               [12]  605 	mov	r6,a
                                    606 ;	gpio-hal.c:57: mask |= 1;
      000403 74 01            [12]  607 	mov	a,#0x01
      000405 4E               [12]  608 	orl	a,r6
      000406 FC               [12]  609 	mov	r4,a
                                    610 ;	gpio-hal.c:55: for (uint8_t n = gpioConfig->count; n > 0; n--) {
      000407 1F               [12]  611 	dec	r7
      000408 80 F1            [24]  612 	sjmp	00110$
      00040A                        613 00101$:
                                    614 ;	gpio-hal.c:60: gpioConfig->__setMask = mask << gpioConfig->pin;
      00040A 78 0D            [12]  615 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00040C E2               [24]  616 	movx	a,@r0
      00040D 24 04            [12]  617 	add	a,#0x04
      00040F F5 10            [12]  618 	mov	_gpioConfigure_sloc0_1_0,a
      000411 08               [12]  619 	inc	r0
      000412 E2               [24]  620 	movx	a,@r0
      000413 34 00            [12]  621 	addc	a,#0x00
      000415 F5 11            [12]  622 	mov	(_gpioConfigure_sloc0_1_0 + 1),a
      000417 08               [12]  623 	inc	r0
      000418 E2               [24]  624 	movx	a,@r0
      000419 F5 12            [12]  625 	mov	(_gpioConfigure_sloc0_1_0 + 2),a
      00041B 78 0D            [12]  626 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00041D E2               [24]  627 	movx	a,@r0
      00041E 24 01            [12]  628 	add	a,#0x01
      000420 FA               [12]  629 	mov	r2,a
      000421 08               [12]  630 	inc	r0
      000422 E2               [24]  631 	movx	a,@r0
      000423 34 00            [12]  632 	addc	a,#0x00
      000425 FB               [12]  633 	mov	r3,a
      000426 08               [12]  634 	inc	r0
      000427 E2               [24]  635 	movx	a,@r0
      000428 FF               [12]  636 	mov	r7,a
      000429 8A 82            [24]  637 	mov	dpl,r2
      00042B 8B 83            [24]  638 	mov	dph,r3
      00042D 8F F0            [24]  639 	mov	b,r7
      00042F 12 15 ED         [24]  640 	lcall	__gptrget
      000432 FA               [12]  641 	mov	r2,a
      000433 8A F0            [24]  642 	mov	b,r2
      000435 05 F0            [12]  643 	inc	b
      000437 EC               [12]  644 	mov	a,r4
      000438 80 02            [24]  645 	sjmp	00135$
      00043A                        646 00133$:
      00043A 25 E0            [12]  647 	add	a,acc
      00043C                        648 00135$:
      00043C D5 F0 FB         [24]  649 	djnz	b,00133$
      00043F FA               [12]  650 	mov	r2,a
      000440 85 10 82         [24]  651 	mov	dpl,_gpioConfigure_sloc0_1_0
      000443 85 11 83         [24]  652 	mov	dph,(_gpioConfigure_sloc0_1_0 + 1)
      000446 85 12 F0         [24]  653 	mov	b,(_gpioConfigure_sloc0_1_0 + 2)
      000449 12 15 D2         [24]  654 	lcall	__gptrput
                                    655 ;	gpio-hal.c:61: gpioConfig->__clearMask = ~gpioConfig->__setMask;
      00044C 78 0D            [12]  656 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00044E E2               [24]  657 	movx	a,@r0
      00044F 24 05            [12]  658 	add	a,#0x05
      000451 FD               [12]  659 	mov	r5,a
      000452 08               [12]  660 	inc	r0
      000453 E2               [24]  661 	movx	a,@r0
      000454 34 00            [12]  662 	addc	a,#0x00
      000456 FE               [12]  663 	mov	r6,a
      000457 08               [12]  664 	inc	r0
      000458 E2               [24]  665 	movx	a,@r0
      000459 FF               [12]  666 	mov	r7,a
      00045A EA               [12]  667 	mov	a,r2
      00045B F4               [12]  668 	cpl	a
      00045C FA               [12]  669 	mov	r2,a
      00045D 8D 82            [24]  670 	mov	dpl,r5
      00045F 8E 83            [24]  671 	mov	dph,r6
      000461 8F F0            [24]  672 	mov	b,r7
      000463 12 15 D2         [24]  673 	lcall	__gptrput
                                    674 ;	gpio-hal.c:63: switch (gpioConfig->port) {
      000466 78 0D            [12]  675 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000468 E2               [24]  676 	movx	a,@r0
      000469 F5 82            [12]  677 	mov	dpl,a
      00046B 08               [12]  678 	inc	r0
      00046C E2               [24]  679 	movx	a,@r0
      00046D F5 83            [12]  680 	mov	dph,a
      00046F 08               [12]  681 	inc	r0
      000470 E2               [24]  682 	movx	a,@r0
      000471 F5 F0            [12]  683 	mov	b,a
      000473 12 15 ED         [24]  684 	lcall	__gptrget
      000476 FF               [12]  685 	mov  r7,a
      000477 24 FA            [12]  686 	add	a,#0xff - 0x05
      000479 50 01            [24]  687 	jnc	00136$
      00047B 22               [24]  688 	ret
      00047C                        689 00136$:
      00047C EF               [12]  690 	mov	a,r7
      00047D 2F               [12]  691 	add	a,r7
      00047E 2F               [12]  692 	add	a,r7
      00047F 90 04 83         [24]  693 	mov	dptr,#00137$
      000482 73               [24]  694 	jmp	@a+dptr
      000483                        695 00137$:
      000483 02 04 95         [24]  696 	ljmp	00102$
      000486 02 05 00         [24]  697 	ljmp	00103$
      000489 02 05 6B         [24]  698 	ljmp	00104$
      00048C 02 05 D6         [24]  699 	ljmp	00105$
      00048F 02 06 41         [24]  700 	ljmp	00106$
      000492 02 06 AC         [24]  701 	ljmp	00107$
                                    702 ;	gpio-hal.c:68: case GPIO_PORT0:
      000495                        703 00102$:
                                    704 ;	gpio-hal.c:69: P0M1 = __gpio_setBits(P0M1, gpioConfig->portMode & 2, gpioConfig);
      000495 78 0D            [12]  705 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000497 E2               [24]  706 	movx	a,@r0
      000498 24 03            [12]  707 	add	a,#0x03
      00049A FD               [12]  708 	mov	r5,a
      00049B 08               [12]  709 	inc	r0
      00049C E2               [24]  710 	movx	a,@r0
      00049D 34 00            [12]  711 	addc	a,#0x00
      00049F FE               [12]  712 	mov	r6,a
      0004A0 08               [12]  713 	inc	r0
      0004A1 E2               [24]  714 	movx	a,@r0
      0004A2 FF               [12]  715 	mov	r7,a
      0004A3 8D 82            [24]  716 	mov	dpl,r5
      0004A5 8E 83            [24]  717 	mov	dph,r6
      0004A7 8F F0            [24]  718 	mov	b,r7
      0004A9 12 15 ED         [24]  719 	lcall	__gptrget
      0004AC FD               [12]  720 	mov	r5,a
      0004AD 78 09            [12]  721 	mov	r0,#___gpio_setBits_PARM_2
      0004AF 74 02            [12]  722 	mov	a,#0x02
      0004B1 5D               [12]  723 	anl	a,r5
      0004B2 F2               [24]  724 	movx	@r0,a
      0004B3 78 0D            [12]  725 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0004B5 79 0A            [12]  726 	mov	r1,#___gpio_setBits_PARM_3
      0004B7 E2               [24]  727 	movx	a,@r0
      0004B8 F3               [24]  728 	movx	@r1,a
      0004B9 08               [12]  729 	inc	r0
      0004BA E2               [24]  730 	movx	a,@r0
      0004BB 09               [12]  731 	inc	r1
      0004BC F3               [24]  732 	movx	@r1,a
      0004BD 08               [12]  733 	inc	r0
      0004BE E2               [24]  734 	movx	a,@r0
      0004BF 09               [12]  735 	inc	r1
      0004C0 F3               [24]  736 	movx	@r1,a
      0004C1 85 93 82         [24]  737 	mov	dpl,_P0M1
      0004C4 12 03 37         [24]  738 	lcall	___gpio_setBits
      0004C7 85 82 93         [24]  739 	mov	_P0M1,dpl
                                    740 ;	gpio-hal.c:70: P0M0 = __gpio_setBits(P0M0, gpioConfig->portMode & 1, gpioConfig);
      0004CA 78 0D            [12]  741 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0004CC E2               [24]  742 	movx	a,@r0
      0004CD 24 03            [12]  743 	add	a,#0x03
      0004CF FD               [12]  744 	mov	r5,a
      0004D0 08               [12]  745 	inc	r0
      0004D1 E2               [24]  746 	movx	a,@r0
      0004D2 34 00            [12]  747 	addc	a,#0x00
      0004D4 FE               [12]  748 	mov	r6,a
      0004D5 08               [12]  749 	inc	r0
      0004D6 E2               [24]  750 	movx	a,@r0
      0004D7 FF               [12]  751 	mov	r7,a
      0004D8 8D 82            [24]  752 	mov	dpl,r5
      0004DA 8E 83            [24]  753 	mov	dph,r6
      0004DC 8F F0            [24]  754 	mov	b,r7
      0004DE 12 15 ED         [24]  755 	lcall	__gptrget
      0004E1 FD               [12]  756 	mov	r5,a
      0004E2 78 09            [12]  757 	mov	r0,#___gpio_setBits_PARM_2
      0004E4 74 01            [12]  758 	mov	a,#0x01
      0004E6 5D               [12]  759 	anl	a,r5
      0004E7 F2               [24]  760 	movx	@r0,a
      0004E8 78 0D            [12]  761 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0004EA 79 0A            [12]  762 	mov	r1,#___gpio_setBits_PARM_3
      0004EC E2               [24]  763 	movx	a,@r0
      0004ED F3               [24]  764 	movx	@r1,a
      0004EE 08               [12]  765 	inc	r0
      0004EF E2               [24]  766 	movx	a,@r0
      0004F0 09               [12]  767 	inc	r1
      0004F1 F3               [24]  768 	movx	@r1,a
      0004F2 08               [12]  769 	inc	r0
      0004F3 E2               [24]  770 	movx	a,@r0
      0004F4 09               [12]  771 	inc	r1
      0004F5 F3               [24]  772 	movx	@r1,a
      0004F6 85 94 82         [24]  773 	mov	dpl,_P0M0
      0004F9 12 03 37         [24]  774 	lcall	___gpio_setBits
      0004FC 85 82 94         [24]  775 	mov	_P0M0,dpl
                                    776 ;	gpio-hal.c:98: break;
      0004FF 22               [24]  777 	ret
                                    778 ;	gpio-hal.c:104: case GPIO_PORT1:
      000500                        779 00103$:
                                    780 ;	gpio-hal.c:105: P1M1 = __gpio_setBits(P1M1, gpioConfig->portMode & 2, gpioConfig);
      000500 78 0D            [12]  781 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000502 E2               [24]  782 	movx	a,@r0
      000503 24 03            [12]  783 	add	a,#0x03
      000505 FD               [12]  784 	mov	r5,a
      000506 08               [12]  785 	inc	r0
      000507 E2               [24]  786 	movx	a,@r0
      000508 34 00            [12]  787 	addc	a,#0x00
      00050A FE               [12]  788 	mov	r6,a
      00050B 08               [12]  789 	inc	r0
      00050C E2               [24]  790 	movx	a,@r0
      00050D FF               [12]  791 	mov	r7,a
      00050E 8D 82            [24]  792 	mov	dpl,r5
      000510 8E 83            [24]  793 	mov	dph,r6
      000512 8F F0            [24]  794 	mov	b,r7
      000514 12 15 ED         [24]  795 	lcall	__gptrget
      000517 FD               [12]  796 	mov	r5,a
      000518 78 09            [12]  797 	mov	r0,#___gpio_setBits_PARM_2
      00051A 74 02            [12]  798 	mov	a,#0x02
      00051C 5D               [12]  799 	anl	a,r5
      00051D F2               [24]  800 	movx	@r0,a
      00051E 78 0D            [12]  801 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000520 79 0A            [12]  802 	mov	r1,#___gpio_setBits_PARM_3
      000522 E2               [24]  803 	movx	a,@r0
      000523 F3               [24]  804 	movx	@r1,a
      000524 08               [12]  805 	inc	r0
      000525 E2               [24]  806 	movx	a,@r0
      000526 09               [12]  807 	inc	r1
      000527 F3               [24]  808 	movx	@r1,a
      000528 08               [12]  809 	inc	r0
      000529 E2               [24]  810 	movx	a,@r0
      00052A 09               [12]  811 	inc	r1
      00052B F3               [24]  812 	movx	@r1,a
      00052C 85 91 82         [24]  813 	mov	dpl,_P1M1
      00052F 12 03 37         [24]  814 	lcall	___gpio_setBits
      000532 85 82 91         [24]  815 	mov	_P1M1,dpl
                                    816 ;	gpio-hal.c:106: P1M0 = __gpio_setBits(P1M0, gpioConfig->portMode & 1, gpioConfig);
      000535 78 0D            [12]  817 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000537 E2               [24]  818 	movx	a,@r0
      000538 24 03            [12]  819 	add	a,#0x03
      00053A FD               [12]  820 	mov	r5,a
      00053B 08               [12]  821 	inc	r0
      00053C E2               [24]  822 	movx	a,@r0
      00053D 34 00            [12]  823 	addc	a,#0x00
      00053F FE               [12]  824 	mov	r6,a
      000540 08               [12]  825 	inc	r0
      000541 E2               [24]  826 	movx	a,@r0
      000542 FF               [12]  827 	mov	r7,a
      000543 8D 82            [24]  828 	mov	dpl,r5
      000545 8E 83            [24]  829 	mov	dph,r6
      000547 8F F0            [24]  830 	mov	b,r7
      000549 12 15 ED         [24]  831 	lcall	__gptrget
      00054C FD               [12]  832 	mov	r5,a
      00054D 78 09            [12]  833 	mov	r0,#___gpio_setBits_PARM_2
      00054F 74 01            [12]  834 	mov	a,#0x01
      000551 5D               [12]  835 	anl	a,r5
      000552 F2               [24]  836 	movx	@r0,a
      000553 78 0D            [12]  837 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000555 79 0A            [12]  838 	mov	r1,#___gpio_setBits_PARM_3
      000557 E2               [24]  839 	movx	a,@r0
      000558 F3               [24]  840 	movx	@r1,a
      000559 08               [12]  841 	inc	r0
      00055A E2               [24]  842 	movx	a,@r0
      00055B 09               [12]  843 	inc	r1
      00055C F3               [24]  844 	movx	@r1,a
      00055D 08               [12]  845 	inc	r0
      00055E E2               [24]  846 	movx	a,@r0
      00055F 09               [12]  847 	inc	r1
      000560 F3               [24]  848 	movx	@r1,a
      000561 85 92 82         [24]  849 	mov	dpl,_P1M0
      000564 12 03 37         [24]  850 	lcall	___gpio_setBits
      000567 85 82 92         [24]  851 	mov	_P1M0,dpl
                                    852 ;	gpio-hal.c:134: break;
      00056A 22               [24]  853 	ret
                                    854 ;	gpio-hal.c:140: case GPIO_PORT2:
      00056B                        855 00104$:
                                    856 ;	gpio-hal.c:141: P2M1 = __gpio_setBits(P2M1, gpioConfig->portMode & 2, gpioConfig);
      00056B 78 0D            [12]  857 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00056D E2               [24]  858 	movx	a,@r0
      00056E 24 03            [12]  859 	add	a,#0x03
      000570 FD               [12]  860 	mov	r5,a
      000571 08               [12]  861 	inc	r0
      000572 E2               [24]  862 	movx	a,@r0
      000573 34 00            [12]  863 	addc	a,#0x00
      000575 FE               [12]  864 	mov	r6,a
      000576 08               [12]  865 	inc	r0
      000577 E2               [24]  866 	movx	a,@r0
      000578 FF               [12]  867 	mov	r7,a
      000579 8D 82            [24]  868 	mov	dpl,r5
      00057B 8E 83            [24]  869 	mov	dph,r6
      00057D 8F F0            [24]  870 	mov	b,r7
      00057F 12 15 ED         [24]  871 	lcall	__gptrget
      000582 FD               [12]  872 	mov	r5,a
      000583 78 09            [12]  873 	mov	r0,#___gpio_setBits_PARM_2
      000585 74 02            [12]  874 	mov	a,#0x02
      000587 5D               [12]  875 	anl	a,r5
      000588 F2               [24]  876 	movx	@r0,a
      000589 78 0D            [12]  877 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00058B 79 0A            [12]  878 	mov	r1,#___gpio_setBits_PARM_3
      00058D E2               [24]  879 	movx	a,@r0
      00058E F3               [24]  880 	movx	@r1,a
      00058F 08               [12]  881 	inc	r0
      000590 E2               [24]  882 	movx	a,@r0
      000591 09               [12]  883 	inc	r1
      000592 F3               [24]  884 	movx	@r1,a
      000593 08               [12]  885 	inc	r0
      000594 E2               [24]  886 	movx	a,@r0
      000595 09               [12]  887 	inc	r1
      000596 F3               [24]  888 	movx	@r1,a
      000597 85 95 82         [24]  889 	mov	dpl,_P2M1
      00059A 12 03 37         [24]  890 	lcall	___gpio_setBits
      00059D 85 82 95         [24]  891 	mov	_P2M1,dpl
                                    892 ;	gpio-hal.c:142: P2M0 = __gpio_setBits(P2M0, gpioConfig->portMode & 1, gpioConfig);
      0005A0 78 0D            [12]  893 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0005A2 E2               [24]  894 	movx	a,@r0
      0005A3 24 03            [12]  895 	add	a,#0x03
      0005A5 FD               [12]  896 	mov	r5,a
      0005A6 08               [12]  897 	inc	r0
      0005A7 E2               [24]  898 	movx	a,@r0
      0005A8 34 00            [12]  899 	addc	a,#0x00
      0005AA FE               [12]  900 	mov	r6,a
      0005AB 08               [12]  901 	inc	r0
      0005AC E2               [24]  902 	movx	a,@r0
      0005AD FF               [12]  903 	mov	r7,a
      0005AE 8D 82            [24]  904 	mov	dpl,r5
      0005B0 8E 83            [24]  905 	mov	dph,r6
      0005B2 8F F0            [24]  906 	mov	b,r7
      0005B4 12 15 ED         [24]  907 	lcall	__gptrget
      0005B7 FD               [12]  908 	mov	r5,a
      0005B8 78 09            [12]  909 	mov	r0,#___gpio_setBits_PARM_2
      0005BA 74 01            [12]  910 	mov	a,#0x01
      0005BC 5D               [12]  911 	anl	a,r5
      0005BD F2               [24]  912 	movx	@r0,a
      0005BE 78 0D            [12]  913 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0005C0 79 0A            [12]  914 	mov	r1,#___gpio_setBits_PARM_3
      0005C2 E2               [24]  915 	movx	a,@r0
      0005C3 F3               [24]  916 	movx	@r1,a
      0005C4 08               [12]  917 	inc	r0
      0005C5 E2               [24]  918 	movx	a,@r0
      0005C6 09               [12]  919 	inc	r1
      0005C7 F3               [24]  920 	movx	@r1,a
      0005C8 08               [12]  921 	inc	r0
      0005C9 E2               [24]  922 	movx	a,@r0
      0005CA 09               [12]  923 	inc	r1
      0005CB F3               [24]  924 	movx	@r1,a
      0005CC 85 96 82         [24]  925 	mov	dpl,_P2M0
      0005CF 12 03 37         [24]  926 	lcall	___gpio_setBits
      0005D2 85 82 96         [24]  927 	mov	_P2M0,dpl
                                    928 ;	gpio-hal.c:170: break;
      0005D5 22               [24]  929 	ret
                                    930 ;	gpio-hal.c:175: case GPIO_PORT3:
      0005D6                        931 00105$:
                                    932 ;	gpio-hal.c:176: P3M1 = __gpio_setBits(P3M1, gpioConfig->portMode & 2, gpioConfig);
      0005D6 78 0D            [12]  933 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0005D8 E2               [24]  934 	movx	a,@r0
      0005D9 24 03            [12]  935 	add	a,#0x03
      0005DB FD               [12]  936 	mov	r5,a
      0005DC 08               [12]  937 	inc	r0
      0005DD E2               [24]  938 	movx	a,@r0
      0005DE 34 00            [12]  939 	addc	a,#0x00
      0005E0 FE               [12]  940 	mov	r6,a
      0005E1 08               [12]  941 	inc	r0
      0005E2 E2               [24]  942 	movx	a,@r0
      0005E3 FF               [12]  943 	mov	r7,a
      0005E4 8D 82            [24]  944 	mov	dpl,r5
      0005E6 8E 83            [24]  945 	mov	dph,r6
      0005E8 8F F0            [24]  946 	mov	b,r7
      0005EA 12 15 ED         [24]  947 	lcall	__gptrget
      0005ED FD               [12]  948 	mov	r5,a
      0005EE 78 09            [12]  949 	mov	r0,#___gpio_setBits_PARM_2
      0005F0 74 02            [12]  950 	mov	a,#0x02
      0005F2 5D               [12]  951 	anl	a,r5
      0005F3 F2               [24]  952 	movx	@r0,a
      0005F4 78 0D            [12]  953 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0005F6 79 0A            [12]  954 	mov	r1,#___gpio_setBits_PARM_3
      0005F8 E2               [24]  955 	movx	a,@r0
      0005F9 F3               [24]  956 	movx	@r1,a
      0005FA 08               [12]  957 	inc	r0
      0005FB E2               [24]  958 	movx	a,@r0
      0005FC 09               [12]  959 	inc	r1
      0005FD F3               [24]  960 	movx	@r1,a
      0005FE 08               [12]  961 	inc	r0
      0005FF E2               [24]  962 	movx	a,@r0
      000600 09               [12]  963 	inc	r1
      000601 F3               [24]  964 	movx	@r1,a
      000602 85 B1 82         [24]  965 	mov	dpl,_P3M1
      000605 12 03 37         [24]  966 	lcall	___gpio_setBits
      000608 85 82 B1         [24]  967 	mov	_P3M1,dpl
                                    968 ;	gpio-hal.c:177: P3M0 = __gpio_setBits(P3M0, gpioConfig->portMode & 1, gpioConfig);
      00060B 78 0D            [12]  969 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00060D E2               [24]  970 	movx	a,@r0
      00060E 24 03            [12]  971 	add	a,#0x03
      000610 FD               [12]  972 	mov	r5,a
      000611 08               [12]  973 	inc	r0
      000612 E2               [24]  974 	movx	a,@r0
      000613 34 00            [12]  975 	addc	a,#0x00
      000615 FE               [12]  976 	mov	r6,a
      000616 08               [12]  977 	inc	r0
      000617 E2               [24]  978 	movx	a,@r0
      000618 FF               [12]  979 	mov	r7,a
      000619 8D 82            [24]  980 	mov	dpl,r5
      00061B 8E 83            [24]  981 	mov	dph,r6
      00061D 8F F0            [24]  982 	mov	b,r7
      00061F 12 15 ED         [24]  983 	lcall	__gptrget
      000622 FD               [12]  984 	mov	r5,a
      000623 78 09            [12]  985 	mov	r0,#___gpio_setBits_PARM_2
      000625 74 01            [12]  986 	mov	a,#0x01
      000627 5D               [12]  987 	anl	a,r5
      000628 F2               [24]  988 	movx	@r0,a
      000629 78 0D            [12]  989 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      00062B 79 0A            [12]  990 	mov	r1,#___gpio_setBits_PARM_3
      00062D E2               [24]  991 	movx	a,@r0
      00062E F3               [24]  992 	movx	@r1,a
      00062F 08               [12]  993 	inc	r0
      000630 E2               [24]  994 	movx	a,@r0
      000631 09               [12]  995 	inc	r1
      000632 F3               [24]  996 	movx	@r1,a
      000633 08               [12]  997 	inc	r0
      000634 E2               [24]  998 	movx	a,@r0
      000635 09               [12]  999 	inc	r1
      000636 F3               [24] 1000 	movx	@r1,a
      000637 85 B2 82         [24] 1001 	mov	dpl,_P3M0
      00063A 12 03 37         [24] 1002 	lcall	___gpio_setBits
      00063D 85 82 B2         [24] 1003 	mov	_P3M0,dpl
                                   1004 ;	gpio-hal.c:205: break;
      000640 22               [24] 1005 	ret
                                   1006 ;	gpio-hal.c:210: case GPIO_PORT4:
      000641                       1007 00106$:
                                   1008 ;	gpio-hal.c:211: P4M1 = __gpio_setBits(P4M1, gpioConfig->portMode & 2, gpioConfig);
      000641 78 0D            [12] 1009 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000643 E2               [24] 1010 	movx	a,@r0
      000644 24 03            [12] 1011 	add	a,#0x03
      000646 FD               [12] 1012 	mov	r5,a
      000647 08               [12] 1013 	inc	r0
      000648 E2               [24] 1014 	movx	a,@r0
      000649 34 00            [12] 1015 	addc	a,#0x00
      00064B FE               [12] 1016 	mov	r6,a
      00064C 08               [12] 1017 	inc	r0
      00064D E2               [24] 1018 	movx	a,@r0
      00064E FF               [12] 1019 	mov	r7,a
      00064F 8D 82            [24] 1020 	mov	dpl,r5
      000651 8E 83            [24] 1021 	mov	dph,r6
      000653 8F F0            [24] 1022 	mov	b,r7
      000655 12 15 ED         [24] 1023 	lcall	__gptrget
      000658 FD               [12] 1024 	mov	r5,a
      000659 78 09            [12] 1025 	mov	r0,#___gpio_setBits_PARM_2
      00065B 74 02            [12] 1026 	mov	a,#0x02
      00065D 5D               [12] 1027 	anl	a,r5
      00065E F2               [24] 1028 	movx	@r0,a
      00065F 78 0D            [12] 1029 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000661 79 0A            [12] 1030 	mov	r1,#___gpio_setBits_PARM_3
      000663 E2               [24] 1031 	movx	a,@r0
      000664 F3               [24] 1032 	movx	@r1,a
      000665 08               [12] 1033 	inc	r0
      000666 E2               [24] 1034 	movx	a,@r0
      000667 09               [12] 1035 	inc	r1
      000668 F3               [24] 1036 	movx	@r1,a
      000669 08               [12] 1037 	inc	r0
      00066A E2               [24] 1038 	movx	a,@r0
      00066B 09               [12] 1039 	inc	r1
      00066C F3               [24] 1040 	movx	@r1,a
      00066D 85 B3 82         [24] 1041 	mov	dpl,_P4M1
      000670 12 03 37         [24] 1042 	lcall	___gpio_setBits
      000673 85 82 B3         [24] 1043 	mov	_P4M1,dpl
                                   1044 ;	gpio-hal.c:212: P4M0 = __gpio_setBits(P4M0, gpioConfig->portMode & 1, gpioConfig);
      000676 78 0D            [12] 1045 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000678 E2               [24] 1046 	movx	a,@r0
      000679 24 03            [12] 1047 	add	a,#0x03
      00067B FD               [12] 1048 	mov	r5,a
      00067C 08               [12] 1049 	inc	r0
      00067D E2               [24] 1050 	movx	a,@r0
      00067E 34 00            [12] 1051 	addc	a,#0x00
      000680 FE               [12] 1052 	mov	r6,a
      000681 08               [12] 1053 	inc	r0
      000682 E2               [24] 1054 	movx	a,@r0
      000683 FF               [12] 1055 	mov	r7,a
      000684 8D 82            [24] 1056 	mov	dpl,r5
      000686 8E 83            [24] 1057 	mov	dph,r6
      000688 8F F0            [24] 1058 	mov	b,r7
      00068A 12 15 ED         [24] 1059 	lcall	__gptrget
      00068D FD               [12] 1060 	mov	r5,a
      00068E 78 09            [12] 1061 	mov	r0,#___gpio_setBits_PARM_2
      000690 74 01            [12] 1062 	mov	a,#0x01
      000692 5D               [12] 1063 	anl	a,r5
      000693 F2               [24] 1064 	movx	@r0,a
      000694 78 0D            [12] 1065 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000696 79 0A            [12] 1066 	mov	r1,#___gpio_setBits_PARM_3
      000698 E2               [24] 1067 	movx	a,@r0
      000699 F3               [24] 1068 	movx	@r1,a
      00069A 08               [12] 1069 	inc	r0
      00069B E2               [24] 1070 	movx	a,@r0
      00069C 09               [12] 1071 	inc	r1
      00069D F3               [24] 1072 	movx	@r1,a
      00069E 08               [12] 1073 	inc	r0
      00069F E2               [24] 1074 	movx	a,@r0
      0006A0 09               [12] 1075 	inc	r1
      0006A1 F3               [24] 1076 	movx	@r1,a
      0006A2 85 B4 82         [24] 1077 	mov	dpl,_P4M0
      0006A5 12 03 37         [24] 1078 	lcall	___gpio_setBits
      0006A8 85 82 B4         [24] 1079 	mov	_P4M0,dpl
                                   1080 ;	gpio-hal.c:240: break;
                                   1081 ;	gpio-hal.c:245: case GPIO_PORT5:
      0006AB 22               [24] 1082 	ret
      0006AC                       1083 00107$:
                                   1084 ;	gpio-hal.c:246: P5M1 = __gpio_setBits(P5M1, gpioConfig->portMode & 2, gpioConfig);
      0006AC 78 0D            [12] 1085 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0006AE E2               [24] 1086 	movx	a,@r0
      0006AF 24 03            [12] 1087 	add	a,#0x03
      0006B1 FD               [12] 1088 	mov	r5,a
      0006B2 08               [12] 1089 	inc	r0
      0006B3 E2               [24] 1090 	movx	a,@r0
      0006B4 34 00            [12] 1091 	addc	a,#0x00
      0006B6 FE               [12] 1092 	mov	r6,a
      0006B7 08               [12] 1093 	inc	r0
      0006B8 E2               [24] 1094 	movx	a,@r0
      0006B9 FF               [12] 1095 	mov	r7,a
      0006BA 8D 82            [24] 1096 	mov	dpl,r5
      0006BC 8E 83            [24] 1097 	mov	dph,r6
      0006BE 8F F0            [24] 1098 	mov	b,r7
      0006C0 12 15 ED         [24] 1099 	lcall	__gptrget
      0006C3 FD               [12] 1100 	mov	r5,a
      0006C4 78 09            [12] 1101 	mov	r0,#___gpio_setBits_PARM_2
      0006C6 74 02            [12] 1102 	mov	a,#0x02
      0006C8 5D               [12] 1103 	anl	a,r5
      0006C9 F2               [24] 1104 	movx	@r0,a
      0006CA 78 0D            [12] 1105 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0006CC 79 0A            [12] 1106 	mov	r1,#___gpio_setBits_PARM_3
      0006CE E2               [24] 1107 	movx	a,@r0
      0006CF F3               [24] 1108 	movx	@r1,a
      0006D0 08               [12] 1109 	inc	r0
      0006D1 E2               [24] 1110 	movx	a,@r0
      0006D2 09               [12] 1111 	inc	r1
      0006D3 F3               [24] 1112 	movx	@r1,a
      0006D4 08               [12] 1113 	inc	r0
      0006D5 E2               [24] 1114 	movx	a,@r0
      0006D6 09               [12] 1115 	inc	r1
      0006D7 F3               [24] 1116 	movx	@r1,a
      0006D8 85 C9 82         [24] 1117 	mov	dpl,_P5M1
      0006DB 12 03 37         [24] 1118 	lcall	___gpio_setBits
      0006DE 85 82 C9         [24] 1119 	mov	_P5M1,dpl
                                   1120 ;	gpio-hal.c:247: P5M0 = __gpio_setBits(P5M0, gpioConfig->portMode & 1, gpioConfig);
      0006E1 78 0D            [12] 1121 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      0006E3 E2               [24] 1122 	movx	a,@r0
      0006E4 24 03            [12] 1123 	add	a,#0x03
      0006E6 FD               [12] 1124 	mov	r5,a
      0006E7 08               [12] 1125 	inc	r0
      0006E8 E2               [24] 1126 	movx	a,@r0
      0006E9 34 00            [12] 1127 	addc	a,#0x00
      0006EB FE               [12] 1128 	mov	r6,a
      0006EC 08               [12] 1129 	inc	r0
      0006ED E2               [24] 1130 	movx	a,@r0
      0006EE FF               [12] 1131 	mov	r7,a
      0006EF 8D 82            [24] 1132 	mov	dpl,r5
      0006F1 8E 83            [24] 1133 	mov	dph,r6
      0006F3 8F F0            [24] 1134 	mov	b,r7
      0006F5 12 15 ED         [24] 1135 	lcall	__gptrget
      0006F8 FD               [12] 1136 	mov	r5,a
      0006F9 78 09            [12] 1137 	mov	r0,#___gpio_setBits_PARM_2
      0006FB 74 01            [12] 1138 	mov	a,#0x01
      0006FD 5D               [12] 1139 	anl	a,r5
      0006FE F2               [24] 1140 	movx	@r0,a
      0006FF 78 0D            [12] 1141 	mov	r0,#_gpioConfigure_gpioConfig_65536_10
      000701 79 0A            [12] 1142 	mov	r1,#___gpio_setBits_PARM_3
      000703 E2               [24] 1143 	movx	a,@r0
      000704 F3               [24] 1144 	movx	@r1,a
      000705 08               [12] 1145 	inc	r0
      000706 E2               [24] 1146 	movx	a,@r0
      000707 09               [12] 1147 	inc	r1
      000708 F3               [24] 1148 	movx	@r1,a
      000709 08               [12] 1149 	inc	r0
      00070A E2               [24] 1150 	movx	a,@r0
      00070B 09               [12] 1151 	inc	r1
      00070C F3               [24] 1152 	movx	@r1,a
      00070D 85 CA 82         [24] 1153 	mov	dpl,_P5M0
      000710 12 03 37         [24] 1154 	lcall	___gpio_setBits
      000713 85 82 CA         [24] 1155 	mov	_P5M0,dpl
                                   1156 ;	gpio-hal.c:348: }
                                   1157 ;	gpio-hal.c:349: }
      000716 22               [24] 1158 	ret
                                   1159 ;------------------------------------------------------------
                                   1160 ;Allocation info for local variables in function 'gpioRead'
                                   1161 ;------------------------------------------------------------
                                   1162 ;	gpio-hal.c:351: uint8_t gpioRead(GpioConfig *gpioConfig) {
                                   1163 ;	-----------------------------------------
                                   1164 ;	 function gpioRead
                                   1165 ;	-----------------------------------------
      000717                       1166 _gpioRead:
                                   1167 ;	gpio-hal.c:352: uint8_t value = 0;
                                   1168 ;	gpio-hal.c:354: switch (gpioConfig->port) {
      000717 AD 82            [24] 1169 	mov	r5,dpl
      000719 AE 83            [24] 1170 	mov	r6,dph
      00071B AF F0            [24] 1171 	mov	r7,b
      00071D 7C 00            [12] 1172 	mov	r4,#0x00
      00071F 12 15 ED         [24] 1173 	lcall	__gptrget
      000722 FB               [12] 1174 	mov  r3,a
      000723 24 FA            [12] 1175 	add	a,#0xff - 0x05
      000725 40 28            [24] 1176 	jc	00107$
      000727 EB               [12] 1177 	mov	a,r3
      000728 2B               [12] 1178 	add	a,r3
                                   1179 ;	gpio-hal.c:359: case GPIO_PORT0:
      000729 90 07 2D         [24] 1180 	mov	dptr,#00115$
      00072C 73               [24] 1181 	jmp	@a+dptr
      00072D                       1182 00115$:
      00072D 80 0A            [24] 1183 	sjmp	00101$
      00072F 80 0C            [24] 1184 	sjmp	00102$
      000731 80 0E            [24] 1185 	sjmp	00103$
      000733 80 10            [24] 1186 	sjmp	00104$
      000735 80 12            [24] 1187 	sjmp	00105$
      000737 80 14            [24] 1188 	sjmp	00106$
      000739                       1189 00101$:
                                   1190 ;	gpio-hal.c:360: value = P0;
      000739 AC 80            [24] 1191 	mov	r4,_P0
                                   1192 ;	gpio-hal.c:361: break;
                                   1193 ;	gpio-hal.c:367: case GPIO_PORT1:
      00073B 80 12            [24] 1194 	sjmp	00107$
      00073D                       1195 00102$:
                                   1196 ;	gpio-hal.c:368: value = P1;
      00073D AC 90            [24] 1197 	mov	r4,_P1
                                   1198 ;	gpio-hal.c:369: break;
                                   1199 ;	gpio-hal.c:375: case GPIO_PORT2:
      00073F 80 0E            [24] 1200 	sjmp	00107$
      000741                       1201 00103$:
                                   1202 ;	gpio-hal.c:376: value = P2;
      000741 AC A0            [24] 1203 	mov	r4,_P2
                                   1204 ;	gpio-hal.c:377: break;
                                   1205 ;	gpio-hal.c:382: case GPIO_PORT3:
      000743 80 0A            [24] 1206 	sjmp	00107$
      000745                       1207 00104$:
                                   1208 ;	gpio-hal.c:383: value = P3;
      000745 AC B0            [24] 1209 	mov	r4,_P3
                                   1210 ;	gpio-hal.c:384: break;
                                   1211 ;	gpio-hal.c:389: case GPIO_PORT4:
      000747 80 06            [24] 1212 	sjmp	00107$
      000749                       1213 00105$:
                                   1214 ;	gpio-hal.c:390: value = P4;
      000749 AC C0            [24] 1215 	mov	r4,_P4
                                   1216 ;	gpio-hal.c:391: break;
                                   1217 ;	gpio-hal.c:396: case GPIO_PORT5:
      00074B 80 02            [24] 1218 	sjmp	00107$
      00074D                       1219 00106$:
                                   1220 ;	gpio-hal.c:397: value = P5;
      00074D AC C8            [24] 1221 	mov	r4,_P5
                                   1222 ;	gpio-hal.c:415: }
      00074F                       1223 00107$:
                                   1224 ;	gpio-hal.c:417: return (value & gpioConfig->__setMask) >> gpioConfig->pin;
      00074F 74 04            [12] 1225 	mov	a,#0x04
      000751 2D               [12] 1226 	add	a,r5
      000752 F9               [12] 1227 	mov	r1,a
      000753 E4               [12] 1228 	clr	a
      000754 3E               [12] 1229 	addc	a,r6
      000755 FA               [12] 1230 	mov	r2,a
      000756 8F 03            [24] 1231 	mov	ar3,r7
      000758 89 82            [24] 1232 	mov	dpl,r1
      00075A 8A 83            [24] 1233 	mov	dph,r2
      00075C 8B F0            [24] 1234 	mov	b,r3
      00075E 12 15 ED         [24] 1235 	lcall	__gptrget
      000761 52 04            [12] 1236 	anl	ar4,a
      000763 0D               [12] 1237 	inc	r5
      000764 BD 00 01         [24] 1238 	cjne	r5,#0x00,00116$
      000767 0E               [12] 1239 	inc	r6
      000768                       1240 00116$:
      000768 8D 82            [24] 1241 	mov	dpl,r5
      00076A 8E 83            [24] 1242 	mov	dph,r6
      00076C 8F F0            [24] 1243 	mov	b,r7
      00076E 12 15 ED         [24] 1244 	lcall	__gptrget
      000771 FD               [12] 1245 	mov	r5,a
      000772 8D F0            [24] 1246 	mov	b,r5
      000774 05 F0            [12] 1247 	inc	b
      000776 EC               [12] 1248 	mov	a,r4
      000777 80 02            [24] 1249 	sjmp	00118$
      000779                       1250 00117$:
      000779 C3               [12] 1251 	clr	c
      00077A 13               [12] 1252 	rrc	a
      00077B                       1253 00118$:
      00077B D5 F0 FB         [24] 1254 	djnz	b,00117$
      00077E F5 82            [12] 1255 	mov	dpl,a
                                   1256 ;	gpio-hal.c:418: }
      000780 22               [24] 1257 	ret
                                   1258 ;------------------------------------------------------------
                                   1259 ;Allocation info for local variables in function 'gpioWrite'
                                   1260 ;------------------------------------------------------------
                                   1261 ;	gpio-hal.c:420: void gpioWrite(GpioConfig *gpioConfig, uint8_t value) {
                                   1262 ;	-----------------------------------------
                                   1263 ;	 function gpioWrite
                                   1264 ;	-----------------------------------------
      000781                       1265 _gpioWrite:
      000781 AF F0            [24] 1266 	mov	r7,b
      000783 AE 83            [24] 1267 	mov	r6,dph
      000785 E5 82            [12] 1268 	mov	a,dpl
      000787 78 11            [12] 1269 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      000789 F2               [24] 1270 	movx	@r0,a
      00078A EE               [12] 1271 	mov	a,r6
      00078B 08               [12] 1272 	inc	r0
      00078C F2               [24] 1273 	movx	@r0,a
      00078D EF               [12] 1274 	mov	a,r7
      00078E 08               [12] 1275 	inc	r0
      00078F F2               [24] 1276 	movx	@r0,a
                                   1277 ;	gpio-hal.c:421: if (gpioConfig->count == 1) {
      000790 78 11            [12] 1278 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      000792 E2               [24] 1279 	movx	a,@r0
      000793 24 02            [12] 1280 	add	a,#0x02
      000795 FA               [12] 1281 	mov	r2,a
      000796 08               [12] 1282 	inc	r0
      000797 E2               [24] 1283 	movx	a,@r0
      000798 34 00            [12] 1284 	addc	a,#0x00
      00079A FB               [12] 1285 	mov	r3,a
      00079B 08               [12] 1286 	inc	r0
      00079C E2               [24] 1287 	movx	a,@r0
      00079D FC               [12] 1288 	mov	r4,a
      00079E 8A 82            [24] 1289 	mov	dpl,r2
      0007A0 8B 83            [24] 1290 	mov	dph,r3
      0007A2 8C F0            [24] 1291 	mov	b,r4
      0007A4 12 15 ED         [24] 1292 	lcall	__gptrget
      0007A7 FA               [12] 1293 	mov	r2,a
      0007A8 BA 01 13         [24] 1294 	cjne	r2,#0x01,00102$
                                   1295 ;	gpio-hal.c:425: value = value ? 1 : 0;
      0007AB 78 10            [12] 1296 	mov	r0,#_gpioWrite_PARM_2
      0007AD E2               [24] 1297 	movx	a,@r0
      0007AE 60 06            [24] 1298 	jz	00112$
      0007B0 7B 01            [12] 1299 	mov	r3,#0x01
      0007B2 7C 00            [12] 1300 	mov	r4,#0x00
      0007B4 80 04            [24] 1301 	sjmp	00113$
      0007B6                       1302 00112$:
      0007B6 7B 00            [12] 1303 	mov	r3,#0x00
      0007B8 7C 00            [12] 1304 	mov	r4,#0x00
      0007BA                       1305 00113$:
      0007BA 78 10            [12] 1306 	mov	r0,#_gpioWrite_PARM_2
      0007BC EB               [12] 1307 	mov	a,r3
      0007BD F2               [24] 1308 	movx	@r0,a
      0007BE                       1309 00102$:
                                   1310 ;	gpio-hal.c:428: value = (value << gpioConfig->pin) & gpioConfig->__setMask;
      0007BE 78 11            [12] 1311 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      0007C0 E2               [24] 1312 	movx	a,@r0
      0007C1 24 01            [12] 1313 	add	a,#0x01
      0007C3 FA               [12] 1314 	mov	r2,a
      0007C4 08               [12] 1315 	inc	r0
      0007C5 E2               [24] 1316 	movx	a,@r0
      0007C6 34 00            [12] 1317 	addc	a,#0x00
      0007C8 FB               [12] 1318 	mov	r3,a
      0007C9 08               [12] 1319 	inc	r0
      0007CA E2               [24] 1320 	movx	a,@r0
      0007CB FC               [12] 1321 	mov	r4,a
      0007CC 8A 82            [24] 1322 	mov	dpl,r2
      0007CE 8B 83            [24] 1323 	mov	dph,r3
      0007D0 8C F0            [24] 1324 	mov	b,r4
      0007D2 12 15 ED         [24] 1325 	lcall	__gptrget
      0007D5 FA               [12] 1326 	mov	r2,a
      0007D6 8A F0            [24] 1327 	mov	b,r2
      0007D8 05 F0            [12] 1328 	inc	b
      0007DA 78 10            [12] 1329 	mov	r0,#_gpioWrite_PARM_2
      0007DC E2               [24] 1330 	movx	a,@r0
      0007DD 80 02            [24] 1331 	sjmp	00131$
      0007DF                       1332 00129$:
      0007DF 25 E0            [12] 1333 	add	a,acc
      0007E1                       1334 00131$:
      0007E1 D5 F0 FB         [24] 1335 	djnz	b,00129$
      0007E4 FA               [12] 1336 	mov	r2,a
      0007E5 78 11            [12] 1337 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      0007E7 E2               [24] 1338 	movx	a,@r0
      0007E8 24 04            [12] 1339 	add	a,#0x04
      0007EA FB               [12] 1340 	mov	r3,a
      0007EB 08               [12] 1341 	inc	r0
      0007EC E2               [24] 1342 	movx	a,@r0
      0007ED 34 00            [12] 1343 	addc	a,#0x00
      0007EF FC               [12] 1344 	mov	r4,a
      0007F0 08               [12] 1345 	inc	r0
      0007F1 E2               [24] 1346 	movx	a,@r0
      0007F2 FF               [12] 1347 	mov	r7,a
      0007F3 8B 82            [24] 1348 	mov	dpl,r3
      0007F5 8C 83            [24] 1349 	mov	dph,r4
      0007F7 8F F0            [24] 1350 	mov	b,r7
      0007F9 12 15 ED         [24] 1351 	lcall	__gptrget
      0007FC FB               [12] 1352 	mov	r3,a
      0007FD 5A               [12] 1353 	anl	a,r2
      0007FE 78 10            [12] 1354 	mov	r0,#_gpioWrite_PARM_2
      000800 F2               [24] 1355 	movx	@r0,a
                                   1356 ;	gpio-hal.c:430: switch (gpioConfig->port) {
      000801 78 11            [12] 1357 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      000803 E2               [24] 1358 	movx	a,@r0
      000804 F5 82            [12] 1359 	mov	dpl,a
      000806 08               [12] 1360 	inc	r0
      000807 E2               [24] 1361 	movx	a,@r0
      000808 F5 83            [12] 1362 	mov	dph,a
      00080A 08               [12] 1363 	inc	r0
      00080B E2               [24] 1364 	movx	a,@r0
      00080C F5 F0            [12] 1365 	mov	b,a
      00080E 12 15 ED         [24] 1366 	lcall	__gptrget
      000811 FF               [12] 1367 	mov  r7,a
      000812 24 FA            [12] 1368 	add	a,#0xff - 0x05
      000814 50 01            [24] 1369 	jnc	00132$
      000816 22               [24] 1370 	ret
      000817                       1371 00132$:
      000817 EF               [12] 1372 	mov	a,r7
      000818 2F               [12] 1373 	add	a,r7
      000819 2F               [12] 1374 	add	a,r7
      00081A 90 08 1E         [24] 1375 	mov	dptr,#00133$
      00081D 73               [24] 1376 	jmp	@a+dptr
      00081E                       1377 00133$:
      00081E 02 08 30         [24] 1378 	ljmp	00103$
      000821 02 08 53         [24] 1379 	ljmp	00104$
      000824 02 08 76         [24] 1380 	ljmp	00105$
      000827 02 08 99         [24] 1381 	ljmp	00106$
      00082A 02 08 BC         [24] 1382 	ljmp	00107$
      00082D 02 08 DF         [24] 1383 	ljmp	00108$
                                   1384 ;	gpio-hal.c:435: case GPIO_PORT0:
      000830                       1385 00103$:
                                   1386 ;	gpio-hal.c:436: P0 = (P0 & gpioConfig->__clearMask) | value;
      000830 78 11            [12] 1387 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      000832 E2               [24] 1388 	movx	a,@r0
      000833 24 05            [12] 1389 	add	a,#0x05
      000835 FD               [12] 1390 	mov	r5,a
      000836 08               [12] 1391 	inc	r0
      000837 E2               [24] 1392 	movx	a,@r0
      000838 34 00            [12] 1393 	addc	a,#0x00
      00083A FE               [12] 1394 	mov	r6,a
      00083B 08               [12] 1395 	inc	r0
      00083C E2               [24] 1396 	movx	a,@r0
      00083D FF               [12] 1397 	mov	r7,a
      00083E 8D 82            [24] 1398 	mov	dpl,r5
      000840 8E 83            [24] 1399 	mov	dph,r6
      000842 8F F0            [24] 1400 	mov	b,r7
      000844 12 15 ED         [24] 1401 	lcall	__gptrget
      000847 FD               [12] 1402 	mov	r5,a
      000848 E5 80            [12] 1403 	mov	a,_P0
      00084A 52 05            [12] 1404 	anl	ar5,a
      00084C 78 10            [12] 1405 	mov	r0,#_gpioWrite_PARM_2
      00084E E2               [24] 1406 	movx	a,@r0
      00084F 4D               [12] 1407 	orl	a,r5
      000850 F5 80            [12] 1408 	mov	_P0,a
                                   1409 ;	gpio-hal.c:437: break;
      000852 22               [24] 1410 	ret
                                   1411 ;	gpio-hal.c:443: case GPIO_PORT1:
      000853                       1412 00104$:
                                   1413 ;	gpio-hal.c:444: P1 = (P1 & gpioConfig->__clearMask) | value;
      000853 78 11            [12] 1414 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      000855 E2               [24] 1415 	movx	a,@r0
      000856 24 05            [12] 1416 	add	a,#0x05
      000858 FD               [12] 1417 	mov	r5,a
      000859 08               [12] 1418 	inc	r0
      00085A E2               [24] 1419 	movx	a,@r0
      00085B 34 00            [12] 1420 	addc	a,#0x00
      00085D FE               [12] 1421 	mov	r6,a
      00085E 08               [12] 1422 	inc	r0
      00085F E2               [24] 1423 	movx	a,@r0
      000860 FF               [12] 1424 	mov	r7,a
      000861 8D 82            [24] 1425 	mov	dpl,r5
      000863 8E 83            [24] 1426 	mov	dph,r6
      000865 8F F0            [24] 1427 	mov	b,r7
      000867 12 15 ED         [24] 1428 	lcall	__gptrget
      00086A FD               [12] 1429 	mov	r5,a
      00086B E5 90            [12] 1430 	mov	a,_P1
      00086D 52 05            [12] 1431 	anl	ar5,a
      00086F 78 10            [12] 1432 	mov	r0,#_gpioWrite_PARM_2
      000871 E2               [24] 1433 	movx	a,@r0
      000872 4D               [12] 1434 	orl	a,r5
      000873 F5 90            [12] 1435 	mov	_P1,a
                                   1436 ;	gpio-hal.c:445: break;
      000875 22               [24] 1437 	ret
                                   1438 ;	gpio-hal.c:451: case GPIO_PORT2:
      000876                       1439 00105$:
                                   1440 ;	gpio-hal.c:452: P2 = (P2 & gpioConfig->__clearMask) | value;
      000876 78 11            [12] 1441 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      000878 E2               [24] 1442 	movx	a,@r0
      000879 24 05            [12] 1443 	add	a,#0x05
      00087B FD               [12] 1444 	mov	r5,a
      00087C 08               [12] 1445 	inc	r0
      00087D E2               [24] 1446 	movx	a,@r0
      00087E 34 00            [12] 1447 	addc	a,#0x00
      000880 FE               [12] 1448 	mov	r6,a
      000881 08               [12] 1449 	inc	r0
      000882 E2               [24] 1450 	movx	a,@r0
      000883 FF               [12] 1451 	mov	r7,a
      000884 8D 82            [24] 1452 	mov	dpl,r5
      000886 8E 83            [24] 1453 	mov	dph,r6
      000888 8F F0            [24] 1454 	mov	b,r7
      00088A 12 15 ED         [24] 1455 	lcall	__gptrget
      00088D FD               [12] 1456 	mov	r5,a
      00088E E5 A0            [12] 1457 	mov	a,_P2
      000890 52 05            [12] 1458 	anl	ar5,a
      000892 78 10            [12] 1459 	mov	r0,#_gpioWrite_PARM_2
      000894 E2               [24] 1460 	movx	a,@r0
      000895 4D               [12] 1461 	orl	a,r5
      000896 F5 A0            [12] 1462 	mov	_P2,a
                                   1463 ;	gpio-hal.c:453: break;
                                   1464 ;	gpio-hal.c:458: case GPIO_PORT3:
      000898 22               [24] 1465 	ret
      000899                       1466 00106$:
                                   1467 ;	gpio-hal.c:459: P3 = (P3 & gpioConfig->__clearMask) | value;
      000899 78 11            [12] 1468 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      00089B E2               [24] 1469 	movx	a,@r0
      00089C 24 05            [12] 1470 	add	a,#0x05
      00089E FD               [12] 1471 	mov	r5,a
      00089F 08               [12] 1472 	inc	r0
      0008A0 E2               [24] 1473 	movx	a,@r0
      0008A1 34 00            [12] 1474 	addc	a,#0x00
      0008A3 FE               [12] 1475 	mov	r6,a
      0008A4 08               [12] 1476 	inc	r0
      0008A5 E2               [24] 1477 	movx	a,@r0
      0008A6 FF               [12] 1478 	mov	r7,a
      0008A7 8D 82            [24] 1479 	mov	dpl,r5
      0008A9 8E 83            [24] 1480 	mov	dph,r6
      0008AB 8F F0            [24] 1481 	mov	b,r7
      0008AD 12 15 ED         [24] 1482 	lcall	__gptrget
      0008B0 FD               [12] 1483 	mov	r5,a
      0008B1 E5 B0            [12] 1484 	mov	a,_P3
      0008B3 52 05            [12] 1485 	anl	ar5,a
      0008B5 78 10            [12] 1486 	mov	r0,#_gpioWrite_PARM_2
      0008B7 E2               [24] 1487 	movx	a,@r0
      0008B8 4D               [12] 1488 	orl	a,r5
      0008B9 F5 B0            [12] 1489 	mov	_P3,a
                                   1490 ;	gpio-hal.c:460: break;
                                   1491 ;	gpio-hal.c:465: case GPIO_PORT4:
      0008BB 22               [24] 1492 	ret
      0008BC                       1493 00107$:
                                   1494 ;	gpio-hal.c:466: P4 = (P4 & gpioConfig->__clearMask) | value;
      0008BC 78 11            [12] 1495 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      0008BE E2               [24] 1496 	movx	a,@r0
      0008BF 24 05            [12] 1497 	add	a,#0x05
      0008C1 FD               [12] 1498 	mov	r5,a
      0008C2 08               [12] 1499 	inc	r0
      0008C3 E2               [24] 1500 	movx	a,@r0
      0008C4 34 00            [12] 1501 	addc	a,#0x00
      0008C6 FE               [12] 1502 	mov	r6,a
      0008C7 08               [12] 1503 	inc	r0
      0008C8 E2               [24] 1504 	movx	a,@r0
      0008C9 FF               [12] 1505 	mov	r7,a
      0008CA 8D 82            [24] 1506 	mov	dpl,r5
      0008CC 8E 83            [24] 1507 	mov	dph,r6
      0008CE 8F F0            [24] 1508 	mov	b,r7
      0008D0 12 15 ED         [24] 1509 	lcall	__gptrget
      0008D3 FD               [12] 1510 	mov	r5,a
      0008D4 E5 C0            [12] 1511 	mov	a,_P4
      0008D6 52 05            [12] 1512 	anl	ar5,a
      0008D8 78 10            [12] 1513 	mov	r0,#_gpioWrite_PARM_2
      0008DA E2               [24] 1514 	movx	a,@r0
      0008DB 4D               [12] 1515 	orl	a,r5
      0008DC F5 C0            [12] 1516 	mov	_P4,a
                                   1517 ;	gpio-hal.c:467: break;
                                   1518 ;	gpio-hal.c:472: case GPIO_PORT5:
      0008DE 22               [24] 1519 	ret
      0008DF                       1520 00108$:
                                   1521 ;	gpio-hal.c:473: P5 = (P5 & gpioConfig->__clearMask) | value;
      0008DF 78 11            [12] 1522 	mov	r0,#_gpioWrite_gpioConfig_65536_18
      0008E1 E2               [24] 1523 	movx	a,@r0
      0008E2 24 05            [12] 1524 	add	a,#0x05
      0008E4 FD               [12] 1525 	mov	r5,a
      0008E5 08               [12] 1526 	inc	r0
      0008E6 E2               [24] 1527 	movx	a,@r0
      0008E7 34 00            [12] 1528 	addc	a,#0x00
      0008E9 FE               [12] 1529 	mov	r6,a
      0008EA 08               [12] 1530 	inc	r0
      0008EB E2               [24] 1531 	movx	a,@r0
      0008EC FF               [12] 1532 	mov	r7,a
      0008ED 8D 82            [24] 1533 	mov	dpl,r5
      0008EF 8E 83            [24] 1534 	mov	dph,r6
      0008F1 8F F0            [24] 1535 	mov	b,r7
      0008F3 12 15 ED         [24] 1536 	lcall	__gptrget
      0008F6 FD               [12] 1537 	mov	r5,a
      0008F7 E5 C8            [12] 1538 	mov	a,_P5
      0008F9 52 05            [12] 1539 	anl	ar5,a
      0008FB 78 10            [12] 1540 	mov	r0,#_gpioWrite_PARM_2
      0008FD E2               [24] 1541 	movx	a,@r0
      0008FE 4D               [12] 1542 	orl	a,r5
      0008FF F5 C8            [12] 1543 	mov	_P5,a
                                   1544 ;	gpio-hal.c:491: }
                                   1545 ;	gpio-hal.c:492: }
      000901 22               [24] 1546 	ret
                                   1547 	.area CSEG    (CODE)
                                   1548 	.area CONST   (CODE)
                                   1549 	.area XINIT   (CODE)
                                   1550 	.area CABS    (ABS,CODE)
