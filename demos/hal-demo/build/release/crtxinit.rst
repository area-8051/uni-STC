                                      1 ;--------------------------------------------------------------------------
                                      2 ;  crtxinit.asm :- C run-time: copy XINIT to XISEG
                                      3 ;
                                      4 ;  Copyright (C) 2004, Erik Petrich
                                      5 ;
                                      6 ;  This library is free software; you can redistribute it and/or modify it
                                      7 ;  under the terms of the GNU General Public License as published by the
                                      8 ;  Free Software Foundation; either version 2, or (at your option) any
                                      9 ;  later version.
                                     10 ;
                                     11 ;  This library is distributed in the hope that it will be useful,
                                     12 ;  but WITHOUT ANY WARRANTY; without even the implied warranty of
                                     13 ;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
                                     14 ;  GNU General Public License for more details.
                                     15 ;
                                     16 ;  You should have received a copy of the GNU General Public License 
                                     17 ;  along with this library; see the file COPYING. If not, write to the
                                     18 ;  Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
                                     19 ;   MA 02110-1301, USA.
                                     20 ;
                                     21 ;  As a special exception, if you link this library with other files,
                                     22 ;  some of which are compiled with SDCC, to produce an executable,
                                     23 ;  this library does not by itself cause the resulting executable to
                                     24 ;  be covered by the GNU General Public License. This exception does
                                     25 ;  not however invalidate any other reasons why the executable file
                                     26 ;  might be covered by the GNU General Public License.
                                     27 ;--------------------------------------------------------------------------
                                     28 
                                     29 ; Set DUAL_DPTR to 1 and reassemble if your derivative has dual data pointers
                                     30 ; Especially useful if movx @Ri cannot go beyond the first 256 bytes of xdata
                                     31 ; due to lack of P2 or _XPAGE
                                     32 ; If the derivative has auto-toggle or auto-increment it can be further optimized
                           000001    33 	DUAL_DPTR = 1
                                     34 
                                     35 	.area CSEG    (CODE)
                                     36 	.area GSINIT0 (CODE)
                                     37 	.area GSINIT1 (CODE)
                                     38 	.area GSINIT2 (CODE)
                                     39 	.area GSINIT3 (CODE)
                                     40 	.area GSINIT4 (CODE)
                                     41 	.area GSINIT5 (CODE)
                                     42 	.area GSINIT  (CODE)
                                     43 	.area GSFINAL (CODE)
                                     44 
                                     45 	.area GSINIT3 (CODE)
                                     46 
                           000001    47 	.if DUAL_DPTR
                                     48 
                                     49 	.globl _DPS			; assume DPSEL is in DPS bit0
                                     50 
      000056                         51 __mcs51_genXINIT::
      000056 79 00            [12]   52 	mov	r1,#l_XINIT
      000058 E9               [12]   53 	mov	a,r1
      000059 44 00            [12]   54 	orl	a,#(l_XINIT >> 8)
      00005B 60 1A            [24]   55 	jz	00003$
      00005D 7A 00            [12]   56 	mov	r2,#((l_XINIT+255) >> 8)
      00005F 43 A2 01         [24]   57 	orl	_DPS,#0x01		; set DPSEL, select DPTR1
      000062 90 16 21         [24]   58 	mov	dptr,#s_XINIT		; DPTR1 for code
      000065 15 A2            [12]   59 	dec	_DPS			; clear DPSEL, select DPTR0
      000067 90 00 D2         [24]   60 	mov	dptr,#s_XISEG		; DPTR0 for xdata
      00006A E4               [12]   61 00001$:	clr	a
      00006B 05 A2            [12]   62 	inc	_DPS			; set DPSEL, select DPTR1
      00006D 93               [24]   63 	movc	a,@a+dptr
      00006E A3               [24]   64 	inc	dptr
      00006F 15 A2            [12]   65 	dec	_DPS			; clear DPSEL, select DPTR0
      000071 F0               [24]   66 	movx	@dptr,a
      000072 A3               [24]   67 	inc	dptr
      000073 D9 F5            [24]   68 	djnz	r1,00001$
      000075 DA F3            [24]   69 	djnz	r2,00001$
      000077                         70 00003$:
                                     71 
                           000000    72 	.else
                                     73 
                                     74 	.globl __XPAGE
                                     75 
                                     76 __mcs51_genXINIT::
                                     77 	mov	r1,#l_XINIT
                                     78 	mov	a,r1
                                     79 	orl	a,#(l_XINIT >> 8)
                                     80 	jz	00003$
                                     81 	mov	r2,#((l_XINIT+255) >> 8)
                                     82 	mov	dptr,#s_XINIT
                                     83 	mov	r0,#s_XISEG
                                     84 	mov	__XPAGE,#(s_XISEG >> 8)
                                     85 00001$:	clr	a
                                     86 	movc	a,@a+dptr
                                     87 	movx	@r0,a
                                     88 	inc	dptr
                                     89 	inc	r0
                                     90 	cjne	r0,#0,00002$
                                     91 	inc	__XPAGE
                                     92 00002$:	djnz	r1,00001$
                                     93 	djnz	r2,00001$
                                     94 	mov	__XPAGE,#0xFF
                                     95 00003$:
                                     96 
                                     97 	.endif
