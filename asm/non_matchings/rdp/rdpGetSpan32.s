glabel rdpGetSpan32
/* 06AACC 8007006C 5480073E */  clrlwi  r0, r4, 0x1c
/* 06AAD0 80070070 2800000C */  cmplwi  r0, 0xc
/* 06AAD4 80070074 41810058 */  bgt     lbl_800700CC
/* 06AAD8 80070078 3C80800F */  lis     r4, jtbl_800EDF5C@ha
/* 06AADC 8007007C 3884DF5C */  addi    r4, r4, jtbl_800EDF5C@l
/* 06AAE0 80070080 5400103A */  slwi    r0, r0, 2
/* 06AAE4 80070084 7C04002E */  lwzx    r0, r4, r0
/* 06AAE8 80070088 7C0903A6 */  mtctr   r0
/* 06AAEC 8007008C 4E800420 */  bctr    
.global lbl_80070090
lbl_80070090:
/* 06AAF0 80070090 80030000 */  lwz     r0, 0(r3)
/* 06AAF4 80070094 5400057E */  clrlwi  r0, r0, 0x15
/* 06AAF8 80070098 90050000 */  stw     r0, 0(r5)
/* 06AAFC 8007009C 48000038 */  b       lbl_800700D4
.global lbl_800700A0
lbl_800700A0:
/* 06AB00 800700A0 8003000C */  lwz     r0, 0xc(r3)
/* 06AB04 800700A4 540007FE */  clrlwi  r0, r0, 0x1f
/* 06AB08 800700A8 90050000 */  stw     r0, 0(r5)
/* 06AB0C 800700AC 48000028 */  b       lbl_800700D4
.global lbl_800700B0
lbl_800700B0:
/* 06AB10 800700B0 80030014 */  lwz     r0, 0x14(r3)
/* 06AB14 800700B4 5400067E */  clrlwi  r0, r0, 0x19
/* 06AB18 800700B8 90050000 */  stw     r0, 0(r5)
/* 06AB1C 800700BC 48000018 */  b       lbl_800700D4
.global lbl_800700C0
lbl_800700C0:
/* 06AB20 800700C0 80030010 */  lwz     r0, 0x10(r3)
/* 06AB24 800700C4 90050000 */  stw     r0, 0(r5)
/* 06AB28 800700C8 4800000C */  b       lbl_800700D4
.global lbl_800700CC
lbl_800700CC:
/* 06AB2C 800700CC 38600000 */  li      r3, 0
/* 06AB30 800700D0 4E800020 */  blr     
lbl_800700D4:
/* 06AB34 800700D4 38600001 */  li      r3, 1
/* 06AB38 800700D8 4E800020 */  blr     

.section .data

jtbl_800EDF5C:
    .word lbl_80070090
    .word lbl_800700CC
    .word lbl_800700CC
    .word lbl_800700CC
    .word lbl_800700A0
    .word lbl_800700CC
    .word lbl_800700CC
    .word lbl_800700CC
    .word lbl_800700B0
    .word lbl_800700CC
    .word lbl_800700CC
    .word lbl_800700CC
    .word lbl_800700C0
