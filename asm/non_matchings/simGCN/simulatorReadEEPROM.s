glabel simulatorReadEEPROM
/* 0039AC 80008F4C 7C0802A6 */  mflr    r0
/* 0039B0 80008F50 90010004 */  stw     r0, 4(r1)
/* 0039B4 80008F54 9421FFE0 */  stwu    r1, -0x20(r1)
/* 0039B8 80008F58 93E1001C */  stw     r31, 0x1c(r1)
/* 0039BC 80008F5C 3BE40000 */  addi    r31, r4, 0
/* 0039C0 80008F60 38810010 */  addi    r4, r1, 0x10
/* 0039C4 80008F64 93C10018 */  stw     r30, 0x18(r1)
/* 0039C8 80008F68 3BC30000 */  addi    r30, r3, 0
/* 0039CC 80008F6C 80AD8920 */  lwz     r5, gpSystem@sda21(r13)
/* 0039D0 80008F70 80650028 */  lwz     r3, 0x28(r5)
/* 0039D4 80008F74 48063961 */  bl      pifGetEEPROMSize
/* 0039D8 80008F78 2C030000 */  cmpwi   r3, 0
/* 0039DC 80008F7C 4082000C */  bne     lbl_80008F88
/* 0039E0 80008F80 38600000 */  li      r3, 0
/* 0039E4 80008F84 48000020 */  b       lbl_80008FA4
lbl_80008F88:
/* 0039E8 80008F88 3C608010 */  lis     r3, mCard@ha
/* 0039EC 80008F8C 386379B0 */  addi    r3, r3, mCard@l
/* 0039F0 80008F90 38DF0000 */  addi    r6, r31, 0
/* 0039F4 80008F94 57C41D78 */  rlwinm  r4, r30, 3, 0x15, 0x1c
/* 0039F8 80008F98 38A00008 */  li      r5, 8
/* 0039FC 80008F9C 4800E879 */  bl      mcardRead
/* 003A00 80008FA0 38600001 */  li      r3, 1
lbl_80008FA4:
/* 003A04 80008FA4 80010024 */  lwz     r0, 0x24(r1)
/* 003A08 80008FA8 83E1001C */  lwz     r31, 0x1c(r1)
/* 003A0C 80008FAC 83C10018 */  lwz     r30, 0x18(r1)
/* 003A10 80008FB0 7C0803A6 */  mtlr    r0
/* 003A14 80008FB4 38210020 */  addi    r1, r1, 0x20
/* 003A18 80008FB8 4E800020 */  blr     
