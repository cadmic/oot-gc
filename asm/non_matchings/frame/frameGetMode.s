glabel frameGetMode
/* 01AA5C 8001FFFC 5480103A */  slwi    r0, r4, 2
/* 01AA60 80020000 7C630214 */  add     r3, r3, r0
/* 01AA64 80020004 80030090 */  lwz     r0, 0x90(r3)
/* 01AA68 80020008 38600001 */  li      r3, 1
/* 01AA6C 8002000C 90050000 */  stw     r0, 0(r5)
/* 01AA70 80020010 4E800020 */  blr     