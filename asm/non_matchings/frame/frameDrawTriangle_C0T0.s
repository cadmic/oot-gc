glabel frameDrawTriangle_C0T0
/* 023B78 80029118 7C0802A6 */  mflr    r0
/* 023B7C 8002911C 90010004 */  stw     r0, 4(r1)
/* 023B80 80029120 9421FFD0 */  stwu    r1, -0x30(r1)
/* 023B84 80029124 93E1002C */  stw     r31, 0x2c(r1)
/* 023B88 80029128 93C10028 */  stw     r30, 0x28(r1)
/* 023B8C 8002912C 93A10024 */  stw     r29, 0x24(r1)
/* 023B90 80029130 7C7E1B78 */  mr      r30, r3
/* 023B94 80029134 7C9F2378 */  mr      r31, r4
/* 023B98 80029138 3FBE0004 */  addis   r29, r30, 4
/* 023B9C 8002913C 801DD138 */  lwz     r0, -0x2ec8(r29)
/* 023BA0 80029140 28000011 */  cmplwi  r0, 0x11
/* 023BA4 80029144 41820034 */  beq     lbl_80029178
/* 023BA8 80029148 480810A1 */  bl      GXClearVtxDesc
/* 023BAC 8002914C 38600009 */  li      r3, 9
/* 023BB0 80029150 38800001 */  li      r4, 1
/* 023BB4 80029154 48080C49 */  bl      GXSetVtxDesc
/* 023BB8 80029158 38600000 */  li      r3, 0
/* 023BBC 8002915C 38800009 */  li      r4, 9
/* 023BC0 80029160 38A00001 */  li      r5, 1
/* 023BC4 80029164 38C00004 */  li      r6, 4
/* 023BC8 80029168 38E00000 */  li      r7, 0
/* 023BCC 8002916C 480810B5 */  bl      GXSetVtxAttrFmt
/* 023BD0 80029170 38000011 */  li      r0, 0x11
/* 023BD4 80029174 901DD138 */  stw     r0, -0x2ec8(r29)
lbl_80029178:
/* 023BD8 80029178 801F0000 */  lwz     r0, 0(r31)
/* 023BDC 8002917C 38600090 */  li      r3, 0x90
/* 023BE0 80029180 38800000 */  li      r4, 0
/* 023BE4 80029184 5405043E */  clrlwi  r5, r0, 0x10
/* 023BE8 80029188 480822D9 */  bl      GXBegin
/* 023BEC 8002918C 38FF0004 */  addi    r7, r31, 4
/* 023BF0 80029190 38C00000 */  li      r6, 0
/* 023BF4 80029194 48000004 */  b       lbl_80029198
lbl_80029198:
/* 023BF8 80029198 3C80CC01 */  lis     r4, 0xcc01
/* 023BFC 8002919C 48000004 */  b       lbl_800291A0
lbl_800291A0:
/* 023C00 800291A0 48000084 */  b       lbl_80029224
lbl_800291A4:
/* 023C04 800291A4 7CA73214 */  add     r5, r7, r6
/* 023C08 800291A8 88050000 */  lbz     r0, 0(r5)
/* 023C0C 800291AC 38C60003 */  addi    r6, r6, 3
/* 023C10 800291B0 1C60001C */  mulli   r3, r0, 0x1c
/* 023C14 800291B4 38630358 */  addi    r3, r3, 0x358
/* 023C18 800291B8 7C7E1A14 */  add     r3, r30, r3
/* 023C1C 800291BC C0430014 */  lfs     f2, 0x14(r3)
/* 023C20 800291C0 C0230010 */  lfs     f1, 0x10(r3)
/* 023C24 800291C4 C003000C */  lfs     f0, 0xc(r3)
/* 023C28 800291C8 D0048000 */  stfs    f0, -0x8000(r4)
/* 023C2C 800291CC D0248000 */  stfs    f1, -0x8000(r4)
/* 023C30 800291D0 D0448000 */  stfs    f2, -0x8000(r4)
/* 023C34 800291D4 88050001 */  lbz     r0, 1(r5)
/* 023C38 800291D8 1C60001C */  mulli   r3, r0, 0x1c
/* 023C3C 800291DC 38630358 */  addi    r3, r3, 0x358
/* 023C40 800291E0 7C7E1A14 */  add     r3, r30, r3
/* 023C44 800291E4 C0430014 */  lfs     f2, 0x14(r3)
/* 023C48 800291E8 C0230010 */  lfs     f1, 0x10(r3)
/* 023C4C 800291EC C003000C */  lfs     f0, 0xc(r3)
/* 023C50 800291F0 D0048000 */  stfs    f0, -0x8000(r4)
/* 023C54 800291F4 D0248000 */  stfs    f1, -0x8000(r4)
/* 023C58 800291F8 D0448000 */  stfs    f2, -0x8000(r4)
/* 023C5C 800291FC 88050002 */  lbz     r0, 2(r5)
/* 023C60 80029200 1C60001C */  mulli   r3, r0, 0x1c
/* 023C64 80029204 38630358 */  addi    r3, r3, 0x358
/* 023C68 80029208 7C7E1A14 */  add     r3, r30, r3
/* 023C6C 8002920C C0430014 */  lfs     f2, 0x14(r3)
/* 023C70 80029210 C0230010 */  lfs     f1, 0x10(r3)
/* 023C74 80029214 C003000C */  lfs     f0, 0xc(r3)
/* 023C78 80029218 D0048000 */  stfs    f0, -0x8000(r4)
/* 023C7C 8002921C D0248000 */  stfs    f1, -0x8000(r4)
/* 023C80 80029220 D0448000 */  stfs    f2, -0x8000(r4)
lbl_80029224:
/* 023C84 80029224 801F0000 */  lwz     r0, 0(r31)
/* 023C88 80029228 7C060000 */  cmpw    r6, r0
/* 023C8C 8002922C 4180FF78 */  blt     lbl_800291A4
/* 023C90 80029230 38600001 */  li      r3, 1
/* 023C94 80029234 80010034 */  lwz     r0, 0x34(r1)
/* 023C98 80029238 83E1002C */  lwz     r31, 0x2c(r1)
/* 023C9C 8002923C 83C10028 */  lwz     r30, 0x28(r1)
/* 023CA0 80029240 7C0803A6 */  mtlr    r0
/* 023CA4 80029244 83A10024 */  lwz     r29, 0x24(r1)
/* 023CA8 80029248 38210030 */  addi    r1, r1, 0x30
/* 023CAC 8002924C 4E800020 */  blr     
