glabel frameDrawRectFill
/* 0214FC 80026A9C 7C0802A6 */  mflr    r0
/* 021500 80026AA0 90010004 */  stw     r0, 4(r1)
/* 021504 80026AA4 9421FFA0 */  stwu    r1, -0x60(r1)
/* 021508 80026AA8 DBE10058 */  stfd    f31, 0x58(r1)
/* 02150C 80026AAC DBC10050 */  stfd    f30, 0x50(r1)
/* 021510 80026AB0 DBA10048 */  stfd    f29, 0x48(r1)
/* 021514 80026AB4 DB810040 */  stfd    f28, 0x40(r1)
/* 021518 80026AB8 DB610038 */  stfd    f27, 0x38(r1)
/* 02151C 80026ABC 93E10034 */  stw     r31, 0x34(r1)
/* 021520 80026AC0 800300A4 */  lwz     r0, 0xa4(r3)
/* 021524 80026AC4 54050296 */  rlwinm  r5, r0, 0, 0xa, 0xb
/* 021528 80026AC8 3C05FFD0 */  addis   r0, r5, 0xffd0
/* 02152C 80026ACC 28000000 */  cmplwi  r0, 0
/* 021530 80026AD0 408200D0 */  bne     lbl_80026BA0
/* 021534 80026AD4 80040008 */  lwz     r0, 8(r4)
/* 021538 80026AD8 2C000010 */  cmpwi   r0, 0x10
/* 02153C 80026ADC 418100C4 */  bgt     lbl_80026BA0
/* 021540 80026AE0 8004000C */  lwz     r0, 0xc(r4)
/* 021544 80026AE4 2C000020 */  cmpwi   r0, 0x20
/* 021548 80026AE8 418100B8 */  bgt     lbl_80026BA0
/* 02154C 80026AEC 80040010 */  lwz     r0, 0x10(r4)
/* 021550 80026AF0 2C000130 */  cmpwi   r0, 0x130
/* 021554 80026AF4 418000AC */  blt     lbl_80026BA0
/* 021558 80026AF8 80040014 */  lwz     r0, 0x14(r4)
/* 02155C 80026AFC 2C0000D0 */  cmpwi   r0, 0xd0
/* 021560 80026B00 418000A0 */  blt     lbl_80026BA0
/* 021564 80026B04 3CC30004 */  addis   r6, r3, 4
/* 021568 80026B08 88E6D128 */  lbz     r7, -0x2ed8(r6)
/* 02156C 80026B0C 39000000 */  li      r8, 0
/* 021570 80026B10 280700FF */  cmplwi  r7, 0xff
/* 021574 80026B14 4082002C */  bne     lbl_80026B40
/* 021578 80026B18 8806D129 */  lbz     r0, -0x2ed7(r6)
/* 02157C 80026B1C 280000FC */  cmplwi  r0, 0xfc
/* 021580 80026B20 40820020 */  bne     lbl_80026B40
/* 021584 80026B24 8806D12A */  lbz     r0, -0x2ed6(r6)
/* 021588 80026B28 280000FF */  cmplwi  r0, 0xff
/* 02158C 80026B2C 40820014 */  bne     lbl_80026B40
/* 021590 80026B30 8806D12B */  lbz     r0, -0x2ed5(r6)
/* 021594 80026B34 280000FC */  cmplwi  r0, 0xfc
/* 021598 80026B38 40820008 */  bne     lbl_80026B40
/* 02159C 80026B3C 39000001 */  li      r8, 1
lbl_80026B40:
/* 0215A0 80026B40 280700F8 */  cmplwi  r7, 0xf8
/* 0215A4 80026B44 40820030 */  bne     lbl_80026B74
/* 0215A8 80026B48 3CC30004 */  addis   r6, r3, 4
/* 0215AC 80026B4C 8806D129 */  lbz     r0, -0x2ed7(r6)
/* 0215B0 80026B50 280000F8 */  cmplwi  r0, 0xf8
/* 0215B4 80026B54 40820020 */  bne     lbl_80026B74
/* 0215B8 80026B58 8806D12A */  lbz     r0, -0x2ed6(r6)
/* 0215BC 80026B5C 280000F0 */  cmplwi  r0, 0xf0
/* 0215C0 80026B60 40820014 */  bne     lbl_80026B74
/* 0215C4 80026B64 8806D12B */  lbz     r0, -0x2ed5(r6)
/* 0215C8 80026B68 28000000 */  cmplwi  r0, 0
/* 0215CC 80026B6C 40820008 */  bne     lbl_80026B74
/* 0215D0 80026B70 39000001 */  li      r8, 1
lbl_80026B74:
/* 0215D4 80026B74 2C080000 */  cmpwi   r8, 0
/* 0215D8 80026B78 41820028 */  beq     lbl_80026BA0
/* 0215DC 80026B7C 8003008C */  lwz     r0, 0x8c(r3)
/* 0215E0 80026B80 540002D6 */  rlwinm  r0, r0, 0, 0xb, 0xb
/* 0215E4 80026B84 28000000 */  cmplwi  r0, 0
/* 0215E8 80026B88 40820018 */  bne     lbl_80026BA0
/* 0215EC 80026B8C 8003008C */  lwz     r0, 0x8c(r3)
/* 0215F0 80026B90 64000010 */  oris    r0, r0, 0x10
/* 0215F4 80026B94 9003008C */  stw     r0, 0x8c(r3)
/* 0215F8 80026B98 38600001 */  li      r3, 1
/* 0215FC 80026B9C 4800016C */  b       lbl_80026D08
lbl_80026BA0:
/* 021600 80026BA0 81240008 */  lwz     r9, 8(r4)
/* 021604 80026BA4 3C05FFD0 */  addis   r0, r5, 0xffd0
/* 021608 80026BA8 80E40010 */  lwz     r7, 0x10(r4)
/* 02160C 80026BAC 3D004330 */  lis     r8, 0x4330
/* 021610 80026BB0 80C4000C */  lwz     r6, 0xc(r4)
/* 021614 80026BB4 80840014 */  lwz     r4, 0x14(r4)
/* 021618 80026BB8 6D298000 */  xoris   r9, r9, 0x8000
/* 02161C 80026BBC 6CE78000 */  xoris   r7, r7, 0x8000
/* 021620 80026BC0 9121002C */  stw     r9, 0x2c(r1)
/* 021624 80026BC4 6CC68000 */  xoris   r6, r6, 0x8000
/* 021628 80026BC8 6C848000 */  xoris   r4, r4, 0x8000
/* 02162C 80026BCC 90E10024 */  stw     r7, 0x24(r1)
/* 021630 80026BD0 C8428110 */  lfd     f2, D_80135E10@sda21(r2)
/* 021634 80026BD4 28000000 */  cmplwi  r0, 0
/* 021638 80026BD8 90C1001C */  stw     r6, 0x1c(r1)
/* 02163C 80026BDC 90810014 */  stw     r4, 0x14(r1)
/* 021640 80026BE0 91010028 */  stw     r8, 0x28(r1)
/* 021644 80026BE4 91010020 */  stw     r8, 0x20(r1)
/* 021648 80026BE8 C8210028 */  lfd     f1, 0x28(r1)
/* 02164C 80026BEC 91010018 */  stw     r8, 0x18(r1)
/* 021650 80026BF0 C8010020 */  lfd     f0, 0x20(r1)
/* 021654 80026BF4 EFC11028 */  fsubs   f30, f1, f2
/* 021658 80026BF8 91010010 */  stw     r8, 0x10(r1)
/* 02165C 80026BFC C8210018 */  lfd     f1, 0x18(r1)
/* 021660 80026C00 EF801028 */  fsubs   f28, f0, f2
/* 021664 80026C04 C8010010 */  lfd     f0, 0x10(r1)
/* 021668 80026C08 EFA11028 */  fsubs   f29, f1, f2
/* 02166C 80026C0C EF601028 */  fsubs   f27, f0, f2
/* 021670 80026C10 41820010 */  beq     lbl_80026C20
/* 021674 80026C14 3C05FFE0 */  addis   r0, r5, 0xffe0
/* 021678 80026C18 28000000 */  cmplwi  r0, 0
/* 02167C 80026C1C 40820010 */  bne     lbl_80026C2C
lbl_80026C20:
/* 021680 80026C20 C0028138 */  lfs     f0, D_80135E38@sda21(r2)
/* 021684 80026C24 EF9C002A */  fadds   f28, f28, f0
/* 021688 80026C28 EF7B002A */  fadds   f27, f27, f0
lbl_80026C2C:
/* 02168C 80026C2C 800300A0 */  lwz     r0, 0xa0(r3)
/* 021690 80026C30 5400077A */  rlwinm  r0, r0, 0, 0x1d, 0x1d
/* 021694 80026C34 28000004 */  cmplwi  r0, 4
/* 021698 80026C38 4082000C */  bne     lbl_80026C44
/* 02169C 80026C3C C3E30124 */  lfs     f31, 0x124(r3)
/* 0216A0 80026C40 48000008 */  b       lbl_80026C48
lbl_80026C44:
/* 0216A4 80026C44 C3E28100 */  lfs     f31, D_80135E00@sda21(r2)
lbl_80026C48:
/* 0216A8 80026C48 3FE30004 */  addis   r31, r3, 4
/* 0216AC 80026C4C 801FD138 */  lwz     r0, -0x2ec8(r31)
/* 0216B0 80026C50 2800000B */  cmplwi  r0, 0xb
/* 0216B4 80026C54 41820058 */  beq     lbl_80026CAC
/* 0216B8 80026C58 48083591 */  bl      GXClearVtxDesc
/* 0216BC 80026C5C 38600009 */  li      r3, 9
/* 0216C0 80026C60 38800001 */  li      r4, 1
/* 0216C4 80026C64 48083139 */  bl      GXSetVtxDesc
/* 0216C8 80026C68 3860000B */  li      r3, 0xb
/* 0216CC 80026C6C 38800001 */  li      r4, 1
/* 0216D0 80026C70 4808312D */  bl      GXSetVtxDesc
/* 0216D4 80026C74 38600000 */  li      r3, 0
/* 0216D8 80026C78 38800009 */  li      r4, 9
/* 0216DC 80026C7C 38A00001 */  li      r5, 1
/* 0216E0 80026C80 38C00004 */  li      r6, 4
/* 0216E4 80026C84 38E00000 */  li      r7, 0
/* 0216E8 80026C88 48083599 */  bl      GXSetVtxAttrFmt
/* 0216EC 80026C8C 38600000 */  li      r3, 0
/* 0216F0 80026C90 3880000B */  li      r4, 0xb
/* 0216F4 80026C94 38A00001 */  li      r5, 1
/* 0216F8 80026C98 38C00005 */  li      r6, 5
/* 0216FC 80026C9C 38E00000 */  li      r7, 0
/* 021700 80026CA0 48083581 */  bl      GXSetVtxAttrFmt
/* 021704 80026CA4 3800000B */  li      r0, 0xb
/* 021708 80026CA8 901FD138 */  stw     r0, -0x2ec8(r31)
lbl_80026CAC:
/* 02170C 80026CAC 38600080 */  li      r3, 0x80
/* 021710 80026CB0 38800000 */  li      r4, 0
/* 021714 80026CB4 38A00004 */  li      r5, 4
/* 021718 80026CB8 480847A9 */  bl      GXBegin
/* 02171C 80026CBC 3C80CC01 */  lis     r4, 0xcc01
/* 021720 80026CC0 D3C48000 */  stfs    f30, -0x8000(r4)
/* 021724 80026CC4 38000000 */  li      r0, 0
/* 021728 80026CC8 38600001 */  li      r3, 1
/* 02172C 80026CCC D3A48000 */  stfs    f29, -0x8000(r4)
/* 021730 80026CD0 D3E48000 */  stfs    f31, -0x8000(r4)
/* 021734 80026CD4 90048000 */  stw     r0, -0x8000(r4)
/* 021738 80026CD8 D3848000 */  stfs    f28, -0x8000(r4)
/* 02173C 80026CDC D3A48000 */  stfs    f29, -0x8000(r4)
/* 021740 80026CE0 D3E48000 */  stfs    f31, -0x8000(r4)
/* 021744 80026CE4 90048000 */  stw     r0, -0x8000(r4)
/* 021748 80026CE8 D3848000 */  stfs    f28, -0x8000(r4)
/* 02174C 80026CEC D3648000 */  stfs    f27, -0x8000(r4)
/* 021750 80026CF0 D3E48000 */  stfs    f31, -0x8000(r4)
/* 021754 80026CF4 90048000 */  stw     r0, -0x8000(r4)
/* 021758 80026CF8 D3C48000 */  stfs    f30, -0x8000(r4)
/* 02175C 80026CFC D3648000 */  stfs    f27, -0x8000(r4)
/* 021760 80026D00 D3E48000 */  stfs    f31, -0x8000(r4)
/* 021764 80026D04 90048000 */  stw     r0, -0x8000(r4)
lbl_80026D08:
/* 021768 80026D08 80010064 */  lwz     r0, 0x64(r1)
/* 02176C 80026D0C CBE10058 */  lfd     f31, 0x58(r1)
/* 021770 80026D10 CBC10050 */  lfd     f30, 0x50(r1)
/* 021774 80026D14 7C0803A6 */  mtlr    r0
/* 021778 80026D18 CBA10048 */  lfd     f29, 0x48(r1)
/* 02177C 80026D1C CB810040 */  lfd     f28, 0x40(r1)
/* 021780 80026D20 CB610038 */  lfd     f27, 0x38(r1)
/* 021784 80026D24 83E10034 */  lwz     r31, 0x34(r1)
/* 021788 80026D28 38210060 */  addi    r1, r1, 0x60
/* 02178C 80026D2C 4E800020 */  blr     
