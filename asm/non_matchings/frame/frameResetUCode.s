glabel frameResetUCode
/* 018290 8001D830 3CA30004 */  addis   r5, r3, 4
/* 018294 8001D834 38000000 */  li      r0, 0
/* 018298 8001D838 9005C4CC */  stw     r0, -0x3b34(r5)
/* 01829C 8001D83C 8003008C */  lwz     r0, 0x8c(r3)
/* 0182A0 8001D840 74009C1F */  andis.  r0, r0, 0x9c1f
/* 0182A4 8001D844 2C040000 */  cmpwi   r4, 0
/* 0182A8 8001D848 9003008C */  stw     r0, 0x8c(r3)
/* 0182AC 8001D84C 40820018 */  bne     lbl_8001D864
/* 0182B0 8001D850 8083008C */  lwz     r4, 0x8c(r3)
/* 0182B4 8001D854 3800FFFF */  li      r0, -1
/* 0182B8 8001D858 54840184 */  rlwinm  r4, r4, 0, 6, 2
/* 0182BC 8001D85C 9083008C */  stw     r4, 0x8c(r3)
/* 0182C0 8001D860 9005C4D0 */  stw     r0, -0x3b30(r5)
lbl_8001D864:
/* 0182C4 8001D864 48000004 */  b       lbl_8001D868
lbl_8001D868:
/* 0182C8 8001D868 38800000 */  li      r4, 0
/* 0182CC 8001D86C 48000004 */  b       lbl_8001D870
lbl_8001D870:
/* 0182D0 8001D870 90830090 */  stw     r4, 0x90(r3)
/* 0182D4 8001D874 38C00008 */  li      r6, 8
/* 0182D8 8001D878 90830094 */  stw     r4, 0x94(r3)
/* 0182DC 8001D87C 90830098 */  stw     r4, 0x98(r3)
/* 0182E0 8001D880 9083009C */  stw     r4, 0x9c(r3)
/* 0182E4 8001D884 908300A0 */  stw     r4, 0xa0(r3)
/* 0182E8 8001D888 908300A4 */  stw     r4, 0xa4(r3)
/* 0182EC 8001D88C 908300A8 */  stw     r4, 0xa8(r3)
/* 0182F0 8001D890 908300AC */  stw     r4, 0xac(r3)
/* 0182F4 8001D894 4800003C */  b       lbl_8001D8D0
lbl_8001D898:
/* 0182F8 8001D898 2006000A */  subfic  r0, r6, 0xa
/* 0182FC 8001D89C 2C06000A */  cmpwi   r6, 0xa
/* 018300 8001D8A0 7C0903A6 */  mtctr   r0
/* 018304 8001D8A4 40800014 */  bge     lbl_8001D8B8
/* 018308 8001D8A8 48000004 */  b       lbl_8001D8AC
lbl_8001D8AC:
/* 01830C 8001D8AC 90850090 */  stw     r4, 0x90(r5)
/* 018310 8001D8B0 38A50004 */  addi    r5, r5, 4
/* 018314 8001D8B4 4200FFF8 */  bdnz    lbl_8001D8AC
lbl_8001D8B8:
/* 018318 8001D8B8 3800FFFF */  li      r0, -1
/* 01831C 8001D8BC 90030120 */  stw     r0, 0x120(r3)
/* 018320 8001D8C0 38000000 */  li      r0, 0
/* 018324 8001D8C4 9003013C */  stw     r0, 0x13c(r3)
/* 018328 8001D8C8 38600001 */  li      r3, 1
/* 01832C 8001D8CC 48000010 */  b       lbl_8001D8DC
lbl_8001D8D0:
/* 018330 8001D8D0 54C0103A */  slwi    r0, r6, 2
/* 018334 8001D8D4 7CA30214 */  add     r5, r3, r0
/* 018338 8001D8D8 4BFFFFC0 */  b       lbl_8001D898
lbl_8001D8DC:
/* 01833C 8001D8DC 4E800020 */  blr     