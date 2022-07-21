                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module uart_hal
                                      6 	.optsdcc -mmcs51 --model-medium
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _uartBufferRead
                                     12 	.globl _uartBufferWrite
                                     13 	.globl _uartBufferLength
                                     14 	.globl _uartBufferInitialise
                                     15 	.globl _startTimer
                                     16 	.globl _baudRateToSysclkDivisor
                                     17 	.globl _S1SM0_FE
                                     18 	.globl _T1IF
                                     19 	.globl _T1R
                                     20 	.globl _T0IF
                                     21 	.globl _T0R
                                     22 	.globl _CF
                                     23 	.globl _CR
                                     24 	.globl _CCF1
                                     25 	.globl _CCF0
                                     26 	.globl _CY
                                     27 	.globl _AC
                                     28 	.globl _F0
                                     29 	.globl _RS1
                                     30 	.globl _RS0
                                     31 	.globl _OV
                                     32 	.globl _F1
                                     33 	.globl _P
                                     34 	.globl _EA
                                     35 	.globl _INT1IF
                                     36 	.globl _IT1
                                     37 	.globl _INT0IF
                                     38 	.globl _IT0
                                     39 	.globl _P5_5
                                     40 	.globl _P5_4
                                     41 	.globl _P5_3
                                     42 	.globl _P5_2
                                     43 	.globl _P5_1
                                     44 	.globl _P5_0
                                     45 	.globl _P4_7
                                     46 	.globl _P4_6
                                     47 	.globl _P4_5
                                     48 	.globl _P4_4
                                     49 	.globl _P4_3
                                     50 	.globl _P4_2
                                     51 	.globl _P4_1
                                     52 	.globl _P4_0
                                     53 	.globl _P3_7
                                     54 	.globl _P3_6
                                     55 	.globl _P3_5
                                     56 	.globl _P3_4
                                     57 	.globl _P3_3
                                     58 	.globl _P3_2
                                     59 	.globl _P3_1
                                     60 	.globl _P3_0
                                     61 	.globl _P2_7
                                     62 	.globl _P2_6
                                     63 	.globl _P2_5
                                     64 	.globl _P2_4
                                     65 	.globl _P2_3
                                     66 	.globl _P2_2
                                     67 	.globl _P2_1
                                     68 	.globl _P2_0
                                     69 	.globl _P1_7
                                     70 	.globl _P1_6
                                     71 	.globl _P1_5
                                     72 	.globl _P1_4
                                     73 	.globl _P1_3
                                     74 	.globl _P1_2
                                     75 	.globl _P1_1
                                     76 	.globl _P1_0
                                     77 	.globl _P0_7
                                     78 	.globl _P0_6
                                     79 	.globl _P0_5
                                     80 	.globl _P0_4
                                     81 	.globl _P0_3
                                     82 	.globl _P0_2
                                     83 	.globl _P0_1
                                     84 	.globl _P0_0
                                     85 	.globl _S2BUF
                                     86 	.globl _S2CON
                                     87 	.globl _S1BUF
                                     88 	.globl _S1CON
                                     89 	.globl _SADEN
                                     90 	.globl _SADDR
                                     91 	.globl _WDT_CONTR
                                     92 	.globl _AUXR
                                     93 	.globl _BRT
                                     94 	.globl _T1
                                     95 	.globl _T1H
                                     96 	.globl _T1L
                                     97 	.globl _T0
                                     98 	.globl _T0H
                                     99 	.globl _T0L
                                    100 	.globl _TMOD
                                    101 	.globl _TCON
                                    102 	.globl _CLKDIV
                                    103 	.globl _SPDAT
                                    104 	.globl _SPCTL
                                    105 	.globl _SPSTAT
                                    106 	.globl _PCA_PWM1
                                    107 	.globl _PCA_PWM0
                                    108 	.globl _CCAP1
                                    109 	.globl _CCAP0
                                    110 	.globl _CCAP1H
                                    111 	.globl _CCAP0H
                                    112 	.globl _CCAP1L
                                    113 	.globl _CCAP0L
                                    114 	.globl _PCA_CTR
                                    115 	.globl _CH
                                    116 	.globl _CL
                                    117 	.globl _CCAPM1
                                    118 	.globl _CCAPM0
                                    119 	.globl _CMOD
                                    120 	.globl _CCON
                                    121 	.globl _BUS_SPEED
                                    122 	.globl _P4SW
                                    123 	.globl _P1ASF
                                    124 	.globl _P_SW1
                                    125 	.globl _WAKE_CLKO
                                    126 	.globl _PCON
                                    127 	.globl _B
                                    128 	.globl _ACC
                                    129 	.globl _PSW
                                    130 	.globl _SP
                                    131 	.globl _IP2H
                                    132 	.globl _IP2L
                                    133 	.globl _IP1H
                                    134 	.globl _IP1L
                                    135 	.globl _IE2
                                    136 	.globl _IE1
                                    137 	.globl _IAP_CONTR
                                    138 	.globl _IAP_TRIG
                                    139 	.globl _IAP_CMD
                                    140 	.globl _IAP_ADDR
                                    141 	.globl _IAP_ADDRL
                                    142 	.globl _IAP_ADDRH
                                    143 	.globl _IAP_DATA
                                    144 	.globl _P5M0
                                    145 	.globl _P5M1
                                    146 	.globl _P5
                                    147 	.globl _P4M0
                                    148 	.globl _P4M1
                                    149 	.globl _P4
                                    150 	.globl _P3M0
                                    151 	.globl _P3M1
                                    152 	.globl _P3
                                    153 	.globl _P2M0
                                    154 	.globl _P2M1
                                    155 	.globl _P2
                                    156 	.globl _P1M0
                                    157 	.globl _P1M1
                                    158 	.globl _P1
                                    159 	.globl _P0M0
                                    160 	.globl _P0M1
                                    161 	.globl _P0
                                    162 	.globl _DPS
                                    163 	.globl _DP
                                    164 	.globl _DPH
                                    165 	.globl _DPL
                                    166 	.globl _ADC_RESL
                                    167 	.globl _ADC_RESH
                                    168 	.globl _ADC_CONTR
                                    169 	.globl _uartSendCharacter_PARM_2
                                    170 	.globl _uartInitialise_PARM_5
                                    171 	.globl _uartInitialise_PARM_4
                                    172 	.globl _uartInitialise_PARM_3
                                    173 	.globl _uartInitialise_PARM_2
                                    174 	.globl _UART2_mode
                                    175 	.globl _UART2_outputBuffer
                                    176 	.globl _UART2_inputBuffer
                                    177 	.globl _UART1_mode
                                    178 	.globl _UART1_outputBuffer
                                    179 	.globl _UART1_inputBuffer
                                    180 	.globl _uartReceiveBufferEmpty
                                    181 	.globl _uartReceiveBufferFull
                                    182 	.globl _uartTransmitBufferEmpty
                                    183 	.globl _uartTransmitBufferFull
                                    184 	.globl _uartInitialise
                                    185 	.globl ___uart1_isr
                                    186 	.globl ___uart2_isr
                                    187 	.globl _uartGetCharacter
                                    188 	.globl _uartSendCharacter
                                    189 ;--------------------------------------------------------
                                    190 ; special function registers
                                    191 ;--------------------------------------------------------
                                    192 	.area RSEG    (ABS,DATA)
      000000                        193 	.org 0x0000
                           0000BC   194 _ADC_CONTR	=	0x00bc
                           0000BD   195 _ADC_RESH	=	0x00bd
                           0000BE   196 _ADC_RESL	=	0x00be
                           000082   197 _DPL	=	0x0082
                           000083   198 _DPH	=	0x0083
                           008382   199 _DP	=	0x8382
                           0000A2   200 _DPS	=	0x00a2
                           000080   201 _P0	=	0x0080
                           000093   202 _P0M1	=	0x0093
                           000094   203 _P0M0	=	0x0094
                           000090   204 _P1	=	0x0090
                           000091   205 _P1M1	=	0x0091
                           000092   206 _P1M0	=	0x0092
                           0000A0   207 _P2	=	0x00a0
                           000095   208 _P2M1	=	0x0095
                           000096   209 _P2M0	=	0x0096
                           0000B0   210 _P3	=	0x00b0
                           0000B1   211 _P3M1	=	0x00b1
                           0000B2   212 _P3M0	=	0x00b2
                           0000C0   213 _P4	=	0x00c0
                           0000B3   214 _P4M1	=	0x00b3
                           0000B4   215 _P4M0	=	0x00b4
                           0000C8   216 _P5	=	0x00c8
                           0000C9   217 _P5M1	=	0x00c9
                           0000CA   218 _P5M0	=	0x00ca
                           0000C2   219 _IAP_DATA	=	0x00c2
                           0000C3   220 _IAP_ADDRH	=	0x00c3
                           0000C4   221 _IAP_ADDRL	=	0x00c4
                           00C3C4   222 _IAP_ADDR	=	0xc3c4
                           0000C5   223 _IAP_CMD	=	0x00c5
                           0000C6   224 _IAP_TRIG	=	0x00c6
                           0000C7   225 _IAP_CONTR	=	0x00c7
                           0000A8   226 _IE1	=	0x00a8
                           0000AF   227 _IE2	=	0x00af
                           0000B8   228 _IP1L	=	0x00b8
                           0000B7   229 _IP1H	=	0x00b7
                           0000B5   230 _IP2L	=	0x00b5
                           0000B6   231 _IP2H	=	0x00b6
                           000081   232 _SP	=	0x0081
                           0000D0   233 _PSW	=	0x00d0
                           0000E0   234 _ACC	=	0x00e0
                           0000F0   235 _B	=	0x00f0
                           000087   236 _PCON	=	0x0087
                           00008F   237 _WAKE_CLKO	=	0x008f
                           0000A2   238 _P_SW1	=	0x00a2
                           00009D   239 _P1ASF	=	0x009d
                           0000BB   240 _P4SW	=	0x00bb
                           0000A1   241 _BUS_SPEED	=	0x00a1
                           0000D8   242 _CCON	=	0x00d8
                           0000D9   243 _CMOD	=	0x00d9
                           0000DA   244 _CCAPM0	=	0x00da
                           0000DB   245 _CCAPM1	=	0x00db
                           0000E9   246 _CL	=	0x00e9
                           0000F9   247 _CH	=	0x00f9
                           00F9E9   248 _PCA_CTR	=	0xf9e9
                           0000EA   249 _CCAP0L	=	0x00ea
                           0000EB   250 _CCAP1L	=	0x00eb
                           0000FA   251 _CCAP0H	=	0x00fa
                           0000FB   252 _CCAP1H	=	0x00fb
                           00FAEA   253 _CCAP0	=	0xfaea
                           00FBEB   254 _CCAP1	=	0xfbeb
                           0000F2   255 _PCA_PWM0	=	0x00f2
                           0000F3   256 _PCA_PWM1	=	0x00f3
                           0000CD   257 _SPSTAT	=	0x00cd
                           0000CE   258 _SPCTL	=	0x00ce
                           0000CF   259 _SPDAT	=	0x00cf
                           000097   260 _CLKDIV	=	0x0097
                           000088   261 _TCON	=	0x0088
                           000089   262 _TMOD	=	0x0089
                           00008A   263 _T0L	=	0x008a
                           00008C   264 _T0H	=	0x008c
                           008C8A   265 _T0	=	0x8c8a
                           00008B   266 _T1L	=	0x008b
                           00008D   267 _T1H	=	0x008d
                           008D8B   268 _T1	=	0x8d8b
                           00009C   269 _BRT	=	0x009c
                           00008E   270 _AUXR	=	0x008e
                           0000C1   271 _WDT_CONTR	=	0x00c1
                           0000A9   272 _SADDR	=	0x00a9
                           0000B9   273 _SADEN	=	0x00b9
                           000098   274 _S1CON	=	0x0098
                           000099   275 _S1BUF	=	0x0099
                           00009A   276 _S2CON	=	0x009a
                           00009B   277 _S2BUF	=	0x009b
                                    278 ;--------------------------------------------------------
                                    279 ; special function bits
                                    280 ;--------------------------------------------------------
                                    281 	.area RSEG    (ABS,DATA)
      000000                        282 	.org 0x0000
                           000080   283 _P0_0	=	0x0080
                           000081   284 _P0_1	=	0x0081
                           000082   285 _P0_2	=	0x0082
                           000083   286 _P0_3	=	0x0083
                           000084   287 _P0_4	=	0x0084
                           000085   288 _P0_5	=	0x0085
                           000086   289 _P0_6	=	0x0086
                           000087   290 _P0_7	=	0x0087
                           000090   291 _P1_0	=	0x0090
                           000091   292 _P1_1	=	0x0091
                           000092   293 _P1_2	=	0x0092
                           000093   294 _P1_3	=	0x0093
                           000094   295 _P1_4	=	0x0094
                           000095   296 _P1_5	=	0x0095
                           000096   297 _P1_6	=	0x0096
                           000097   298 _P1_7	=	0x0097
                           0000A0   299 _P2_0	=	0x00a0
                           0000A1   300 _P2_1	=	0x00a1
                           0000A2   301 _P2_2	=	0x00a2
                           0000A3   302 _P2_3	=	0x00a3
                           0000A4   303 _P2_4	=	0x00a4
                           0000A5   304 _P2_5	=	0x00a5
                           0000A6   305 _P2_6	=	0x00a6
                           0000A7   306 _P2_7	=	0x00a7
                           0000B0   307 _P3_0	=	0x00b0
                           0000B1   308 _P3_1	=	0x00b1
                           0000B2   309 _P3_2	=	0x00b2
                           0000B3   310 _P3_3	=	0x00b3
                           0000B4   311 _P3_4	=	0x00b4
                           0000B5   312 _P3_5	=	0x00b5
                           0000B6   313 _P3_6	=	0x00b6
                           0000B7   314 _P3_7	=	0x00b7
                           0000C0   315 _P4_0	=	0x00c0
                           0000C1   316 _P4_1	=	0x00c1
                           0000C2   317 _P4_2	=	0x00c2
                           0000C3   318 _P4_3	=	0x00c3
                           0000C4   319 _P4_4	=	0x00c4
                           0000C5   320 _P4_5	=	0x00c5
                           0000C6   321 _P4_6	=	0x00c6
                           0000C7   322 _P4_7	=	0x00c7
                           0000C8   323 _P5_0	=	0x00c8
                           0000C9   324 _P5_1	=	0x00c9
                           0000CA   325 _P5_2	=	0x00ca
                           0000CB   326 _P5_3	=	0x00cb
                           0000CC   327 _P5_4	=	0x00cc
                           0000CD   328 _P5_5	=	0x00cd
                           000088   329 _IT0	=	0x0088
                           000089   330 _INT0IF	=	0x0089
                           00008A   331 _IT1	=	0x008a
                           00008B   332 _INT1IF	=	0x008b
                           0000AF   333 _EA	=	0x00af
                           0000D0   334 _P	=	0x00d0
                           0000D1   335 _F1	=	0x00d1
                           0000D2   336 _OV	=	0x00d2
                           0000D3   337 _RS0	=	0x00d3
                           0000D4   338 _RS1	=	0x00d4
                           0000D5   339 _F0	=	0x00d5
                           0000D6   340 _AC	=	0x00d6
                           0000D7   341 _CY	=	0x00d7
                           0000D8   342 _CCF0	=	0x00d8
                           0000D9   343 _CCF1	=	0x00d9
                           0000DE   344 _CR	=	0x00de
                           0000DF   345 _CF	=	0x00df
                           00008C   346 _T0R	=	0x008c
                           00008D   347 _T0IF	=	0x008d
                           00008E   348 _T1R	=	0x008e
                           00008F   349 _T1IF	=	0x008f
                           00009F   350 _S1SM0_FE	=	0x009f
                                    351 ;--------------------------------------------------------
                                    352 ; overlayable register banks
                                    353 ;--------------------------------------------------------
                                    354 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        355 	.ds 8
                                    356 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        357 	.ds 8
                                    358 ;--------------------------------------------------------
                                    359 ; overlayable bit register bank
                                    360 ;--------------------------------------------------------
                                    361 	.area BIT_BANK	(REL,OVR,DATA)
      000021                        362 bits:
      000021                        363 	.ds 1
                           008000   364 	b0 = bits[0]
                           008100   365 	b1 = bits[1]
                           008200   366 	b2 = bits[2]
                           008300   367 	b3 = bits[3]
                           008400   368 	b4 = bits[4]
                           008500   369 	b5 = bits[5]
                           008600   370 	b6 = bits[6]
                           008700   371 	b7 = bits[7]
                                    372 ;--------------------------------------------------------
                                    373 ; internal ram data
                                    374 ;--------------------------------------------------------
                                    375 	.area DSEG    (DATA)
      000017                        376 _uartInitialise_sloc0_1_0:
      000017                        377 	.ds 2
                                    378 ;--------------------------------------------------------
                                    379 ; overlayable items in internal ram
                                    380 ;--------------------------------------------------------
                                    381 ;--------------------------------------------------------
                                    382 ; indirectly addressable internal ram data
                                    383 ;--------------------------------------------------------
                                    384 	.area ISEG    (DATA)
                                    385 ;--------------------------------------------------------
                                    386 ; absolute internal ram data
                                    387 ;--------------------------------------------------------
                                    388 	.area IABS    (ABS,DATA)
                                    389 	.area IABS    (ABS,DATA)
                                    390 ;--------------------------------------------------------
                                    391 ; bit data
                                    392 ;--------------------------------------------------------
                                    393 	.area BSEG    (BIT)
                                    394 ;--------------------------------------------------------
                                    395 ; paged external ram data
                                    396 ;--------------------------------------------------------
                                    397 	.area PSEG    (PAG,XDATA)
      000066                        398 _UART1_inputBuffer::
      000066                        399 	.ds 19
      000079                        400 _UART1_outputBuffer::
      000079                        401 	.ds 19
      00008C                        402 _UART1_mode::
      00008C                        403 	.ds 1
      00008D                        404 _UART2_inputBuffer::
      00008D                        405 	.ds 19
      0000A0                        406 _UART2_outputBuffer::
      0000A0                        407 	.ds 19
      0000B3                        408 _UART2_mode::
      0000B3                        409 	.ds 1
      0000B4                        410 _uartInitialise_PARM_2:
      0000B4                        411 	.ds 4
      0000B8                        412 _uartInitialise_PARM_3:
      0000B8                        413 	.ds 1
      0000B9                        414 _uartInitialise_PARM_4:
      0000B9                        415 	.ds 1
      0000BA                        416 _uartInitialise_PARM_5:
      0000BA                        417 	.ds 1
      0000BB                        418 _uartSendCharacter_PARM_2:
      0000BB                        419 	.ds 1
      0000BC                        420 _uartSendCharacter_uart_65536_97:
      0000BC                        421 	.ds 1
      0000BD                        422 _uartSendCharacter_result_65536_98:
      0000BD                        423 	.ds 1
                                    424 ;--------------------------------------------------------
                                    425 ; external ram data
                                    426 ;--------------------------------------------------------
                                    427 	.area XSEG    (XDATA)
                                    428 ;--------------------------------------------------------
                                    429 ; absolute external ram data
                                    430 ;--------------------------------------------------------
                                    431 	.area XABS    (ABS,XDATA)
                                    432 ;--------------------------------------------------------
                                    433 ; external initialized ram data
                                    434 ;--------------------------------------------------------
                                    435 	.area XISEG   (XDATA)
                                    436 	.area HOME    (CODE)
                                    437 	.area GSINIT0 (CODE)
                                    438 	.area GSINIT1 (CODE)
                                    439 	.area GSINIT2 (CODE)
                                    440 	.area GSINIT3 (CODE)
                                    441 	.area GSINIT4 (CODE)
                                    442 	.area GSINIT5 (CODE)
                                    443 	.area GSINIT  (CODE)
                                    444 	.area GSFINAL (CODE)
                                    445 	.area CSEG    (CODE)
                                    446 ;--------------------------------------------------------
                                    447 ; global & static initialisations
                                    448 ;--------------------------------------------------------
                                    449 	.area HOME    (CODE)
                                    450 	.area GSINIT  (CODE)
                                    451 	.area GSFINAL (CODE)
                                    452 	.area GSINIT  (CODE)
                                    453 ;--------------------------------------------------------
                                    454 ; Home
                                    455 ;--------------------------------------------------------
                                    456 	.area HOME    (CODE)
                                    457 	.area HOME    (CODE)
                                    458 ;--------------------------------------------------------
                                    459 ; code
                                    460 ;--------------------------------------------------------
                                    461 	.area CSEG    (CODE)
                                    462 ;------------------------------------------------------------
                                    463 ;Allocation info for local variables in function 'inputBuffer'
                                    464 ;------------------------------------------------------------
                                    465 ;	uart-hal.c:63: static UartBuffer *inputBuffer(Uart uart) {
                                    466 ;	-----------------------------------------
                                    467 ;	 function inputBuffer
                                    468 ;	-----------------------------------------
      000D9A                        469 _inputBuffer:
                           000007   470 	ar7 = 0x07
                           000006   471 	ar6 = 0x06
                           000005   472 	ar5 = 0x05
                           000004   473 	ar4 = 0x04
                           000003   474 	ar3 = 0x03
                           000002   475 	ar2 = 0x02
                           000001   476 	ar1 = 0x01
                           000000   477 	ar0 = 0x00
      000D9A AF 82            [24]  478 	mov	r7,dpl
                                    479 ;	uart-hal.c:64: UartBuffer *result = NULL;
      000D9C 7C 00            [12]  480 	mov	r4,#0x00
      000D9E 7D 00            [12]  481 	mov	r5,#0x00
      000DA0 7E 00            [12]  482 	mov	r6,#0x00
                                    483 ;	uart-hal.c:66: switch (uart) {
      000DA2 BF 01 02         [24]  484 	cjne	r7,#0x01,00114$
      000DA5 80 05            [24]  485 	sjmp	00101$
      000DA7                        486 00114$:
                                    487 ;	uart-hal.c:67: case UART1:
      000DA7 BF 02 10         [24]  488 	cjne	r7,#0x02,00103$
      000DAA 80 08            [24]  489 	sjmp	00102$
      000DAC                        490 00101$:
                                    491 ;	uart-hal.c:68: result = &UART1_inputBuffer;
      000DAC 7C 66            [12]  492 	mov	r4,#_UART1_inputBuffer
      000DAE 7D 00            [12]  493 	mov	r5,#0x00
      000DB0 7E 60            [12]  494 	mov	r6,#0x60
                                    495 ;	uart-hal.c:69: break;
                                    496 ;	uart-hal.c:72: case UART2:
      000DB2 80 06            [24]  497 	sjmp	00103$
      000DB4                        498 00102$:
                                    499 ;	uart-hal.c:73: result = &UART2_inputBuffer;
      000DB4 7C 8D            [12]  500 	mov	r4,#_UART2_inputBuffer
      000DB6 7D 00            [12]  501 	mov	r5,#0x00
      000DB8 7E 60            [12]  502 	mov	r6,#0x60
                                    503 ;	uart-hal.c:86: }
      000DBA                        504 00103$:
                                    505 ;	uart-hal.c:88: return result;
      000DBA 8C 82            [24]  506 	mov	dpl,r4
      000DBC 8D 83            [24]  507 	mov	dph,r5
      000DBE 8E F0            [24]  508 	mov	b,r6
                                    509 ;	uart-hal.c:89: }
      000DC0 22               [24]  510 	ret
                                    511 ;------------------------------------------------------------
                                    512 ;Allocation info for local variables in function 'outputBuffer'
                                    513 ;------------------------------------------------------------
                                    514 ;	uart-hal.c:91: static UartBuffer *outputBuffer(Uart uart) {
                                    515 ;	-----------------------------------------
                                    516 ;	 function outputBuffer
                                    517 ;	-----------------------------------------
      000DC1                        518 _outputBuffer:
      000DC1 AF 82            [24]  519 	mov	r7,dpl
                                    520 ;	uart-hal.c:92: UartBuffer *result = NULL;
      000DC3 7C 00            [12]  521 	mov	r4,#0x00
      000DC5 7D 00            [12]  522 	mov	r5,#0x00
      000DC7 7E 00            [12]  523 	mov	r6,#0x00
                                    524 ;	uart-hal.c:94: switch (uart) {
      000DC9 BF 01 02         [24]  525 	cjne	r7,#0x01,00114$
      000DCC 80 05            [24]  526 	sjmp	00101$
      000DCE                        527 00114$:
                                    528 ;	uart-hal.c:95: case UART1:
      000DCE BF 02 10         [24]  529 	cjne	r7,#0x02,00103$
      000DD1 80 08            [24]  530 	sjmp	00102$
      000DD3                        531 00101$:
                                    532 ;	uart-hal.c:96: result = &UART1_outputBuffer;
      000DD3 7C 79            [12]  533 	mov	r4,#_UART1_outputBuffer
      000DD5 7D 00            [12]  534 	mov	r5,#0x00
      000DD7 7E 60            [12]  535 	mov	r6,#0x60
                                    536 ;	uart-hal.c:97: break;
                                    537 ;	uart-hal.c:100: case UART2:
      000DD9 80 06            [24]  538 	sjmp	00103$
      000DDB                        539 00102$:
                                    540 ;	uart-hal.c:101: result = &UART2_outputBuffer;
      000DDB 7C A0            [12]  541 	mov	r4,#_UART2_outputBuffer
      000DDD 7D 00            [12]  542 	mov	r5,#0x00
      000DDF 7E 60            [12]  543 	mov	r6,#0x60
                                    544 ;	uart-hal.c:114: }
      000DE1                        545 00103$:
                                    546 ;	uart-hal.c:116: return result;
      000DE1 8C 82            [24]  547 	mov	dpl,r4
      000DE3 8D 83            [24]  548 	mov	dph,r5
      000DE5 8E F0            [24]  549 	mov	b,r6
                                    550 ;	uart-hal.c:117: }
      000DE7 22               [24]  551 	ret
                                    552 ;------------------------------------------------------------
                                    553 ;Allocation info for local variables in function 'uartMode'
                                    554 ;------------------------------------------------------------
                                    555 ;	uart-hal.c:119: static UartMode uartMode(Uart uart) {
                                    556 ;	-----------------------------------------
                                    557 ;	 function uartMode
                                    558 ;	-----------------------------------------
      000DE8                        559 _uartMode:
      000DE8 AF 82            [24]  560 	mov	r7,dpl
                                    561 ;	uart-hal.c:120: UartMode result = UART_8N1;
      000DEA 7E 00            [12]  562 	mov	r6,#0x00
                                    563 ;	uart-hal.c:122: switch (uart) {
      000DEC BF 01 02         [24]  564 	cjne	r7,#0x01,00114$
      000DEF 80 05            [24]  565 	sjmp	00101$
      000DF1                        566 00114$:
                                    567 ;	uart-hal.c:123: case UART1:
      000DF1 BF 02 0C         [24]  568 	cjne	r7,#0x02,00103$
      000DF4 80 06            [24]  569 	sjmp	00102$
      000DF6                        570 00101$:
                                    571 ;	uart-hal.c:124: result = UART1_mode;
      000DF6 78 8C            [12]  572 	mov	r0,#_UART1_mode
      000DF8 E2               [24]  573 	movx	a,@r0
      000DF9 FE               [12]  574 	mov	r6,a
                                    575 ;	uart-hal.c:125: break;
                                    576 ;	uart-hal.c:128: case UART2:
      000DFA 80 04            [24]  577 	sjmp	00103$
      000DFC                        578 00102$:
                                    579 ;	uart-hal.c:129: result = UART2_mode;
      000DFC 78 B3            [12]  580 	mov	r0,#_UART2_mode
      000DFE E2               [24]  581 	movx	a,@r0
      000DFF FE               [12]  582 	mov	r6,a
                                    583 ;	uart-hal.c:142: }
      000E00                        584 00103$:
                                    585 ;	uart-hal.c:144: return result;
      000E00 8E 82            [24]  586 	mov	dpl,r6
                                    587 ;	uart-hal.c:145: }
      000E02 22               [24]  588 	ret
                                    589 ;------------------------------------------------------------
                                    590 ;Allocation info for local variables in function 'uartReceiveBufferEmpty'
                                    591 ;------------------------------------------------------------
                                    592 ;	uart-hal.c:147: uint8_t uartReceiveBufferEmpty(Uart uart) {
                                    593 ;	-----------------------------------------
                                    594 ;	 function uartReceiveBufferEmpty
                                    595 ;	-----------------------------------------
      000E03                        596 _uartReceiveBufferEmpty:
                                    597 ;	uart-hal.c:148: return uartBufferLength(inputBuffer(uart)) == 0;
      000E03 12 0D 9A         [24]  598 	lcall	_inputBuffer
      000E06 12 12 0A         [24]  599 	lcall	_uartBufferLength
      000E09 AF 82            [24]  600 	mov	r7,dpl
      000E0B E4               [12]  601 	clr	a
      000E0C BF 00 01         [24]  602 	cjne	r7,#0x00,00103$
      000E0F 04               [12]  603 	inc	a
      000E10                        604 00103$:
      000E10 F5 82            [12]  605 	mov	dpl,a
                                    606 ;	uart-hal.c:149: }
      000E12 22               [24]  607 	ret
                                    608 ;------------------------------------------------------------
                                    609 ;Allocation info for local variables in function 'uartReceiveBufferFull'
                                    610 ;------------------------------------------------------------
                                    611 ;	uart-hal.c:151: uint8_t uartReceiveBufferFull(Uart uart) {
                                    612 ;	-----------------------------------------
                                    613 ;	 function uartReceiveBufferFull
                                    614 ;	-----------------------------------------
      000E13                        615 _uartReceiveBufferFull:
                                    616 ;	uart-hal.c:152: return uartBufferLength(inputBuffer(uart)) == UART_BUFFER_SIZE;
      000E13 12 0D 9A         [24]  617 	lcall	_inputBuffer
      000E16 12 12 0A         [24]  618 	lcall	_uartBufferLength
      000E19 AF 82            [24]  619 	mov	r7,dpl
      000E1B E4               [12]  620 	clr	a
      000E1C BF 10 01         [24]  621 	cjne	r7,#0x10,00103$
      000E1F 04               [12]  622 	inc	a
      000E20                        623 00103$:
      000E20 F5 82            [12]  624 	mov	dpl,a
                                    625 ;	uart-hal.c:153: }
      000E22 22               [24]  626 	ret
                                    627 ;------------------------------------------------------------
                                    628 ;Allocation info for local variables in function 'uartTransmitBufferEmpty'
                                    629 ;------------------------------------------------------------
                                    630 ;	uart-hal.c:155: uint8_t uartTransmitBufferEmpty(Uart uart) {
                                    631 ;	-----------------------------------------
                                    632 ;	 function uartTransmitBufferEmpty
                                    633 ;	-----------------------------------------
      000E23                        634 _uartTransmitBufferEmpty:
                                    635 ;	uart-hal.c:156: return uartBufferLength(outputBuffer(uart)) == 0;
      000E23 12 0D C1         [24]  636 	lcall	_outputBuffer
      000E26 12 12 0A         [24]  637 	lcall	_uartBufferLength
      000E29 AF 82            [24]  638 	mov	r7,dpl
      000E2B E4               [12]  639 	clr	a
      000E2C BF 00 01         [24]  640 	cjne	r7,#0x00,00103$
      000E2F 04               [12]  641 	inc	a
      000E30                        642 00103$:
      000E30 F5 82            [12]  643 	mov	dpl,a
                                    644 ;	uart-hal.c:157: }
      000E32 22               [24]  645 	ret
                                    646 ;------------------------------------------------------------
                                    647 ;Allocation info for local variables in function 'uartTransmitBufferFull'
                                    648 ;------------------------------------------------------------
                                    649 ;	uart-hal.c:159: uint8_t uartTransmitBufferFull(Uart uart) {
                                    650 ;	-----------------------------------------
                                    651 ;	 function uartTransmitBufferFull
                                    652 ;	-----------------------------------------
      000E33                        653 _uartTransmitBufferFull:
                                    654 ;	uart-hal.c:160: return uartBufferLength(outputBuffer(uart)) == UART_BUFFER_SIZE;
      000E33 12 0D C1         [24]  655 	lcall	_outputBuffer
      000E36 12 12 0A         [24]  656 	lcall	_uartBufferLength
      000E39 AF 82            [24]  657 	mov	r7,dpl
      000E3B E4               [12]  658 	clr	a
      000E3C BF 10 01         [24]  659 	cjne	r7,#0x10,00103$
      000E3F 04               [12]  660 	inc	a
      000E40                        661 00103$:
      000E40 F5 82            [12]  662 	mov	dpl,a
                                    663 ;	uart-hal.c:161: }
      000E42 22               [24]  664 	ret
                                    665 ;------------------------------------------------------------
                                    666 ;Allocation info for local variables in function 'uartInitialise'
                                    667 ;------------------------------------------------------------
                                    668 ;sloc0                     Allocated with name '_uartInitialise_sloc0_1_0'
                                    669 ;------------------------------------------------------------
                                    670 ;	uart-hal.c:168: Timer_Status uartInitialise(Uart uart, uint32_t baudRate, UartBaudRateTimer baudRateTimer, UartMode mode, uint8_t pinSwitch) {
                                    671 ;	-----------------------------------------
                                    672 ;	 function uartInitialise
                                    673 ;	-----------------------------------------
      000E43                        674 _uartInitialise:
      000E43 AF 82            [24]  675 	mov	r7,dpl
                                    676 ;	uart-hal.c:169: Timer_Status rc = TIMER_FREQUENCY_OK;
      000E45 7E 00            [12]  677 	mov	r6,#0x00
                                    678 ;	uart-hal.c:174: if (uart != UART1 || mode == UART_8N1) {
      000E47 BF 01 05         [24]  679 	cjne	r7,#0x01,00101$
      000E4A 78 B9            [12]  680 	mov	r0,#_uartInitialise_PARM_4
      000E4C E2               [24]  681 	movx	a,@r0
      000E4D 70 51            [24]  682 	jnz	00102$
      000E4F                        683 00101$:
                                    684 ;	uart-hal.c:175: Timer timer = (baudRateTimer == UART_USE_TIMER2)
      000E4F 78 B8            [12]  685 	mov	r0,#_uartInitialise_PARM_3
      000E51 E2               [24]  686 	movx	a,@r0
      000E52 70 05            [24]  687 	jnz	00134$
      000E54 7C 02            [12]  688 	mov	r4,#0x02
      000E56 FD               [12]  689 	mov	r5,a
      000E57 80 04            [24]  690 	sjmp	00135$
      000E59                        691 00134$:
      000E59 8F 04            [24]  692 	mov	ar4,r7
      000E5B 7D 00            [12]  693 	mov	r5,#0x00
      000E5D                        694 00135$:
      000E5D C0 07            [24]  695 	push	ar7
                                    696 ;	uart-hal.c:182: baudRateToSysclkDivisor(baudRate), 
      000E5F 78 B4            [12]  697 	mov	r0,#_uartInitialise_PARM_2
      000E61 E2               [24]  698 	movx	a,@r0
      000E62 F5 82            [12]  699 	mov	dpl,a
      000E64 08               [12]  700 	inc	r0
      000E65 E2               [24]  701 	movx	a,@r0
      000E66 F5 83            [12]  702 	mov	dph,a
      000E68 08               [12]  703 	inc	r0
      000E69 E2               [24]  704 	movx	a,@r0
      000E6A F5 F0            [12]  705 	mov	b,a
      000E6C 08               [12]  706 	inc	r0
      000E6D E2               [24]  707 	movx	a,@r0
      000E6E C0 04            [24]  708 	push	ar4
      000E70 12 00 DB         [24]  709 	lcall	_baudRateToSysclkDivisor
      000E73 AA 82            [24]  710 	mov	r2,dpl
      000E75 AB 83            [24]  711 	mov	r3,dph
      000E77 AD F0            [24]  712 	mov	r5,b
      000E79 FF               [12]  713 	mov	r7,a
      000E7A D0 04            [24]  714 	pop	ar4
                                    715 ;	uart-hal.c:185: TIMER_FREE_RUNNING
      000E7C 78 00            [12]  716 	mov	r0,#_startTimer_PARM_2
      000E7E EA               [12]  717 	mov	a,r2
      000E7F F2               [24]  718 	movx	@r0,a
      000E80 EB               [12]  719 	mov	a,r3
      000E81 08               [12]  720 	inc	r0
      000E82 F2               [24]  721 	movx	@r0,a
      000E83 ED               [12]  722 	mov	a,r5
      000E84 08               [12]  723 	inc	r0
      000E85 F2               [24]  724 	movx	@r0,a
      000E86 EF               [12]  725 	mov	a,r7
      000E87 08               [12]  726 	inc	r0
      000E88 F2               [24]  727 	movx	@r0,a
      000E89 78 04            [12]  728 	mov	r0,#_startTimer_PARM_3
      000E8B E4               [12]  729 	clr	a
      000E8C F2               [24]  730 	movx	@r0,a
      000E8D 78 05            [12]  731 	mov	r0,#_startTimer_PARM_4
      000E8F F2               [24]  732 	movx	@r0,a
      000E90 78 06            [12]  733 	mov	r0,#_startTimer_PARM_5
      000E92 F2               [24]  734 	movx	@r0,a
      000E93 8C 82            [24]  735 	mov	dpl,r4
      000E95 C0 07            [24]  736 	push	ar7
      000E97 12 01 4B         [24]  737 	lcall	_startTimer
      000E9A AE 82            [24]  738 	mov	r6,dpl
      000E9C D0 07            [24]  739 	pop	ar7
                                    740 ;	uart-hal.c:336: return rc;
      000E9E D0 07            [24]  741 	pop	ar7
                                    742 ;	uart-hal.c:185: TIMER_FREE_RUNNING
      000EA0                        743 00102$:
                                    744 ;	uart-hal.c:189: if (rc == TIMER_FREQUENCY_OK) {
      000EA0 EE               [12]  745 	mov	a,r6
      000EA1 60 03            [24]  746 	jz	00214$
      000EA3 02 0F E1         [24]  747 	ljmp	00131$
      000EA6                        748 00214$:
                                    749 ;	uart-hal.c:190: uartBufferInitialise(inputBuffer(uart));
      000EA6 8F 82            [24]  750 	mov	dpl,r7
      000EA8 C0 07            [24]  751 	push	ar7
      000EAA C0 06            [24]  752 	push	ar6
      000EAC 12 0D 9A         [24]  753 	lcall	_inputBuffer
      000EAF 12 11 CC         [24]  754 	lcall	_uartBufferInitialise
      000EB2 D0 06            [24]  755 	pop	ar6
      000EB4 D0 07            [24]  756 	pop	ar7
                                    757 ;	uart-hal.c:191: uartBufferInitialise(outputBuffer(uart));
      000EB6 8F 82            [24]  758 	mov	dpl,r7
      000EB8 C0 07            [24]  759 	push	ar7
      000EBA C0 06            [24]  760 	push	ar6
      000EBC 12 0D C1         [24]  761 	lcall	_outputBuffer
      000EBF 12 11 CC         [24]  762 	lcall	_uartBufferInitialise
      000EC2 D0 06            [24]  763 	pop	ar6
      000EC4 D0 07            [24]  764 	pop	ar7
                                    765 ;	uart-hal.c:193: uint8_t operationMode = 0;
      000EC6 7D 00            [12]  766 	mov	r5,#0x00
                                    767 ;	uart-hal.c:195: switch (mode) {
      000EC8 78 B9            [12]  768 	mov	r0,#_uartInitialise_PARM_4
      000ECA C3               [12]  769 	clr	c
      000ECB E2               [24]  770 	movx	a,@r0
      000ECC F5 F0            [12]  771 	mov	b,a
      000ECE 74 03            [12]  772 	mov	a,#0x03
      000ED0 95 F0            [12]  773 	subb	a,b
      000ED2 40 39            [24]  774 	jc	00113$
      000ED4 78 B9            [12]  775 	mov	r0,#_uartInitialise_PARM_4
      000ED6 E2               [24]  776 	movx	a,@r0
      000ED7 75 F0 03         [24]  777 	mov	b,#0x03
      000EDA A4               [48]  778 	mul	ab
      000EDB 90 0E DF         [24]  779 	mov	dptr,#00216$
      000EDE 73               [24]  780 	jmp	@a+dptr
      000EDF                        781 00216$:
      000EDF 02 0E EB         [24]  782 	ljmp	00104$
      000EE2 02 0E F2         [24]  783 	ljmp	00109$
      000EE5 02 0E F2         [24]  784 	ljmp	00109$
      000EE8 02 0E F2         [24]  785 	ljmp	00109$
                                    786 ;	uart-hal.c:196: case UART_8N1:
      000EEB                        787 00104$:
                                    788 ;	uart-hal.c:197: if (uart == UART1) {
      000EEB BF 01 1F         [24]  789 	cjne	r7,#0x01,00113$
                                    790 ;	uart-hal.c:198: operationMode = 1;
      000EEE 7D 01            [12]  791 	mov	r5,#0x01
                                    792 ;	uart-hal.c:200: break;
                                    793 ;	uart-hal.c:204: case UART_MULTI_MACHINE:
      000EF0 80 1B            [24]  794 	sjmp	00113$
      000EF2                        795 00109$:
                                    796 ;	uart-hal.c:205: if (uart == UART1) {
      000EF2 BF 01 16         [24]  797 	cjne	r7,#0x01,00111$
                                    798 ;	uart-hal.c:206: operationMode = 2 | ((baudRate & 2) >> 1);
      000EF5 78 B4            [12]  799 	mov	r0,#_uartInitialise_PARM_2
      000EF7 E2               [24]  800 	movx	a,@r0
      000EF8 FB               [12]  801 	mov	r3,a
      000EF9 08               [12]  802 	inc	r0
      000EFA E2               [24]  803 	movx	a,@r0
      000EFB 53 03 02         [24]  804 	anl	ar3,#0x02
      000EFE E4               [12]  805 	clr	a
      000EFF C3               [12]  806 	clr	c
      000F00 13               [12]  807 	rrc	a
      000F01 CB               [12]  808 	xch	a,r3
      000F02 13               [12]  809 	rrc	a
      000F03 CB               [12]  810 	xch	a,r3
      000F04 FC               [12]  811 	mov	r4,a
      000F05 74 02            [12]  812 	mov	a,#0x02
      000F07 4B               [12]  813 	orl	a,r3
      000F08 FD               [12]  814 	mov	r5,a
      000F09 80 02            [24]  815 	sjmp	00113$
      000F0B                        816 00111$:
                                    817 ;	uart-hal.c:208: operationMode = 1;
      000F0B 7D 01            [12]  818 	mov	r5,#0x01
                                    819 ;	uart-hal.c:211: }
      000F0D                        820 00113$:
                                    821 ;	uart-hal.c:213: uint8_t scon = ((mode == UART_MULTI_MACHINE) ? M_SM2 : 0)
      000F0D 78 B9            [12]  822 	mov	r0,#_uartInitialise_PARM_4
      000F0F E2               [24]  823 	movx	a,@r0
      000F10 B4 03 06         [24]  824 	cjne	a,#0x03,00136$
      000F13 7B 20            [12]  825 	mov	r3,#0x20
      000F15 7C 00            [12]  826 	mov	r4,#0x00
      000F17 80 04            [24]  827 	sjmp	00137$
      000F19                        828 00136$:
      000F19 7B 00            [12]  829 	mov	r3,#0x00
      000F1B 7C 00            [12]  830 	mov	r4,#0x00
      000F1D                        831 00137$:
      000F1D ED               [12]  832 	mov	a,r5
      000F1E 30 E1 08         [24]  833 	jnb	acc.1,00138$
      000F21 75 17 80         [24]  834 	mov	_uartInitialise_sloc0_1_0,#0x80
      000F24 75 18 00         [24]  835 	mov	(_uartInitialise_sloc0_1_0 + 1),#0x00
      000F27 80 05            [24]  836 	sjmp	00139$
      000F29                        837 00138$:
      000F29 E4               [12]  838 	clr	a
      000F2A F5 17            [12]  839 	mov	_uartInitialise_sloc0_1_0,a
      000F2C F5 18            [12]  840 	mov	(_uartInitialise_sloc0_1_0 + 1),a
      000F2E                        841 00139$:
      000F2E E5 17            [12]  842 	mov	a,_uartInitialise_sloc0_1_0
      000F30 4B               [12]  843 	orl	a,r3
      000F31 44 10            [12]  844 	orl	a,#0x10
      000F33 FC               [12]  845 	mov	r4,a
                                    846 ;	uart-hal.c:216: switch (uart) {
      000F34 BF 01 02         [24]  847 	cjne	r7,#0x01,00224$
      000F37 80 09            [24]  848 	sjmp	00114$
      000F39                        849 00224$:
      000F39 BF 02 03         [24]  850 	cjne	r7,#0x02,00225$
      000F3C 02 0F C1         [24]  851 	ljmp	00128$
      000F3F                        852 00225$:
      000F3F 02 0F E1         [24]  853 	ljmp	00131$
                                    854 ;	uart-hal.c:217: case UART1:
      000F42                        855 00114$:
                                    856 ;	uart-hal.c:219: switch (operationMode) {
      000F42 BD 01 02         [24]  857 	cjne	r5,#0x01,00226$
      000F45 80 0A            [24]  858 	sjmp	00115$
      000F47                        859 00226$:
      000F47 BD 02 02         [24]  860 	cjne	r5,#0x02,00227$
      000F4A 80 14            [24]  861 	sjmp	00119$
      000F4C                        862 00227$:
                                    863 ;	uart-hal.c:220: case 1:
      000F4C BD 03 55         [24]  864 	cjne	r5,#0x03,00127$
      000F4F 80 32            [24]  865 	sjmp	00123$
      000F51                        866 00115$:
                                    867 ;	uart-hal.c:221: if (baudRateTimer == UART_USE_TIMER2) {
      000F51 78 B8            [12]  868 	mov	r0,#_uartInitialise_PARM_3
      000F53 E2               [24]  869 	movx	a,@r0
      000F54 70 05            [24]  870 	jnz	00117$
                                    871 ;	uart-hal.c:222: AUXR |= M_S1ST2;
      000F56 43 8E 01         [24]  872 	orl	_AUXR,#0x01
      000F59 80 49            [24]  873 	sjmp	00127$
      000F5B                        874 00117$:
                                    875 ;	uart-hal.c:224: AUXR &= ~M_S1ST2;
      000F5B 53 8E FE         [24]  876 	anl	_AUXR,#0xfe
                                    877 ;	uart-hal.c:226: break;
                                    878 ;	uart-hal.c:228: case 2:
      000F5E 80 44            [24]  879 	sjmp	00127$
      000F60                        880 00119$:
                                    881 ;	uart-hal.c:230: if (baudRate & 1) {
      000F60 78 B4            [12]  882 	mov	r0,#_uartInitialise_PARM_2
      000F62 E2               [24]  883 	movx	a,@r0
      000F63 54 01            [12]  884 	anl	a,#0x01
      000F65 70 12            [24]  885 	jnz	00230$
      000F67 08               [12]  886 	inc	r0
      000F68 E2               [24]  887 	movx	a,@r0
      000F69 54 00            [12]  888 	anl	a,#0x00
      000F6B 70 0C            [24]  889 	jnz	00230$
      000F6D 08               [12]  890 	inc	r0
      000F6E E2               [24]  891 	movx	a,@r0
      000F6F 54 00            [12]  892 	anl	a,#0x00
      000F71 70 06            [24]  893 	jnz	00230$
      000F73 08               [12]  894 	inc	r0
      000F74 E2               [24]  895 	movx	a,@r0
      000F75 54 00            [12]  896 	anl	a,#0x00
      000F77 60 05            [24]  897 	jz	00121$
      000F79                        898 00230$:
                                    899 ;	uart-hal.c:231: PCON |= M_SMOD;
      000F79 43 87 80         [24]  900 	orl	_PCON,#0x80
      000F7C 80 26            [24]  901 	sjmp	00127$
      000F7E                        902 00121$:
                                    903 ;	uart-hal.c:233: PCON &= ~M_SMOD;
      000F7E 53 87 7F         [24]  904 	anl	_PCON,#0x7f
                                    905 ;	uart-hal.c:235: break;
                                    906 ;	uart-hal.c:237: case 3:
      000F81 80 21            [24]  907 	sjmp	00127$
      000F83                        908 00123$:
                                    909 ;	uart-hal.c:239: if (baudRate & 1) {
      000F83 78 B4            [12]  910 	mov	r0,#_uartInitialise_PARM_2
      000F85 E2               [24]  911 	movx	a,@r0
      000F86 54 01            [12]  912 	anl	a,#0x01
      000F88 70 12            [24]  913 	jnz	00231$
      000F8A 08               [12]  914 	inc	r0
      000F8B E2               [24]  915 	movx	a,@r0
      000F8C 54 00            [12]  916 	anl	a,#0x00
      000F8E 70 0C            [24]  917 	jnz	00231$
      000F90 08               [12]  918 	inc	r0
      000F91 E2               [24]  919 	movx	a,@r0
      000F92 54 00            [12]  920 	anl	a,#0x00
      000F94 70 06            [24]  921 	jnz	00231$
      000F96 08               [12]  922 	inc	r0
      000F97 E2               [24]  923 	movx	a,@r0
      000F98 54 00            [12]  924 	anl	a,#0x00
      000F9A 60 05            [24]  925 	jz	00125$
      000F9C                        926 00231$:
                                    927 ;	uart-hal.c:240: AUXR |= M_UART_M0x6;
      000F9C 43 8E 20         [24]  928 	orl	_AUXR,#0x20
      000F9F 80 03            [24]  929 	sjmp	00127$
      000FA1                        930 00125$:
                                    931 ;	uart-hal.c:242: AUXR &= ~M_UART_M0x6;
      000FA1 53 8E DF         [24]  932 	anl	_AUXR,#0xdf
                                    933 ;	uart-hal.c:245: }
      000FA4                        934 00127$:
                                    935 ;	uart-hal.c:253: UART1_mode = mode;
      000FA4 78 B9            [12]  936 	mov	r0,#_uartInitialise_PARM_4
      000FA6 E2               [24]  937 	movx	a,@r0
      000FA7 78 8C            [12]  938 	mov	r0,#_UART1_mode
      000FA9 F2               [24]  939 	movx	@r0,a
                                    940 ;	uart-hal.c:256: S1CON = scon | ((operationMode & 1) ? M_SM1 : 0);
      000FAA ED               [12]  941 	mov	a,r5
      000FAB 30 E0 06         [24]  942 	jnb	acc.0,00140$
      000FAE 7D 40            [12]  943 	mov	r5,#0x40
      000FB0 7F 00            [12]  944 	mov	r7,#0x00
      000FB2 80 04            [24]  945 	sjmp	00141$
      000FB4                        946 00140$:
      000FB4 7D 00            [12]  947 	mov	r5,#0x00
      000FB6 7F 00            [12]  948 	mov	r7,#0x00
      000FB8                        949 00141$:
      000FB8 ED               [12]  950 	mov	a,r5
      000FB9 4C               [12]  951 	orl	a,r4
      000FBA F5 98            [12]  952 	mov	_S1CON,a
                                    953 ;	uart-hal.c:259: IE1 |= M_ES1;
      000FBC 43 A8 10         [24]  954 	orl	_IE1,#0x10
                                    955 ;	uart-hal.c:260: break;
                                    956 ;	uart-hal.c:263: case UART2:
      000FBF 80 20            [24]  957 	sjmp	00131$
      000FC1                        958 00128$:
                                    959 ;	uart-hal.c:268: UART2_mode = mode;
      000FC1 78 B9            [12]  960 	mov	r0,#_uartInitialise_PARM_4
      000FC3 E2               [24]  961 	movx	a,@r0
      000FC4 78 B3            [12]  962 	mov	r0,#_UART2_mode
      000FC6 F2               [24]  963 	movx	@r0,a
                                    964 ;	uart-hal.c:280: P_SW1 = (P_SW1 & ~M_S2_S) | ((pinSwitch << P_S2_S) & M_S2_S);
      000FC7 74 EF            [12]  965 	mov	a,#0xef
      000FC9 55 A2            [12]  966 	anl	a,_P_SW1
      000FCB FF               [12]  967 	mov	r7,a
      000FCC 78 BA            [12]  968 	mov	r0,#_uartInitialise_PARM_5
      000FCE E2               [24]  969 	movx	a,@r0
      000FCF C4               [12]  970 	swap	a
      000FD0 54 F0            [12]  971 	anl	a,#0xf0
      000FD2 FD               [12]  972 	mov	r5,a
      000FD3 74 10            [12]  973 	mov	a,#0x10
      000FD5 5D               [12]  974 	anl	a,r5
      000FD6 4F               [12]  975 	orl	a,r7
      000FD7 F5 A2            [12]  976 	mov	_P_SW1,a
                                    977 ;	uart-hal.c:282: S2CON = scon | M_SM1; // Yes, that's not a mistake, see TRM.
      000FD9 74 40            [12]  978 	mov	a,#0x40
      000FDB 4C               [12]  979 	orl	a,r4
      000FDC F5 9A            [12]  980 	mov	_S2CON,a
                                    981 ;	uart-hal.c:286: IE2 |= M_ES2;
      000FDE 43 AF 01         [24]  982 	orl	_IE2,#0x01
                                    983 ;	uart-hal.c:333: }
      000FE1                        984 00131$:
                                    985 ;	uart-hal.c:336: return rc;
      000FE1 8E 82            [24]  986 	mov	dpl,r6
                                    987 ;	uart-hal.c:337: }
      000FE3 22               [24]  988 	ret
                                    989 ;------------------------------------------------------------
                                    990 ;Allocation info for local variables in function '__uart1_isr'
                                    991 ;------------------------------------------------------------
                                    992 ;	uart-hal.c:339: INTERRUPT_USING(__uart1_isr, UART1_INTERRUPT, 1) CRITICAL {
                                    993 ;	-----------------------------------------
                                    994 ;	 function __uart1_isr
                                    995 ;	-----------------------------------------
      000FE4                        996 ___uart1_isr:
                           00000F   997 	ar7 = 0x0f
                           00000E   998 	ar6 = 0x0e
                           00000D   999 	ar5 = 0x0d
                           00000C  1000 	ar4 = 0x0c
                           00000B  1001 	ar3 = 0x0b
                           00000A  1002 	ar2 = 0x0a
                           000009  1003 	ar1 = 0x09
                           000008  1004 	ar0 = 0x08
      000FE4 C2 AF            [12] 1005 	clr	ea
      000FE6 C0 21            [24] 1006 	push	bits
      000FE8 C0 E0            [24] 1007 	push	acc
      000FEA C0 F0            [24] 1008 	push	b
      000FEC C0 82            [24] 1009 	push	dpl
      000FEE C0 83            [24] 1010 	push	dph
      000FF0 C0 07            [24] 1011 	push	(0+7)
      000FF2 C0 06            [24] 1012 	push	(0+6)
      000FF4 C0 05            [24] 1013 	push	(0+5)
      000FF6 C0 04            [24] 1014 	push	(0+4)
      000FF8 C0 03            [24] 1015 	push	(0+3)
      000FFA C0 02            [24] 1016 	push	(0+2)
      000FFC C0 01            [24] 1017 	push	(0+1)
      000FFE C0 00            [24] 1018 	push	(0+0)
      001000 C0 D0            [24] 1019 	push	psw
      001002 75 D0 08         [24] 1020 	mov	psw,#0x08
                                   1021 ;	uart-hal.c:340: if (S1CON & M_TI) {
      001005 E5 98            [12] 1022 	mov	a,_S1CON
      001007 30 E1 2E         [24] 1023 	jnb	acc.1,00105$
                                   1024 ;	uart-hal.c:341: S1CON &= ~M_TI;
      00100A 53 98 FD         [24] 1025 	anl	_S1CON,#0xfd
                                   1026 ;	uart-hal.c:343: if (uartBufferLength(&UART1_outputBuffer) > 0) {
      00100D 90 00 79         [24] 1027 	mov	dptr,#_UART1_outputBuffer
      001010 75 F0 60         [24] 1028 	mov	b,#0x60
      001013 75 D0 00         [24] 1029 	mov	psw,#0x00
      001016 12 12 0A         [24] 1030 	lcall	_uartBufferLength
      001019 75 D0 08         [24] 1031 	mov	psw,#0x08
      00101C E5 82            [12] 1032 	mov	a,dpl
      00101E 60 14            [24] 1033 	jz	00102$
                                   1034 ;	uart-hal.c:344: S1BUF = uartBufferRead(&UART1_outputBuffer);
      001020 90 00 79         [24] 1035 	mov	dptr,#_UART1_outputBuffer
      001023 75 F0 60         [24] 1036 	mov	b,#0x60
      001026 75 D0 00         [24] 1037 	mov	psw,#0x00
      001029 12 13 2E         [24] 1038 	lcall	_uartBufferRead
      00102C 75 D0 08         [24] 1039 	mov	psw,#0x08
      00102F 85 82 99         [24] 1040 	mov	_S1BUF,dpl
      001032 80 04            [24] 1041 	sjmp	00105$
      001034                       1042 00102$:
                                   1043 ;	uart-hal.c:346: UART1_outputBuffer.busy = 0;
      001034 78 8B            [12] 1044 	mov	r0,#(_UART1_outputBuffer + 0x0012)
      001036 E4               [12] 1045 	clr	a
      001037 F2               [24] 1046 	movx	@r0,a
      001038                       1047 00105$:
                                   1048 ;	uart-hal.c:350: if (S1CON & M_RI) {
      001038 E5 98            [12] 1049 	mov	a,_S1CON
      00103A 30 E0 16         [24] 1050 	jnb	acc.0,00108$
                                   1051 ;	uart-hal.c:351: S1CON &= ~M_RI;
      00103D 53 98 FE         [24] 1052 	anl	_S1CON,#0xfe
                                   1053 ;	uart-hal.c:352: uartBufferWrite(&UART1_inputBuffer, S1BUF);
      001040 C0 99            [24] 1054 	push	_S1BUF
      001042 90 00 66         [24] 1055 	mov	dptr,#_UART1_inputBuffer
      001045 75 F0 60         [24] 1056 	mov	b,#0x60
      001048 75 D0 00         [24] 1057 	mov	psw,#0x00
      00104B 12 12 63         [24] 1058 	lcall	_uartBufferWrite
      00104E 75 D0 08         [24] 1059 	mov	psw,#0x08
      001051 15 81            [12] 1060 	dec	sp
      001053                       1061 00108$:
                                   1062 ;	uart-hal.c:354: }
      001053 D0 D0            [24] 1063 	pop	psw
      001055 D0 00            [24] 1064 	pop	(0+0)
      001057 D0 01            [24] 1065 	pop	(0+1)
      001059 D0 02            [24] 1066 	pop	(0+2)
      00105B D0 03            [24] 1067 	pop	(0+3)
      00105D D0 04            [24] 1068 	pop	(0+4)
      00105F D0 05            [24] 1069 	pop	(0+5)
      001061 D0 06            [24] 1070 	pop	(0+6)
      001063 D0 07            [24] 1071 	pop	(0+7)
      001065 D0 83            [24] 1072 	pop	dph
      001067 D0 82            [24] 1073 	pop	dpl
      001069 D0 F0            [24] 1074 	pop	b
      00106B D0 E0            [24] 1075 	pop	acc
      00106D D0 21            [24] 1076 	pop	bits
      00106F D2 AF            [12] 1077 	setb	ea
      001071 32               [24] 1078 	reti
                                   1079 ;------------------------------------------------------------
                                   1080 ;Allocation info for local variables in function '__uart2_isr'
                                   1081 ;------------------------------------------------------------
                                   1082 ;	uart-hal.c:357: INTERRUPT_USING(__uart2_isr, UART2_INTERRUPT, 1) CRITICAL {
                                   1083 ;	-----------------------------------------
                                   1084 ;	 function __uart2_isr
                                   1085 ;	-----------------------------------------
      001072                       1086 ___uart2_isr:
      001072 C2 AF            [12] 1087 	clr	ea
      001074 C0 21            [24] 1088 	push	bits
      001076 C0 E0            [24] 1089 	push	acc
      001078 C0 F0            [24] 1090 	push	b
      00107A C0 82            [24] 1091 	push	dpl
      00107C C0 83            [24] 1092 	push	dph
      00107E C0 07            [24] 1093 	push	(0+7)
      001080 C0 06            [24] 1094 	push	(0+6)
      001082 C0 05            [24] 1095 	push	(0+5)
      001084 C0 04            [24] 1096 	push	(0+4)
      001086 C0 03            [24] 1097 	push	(0+3)
      001088 C0 02            [24] 1098 	push	(0+2)
      00108A C0 01            [24] 1099 	push	(0+1)
      00108C C0 00            [24] 1100 	push	(0+0)
      00108E C0 D0            [24] 1101 	push	psw
      001090 75 D0 08         [24] 1102 	mov	psw,#0x08
                                   1103 ;	uart-hal.c:358: if (S2CON & M_TI) {
      001093 E5 9A            [12] 1104 	mov	a,_S2CON
      001095 30 E1 2E         [24] 1105 	jnb	acc.1,00105$
                                   1106 ;	uart-hal.c:359: S2CON &= ~M_TI;
      001098 53 9A FD         [24] 1107 	anl	_S2CON,#0xfd
                                   1108 ;	uart-hal.c:361: if (uartBufferLength(&UART2_outputBuffer) > 0) {
      00109B 90 00 A0         [24] 1109 	mov	dptr,#_UART2_outputBuffer
      00109E 75 F0 60         [24] 1110 	mov	b,#0x60
      0010A1 75 D0 00         [24] 1111 	mov	psw,#0x00
      0010A4 12 12 0A         [24] 1112 	lcall	_uartBufferLength
      0010A7 75 D0 08         [24] 1113 	mov	psw,#0x08
      0010AA E5 82            [12] 1114 	mov	a,dpl
      0010AC 60 14            [24] 1115 	jz	00102$
                                   1116 ;	uart-hal.c:362: S2BUF = uartBufferRead(&UART2_outputBuffer);
      0010AE 90 00 A0         [24] 1117 	mov	dptr,#_UART2_outputBuffer
      0010B1 75 F0 60         [24] 1118 	mov	b,#0x60
      0010B4 75 D0 00         [24] 1119 	mov	psw,#0x00
      0010B7 12 13 2E         [24] 1120 	lcall	_uartBufferRead
      0010BA 75 D0 08         [24] 1121 	mov	psw,#0x08
      0010BD 85 82 9B         [24] 1122 	mov	_S2BUF,dpl
      0010C0 80 04            [24] 1123 	sjmp	00105$
      0010C2                       1124 00102$:
                                   1125 ;	uart-hal.c:364: UART2_outputBuffer.busy = 0;
      0010C2 78 B2            [12] 1126 	mov	r0,#(_UART2_outputBuffer + 0x0012)
      0010C4 E4               [12] 1127 	clr	a
      0010C5 F2               [24] 1128 	movx	@r0,a
      0010C6                       1129 00105$:
                                   1130 ;	uart-hal.c:368: if (S2CON & M_RI) {
      0010C6 E5 9A            [12] 1131 	mov	a,_S2CON
      0010C8 30 E0 16         [24] 1132 	jnb	acc.0,00108$
                                   1133 ;	uart-hal.c:369: S2CON &= ~M_RI;
      0010CB 53 9A FE         [24] 1134 	anl	_S2CON,#0xfe
                                   1135 ;	uart-hal.c:370: uartBufferWrite(&UART2_inputBuffer, S2BUF);
      0010CE C0 9B            [24] 1136 	push	_S2BUF
      0010D0 90 00 8D         [24] 1137 	mov	dptr,#_UART2_inputBuffer
      0010D3 75 F0 60         [24] 1138 	mov	b,#0x60
      0010D6 75 D0 00         [24] 1139 	mov	psw,#0x00
      0010D9 12 12 63         [24] 1140 	lcall	_uartBufferWrite
      0010DC 75 D0 08         [24] 1141 	mov	psw,#0x08
      0010DF 15 81            [12] 1142 	dec	sp
      0010E1                       1143 00108$:
                                   1144 ;	uart-hal.c:372: }
      0010E1 D0 D0            [24] 1145 	pop	psw
      0010E3 D0 00            [24] 1146 	pop	(0+0)
      0010E5 D0 01            [24] 1147 	pop	(0+1)
      0010E7 D0 02            [24] 1148 	pop	(0+2)
      0010E9 D0 03            [24] 1149 	pop	(0+3)
      0010EB D0 04            [24] 1150 	pop	(0+4)
      0010ED D0 05            [24] 1151 	pop	(0+5)
      0010EF D0 06            [24] 1152 	pop	(0+6)
      0010F1 D0 07            [24] 1153 	pop	(0+7)
      0010F3 D0 83            [24] 1154 	pop	dph
      0010F5 D0 82            [24] 1155 	pop	dpl
      0010F7 D0 F0            [24] 1156 	pop	b
      0010F9 D0 E0            [24] 1157 	pop	acc
      0010FB D0 21            [24] 1158 	pop	bits
      0010FD D2 AF            [12] 1159 	setb	ea
      0010FF 32               [24] 1160 	reti
                                   1161 ;------------------------------------------------------------
                                   1162 ;Allocation info for local variables in function 'uartGetCharacter'
                                   1163 ;------------------------------------------------------------
                                   1164 ;	uart-hal.c:412: uint8_t uartGetCharacter(Uart uart) {
                                   1165 ;	-----------------------------------------
                                   1166 ;	 function uartGetCharacter
                                   1167 ;	-----------------------------------------
      001100                       1168 _uartGetCharacter:
                           000007  1169 	ar7 = 0x07
                           000006  1170 	ar6 = 0x06
                           000005  1171 	ar5 = 0x05
                           000004  1172 	ar4 = 0x04
                           000003  1173 	ar3 = 0x03
                           000002  1174 	ar2 = 0x02
                           000001  1175 	ar1 = 0x01
                           000000  1176 	ar0 = 0x00
                                   1177 ;	uart-hal.c:413: uint8_t result = 0;
      001100 7F 00            [12] 1178 	mov	r7,#0x00
                                   1179 ;	uart-hal.c:414: UartBuffer *buffer = inputBuffer(uart);
      001102 C0 07            [24] 1180 	push	ar7
      001104 12 0D 9A         [24] 1181 	lcall	_inputBuffer
                                   1182 ;	uart-hal.c:416: if (uartBufferLength(buffer) > 0) {
      001107 AC 82            [24] 1183 	mov	r4,dpl
      001109 AD 83            [24] 1184 	mov	r5,dph
      00110B AE F0            [24] 1185 	mov	r6,b
      00110D C0 06            [24] 1186 	push	ar6
      00110F C0 05            [24] 1187 	push	ar5
      001111 C0 04            [24] 1188 	push	ar4
      001113 12 12 0A         [24] 1189 	lcall	_uartBufferLength
      001116 E5 82            [12] 1190 	mov	a,dpl
      001118 D0 04            [24] 1191 	pop	ar4
      00111A D0 05            [24] 1192 	pop	ar5
      00111C D0 06            [24] 1193 	pop	ar6
      00111E D0 07            [24] 1194 	pop	ar7
      001120 60 0B            [24] 1195 	jz	00102$
                                   1196 ;	uart-hal.c:417: result = uartBufferRead(buffer);
      001122 8C 82            [24] 1197 	mov	dpl,r4
      001124 8D 83            [24] 1198 	mov	dph,r5
      001126 8E F0            [24] 1199 	mov	b,r6
      001128 12 13 2E         [24] 1200 	lcall	_uartBufferRead
      00112B AF 82            [24] 1201 	mov	r7,dpl
      00112D                       1202 00102$:
                                   1203 ;	uart-hal.c:420: return result;
      00112D 8F 82            [24] 1204 	mov	dpl,r7
                                   1205 ;	uart-hal.c:421: }
      00112F 22               [24] 1206 	ret
                                   1207 ;------------------------------------------------------------
                                   1208 ;Allocation info for local variables in function 'uartSendCharacter'
                                   1209 ;------------------------------------------------------------
                                   1210 ;	uart-hal.c:423: uint8_t uartSendCharacter(Uart uart, uint8_t c) {
                                   1211 ;	-----------------------------------------
                                   1212 ;	 function uartSendCharacter
                                   1213 ;	-----------------------------------------
      001130                       1214 _uartSendCharacter:
      001130 E5 82            [12] 1215 	mov	a,dpl
      001132 78 BC            [12] 1216 	mov	r0,#_uartSendCharacter_uart_65536_97
      001134 F2               [24] 1217 	movx	@r0,a
                                   1218 ;	uart-hal.c:424: UartBuffer *buffer = outputBuffer(uart);
      001135 78 BC            [12] 1219 	mov	r0,#_uartSendCharacter_uart_65536_97
      001137 E2               [24] 1220 	movx	a,@r0
      001138 F5 82            [12] 1221 	mov	dpl,a
      00113A 12 0D C1         [24] 1222 	lcall	_outputBuffer
      00113D AC 82            [24] 1223 	mov	r4,dpl
      00113F AD 83            [24] 1224 	mov	r5,dph
      001141 AE F0            [24] 1225 	mov	r6,b
                                   1226 ;	uart-hal.c:425: uint8_t result = uartBufferWrite(buffer, c);
      001143 C0 06            [24] 1227 	push	ar6
      001145 C0 05            [24] 1228 	push	ar5
      001147 C0 04            [24] 1229 	push	ar4
      001149 78 BB            [12] 1230 	mov	r0,#_uartSendCharacter_PARM_2
      00114B E2               [24] 1231 	movx	a,@r0
      00114C C0 E0            [24] 1232 	push	acc
      00114E 8C 82            [24] 1233 	mov	dpl,r4
      001150 8D 83            [24] 1234 	mov	dph,r5
      001152 8E F0            [24] 1235 	mov	b,r6
      001154 12 12 63         [24] 1236 	lcall	_uartBufferWrite
      001157 78 BD            [12] 1237 	mov	r0,#_uartSendCharacter_result_65536_98
      001159 E5 82            [12] 1238 	mov	a,dpl
      00115B F2               [24] 1239 	movx	@r0,a
      00115C 15 81            [12] 1240 	dec	sp
      00115E D0 04            [24] 1241 	pop	ar4
      001160 D0 05            [24] 1242 	pop	ar5
      001162 D0 06            [24] 1243 	pop	ar6
                                   1244 ;	uart-hal.c:427: if (uartBufferLength(buffer) > 0 && !buffer->busy) {
      001164 8C 82            [24] 1245 	mov	dpl,r4
      001166 8D 83            [24] 1246 	mov	dph,r5
      001168 8E F0            [24] 1247 	mov	b,r6
      00116A C0 06            [24] 1248 	push	ar6
      00116C C0 05            [24] 1249 	push	ar5
      00116E C0 04            [24] 1250 	push	ar4
      001170 12 12 0A         [24] 1251 	lcall	_uartBufferLength
      001173 E5 82            [12] 1252 	mov	a,dpl
      001175 D0 04            [24] 1253 	pop	ar4
      001177 D0 05            [24] 1254 	pop	ar5
      001179 D0 06            [24] 1255 	pop	ar6
      00117B 60 49            [24] 1256 	jz	00105$
      00117D 74 12            [12] 1257 	mov	a,#0x12
      00117F 2C               [12] 1258 	add	a,r4
      001180 FA               [12] 1259 	mov	r2,a
      001181 E4               [12] 1260 	clr	a
      001182 3D               [12] 1261 	addc	a,r5
      001183 FB               [12] 1262 	mov	r3,a
      001184 8E 07            [24] 1263 	mov	ar7,r6
      001186 8A 82            [24] 1264 	mov	dpl,r2
      001188 8B 83            [24] 1265 	mov	dph,r3
      00118A 8F F0            [24] 1266 	mov	b,r7
      00118C 12 15 ED         [24] 1267 	lcall	__gptrget
      00118F 70 35            [24] 1268 	jnz	00105$
                                   1269 ;	uart-hal.c:428: buffer->busy = 1;
      001191 8A 82            [24] 1270 	mov	dpl,r2
      001193 8B 83            [24] 1271 	mov	dph,r3
      001195 8F F0            [24] 1272 	mov	b,r7
      001197 74 01            [12] 1273 	mov	a,#0x01
      001199 12 15 D2         [24] 1274 	lcall	__gptrput
                                   1275 ;	uart-hal.c:430: switch (uart) {
      00119C 78 BC            [12] 1276 	mov	r0,#_uartSendCharacter_uart_65536_97
      00119E E2               [24] 1277 	movx	a,@r0
      00119F B4 01 02         [24] 1278 	cjne	a,#0x01,00127$
      0011A2 80 08            [24] 1279 	sjmp	00101$
      0011A4                       1280 00127$:
      0011A4 78 BC            [12] 1281 	mov	r0,#_uartSendCharacter_uart_65536_97
      0011A6 E2               [24] 1282 	movx	a,@r0
                                   1283 ;	uart-hal.c:431: case UART1:
      0011A7 B4 02 1C         [24] 1284 	cjne	a,#0x02,00105$
      0011AA 80 0E            [24] 1285 	sjmp	00102$
      0011AC                       1286 00101$:
                                   1287 ;	uart-hal.c:432: S1BUF = uartBufferRead(buffer);
      0011AC 8C 82            [24] 1288 	mov	dpl,r4
      0011AE 8D 83            [24] 1289 	mov	dph,r5
      0011B0 8E F0            [24] 1290 	mov	b,r6
      0011B2 12 13 2E         [24] 1291 	lcall	_uartBufferRead
      0011B5 85 82 99         [24] 1292 	mov	_S1BUF,dpl
                                   1293 ;	uart-hal.c:433: break;
                                   1294 ;	uart-hal.c:436: case UART2:
      0011B8 80 0C            [24] 1295 	sjmp	00105$
      0011BA                       1296 00102$:
                                   1297 ;	uart-hal.c:437: S2BUF = uartBufferRead(buffer);
      0011BA 8C 82            [24] 1298 	mov	dpl,r4
      0011BC 8D 83            [24] 1299 	mov	dph,r5
      0011BE 8E F0            [24] 1300 	mov	b,r6
      0011C0 12 13 2E         [24] 1301 	lcall	_uartBufferRead
      0011C3 85 82 9B         [24] 1302 	mov	_S2BUF,dpl
                                   1303 ;	uart-hal.c:450: }
      0011C6                       1304 00105$:
                                   1305 ;	uart-hal.c:453: return result;
      0011C6 78 BD            [12] 1306 	mov	r0,#_uartSendCharacter_result_65536_98
      0011C8 E2               [24] 1307 	movx	a,@r0
      0011C9 F5 82            [12] 1308 	mov	dpl,a
                                   1309 ;	uart-hal.c:454: }
      0011CB 22               [24] 1310 	ret
                                   1311 	.area CSEG    (CODE)
                                   1312 	.area CONST   (CODE)
                                   1313 	.area XINIT   (CODE)
                                   1314 	.area CABS    (ABS,CODE)
