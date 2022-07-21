                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 4.2.0 #13081 (Linux)
                                      4 ;--------------------------------------------------------
                                      5 	.module pca_hal
                                      6 	.optsdcc -mmcs51 --model-medium
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _pcaOnInterrupt
                                     12 	.globl _gpioConfigure
                                     13 	.globl _S1SM0_FE
                                     14 	.globl _T1IF
                                     15 	.globl _T1R
                                     16 	.globl _T0IF
                                     17 	.globl _T0R
                                     18 	.globl _CF
                                     19 	.globl _CR
                                     20 	.globl _CCF1
                                     21 	.globl _CCF0
                                     22 	.globl _CY
                                     23 	.globl _AC
                                     24 	.globl _F0
                                     25 	.globl _RS1
                                     26 	.globl _RS0
                                     27 	.globl _OV
                                     28 	.globl _F1
                                     29 	.globl _P
                                     30 	.globl _EA
                                     31 	.globl _INT1IF
                                     32 	.globl _IT1
                                     33 	.globl _INT0IF
                                     34 	.globl _IT0
                                     35 	.globl _P5_5
                                     36 	.globl _P5_4
                                     37 	.globl _P5_3
                                     38 	.globl _P5_2
                                     39 	.globl _P5_1
                                     40 	.globl _P5_0
                                     41 	.globl _P4_7
                                     42 	.globl _P4_6
                                     43 	.globl _P4_5
                                     44 	.globl _P4_4
                                     45 	.globl _P4_3
                                     46 	.globl _P4_2
                                     47 	.globl _P4_1
                                     48 	.globl _P4_0
                                     49 	.globl _P3_7
                                     50 	.globl _P3_6
                                     51 	.globl _P3_5
                                     52 	.globl _P3_4
                                     53 	.globl _P3_3
                                     54 	.globl _P3_2
                                     55 	.globl _P3_1
                                     56 	.globl _P3_0
                                     57 	.globl _P2_7
                                     58 	.globl _P2_6
                                     59 	.globl _P2_5
                                     60 	.globl _P2_4
                                     61 	.globl _P2_3
                                     62 	.globl _P2_2
                                     63 	.globl _P2_1
                                     64 	.globl _P2_0
                                     65 	.globl _P1_7
                                     66 	.globl _P1_6
                                     67 	.globl _P1_5
                                     68 	.globl _P1_4
                                     69 	.globl _P1_3
                                     70 	.globl _P1_2
                                     71 	.globl _P1_1
                                     72 	.globl _P1_0
                                     73 	.globl _P0_7
                                     74 	.globl _P0_6
                                     75 	.globl _P0_5
                                     76 	.globl _P0_4
                                     77 	.globl _P0_3
                                     78 	.globl _P0_2
                                     79 	.globl _P0_1
                                     80 	.globl _P0_0
                                     81 	.globl _S2BUF
                                     82 	.globl _S2CON
                                     83 	.globl _S1BUF
                                     84 	.globl _S1CON
                                     85 	.globl _SADEN
                                     86 	.globl _SADDR
                                     87 	.globl _WDT_CONTR
                                     88 	.globl _AUXR
                                     89 	.globl _BRT
                                     90 	.globl _T1
                                     91 	.globl _T1H
                                     92 	.globl _T1L
                                     93 	.globl _T0
                                     94 	.globl _T0H
                                     95 	.globl _T0L
                                     96 	.globl _TMOD
                                     97 	.globl _TCON
                                     98 	.globl _CLKDIV
                                     99 	.globl _SPDAT
                                    100 	.globl _SPCTL
                                    101 	.globl _SPSTAT
                                    102 	.globl _PCA_PWM1
                                    103 	.globl _PCA_PWM0
                                    104 	.globl _CCAP1
                                    105 	.globl _CCAP0
                                    106 	.globl _CCAP1H
                                    107 	.globl _CCAP0H
                                    108 	.globl _CCAP1L
                                    109 	.globl _CCAP0L
                                    110 	.globl _PCA_CTR
                                    111 	.globl _CH
                                    112 	.globl _CL
                                    113 	.globl _CCAPM1
                                    114 	.globl _CCAPM0
                                    115 	.globl _CMOD
                                    116 	.globl _CCON
                                    117 	.globl _BUS_SPEED
                                    118 	.globl _P4SW
                                    119 	.globl _P1ASF
                                    120 	.globl _P_SW1
                                    121 	.globl _WAKE_CLKO
                                    122 	.globl _PCON
                                    123 	.globl _B
                                    124 	.globl _ACC
                                    125 	.globl _PSW
                                    126 	.globl _SP
                                    127 	.globl _IP2H
                                    128 	.globl _IP2L
                                    129 	.globl _IP1H
                                    130 	.globl _IP1L
                                    131 	.globl _IE2
                                    132 	.globl _IE1
                                    133 	.globl _IAP_CONTR
                                    134 	.globl _IAP_TRIG
                                    135 	.globl _IAP_CMD
                                    136 	.globl _IAP_ADDR
                                    137 	.globl _IAP_ADDRL
                                    138 	.globl _IAP_ADDRH
                                    139 	.globl _IAP_DATA
                                    140 	.globl _P5M0
                                    141 	.globl _P5M1
                                    142 	.globl _P5
                                    143 	.globl _P4M0
                                    144 	.globl _P4M1
                                    145 	.globl _P4
                                    146 	.globl _P3M0
                                    147 	.globl _P3M1
                                    148 	.globl _P3
                                    149 	.globl _P2M0
                                    150 	.globl _P2M1
                                    151 	.globl _P2
                                    152 	.globl _P1M0
                                    153 	.globl _P1M1
                                    154 	.globl _P1
                                    155 	.globl _P0M0
                                    156 	.globl _P0M1
                                    157 	.globl _P0
                                    158 	.globl _DPS
                                    159 	.globl _DP
                                    160 	.globl _DPH
                                    161 	.globl _DPL
                                    162 	.globl _ADC_RESL
                                    163 	.globl _ADC_RESH
                                    164 	.globl _ADC_CONTR
                                    165 	.globl _pcaStartTimer_PARM_4
                                    166 	.globl _pcaStartTimer_PARM_3
                                    167 	.globl _pcaStartTimer_PARM_2
                                    168 	.globl _pcaSetPwmDutyCycle_PARM_2
                                    169 	.globl _pcaStartPwm_PARM_5
                                    170 	.globl _pcaStartPwm_PARM_4
                                    171 	.globl _pcaStartPwm_PARM_3
                                    172 	.globl _pcaStartPwm_PARM_2
                                    173 	.globl _pcaStartCapture_PARM_5
                                    174 	.globl _pcaStartCapture_PARM_4
                                    175 	.globl _pcaStartCapture_PARM_3
                                    176 	.globl _pcaStartCapture_PARM_2
                                    177 	.globl _pcaInitialise_PARM_4
                                    178 	.globl _pcaInitialise_PARM_3
                                    179 	.globl _pcaInitialise_PARM_2
                                    180 	.globl _pcaInitialise
                                    181 	.globl _pcaStartCapture
                                    182 	.globl _pcaStartPwm
                                    183 	.globl _pcaSetPwmDutyCycle
                                    184 	.globl _pcaStartTimer
                                    185 	.globl ___pca_isr
                                    186 ;--------------------------------------------------------
                                    187 ; special function registers
                                    188 ;--------------------------------------------------------
                                    189 	.area RSEG    (ABS,DATA)
      000000                        190 	.org 0x0000
                           0000BC   191 _ADC_CONTR	=	0x00bc
                           0000BD   192 _ADC_RESH	=	0x00bd
                           0000BE   193 _ADC_RESL	=	0x00be
                           000082   194 _DPL	=	0x0082
                           000083   195 _DPH	=	0x0083
                           008382   196 _DP	=	0x8382
                           0000A2   197 _DPS	=	0x00a2
                           000080   198 _P0	=	0x0080
                           000093   199 _P0M1	=	0x0093
                           000094   200 _P0M0	=	0x0094
                           000090   201 _P1	=	0x0090
                           000091   202 _P1M1	=	0x0091
                           000092   203 _P1M0	=	0x0092
                           0000A0   204 _P2	=	0x00a0
                           000095   205 _P2M1	=	0x0095
                           000096   206 _P2M0	=	0x0096
                           0000B0   207 _P3	=	0x00b0
                           0000B1   208 _P3M1	=	0x00b1
                           0000B2   209 _P3M0	=	0x00b2
                           0000C0   210 _P4	=	0x00c0
                           0000B3   211 _P4M1	=	0x00b3
                           0000B4   212 _P4M0	=	0x00b4
                           0000C8   213 _P5	=	0x00c8
                           0000C9   214 _P5M1	=	0x00c9
                           0000CA   215 _P5M0	=	0x00ca
                           0000C2   216 _IAP_DATA	=	0x00c2
                           0000C3   217 _IAP_ADDRH	=	0x00c3
                           0000C4   218 _IAP_ADDRL	=	0x00c4
                           00C3C4   219 _IAP_ADDR	=	0xc3c4
                           0000C5   220 _IAP_CMD	=	0x00c5
                           0000C6   221 _IAP_TRIG	=	0x00c6
                           0000C7   222 _IAP_CONTR	=	0x00c7
                           0000A8   223 _IE1	=	0x00a8
                           0000AF   224 _IE2	=	0x00af
                           0000B8   225 _IP1L	=	0x00b8
                           0000B7   226 _IP1H	=	0x00b7
                           0000B5   227 _IP2L	=	0x00b5
                           0000B6   228 _IP2H	=	0x00b6
                           000081   229 _SP	=	0x0081
                           0000D0   230 _PSW	=	0x00d0
                           0000E0   231 _ACC	=	0x00e0
                           0000F0   232 _B	=	0x00f0
                           000087   233 _PCON	=	0x0087
                           00008F   234 _WAKE_CLKO	=	0x008f
                           0000A2   235 _P_SW1	=	0x00a2
                           00009D   236 _P1ASF	=	0x009d
                           0000BB   237 _P4SW	=	0x00bb
                           0000A1   238 _BUS_SPEED	=	0x00a1
                           0000D8   239 _CCON	=	0x00d8
                           0000D9   240 _CMOD	=	0x00d9
                           0000DA   241 _CCAPM0	=	0x00da
                           0000DB   242 _CCAPM1	=	0x00db
                           0000E9   243 _CL	=	0x00e9
                           0000F9   244 _CH	=	0x00f9
                           00F9E9   245 _PCA_CTR	=	0xf9e9
                           0000EA   246 _CCAP0L	=	0x00ea
                           0000EB   247 _CCAP1L	=	0x00eb
                           0000FA   248 _CCAP0H	=	0x00fa
                           0000FB   249 _CCAP1H	=	0x00fb
                           00FAEA   250 _CCAP0	=	0xfaea
                           00FBEB   251 _CCAP1	=	0xfbeb
                           0000F2   252 _PCA_PWM0	=	0x00f2
                           0000F3   253 _PCA_PWM1	=	0x00f3
                           0000CD   254 _SPSTAT	=	0x00cd
                           0000CE   255 _SPCTL	=	0x00ce
                           0000CF   256 _SPDAT	=	0x00cf
                           000097   257 _CLKDIV	=	0x0097
                           000088   258 _TCON	=	0x0088
                           000089   259 _TMOD	=	0x0089
                           00008A   260 _T0L	=	0x008a
                           00008C   261 _T0H	=	0x008c
                           008C8A   262 _T0	=	0x8c8a
                           00008B   263 _T1L	=	0x008b
                           00008D   264 _T1H	=	0x008d
                           008D8B   265 _T1	=	0x8d8b
                           00009C   266 _BRT	=	0x009c
                           00008E   267 _AUXR	=	0x008e
                           0000C1   268 _WDT_CONTR	=	0x00c1
                           0000A9   269 _SADDR	=	0x00a9
                           0000B9   270 _SADEN	=	0x00b9
                           000098   271 _S1CON	=	0x0098
                           000099   272 _S1BUF	=	0x0099
                           00009A   273 _S2CON	=	0x009a
                           00009B   274 _S2BUF	=	0x009b
                                    275 ;--------------------------------------------------------
                                    276 ; special function bits
                                    277 ;--------------------------------------------------------
                                    278 	.area RSEG    (ABS,DATA)
      000000                        279 	.org 0x0000
                           000080   280 _P0_0	=	0x0080
                           000081   281 _P0_1	=	0x0081
                           000082   282 _P0_2	=	0x0082
                           000083   283 _P0_3	=	0x0083
                           000084   284 _P0_4	=	0x0084
                           000085   285 _P0_5	=	0x0085
                           000086   286 _P0_6	=	0x0086
                           000087   287 _P0_7	=	0x0087
                           000090   288 _P1_0	=	0x0090
                           000091   289 _P1_1	=	0x0091
                           000092   290 _P1_2	=	0x0092
                           000093   291 _P1_3	=	0x0093
                           000094   292 _P1_4	=	0x0094
                           000095   293 _P1_5	=	0x0095
                           000096   294 _P1_6	=	0x0096
                           000097   295 _P1_7	=	0x0097
                           0000A0   296 _P2_0	=	0x00a0
                           0000A1   297 _P2_1	=	0x00a1
                           0000A2   298 _P2_2	=	0x00a2
                           0000A3   299 _P2_3	=	0x00a3
                           0000A4   300 _P2_4	=	0x00a4
                           0000A5   301 _P2_5	=	0x00a5
                           0000A6   302 _P2_6	=	0x00a6
                           0000A7   303 _P2_7	=	0x00a7
                           0000B0   304 _P3_0	=	0x00b0
                           0000B1   305 _P3_1	=	0x00b1
                           0000B2   306 _P3_2	=	0x00b2
                           0000B3   307 _P3_3	=	0x00b3
                           0000B4   308 _P3_4	=	0x00b4
                           0000B5   309 _P3_5	=	0x00b5
                           0000B6   310 _P3_6	=	0x00b6
                           0000B7   311 _P3_7	=	0x00b7
                           0000C0   312 _P4_0	=	0x00c0
                           0000C1   313 _P4_1	=	0x00c1
                           0000C2   314 _P4_2	=	0x00c2
                           0000C3   315 _P4_3	=	0x00c3
                           0000C4   316 _P4_4	=	0x00c4
                           0000C5   317 _P4_5	=	0x00c5
                           0000C6   318 _P4_6	=	0x00c6
                           0000C7   319 _P4_7	=	0x00c7
                           0000C8   320 _P5_0	=	0x00c8
                           0000C9   321 _P5_1	=	0x00c9
                           0000CA   322 _P5_2	=	0x00ca
                           0000CB   323 _P5_3	=	0x00cb
                           0000CC   324 _P5_4	=	0x00cc
                           0000CD   325 _P5_5	=	0x00cd
                           000088   326 _IT0	=	0x0088
                           000089   327 _INT0IF	=	0x0089
                           00008A   328 _IT1	=	0x008a
                           00008B   329 _INT1IF	=	0x008b
                           0000AF   330 _EA	=	0x00af
                           0000D0   331 _P	=	0x00d0
                           0000D1   332 _F1	=	0x00d1
                           0000D2   333 _OV	=	0x00d2
                           0000D3   334 _RS0	=	0x00d3
                           0000D4   335 _RS1	=	0x00d4
                           0000D5   336 _F0	=	0x00d5
                           0000D6   337 _AC	=	0x00d6
                           0000D7   338 _CY	=	0x00d7
                           0000D8   339 _CCF0	=	0x00d8
                           0000D9   340 _CCF1	=	0x00d9
                           0000DE   341 _CR	=	0x00de
                           0000DF   342 _CF	=	0x00df
                           00008C   343 _T0R	=	0x008c
                           00008D   344 _T0IF	=	0x008d
                           00008E   345 _T1R	=	0x008e
                           00008F   346 _T1IF	=	0x008f
                           00009F   347 _S1SM0_FE	=	0x009f
                                    348 ;--------------------------------------------------------
                                    349 ; overlayable register banks
                                    350 ;--------------------------------------------------------
                                    351 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        352 	.ds 8
                                    353 	.area REG_BANK_1	(REL,OVR,DATA)
      000008                        354 	.ds 8
                                    355 ;--------------------------------------------------------
                                    356 ; overlayable bit register bank
                                    357 ;--------------------------------------------------------
                                    358 	.area BIT_BANK	(REL,OVR,DATA)
      000021                        359 bits:
      000021                        360 	.ds 1
                           008000   361 	b0 = bits[0]
                           008100   362 	b1 = bits[1]
                           008200   363 	b2 = bits[2]
                           008300   364 	b3 = bits[3]
                           008400   365 	b4 = bits[4]
                           008500   366 	b5 = bits[5]
                           008600   367 	b6 = bits[6]
                           008700   368 	b7 = bits[7]
                                    369 ;--------------------------------------------------------
                                    370 ; internal ram data
                                    371 ;--------------------------------------------------------
                                    372 	.area DSEG    (DATA)
      000013                        373 ___pca_isr_sloc0_1_0:
      000013                        374 	.ds 4
                                    375 ;--------------------------------------------------------
                                    376 ; overlayable items in internal ram
                                    377 ;--------------------------------------------------------
                                    378 ;--------------------------------------------------------
                                    379 ; indirectly addressable internal ram data
                                    380 ;--------------------------------------------------------
                                    381 	.area ISEG    (DATA)
                                    382 ;--------------------------------------------------------
                                    383 ; absolute internal ram data
                                    384 ;--------------------------------------------------------
                                    385 	.area IABS    (ABS,DATA)
                                    386 	.area IABS    (ABS,DATA)
                                    387 ;--------------------------------------------------------
                                    388 ; bit data
                                    389 ;--------------------------------------------------------
                                    390 	.area BSEG    (BIT)
      000002                        391 ___pcaConfigurePWM_sloc0_1_0:
      000002                        392 	.ds 1
                                    393 ;--------------------------------------------------------
                                    394 ; paged external ram data
                                    395 ;--------------------------------------------------------
                                    396 	.area PSEG    (PAG,XDATA)
      000014                        397 ___pca_pinConfigurations:
      000014                        398 	.ds 6
      00001A                        399 ___pca_pinSwitch:
      00001A                        400 	.ds 1
      00001B                        401 ___pca_captureStartCount:
      00001B                        402 	.ds 8
      000023                        403 ___pca_captureEndCount:
      000023                        404 	.ds 8
      00002B                        405 ___pca_timerPeriod:
      00002B                        406 	.ds 4
      00002F                        407 ___pca_timerValue:
      00002F                        408 	.ds 4
      000033                        409 ___pca_captureOverflowCounter:
      000033                        410 	.ds 2
      000035                        411 ___pca_captureShiftBits:
      000035                        412 	.ds 2
      000037                        413 ___pca_captureMode:
      000037                        414 	.ds 2
      000039                        415 ___pca_channelMode:
      000039                        416 	.ds 2
      00003B                        417 ___pca_configureChannelOutput_PARM_2:
      00003B                        418 	.ds 1
      00003C                        419 ___pca_configureChannelOutput_pinConfig_65536_12:
      00003C                        420 	.ds 6
      000042                        421 _pcaInitialise_PARM_2:
      000042                        422 	.ds 1
      000043                        423 _pcaInitialise_PARM_3:
      000043                        424 	.ds 1
      000044                        425 _pcaInitialise_PARM_4:
      000044                        426 	.ds 1
      000045                        427 _pcaStartCapture_PARM_2:
      000045                        428 	.ds 1
      000046                        429 _pcaStartCapture_PARM_3:
      000046                        430 	.ds 1
      000047                        431 _pcaStartCapture_PARM_4:
      000047                        432 	.ds 1
      000048                        433 _pcaStartCapture_PARM_5:
      000048                        434 	.ds 1
      000049                        435 ___pcaConfigurePWM_PARM_2:
      000049                        436 	.ds 1
      00004A                        437 ___pcaConfigurePWM_PARM_3:
      00004A                        438 	.ds 1
      00004B                        439 ___pcaConfigurePWM_PARM_4:
      00004B                        440 	.ds 1
      00004C                        441 ___pcaConfigurePWM_PARM_5:
      00004C                        442 	.ds 1
      00004D                        443 ___pcaConfigurePWM_PARM_6:
      00004D                        444 	.ds 2
      00004F                        445 _pcaStartPwm_PARM_2:
      00004F                        446 	.ds 1
      000050                        447 _pcaStartPwm_PARM_3:
      000050                        448 	.ds 1
      000051                        449 _pcaStartPwm_PARM_4:
      000051                        450 	.ds 1
      000052                        451 _pcaStartPwm_PARM_5:
      000052                        452 	.ds 2
      000054                        453 _pcaSetPwmDutyCycle_PARM_2:
      000054                        454 	.ds 2
      000056                        455 _pcaStartTimer_PARM_2:
      000056                        456 	.ds 1
      000057                        457 _pcaStartTimer_PARM_3:
      000057                        458 	.ds 1
      000058                        459 _pcaStartTimer_PARM_4:
      000058                        460 	.ds 2
      00005A                        461 ___pca_isr_ccaph_65536_44:
      00005A                        462 	.ds 1
      00005B                        463 ___pca_isr_channel_65536_44:
      00005B                        464 	.ds 1
      00005C                        465 ___pca_isr_width_65536_44:
      00005C                        466 	.ds 4
                                    467 ;--------------------------------------------------------
                                    468 ; external ram data
                                    469 ;--------------------------------------------------------
                                    470 	.area XSEG    (XDATA)
                                    471 ;--------------------------------------------------------
                                    472 ; absolute external ram data
                                    473 ;--------------------------------------------------------
                                    474 	.area XABS    (ABS,XDATA)
                                    475 ;--------------------------------------------------------
                                    476 ; external initialized ram data
                                    477 ;--------------------------------------------------------
                                    478 	.area XISEG   (XDATA)
                                    479 	.area HOME    (CODE)
                                    480 	.area GSINIT0 (CODE)
                                    481 	.area GSINIT1 (CODE)
                                    482 	.area GSINIT2 (CODE)
                                    483 	.area GSINIT3 (CODE)
                                    484 	.area GSINIT4 (CODE)
                                    485 	.area GSINIT5 (CODE)
                                    486 	.area GSINIT  (CODE)
                                    487 	.area GSFINAL (CODE)
                                    488 	.area CSEG    (CODE)
                                    489 ;--------------------------------------------------------
                                    490 ; global & static initialisations
                                    491 ;--------------------------------------------------------
                                    492 	.area HOME    (CODE)
                                    493 	.area GSINIT  (CODE)
                                    494 	.area GSFINAL (CODE)
                                    495 	.area GSINIT  (CODE)
                                    496 ;	pca-hal.c:39: static uint8_t __pca_pinConfigurations[][PCA_CHANNELS + 1] = {
      0000A1 78 14            [12]  497 	mov	r0,#___pca_pinConfigurations
      0000A3 74 13            [12]  498 	mov	a,#0x13
      0000A5 F2               [24]  499 	movx	@r0,a
      0000A6 78 15            [12]  500 	mov	r0,#(___pca_pinConfigurations + 0x0001)
      0000A8 04               [12]  501 	inc	a
      0000A9 F2               [24]  502 	movx	@r0,a
      0000AA 78 16            [12]  503 	mov	r0,#(___pca_pinConfigurations + 0x0002)
      0000AC 74 12            [12]  504 	mov	a,#0x12
      0000AE F2               [24]  505 	movx	@r0,a
      0000AF 78 17            [12]  506 	mov	r0,#(___pca_pinConfigurations + 0x0003)
      0000B1 74 42            [12]  507 	mov	a,#0x42
      0000B3 F2               [24]  508 	movx	@r0,a
      0000B4 78 18            [12]  509 	mov	r0,#(___pca_pinConfigurations + 0x0004)
      0000B6 04               [12]  510 	inc	a
      0000B7 F2               [24]  511 	movx	@r0,a
      0000B8 78 19            [12]  512 	mov	r0,#(___pca_pinConfigurations + 0x0005)
      0000BA 74 41            [12]  513 	mov	a,#0x41
      0000BC F2               [24]  514 	movx	@r0,a
                                    515 ;--------------------------------------------------------
                                    516 ; Home
                                    517 ;--------------------------------------------------------
                                    518 	.area HOME    (CODE)
                                    519 	.area HOME    (CODE)
                                    520 ;--------------------------------------------------------
                                    521 ; code
                                    522 ;--------------------------------------------------------
                                    523 	.area CSEG    (CODE)
                                    524 ;------------------------------------------------------------
                                    525 ;Allocation info for local variables in function '__pca_configureChannelOutput'
                                    526 ;------------------------------------------------------------
                                    527 ;	pca-hal.c:127: static void __pca_configureChannelOutput(PCA_Channel channel, GpioPortMode pinMode) {
                                    528 ;	-----------------------------------------
                                    529 ;	 function __pca_configureChannelOutput
                                    530 ;	-----------------------------------------
      000902                        531 ___pca_configureChannelOutput:
                           000007   532 	ar7 = 0x07
                           000006   533 	ar6 = 0x06
                           000005   534 	ar5 = 0x05
                           000004   535 	ar4 = 0x04
                           000003   536 	ar3 = 0x03
                           000002   537 	ar2 = 0x02
                           000001   538 	ar1 = 0x01
                           000000   539 	ar0 = 0x00
      000902 AF 82            [24]  540 	mov	r7,dpl
                                    541 ;	pca-hal.c:128: uint8_t channelPin = __pca_pinConfigurations[__pca_pinSwitch][channel];
      000904 78 1A            [12]  542 	mov	r0,#___pca_pinSwitch
      000906 E2               [24]  543 	movx	a,@r0
      000907 75 F0 03         [24]  544 	mov	b,#0x03
      00090A A4               [48]  545 	mul	ab
      00090B 24 14            [12]  546 	add	a,#___pca_pinConfigurations
      00090D 2F               [12]  547 	add	a,r7
      00090E F9               [12]  548 	mov	r1,a
      00090F E3               [24]  549 	movx	a,@r1
                                    550 ;	pca-hal.c:129: GpioPort port = (GpioPort) (channelPin >> 4);
      000910 FF               [12]  551 	mov	r7,a
      000911 C4               [12]  552 	swap	a
      000912 54 0F            [12]  553 	anl	a,#0x0f
      000914 FE               [12]  554 	mov	r6,a
                                    555 ;	pca-hal.c:130: GpioPin pin = (GpioPin) (channelPin & 0x0f);
      000915 53 07 0F         [24]  556 	anl	ar7,#0x0f
                                    557 ;	pca-hal.c:131: GpioConfig pinConfig = GPIO_PIN_CONFIG(port, pin, pinMode);
      000918 78 3C            [12]  558 	mov	r0,#___pca_configureChannelOutput_pinConfig_65536_12
      00091A EE               [12]  559 	mov	a,r6
      00091B F2               [24]  560 	movx	@r0,a
      00091C 78 3D            [12]  561 	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0001)
      00091E EF               [12]  562 	mov	a,r7
      00091F F2               [24]  563 	movx	@r0,a
      000920 78 3E            [12]  564 	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0002)
      000922 74 01            [12]  565 	mov	a,#0x01
      000924 F2               [24]  566 	movx	@r0,a
      000925 78 3F            [12]  567 	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0003)
      000927 79 3B            [12]  568 	mov	r1,#___pca_configureChannelOutput_PARM_2
      000929 E3               [24]  569 	movx	a,@r1
      00092A F2               [24]  570 	movx	@r0,a
      00092B 78 40            [12]  571 	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0004)
      00092D E4               [12]  572 	clr	a
      00092E F2               [24]  573 	movx	@r0,a
      00092F 78 41            [12]  574 	mov	r0,#(___pca_configureChannelOutput_pinConfig_65536_12 + 0x0005)
      000931 F2               [24]  575 	movx	@r0,a
                                    576 ;	pca-hal.c:132: gpioConfigure(&pinConfig);
      000932 90 00 3C         [24]  577 	mov	dptr,#___pca_configureChannelOutput_pinConfig_65536_12
      000935 75 F0 60         [24]  578 	mov	b,#0x60
                                    579 ;	pca-hal.c:133: }
      000938 02 03 D2         [24]  580 	ljmp	_gpioConfigure
                                    581 ;------------------------------------------------------------
                                    582 ;Allocation info for local variables in function 'pcaInitialise'
                                    583 ;------------------------------------------------------------
                                    584 ;	pca-hal.c:149: void pcaInitialise(PCA_ClockSource clockSource, PCA_CounterMode counterMode, PCA_InterruptEnable overflowInterrupt, uint8_t pinSwitch) {
                                    585 ;	-----------------------------------------
                                    586 ;	 function pcaInitialise
                                    587 ;	-----------------------------------------
      00093B                        588 _pcaInitialise:
      00093B AF 82            [24]  589 	mov	r7,dpl
                                    590 ;	pca-hal.c:150: __pca_pinSwitch = pinSwitch;
      00093D 78 44            [12]  591 	mov	r0,#_pcaInitialise_PARM_4
      00093F E2               [24]  592 	movx	a,@r0
      000940 FE               [12]  593 	mov	r6,a
      000941 78 1A            [12]  594 	mov	r0,#___pca_pinSwitch
      000943 F2               [24]  595 	movx	@r0,a
                                    596 ;	pca-hal.c:151: P_SW1 = (P_SW1 & ~M_CCP_S) | ((pinSwitch << P_CCP_S) & M_CCP_S);
      000944 74 BF            [12]  597 	mov	a,#0xbf
      000946 55 A2            [12]  598 	anl	a,_P_SW1
      000948 FD               [12]  599 	mov	r5,a
      000949 EE               [12]  600 	mov	a,r6
      00094A 03               [12]  601 	rr	a
      00094B 03               [12]  602 	rr	a
      00094C 54 C0            [12]  603 	anl	a,#0xc0
      00094E FE               [12]  604 	mov	r6,a
      00094F 74 40            [12]  605 	mov	a,#0x40
      000951 5E               [12]  606 	anl	a,r6
      000952 4D               [12]  607 	orl	a,r5
      000953 F5 A2            [12]  608 	mov	_P_SW1,a
                                    609 ;	pca-hal.c:153: for (uint8_t channel = 0; channel < PCA_CHANNELS; channel++) {
      000955 7E 00            [12]  610 	mov	r6,#0x00
      000957                        611 00103$:
      000957 BE 02 00         [24]  612 	cjne	r6,#0x02,00116$
      00095A                        613 00116$:
      00095A 50 09            [24]  614 	jnc	00101$
                                    615 ;	pca-hal.c:154: __pca_channelMode[channel] = PCA_UNUSED;
      00095C EE               [12]  616 	mov	a,r6
      00095D 24 39            [12]  617 	add	a,#___pca_channelMode
      00095F F8               [12]  618 	mov	r0,a
      000960 E4               [12]  619 	clr	a
      000961 F2               [24]  620 	movx	@r0,a
                                    621 ;	pca-hal.c:153: for (uint8_t channel = 0; channel < PCA_CHANNELS; channel++) {
      000962 0E               [12]  622 	inc	r6
      000963 80 F2            [24]  623 	sjmp	00103$
      000965                        624 00101$:
                                    625 ;	pca-hal.c:157: CMOD = (counterMode << P_CIDL) | (clockSource << P_CPS) | (overflowInterrupt << P_ECF);
      000965 78 42            [12]  626 	mov	r0,#_pcaInitialise_PARM_2
      000967 E2               [24]  627 	movx	a,@r0
      000968 03               [12]  628 	rr	a
      000969 54 80            [12]  629 	anl	a,#0x80
      00096B FE               [12]  630 	mov	r6,a
      00096C EF               [12]  631 	mov	a,r7
      00096D 2F               [12]  632 	add	a,r7
      00096E 42 06            [12]  633 	orl	ar6,a
      000970 78 43            [12]  634 	mov	r0,#_pcaInitialise_PARM_3
      000972 E2               [24]  635 	movx	a,@r0
      000973 4E               [12]  636 	orl	a,r6
      000974 F5 D9            [12]  637 	mov	_CMOD,a
                                    638 ;	pca-hal.c:158: CCON = 0;
                                    639 ;	pca-hal.c:159: PCA_CTR = 0;
      000976 E4               [12]  640 	clr	a
      000977 F5 D8            [12]  641 	mov	_CCON,a
      000979 F5 E9            [12]  642 	mov	((_PCA_CTR >> 0) & 0xFF),a
      00097B F5 F9            [12]  643 	mov	((_PCA_CTR >> 8) & 0xFF),a
                                    644 ;	pca-hal.c:160: CR = 1;
                                    645 ;	assignBit
      00097D D2 DE            [12]  646 	setb	_CR
                                    647 ;	pca-hal.c:161: }
      00097F 22               [24]  648 	ret
                                    649 ;------------------------------------------------------------
                                    650 ;Allocation info for local variables in function 'pcaStartCapture'
                                    651 ;------------------------------------------------------------
                                    652 ;	pca-hal.c:163: void pcaStartCapture(PCA_Channel channel, GpioPortMode pinMode, PCA_EdgeTrigger trigger, PCA_CaptureMode captureMode, uint8_t shiftBits) {
                                    653 ;	-----------------------------------------
                                    654 ;	 function pcaStartCapture
                                    655 ;	-----------------------------------------
      000980                        656 _pcaStartCapture:
      000980 AF 82            [24]  657 	mov	r7,dpl
                                    658 ;	pca-hal.c:164: CR = 0;
                                    659 ;	assignBit
      000982 C2 DE            [12]  660 	clr	_CR
                                    661 ;	pca-hal.c:165: __pca_configureChannelOutput(channel, pinMode);
      000984 78 45            [12]  662 	mov	r0,#_pcaStartCapture_PARM_2
      000986 79 3B            [12]  663 	mov	r1,#___pca_configureChannelOutput_PARM_2
      000988 E2               [24]  664 	movx	a,@r0
      000989 F3               [24]  665 	movx	@r1,a
      00098A 8F 82            [24]  666 	mov	dpl,r7
      00098C C0 07            [24]  667 	push	ar7
      00098E 12 09 02         [24]  668 	lcall	___pca_configureChannelOutput
      000991 D0 07            [24]  669 	pop	ar7
                                    670 ;	pca-hal.c:167: __pca_captureOverflowCounter[channel] = 0;
      000993 EF               [12]  671 	mov	a,r7
      000994 24 33            [12]  672 	add	a,#___pca_captureOverflowCounter
      000996 F8               [12]  673 	mov	r0,a
      000997 E4               [12]  674 	clr	a
      000998 F2               [24]  675 	movx	@r0,a
                                    676 ;	pca-hal.c:168: __pca_captureStartCount[channel].count = 0;
      000999 EF               [12]  677 	mov	a,r7
      00099A 2F               [12]  678 	add	a,r7
      00099B 25 E0            [12]  679 	add	a,acc
      00099D FE               [12]  680 	mov	r6,a
      00099E 24 1B            [12]  681 	add	a,#___pca_captureStartCount
      0009A0 F9               [12]  682 	mov	r1,a
      0009A1 E4               [12]  683 	clr	a
      0009A2 F3               [24]  684 	movx	@r1,a
      0009A3 09               [12]  685 	inc	r1
      0009A4 F3               [24]  686 	movx	@r1,a
      0009A5 09               [12]  687 	inc	r1
      0009A6 F3               [24]  688 	movx	@r1,a
      0009A7 09               [12]  689 	inc	r1
      0009A8 F3               [24]  690 	movx	@r1,a
                                    691 ;	pca-hal.c:169: __pca_captureEndCount[channel].count = 0;
      0009A9 EE               [12]  692 	mov	a,r6
      0009AA 24 23            [12]  693 	add	a,#___pca_captureEndCount
      0009AC F9               [12]  694 	mov	r1,a
      0009AD E4               [12]  695 	clr	a
      0009AE F3               [24]  696 	movx	@r1,a
      0009AF 09               [12]  697 	inc	r1
      0009B0 F3               [24]  698 	movx	@r1,a
      0009B1 09               [12]  699 	inc	r1
      0009B2 F3               [24]  700 	movx	@r1,a
      0009B3 09               [12]  701 	inc	r1
      0009B4 F3               [24]  702 	movx	@r1,a
                                    703 ;	pca-hal.c:170: __pca_captureShiftBits[channel] = shiftBits;
      0009B5 EF               [12]  704 	mov	a,r7
      0009B6 24 35            [12]  705 	add	a,#___pca_captureShiftBits
      0009B8 F8               [12]  706 	mov	r0,a
      0009B9 79 48            [12]  707 	mov	r1,#_pcaStartCapture_PARM_5
      0009BB E3               [24]  708 	movx	a,@r1
      0009BC F2               [24]  709 	movx	@r0,a
                                    710 ;	pca-hal.c:171: __pca_captureMode[channel] = captureMode;
      0009BD EF               [12]  711 	mov	a,r7
      0009BE 24 37            [12]  712 	add	a,#___pca_captureMode
      0009C0 F8               [12]  713 	mov	r0,a
      0009C1 79 47            [12]  714 	mov	r1,#_pcaStartCapture_PARM_4
      0009C3 E3               [24]  715 	movx	a,@r1
      0009C4 F2               [24]  716 	movx	@r0,a
                                    717 ;	pca-hal.c:172: __pca_channelMode[channel] = PCA_CAPTURE;
      0009C5 EF               [12]  718 	mov	a,r7
      0009C6 24 39            [12]  719 	add	a,#___pca_channelMode
      0009C8 F8               [12]  720 	mov	r0,a
      0009C9 74 40            [12]  721 	mov	a,#0x40
      0009CB F2               [24]  722 	movx	@r0,a
                                    723 ;	pca-hal.c:174: uint8_t ccapMode = __pca_ccapMode(PCA_CAPTURE, trigger);
      0009CC 78 46            [12]  724 	mov	r0,#_pcaStartCapture_PARM_3
      0009CE E2               [24]  725 	movx	a,@r0
      0009CF FE               [12]  726 	mov	r6,a
      0009D0 FD               [12]  727 	mov	r5,a
      0009D1 ED               [12]  728 	mov	a,r5
      0009D2 C4               [12]  729 	swap	a
      0009D3 54 F0            [12]  730 	anl	a,#0xf0
      0009D5 FD               [12]  731 	mov	r5,a
      0009D6 43 05 40         [24]  732 	orl	ar5,#0x40
      0009D9 EE               [12]  733 	mov	a,r6
      0009DA 60 06            [24]  734 	jz	00107$
      0009DC 7C 01            [12]  735 	mov	r4,#0x01
      0009DE 7E 00            [12]  736 	mov	r6,#0x00
      0009E0 80 04            [24]  737 	sjmp	00108$
      0009E2                        738 00107$:
      0009E2 7C 00            [12]  739 	mov	r4,#0x00
      0009E4 7E 00            [12]  740 	mov	r6,#0x00
      0009E6                        741 00108$:
      0009E6 EC               [12]  742 	mov	a,r4
      0009E7 4D               [12]  743 	orl	a,r5
      0009E8 FE               [12]  744 	mov	r6,a
                                    745 ;	pca-hal.c:176: switch (channel) {
      0009E9 BF 00 02         [24]  746 	cjne	r7,#0x00,00122$
      0009EC 80 05            [24]  747 	sjmp	00101$
      0009EE                        748 00122$:
                                    749 ;	pca-hal.c:177: case PCA_CHANNEL0:
      0009EE BF 01 12         [24]  750 	cjne	r7,#0x01,00103$
      0009F1 80 09            [24]  751 	sjmp	00102$
      0009F3                        752 00101$:
                                    753 ;	pca-hal.c:178: CCAPM0 = ccapMode;
      0009F3 8E DA            [24]  754 	mov	_CCAPM0,r6
                                    755 ;	pca-hal.c:179: CCAP0 = 0;
      0009F5 E4               [12]  756 	clr	a
      0009F6 F5 EA            [12]  757 	mov	((_CCAP0 >> 0) & 0xFF),a
      0009F8 F5 FA            [12]  758 	mov	((_CCAP0 >> 8) & 0xFF),a
                                    759 ;	pca-hal.c:180: break;
                                    760 ;	pca-hal.c:183: case PCA_CHANNEL1:
      0009FA 80 07            [24]  761 	sjmp	00103$
      0009FC                        762 00102$:
                                    763 ;	pca-hal.c:184: CCAPM1 = ccapMode;
      0009FC 8E DB            [24]  764 	mov	_CCAPM1,r6
                                    765 ;	pca-hal.c:185: CCAP1 = 0;
      0009FE E4               [12]  766 	clr	a
      0009FF F5 EB            [12]  767 	mov	((_CCAP1 >> 0) & 0xFF),a
      000A01 F5 FB            [12]  768 	mov	((_CCAP1 >> 8) & 0xFF),a
                                    769 ;	pca-hal.c:210: }
      000A03                        770 00103$:
                                    771 ;	pca-hal.c:212: PCA_CTR = 0;
      000A03 E4               [12]  772 	clr	a
      000A04 F5 E9            [12]  773 	mov	((_PCA_CTR >> 0) & 0xFF),a
      000A06 F5 F9            [12]  774 	mov	((_PCA_CTR >> 8) & 0xFF),a
                                    775 ;	pca-hal.c:213: CR = 1;
                                    776 ;	assignBit
      000A08 D2 DE            [12]  777 	setb	_CR
                                    778 ;	pca-hal.c:214: }
      000A0A 22               [24]  779 	ret
                                    780 ;------------------------------------------------------------
                                    781 ;Allocation info for local variables in function '__pcaConfigurePWM'
                                    782 ;------------------------------------------------------------
                                    783 ;	pca-hal.c:220: static void __pcaConfigurePWM(uint8_t initialise, PCA_Channel channel, GpioPortMode pinMode, PCA_PWM_Bits pwmBits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
                                    784 ;	-----------------------------------------
                                    785 ;	 function __pcaConfigurePWM
                                    786 ;	-----------------------------------------
      000A0B                        787 ___pcaConfigurePWM:
      000A0B AF 82            [24]  788 	mov	r7,dpl
                                    789 ;	pca-hal.c:221: __pca_channelMode[channel] = PCA_PWM;
      000A0D 78 49            [12]  790 	mov	r0,#___pcaConfigurePWM_PARM_2
      000A0F E2               [24]  791 	movx	a,@r0
      000A10 24 39            [12]  792 	add	a,#___pca_channelMode
      000A12 F8               [12]  793 	mov	r0,a
      000A13 74 42            [12]  794 	mov	a,#0x42
      000A15 F2               [24]  795 	movx	@r0,a
                                    796 ;	pca-hal.c:290: uint16_t reloadValue = maxValue - ((clocksHigh >= maxValue) ? (maxValue - 1) : clocksHigh);
      000A16 78 4D            [12]  797 	mov	r0,#___pcaConfigurePWM_PARM_6
      000A18 C3               [12]  798 	clr	c
      000A19 08               [12]  799 	inc	r0
      000A1A E2               [24]  800 	movx	a,@r0
      000A1B 94 01            [12]  801 	subb	a,#0x01
      000A1D 92 02            [24]  802 	mov	___pcaConfigurePWM_sloc0_1_0,c
      000A1F 40 06            [24]  803 	jc	00111$
      000A21 7D FF            [12]  804 	mov	r5,#0xff
      000A23 7E 00            [12]  805 	mov	r6,#0x00
      000A25 80 07            [24]  806 	sjmp	00112$
      000A27                        807 00111$:
      000A27 78 4D            [12]  808 	mov	r0,#___pcaConfigurePWM_PARM_6
      000A29 E2               [24]  809 	movx	a,@r0
      000A2A FD               [12]  810 	mov	r5,a
      000A2B 08               [12]  811 	inc	r0
      000A2C E2               [24]  812 	movx	a,@r0
      000A2D FE               [12]  813 	mov	r6,a
      000A2E                        814 00112$:
      000A2E E4               [12]  815 	clr	a
      000A2F C3               [12]  816 	clr	c
      000A30 9D               [12]  817 	subb	a,r5
      000A31 FD               [12]  818 	mov	r5,a
      000A32 74 01            [12]  819 	mov	a,#0x01
      000A34 9E               [12]  820 	subb	a,r6
                                    821 ;	pca-hal.c:291: uint8_t xccap = (reloadValue >> 8) & 3;
                                    822 ;	pca-hal.c:292: uint8_t ccap = reloadValue;
                                    823 ;	pca-hal.c:296: uint8_t pcaPwm = (bits << P_EBS) | (xccap << P_XCCAPH) | (xccap << P_XCCAPL);
      000A35 54 03            [12]  824 	anl	a,#0x03
      000A37 FC               [12]  825 	mov	r4,a
      000A38 C4               [12]  826 	swap	a
      000A39 54 F0            [12]  827 	anl	a,#0xf0
      000A3B FE               [12]  828 	mov	r6,a
      000A3C EC               [12]  829 	mov	a,r4
      000A3D 2C               [12]  830 	add	a,r4
      000A3E 25 E0            [12]  831 	add	a,acc
      000A40 42 06            [12]  832 	orl	ar6,a
                                    833 ;	pca-hal.c:297: uint8_t ccapMode = __pca_ccapMode(PCA_PWM, interruptTrigger);
      000A42 78 4C            [12]  834 	mov	r0,#___pcaConfigurePWM_PARM_5
      000A44 E2               [24]  835 	movx	a,@r0
      000A45 FC               [12]  836 	mov	r4,a
      000A46 FB               [12]  837 	mov	r3,a
      000A47 EB               [12]  838 	mov	a,r3
      000A48 C4               [12]  839 	swap	a
      000A49 54 F0            [12]  840 	anl	a,#0xf0
      000A4B FB               [12]  841 	mov	r3,a
      000A4C 43 03 42         [24]  842 	orl	ar3,#0x42
      000A4F EC               [12]  843 	mov	a,r4
      000A50 60 06            [24]  844 	jz	00113$
      000A52 7A 01            [12]  845 	mov	r2,#0x01
      000A54 7C 00            [12]  846 	mov	r4,#0x00
      000A56 80 04            [24]  847 	sjmp	00114$
      000A58                        848 00113$:
      000A58 7A 00            [12]  849 	mov	r2,#0x00
      000A5A 7C 00            [12]  850 	mov	r4,#0x00
      000A5C                        851 00114$:
      000A5C EA               [12]  852 	mov	a,r2
      000A5D 4B               [12]  853 	orl	a,r3
      000A5E FC               [12]  854 	mov	r4,a
                                    855 ;	pca-hal.c:299: switch (channel) {
      000A5F 78 49            [12]  856 	mov	r0,#___pcaConfigurePWM_PARM_2
      000A61 E2               [24]  857 	movx	a,@r0
      000A62 60 08            [24]  858 	jz	00101$
      000A64 78 49            [12]  859 	mov	r0,#___pcaConfigurePWM_PARM_2
      000A66 E2               [24]  860 	movx	a,@r0
                                    861 ;	pca-hal.c:300: case PCA_CHANNEL0:
      000A67 B4 01 19         [24]  862 	cjne	a,#0x01,00109$
      000A6A 80 0C            [24]  863 	sjmp	00104$
      000A6C                        864 00101$:
                                    865 ;	pca-hal.c:301: PCA_PWM0 = pcaPwm;
      000A6C 8E F2            [24]  866 	mov	_PCA_PWM0,r6
                                    867 ;	pca-hal.c:303: if (initialise) {
      000A6E EF               [12]  868 	mov	a,r7
      000A6F 60 04            [24]  869 	jz	00103$
                                    870 ;	pca-hal.c:304: CCAPM0 = ccapMode;
      000A71 8C DA            [24]  871 	mov	_CCAPM0,r4
                                    872 ;	pca-hal.c:305: CCAP0L = ccap;
      000A73 8D EA            [24]  873 	mov	_CCAP0L,r5
      000A75                        874 00103$:
                                    875 ;	pca-hal.c:308: CCAP0H = ccap;
      000A75 8D FA            [24]  876 	mov	_CCAP0H,r5
                                    877 ;	pca-hal.c:309: break;
                                    878 ;	pca-hal.c:312: case PCA_CHANNEL1:
      000A77 22               [24]  879 	ret
      000A78                        880 00104$:
                                    881 ;	pca-hal.c:313: PCA_PWM1 = pcaPwm;
      000A78 8E F3            [24]  882 	mov	_PCA_PWM1,r6
                                    883 ;	pca-hal.c:315: if (initialise) {
      000A7A EF               [12]  884 	mov	a,r7
      000A7B 60 04            [24]  885 	jz	00106$
                                    886 ;	pca-hal.c:316: CCAPM1 = ccapMode;
      000A7D 8C DB            [24]  887 	mov	_CCAPM1,r4
                                    888 ;	pca-hal.c:317: CCAP1L = ccap;
      000A7F 8D EB            [24]  889 	mov	_CCAP1L,r5
      000A81                        890 00106$:
                                    891 ;	pca-hal.c:320: CCAP1H = ccap;
      000A81 8D FB            [24]  892 	mov	_CCAP1H,r5
                                    893 ;	pca-hal.c:357: }
      000A83                        894 00109$:
                                    895 ;	pca-hal.c:358: }
      000A83 22               [24]  896 	ret
                                    897 ;------------------------------------------------------------
                                    898 ;Allocation info for local variables in function 'pcaStartPwm'
                                    899 ;------------------------------------------------------------
                                    900 ;	pca-hal.c:360: void pcaStartPwm(PCA_Channel channel, GpioPortMode pinMode, PCA_PWM_Bits bits, PCA_EdgeTrigger interruptTrigger, uint16_t clocksHigh) {
                                    901 ;	-----------------------------------------
                                    902 ;	 function pcaStartPwm
                                    903 ;	-----------------------------------------
      000A84                        904 _pcaStartPwm:
      000A84 AF 82            [24]  905 	mov	r7,dpl
                                    906 ;	pca-hal.c:361: __pcaConfigurePWM(1, channel, pinMode, bits, interruptTrigger, clocksHigh);
      000A86 78 49            [12]  907 	mov	r0,#___pcaConfigurePWM_PARM_2
      000A88 EF               [12]  908 	mov	a,r7
      000A89 F2               [24]  909 	movx	@r0,a
      000A8A 78 4F            [12]  910 	mov	r0,#_pcaStartPwm_PARM_2
      000A8C 79 4A            [12]  911 	mov	r1,#___pcaConfigurePWM_PARM_3
      000A8E E2               [24]  912 	movx	a,@r0
      000A8F F3               [24]  913 	movx	@r1,a
      000A90 78 50            [12]  914 	mov	r0,#_pcaStartPwm_PARM_3
      000A92 79 4B            [12]  915 	mov	r1,#___pcaConfigurePWM_PARM_4
      000A94 E2               [24]  916 	movx	a,@r0
      000A95 F3               [24]  917 	movx	@r1,a
      000A96 78 51            [12]  918 	mov	r0,#_pcaStartPwm_PARM_4
      000A98 79 4C            [12]  919 	mov	r1,#___pcaConfigurePWM_PARM_5
      000A9A E2               [24]  920 	movx	a,@r0
      000A9B F3               [24]  921 	movx	@r1,a
      000A9C 78 52            [12]  922 	mov	r0,#_pcaStartPwm_PARM_5
      000A9E 79 4D            [12]  923 	mov	r1,#___pcaConfigurePWM_PARM_6
      000AA0 E2               [24]  924 	movx	a,@r0
      000AA1 F3               [24]  925 	movx	@r1,a
      000AA2 08               [12]  926 	inc	r0
      000AA3 E2               [24]  927 	movx	a,@r0
      000AA4 09               [12]  928 	inc	r1
      000AA5 F3               [24]  929 	movx	@r1,a
      000AA6 75 82 01         [24]  930 	mov	dpl,#0x01
                                    931 ;	pca-hal.c:362: }
      000AA9 02 0A 0B         [24]  932 	ljmp	___pcaConfigurePWM
                                    933 ;------------------------------------------------------------
                                    934 ;Allocation info for local variables in function 'pcaSetPwmDutyCycle'
                                    935 ;------------------------------------------------------------
                                    936 ;	pca-hal.c:364: void pcaSetPwmDutyCycle(PCA_Channel channel, uint16_t clocksHigh) {
                                    937 ;	-----------------------------------------
                                    938 ;	 function pcaSetPwmDutyCycle
                                    939 ;	-----------------------------------------
      000AAC                        940 _pcaSetPwmDutyCycle:
      000AAC AF 82            [24]  941 	mov	r7,dpl
                                    942 ;	pca-hal.c:365: __pcaConfigurePWM(0, channel, GPIO_BIDIRECTIONAL, 0, PCA_EDGE_NONE, clocksHigh);
      000AAE 78 49            [12]  943 	mov	r0,#___pcaConfigurePWM_PARM_2
      000AB0 EF               [12]  944 	mov	a,r7
      000AB1 F2               [24]  945 	movx	@r0,a
      000AB2 78 4A            [12]  946 	mov	r0,#___pcaConfigurePWM_PARM_3
      000AB4 E4               [12]  947 	clr	a
      000AB5 F2               [24]  948 	movx	@r0,a
      000AB6 78 4B            [12]  949 	mov	r0,#___pcaConfigurePWM_PARM_4
      000AB8 F2               [24]  950 	movx	@r0,a
      000AB9 78 4C            [12]  951 	mov	r0,#___pcaConfigurePWM_PARM_5
      000ABB F2               [24]  952 	movx	@r0,a
      000ABC 78 54            [12]  953 	mov	r0,#_pcaSetPwmDutyCycle_PARM_2
      000ABE 79 4D            [12]  954 	mov	r1,#___pcaConfigurePWM_PARM_6
      000AC0 E2               [24]  955 	movx	a,@r0
      000AC1 F3               [24]  956 	movx	@r1,a
      000AC2 08               [12]  957 	inc	r0
      000AC3 E2               [24]  958 	movx	a,@r0
      000AC4 09               [12]  959 	inc	r1
      000AC5 F3               [24]  960 	movx	@r1,a
      000AC6 75 82 00         [24]  961 	mov	dpl,#0x00
                                    962 ;	pca-hal.c:366: }
      000AC9 02 0A 0B         [24]  963 	ljmp	___pcaConfigurePWM
                                    964 ;------------------------------------------------------------
                                    965 ;Allocation info for local variables in function 'pcaStartTimer'
                                    966 ;------------------------------------------------------------
                                    967 ;	pca-hal.c:368: void pcaStartTimer(PCA_Channel channel, GpioPortMode pinMode, PCA_OutputEnable pulseOutput, uint16_t timerPeriod) {
                                    968 ;	-----------------------------------------
                                    969 ;	 function pcaStartTimer
                                    970 ;	-----------------------------------------
      000ACC                        971 _pcaStartTimer:
      000ACC AF 82            [24]  972 	mov	r7,dpl
                                    973 ;	pca-hal.c:369: __pca_configureChannelOutput(channel, pinMode);
      000ACE 78 56            [12]  974 	mov	r0,#_pcaStartTimer_PARM_2
      000AD0 79 3B            [12]  975 	mov	r1,#___pca_configureChannelOutput_PARM_2
      000AD2 E2               [24]  976 	movx	a,@r0
      000AD3 F3               [24]  977 	movx	@r1,a
      000AD4 8F 82            [24]  978 	mov	dpl,r7
      000AD6 C0 07            [24]  979 	push	ar7
      000AD8 12 09 02         [24]  980 	lcall	___pca_configureChannelOutput
      000ADB D0 07            [24]  981 	pop	ar7
                                    982 ;	pca-hal.c:371: __pca_timerPeriod[channel] = timerPeriod;
      000ADD EF               [12]  983 	mov	a,r7
      000ADE 2F               [12]  984 	add	a,r7
      000ADF FE               [12]  985 	mov	r6,a
      000AE0 24 2B            [12]  986 	add	a,#___pca_timerPeriod
      000AE2 F8               [12]  987 	mov	r0,a
      000AE3 79 58            [12]  988 	mov	r1,#_pcaStartTimer_PARM_4
      000AE5 E3               [24]  989 	movx	a,@r1
      000AE6 F2               [24]  990 	movx	@r0,a
      000AE7 08               [12]  991 	inc	r0
      000AE8 09               [12]  992 	inc	r1
      000AE9 E3               [24]  993 	movx	a,@r1
      000AEA F2               [24]  994 	movx	@r0,a
                                    995 ;	pca-hal.c:372: __pca_timerValue[channel] = __pca_timerPeriod[channel];
      000AEB EE               [12]  996 	mov	a,r6
      000AEC 24 2F            [12]  997 	add	a,#___pca_timerValue
      000AEE F9               [12]  998 	mov	r1,a
      000AEF 78 58            [12]  999 	mov	r0,#_pcaStartTimer_PARM_4
      000AF1 E2               [24] 1000 	movx	a,@r0
      000AF2 F3               [24] 1001 	movx	@r1,a
      000AF3 09               [12] 1002 	inc	r1
      000AF4 08               [12] 1003 	inc	r0
      000AF5 E2               [24] 1004 	movx	a,@r0
      000AF6 F3               [24] 1005 	movx	@r1,a
      000AF7 19               [12] 1006 	dec	r1
                                   1007 ;	pca-hal.c:373: uint8_t ccapMode = (pulseOutput == PCA_OUTPUT_ENABLE) ? PCA_PULSE : PCA_TIMER;
      000AF8 78 57            [12] 1008 	mov	r0,#_pcaStartTimer_PARM_3
      000AFA E2               [24] 1009 	movx	a,@r0
      000AFB B4 01 06         [24] 1010 	cjne	a,#0x01,00106$
      000AFE 7D 4D            [12] 1011 	mov	r5,#0x4d
      000B00 7E 00            [12] 1012 	mov	r6,#0x00
      000B02 80 04            [24] 1013 	sjmp	00107$
      000B04                       1014 00106$:
      000B04 7D 49            [12] 1015 	mov	r5,#0x49
      000B06 7E 00            [12] 1016 	mov	r6,#0x00
      000B08                       1017 00107$:
                                   1018 ;	pca-hal.c:374: __pca_channelMode[channel] = ccapMode;
      000B08 EF               [12] 1019 	mov	a,r7
      000B09 24 39            [12] 1020 	add	a,#___pca_channelMode
      000B0B F8               [12] 1021 	mov	r0,a
      000B0C ED               [12] 1022 	mov	a,r5
      000B0D F2               [24] 1023 	movx	@r0,a
                                   1024 ;	pca-hal.c:376: switch (channel) {
      000B0E BF 00 02         [24] 1025 	cjne	r7,#0x00,00122$
      000B11 80 05            [24] 1026 	sjmp	00101$
      000B13                       1027 00122$:
                                   1028 ;	pca-hal.c:377: case PCA_CHANNEL0:
      000B13 BF 01 1A         [24] 1029 	cjne	r7,#0x01,00104$
      000B16 80 0D            [24] 1030 	sjmp	00102$
      000B18                       1031 00101$:
                                   1032 ;	pca-hal.c:378: CCAPM0 = ccapMode;
      000B18 8D DA            [24] 1033 	mov	_CCAPM0,r5
                                   1034 ;	pca-hal.c:379: CCAP0 = __pca_timerValue[channel];
      000B1A E3               [24] 1035 	movx	a,@r1
      000B1B FE               [12] 1036 	mov	r6,a
      000B1C 09               [12] 1037 	inc	r1
      000B1D E3               [24] 1038 	movx	a,@r1
      000B1E FF               [12] 1039 	mov	r7,a
      000B1F 19               [12] 1040 	dec	r1
      000B20 8E EA            [24] 1041 	mov	((_CCAP0 >> 0) & 0xFF),r6
      000B22 8F FA            [24] 1042 	mov	((_CCAP0 >> 8) & 0xFF),r7
                                   1043 ;	pca-hal.c:380: break;
                                   1044 ;	pca-hal.c:383: case PCA_CHANNEL1:
      000B24 22               [24] 1045 	ret
      000B25                       1046 00102$:
                                   1047 ;	pca-hal.c:384: CCAPM1 = ccapMode;
      000B25 8D DB            [24] 1048 	mov	_CCAPM1,r5
                                   1049 ;	pca-hal.c:385: CCAP1 = __pca_timerValue[channel];
      000B27 E3               [24] 1050 	movx	a,@r1
      000B28 FE               [12] 1051 	mov	r6,a
      000B29 09               [12] 1052 	inc	r1
      000B2A E3               [24] 1053 	movx	a,@r1
      000B2B FF               [12] 1054 	mov	r7,a
      000B2C 8E EB            [24] 1055 	mov	((_CCAP1 >> 0) & 0xFF),r6
      000B2E 8F FB            [24] 1056 	mov	((_CCAP1 >> 8) & 0xFF),r7
                                   1057 ;	pca-hal.c:410: }
      000B30                       1058 00104$:
                                   1059 ;	pca-hal.c:411: }
      000B30 22               [24] 1060 	ret
                                   1061 ;------------------------------------------------------------
                                   1062 ;Allocation info for local variables in function '__pca_isr'
                                   1063 ;------------------------------------------------------------
                                   1064 ;sloc0                     Allocated with name '___pca_isr_sloc0_1_0'
                                   1065 ;------------------------------------------------------------
                                   1066 ;	pca-hal.c:413: INTERRUPT_USING(__pca_isr, PCA_INTERRUPT, 1) CRITICAL {
                                   1067 ;	-----------------------------------------
                                   1068 ;	 function __pca_isr
                                   1069 ;	-----------------------------------------
      000B31                       1070 ___pca_isr:
                           00000F  1071 	ar7 = 0x0f
                           00000E  1072 	ar6 = 0x0e
                           00000D  1073 	ar5 = 0x0d
                           00000C  1074 	ar4 = 0x0c
                           00000B  1075 	ar3 = 0x0b
                           00000A  1076 	ar2 = 0x0a
                           000009  1077 	ar1 = 0x09
                           000008  1078 	ar0 = 0x08
      000B31 C2 AF            [12] 1079 	clr	ea
      000B33 C0 21            [24] 1080 	push	bits
      000B35 C0 E0            [24] 1081 	push	acc
      000B37 C0 F0            [24] 1082 	push	b
      000B39 C0 82            [24] 1083 	push	dpl
      000B3B C0 83            [24] 1084 	push	dph
      000B3D C0 D0            [24] 1085 	push	psw
      000B3F 75 D0 08         [24] 1086 	mov	psw,#0x08
                                   1087 ;	pca-hal.c:414: uint8_t ccapl = 0;
      000B42 7D 00            [12] 1088 	mov	r5,#0x00
                                   1089 ;	pca-hal.c:415: uint8_t ccaph = 0;
      000B44 78 5A            [12] 1090 	mov	r0,#___pca_isr_ccaph_65536_44
      000B46 E4               [12] 1091 	clr	a
      000B47 F2               [24] 1092 	movx	@r0,a
                                   1093 ;	pca-hal.c:416: uint8_t channel = HAL_PCA_CHANNELS;
      000B48 78 5B            [12] 1094 	mov	r0,#___pca_isr_channel_65536_44
      000B4A 74 02            [12] 1095 	mov	a,#0x02
      000B4C F2               [24] 1096 	movx	@r0,a
                                   1097 ;	pca-hal.c:420: if (CF) {
                                   1098 ;	pca-hal.c:421: CF = 0;
                                   1099 ;	assignBit
      000B4D 10 DF 02         [24] 1100 	jbc	_CF,00193$
      000B50 80 0F            [24] 1101 	sjmp	00102$
      000B52                       1102 00193$:
                                   1103 ;	pca-hal.c:422: __pca_captureOverflowCounter[PCA_CHANNEL0]++;
      000B52 78 33            [12] 1104 	mov	r0,#___pca_captureOverflowCounter
      000B54 E2               [24] 1105 	movx	a,@r0
      000B55 04               [12] 1106 	inc	a
      000B56 78 33            [12] 1107 	mov	r0,#___pca_captureOverflowCounter
      000B58 F2               [24] 1108 	movx	@r0,a
                                   1109 ;	pca-hal.c:425: __pca_captureOverflowCounter[PCA_CHANNEL1]++;
      000B59 78 34            [12] 1110 	mov	r0,#(___pca_captureOverflowCounter + 0x0001)
      000B5B E2               [24] 1111 	movx	a,@r0
      000B5C FC               [12] 1112 	mov	r4,a
      000B5D 04               [12] 1113 	inc	a
      000B5E 78 34            [12] 1114 	mov	r0,#(___pca_captureOverflowCounter + 0x0001)
      000B60 F2               [24] 1115 	movx	@r0,a
      000B61                       1116 00102$:
                                   1117 ;	pca-hal.c:437: if (CCF0) {
                                   1118 ;	pca-hal.c:438: CCF0 = 0;
                                   1119 ;	assignBit
      000B61 10 D8 02         [24] 1120 	jbc	_CCF0,00194$
      000B64 80 4D            [24] 1121 	sjmp	00110$
      000B66                       1122 00194$:
                                   1123 ;	pca-hal.c:439: channel = PCA_CHANNEL0;
      000B66 78 5B            [12] 1124 	mov	r0,#___pca_isr_channel_65536_44
      000B68 E4               [12] 1125 	clr	a
      000B69 F2               [24] 1126 	movx	@r0,a
                                   1127 ;	pca-hal.c:441: switch (__pca_channelMode[channel]) {
      000B6A 78 39            [12] 1128 	mov	r0,#___pca_channelMode
      000B6C E2               [24] 1129 	movx	a,@r0
      000B6D FC               [12] 1130 	mov	r4,a
      000B6E BC 40 02         [24] 1131 	cjne	r4,#0x40,00195$
      000B71 80 0A            [24] 1132 	sjmp	00103$
      000B73                       1133 00195$:
      000B73 BC 49 02         [24] 1134 	cjne	r4,#0x49,00196$
      000B76 80 1C            [24] 1135 	sjmp	00107$
      000B78                       1136 00196$:
                                   1137 ;	pca-hal.c:442: case PCA_CAPTURE:
      000B78 BC 4D 38         [24] 1138 	cjne	r4,#0x4d,00110$
      000B7B 80 17            [24] 1139 	sjmp	00107$
      000B7D                       1140 00103$:
                                   1141 ;	pca-hal.c:443: ccapl = CCAP0L;
      000B7D AD EA            [24] 1142 	mov	r5,_CCAP0L
                                   1143 ;	pca-hal.c:444: ccaph = CCAP0H;
      000B7F 78 5A            [12] 1144 	mov	r0,#___pca_isr_ccaph_65536_44
      000B81 E5 FA            [12] 1145 	mov	a,_CCAP0H
      000B83 F2               [24] 1146 	movx	@r0,a
                                   1147 ;	pca-hal.c:446: if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
      000B84 78 37            [12] 1148 	mov	r0,#___pca_captureMode
      000B86 E2               [24] 1149 	movx	a,@r0
      000B87 FC               [12] 1150 	mov	r4,a
      000B88 BC 01 28         [24] 1151 	cjne	r4,#0x01,00110$
                                   1152 ;	pca-hal.c:447: CCAPM0 = 0;
      000B8B 75 DA 00         [24] 1153 	mov	_CCAPM0,#0x00
                                   1154 ;	pca-hal.c:448: __pca_channelMode[channel] = PCA_UNUSED;
      000B8E 78 39            [12] 1155 	mov	r0,#___pca_channelMode
      000B90 E4               [12] 1156 	clr	a
      000B91 F2               [24] 1157 	movx	@r0,a
                                   1158 ;	pca-hal.c:450: break;
                                   1159 ;	pca-hal.c:453: case PCA_PULSE:
      000B92 80 1F            [24] 1160 	sjmp	00110$
      000B94                       1161 00107$:
                                   1162 ;	pca-hal.c:454: __pca_timerValue[channel] += __pca_timerPeriod[channel];
      000B94 78 2F            [12] 1163 	mov	r0,#___pca_timerValue
      000B96 E2               [24] 1164 	movx	a,@r0
      000B97 FB               [12] 1165 	mov	r3,a
      000B98 08               [12] 1166 	inc	r0
      000B99 E2               [24] 1167 	movx	a,@r0
      000B9A FC               [12] 1168 	mov	r4,a
      000B9B 78 2B            [12] 1169 	mov	r0,#___pca_timerPeriod
      000B9D E2               [24] 1170 	movx	a,@r0
      000B9E FA               [12] 1171 	mov	r2,a
      000B9F 08               [12] 1172 	inc	r0
      000BA0 E2               [24] 1173 	movx	a,@r0
      000BA1 FE               [12] 1174 	mov	r6,a
      000BA2 EA               [12] 1175 	mov	a,r2
      000BA3 2B               [12] 1176 	add	a,r3
      000BA4 FB               [12] 1177 	mov	r3,a
      000BA5 EE               [12] 1178 	mov	a,r6
      000BA6 3C               [12] 1179 	addc	a,r4
      000BA7 FC               [12] 1180 	mov	r4,a
      000BA8 78 2F            [12] 1181 	mov	r0,#___pca_timerValue
      000BAA EB               [12] 1182 	mov	a,r3
      000BAB F2               [24] 1183 	movx	@r0,a
      000BAC 08               [12] 1184 	inc	r0
      000BAD EC               [12] 1185 	mov	a,r4
      000BAE F2               [24] 1186 	movx	@r0,a
                                   1187 ;	pca-hal.c:455: CCAP0 = __pca_timerValue[channel];
      000BAF 8B EA            [24] 1188 	mov	((_CCAP0 >> 0) & 0xFF),r3
      000BB1 8C FA            [24] 1189 	mov	((_CCAP0 >> 8) & 0xFF),r4
                                   1190 ;	pca-hal.c:563: }
                                   1191 ;	pca-hal.c:457: }
      000BB3                       1192 00110$:
                                   1193 ;	pca-hal.c:461: if (CCF1) {
                                   1194 ;	pca-hal.c:462: CCF1 = 0;
                                   1195 ;	assignBit
      000BB3 10 D9 02         [24] 1196 	jbc	_CCF1,00200$
      000BB6 80 4E            [24] 1197 	sjmp	00118$
      000BB8                       1198 00200$:
                                   1199 ;	pca-hal.c:463: channel = PCA_CHANNEL1;
      000BB8 78 5B            [12] 1200 	mov	r0,#___pca_isr_channel_65536_44
      000BBA 74 01            [12] 1201 	mov	a,#0x01
      000BBC F2               [24] 1202 	movx	@r0,a
                                   1203 ;	pca-hal.c:465: switch (__pca_channelMode[channel]) {
      000BBD 78 3A            [12] 1204 	mov	r0,#(___pca_channelMode + 0x0001)
      000BBF E2               [24] 1205 	movx	a,@r0
      000BC0 FC               [12] 1206 	mov	r4,a
      000BC1 BC 40 02         [24] 1207 	cjne	r4,#0x40,00201$
      000BC4 80 0A            [24] 1208 	sjmp	00111$
      000BC6                       1209 00201$:
      000BC6 BC 49 02         [24] 1210 	cjne	r4,#0x49,00202$
      000BC9 80 1C            [24] 1211 	sjmp	00115$
      000BCB                       1212 00202$:
                                   1213 ;	pca-hal.c:466: case PCA_CAPTURE:
      000BCB BC 4D 38         [24] 1214 	cjne	r4,#0x4d,00118$
      000BCE 80 17            [24] 1215 	sjmp	00115$
      000BD0                       1216 00111$:
                                   1217 ;	pca-hal.c:467: ccapl = CCAP1L;
      000BD0 AD EB            [24] 1218 	mov	r5,_CCAP1L
                                   1219 ;	pca-hal.c:468: ccaph = CCAP1H;
      000BD2 78 5A            [12] 1220 	mov	r0,#___pca_isr_ccaph_65536_44
      000BD4 E5 FB            [12] 1221 	mov	a,_CCAP1H
      000BD6 F2               [24] 1222 	movx	@r0,a
                                   1223 ;	pca-hal.c:470: if (__pca_captureMode[channel] == PCA_ONE_SHOT) {
      000BD7 78 38            [12] 1224 	mov	r0,#(___pca_captureMode + 0x0001)
      000BD9 E2               [24] 1225 	movx	a,@r0
      000BDA FC               [12] 1226 	mov	r4,a
      000BDB BC 01 28         [24] 1227 	cjne	r4,#0x01,00118$
                                   1228 ;	pca-hal.c:471: CCAPM1 = 0;
      000BDE 75 DB 00         [24] 1229 	mov	_CCAPM1,#0x00
                                   1230 ;	pca-hal.c:472: __pca_channelMode[channel] = PCA_UNUSED;
      000BE1 78 3A            [12] 1231 	mov	r0,#(___pca_channelMode + 0x0001)
      000BE3 E4               [12] 1232 	clr	a
      000BE4 F2               [24] 1233 	movx	@r0,a
                                   1234 ;	pca-hal.c:474: break;
                                   1235 ;	pca-hal.c:477: case PCA_PULSE:
      000BE5 80 1F            [24] 1236 	sjmp	00118$
      000BE7                       1237 00115$:
                                   1238 ;	pca-hal.c:478: __pca_timerValue[channel] += __pca_timerPeriod[channel];
      000BE7 78 31            [12] 1239 	mov	r0,#(___pca_timerValue + 0x0002)
      000BE9 E2               [24] 1240 	movx	a,@r0
      000BEA FB               [12] 1241 	mov	r3,a
      000BEB 08               [12] 1242 	inc	r0
      000BEC E2               [24] 1243 	movx	a,@r0
      000BED FC               [12] 1244 	mov	r4,a
      000BEE 78 2D            [12] 1245 	mov	r0,#(___pca_timerPeriod + 0x0002)
      000BF0 E2               [24] 1246 	movx	a,@r0
      000BF1 FA               [12] 1247 	mov	r2,a
      000BF2 08               [12] 1248 	inc	r0
      000BF3 E2               [24] 1249 	movx	a,@r0
      000BF4 FE               [12] 1250 	mov	r6,a
      000BF5 EA               [12] 1251 	mov	a,r2
      000BF6 2B               [12] 1252 	add	a,r3
      000BF7 FB               [12] 1253 	mov	r3,a
      000BF8 EE               [12] 1254 	mov	a,r6
      000BF9 3C               [12] 1255 	addc	a,r4
      000BFA FC               [12] 1256 	mov	r4,a
      000BFB 78 31            [12] 1257 	mov	r0,#(___pca_timerValue + 0x0002)
      000BFD EB               [12] 1258 	mov	a,r3
      000BFE F2               [24] 1259 	movx	@r0,a
      000BFF 08               [12] 1260 	inc	r0
      000C00 EC               [12] 1261 	mov	a,r4
      000C01 F2               [24] 1262 	movx	@r0,a
                                   1263 ;	pca-hal.c:479: CCAP1 = __pca_timerValue[channel];
      000C02 8B EB            [24] 1264 	mov	((_CCAP1 >> 0) & 0xFF),r3
      000C04 8C FB            [24] 1265 	mov	((_CCAP1 >> 8) & 0xFF),r4
                                   1266 ;	pca-hal.c:563: }
                                   1267 ;	pca-hal.c:481: }
      000C06                       1268 00118$:
                                   1269 ;	pca-hal.c:543: if (channel < HAL_PCA_CHANNELS) {
      000C06 78 5B            [12] 1270 	mov	r0,#___pca_isr_channel_65536_44
      000C08 E2               [24] 1271 	movx	a,@r0
      000C09 B4 02 00         [24] 1272 	cjne	a,#0x02,00206$
      000C0C                       1273 00206$:
      000C0C 40 03            [24] 1274 	jc	00207$
      000C0E 02 0D 1A         [24] 1275 	ljmp	00125$
      000C11                       1276 00207$:
                                   1277 ;	pca-hal.c:544: switch (__pca_channelMode[channel]) {
      000C11 78 5B            [12] 1278 	mov	r0,#___pca_isr_channel_65536_44
      000C13 E2               [24] 1279 	movx	a,@r0
      000C14 24 39            [12] 1280 	add	a,#___pca_channelMode
      000C16 F9               [12] 1281 	mov	r1,a
      000C17 E3               [24] 1282 	movx	a,@r1
      000C18 FC               [12] 1283 	mov	r4,a
      000C19 BC 40 02         [24] 1284 	cjne	r4,#0x40,00208$
      000C1C 80 0F            [24] 1285 	sjmp	00119$
      000C1E                       1286 00208$:
      000C1E BC 42 03         [24] 1287 	cjne	r4,#0x42,00209$
      000C21 02 0D 0C         [24] 1288 	ljmp	00121$
      000C24                       1289 00209$:
      000C24 BC 49 03         [24] 1290 	cjne	r4,#0x49,00210$
      000C27 02 0D 0C         [24] 1291 	ljmp	00121$
      000C2A                       1292 00210$:
      000C2A 02 0D 1A         [24] 1293 	ljmp	00125$
                                   1294 ;	pca-hal.c:545: case PCA_CAPTURE:
      000C2D                       1295 00119$:
                                   1296 ;	pca-hal.c:546: __pca_captureStartCount[channel].count = __pca_captureEndCount[channel].count;
      000C2D 78 5B            [12] 1297 	mov	r0,#___pca_isr_channel_65536_44
      000C2F E2               [24] 1298 	movx	a,@r0
      000C30 25 E0            [12] 1299 	add	a,acc
      000C32 25 E0            [12] 1300 	add	a,acc
      000C34 FC               [12] 1301 	mov	r4,a
      000C35 24 1B            [12] 1302 	add	a,#___pca_captureStartCount
      000C37 F9               [12] 1303 	mov	r1,a
      000C38 EC               [12] 1304 	mov	a,r4
      000C39 24 23            [12] 1305 	add	a,#___pca_captureEndCount
      000C3B F8               [12] 1306 	mov	r0,a
      000C3C E2               [24] 1307 	movx	a,@r0
      000C3D FA               [12] 1308 	mov	r2,a
      000C3E 08               [12] 1309 	inc	r0
      000C3F E2               [24] 1310 	movx	a,@r0
      000C40 FB               [12] 1311 	mov	r3,a
      000C41 08               [12] 1312 	inc	r0
      000C42 E2               [24] 1313 	movx	a,@r0
      000C43 FE               [12] 1314 	mov	r6,a
      000C44 08               [12] 1315 	inc	r0
      000C45 E2               [24] 1316 	movx	a,@r0
      000C46 FF               [12] 1317 	mov	r7,a
      000C47 EA               [12] 1318 	mov	a,r2
      000C48 F3               [24] 1319 	movx	@r1,a
      000C49 09               [12] 1320 	inc	r1
      000C4A EB               [12] 1321 	mov	a,r3
      000C4B F3               [24] 1322 	movx	@r1,a
      000C4C 09               [12] 1323 	inc	r1
      000C4D EE               [12] 1324 	mov	a,r6
      000C4E F3               [24] 1325 	movx	@r1,a
      000C4F 09               [12] 1326 	inc	r1
      000C50 EF               [12] 1327 	mov	a,r7
      000C51 F3               [24] 1328 	movx	@r1,a
      000C52 19               [12] 1329 	dec	r1
      000C53 19               [12] 1330 	dec	r1
      000C54 19               [12] 1331 	dec	r1
                                   1332 ;	pca-hal.c:547: __pca_captureEndCount[channel].fields.ccapl = ccapl;
      000C55 EC               [12] 1333 	mov	a,r4
      000C56 24 23            [12] 1334 	add	a,#___pca_captureEndCount
      000C58 F8               [12] 1335 	mov	r0,a
      000C59 ED               [12] 1336 	mov	a,r5
      000C5A F2               [24] 1337 	movx	@r0,a
                                   1338 ;	pca-hal.c:548: __pca_captureEndCount[channel].fields.ccaph = ccaph;
      000C5B E8               [12] 1339 	mov	a,r0
      000C5C 04               [12] 1340 	inc	a
      000C5D FF               [12] 1341 	mov	r7,a
      000C5E C0 08            [24] 1342 	push	ar0
      000C60 A8 0F            [24] 1343 	mov	r0,ar7
      000C62 C0 09            [24] 1344 	push	ar1
      000C64 79 5A            [12] 1345 	mov	r1,#___pca_isr_ccaph_65536_44
      000C66 E3               [24] 1346 	movx	a,@r1
      000C67 F2               [24] 1347 	movx	@r0,a
      000C68 D0 08            [24] 1348 	pop	ar0
      000C6A D0 09            [24] 1349 	pop	ar1
                                   1350 ;	pca-hal.c:549: __pca_captureEndCount[channel].fields.cnt = __pca_captureOverflowCounter[channel];
      000C6C 74 02            [12] 1351 	mov	a,#0x02
      000C6E 28               [12] 1352 	add	a,r0
      000C6F FF               [12] 1353 	mov	r7,a
      000C70 C0 08            [24] 1354 	push	ar0
      000C72 78 5B            [12] 1355 	mov	r0,#___pca_isr_channel_65536_44
      000C74 E2               [24] 1356 	movx	a,@r0
      000C75 24 33            [12] 1357 	add	a,#___pca_captureOverflowCounter
      000C77 FE               [12] 1358 	mov	r6,a
      000C78 A8 0E            [24] 1359 	mov	r0,ar6
      000C7A E2               [24] 1360 	movx	a,@r0
      000C7B A8 0F            [24] 1361 	mov	r0,ar7
      000C7D F2               [24] 1362 	movx	@r0,a
      000C7E D0 08            [24] 1363 	pop	ar0
                                   1364 ;	pca-hal.c:550: __pca_captureEndCount[channel].fields.zero = 0;
      000C80 08               [12] 1365 	inc	r0
      000C81 08               [12] 1366 	inc	r0
      000C82 08               [12] 1367 	inc	r0
      000C83 E4               [12] 1368 	clr	a
      000C84 F2               [24] 1369 	movx	@r0,a
                                   1370 ;	pca-hal.c:552: width.count = (__pca_captureEndCount[channel].count - __pca_captureStartCount[channel].count) >> __pca_captureShiftBits[channel];
      000C85 EC               [12] 1371 	mov	a,r4
      000C86 24 23            [12] 1372 	add	a,#___pca_captureEndCount
      000C88 F8               [12] 1373 	mov	r0,a
      000C89 E2               [24] 1374 	movx	a,@r0
      000C8A F5 13            [12] 1375 	mov	___pca_isr_sloc0_1_0,a
      000C8C 08               [12] 1376 	inc	r0
      000C8D E2               [24] 1377 	movx	a,@r0
      000C8E F5 14            [12] 1378 	mov	(___pca_isr_sloc0_1_0 + 1),a
      000C90 08               [12] 1379 	inc	r0
      000C91 E2               [24] 1380 	movx	a,@r0
      000C92 F5 15            [12] 1381 	mov	(___pca_isr_sloc0_1_0 + 2),a
      000C94 08               [12] 1382 	inc	r0
      000C95 E2               [24] 1383 	movx	a,@r0
      000C96 F5 16            [12] 1384 	mov	(___pca_isr_sloc0_1_0 + 3),a
      000C98 E3               [24] 1385 	movx	a,@r1
      000C99 FA               [12] 1386 	mov	r2,a
      000C9A 09               [12] 1387 	inc	r1
      000C9B E3               [24] 1388 	movx	a,@r1
      000C9C FD               [12] 1389 	mov	r5,a
      000C9D 09               [12] 1390 	inc	r1
      000C9E E3               [24] 1391 	movx	a,@r1
      000C9F FE               [12] 1392 	mov	r6,a
      000CA0 09               [12] 1393 	inc	r1
      000CA1 E3               [24] 1394 	movx	a,@r1
      000CA2 FF               [12] 1395 	mov	r7,a
      000CA3 E5 13            [12] 1396 	mov	a,___pca_isr_sloc0_1_0
      000CA5 C3               [12] 1397 	clr	c
      000CA6 9A               [12] 1398 	subb	a,r2
      000CA7 FA               [12] 1399 	mov	r2,a
      000CA8 E5 14            [12] 1400 	mov	a,(___pca_isr_sloc0_1_0 + 1)
      000CAA 9D               [12] 1401 	subb	a,r5
      000CAB FD               [12] 1402 	mov	r5,a
      000CAC E5 15            [12] 1403 	mov	a,(___pca_isr_sloc0_1_0 + 2)
      000CAE 9E               [12] 1404 	subb	a,r6
      000CAF FE               [12] 1405 	mov	r6,a
      000CB0 E5 16            [12] 1406 	mov	a,(___pca_isr_sloc0_1_0 + 3)
      000CB2 9F               [12] 1407 	subb	a,r7
      000CB3 FF               [12] 1408 	mov	r7,a
      000CB4 78 5B            [12] 1409 	mov	r0,#___pca_isr_channel_65536_44
      000CB6 E2               [24] 1410 	movx	a,@r0
      000CB7 24 35            [12] 1411 	add	a,#___pca_captureShiftBits
      000CB9 F9               [12] 1412 	mov	r1,a
      000CBA E3               [24] 1413 	movx	a,@r1
      000CBB FC               [12] 1414 	mov	r4,a
      000CBC 8C F0            [24] 1415 	mov	b,r4
      000CBE 05 F0            [12] 1416 	inc	b
      000CC0 80 0D            [24] 1417 	sjmp	00212$
      000CC2                       1418 00211$:
      000CC2 C3               [12] 1419 	clr	c
      000CC3 EF               [12] 1420 	mov	a,r7
      000CC4 13               [12] 1421 	rrc	a
      000CC5 FF               [12] 1422 	mov	r7,a
      000CC6 EE               [12] 1423 	mov	a,r6
      000CC7 13               [12] 1424 	rrc	a
      000CC8 FE               [12] 1425 	mov	r6,a
      000CC9 ED               [12] 1426 	mov	a,r5
      000CCA 13               [12] 1427 	rrc	a
      000CCB FD               [12] 1428 	mov	r5,a
      000CCC EA               [12] 1429 	mov	a,r2
      000CCD 13               [12] 1430 	rrc	a
      000CCE FA               [12] 1431 	mov	r2,a
      000CCF                       1432 00212$:
      000CCF D5 F0 F0         [24] 1433 	djnz	b,00211$
      000CD2 78 5C            [12] 1434 	mov	r0,#___pca_isr_width_65536_44
      000CD4 EA               [12] 1435 	mov	a,r2
      000CD5 F2               [24] 1436 	movx	@r0,a
      000CD6 08               [12] 1437 	inc	r0
      000CD7 ED               [12] 1438 	mov	a,r5
      000CD8 F2               [24] 1439 	movx	@r0,a
      000CD9 08               [12] 1440 	inc	r0
      000CDA EE               [12] 1441 	mov	a,r6
      000CDB F2               [24] 1442 	movx	@r0,a
      000CDC 08               [12] 1443 	inc	r0
      000CDD EF               [12] 1444 	mov	a,r7
      000CDE F2               [24] 1445 	movx	@r0,a
                                   1446 ;	pca-hal.c:554: duration = width.fields.cnt ? 0xffff : ((uint16_t) width.count);
      000CDF 78 5E            [12] 1447 	mov	r0,#(___pca_isr_width_65536_44 + 0x0002)
      000CE1 E2               [24] 1448 	movx	a,@r0
      000CE2 60 06            [24] 1449 	jz	00127$
      000CE4 7E FF            [12] 1450 	mov	r6,#0xff
      000CE6 7F FF            [12] 1451 	mov	r7,#0xff
      000CE8 80 11            [24] 1452 	sjmp	00128$
      000CEA                       1453 00127$:
      000CEA 78 5C            [12] 1454 	mov	r0,#___pca_isr_width_65536_44
      000CEC E2               [24] 1455 	movx	a,@r0
      000CED FA               [12] 1456 	mov	r2,a
      000CEE 08               [12] 1457 	inc	r0
      000CEF E2               [24] 1458 	movx	a,@r0
      000CF0 FB               [12] 1459 	mov	r3,a
      000CF1 08               [12] 1460 	inc	r0
      000CF2 E2               [24] 1461 	movx	a,@r0
      000CF3 FC               [12] 1462 	mov	r4,a
      000CF4 08               [12] 1463 	inc	r0
      000CF5 E2               [24] 1464 	movx	a,@r0
      000CF6 FD               [12] 1465 	mov	r5,a
      000CF7 8A 0E            [24] 1466 	mov	ar6,r2
      000CF9 8B 0F            [24] 1467 	mov	ar7,r3
      000CFB                       1468 00128$:
                                   1469 ;	pca-hal.c:556: pcaOnInterrupt(channel, duration);
      000CFB 78 C7            [12] 1470 	mov	r0,#_pcaOnInterrupt_PARM_2
      000CFD EE               [12] 1471 	mov	a,r6
      000CFE F2               [24] 1472 	movx	@r0,a
      000CFF EF               [12] 1473 	mov	a,r7
      000D00 08               [12] 1474 	inc	r0
      000D01 F2               [24] 1475 	movx	@r0,a
      000D02 78 5B            [12] 1476 	mov	r0,#___pca_isr_channel_65536_44
      000D04 E2               [24] 1477 	movx	a,@r0
      000D05 F5 82            [12] 1478 	mov	dpl,a
      000D07 12 13 EB         [24] 1479 	lcall	_pcaOnInterrupt
                                   1480 ;	pca-hal.c:557: break;
                                   1481 ;	pca-hal.c:560: case PCA_TIMER:
      000D0A 80 0E            [24] 1482 	sjmp	00125$
      000D0C                       1483 00121$:
                                   1484 ;	pca-hal.c:561: pcaOnInterrupt(channel, duration);
      000D0C 78 C7            [12] 1485 	mov	r0,#_pcaOnInterrupt_PARM_2
      000D0E E4               [12] 1486 	clr	a
      000D0F F2               [24] 1487 	movx	@r0,a
      000D10 08               [12] 1488 	inc	r0
      000D11 F2               [24] 1489 	movx	@r0,a
      000D12 78 5B            [12] 1490 	mov	r0,#___pca_isr_channel_65536_44
      000D14 E2               [24] 1491 	movx	a,@r0
      000D15 F5 82            [12] 1492 	mov	dpl,a
      000D17 12 13 EB         [24] 1493 	lcall	_pcaOnInterrupt
                                   1494 ;	pca-hal.c:563: }
      000D1A                       1495 00125$:
                                   1496 ;	pca-hal.c:565: }
      000D1A D0 D0            [24] 1497 	pop	psw
      000D1C D0 83            [24] 1498 	pop	dph
      000D1E D0 82            [24] 1499 	pop	dpl
      000D20 D0 F0            [24] 1500 	pop	b
      000D22 D0 E0            [24] 1501 	pop	acc
      000D24 D0 21            [24] 1502 	pop	bits
      000D26 D2 AF            [12] 1503 	setb	ea
      000D28 32               [24] 1504 	reti
                                   1505 	.area CSEG    (CODE)
                                   1506 	.area CONST   (CODE)
                                   1507 	.area XINIT   (CODE)
                                   1508 	.area CABS    (ABS,CODE)
