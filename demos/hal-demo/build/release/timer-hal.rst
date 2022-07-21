                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module timer_hal
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
                                    163 	.globl _startWatchdog_PARM_2
                                    164 	.globl _startTimer_PARM_5
                                    165 	.globl _startTimer_PARM_4
                                    166 	.globl _startTimer_PARM_3
                                    167 	.globl _startTimer_PARM_2
                                    168 	.globl _baudRateToSysclkDivisor
                                    169 	.globl _frequencyToSysclkDivisor
                                    170 	.globl _startTimer
                                    171 	.globl _startWatchdog
                                    172 	.globl _clearWatchdog
                                    173 ;--------------------------------------------------------
                                    174 ; special function registers
                                    175 ;--------------------------------------------------------
                                    176 	.area RSEG    (ABS,DATA)
      000000                        177 	.org 0x0000
                           0000BC   178 _ADC_CONTR	=	0x00bc
                           0000BD   179 _ADC_RESH	=	0x00bd
                           0000BE   180 _ADC_RESL	=	0x00be
                           000082   181 _DPL	=	0x0082
                           000083   182 _DPH	=	0x0083
                           008382   183 _DP	=	0x8382
                           0000A2   184 _DPS	=	0x00a2
                           000080   185 _P0	=	0x0080
                           000093   186 _P0M1	=	0x0093
                           000094   187 _P0M0	=	0x0094
                           000090   188 _P1	=	0x0090
                           000091   189 _P1M1	=	0x0091
                           000092   190 _P1M0	=	0x0092
                           0000A0   191 _P2	=	0x00a0
                           000095   192 _P2M1	=	0x0095
                           000096   193 _P2M0	=	0x0096
                           0000B0   194 _P3	=	0x00b0
                           0000B1   195 _P3M1	=	0x00b1
                           0000B2   196 _P3M0	=	0x00b2
                           0000C0   197 _P4	=	0x00c0
                           0000B3   198 _P4M1	=	0x00b3
                           0000B4   199 _P4M0	=	0x00b4
                           0000C8   200 _P5	=	0x00c8
                           0000C9   201 _P5M1	=	0x00c9
                           0000CA   202 _P5M0	=	0x00ca
                           0000C2   203 _IAP_DATA	=	0x00c2
                           0000C3   204 _IAP_ADDRH	=	0x00c3
                           0000C4   205 _IAP_ADDRL	=	0x00c4
                           00C3C4   206 _IAP_ADDR	=	0xc3c4
                           0000C5   207 _IAP_CMD	=	0x00c5
                           0000C6   208 _IAP_TRIG	=	0x00c6
                           0000C7   209 _IAP_CONTR	=	0x00c7
                           0000A8   210 _IE1	=	0x00a8
                           0000AF   211 _IE2	=	0x00af
                           0000B8   212 _IP1L	=	0x00b8
                           0000B7   213 _IP1H	=	0x00b7
                           0000B5   214 _IP2L	=	0x00b5
                           0000B6   215 _IP2H	=	0x00b6
                           000081   216 _SP	=	0x0081
                           0000D0   217 _PSW	=	0x00d0
                           0000E0   218 _ACC	=	0x00e0
                           0000F0   219 _B	=	0x00f0
                           000087   220 _PCON	=	0x0087
                           00008F   221 _WAKE_CLKO	=	0x008f
                           0000A2   222 _P_SW1	=	0x00a2
                           00009D   223 _P1ASF	=	0x009d
                           0000BB   224 _P4SW	=	0x00bb
                           0000A1   225 _BUS_SPEED	=	0x00a1
                           0000D8   226 _CCON	=	0x00d8
                           0000D9   227 _CMOD	=	0x00d9
                           0000DA   228 _CCAPM0	=	0x00da
                           0000DB   229 _CCAPM1	=	0x00db
                           0000E9   230 _CL	=	0x00e9
                           0000F9   231 _CH	=	0x00f9
                           00F9E9   232 _PCA_CTR	=	0xf9e9
                           0000EA   233 _CCAP0L	=	0x00ea
                           0000EB   234 _CCAP1L	=	0x00eb
                           0000FA   235 _CCAP0H	=	0x00fa
                           0000FB   236 _CCAP1H	=	0x00fb
                           00FAEA   237 _CCAP0	=	0xfaea
                           00FBEB   238 _CCAP1	=	0xfbeb
                           0000F2   239 _PCA_PWM0	=	0x00f2
                           0000F3   240 _PCA_PWM1	=	0x00f3
                           0000CD   241 _SPSTAT	=	0x00cd
                           0000CE   242 _SPCTL	=	0x00ce
                           0000CF   243 _SPDAT	=	0x00cf
                           000097   244 _CLKDIV	=	0x0097
                           000088   245 _TCON	=	0x0088
                           000089   246 _TMOD	=	0x0089
                           00008A   247 _T0L	=	0x008a
                           00008C   248 _T0H	=	0x008c
                           008C8A   249 _T0	=	0x8c8a
                           00008B   250 _T1L	=	0x008b
                           00008D   251 _T1H	=	0x008d
                           008D8B   252 _T1	=	0x8d8b
                           00009C   253 _BRT	=	0x009c
                           00008E   254 _AUXR	=	0x008e
                           0000C1   255 _WDT_CONTR	=	0x00c1
                           0000A9   256 _SADDR	=	0x00a9
                           0000B9   257 _SADEN	=	0x00b9
                           000098   258 _S1CON	=	0x0098
                           000099   259 _S1BUF	=	0x0099
                           00009A   260 _S2CON	=	0x009a
                           00009B   261 _S2BUF	=	0x009b
                                    262 ;--------------------------------------------------------
                                    263 ; special function bits
                                    264 ;--------------------------------------------------------
                                    265 	.area RSEG    (ABS,DATA)
      000000                        266 	.org 0x0000
                           000080   267 _P0_0	=	0x0080
                           000081   268 _P0_1	=	0x0081
                           000082   269 _P0_2	=	0x0082
                           000083   270 _P0_3	=	0x0083
                           000084   271 _P0_4	=	0x0084
                           000085   272 _P0_5	=	0x0085
                           000086   273 _P0_6	=	0x0086
                           000087   274 _P0_7	=	0x0087
                           000090   275 _P1_0	=	0x0090
                           000091   276 _P1_1	=	0x0091
                           000092   277 _P1_2	=	0x0092
                           000093   278 _P1_3	=	0x0093
                           000094   279 _P1_4	=	0x0094
                           000095   280 _P1_5	=	0x0095
                           000096   281 _P1_6	=	0x0096
                           000097   282 _P1_7	=	0x0097
                           0000A0   283 _P2_0	=	0x00a0
                           0000A1   284 _P2_1	=	0x00a1
                           0000A2   285 _P2_2	=	0x00a2
                           0000A3   286 _P2_3	=	0x00a3
                           0000A4   287 _P2_4	=	0x00a4
                           0000A5   288 _P2_5	=	0x00a5
                           0000A6   289 _P2_6	=	0x00a6
                           0000A7   290 _P2_7	=	0x00a7
                           0000B0   291 _P3_0	=	0x00b0
                           0000B1   292 _P3_1	=	0x00b1
                           0000B2   293 _P3_2	=	0x00b2
                           0000B3   294 _P3_3	=	0x00b3
                           0000B4   295 _P3_4	=	0x00b4
                           0000B5   296 _P3_5	=	0x00b5
                           0000B6   297 _P3_6	=	0x00b6
                           0000B7   298 _P3_7	=	0x00b7
                           0000C0   299 _P4_0	=	0x00c0
                           0000C1   300 _P4_1	=	0x00c1
                           0000C2   301 _P4_2	=	0x00c2
                           0000C3   302 _P4_3	=	0x00c3
                           0000C4   303 _P4_4	=	0x00c4
                           0000C5   304 _P4_5	=	0x00c5
                           0000C6   305 _P4_6	=	0x00c6
                           0000C7   306 _P4_7	=	0x00c7
                           0000C8   307 _P5_0	=	0x00c8
                           0000C9   308 _P5_1	=	0x00c9
                           0000CA   309 _P5_2	=	0x00ca
                           0000CB   310 _P5_3	=	0x00cb
                           0000CC   311 _P5_4	=	0x00cc
                           0000CD   312 _P5_5	=	0x00cd
                           000088   313 _IT0	=	0x0088
                           000089   314 _INT0IF	=	0x0089
                           00008A   315 _IT1	=	0x008a
                           00008B   316 _INT1IF	=	0x008b
                           0000AF   317 _EA	=	0x00af
                           0000D0   318 _P	=	0x00d0
                           0000D1   319 _F1	=	0x00d1
                           0000D2   320 _OV	=	0x00d2
                           0000D3   321 _RS0	=	0x00d3
                           0000D4   322 _RS1	=	0x00d4
                           0000D5   323 _F0	=	0x00d5
                           0000D6   324 _AC	=	0x00d6
                           0000D7   325 _CY	=	0x00d7
                           0000D8   326 _CCF0	=	0x00d8
                           0000D9   327 _CCF1	=	0x00d9
                           0000DE   328 _CR	=	0x00de
                           0000DF   329 _CF	=	0x00df
                           00008C   330 _T0R	=	0x008c
                           00008D   331 _T0IF	=	0x008d
                           00008E   332 _T1R	=	0x008e
                           00008F   333 _T1IF	=	0x008f
                           00009F   334 _S1SM0_FE	=	0x009f
                                    335 ;--------------------------------------------------------
                                    336 ; overlayable register banks
                                    337 ;--------------------------------------------------------
                                    338 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        339 	.ds 8
                                    340 ;--------------------------------------------------------
                                    341 ; internal ram data
                                    342 ;--------------------------------------------------------
                                    343 	.area DSEG    (DATA)
                                    344 ;--------------------------------------------------------
                                    345 ; overlayable items in internal ram
                                    346 ;--------------------------------------------------------
                                    347 ;--------------------------------------------------------
                                    348 ; indirectly addressable internal ram data
                                    349 ;--------------------------------------------------------
                                    350 	.area ISEG    (DATA)
                                    351 ;--------------------------------------------------------
                                    352 ; absolute internal ram data
                                    353 ;--------------------------------------------------------
                                    354 	.area IABS    (ABS,DATA)
                                    355 	.area IABS    (ABS,DATA)
                                    356 ;--------------------------------------------------------
                                    357 ; bit data
                                    358 ;--------------------------------------------------------
                                    359 	.area BSEG    (BIT)
                                    360 ;--------------------------------------------------------
                                    361 ; paged external ram data
                                    362 ;--------------------------------------------------------
                                    363 	.area PSEG    (PAG,XDATA)
      000000                        364 _startTimer_PARM_2:
      000000                        365 	.ds 4
      000004                        366 _startTimer_PARM_3:
      000004                        367 	.ds 1
      000005                        368 _startTimer_PARM_4:
      000005                        369 	.ds 1
      000006                        370 _startTimer_PARM_5:
      000006                        371 	.ds 1
      000007                        372 _startTimer_rc_65536_10:
      000007                        373 	.ds 1
      000008                        374 _startWatchdog_PARM_2:
      000008                        375 	.ds 1
                                    376 ;--------------------------------------------------------
                                    377 ; external ram data
                                    378 ;--------------------------------------------------------
                                    379 	.area XSEG    (XDATA)
                                    380 ;--------------------------------------------------------
                                    381 ; absolute external ram data
                                    382 ;--------------------------------------------------------
                                    383 	.area XABS    (ABS,XDATA)
                                    384 ;--------------------------------------------------------
                                    385 ; external initialized ram data
                                    386 ;--------------------------------------------------------
                                    387 	.area XISEG   (XDATA)
                                    388 	.area HOME    (CODE)
                                    389 	.area GSINIT0 (CODE)
                                    390 	.area GSINIT1 (CODE)
                                    391 	.area GSINIT2 (CODE)
                                    392 	.area GSINIT3 (CODE)
                                    393 	.area GSINIT4 (CODE)
                                    394 	.area GSINIT5 (CODE)
                                    395 	.area GSINIT  (CODE)
                                    396 	.area GSFINAL (CODE)
                                    397 	.area CSEG    (CODE)
                                    398 ;--------------------------------------------------------
                                    399 ; global & static initialisations
                                    400 ;--------------------------------------------------------
                                    401 	.area HOME    (CODE)
                                    402 	.area GSINIT  (CODE)
                                    403 	.area GSFINAL (CODE)
                                    404 	.area GSINIT  (CODE)
                                    405 ;--------------------------------------------------------
                                    406 ; Home
                                    407 ;--------------------------------------------------------
                                    408 	.area HOME    (CODE)
                                    409 	.area HOME    (CODE)
                                    410 ;--------------------------------------------------------
                                    411 ; code
                                    412 ;--------------------------------------------------------
                                    413 	.area CSEG    (CODE)
                                    414 ;------------------------------------------------------------
                                    415 ;Allocation info for local variables in function 'baudRateToSysclkDivisor'
                                    416 ;------------------------------------------------------------
                                    417 ;	timer-hal.c:47: uint32_t baudRateToSysclkDivisor(uint32_t baudRate) {
                                    418 ;	-----------------------------------------
                                    419 ;	 function baudRateToSysclkDivisor
                                    420 ;	-----------------------------------------
      0000DB                        421 _baudRateToSysclkDivisor:
                           000007   422 	ar7 = 0x07
                           000006   423 	ar6 = 0x06
                           000005   424 	ar5 = 0x05
                           000004   425 	ar4 = 0x04
                           000003   426 	ar3 = 0x03
                           000002   427 	ar2 = 0x02
                           000001   428 	ar1 = 0x01
                           000000   429 	ar0 = 0x00
      0000DB AC 82            [24]  430 	mov	r4,dpl
      0000DD AD 83            [24]  431 	mov	r5,dph
      0000DF AE F0            [24]  432 	mov	r6,b
      0000E1 FF               [12]  433 	mov	r7,a
                                    434 ;	timer-hal.c:53: divisor = (MCU_FREQ / baudRate / 32UL);
      0000E2 78 C9            [12]  435 	mov	r0,#__divulong_PARM_2
      0000E4 EC               [12]  436 	mov	a,r4
      0000E5 F2               [24]  437 	movx	@r0,a
      0000E6 ED               [12]  438 	mov	a,r5
      0000E7 08               [12]  439 	inc	r0
      0000E8 F2               [24]  440 	movx	@r0,a
      0000E9 EE               [12]  441 	mov	a,r6
      0000EA 08               [12]  442 	inc	r0
      0000EB F2               [24]  443 	movx	@r0,a
      0000EC EF               [12]  444 	mov	a,r7
      0000ED 08               [12]  445 	inc	r0
      0000EE F2               [24]  446 	movx	@r0,a
      0000EF 90 C0 00         [24]  447 	mov	dptr,#0xc000
      0000F2 75 F0 A8         [24]  448 	mov	b,#0xa8
      0000F5 E4               [12]  449 	clr	a
      0000F6 12 15 35         [24]  450 	lcall	__divulong
      0000F9 AC 82            [24]  451 	mov	r4,dpl
      0000FB AD 83            [24]  452 	mov	r5,dph
      0000FD AE F0            [24]  453 	mov	r6,b
      0000FF FF               [12]  454 	mov	r7,a
      000100 ED               [12]  455 	mov	a,r5
      000101 C4               [12]  456 	swap	a
      000102 03               [12]  457 	rr	a
      000103 CC               [12]  458 	xch	a,r4
      000104 C4               [12]  459 	swap	a
      000105 03               [12]  460 	rr	a
      000106 54 07            [12]  461 	anl	a,#0x07
      000108 6C               [12]  462 	xrl	a,r4
      000109 CC               [12]  463 	xch	a,r4
      00010A 54 07            [12]  464 	anl	a,#0x07
      00010C CC               [12]  465 	xch	a,r4
      00010D 6C               [12]  466 	xrl	a,r4
      00010E CC               [12]  467 	xch	a,r4
      00010F FD               [12]  468 	mov	r5,a
      000110 EE               [12]  469 	mov	a,r6
      000111 C4               [12]  470 	swap	a
      000112 03               [12]  471 	rr	a
      000113 54 F8            [12]  472 	anl	a,#0xf8
      000115 4D               [12]  473 	orl	a,r5
      000116 FD               [12]  474 	mov	r5,a
      000117 EF               [12]  475 	mov	a,r7
      000118 C4               [12]  476 	swap	a
      000119 03               [12]  477 	rr	a
      00011A CE               [12]  478 	xch	a,r6
      00011B C4               [12]  479 	swap	a
      00011C 03               [12]  480 	rr	a
      00011D 54 07            [12]  481 	anl	a,#0x07
      00011F 6E               [12]  482 	xrl	a,r6
      000120 CE               [12]  483 	xch	a,r6
      000121 54 07            [12]  484 	anl	a,#0x07
      000123 CE               [12]  485 	xch	a,r6
      000124 6E               [12]  486 	xrl	a,r6
      000125 CE               [12]  487 	xch	a,r6
                                    488 ;	timer-hal.c:62: return divisor;
      000126 8C 82            [24]  489 	mov	dpl,r4
      000128 8D 83            [24]  490 	mov	dph,r5
      00012A 8E F0            [24]  491 	mov	b,r6
                                    492 ;	timer-hal.c:63: }
      00012C 22               [24]  493 	ret
                                    494 ;------------------------------------------------------------
                                    495 ;Allocation info for local variables in function 'frequencyToSysclkDivisor'
                                    496 ;------------------------------------------------------------
                                    497 ;	timer-hal.c:65: uint32_t frequencyToSysclkDivisor(uint32_t frequency) {
                                    498 ;	-----------------------------------------
                                    499 ;	 function frequencyToSysclkDivisor
                                    500 ;	-----------------------------------------
      00012D                        501 _frequencyToSysclkDivisor:
      00012D AC 82            [24]  502 	mov	r4,dpl
      00012F AD 83            [24]  503 	mov	r5,dph
      000131 AE F0            [24]  504 	mov	r6,b
      000133 FF               [12]  505 	mov	r7,a
                                    506 ;	timer-hal.c:66: return MCU_FREQ / frequency;
      000134 78 C9            [12]  507 	mov	r0,#__divulong_PARM_2
      000136 EC               [12]  508 	mov	a,r4
      000137 F2               [24]  509 	movx	@r0,a
      000138 ED               [12]  510 	mov	a,r5
      000139 08               [12]  511 	inc	r0
      00013A F2               [24]  512 	movx	@r0,a
      00013B EE               [12]  513 	mov	a,r6
      00013C 08               [12]  514 	inc	r0
      00013D F2               [24]  515 	movx	@r0,a
      00013E EF               [12]  516 	mov	a,r7
      00013F 08               [12]  517 	inc	r0
      000140 F2               [24]  518 	movx	@r0,a
      000141 90 C0 00         [24]  519 	mov	dptr,#0xc000
      000144 75 F0 A8         [24]  520 	mov	b,#0xa8
      000147 E4               [12]  521 	clr	a
                                    522 ;	timer-hal.c:67: }
      000148 02 15 35         [24]  523 	ljmp	__divulong
                                    524 ;------------------------------------------------------------
                                    525 ;Allocation info for local variables in function 'startTimer'
                                    526 ;------------------------------------------------------------
                                    527 ;	timer-hal.c:69: Timer_Status startTimer(Timer timer, uint32_t sysclkDivisor, Timer_Output enableOutput, Timer_Interrupt enableInterrupt, Timer_Control timerControl) {
                                    528 ;	-----------------------------------------
                                    529 ;	 function startTimer
                                    530 ;	-----------------------------------------
      00014B                        531 _startTimer:
      00014B AF 82            [24]  532 	mov	r7,dpl
                                    533 ;	timer-hal.c:70: Timer_Status rc = TIMER_FREQUENCY_OK;
      00014D 78 07            [12]  534 	mov	r0,#_startTimer_rc_65536_10
      00014F E4               [12]  535 	clr	a
      000150 F2               [24]  536 	movx	@r0,a
                                    537 ;	timer-hal.c:71: uint8_t sysclkDiv1 = 1;
      000151 7D 01            [12]  538 	mov	r5,#0x01
                                    539 ;	timer-hal.c:73: if (sysclkDivisor == 0) {
      000153 78 00            [12]  540 	mov	r0,#_startTimer_PARM_2
      000155 E2               [24]  541 	movx	a,@r0
      000156 F5 F0            [12]  542 	mov	b,a
      000158 08               [12]  543 	inc	r0
      000159 E2               [24]  544 	movx	a,@r0
      00015A 42 F0            [12]  545 	orl	b,a
      00015C 08               [12]  546 	inc	r0
      00015D E2               [24]  547 	movx	a,@r0
      00015E 42 F0            [12]  548 	orl	b,a
      000160 08               [12]  549 	inc	r0
      000161 E2               [24]  550 	movx	a,@r0
      000162 45 F0            [12]  551 	orl	a,b
      000164 70 08            [24]  552 	jnz	00107$
                                    553 ;	timer-hal.c:75: rc = TIMER_FREQUENCY_TOO_HIGH;
      000166 78 07            [12]  554 	mov	r0,#_startTimer_rc_65536_10
      000168 74 01            [12]  555 	mov	a,#0x01
      00016A F2               [24]  556 	movx	@r0,a
      00016B 02 01 E3         [24]  557 	ljmp	00108$
      00016E                        558 00107$:
                                    559 ;	timer-hal.c:76: } else if (sysclkDivisor >= (COUNTER_MAX * 12UL)) {
      00016E 78 00            [12]  560 	mov	r0,#_startTimer_PARM_2
      000170 C3               [12]  561 	clr	c
      000171 08               [12]  562 	inc	r0
      000172 E2               [24]  563 	movx	a,@r0
      000173 94 0C            [12]  564 	subb	a,#0x0c
      000175 08               [12]  565 	inc	r0
      000176 E2               [24]  566 	movx	a,@r0
      000177 94 00            [12]  567 	subb	a,#0x00
      000179 08               [12]  568 	inc	r0
      00017A E2               [24]  569 	movx	a,@r0
      00017B 94 00            [12]  570 	subb	a,#0x00
      00017D 40 07            [24]  571 	jc	00104$
                                    572 ;	timer-hal.c:78: rc = TIMER_FREQUENCY_TOO_LOW;
      00017F 78 07            [12]  573 	mov	r0,#_startTimer_rc_65536_10
      000181 74 02            [12]  574 	mov	a,#0x02
      000183 F2               [24]  575 	movx	@r0,a
      000184 80 5D            [24]  576 	sjmp	00108$
      000186                        577 00104$:
                                    578 ;	timer-hal.c:80: if (sysclkDivisor > COUNTER_MAX) {
      000186 78 00            [12]  579 	mov	r0,#_startTimer_PARM_2
      000188 C3               [12]  580 	clr	c
      000189 E2               [24]  581 	movx	a,@r0
      00018A F5 F0            [12]  582 	mov	b,a
      00018C E4               [12]  583 	clr	a
      00018D 95 F0            [12]  584 	subb	a,b
      00018F 08               [12]  585 	inc	r0
      000190 E2               [24]  586 	movx	a,@r0
      000191 F5 F0            [12]  587 	mov	b,a
      000193 74 01            [12]  588 	mov	a,#0x01
      000195 95 F0            [12]  589 	subb	a,b
      000197 08               [12]  590 	inc	r0
      000198 E2               [24]  591 	movx	a,@r0
      000199 F5 F0            [12]  592 	mov	b,a
      00019B E4               [12]  593 	clr	a
      00019C 95 F0            [12]  594 	subb	a,b
      00019E 08               [12]  595 	inc	r0
      00019F E2               [24]  596 	movx	a,@r0
      0001A0 F5 F0            [12]  597 	mov	b,a
      0001A2 E4               [12]  598 	clr	a
      0001A3 95 F0            [12]  599 	subb	a,b
      0001A5 50 3C            [24]  600 	jnc	00108$
                                    601 ;	timer-hal.c:82: sysclkDiv1 = 0;
      0001A7 7D 00            [12]  602 	mov	r5,#0x00
                                    603 ;	timer-hal.c:83: sysclkDivisor /= 12UL;
      0001A9 78 C9            [12]  604 	mov	r0,#__divulong_PARM_2
      0001AB 74 0C            [12]  605 	mov	a,#0x0c
      0001AD F2               [24]  606 	movx	@r0,a
      0001AE E4               [12]  607 	clr	a
      0001AF 08               [12]  608 	inc	r0
      0001B0 F2               [24]  609 	movx	@r0,a
      0001B1 08               [12]  610 	inc	r0
      0001B2 F2               [24]  611 	movx	@r0,a
      0001B3 08               [12]  612 	inc	r0
      0001B4 F2               [24]  613 	movx	@r0,a
      0001B5 78 00            [12]  614 	mov	r0,#_startTimer_PARM_2
      0001B7 E2               [24]  615 	movx	a,@r0
      0001B8 F5 82            [12]  616 	mov	dpl,a
      0001BA 08               [12]  617 	inc	r0
      0001BB E2               [24]  618 	movx	a,@r0
      0001BC F5 83            [12]  619 	mov	dph,a
      0001BE 08               [12]  620 	inc	r0
      0001BF E2               [24]  621 	movx	a,@r0
      0001C0 F5 F0            [12]  622 	mov	b,a
      0001C2 08               [12]  623 	inc	r0
      0001C3 E2               [24]  624 	movx	a,@r0
      0001C4 C0 07            [24]  625 	push	ar7
      0001C6 C0 05            [24]  626 	push	ar5
      0001C8 12 15 35         [24]  627 	lcall	__divulong
      0001CB AA 82            [24]  628 	mov	r2,dpl
      0001CD AB 83            [24]  629 	mov	r3,dph
      0001CF AC F0            [24]  630 	mov	r4,b
      0001D1 FE               [12]  631 	mov	r6,a
      0001D2 D0 05            [24]  632 	pop	ar5
      0001D4 D0 07            [24]  633 	pop	ar7
      0001D6 78 00            [12]  634 	mov	r0,#_startTimer_PARM_2
      0001D8 EA               [12]  635 	mov	a,r2
      0001D9 F2               [24]  636 	movx	@r0,a
      0001DA EB               [12]  637 	mov	a,r3
      0001DB 08               [12]  638 	inc	r0
      0001DC F2               [24]  639 	movx	@r0,a
      0001DD EC               [12]  640 	mov	a,r4
      0001DE 08               [12]  641 	inc	r0
      0001DF F2               [24]  642 	movx	@r0,a
      0001E0 EE               [12]  643 	mov	a,r6
      0001E1 08               [12]  644 	inc	r0
      0001E2 F2               [24]  645 	movx	@r0,a
      0001E3                        646 00108$:
                                    647 ;	timer-hal.c:87: if (rc == TIMER_FREQUENCY_OK) {
      0001E3 78 07            [12]  648 	mov	r0,#_startTimer_rc_65536_10
      0001E5 E2               [24]  649 	movx	a,@r0
      0001E6 60 03            [24]  650 	jz	00195$
      0001E8 02 02 E0         [24]  651 	ljmp	00129$
      0001EB                        652 00195$:
                                    653 ;	timer-hal.c:88: uint16_t reloadValue = (uint16_t) (COUNTER_MAX - sysclkDivisor);
      0001EB 78 00            [12]  654 	mov	r0,#_startTimer_PARM_2
      0001ED E2               [24]  655 	movx	a,@r0
      0001EE FC               [12]  656 	mov	r4,a
      0001EF 08               [12]  657 	inc	r0
      0001F0 E2               [24]  658 	movx	a,@r0
      0001F1 FE               [12]  659 	mov	r6,a
      0001F2 E4               [12]  660 	clr	a
      0001F3 C3               [12]  661 	clr	c
      0001F4 9C               [12]  662 	subb	a,r4
      0001F5 FC               [12]  663 	mov	r4,a
      0001F6 74 01            [12]  664 	mov	a,#0x01
      0001F8 9E               [12]  665 	subb	a,r6
      0001F9 FE               [12]  666 	mov	r6,a
                                    667 ;	timer-hal.c:90: switch (timer) {
      0001FA BF 00 02         [24]  668 	cjne	r7,#0x00,00196$
      0001FD 80 0E            [24]  669 	sjmp	00109$
      0001FF                        670 00196$:
      0001FF BF 01 02         [24]  671 	cjne	r7,#0x01,00197$
      000202 80 61            [24]  672 	sjmp	00116$
      000204                        673 00197$:
      000204 BF 02 03         [24]  674 	cjne	r7,#0x02,00198$
      000207 02 02 BC         [24]  675 	ljmp	00123$
      00020A                        676 00198$:
      00020A 02 02 E0         [24]  677 	ljmp	00129$
                                    678 ;	timer-hal.c:91: case TIMER0:
      00020D                        679 00109$:
                                    680 ;	timer-hal.c:93: AUXR = (AUXR & ~M_T0x12) | ((sysclkDiv1 << P_T0x12) & M_T0x12);
      00020D 74 7F            [12]  681 	mov	a,#0x7f
      00020F 55 8E            [12]  682 	anl	a,_AUXR
      000211 FF               [12]  683 	mov	r7,a
      000212 8D 03            [24]  684 	mov	ar3,r5
      000214 EB               [12]  685 	mov	a,r3
      000215 03               [12]  686 	rr	a
      000216 54 80            [12]  687 	anl	a,#0x80
      000218 FB               [12]  688 	mov	r3,a
      000219 74 80            [12]  689 	mov	a,#0x80
      00021B 5B               [12]  690 	anl	a,r3
      00021C 4F               [12]  691 	orl	a,r7
      00021D F5 8E            [12]  692 	mov	_AUXR,a
                                    693 ;	timer-hal.c:96: TMOD &= 0xf0;
      00021F 53 89 F0         [24]  694 	anl	_TMOD,#0xf0
                                    695 ;	timer-hal.c:99: TMOD = (TMOD & ~M_T0_GATE) | ((timerControl << P_T0_GATE) & M_T0_GATE);
      000222 74 F7            [12]  696 	mov	a,#0xf7
      000224 55 89            [12]  697 	anl	a,_TMOD
      000226 FF               [12]  698 	mov	r7,a
      000227 78 06            [12]  699 	mov	r0,#_startTimer_PARM_5
      000229 E2               [24]  700 	movx	a,@r0
      00022A C4               [12]  701 	swap	a
      00022B 03               [12]  702 	rr	a
      00022C 54 F8            [12]  703 	anl	a,#0xf8
      00022E FB               [12]  704 	mov	r3,a
      00022F 74 08            [12]  705 	mov	a,#0x08
      000231 5B               [12]  706 	anl	a,r3
      000232 4F               [12]  707 	orl	a,r7
      000233 F5 89            [12]  708 	mov	_TMOD,a
                                    709 ;	timer-hal.c:103: TMOD |= 2;
      000235 43 89 02         [24]  710 	orl	_TMOD,#0x02
                                    711 ;	timer-hal.c:105: if (enableOutput == TIMER_OUTPUT_ENABLE) {
      000238 78 04            [12]  712 	mov	r0,#_startTimer_PARM_3
      00023A E2               [24]  713 	movx	a,@r0
      00023B B4 01 05         [24]  714 	cjne	a,#0x01,00111$
                                    715 ;	timer-hal.c:106: WAKE_CLKO |= M_T0CLKO;
      00023E 43 8F 01         [24]  716 	orl	_WAKE_CLKO,#0x01
      000241 80 03            [24]  717 	sjmp	00112$
      000243                        718 00111$:
                                    719 ;	timer-hal.c:108: WAKE_CLKO &= ~M_T0CLKO;
      000243 53 8F FE         [24]  720 	anl	_WAKE_CLKO,#0xfe
      000246                        721 00112$:
                                    722 ;	timer-hal.c:111: T0H = T0L = reloadValue;
      000246 8C 07            [24]  723 	mov	ar7,r4
      000248 8F 8A            [24]  724 	mov	_T0L,r7
      00024A 8F 8C            [24]  725 	mov	_T0H,r7
                                    726 ;	timer-hal.c:122: if (enableInterrupt == TIMER_INTERRUPT_ENABLE) {
      00024C 78 05            [12]  727 	mov	r0,#_startTimer_PARM_4
      00024E E2               [24]  728 	movx	a,@r0
      00024F B4 01 05         [24]  729 	cjne	a,#0x01,00114$
                                    730 ;	timer-hal.c:123: IE1 |= M_ET0;
      000252 43 A8 02         [24]  731 	orl	_IE1,#0x02
      000255 80 03            [24]  732 	sjmp	00115$
      000257                        733 00114$:
                                    734 ;	timer-hal.c:125: IE1 &= ~M_ET0;
      000257 53 A8 FD         [24]  735 	anl	_IE1,#0xfd
      00025A                        736 00115$:
                                    737 ;	timer-hal.c:129: TCON = (TCON & ~M_T0IF) | M_T0R;
      00025A 74 DF            [12]  738 	mov	a,#0xdf
      00025C 55 88            [12]  739 	anl	a,_TCON
      00025E 44 10            [12]  740 	orl	a,#0x10
      000260 F5 88            [12]  741 	mov	_TCON,a
                                    742 ;	timer-hal.c:130: break;
      000262 02 02 E0         [24]  743 	ljmp	00129$
                                    744 ;	timer-hal.c:133: case TIMER1:
      000265                        745 00116$:
                                    746 ;	timer-hal.c:136: TMOD = (TMOD & 0x0f) | (2 << P_T1_M);
      000265 E5 89            [12]  747 	mov	a,_TMOD
      000267 54 0F            [12]  748 	anl	a,#0x0f
      000269 44 20            [12]  749 	orl	a,#0x20
      00026B F5 89            [12]  750 	mov	_TMOD,a
                                    751 ;	timer-hal.c:138: if (enableOutput == TIMER_OUTPUT_ENABLE) {
      00026D 78 04            [12]  752 	mov	r0,#_startTimer_PARM_3
      00026F E2               [24]  753 	movx	a,@r0
      000270 B4 01 05         [24]  754 	cjne	a,#0x01,00118$
                                    755 ;	timer-hal.c:139: WAKE_CLKO |= M_T1CLKO;
      000273 43 8F 02         [24]  756 	orl	_WAKE_CLKO,#0x02
      000276 80 03            [24]  757 	sjmp	00119$
      000278                        758 00118$:
                                    759 ;	timer-hal.c:141: WAKE_CLKO &= ~M_T1CLKO;
      000278 53 8F FD         [24]  760 	anl	_WAKE_CLKO,#0xfd
      00027B                        761 00119$:
                                    762 ;	timer-hal.c:145: T1H = T1L = reloadValue;
      00027B 8C 07            [24]  763 	mov	ar7,r4
      00027D 8F 8B            [24]  764 	mov	_T1L,r7
      00027F 8F 8D            [24]  765 	mov	_T1H,r7
                                    766 ;	timer-hal.c:161: TMOD = (TMOD & ~M_T1_GATE) | ((timerControl << P_T1_GATE) & M_T1_GATE);
      000281 74 7F            [12]  767 	mov	a,#0x7f
      000283 55 89            [12]  768 	anl	a,_TMOD
      000285 FF               [12]  769 	mov	r7,a
      000286 78 06            [12]  770 	mov	r0,#_startTimer_PARM_5
      000288 E2               [24]  771 	movx	a,@r0
      000289 03               [12]  772 	rr	a
      00028A 54 80            [12]  773 	anl	a,#0x80
      00028C FB               [12]  774 	mov	r3,a
      00028D 74 80            [12]  775 	mov	a,#0x80
      00028F 5B               [12]  776 	anl	a,r3
      000290 4F               [12]  777 	orl	a,r7
      000291 F5 89            [12]  778 	mov	_TMOD,a
                                    779 ;	timer-hal.c:164: AUXR = (sysclkDiv1) ? (AUXR | M_T1x12) : (AUXR & ~M_T1x12);
      000293 ED               [12]  780 	mov	a,r5
      000294 60 07            [24]  781 	jz	00132$
      000296 74 40            [12]  782 	mov	a,#0x40
      000298 45 8E            [12]  783 	orl	a,_AUXR
      00029A FF               [12]  784 	mov	r7,a
      00029B 80 05            [24]  785 	sjmp	00133$
      00029D                        786 00132$:
      00029D 74 BF            [12]  787 	mov	a,#0xbf
      00029F 55 8E            [12]  788 	anl	a,_AUXR
      0002A1 FF               [12]  789 	mov	r7,a
      0002A2                        790 00133$:
      0002A2 8F 8E            [24]  791 	mov	_AUXR,r7
                                    792 ;	timer-hal.c:166: if (enableInterrupt == TIMER_INTERRUPT_ENABLE) {
      0002A4 78 05            [12]  793 	mov	r0,#_startTimer_PARM_4
      0002A6 E2               [24]  794 	movx	a,@r0
      0002A7 B4 01 05         [24]  795 	cjne	a,#0x01,00121$
                                    796 ;	timer-hal.c:167: IE1 |= M_ET1;
      0002AA 43 A8 08         [24]  797 	orl	_IE1,#0x08
      0002AD 80 03            [24]  798 	sjmp	00122$
      0002AF                        799 00121$:
                                    800 ;	timer-hal.c:169: IE1 &= ~M_ET1;
      0002AF 53 A8 F7         [24]  801 	anl	_IE1,#0xf7
      0002B2                        802 00122$:
                                    803 ;	timer-hal.c:173: TCON = (TCON & ~M_T1IF) | M_T1R;
      0002B2 74 7F            [12]  804 	mov	a,#0x7f
      0002B4 55 88            [12]  805 	anl	a,_TCON
      0002B6 44 40            [12]  806 	orl	a,#0x40
      0002B8 F5 88            [12]  807 	mov	_TCON,a
                                    808 ;	timer-hal.c:174: break;
                                    809 ;	timer-hal.c:177: case TIMER2:
      0002BA 80 24            [24]  810 	sjmp	00129$
      0002BC                        811 00123$:
                                    812 ;	timer-hal.c:193: if (enableOutput == TIMER_OUTPUT_ENABLE) {
      0002BC 78 04            [12]  813 	mov	r0,#_startTimer_PARM_3
      0002BE E2               [24]  814 	movx	a,@r0
      0002BF B4 01 05         [24]  815 	cjne	a,#0x01,00125$
                                    816 ;	timer-hal.c:194: WAKE_CLKO |= M_BRTCLKO;
      0002C2 43 8F 04         [24]  817 	orl	_WAKE_CLKO,#0x04
      0002C5 80 03            [24]  818 	sjmp	00126$
      0002C7                        819 00125$:
                                    820 ;	timer-hal.c:196: WAKE_CLKO &= ~M_BRTCLKO;
      0002C7 53 8F FB         [24]  821 	anl	_WAKE_CLKO,#0xfb
      0002CA                        822 00126$:
                                    823 ;	timer-hal.c:200: BRT =  reloadValue;
      0002CA 8C 9C            [24]  824 	mov	_BRT,r4
                                    825 ;	timer-hal.c:204: AUXR = (sysclkDiv1) ? (AUXR | M_T2x12) : (AUXR & ~M_T2x12);
      0002CC ED               [12]  826 	mov	a,r5
      0002CD 60 07            [24]  827 	jz	00134$
      0002CF 74 04            [12]  828 	mov	a,#0x04
      0002D1 45 8E            [12]  829 	orl	a,_AUXR
      0002D3 FF               [12]  830 	mov	r7,a
      0002D4 80 05            [24]  831 	sjmp	00135$
      0002D6                        832 00134$:
      0002D6 74 FB            [12]  833 	mov	a,#0xfb
      0002D8 55 8E            [12]  834 	anl	a,_AUXR
      0002DA FF               [12]  835 	mov	r7,a
      0002DB                        836 00135$:
      0002DB 8F 8E            [24]  837 	mov	_AUXR,r7
                                    838 ;	timer-hal.c:220: AUXR |= M_T2R;
      0002DD 43 8E 10         [24]  839 	orl	_AUXR,#0x10
                                    840 ;	timer-hal.c:282: }
      0002E0                        841 00129$:
                                    842 ;	timer-hal.c:285: return rc;
      0002E0 78 07            [12]  843 	mov	r0,#_startTimer_rc_65536_10
      0002E2 E2               [24]  844 	movx	a,@r0
      0002E3 F5 82            [12]  845 	mov	dpl,a
                                    846 ;	timer-hal.c:286: }
      0002E5 22               [24]  847 	ret
                                    848 ;------------------------------------------------------------
                                    849 ;Allocation info for local variables in function 'startWatchdog'
                                    850 ;------------------------------------------------------------
                                    851 ;	timer-hal.c:288: void startWatchdog(WatchdogPrescaler prescaler, WatchdogIdleMode idleMode) {
                                    852 ;	-----------------------------------------
                                    853 ;	 function startWatchdog
                                    854 ;	-----------------------------------------
      0002E6                        855 _startWatchdog:
      0002E6 AF 82            [24]  856 	mov	r7,dpl
                                    857 ;	timer-hal.c:289: WDT_CONTR = M_EN_WDT | (prescaler << P_WDT_PS)
      0002E8 43 07 20         [24]  858 	orl	ar7,#0x20
                                    859 ;	timer-hal.c:290: | (idleMode == WDT_ENABLED_IN_IDLE_MODE ? M_IDL_WDT : 0);
      0002EB 78 08            [12]  860 	mov	r0,#_startWatchdog_PARM_2
      0002ED E2               [24]  861 	movx	a,@r0
      0002EE B4 01 06         [24]  862 	cjne	a,#0x01,00103$
      0002F1 7D 08            [12]  863 	mov	r5,#0x08
      0002F3 7E 00            [12]  864 	mov	r6,#0x00
      0002F5 80 04            [24]  865 	sjmp	00104$
      0002F7                        866 00103$:
      0002F7 7D 00            [12]  867 	mov	r5,#0x00
      0002F9 7E 00            [12]  868 	mov	r6,#0x00
      0002FB                        869 00104$:
      0002FB ED               [12]  870 	mov	a,r5
      0002FC 4F               [12]  871 	orl	a,r7
      0002FD F5 C1            [12]  872 	mov	_WDT_CONTR,a
                                    873 ;	timer-hal.c:291: }
      0002FF 22               [24]  874 	ret
                                    875 ;------------------------------------------------------------
                                    876 ;Allocation info for local variables in function 'clearWatchdog'
                                    877 ;------------------------------------------------------------
                                    878 ;	timer-hal.c:293: void clearWatchdog() {
                                    879 ;	-----------------------------------------
                                    880 ;	 function clearWatchdog
                                    881 ;	-----------------------------------------
      000300                        882 _clearWatchdog:
                                    883 ;	timer-hal.c:294: WDT_CONTR |= M_CLR_WDT;
      000300 43 C1 10         [24]  884 	orl	_WDT_CONTR,#0x10
                                    885 ;	timer-hal.c:295: }
      000303 22               [24]  886 	ret
                                    887 	.area CSEG    (CODE)
                                    888 	.area CONST   (CODE)
                                    889 	.area XINIT   (CODE)
                                    890 	.area CABS    (ABS,CODE)
