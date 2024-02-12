glabel romMakeFreeCache
/* 06A498 8006FA38 7C0802A6 */  mflr    r0
/* 06A49C 8006FA3C 2C050000 */  cmpwi   r5, 0
/* 06A4A0 8006FA40 90010004 */  stw     r0, 4(r1)
/* 06A4A4 8006FA44 9421FFD0 */  stwu    r1, -0x30(r1)
/* 06A4A8 8006FA48 93E1002C */  stw     r31, 0x2c(r1)
/* 06A4AC 8006FA4C 3BE40000 */  addi    r31, r4, 0
/* 06A4B0 8006FA50 93C10028 */  stw     r30, 0x28(r1)
/* 06A4B4 8006FA54 3BC30000 */  addi    r30, r3, 0
/* 06A4B8 8006FA58 4082010C */  bne     lbl_8006FB64
/* 06A4BC 8006FA5C 387E0000 */  addi    r3, r30, 0
/* 06A4C0 8006FA60 38810020 */  addi    r4, r1, 0x20
/* 06A4C4 8006FA64 38A00000 */  li      r5, 0
/* 06A4C8 8006FA68 48000395 */  bl      romFindFreeCache
/* 06A4CC 8006FA6C 2C030000 */  cmpwi   r3, 0
/* 06A4D0 8006FA70 408201B8 */  bne     lbl_8006FC28
/* 06A4D4 8006FA74 387E0000 */  addi    r3, r30, 0
/* 06A4D8 8006FA78 3881001C */  addi    r4, r1, 0x1c
/* 06A4DC 8006FA7C 38A00000 */  li      r5, 0
/* 06A4E0 8006FA80 38C00002 */  li      r6, 2
/* 06A4E4 8006FA84 480001C9 */  bl      romFindOldestBlock
/* 06A4E8 8006FA88 2C030000 */  cmpwi   r3, 0
/* 06A4EC 8006FA8C 418200D0 */  beq     lbl_8006FB5C
/* 06A4F0 8006FA90 8081001C */  lwz     r4, 0x1c(r1)
/* 06A4F4 8006FA94 387E0000 */  addi    r3, r30, 0
/* 06A4F8 8006FA98 38A00001 */  li      r5, 1
/* 06A4FC 8006FA9C 54802036 */  slwi    r0, r4, 4
/* 06A500 8006FAA0 7CDE0214 */  add     r6, r30, r0
/* 06A504 8006FAA4 8006021C */  lwz     r0, 0x21c(r6)
/* 06A508 8006FAA8 90010020 */  stw     r0, 0x20(r1)
/* 06A50C 8006FAAC 4BFFFD35 */  bl      romSetBlockCache
/* 06A510 8006FAB0 2C030000 */  cmpwi   r3, 0
/* 06A514 8006FAB4 40820174 */  bne     lbl_8006FC28
/* 06A518 8006FAB8 387E0000 */  addi    r3, r30, 0
/* 06A51C 8006FABC 3881001C */  addi    r4, r1, 0x1c
/* 06A520 8006FAC0 38A00000 */  li      r5, 0
/* 06A524 8006FAC4 38C00000 */  li      r6, 0
/* 06A528 8006FAC8 48000185 */  bl      romFindOldestBlock
/* 06A52C 8006FACC 2C030000 */  cmpwi   r3, 0
/* 06A530 8006FAD0 41820158 */  beq     lbl_8006FC28
/* 06A534 8006FAD4 8001001C */  lwz     r0, 0x1c(r1)
/* 06A538 8006FAD8 54042036 */  slwi    r4, r0, 4
/* 06A53C 8006FADC 7C7E2214 */  add     r3, r30, r4
/* 06A540 8006FAE0 8003021C */  lwz     r0, 0x21c(r3)
/* 06A544 8006FAE4 38C4021C */  addi    r6, r4, 0x21c
/* 06A548 8006FAE8 7CDE3214 */  add     r6, r30, r6
/* 06A54C 8006FAEC 90010020 */  stw     r0, 0x20(r1)
/* 06A550 8006FAF0 80860000 */  lwz     r4, 0(r6)
/* 06A554 8006FAF4 2C040000 */  cmpwi   r4, 0
/* 06A558 8006FAF8 40800034 */  bge     lbl_8006FB2C
/* 06A55C 8006FAFC 38040001 */  addi    r0, r4, 1
/* 06A560 8006FB00 7C8000D0 */  neg     r4, r0
/* 06A564 8006FB04 3C7E0001 */  addis   r3, r30, 1
/* 06A568 8006FB08 7C801E70 */  srawi   r0, r4, 3
/* 06A56C 8006FB0C 7CA30214 */  add     r5, r3, r0
/* 06A570 8006FB10 5480077E */  clrlwi  r0, r4, 0x1d
/* 06A574 8006FB14 88850624 */  lbz     r4, 0x624(r5)
/* 06A578 8006FB18 38600001 */  li      r3, 1
/* 06A57C 8006FB1C 7C600030 */  slw     r0, r3, r0
/* 06A580 8006FB20 7C800078 */  andc    r0, r4, r0
/* 06A584 8006FB24 98050624 */  stb     r0, 0x624(r5)
/* 06A588 8006FB28 48000028 */  b       lbl_8006FB50
lbl_8006FB2C:
/* 06A58C 8006FB2C 3C7E0001 */  addis   r3, r30, 1
/* 06A590 8006FB30 7C801E70 */  srawi   r0, r4, 3
/* 06A594 8006FB34 7CA30214 */  add     r5, r3, r0
/* 06A598 8006FB38 5480077E */  clrlwi  r0, r4, 0x1d
/* 06A59C 8006FB3C 88850224 */  lbz     r4, 0x224(r5)
/* 06A5A0 8006FB40 38600001 */  li      r3, 1
/* 06A5A4 8006FB44 7C600030 */  slw     r0, r3, r0
/* 06A5A8 8006FB48 7C800078 */  andc    r0, r4, r0
/* 06A5AC 8006FB4C 98050224 */  stb     r0, 0x224(r5)
lbl_8006FB50:
/* 06A5B0 8006FB50 38000000 */  li      r0, 0
/* 06A5B4 8006FB54 90060004 */  stw     r0, 4(r6)
/* 06A5B8 8006FB58 480000D0 */  b       lbl_8006FC28
lbl_8006FB5C:
/* 06A5BC 8006FB5C 38600000 */  li      r3, 0
/* 06A5C0 8006FB60 480000D4 */  b       lbl_8006FC34
lbl_8006FB64:
/* 06A5C4 8006FB64 387E0000 */  addi    r3, r30, 0
/* 06A5C8 8006FB68 38810020 */  addi    r4, r1, 0x20
/* 06A5CC 8006FB6C 38A00001 */  li      r5, 1
/* 06A5D0 8006FB70 4800028D */  bl      romFindFreeCache
/* 06A5D4 8006FB74 2C030000 */  cmpwi   r3, 0
/* 06A5D8 8006FB78 408200B0 */  bne     lbl_8006FC28
/* 06A5DC 8006FB7C 387E0000 */  addi    r3, r30, 0
/* 06A5E0 8006FB80 3881001C */  addi    r4, r1, 0x1c
/* 06A5E4 8006FB84 38A00001 */  li      r5, 1
/* 06A5E8 8006FB88 38C00000 */  li      r6, 0
/* 06A5EC 8006FB8C 480000C1 */  bl      romFindOldestBlock
/* 06A5F0 8006FB90 2C030000 */  cmpwi   r3, 0
/* 06A5F4 8006FB94 4182008C */  beq     lbl_8006FC20
/* 06A5F8 8006FB98 8001001C */  lwz     r0, 0x1c(r1)
/* 06A5FC 8006FB9C 54042036 */  slwi    r4, r0, 4
/* 06A600 8006FBA0 7C7E2214 */  add     r3, r30, r4
/* 06A604 8006FBA4 8003021C */  lwz     r0, 0x21c(r3)
/* 06A608 8006FBA8 38C4021C */  addi    r6, r4, 0x21c
/* 06A60C 8006FBAC 7CDE3214 */  add     r6, r30, r6
/* 06A610 8006FBB0 90010020 */  stw     r0, 0x20(r1)
/* 06A614 8006FBB4 80860000 */  lwz     r4, 0(r6)
/* 06A618 8006FBB8 2C040000 */  cmpwi   r4, 0
/* 06A61C 8006FBBC 40800034 */  bge     lbl_8006FBF0
/* 06A620 8006FBC0 38040001 */  addi    r0, r4, 1
/* 06A624 8006FBC4 7C8000D0 */  neg     r4, r0
/* 06A628 8006FBC8 3C7E0001 */  addis   r3, r30, 1
/* 06A62C 8006FBCC 7C801E70 */  srawi   r0, r4, 3
/* 06A630 8006FBD0 7CA30214 */  add     r5, r3, r0
/* 06A634 8006FBD4 5480077E */  clrlwi  r0, r4, 0x1d
/* 06A638 8006FBD8 88850624 */  lbz     r4, 0x624(r5)
/* 06A63C 8006FBDC 38600001 */  li      r3, 1
/* 06A640 8006FBE0 7C600030 */  slw     r0, r3, r0
/* 06A644 8006FBE4 7C800078 */  andc    r0, r4, r0
/* 06A648 8006FBE8 98050624 */  stb     r0, 0x624(r5)
/* 06A64C 8006FBEC 48000028 */  b       lbl_8006FC14
lbl_8006FBF0:
/* 06A650 8006FBF0 3C7E0001 */  addis   r3, r30, 1
/* 06A654 8006FBF4 7C801E70 */  srawi   r0, r4, 3
/* 06A658 8006FBF8 7CA30214 */  add     r5, r3, r0
/* 06A65C 8006FBFC 5480077E */  clrlwi  r0, r4, 0x1d
/* 06A660 8006FC00 88850224 */  lbz     r4, 0x224(r5)
/* 06A664 8006FC04 38600001 */  li      r3, 1
/* 06A668 8006FC08 7C600030 */  slw     r0, r3, r0
/* 06A66C 8006FC0C 7C800078 */  andc    r0, r4, r0
/* 06A670 8006FC10 98050224 */  stb     r0, 0x224(r5)
lbl_8006FC14:
/* 06A674 8006FC14 38000000 */  li      r0, 0
/* 06A678 8006FC18 90060004 */  stw     r0, 4(r6)
/* 06A67C 8006FC1C 4800000C */  b       lbl_8006FC28
lbl_8006FC20:
/* 06A680 8006FC20 38600000 */  li      r3, 0
/* 06A684 8006FC24 48000010 */  b       lbl_8006FC34
lbl_8006FC28:
/* 06A688 8006FC28 80010020 */  lwz     r0, 0x20(r1)
/* 06A68C 8006FC2C 38600001 */  li      r3, 1
/* 06A690 8006FC30 901F0000 */  stw     r0, 0(r31)
lbl_8006FC34:
/* 06A694 8006FC34 80010034 */  lwz     r0, 0x34(r1)
/* 06A698 8006FC38 83E1002C */  lwz     r31, 0x2c(r1)
/* 06A69C 8006FC3C 83C10028 */  lwz     r30, 0x28(r1)
/* 06A6A0 8006FC40 7C0803A6 */  mtlr    r0
/* 06A6A4 8006FC44 38210030 */  addi    r1, r1, 0x30
/* 06A6A8 8006FC48 4E800020 */  blr     
