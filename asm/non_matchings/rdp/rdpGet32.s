glabel rdpGet32
/* 06ABD0 80070170 548006FE */  clrlwi  r0, r4, 0x1b
/* 06ABD4 80070174 2800001C */  cmplwi  r0, 0x1c
/* 06ABD8 80070178 4181008C */  bgt     lbl_80070204
/* 06ABDC 8007017C 3C80800F */  lis     r4, jtbl_800EDFC4@ha
/* 06ABE0 80070180 3884DFC4 */  addi    r4, r4, jtbl_800EDFC4@l
/* 06ABE4 80070184 5400103A */  slwi    r0, r0, 2
/* 06ABE8 80070188 7C04002E */  lwzx    r0, r4, r0
/* 06ABEC 8007018C 7C0903A6 */  mtctr   r0
/* 06ABF0 80070190 4E800420 */  bctr    
.global lbl_80070194
lbl_80070194:
/* 06ABF4 80070194 80030018 */  lwz     r0, 0x18(r3)
/* 06ABF8 80070198 90050000 */  stw     r0, 0(r5)
/* 06ABFC 8007019C 48000070 */  b       lbl_8007020C
.global lbl_800701A0
lbl_800701A0:
/* 06AC00 800701A0 8003001C */  lwz     r0, 0x1c(r3)
/* 06AC04 800701A4 90050000 */  stw     r0, 0(r5)
/* 06AC08 800701A8 48000064 */  b       lbl_8007020C
.global lbl_800701AC
lbl_800701AC:
/* 06AC0C 800701AC 8003001C */  lwz     r0, 0x1c(r3)
/* 06AC10 800701B0 90050000 */  stw     r0, 0(r5)
/* 06AC14 800701B4 48000058 */  b       lbl_8007020C
.global lbl_800701B8
lbl_800701B8:
/* 06AC18 800701B8 80030004 */  lwz     r0, 4(r3)
/* 06AC1C 800701BC 90050000 */  stw     r0, 0(r5)
/* 06AC20 800701C0 4800004C */  b       lbl_8007020C
.global lbl_800701C4
lbl_800701C4:
/* 06AC24 800701C4 80030020 */  lwz     r0, 0x20(r3)
/* 06AC28 800701C8 5400023E */  clrlwi  r0, r0, 8
/* 06AC2C 800701CC 90050000 */  stw     r0, 0(r5)
/* 06AC30 800701D0 4800003C */  b       lbl_8007020C
.global lbl_800701D4
lbl_800701D4:
/* 06AC34 800701D4 80030024 */  lwz     r0, 0x24(r3)
/* 06AC38 800701D8 5400023E */  clrlwi  r0, r0, 8
/* 06AC3C 800701DC 90050000 */  stw     r0, 0(r5)
/* 06AC40 800701E0 4800002C */  b       lbl_8007020C
.global lbl_800701E4
lbl_800701E4:
/* 06AC44 800701E4 80030028 */  lwz     r0, 0x28(r3)
/* 06AC48 800701E8 5400023E */  clrlwi  r0, r0, 8
/* 06AC4C 800701EC 90050000 */  stw     r0, 0(r5)
/* 06AC50 800701F0 4800001C */  b       lbl_8007020C
.global lbl_800701F4
lbl_800701F4:
/* 06AC54 800701F4 8003002C */  lwz     r0, 0x2c(r3)
/* 06AC58 800701F8 5400023E */  clrlwi  r0, r0, 8
/* 06AC5C 800701FC 90050000 */  stw     r0, 0(r5)
/* 06AC60 80070200 4800000C */  b       lbl_8007020C
.global lbl_80070204
lbl_80070204:
/* 06AC64 80070204 38600000 */  li      r3, 0
/* 06AC68 80070208 4E800020 */  blr     
lbl_8007020C:
/* 06AC6C 8007020C 38600001 */  li      r3, 1
/* 06AC70 80070210 4E800020 */  blr     

.section .data

jtbl_800EDFC4:
    .word lbl_80070194
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701A0
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701AC
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701B8
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701C4
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701D4
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701E4
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_80070204
    .word lbl_800701F4
