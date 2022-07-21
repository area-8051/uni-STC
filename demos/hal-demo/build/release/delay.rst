                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module delay
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
                                    163 	.globl _delay1ms
                                    164 	.globl _delay10us
                                    165 ;--------------------------------------------------------
                                    166 ; special function registers
                                    167 ;--------------------------------------------------------
                                    168 	.area RSEG    (ABS,DATA)
      000000                        169 	.org 0x0000
                           0000BC   170 _ADC_CONTR	=	0x00bc
                           0000BD   171 _ADC_RESH	=	0x00bd
                           0000BE   172 _ADC_RESL	=	0x00be
                           000082   173 _DPL	=	0x0082
                           000083   174 _DPH	=	0x0083
                           008382   175 _DP	=	0x8382
                           0000A2   176 _DPS	=	0x00a2
                           000080   177 _P0	=	0x0080
                           000093   178 _P0M1	=	0x0093
                           000094   179 _P0M0	=	0x0094
                           000090   180 _P1	=	0x0090
                           000091   181 _P1M1	=	0x0091
                           000092   182 _P1M0	=	0x0092
                           0000A0   183 _P2	=	0x00a0
                           000095   184 _P2M1	=	0x0095
                           000096   185 _P2M0	=	0x0096
                           0000B0   186 _P3	=	0x00b0
                           0000B1   187 _P3M1	=	0x00b1
                           0000B2   188 _P3M0	=	0x00b2
                           0000C0   189 _P4	=	0x00c0
                           0000B3   190 _P4M1	=	0x00b3
                           0000B4   191 _P4M0	=	0x00b4
                           0000C8   192 _P5	=	0x00c8
                           0000C9   193 _P5M1	=	0x00c9
                           0000CA   194 _P5M0	=	0x00ca
                           0000C2   195 _IAP_DATA	=	0x00c2
                           0000C3   196 _IAP_ADDRH	=	0x00c3
                           0000C4   197 _IAP_ADDRL	=	0x00c4
                           00C3C4   198 _IAP_ADDR	=	0xc3c4
                           0000C5   199 _IAP_CMD	=	0x00c5
                           0000C6   200 _IAP_TRIG	=	0x00c6
                           0000C7   201 _IAP_CONTR	=	0x00c7
                           0000A8   202 _IE1	=	0x00a8
                           0000AF   203 _IE2	=	0x00af
                           0000B8   204 _IP1L	=	0x00b8
                           0000B7   205 _IP1H	=	0x00b7
                           0000B5   206 _IP2L	=	0x00b5
                           0000B6   207 _IP2H	=	0x00b6
                           000081   208 _SP	=	0x0081
                           0000D0   209 _PSW	=	0x00d0
                           0000E0   210 _ACC	=	0x00e0
                           0000F0   211 _B	=	0x00f0
                           000087   212 _PCON	=	0x0087
                           00008F   213 _WAKE_CLKO	=	0x008f
                           0000A2   214 _P_SW1	=	0x00a2
                           00009D   215 _P1ASF	=	0x009d
                           0000BB   216 _P4SW	=	0x00bb
                           0000A1   217 _BUS_SPEED	=	0x00a1
                           0000D8   218 _CCON	=	0x00d8
                           0000D9   219 _CMOD	=	0x00d9
                           0000DA   220 _CCAPM0	=	0x00da
                           0000DB   221 _CCAPM1	=	0x00db
                           0000E9   222 _CL	=	0x00e9
                           0000F9   223 _CH	=	0x00f9
                           00F9E9   224 _PCA_CTR	=	0xf9e9
                           0000EA   225 _CCAP0L	=	0x00ea
                           0000EB   226 _CCAP1L	=	0x00eb
                           0000FA   227 _CCAP0H	=	0x00fa
                           0000FB   228 _CCAP1H	=	0x00fb
                           00FAEA   229 _CCAP0	=	0xfaea
                           00FBEB   230 _CCAP1	=	0xfbeb
                           0000F2   231 _PCA_PWM0	=	0x00f2
                           0000F3   232 _PCA_PWM1	=	0x00f3
                           0000CD   233 _SPSTAT	=	0x00cd
                           0000CE   234 _SPCTL	=	0x00ce
                           0000CF   235 _SPDAT	=	0x00cf
                           000097   236 _CLKDIV	=	0x0097
                           000088   237 _TCON	=	0x0088
                           000089   238 _TMOD	=	0x0089
                           00008A   239 _T0L	=	0x008a
                           00008C   240 _T0H	=	0x008c
                           008C8A   241 _T0	=	0x8c8a
                           00008B   242 _T1L	=	0x008b
                           00008D   243 _T1H	=	0x008d
                           008D8B   244 _T1	=	0x8d8b
                           00009C   245 _BRT	=	0x009c
                           00008E   246 _AUXR	=	0x008e
                           0000C1   247 _WDT_CONTR	=	0x00c1
                           0000A9   248 _SADDR	=	0x00a9
                           0000B9   249 _SADEN	=	0x00b9
                           000098   250 _S1CON	=	0x0098
                           000099   251 _S1BUF	=	0x0099
                           00009A   252 _S2CON	=	0x009a
                           00009B   253 _S2BUF	=	0x009b
                                    254 ;--------------------------------------------------------
                                    255 ; special function bits
                                    256 ;--------------------------------------------------------
                                    257 	.area RSEG    (ABS,DATA)
      000000                        258 	.org 0x0000
                           000080   259 _P0_0	=	0x0080
                           000081   260 _P0_1	=	0x0081
                           000082   261 _P0_2	=	0x0082
                           000083   262 _P0_3	=	0x0083
                           000084   263 _P0_4	=	0x0084
                           000085   264 _P0_5	=	0x0085
                           000086   265 _P0_6	=	0x0086
                           000087   266 _P0_7	=	0x0087
                           000090   267 _P1_0	=	0x0090
                           000091   268 _P1_1	=	0x0091
                           000092   269 _P1_2	=	0x0092
                           000093   270 _P1_3	=	0x0093
                           000094   271 _P1_4	=	0x0094
                           000095   272 _P1_5	=	0x0095
                           000096   273 _P1_6	=	0x0096
                           000097   274 _P1_7	=	0x0097
                           0000A0   275 _P2_0	=	0x00a0
                           0000A1   276 _P2_1	=	0x00a1
                           0000A2   277 _P2_2	=	0x00a2
                           0000A3   278 _P2_3	=	0x00a3
                           0000A4   279 _P2_4	=	0x00a4
                           0000A5   280 _P2_5	=	0x00a5
                           0000A6   281 _P2_6	=	0x00a6
                           0000A7   282 _P2_7	=	0x00a7
                           0000B0   283 _P3_0	=	0x00b0
                           0000B1   284 _P3_1	=	0x00b1
                           0000B2   285 _P3_2	=	0x00b2
                           0000B3   286 _P3_3	=	0x00b3
                           0000B4   287 _P3_4	=	0x00b4
                           0000B5   288 _P3_5	=	0x00b5
                           0000B6   289 _P3_6	=	0x00b6
                           0000B7   290 _P3_7	=	0x00b7
                           0000C0   291 _P4_0	=	0x00c0
                           0000C1   292 _P4_1	=	0x00c1
                           0000C2   293 _P4_2	=	0x00c2
                           0000C3   294 _P4_3	=	0x00c3
                           0000C4   295 _P4_4	=	0x00c4
                           0000C5   296 _P4_5	=	0x00c5
                           0000C6   297 _P4_6	=	0x00c6
                           0000C7   298 _P4_7	=	0x00c7
                           0000C8   299 _P5_0	=	0x00c8
                           0000C9   300 _P5_1	=	0x00c9
                           0000CA   301 _P5_2	=	0x00ca
                           0000CB   302 _P5_3	=	0x00cb
                           0000CC   303 _P5_4	=	0x00cc
                           0000CD   304 _P5_5	=	0x00cd
                           000088   305 _IT0	=	0x0088
                           000089   306 _INT0IF	=	0x0089
                           00008A   307 _IT1	=	0x008a
                           00008B   308 _INT1IF	=	0x008b
                           0000AF   309 _EA	=	0x00af
                           0000D0   310 _P	=	0x00d0
                           0000D1   311 _F1	=	0x00d1
                           0000D2   312 _OV	=	0x00d2
                           0000D3   313 _RS0	=	0x00d3
                           0000D4   314 _RS1	=	0x00d4
                           0000D5   315 _F0	=	0x00d5
                           0000D6   316 _AC	=	0x00d6
                           0000D7   317 _CY	=	0x00d7
                           0000D8   318 _CCF0	=	0x00d8
                           0000D9   319 _CCF1	=	0x00d9
                           0000DE   320 _CR	=	0x00de
                           0000DF   321 _CF	=	0x00df
                           00008C   322 _T0R	=	0x008c
                           00008D   323 _T0IF	=	0x008d
                           00008E   324 _T1R	=	0x008e
                           00008F   325 _T1IF	=	0x008f
                           00009F   326 _S1SM0_FE	=	0x009f
                                    327 ;--------------------------------------------------------
                                    328 ; overlayable register banks
                                    329 ;--------------------------------------------------------
                                    330 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        331 	.ds 8
                                    332 ;--------------------------------------------------------
                                    333 ; internal ram data
                                    334 ;--------------------------------------------------------
                                    335 	.area DSEG    (DATA)
                                    336 ;--------------------------------------------------------
                                    337 ; overlayable items in internal ram
                                    338 ;--------------------------------------------------------
                                    339 ;--------------------------------------------------------
                                    340 ; indirectly addressable internal ram data
                                    341 ;--------------------------------------------------------
                                    342 	.area ISEG    (DATA)
                                    343 ;--------------------------------------------------------
                                    344 ; absolute internal ram data
                                    345 ;--------------------------------------------------------
                                    346 	.area IABS    (ABS,DATA)
                                    347 	.area IABS    (ABS,DATA)
                                    348 ;--------------------------------------------------------
                                    349 ; bit data
                                    350 ;--------------------------------------------------------
                                    351 	.area BSEG    (BIT)
                                    352 ;--------------------------------------------------------
                                    353 ; paged external ram data
                                    354 ;--------------------------------------------------------
                                    355 	.area PSEG    (PAG,XDATA)
                                    356 ;--------------------------------------------------------
                                    357 ; external ram data
                                    358 ;--------------------------------------------------------
                                    359 	.area XSEG    (XDATA)
                                    360 ;--------------------------------------------------------
                                    361 ; absolute external ram data
                                    362 ;--------------------------------------------------------
                                    363 	.area XABS    (ABS,XDATA)
                                    364 ;--------------------------------------------------------
                                    365 ; external initialized ram data
                                    366 ;--------------------------------------------------------
                                    367 	.area XISEG   (XDATA)
                                    368 	.area HOME    (CODE)
                                    369 	.area GSINIT0 (CODE)
                                    370 	.area GSINIT1 (CODE)
                                    371 	.area GSINIT2 (CODE)
                                    372 	.area GSINIT3 (CODE)
                                    373 	.area GSINIT4 (CODE)
                                    374 	.area GSINIT5 (CODE)
                                    375 	.area GSINIT  (CODE)
                                    376 	.area GSFINAL (CODE)
                                    377 	.area CSEG    (CODE)
                                    378 ;--------------------------------------------------------
                                    379 ; global & static initialisations
                                    380 ;--------------------------------------------------------
                                    381 	.area HOME    (CODE)
                                    382 	.area GSINIT  (CODE)
                                    383 	.area GSFINAL (CODE)
                                    384 	.area GSINIT  (CODE)
                                    385 ;--------------------------------------------------------
                                    386 ; Home
                                    387 ;--------------------------------------------------------
                                    388 	.area HOME    (CODE)
                                    389 	.area HOME    (CODE)
                                    390 ;--------------------------------------------------------
                                    391 ; code
                                    392 ;--------------------------------------------------------
                                    393 	.area CSEG    (CODE)
                                    394 ;------------------------------------------------------------
                                    395 ;Allocation info for local variables in function 'delay1ms'
                                    396 ;------------------------------------------------------------
                                    397 ;	delay.c:158: void delay1ms(uint16_t ms) {
                                    398 ;	-----------------------------------------
                                    399 ;	 function delay1ms
                                    400 ;	-----------------------------------------
      000304                        401 _delay1ms:
                           000007   402 	ar7 = 0x07
                           000006   403 	ar6 = 0x06
                           000005   404 	ar5 = 0x05
                           000004   405 	ar4 = 0x04
                           000003   406 	ar3 = 0x03
                           000002   407 	ar2 = 0x02
                           000001   408 	ar1 = 0x01
                           000000   409 	ar0 = 0x00
      000304 AE 82            [24]  410 	mov	r6,dpl
      000306 AF 83            [24]  411 	mov	r7,dph
                                    412 ;	delay.c:159: for (uint16_t i = ms; i; i--) {
      000308                        413 00107$:
      000308 EE               [12]  414 	mov	a,r6
      000309 4F               [12]  415 	orl	a,r7
      00030A 60 19            [24]  416 	jz	00109$
                                    417 ;	delay.c:160: for (uint16_t n = DELAY_1ms; n; n--) {
      00030C 7C 64            [12]  418 	mov	r4,#0x64
      00030E 7D 02            [12]  419 	mov	r5,#0x02
      000310                        420 00104$:
      000310 EC               [12]  421 	mov	a,r4
      000311 4D               [12]  422 	orl	a,r5
      000312 60 0A            [24]  423 	jz	00108$
                                    424 ;	delay.c:161: NOP();
      000314 00               [12]  425 	NOP	
                                    426 ;	delay.c:162: NOP();
      000315 00               [12]  427 	NOP	
                                    428 ;	delay.c:163: NOP();
      000316 00               [12]  429 	NOP	
                                    430 ;	delay.c:160: for (uint16_t n = DELAY_1ms; n; n--) {
      000317 1C               [12]  431 	dec	r4
      000318 BC FF 01         [24]  432 	cjne	r4,#0xff,00131$
      00031B 1D               [12]  433 	dec	r5
      00031C                        434 00131$:
      00031C 80 F2            [24]  435 	sjmp	00104$
      00031E                        436 00108$:
                                    437 ;	delay.c:159: for (uint16_t i = ms; i; i--) {
      00031E 1E               [12]  438 	dec	r6
      00031F BE FF 01         [24]  439 	cjne	r6,#0xff,00132$
      000322 1F               [12]  440 	dec	r7
      000323                        441 00132$:
      000323 80 E3            [24]  442 	sjmp	00107$
      000325                        443 00109$:
                                    444 ;	delay.c:166: }
      000325 22               [24]  445 	ret
                                    446 ;------------------------------------------------------------
                                    447 ;Allocation info for local variables in function 'delay10us'
                                    448 ;------------------------------------------------------------
                                    449 ;	delay.c:167: void delay10us(uint8_t us) {
                                    450 ;	-----------------------------------------
                                    451 ;	 function delay10us
                                    452 ;	-----------------------------------------
      000326                        453 _delay10us:
      000326 AF 82            [24]  454 	mov	r7,dpl
                                    455 ;	delay.c:168: for (uint8_t i = us; i; i--) {
      000328                        456 00107$:
      000328 EF               [12]  457 	mov	a,r7
      000329 60 0B            [24]  458 	jz	00109$
                                    459 ;	delay.c:169: for (uint8_t n = DELAY_10us; n; n--) {
      00032B 7E 08            [12]  460 	mov	r6,#0x08
      00032D                        461 00104$:
      00032D EE               [12]  462 	mov	a,r6
      00032E 60 03            [24]  463 	jz	00108$
      000330 1E               [12]  464 	dec	r6
      000331 80 FA            [24]  465 	sjmp	00104$
      000333                        466 00108$:
                                    467 ;	delay.c:168: for (uint8_t i = us; i; i--) {
      000333 1F               [12]  468 	dec	r7
      000334 80 F2            [24]  469 	sjmp	00107$
      000336                        470 00109$:
                                    471 ;	delay.c:172: }
      000336 22               [24]  472 	ret
                                    473 	.area CSEG    (CODE)
                                    474 	.area CONST   (CODE)
                                    475 	.area XINIT   (CODE)
                                    476 	.area CABS    (ABS,CODE)
