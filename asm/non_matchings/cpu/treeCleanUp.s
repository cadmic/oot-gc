glabel treeCleanUp
/* 02C07C 8003161C 7C0802A6 */  mflr    r0
/* 02C080 80031620 90010004 */  stw     r0, 4(r1)
/* 02C084 80031624 9421FFD8 */  stwu    r1, -0x28(r1)
/* 02C088 80031628 93E10024 */  stw     r31, 0x24(r1)
/* 02C08C 8003162C 7C9F2378 */  mr      r31, r4
/* 02C090 80031630 93C10020 */  stw     r30, 0x20(r1)
/* 02C094 80031634 3BC00000 */  li      r30, 0
/* 02C098 80031638 93A1001C */  stw     r29, 0x1c(r1)
/* 02C09C 8003163C 3BA30000 */  addi    r29, r3, 0
/* 02C0A0 80031640 38600000 */  li      r3, 0
/* 02C0A4 80031644 80040078 */  lwz     r0, 0x78(r4)
/* 02C0A8 80031648 2C000000 */  cmpwi   r0, 0
/* 02C0AC 8003164C 40820010 */  bne     lbl_8003165C
/* 02C0B0 80031650 7FA3EB78 */  mr      r3, r29
/* 02C0B4 80031654 809F0068 */  lwz     r4, 0x68(r31)
/* 02C0B8 80031658 4BFFFCE5 */  bl      treeCleanNodes
lbl_8003165C:
/* 02C0BC 8003165C 801F0078 */  lwz     r0, 0x78(r31)
/* 02C0C0 80031660 2C000000 */  cmpwi   r0, 0
/* 02C0C4 80031664 4082000C */  bne     lbl_80031670
/* 02C0C8 80031668 2C030000 */  cmpwi   r3, 0
/* 02C0CC 8003166C 4182001C */  beq     lbl_80031688
lbl_80031670:
/* 02C0D0 80031670 7FA3EB78 */  mr      r3, r29
/* 02C0D4 80031674 809F006C */  lwz     r4, 0x6c(r31)
/* 02C0D8 80031678 4BFFFCC5 */  bl      treeCleanNodes
/* 02C0DC 8003167C 2C030000 */  cmpwi   r3, 0
/* 02C0E0 80031680 41820008 */  beq     lbl_80031688
/* 02C0E4 80031684 3BC00001 */  li      r30, 1
lbl_80031688:
/* 02C0E8 80031688 2C1E0000 */  cmpwi   r30, 0
/* 02C0EC 8003168C 4082000C */  bne     lbl_80031698
/* 02C0F0 80031690 38600000 */  li      r3, 0
/* 02C0F4 80031694 4800009C */  b       lbl_80031730
lbl_80031698:
/* 02C0F8 80031698 3C7D0001 */  addis   r3, r29, 1
/* 02C0FC 8003169C 808312A0 */  lwz     r4, 0x12a0(r3)
/* 02C100 800316A0 28040000 */  cmplwi  r4, 0
/* 02C104 800316A4 4082000C */  bne     lbl_800316B0
/* 02C108 800316A8 38600000 */  li      r3, 0
/* 02C10C 800316AC 48000008 */  b       lbl_800316B4
lbl_800316B0:
/* 02C110 800316B0 80640004 */  lwz     r3, 4(r4)
lbl_800316B4:
/* 02C114 800316B4 3C000040 */  lis     r0, 0x40
/* 02C118 800316B8 7C030000 */  cmpw    r3, r0
/* 02C11C 800316BC 40810014 */  ble     lbl_800316D0
/* 02C120 800316C0 807D003C */  lwz     r3, 0x3c(r29)
/* 02C124 800316C4 3803FFF6 */  addi    r0, r3, -10
/* 02C128 800316C8 901F0070 */  stw     r0, 0x70(r31)
/* 02C12C 800316CC 48000060 */  b       lbl_8003172C
lbl_800316D0:
/* 02C130 800316D0 28040000 */  cmplwi  r4, 0
/* 02C134 800316D4 4082000C */  bne     lbl_800316E0
/* 02C138 800316D8 38800000 */  li      r4, 0
/* 02C13C 800316DC 48000008 */  b       lbl_800316E4
lbl_800316E0:
/* 02C140 800316E0 80840004 */  lwz     r4, 4(r4)
lbl_800316E4:
/* 02C144 800316E4 3C600032 */  lis     r3, 0x32
/* 02C148 800316E8 38039750 */  addi    r0, r3, -26800
/* 02C14C 800316EC 7C040000 */  cmpw    r4, r0
/* 02C150 800316F0 4081002C */  ble     lbl_8003171C
/* 02C154 800316F4 807F0070 */  lwz     r3, 0x70(r31)
/* 02C158 800316F8 3803005F */  addi    r0, r3, 0x5f
/* 02C15C 800316FC 901F0070 */  stw     r0, 0x70(r31)
/* 02C160 80031700 807D003C */  lwz     r3, 0x3c(r29)
/* 02C164 80031704 801F0070 */  lwz     r0, 0x70(r31)
/* 02C168 80031708 3863FFF6 */  addi    r3, r3, -10
/* 02C16C 8003170C 7C001800 */  cmpw    r0, r3
/* 02C170 80031710 4081001C */  ble     lbl_8003172C
/* 02C174 80031714 907F0070 */  stw     r3, 0x70(r31)
/* 02C178 80031718 48000014 */  b       lbl_8003172C
lbl_8003171C:
/* 02C17C 8003171C 38000000 */  li      r0, 0
/* 02C180 80031720 901F0070 */  stw     r0, 0x70(r31)
/* 02C184 80031724 901F007C */  stw     r0, 0x7c(r31)
/* 02C188 80031728 901F0080 */  stw     r0, 0x80(r31)
lbl_8003172C:
/* 02C18C 8003172C 38600001 */  li      r3, 1
lbl_80031730:
/* 02C190 80031730 8001002C */  lwz     r0, 0x2c(r1)
/* 02C194 80031734 83E10024 */  lwz     r31, 0x24(r1)
/* 02C198 80031738 83C10020 */  lwz     r30, 0x20(r1)
/* 02C19C 8003173C 7C0803A6 */  mtlr    r0
/* 02C1A0 80031740 83A1001C */  lwz     r29, 0x1c(r1)
/* 02C1A4 80031744 38210028 */  addi    r1, r1, 0x28
/* 02C1A8 80031748 4E800020 */  blr     