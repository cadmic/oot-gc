glabel __sinf
/* 09034C 800958EC 7C0802A6 */  mflr    r0
/* 090350 800958F0 90010004 */  stw     r0, 4(r1)
/* 090354 800958F4 9421FFE8 */  stwu    r1, -0x18(r1)
/* 090358 800958F8 93E10014 */  stw     r31, 0x14(r1)
/* 09035C 800958FC 7C7F1B78 */  mr      r31, r3
/* 090360 80095900 C02301A4 */  lfs     f1, 0x1a4(r3)
/* 090364 80095904 4803C96D */  bl      sinf
/* 090368 80095908 D03F0144 */  stfs    f1, 0x144(r31)
/* 09036C 8009590C 8001001C */  lwz     r0, 0x1c(r1)
/* 090370 80095910 83E10014 */  lwz     r31, 0x14(r1)
/* 090374 80095914 38210018 */  addi    r1, r1, 0x18
/* 090378 80095918 7C0803A6 */  mtlr    r0
/* 09037C 8009591C 4E800020 */  blr     