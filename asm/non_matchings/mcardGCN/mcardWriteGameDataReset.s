glabel mcardWriteGameDataReset
/* 0140D0 80019670 7C0802A6 */  mflr    r0
/* 0140D4 80019674 90010004 */  stw     r0, 4(r1)
/* 0140D8 80019678 9421FFE8 */  stwu    r1, -0x18(r1)
/* 0140DC 8001967C 93E10014 */  stw     r31, 0x14(r1)
/* 0140E0 80019680 93C10010 */  stw     r30, 0x10(r1)
/* 0140E4 80019684 7C7E1B78 */  mr      r30, r3
/* 0140E8 80019688 80030470 */  lwz     r0, 0x470(r3)
/* 0140EC 8001968C 2C000001 */  cmpwi   r0, 1
/* 0140F0 80019690 4082002C */  bne     lbl_800196BC
/* 0140F4 80019694 3C608010 */  lis     r3, mCard@ha
/* 0140F8 80019698 3BE379B0 */  addi    r31, r3, mCard@l
/* 0140FC 8001969C 48000014 */  b       lbl_800196B0
lbl_800196A0:
/* 014100 800196A0 809E0038 */  lwz     r4, 0x38(r30)
/* 014104 800196A4 387E0000 */  addi    r3, r30, 0
/* 014108 800196A8 38846000 */  addi    r4, r4, 0x6000
/* 01410C 800196AC 48000931 */  bl      mcardWriteBufferAsynch
lbl_800196B0:
/* 014110 800196B0 801F047C */  lwz     r0, 0x47c(r31)
/* 014114 800196B4 2C000000 */  cmpwi   r0, 0
/* 014118 800196B8 4182FFE8 */  beq     lbl_800196A0
lbl_800196BC:
/* 01411C 800196BC 8001001C */  lwz     r0, 0x1c(r1)
/* 014120 800196C0 38600001 */  li      r3, 1
/* 014124 800196C4 83E10014 */  lwz     r31, 0x14(r1)
/* 014128 800196C8 83C10010 */  lwz     r30, 0x10(r1)
/* 01412C 800196CC 7C0803A6 */  mtlr    r0
/* 014130 800196D0 38210018 */  addi    r1, r1, 0x18
/* 014134 800196D4 4E800020 */  blr     