glabel frameDrawLine_C1T0
/* 022024 800275C4 7C0802A6 */  mflr    r0
/* 022028 800275C8 90010004 */  stw     r0, 4(r1)
/* 02202C 800275CC 9421FFC8 */  stwu    r1, -0x38(r1)
/* 022030 800275D0 93E10034 */  stw     r31, 0x34(r1)
/* 022034 800275D4 93C10030 */  stw     r30, 0x30(r1)
/* 022038 800275D8 93A1002C */  stw     r29, 0x2c(r1)
/* 02203C 800275DC 93810028 */  stw     r28, 0x28(r1)
/* 022040 800275E0 7C7D1B78 */  mr      r29, r3
/* 022044 800275E4 7C9E2378 */  mr      r30, r4
/* 022048 800275E8 807D0120 */  lwz     r3, 0x120(r29)
/* 02204C 800275EC 3BFE0004 */  addi    r31, r30, 4
/* 022050 800275F0 881E0006 */  lbz     r0, 6(r30)
/* 022054 800275F4 7C030000 */  cmpw    r3, r0
/* 022058 800275F8 41820038 */  beq     lbl_80027630
/* 02205C 800275FC 881F0002 */  lbz     r0, 2(r31)
/* 022060 80027600 38800000 */  li      r4, 0
/* 022064 80027604 901D0120 */  stw     r0, 0x120(r29)
/* 022068 80027608 C03D0080 */  lfs     f1, 0x80(r29)
/* 02206C 8002760C C0028130 */  lfs     f0, D_80135E30@sda21(r2)
/* 022070 80027610 881F0002 */  lbz     r0, 2(r31)
/* 022074 80027614 EC010032 */  fmuls   f0, f1, f0
/* 022078 80027618 1C000003 */  mulli   r0, r0, 3
/* 02207C 8002761C FC00001E */  fctiwz  f0, f0
/* 022080 80027620 D8010020 */  stfd    f0, 0x20(r1)
/* 022084 80027624 80610024 */  lwz     r3, 0x24(r1)
/* 022088 80027628 7C6301D6 */  mullw   r3, r3, r0
/* 02208C 8002762C 48083F8D */  bl      GXSetLineWidth
lbl_80027630:
/* 022090 80027630 3F9D0004 */  addis   r28, r29, 4
/* 022094 80027634 801CD138 */  lwz     r0, -0x2ec8(r28)
/* 022098 80027638 28000023 */  cmplwi  r0, 0x23
/* 02209C 8002763C 41820058 */  beq     lbl_80027694
/* 0220A0 80027640 48082BA9 */  bl      GXClearVtxDesc
/* 0220A4 80027644 38600009 */  li      r3, 9
/* 0220A8 80027648 38800001 */  li      r4, 1
/* 0220AC 8002764C 48082751 */  bl      GXSetVtxDesc
/* 0220B0 80027650 3860000B */  li      r3, 0xb
/* 0220B4 80027654 38800001 */  li      r4, 1
/* 0220B8 80027658 48082745 */  bl      GXSetVtxDesc
/* 0220BC 8002765C 38600000 */  li      r3, 0
/* 0220C0 80027660 38800009 */  li      r4, 9
/* 0220C4 80027664 38A00001 */  li      r5, 1
/* 0220C8 80027668 38C00004 */  li      r6, 4
/* 0220CC 8002766C 38E00000 */  li      r7, 0
/* 0220D0 80027670 48082BB1 */  bl      GXSetVtxAttrFmt
/* 0220D4 80027674 38600000 */  li      r3, 0
/* 0220D8 80027678 3880000B */  li      r4, 0xb
/* 0220DC 8002767C 38A00001 */  li      r5, 1
/* 0220E0 80027680 38C00005 */  li      r6, 5
/* 0220E4 80027684 38E00000 */  li      r7, 0
/* 0220E8 80027688 48082B99 */  bl      GXSetVtxAttrFmt
/* 0220EC 8002768C 38000023 */  li      r0, 0x23
/* 0220F0 80027690 901CD138 */  stw     r0, -0x2ec8(r28)
lbl_80027694:
/* 0220F4 80027694 801E0000 */  lwz     r0, 0(r30)
/* 0220F8 80027698 3C605555 */  lis     r3, 0x5555
/* 0220FC 8002769C 38635556 */  addi    r3, r3, 0x5556
/* 022100 800276A0 5400083C */  slwi    r0, r0, 1
/* 022104 800276A4 7C630096 */  mulhw   r3, r3, r0
/* 022108 800276A8 54600FFE */  srwi    r0, r3, 0x1f
/* 02210C 800276AC 7C030214 */  add     r0, r3, r0
/* 022110 800276B0 5405043E */  clrlwi  r5, r0, 0x10
/* 022114 800276B4 386000A8 */  li      r3, 0xa8
/* 022118 800276B8 38800000 */  li      r4, 0
/* 02211C 800276BC 48083DA5 */  bl      GXBegin
/* 022120 800276C0 39400000 */  li      r10, 0
/* 022124 800276C4 48000004 */  b       lbl_800276C8
lbl_800276C8:
/* 022128 800276C8 3CA0CC01 */  lis     r5, 0xcc01
/* 02212C 800276CC 48000004 */  b       lbl_800276D0
lbl_800276D0:
/* 022130 800276D0 4800008C */  b       lbl_8002775C
lbl_800276D4:
/* 022134 800276D4 7D3F5214 */  add     r9, r31, r10
/* 022138 800276D8 88090000 */  lbz     r0, 0(r9)
/* 02213C 800276DC 394A0003 */  addi    r10, r10, 3
/* 022140 800276E0 1C60001C */  mulli   r3, r0, 0x1c
/* 022144 800276E4 38630358 */  addi    r3, r3, 0x358
/* 022148 800276E8 7C7D1A14 */  add     r3, r29, r3
/* 02214C 800276EC C0430014 */  lfs     f2, 0x14(r3)
/* 022150 800276F0 C0230010 */  lfs     f1, 0x10(r3)
/* 022154 800276F4 C003000C */  lfs     f0, 0xc(r3)
/* 022158 800276F8 D0058000 */  stfs    f0, -0x8000(r5)
/* 02215C 800276FC D0258000 */  stfs    f1, -0x8000(r5)
/* 022160 80027700 D0458000 */  stfs    f2, -0x8000(r5)
/* 022164 80027704 8903001B */  lbz     r8, 0x1b(r3)
/* 022168 80027708 88E3001A */  lbz     r7, 0x1a(r3)
/* 02216C 8002770C 88C30019 */  lbz     r6, 0x19(r3)
/* 022170 80027710 88830018 */  lbz     r4, 0x18(r3)
/* 022174 80027714 98858000 */  stb     r4, -0x8000(r5)
/* 022178 80027718 98C58000 */  stb     r6, -0x8000(r5)
/* 02217C 8002771C 98E58000 */  stb     r7, -0x8000(r5)
/* 022180 80027720 99058000 */  stb     r8, -0x8000(r5)
/* 022184 80027724 88090001 */  lbz     r0, 1(r9)
/* 022188 80027728 1C60001C */  mulli   r3, r0, 0x1c
/* 02218C 8002772C 38630358 */  addi    r3, r3, 0x358
/* 022190 80027730 7C7D1A14 */  add     r3, r29, r3
/* 022194 80027734 C0430014 */  lfs     f2, 0x14(r3)
/* 022198 80027738 C0230010 */  lfs     f1, 0x10(r3)
/* 02219C 8002773C C003000C */  lfs     f0, 0xc(r3)
/* 0221A0 80027740 D0058000 */  stfs    f0, -0x8000(r5)
/* 0221A4 80027744 D0258000 */  stfs    f1, -0x8000(r5)
/* 0221A8 80027748 D0458000 */  stfs    f2, -0x8000(r5)
/* 0221AC 8002774C 98858000 */  stb     r4, -0x8000(r5)
/* 0221B0 80027750 98C58000 */  stb     r6, -0x8000(r5)
/* 0221B4 80027754 98E58000 */  stb     r7, -0x8000(r5)
/* 0221B8 80027758 99058000 */  stb     r8, -0x8000(r5)
lbl_8002775C:
/* 0221BC 8002775C 801E0000 */  lwz     r0, 0(r30)
/* 0221C0 80027760 7C0A0000 */  cmpw    r10, r0
/* 0221C4 80027764 4180FF70 */  blt     lbl_800276D4
/* 0221C8 80027768 38600001 */  li      r3, 1
/* 0221CC 8002776C 8001003C */  lwz     r0, 0x3c(r1)
/* 0221D0 80027770 83E10034 */  lwz     r31, 0x34(r1)
/* 0221D4 80027774 83C10030 */  lwz     r30, 0x30(r1)
/* 0221D8 80027778 7C0803A6 */  mtlr    r0
/* 0221DC 8002777C 83A1002C */  lwz     r29, 0x2c(r1)
/* 0221E0 80027780 83810028 */  lwz     r28, 0x28(r1)
/* 0221E4 80027784 38210038 */  addi    r1, r1, 0x38
/* 0221E8 80027788 4E800020 */  blr     
