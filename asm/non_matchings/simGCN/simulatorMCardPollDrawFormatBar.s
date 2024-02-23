glabel simulatorMCardPollDrawFormatBar
/* 003344 800088E4 7C0802A6 */  mflr    r0
/* 003348 800088E8 3C608010 */  lis     r3, mCard@ha
/* 00334C 800088EC 90010004 */  stw     r0, 4(r1)
/* 003350 800088F0 3C80800F */  lis     r4, gOrthoMtx@ha
/* 003354 800088F4 9421FFD8 */  stwu    r1, -0x28(r1)
/* 003358 800088F8 DBE10020 */  stfd    f31, 0x20(r1)
/* 00335C 800088FC 93E1001C */  stw     r31, 0x1c(r1)
/* 003360 80008900 3BE379B0 */  addi    r31, r3, mCard@l
/* 003364 80008904 93C10018 */  stw     r30, 0x18(r1)
/* 003368 80008908 3BC44540 */  addi    r30, r4, gOrthoMtx@l
/* 00336C 8000890C 807F0360 */  lwz     r3, 0x360(r31)
/* 003370 80008910 480B4C11 */  bl      CARDGetXferredBytes
/* 003374 80008914 80BF0368 */  lwz     r5, 0x368(r31)
/* 003378 80008918 3C804330 */  lis     r4, 0x4330
/* 00337C 8000891C 801F036C */  lwz     r0, 0x36c(r31)
/* 003380 80008920 7C651850 */  subf    r3, r5, r3
/* 003384 80008924 C8428038 */  lfd     f2, D_80135D38@sda21(r2)
/* 003388 80008928 6C638000 */  xoris   r3, r3, 0x8000
/* 00338C 8000892C C0628028 */  lfs     f3, D_80135D28@sda21(r2)
/* 003390 80008930 6C008000 */  xoris   r0, r0, 0x8000
/* 003394 80008934 90610014 */  stw     r3, 0x14(r1)
/* 003398 80008938 9001000C */  stw     r0, 0xc(r1)
/* 00339C 8000893C 90810010 */  stw     r4, 0x10(r1)
/* 0033A0 80008940 90810008 */  stw     r4, 8(r1)
/* 0033A4 80008944 C8210010 */  lfd     f1, 0x10(r1)
/* 0033A8 80008948 C8010008 */  lfd     f0, 8(r1)
/* 0033AC 8000894C EC211028 */  fsubs   f1, f1, f2
/* 0033B0 80008950 EC001028 */  fsubs   f0, f0, f2
/* 0033B4 80008954 EC010024 */  fdivs   f0, f1, f0
/* 0033B8 80008958 FC001840 */  fcmpo   cr0, f0, f3
/* 0033BC 8000895C 40810008 */  ble     lbl_80008964
/* 0033C0 80008960 48000008 */  b       lbl_80008968
lbl_80008964:
/* 0033C4 80008964 FC600090 */  fmr     f3, f0
lbl_80008968:
/* 0033C8 80008968 C3E28024 */  lfs     f31, D_80135D24@sda21(r2)
/* 0033CC 8000896C FC03F840 */  fcmpo   cr0, f3, f31
/* 0033D0 80008970 40800008 */  bge     lbl_80008978
/* 0033D4 80008974 48000008 */  b       lbl_8000897C
lbl_80008978:
/* 0033D8 80008978 FFE01890 */  fmr     f31, f3
lbl_8000897C:
/* 0033DC 8000897C 801E01A0 */  lwz     r0, 0x1a0(r30)
/* 0033E0 80008980 2C000000 */  cmpwi   r0, 0
/* 0033E4 80008984 40820028 */  bne     lbl_800089AC
/* 0033E8 80008988 3C60800F */  lis     r3, D_800E9CDC@ha
/* 0033EC 8000898C 4CC63182 */  crclr   6
/* 0033F0 80008990 3C80800F */  lis     r4, D_800E9D08@ha
/* 0033F4 80008994 38639CDC */  addi    r3, r3, D_800E9CDC@l
/* 0033F8 80008998 38849D08 */  addi    r4, r4, D_800E9D08@l
/* 0033FC 8000899C 38A00657 */  li      r5, 0x657
/* 003400 800089A0 4BFFD475 */  bl      xlPostText
/* 003404 800089A4 3860002A */  li      r3, 0x2a
/* 003408 800089A8 48004849 */  bl      simulatorPrepareMessage
lbl_800089AC:
/* 00340C 800089AC 809E01A8 */  lwz     r4, 0x1a8(r30)
/* 003410 800089B0 387E01A0 */  addi    r3, r30, 0x1a0
/* 003414 800089B4 C0028030 */  lfs     f0, D_80135D30@sda21(r2)
/* 003418 800089B8 38C00000 */  li      r6, 0
/* 00341C 800089BC 80A40000 */  lwz     r5, 0(r4)
/* 003420 800089C0 EC0007F2 */  fmuls   f0, f0, f31
/* 003424 800089C4 A0850002 */  lhz     r4, 2(r5)
/* 003428 800089C8 A0050000 */  lhz     r0, 0(r5)
/* 00342C 800089CC FC00001E */  fctiwz  f0, f0
/* 003430 800089D0 7C840E70 */  srawi   r4, r4, 1
/* 003434 800089D4 7C840194 */  addze   r4, r4
/* 003438 800089D8 208400A0 */  subfic  r4, r4, 0xa0
/* 00343C 800089DC D8010008 */  stfd    f0, 8(r1)
/* 003440 800089E0 7C000E70 */  srawi   r0, r0, 1
/* 003444 800089E4 7C000194 */  addze   r0, r0
/* 003448 800089E8 80E1000C */  lwz     r7, 0xc(r1)
/* 00344C 800089EC 20A00078 */  subfic  r5, r0, 0x78
/* 003450 800089F0 48005A95 */  bl      simulatorDrawImage
/* 003454 800089F4 8001002C */  lwz     r0, 0x2c(r1)
/* 003458 800089F8 38600001 */  li      r3, 1
/* 00345C 800089FC CBE10020 */  lfd     f31, 0x20(r1)
/* 003460 80008A00 83E1001C */  lwz     r31, 0x1c(r1)
/* 003464 80008A04 7C0803A6 */  mtlr    r0
/* 003468 80008A08 83C10018 */  lwz     r30, 0x18(r1)
/* 00346C 80008A0C 38210028 */  addi    r1, r1, 0x28
/* 003470 80008A10 4E800020 */  blr     