glabel romTestCode
/* 068B40 8006E0E0 9421FFD8 */  stwu    r1, -0x28(r1)
/* 068B44 8006E0E4 3CA30001 */  addis   r5, r3, 1
/* 068B48 8006E0E8 38000000 */  li      r0, 0
/* 068B4C 8006E0EC 88650EAB */  lbz     r3, 0xeab(r5)
/* 068B50 8006E0F0 38C1001C */  addi    r6, r1, 0x1c
/* 068B54 8006E0F4 9861001C */  stb     r3, 0x1c(r1)
/* 068B58 8006E0F8 88650EAC */  lbz     r3, 0xeac(r5)
/* 068B5C 8006E0FC 9861001D */  stb     r3, 0x1d(r1)
/* 068B60 8006E100 88650EAD */  lbz     r3, 0xead(r5)
/* 068B64 8006E104 9861001E */  stb     r3, 0x1e(r1)
/* 068B68 8006E108 88650EAE */  lbz     r3, 0xeae(r5)
/* 068B6C 8006E10C 9861001F */  stb     r3, 0x1f(r1)
/* 068B70 8006E110 98010020 */  stb     r0, 0x20(r1)
/* 068B74 8006E114 88A1001C */  lbz     r5, 0x1c(r1)
/* 068B78 8006E118 88040000 */  lbz     r0, 0(r4)
/* 068B7C 8006E11C 7CA50774 */  extsb   r5, r5
/* 068B80 8006E120 7C000774 */  extsb   r0, r0
/* 068B84 8006E124 7C050000 */  cmpw    r5, r0
/* 068B88 8006E128 4182000C */  beq     lbl_8006E134
/* 068B8C 8006E12C 38600000 */  li      r3, 0
/* 068B90 8006E130 4800006C */  b       lbl_8006E19C
lbl_8006E134:
/* 068B94 8006E134 8CA60001 */  lbzu    r5, 1(r6)
/* 068B98 8006E138 38640001 */  addi    r3, r4, 1
/* 068B9C 8006E13C 88040001 */  lbz     r0, 1(r4)
/* 068BA0 8006E140 7CA50774 */  extsb   r5, r5
/* 068BA4 8006E144 7C000774 */  extsb   r0, r0
/* 068BA8 8006E148 7C050000 */  cmpw    r5, r0
/* 068BAC 8006E14C 4182000C */  beq     lbl_8006E158
/* 068BB0 8006E150 38600000 */  li      r3, 0
/* 068BB4 8006E154 48000048 */  b       lbl_8006E19C
lbl_8006E158:
/* 068BB8 8006E158 8CA60001 */  lbzu    r5, 1(r6)
/* 068BBC 8006E15C 8C030001 */  lbzu    r0, 1(r3)
/* 068BC0 8006E160 7CA50774 */  extsb   r5, r5
/* 068BC4 8006E164 7C000774 */  extsb   r0, r0
/* 068BC8 8006E168 7C050000 */  cmpw    r5, r0
/* 068BCC 8006E16C 4182000C */  beq     lbl_8006E178
/* 068BD0 8006E170 38600000 */  li      r3, 0
/* 068BD4 8006E174 48000028 */  b       lbl_8006E19C
lbl_8006E178:
/* 068BD8 8006E178 88A60001 */  lbz     r5, 1(r6)
/* 068BDC 8006E17C 88030001 */  lbz     r0, 1(r3)
/* 068BE0 8006E180 7CA50774 */  extsb   r5, r5
/* 068BE4 8006E184 7C000774 */  extsb   r0, r0
/* 068BE8 8006E188 7C050000 */  cmpw    r5, r0
/* 068BEC 8006E18C 4182000C */  beq     lbl_8006E198
/* 068BF0 8006E190 38600000 */  li      r3, 0
/* 068BF4 8006E194 48000008 */  b       lbl_8006E19C
lbl_8006E198:
/* 068BF8 8006E198 38600001 */  li      r3, 1
lbl_8006E19C:
/* 068BFC 8006E19C 38210028 */  addi    r1, r1, 0x28
/* 068C00 8006E1A0 4E800020 */  blr     
