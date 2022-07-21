                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module uart_buffer
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
                                    163 	.globl _uartBufferInitialise
                                    164 	.globl _uartBufferLength
                                    165 	.globl _uartBufferWrite
                                    166 	.globl _uartBufferRead
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
                                    335 ; overlayable bit register bank
                                    336 ;--------------------------------------------------------
                                    337 	.area BIT_BANK	(REL,OVR,DATA)
      000021                        338 bits:
      000021                        339 	.ds 1
                           008000   340 	b0 = bits[0]
                           008100   341 	b1 = bits[1]
                           008200   342 	b2 = bits[2]
                           008300   343 	b3 = bits[3]
                           008400   344 	b4 = bits[4]
                           008500   345 	b5 = bits[5]
                           008600   346 	b6 = bits[6]
                           008700   347 	b7 = bits[7]
                                    348 ;--------------------------------------------------------
                                    349 ; internal ram data
                                    350 ;--------------------------------------------------------
                                    351 	.area DSEG    (DATA)
                                    352 ;--------------------------------------------------------
                                    353 ; overlayable items in internal ram
                                    354 ;--------------------------------------------------------
                                    355 ;--------------------------------------------------------
                                    356 ; indirectly addressable internal ram data
                                    357 ;--------------------------------------------------------
                                    358 	.area ISEG    (DATA)
                                    359 ;--------------------------------------------------------
                                    360 ; absolute internal ram data
                                    361 ;--------------------------------------------------------
                                    362 	.area IABS    (ABS,DATA)
                                    363 	.area IABS    (ABS,DATA)
                                    364 ;--------------------------------------------------------
                                    365 ; bit data
                                    366 ;--------------------------------------------------------
                                    367 	.area BSEG    (BIT)
                                    368 ;--------------------------------------------------------
                                    369 ; paged external ram data
                                    370 ;--------------------------------------------------------
                                    371 	.area PSEG    (PAG,XDATA)
                                    372 ;--------------------------------------------------------
                                    373 ; external ram data
                                    374 ;--------------------------------------------------------
                                    375 	.area XSEG    (XDATA)
                                    376 ;--------------------------------------------------------
                                    377 ; absolute external ram data
                                    378 ;--------------------------------------------------------
                                    379 	.area XABS    (ABS,XDATA)
                                    380 ;--------------------------------------------------------
                                    381 ; external initialized ram data
                                    382 ;--------------------------------------------------------
                                    383 	.area XISEG   (XDATA)
                                    384 	.area HOME    (CODE)
                                    385 	.area GSINIT0 (CODE)
                                    386 	.area GSINIT1 (CODE)
                                    387 	.area GSINIT2 (CODE)
                                    388 	.area GSINIT3 (CODE)
                                    389 	.area GSINIT4 (CODE)
                                    390 	.area GSINIT5 (CODE)
                                    391 	.area GSINIT  (CODE)
                                    392 	.area GSFINAL (CODE)
                                    393 	.area CSEG    (CODE)
                                    394 ;--------------------------------------------------------
                                    395 ; global & static initialisations
                                    396 ;--------------------------------------------------------
                                    397 	.area HOME    (CODE)
                                    398 	.area GSINIT  (CODE)
                                    399 	.area GSFINAL (CODE)
                                    400 	.area GSINIT  (CODE)
                                    401 ;--------------------------------------------------------
                                    402 ; Home
                                    403 ;--------------------------------------------------------
                                    404 	.area HOME    (CODE)
                                    405 	.area HOME    (CODE)
                                    406 ;--------------------------------------------------------
                                    407 ; code
                                    408 ;--------------------------------------------------------
                                    409 	.area CSEG    (CODE)
                                    410 ;------------------------------------------------------------
                                    411 ;Allocation info for local variables in function 'uartBufferInitialise'
                                    412 ;------------------------------------------------------------
                                    413 ;buffer                    Allocated to registers r5 r6 r7 
                                    414 ;------------------------------------------------------------
                                    415 ;	uart-buffer.c:39: void uartBufferInitialise(UartBuffer *buffer) REENTRANT {
                                    416 ;	-----------------------------------------
                                    417 ;	 function uartBufferInitialise
                                    418 ;	-----------------------------------------
      0011CC                        419 _uartBufferInitialise:
                           000007   420 	ar7 = 0x07
                           000006   421 	ar6 = 0x06
                           000005   422 	ar5 = 0x05
                           000004   423 	ar4 = 0x04
                           000003   424 	ar3 = 0x03
                           000002   425 	ar2 = 0x02
                           000001   426 	ar1 = 0x01
                           000000   427 	ar0 = 0x00
      0011CC AD 82            [24]  428 	mov	r5,dpl
      0011CE AE 83            [24]  429 	mov	r6,dph
      0011D0 AF F0            [24]  430 	mov	r7,b
                                    431 ;	uart-buffer.c:40: buffer->first = UART_BUFFER_SIZE;
      0011D2 74 10            [12]  432 	mov	a,#0x10
      0011D4 2D               [12]  433 	add	a,r5
      0011D5 FA               [12]  434 	mov	r2,a
      0011D6 E4               [12]  435 	clr	a
      0011D7 3E               [12]  436 	addc	a,r6
      0011D8 FB               [12]  437 	mov	r3,a
      0011D9 8F 04            [24]  438 	mov	ar4,r7
      0011DB 8A 82            [24]  439 	mov	dpl,r2
      0011DD 8B 83            [24]  440 	mov	dph,r3
      0011DF 8C F0            [24]  441 	mov	b,r4
      0011E1 74 10            [12]  442 	mov	a,#0x10
      0011E3 12 15 D2         [24]  443 	lcall	__gptrput
                                    444 ;	uart-buffer.c:41: buffer->last = UART_BUFFER_SIZE;
      0011E6 04               [12]  445 	inc	a
      0011E7 2D               [12]  446 	add	a,r5
      0011E8 FA               [12]  447 	mov	r2,a
      0011E9 E4               [12]  448 	clr	a
      0011EA 3E               [12]  449 	addc	a,r6
      0011EB FB               [12]  450 	mov	r3,a
      0011EC 8F 04            [24]  451 	mov	ar4,r7
      0011EE 8A 82            [24]  452 	mov	dpl,r2
      0011F0 8B 83            [24]  453 	mov	dph,r3
      0011F2 8C F0            [24]  454 	mov	b,r4
      0011F4 74 10            [12]  455 	mov	a,#0x10
      0011F6 12 15 D2         [24]  456 	lcall	__gptrput
                                    457 ;	uart-buffer.c:42: buffer->busy = 0;
      0011F9 74 12            [12]  458 	mov	a,#0x12
      0011FB 2D               [12]  459 	add	a,r5
      0011FC FD               [12]  460 	mov	r5,a
      0011FD E4               [12]  461 	clr	a
      0011FE 3E               [12]  462 	addc	a,r6
      0011FF FE               [12]  463 	mov	r6,a
      001200 8D 82            [24]  464 	mov	dpl,r5
      001202 8E 83            [24]  465 	mov	dph,r6
      001204 8F F0            [24]  466 	mov	b,r7
      001206 E4               [12]  467 	clr	a
                                    468 ;	uart-buffer.c:43: }
      001207 02 15 D2         [24]  469 	ljmp	__gptrput
                                    470 ;------------------------------------------------------------
                                    471 ;Allocation info for local variables in function 'uartBufferLength'
                                    472 ;------------------------------------------------------------
                                    473 ;buffer                    Allocated to registers r5 r6 r7 
                                    474 ;------------------------------------------------------------
                                    475 ;	uart-buffer.c:45: uint8_t uartBufferLength(UartBuffer *buffer) REENTRANT {
                                    476 ;	-----------------------------------------
                                    477 ;	 function uartBufferLength
                                    478 ;	-----------------------------------------
      00120A                        479 _uartBufferLength:
      00120A AD 82            [24]  480 	mov	r5,dpl
      00120C AE 83            [24]  481 	mov	r6,dph
      00120E AF F0            [24]  482 	mov	r7,b
                                    483 ;	uart-buffer.c:46: return (buffer->last >= buffer->first)
      001210 74 11            [12]  484 	mov	a,#0x11
      001212 2D               [12]  485 	add	a,r5
      001213 FA               [12]  486 	mov	r2,a
      001214 E4               [12]  487 	clr	a
      001215 3E               [12]  488 	addc	a,r6
      001216 FB               [12]  489 	mov	r3,a
      001217 8F 04            [24]  490 	mov	ar4,r7
      001219 8A 82            [24]  491 	mov	dpl,r2
      00121B 8B 83            [24]  492 	mov	dph,r3
      00121D 8C F0            [24]  493 	mov	b,r4
      00121F 12 15 ED         [24]  494 	lcall	__gptrget
      001222 FC               [12]  495 	mov	r4,a
      001223 74 10            [12]  496 	mov	a,#0x10
      001225 2D               [12]  497 	add	a,r5
      001226 FD               [12]  498 	mov	r5,a
      001227 E4               [12]  499 	clr	a
      001228 3E               [12]  500 	addc	a,r6
      001229 FE               [12]  501 	mov	r6,a
      00122A 8D 82            [24]  502 	mov	dpl,r5
      00122C 8E 83            [24]  503 	mov	dph,r6
      00122E 8F F0            [24]  504 	mov	b,r7
      001230 12 15 ED         [24]  505 	lcall	__gptrget
      001233 FF               [12]  506 	mov	r7,a
      001234 C3               [12]  507 	clr	c
      001235 EC               [12]  508 	mov	a,r4
      001236 9F               [12]  509 	subb	a,r7
      001237 92 08            [24]  510 	mov	b0,c
      001239 40 16            [24]  511 	jc	00103$
                                    512 ;	uart-buffer.c:47: ? (buffer->last == UART_BUFFER_SIZE
      00123B BC 10 06         [24]  513 	cjne	r4,#0x10,00105$
                                    514 ;	uart-buffer.c:48: ? 0
      00123E 7D 00            [12]  515 	mov	r5,#0x00
      001240 7E 00            [12]  516 	mov	r6,#0x00
      001242 80 1C            [24]  517 	sjmp	00104$
      001244                        518 00105$:
                                    519 ;	uart-buffer.c:49: : (buffer->last - buffer->first + 1)
      001244 EC               [12]  520 	mov	a,r4
      001245 C3               [12]  521 	clr	c
      001246 9F               [12]  522 	subb	a,r7
      001247 FB               [12]  523 	mov	r3,a
      001248 0B               [12]  524 	inc	r3
      001249 EB               [12]  525 	mov	a,r3
      00124A FD               [12]  526 	mov	r5,a
      00124B 33               [12]  527 	rlc	a
      00124C 95 E0            [12]  528 	subb	a,acc
      00124E FE               [12]  529 	mov	r6,a
      00124F 80 0F            [24]  530 	sjmp	00104$
      001251                        531 00103$:
                                    532 ;	uart-buffer.c:51: : (UART_BUFFER_SIZE - (buffer->first - buffer->last - 1));
      001251 EF               [12]  533 	mov	a,r7
      001252 C3               [12]  534 	clr	c
      001253 9C               [12]  535 	subb	a,r4
      001254 FC               [12]  536 	mov	r4,a
      001255 14               [12]  537 	dec	a
      001256 D3               [12]  538 	setb	c
      001257 94 10            [12]  539 	subb	a,#0x10
      001259 F4               [12]  540 	cpl	a
      00125A FF               [12]  541 	mov	r7,a
      00125B FD               [12]  542 	mov	r5,a
      00125C 33               [12]  543 	rlc	a
      00125D 95 E0            [12]  544 	subb	a,acc
      00125F FE               [12]  545 	mov	r6,a
      001260                        546 00104$:
      001260 8D 82            [24]  547 	mov	dpl,r5
                                    548 ;	uart-buffer.c:52: }
      001262 22               [24]  549 	ret
                                    550 ;------------------------------------------------------------
                                    551 ;Allocation info for local variables in function 'uartBufferWrite'
                                    552 ;------------------------------------------------------------
                                    553 ;data                      Allocated to stack - _bp -3
                                    554 ;buffer                    Allocated to stack - _bp +1
                                    555 ;rc                        Allocated to registers r4 
                                    556 ;sloc0                     Allocated to stack - _bp +4
                                    557 ;------------------------------------------------------------
                                    558 ;	uart-buffer.c:54: uint8_t uartBufferWrite(UartBuffer *buffer, uint8_t data) REENTRANT {
                                    559 ;	-----------------------------------------
                                    560 ;	 function uartBufferWrite
                                    561 ;	-----------------------------------------
      001263                        562 _uartBufferWrite:
      001263 C0 19            [24]  563 	push	_bp
      001265 85 81 19         [24]  564 	mov	_bp,sp
      001268 C0 82            [24]  565 	push	dpl
      00126A C0 83            [24]  566 	push	dph
      00126C C0 F0            [24]  567 	push	b
      00126E 05 81            [12]  568 	inc	sp
      001270 05 81            [12]  569 	inc	sp
      001272 05 81            [12]  570 	inc	sp
                                    571 ;	uart-buffer.c:55: uint8_t rc = 0;
      001274 7C 00            [12]  572 	mov	r4,#0x00
                                    573 ;	uart-buffer.c:57: if (uartBufferLength(buffer) < UART_BUFFER_SIZE) {
      001276 A8 19            [24]  574 	mov	r0,_bp
      001278 08               [12]  575 	inc	r0
      001279 86 82            [24]  576 	mov	dpl,@r0
      00127B 08               [12]  577 	inc	r0
      00127C 86 83            [24]  578 	mov	dph,@r0
      00127E 08               [12]  579 	inc	r0
      00127F 86 F0            [24]  580 	mov	b,@r0
      001281 C0 04            [24]  581 	push	ar4
      001283 12 12 0A         [24]  582 	lcall	_uartBufferLength
      001286 AB 82            [24]  583 	mov	r3,dpl
      001288 D0 04            [24]  584 	pop	ar4
      00128A BB 10 00         [24]  585 	cjne	r3,#0x10,00121$
      00128D                        586 00121$:
      00128D 40 03            [24]  587 	jc	00122$
      00128F 02 13 26         [24]  588 	ljmp	00106$
      001292                        589 00122$:
                                    590 ;	uart-buffer.c:58: buffer->last++;
      001292 A8 19            [24]  591 	mov	r0,_bp
      001294 08               [12]  592 	inc	r0
      001295 74 11            [12]  593 	mov	a,#0x11
      001297 26               [12]  594 	add	a,@r0
      001298 FA               [12]  595 	mov	r2,a
      001299 E4               [12]  596 	clr	a
      00129A 08               [12]  597 	inc	r0
      00129B 36               [12]  598 	addc	a,@r0
      00129C FB               [12]  599 	mov	r3,a
      00129D 08               [12]  600 	inc	r0
      00129E 86 07            [24]  601 	mov	ar7,@r0
      0012A0 8A 82            [24]  602 	mov	dpl,r2
      0012A2 8B 83            [24]  603 	mov	dph,r3
      0012A4 8F F0            [24]  604 	mov	b,r7
      0012A6 12 15 ED         [24]  605 	lcall	__gptrget
      0012A9 FE               [12]  606 	mov	r6,a
      0012AA 0E               [12]  607 	inc	r6
      0012AB 8A 82            [24]  608 	mov	dpl,r2
      0012AD 8B 83            [24]  609 	mov	dph,r3
      0012AF 8F F0            [24]  610 	mov	b,r7
      0012B1 EE               [12]  611 	mov	a,r6
      0012B2 12 15 D2         [24]  612 	lcall	__gptrput
                                    613 ;	uart-buffer.c:60: if (buffer->last >= UART_BUFFER_SIZE) {
      0012B5 BE 10 00         [24]  614 	cjne	r6,#0x10,00123$
      0012B8                        615 00123$:
      0012B8 40 0A            [24]  616 	jc	00102$
                                    617 ;	uart-buffer.c:62: buffer->last = 0;
      0012BA 8A 82            [24]  618 	mov	dpl,r2
      0012BC 8B 83            [24]  619 	mov	dph,r3
      0012BE 8F F0            [24]  620 	mov	b,r7
      0012C0 E4               [12]  621 	clr	a
      0012C1 12 15 D2         [24]  622 	lcall	__gptrput
      0012C4                        623 00102$:
                                    624 ;	uart-buffer.c:65: if (buffer->first == UART_BUFFER_SIZE) {
      0012C4 A8 19            [24]  625 	mov	r0,_bp
      0012C6 08               [12]  626 	inc	r0
      0012C7 E5 19            [12]  627 	mov	a,_bp
      0012C9 24 04            [12]  628 	add	a,#0x04
      0012CB F9               [12]  629 	mov	r1,a
      0012CC 74 10            [12]  630 	mov	a,#0x10
      0012CE 26               [12]  631 	add	a,@r0
      0012CF F7               [12]  632 	mov	@r1,a
      0012D0 E4               [12]  633 	clr	a
      0012D1 08               [12]  634 	inc	r0
      0012D2 36               [12]  635 	addc	a,@r0
      0012D3 09               [12]  636 	inc	r1
      0012D4 F7               [12]  637 	mov	@r1,a
      0012D5 08               [12]  638 	inc	r0
      0012D6 E6               [12]  639 	mov	a,@r0
      0012D7 09               [12]  640 	inc	r1
      0012D8 F7               [12]  641 	mov	@r1,a
      0012D9 E5 19            [12]  642 	mov	a,_bp
      0012DB 24 04            [12]  643 	add	a,#0x04
      0012DD F8               [12]  644 	mov	r0,a
      0012DE 86 82            [24]  645 	mov	dpl,@r0
      0012E0 08               [12]  646 	inc	r0
      0012E1 86 83            [24]  647 	mov	dph,@r0
      0012E3 08               [12]  648 	inc	r0
      0012E4 86 F0            [24]  649 	mov	b,@r0
      0012E6 12 15 ED         [24]  650 	lcall	__gptrget
      0012E9 FE               [12]  651 	mov	r6,a
      0012EA BE 10 11         [24]  652 	cjne	r6,#0x10,00104$
                                    653 ;	uart-buffer.c:67: buffer->first = 0;
      0012ED E5 19            [12]  654 	mov	a,_bp
      0012EF 24 04            [12]  655 	add	a,#0x04
      0012F1 F8               [12]  656 	mov	r0,a
      0012F2 86 82            [24]  657 	mov	dpl,@r0
      0012F4 08               [12]  658 	inc	r0
      0012F5 86 83            [24]  659 	mov	dph,@r0
      0012F7 08               [12]  660 	inc	r0
      0012F8 86 F0            [24]  661 	mov	b,@r0
      0012FA E4               [12]  662 	clr	a
      0012FB 12 15 D2         [24]  663 	lcall	__gptrput
      0012FE                        664 00104$:
                                    665 ;	uart-buffer.c:70: buffer->data[buffer->last] = data;
      0012FE 8A 82            [24]  666 	mov	dpl,r2
      001300 8B 83            [24]  667 	mov	dph,r3
      001302 8F F0            [24]  668 	mov	b,r7
      001304 12 15 ED         [24]  669 	lcall	__gptrget
      001307 FA               [12]  670 	mov	r2,a
      001308 A8 19            [24]  671 	mov	r0,_bp
      00130A 08               [12]  672 	inc	r0
      00130B EA               [12]  673 	mov	a,r2
      00130C 26               [12]  674 	add	a,@r0
      00130D FA               [12]  675 	mov	r2,a
      00130E E4               [12]  676 	clr	a
      00130F 08               [12]  677 	inc	r0
      001310 36               [12]  678 	addc	a,@r0
      001311 FF               [12]  679 	mov	r7,a
      001312 08               [12]  680 	inc	r0
      001313 86 06            [24]  681 	mov	ar6,@r0
      001315 8A 82            [24]  682 	mov	dpl,r2
      001317 8F 83            [24]  683 	mov	dph,r7
      001319 8E F0            [24]  684 	mov	b,r6
      00131B E5 19            [12]  685 	mov	a,_bp
      00131D 24 FD            [12]  686 	add	a,#0xfd
      00131F F8               [12]  687 	mov	r0,a
      001320 E6               [12]  688 	mov	a,@r0
      001321 12 15 D2         [24]  689 	lcall	__gptrput
                                    690 ;	uart-buffer.c:71: rc = 1;
      001324 7C 01            [12]  691 	mov	r4,#0x01
      001326                        692 00106$:
                                    693 ;	uart-buffer.c:74: return rc;
      001326 8C 82            [24]  694 	mov	dpl,r4
                                    695 ;	uart-buffer.c:75: }
      001328 85 19 81         [24]  696 	mov	sp,_bp
      00132B D0 19            [24]  697 	pop	_bp
      00132D 22               [24]  698 	ret
                                    699 ;------------------------------------------------------------
                                    700 ;Allocation info for local variables in function 'uartBufferRead'
                                    701 ;------------------------------------------------------------
                                    702 ;buffer                    Allocated to stack - _bp +1
                                    703 ;result                    Allocated to registers r4 
                                    704 ;sloc0                     Allocated to stack - _bp +4
                                    705 ;------------------------------------------------------------
                                    706 ;	uart-buffer.c:77: uint8_t uartBufferRead(UartBuffer *buffer) REENTRANT {
                                    707 ;	-----------------------------------------
                                    708 ;	 function uartBufferRead
                                    709 ;	-----------------------------------------
      00132E                        710 _uartBufferRead:
      00132E C0 19            [24]  711 	push	_bp
      001330 85 81 19         [24]  712 	mov	_bp,sp
      001333 C0 82            [24]  713 	push	dpl
      001335 C0 83            [24]  714 	push	dph
      001337 C0 F0            [24]  715 	push	b
      001339 05 81            [12]  716 	inc	sp
      00133B 05 81            [12]  717 	inc	sp
      00133D 05 81            [12]  718 	inc	sp
                                    719 ;	uart-buffer.c:78: uint8_t result = 0;
      00133F 7C 00            [12]  720 	mov	r4,#0x00
                                    721 ;	uart-buffer.c:80: if (buffer->first != UART_BUFFER_SIZE) {
      001341 A8 19            [24]  722 	mov	r0,_bp
      001343 08               [12]  723 	inc	r0
      001344 E5 19            [12]  724 	mov	a,_bp
      001346 24 04            [12]  725 	add	a,#0x04
      001348 F9               [12]  726 	mov	r1,a
      001349 74 10            [12]  727 	mov	a,#0x10
      00134B 26               [12]  728 	add	a,@r0
      00134C F7               [12]  729 	mov	@r1,a
      00134D E4               [12]  730 	clr	a
      00134E 08               [12]  731 	inc	r0
      00134F 36               [12]  732 	addc	a,@r0
      001350 09               [12]  733 	inc	r1
      001351 F7               [12]  734 	mov	@r1,a
      001352 08               [12]  735 	inc	r0
      001353 E6               [12]  736 	mov	a,@r0
      001354 09               [12]  737 	inc	r1
      001355 F7               [12]  738 	mov	@r1,a
      001356 E5 19            [12]  739 	mov	a,_bp
      001358 24 04            [12]  740 	add	a,#0x04
      00135A F8               [12]  741 	mov	r0,a
      00135B 86 82            [24]  742 	mov	dpl,@r0
      00135D 08               [12]  743 	inc	r0
      00135E 86 83            [24]  744 	mov	dph,@r0
      001360 08               [12]  745 	inc	r0
      001361 86 F0            [24]  746 	mov	b,@r0
      001363 12 15 ED         [24]  747 	lcall	__gptrget
      001366 FB               [12]  748 	mov	r3,a
      001367 BB 10 03         [24]  749 	cjne	r3,#0x10,00122$
      00136A 02 13 E3         [24]  750 	ljmp	00107$
      00136D                        751 00122$:
                                    752 ;	uart-buffer.c:82: result = buffer->data[buffer->first];
      00136D A8 19            [24]  753 	mov	r0,_bp
      00136F 08               [12]  754 	inc	r0
      001370 EB               [12]  755 	mov	a,r3
      001371 26               [12]  756 	add	a,@r0
      001372 FA               [12]  757 	mov	r2,a
      001373 E4               [12]  758 	clr	a
      001374 08               [12]  759 	inc	r0
      001375 36               [12]  760 	addc	a,@r0
      001376 FE               [12]  761 	mov	r6,a
      001377 08               [12]  762 	inc	r0
      001378 86 07            [24]  763 	mov	ar7,@r0
      00137A 8A 82            [24]  764 	mov	dpl,r2
      00137C 8E 83            [24]  765 	mov	dph,r6
      00137E 8F F0            [24]  766 	mov	b,r7
      001380 12 15 ED         [24]  767 	lcall	__gptrget
      001383 FC               [12]  768 	mov	r4,a
                                    769 ;	uart-buffer.c:84: if (buffer->first == buffer->last) {
      001384 A8 19            [24]  770 	mov	r0,_bp
      001386 08               [12]  771 	inc	r0
      001387 74 11            [12]  772 	mov	a,#0x11
      001389 26               [12]  773 	add	a,@r0
      00138A FD               [12]  774 	mov	r5,a
      00138B E4               [12]  775 	clr	a
      00138C 08               [12]  776 	inc	r0
      00138D 36               [12]  777 	addc	a,@r0
      00138E FE               [12]  778 	mov	r6,a
      00138F 08               [12]  779 	inc	r0
      001390 86 07            [24]  780 	mov	ar7,@r0
      001392 8D 82            [24]  781 	mov	dpl,r5
      001394 8E 83            [24]  782 	mov	dph,r6
      001396 8F F0            [24]  783 	mov	b,r7
      001398 12 15 ED         [24]  784 	lcall	__gptrget
      00139B FA               [12]  785 	mov	r2,a
      00139C EB               [12]  786 	mov	a,r3
      00139D B5 02 1D         [24]  787 	cjne	a,ar2,00104$
                                    788 ;	uart-buffer.c:86: buffer->first = UART_BUFFER_SIZE;
      0013A0 E5 19            [12]  789 	mov	a,_bp
      0013A2 24 04            [12]  790 	add	a,#0x04
      0013A4 F8               [12]  791 	mov	r0,a
      0013A5 86 82            [24]  792 	mov	dpl,@r0
      0013A7 08               [12]  793 	inc	r0
      0013A8 86 83            [24]  794 	mov	dph,@r0
      0013AA 08               [12]  795 	inc	r0
      0013AB 86 F0            [24]  796 	mov	b,@r0
      0013AD 74 10            [12]  797 	mov	a,#0x10
      0013AF 12 15 D2         [24]  798 	lcall	__gptrput
                                    799 ;	uart-buffer.c:87: buffer->last = UART_BUFFER_SIZE;
      0013B2 8D 82            [24]  800 	mov	dpl,r5
      0013B4 8E 83            [24]  801 	mov	dph,r6
      0013B6 8F F0            [24]  802 	mov	b,r7
      0013B8 12 15 D2         [24]  803 	lcall	__gptrput
      0013BB 80 26            [24]  804 	sjmp	00107$
      0013BD                        805 00104$:
                                    806 ;	uart-buffer.c:89: buffer->first++;
      0013BD 0B               [12]  807 	inc	r3
      0013BE E5 19            [12]  808 	mov	a,_bp
      0013C0 24 04            [12]  809 	add	a,#0x04
      0013C2 F8               [12]  810 	mov	r0,a
      0013C3 86 82            [24]  811 	mov	dpl,@r0
      0013C5 08               [12]  812 	inc	r0
      0013C6 86 83            [24]  813 	mov	dph,@r0
      0013C8 08               [12]  814 	inc	r0
      0013C9 86 F0            [24]  815 	mov	b,@r0
      0013CB EB               [12]  816 	mov	a,r3
      0013CC 12 15 D2         [24]  817 	lcall	__gptrput
                                    818 ;	uart-buffer.c:91: if (buffer->first == UART_BUFFER_SIZE) {
      0013CF BB 10 11         [24]  819 	cjne	r3,#0x10,00107$
                                    820 ;	uart-buffer.c:92: buffer->first = 0;
      0013D2 E5 19            [12]  821 	mov	a,_bp
      0013D4 24 04            [12]  822 	add	a,#0x04
      0013D6 F8               [12]  823 	mov	r0,a
      0013D7 86 82            [24]  824 	mov	dpl,@r0
      0013D9 08               [12]  825 	inc	r0
      0013DA 86 83            [24]  826 	mov	dph,@r0
      0013DC 08               [12]  827 	inc	r0
      0013DD 86 F0            [24]  828 	mov	b,@r0
      0013DF E4               [12]  829 	clr	a
      0013E0 12 15 D2         [24]  830 	lcall	__gptrput
      0013E3                        831 00107$:
                                    832 ;	uart-buffer.c:97: return result;
      0013E3 8C 82            [24]  833 	mov	dpl,r4
                                    834 ;	uart-buffer.c:98: }
      0013E5 85 19 81         [24]  835 	mov	sp,_bp
      0013E8 D0 19            [24]  836 	pop	_bp
      0013EA 22               [24]  837 	ret
                                    838 	.area CSEG    (CODE)
                                    839 	.area CONST   (CODE)
                                    840 	.area XINIT   (CODE)
                                    841 	.area CABS    (ABS,CODE)
