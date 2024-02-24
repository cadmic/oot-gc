glabel CopyAndConvertCFB
/* 01F7F4 80024D94 7C0802A6 */  mflr    r0
/* 01F7F8 80024D98 90010004 */  stw     r0, 4(r1)
/* 01F7FC 80024D9C 9421FFE0 */  stwu    r1, -0x20(r1)
/* 01F800 80024DA0 93E1001C */  stw     r31, 0x1c(r1)
/* 01F804 80024DA4 93C10018 */  stw     r30, 0x18(r1)
/* 01F808 80024DA8 93A10014 */  stw     r29, 0x14(r1)
/* 01F80C 80024DAC 7C7D1B78 */  mr      r29, r3
/* 01F810 80024DB0 38600000 */  li      r3, 0
/* 01F814 80024DB4 38800000 */  li      r4, 0
/* 01F818 80024DB8 38A00280 */  li      r5, 0x280
/* 01F81C 80024DBC 38C001E0 */  li      r6, 0x1e0
/* 01F820 80024DC0 48086B1D */  bl      GXSetTexCopySrc
/* 01F824 80024DC4 38600140 */  li      r3, 0x140
/* 01F828 80024DC8 388000F0 */  li      r4, 0xf0
/* 01F82C 80024DCC 38A00005 */  li      r5, 5
/* 01F830 80024DD0 38C00001 */  li      r6, 1
/* 01F834 80024DD4 48086BB9 */  bl      GXSetTexCopyDst
/* 01F838 80024DD8 3C800002 */  lis     r4, 2
/* 01F83C 80024DDC 7FA3EB78 */  mr      r3, r29
/* 01F840 80024DE0 38845800 */  addi    r4, r4, 0x5800
/* 01F844 80024DE4 4807896D */  bl      DCInvalidateRange
/* 01F848 80024DE8 7FA3EB78 */  mr      r3, r29
/* 01F84C 80024DEC 38800000 */  li      r4, 0
/* 01F850 80024DF0 48087449 */  bl      GXCopyTex
/* 01F854 80024DF4 38000000 */  li      r0, 0
/* 01F858 80024DF8 900D89C4 */  stw     r0, sCopyFrameSyncReceived@sda21(r13)
/* 01F85C 80024DFC 38607D00 */  li      r3, 0x7d00
/* 01F860 80024E00 480860BD */  bl      GXSetDrawSync
/* 01F864 80024E04 48000004 */  b       lbl_80024E08
lbl_80024E08:
/* 01F868 80024E08 48000004 */  b       lbl_80024E0C
lbl_80024E0C:
/* 01F86C 80024E0C 800D89C4 */  lwz     r0, sCopyFrameSyncReceived@sda21(r13)
/* 01F870 80024E10 2C000000 */  cmpwi   r0, 0
/* 01F874 80024E14 4182FFF8 */  beq     lbl_80024E0C
/* 01F878 80024E18 3FDD0002 */  addis   r30, r29, 2
/* 01F87C 80024E1C 3BDE5800 */  addi    r30, r30, 0x5800
/* 01F880 80024E20 48000004 */  b       lbl_80024E24
lbl_80024E24:
/* 01F884 80024E24 3C608013 */  lis     r3, line@ha
/* 01F888 80024E28 3BE3FC60 */  addi    r31, r3, line@l
/* 01F88C 80024E2C 48000004 */  b       lbl_80024E30
lbl_80024E30:
/* 01F890 80024E30 48000284 */  b       lbl_800250B4
lbl_80024E34:
/* 01F894 80024E34 7FE3FB78 */  mr      r3, r31
/* 01F898 80024E38 7FA4EB78 */  mr      r4, r29
/* 01F89C 80024E3C 38A00A00 */  li      r5, 0xa00
/* 01F8A0 80024E40 4BFE1CB1 */  bl      xlHeapCopy
/* 01F8A4 80024E44 38E00000 */  li      r7, 0
/* 01F8A8 80024E48 38A00000 */  li      r5, 0
/* 01F8AC 80024E4C 48000004 */  b       lbl_80024E50
lbl_80024E50:
/* 01F8B0 80024E50 48000004 */  b       lbl_80024E54
lbl_80024E54:
/* 01F8B4 80024E54 48000004 */  b       lbl_80024E58
lbl_80024E58:
/* 01F8B8 80024E58 7FE4FB78 */  mr      r4, r31
/* 01F8BC 80024E5C 38C00000 */  li      r6, 0
/* 01F8C0 80024E60 48000004 */  b       lbl_80024E64
lbl_80024E64:
/* 01F8C4 80024E64 38000010 */  li      r0, 0x10
/* 01F8C8 80024E68 7C0903A6 */  mtctr   r0
/* 01F8CC 80024E6C 48000004 */  b       lbl_80024E70
lbl_80024E70:
/* 01F8D0 80024E70 48000004 */  b       lbl_80024E74
lbl_80024E74:
/* 01F8D4 80024E74 7C642A14 */  add     r3, r4, r5
/* 01F8D8 80024E78 48000004 */  b       lbl_80024E7C
lbl_80024E7C:
/* 01F8DC 80024E7C 48000004 */  b       lbl_80024E80
lbl_80024E80:
/* 01F8E0 80024E80 A0030000 */  lhz     r0, 0(r3)
/* 01F8E4 80024E84 38630002 */  addi    r3, r3, 2
/* 01F8E8 80024E88 5400083C */  slwi    r0, r0, 1
/* 01F8EC 80024E8C 60000001 */  ori     r0, r0, 1
/* 01F8F0 80024E90 B01D0000 */  sth     r0, 0(r29)
/* 01F8F4 80024E94 3BBD0002 */  addi    r29, r29, 2
/* 01F8F8 80024E98 A0030000 */  lhz     r0, 0(r3)
/* 01F8FC 80024E9C 38630002 */  addi    r3, r3, 2
/* 01F900 80024EA0 5400083C */  slwi    r0, r0, 1
/* 01F904 80024EA4 60000001 */  ori     r0, r0, 1
/* 01F908 80024EA8 B01D0000 */  sth     r0, 0(r29)
/* 01F90C 80024EAC 3BBD0002 */  addi    r29, r29, 2
/* 01F910 80024EB0 A0030000 */  lhz     r0, 0(r3)
/* 01F914 80024EB4 38630002 */  addi    r3, r3, 2
/* 01F918 80024EB8 5400083C */  slwi    r0, r0, 1
/* 01F91C 80024EBC 60000001 */  ori     r0, r0, 1
/* 01F920 80024EC0 B01D0000 */  sth     r0, 0(r29)
/* 01F924 80024EC4 3BBD0002 */  addi    r29, r29, 2
/* 01F928 80024EC8 A0030000 */  lhz     r0, 0(r3)
/* 01F92C 80024ECC 5400083C */  slwi    r0, r0, 1
/* 01F930 80024ED0 60000001 */  ori     r0, r0, 1
/* 01F934 80024ED4 B01D0000 */  sth     r0, 0(r29)
/* 01F938 80024ED8 3BBD0002 */  addi    r29, r29, 2
/* 01F93C 80024EDC 38840020 */  addi    r4, r4, 0x20
/* 01F940 80024EE0 7C642A14 */  add     r3, r4, r5
/* 01F944 80024EE4 48000004 */  b       lbl_80024EE8
lbl_80024EE8:
/* 01F948 80024EE8 48000004 */  b       lbl_80024EEC
lbl_80024EEC:
/* 01F94C 80024EEC A0030000 */  lhz     r0, 0(r3)
/* 01F950 80024EF0 38630002 */  addi    r3, r3, 2
/* 01F954 80024EF4 5400083C */  slwi    r0, r0, 1
/* 01F958 80024EF8 60000001 */  ori     r0, r0, 1
/* 01F95C 80024EFC B01D0000 */  sth     r0, 0(r29)
/* 01F960 80024F00 3BBD0002 */  addi    r29, r29, 2
/* 01F964 80024F04 A0030000 */  lhz     r0, 0(r3)
/* 01F968 80024F08 38630002 */  addi    r3, r3, 2
/* 01F96C 80024F0C 5400083C */  slwi    r0, r0, 1
/* 01F970 80024F10 60000001 */  ori     r0, r0, 1
/* 01F974 80024F14 B01D0000 */  sth     r0, 0(r29)
/* 01F978 80024F18 3BBD0002 */  addi    r29, r29, 2
/* 01F97C 80024F1C A0030000 */  lhz     r0, 0(r3)
/* 01F980 80024F20 38630002 */  addi    r3, r3, 2
/* 01F984 80024F24 5400083C */  slwi    r0, r0, 1
/* 01F988 80024F28 60000001 */  ori     r0, r0, 1
/* 01F98C 80024F2C B01D0000 */  sth     r0, 0(r29)
/* 01F990 80024F30 3BBD0002 */  addi    r29, r29, 2
/* 01F994 80024F34 A0030000 */  lhz     r0, 0(r3)
/* 01F998 80024F38 5400083C */  slwi    r0, r0, 1
/* 01F99C 80024F3C 60000001 */  ori     r0, r0, 1
/* 01F9A0 80024F40 B01D0000 */  sth     r0, 0(r29)
/* 01F9A4 80024F44 3BBD0002 */  addi    r29, r29, 2
/* 01F9A8 80024F48 38840020 */  addi    r4, r4, 0x20
/* 01F9AC 80024F4C 38C60001 */  addi    r6, r6, 1
/* 01F9B0 80024F50 7C642A14 */  add     r3, r4, r5
/* 01F9B4 80024F54 48000004 */  b       lbl_80024F58
lbl_80024F58:
/* 01F9B8 80024F58 48000004 */  b       lbl_80024F5C
lbl_80024F5C:
/* 01F9BC 80024F5C A0030000 */  lhz     r0, 0(r3)
/* 01F9C0 80024F60 38630002 */  addi    r3, r3, 2
/* 01F9C4 80024F64 5400083C */  slwi    r0, r0, 1
/* 01F9C8 80024F68 60000001 */  ori     r0, r0, 1
/* 01F9CC 80024F6C B01D0000 */  sth     r0, 0(r29)
/* 01F9D0 80024F70 3BBD0002 */  addi    r29, r29, 2
/* 01F9D4 80024F74 A0030000 */  lhz     r0, 0(r3)
/* 01F9D8 80024F78 38630002 */  addi    r3, r3, 2
/* 01F9DC 80024F7C 5400083C */  slwi    r0, r0, 1
/* 01F9E0 80024F80 60000001 */  ori     r0, r0, 1
/* 01F9E4 80024F84 B01D0000 */  sth     r0, 0(r29)
/* 01F9E8 80024F88 3BBD0002 */  addi    r29, r29, 2
/* 01F9EC 80024F8C A0030000 */  lhz     r0, 0(r3)
/* 01F9F0 80024F90 38630002 */  addi    r3, r3, 2
/* 01F9F4 80024F94 5400083C */  slwi    r0, r0, 1
/* 01F9F8 80024F98 60000001 */  ori     r0, r0, 1
/* 01F9FC 80024F9C B01D0000 */  sth     r0, 0(r29)
/* 01FA00 80024FA0 3BBD0002 */  addi    r29, r29, 2
/* 01FA04 80024FA4 A0030000 */  lhz     r0, 0(r3)
/* 01FA08 80024FA8 5400083C */  slwi    r0, r0, 1
/* 01FA0C 80024FAC 60000001 */  ori     r0, r0, 1
/* 01FA10 80024FB0 B01D0000 */  sth     r0, 0(r29)
/* 01FA14 80024FB4 3BBD0002 */  addi    r29, r29, 2
/* 01FA18 80024FB8 38840020 */  addi    r4, r4, 0x20
/* 01FA1C 80024FBC 38C60001 */  addi    r6, r6, 1
/* 01FA20 80024FC0 7C642A14 */  add     r3, r4, r5
/* 01FA24 80024FC4 48000004 */  b       lbl_80024FC8
lbl_80024FC8:
/* 01FA28 80024FC8 48000004 */  b       lbl_80024FCC
lbl_80024FCC:
/* 01FA2C 80024FCC A0030000 */  lhz     r0, 0(r3)
/* 01FA30 80024FD0 38630002 */  addi    r3, r3, 2
/* 01FA34 80024FD4 5400083C */  slwi    r0, r0, 1
/* 01FA38 80024FD8 60000001 */  ori     r0, r0, 1
/* 01FA3C 80024FDC B01D0000 */  sth     r0, 0(r29)
/* 01FA40 80024FE0 3BBD0002 */  addi    r29, r29, 2
/* 01FA44 80024FE4 A0030000 */  lhz     r0, 0(r3)
/* 01FA48 80024FE8 38630002 */  addi    r3, r3, 2
/* 01FA4C 80024FEC 5400083C */  slwi    r0, r0, 1
/* 01FA50 80024FF0 60000001 */  ori     r0, r0, 1
/* 01FA54 80024FF4 B01D0000 */  sth     r0, 0(r29)
/* 01FA58 80024FF8 3BBD0002 */  addi    r29, r29, 2
/* 01FA5C 80024FFC A0030000 */  lhz     r0, 0(r3)
/* 01FA60 80025000 38630002 */  addi    r3, r3, 2
/* 01FA64 80025004 5400083C */  slwi    r0, r0, 1
/* 01FA68 80025008 60000001 */  ori     r0, r0, 1
/* 01FA6C 8002500C B01D0000 */  sth     r0, 0(r29)
/* 01FA70 80025010 3BBD0002 */  addi    r29, r29, 2
/* 01FA74 80025014 A0030000 */  lhz     r0, 0(r3)
/* 01FA78 80025018 5400083C */  slwi    r0, r0, 1
/* 01FA7C 8002501C 60000001 */  ori     r0, r0, 1
/* 01FA80 80025020 B01D0000 */  sth     r0, 0(r29)
/* 01FA84 80025024 3BBD0002 */  addi    r29, r29, 2
/* 01FA88 80025028 38840020 */  addi    r4, r4, 0x20
/* 01FA8C 8002502C 38C60001 */  addi    r6, r6, 1
/* 01FA90 80025030 7C642A14 */  add     r3, r4, r5
/* 01FA94 80025034 48000004 */  b       lbl_80025038
lbl_80025038:
/* 01FA98 80025038 48000004 */  b       lbl_8002503C
lbl_8002503C:
/* 01FA9C 8002503C A0030000 */  lhz     r0, 0(r3)
/* 01FAA0 80025040 38630002 */  addi    r3, r3, 2
/* 01FAA4 80025044 5400083C */  slwi    r0, r0, 1
/* 01FAA8 80025048 60000001 */  ori     r0, r0, 1
/* 01FAAC 8002504C B01D0000 */  sth     r0, 0(r29)
/* 01FAB0 80025050 3BBD0002 */  addi    r29, r29, 2
/* 01FAB4 80025054 A0030000 */  lhz     r0, 0(r3)
/* 01FAB8 80025058 38630002 */  addi    r3, r3, 2
/* 01FABC 8002505C 5400083C */  slwi    r0, r0, 1
/* 01FAC0 80025060 60000001 */  ori     r0, r0, 1
/* 01FAC4 80025064 B01D0000 */  sth     r0, 0(r29)
/* 01FAC8 80025068 3BBD0002 */  addi    r29, r29, 2
/* 01FACC 8002506C A0030000 */  lhz     r0, 0(r3)
/* 01FAD0 80025070 38630002 */  addi    r3, r3, 2
/* 01FAD4 80025074 5400083C */  slwi    r0, r0, 1
/* 01FAD8 80025078 60000001 */  ori     r0, r0, 1
/* 01FADC 8002507C B01D0000 */  sth     r0, 0(r29)
/* 01FAE0 80025080 3BBD0002 */  addi    r29, r29, 2
/* 01FAE4 80025084 A0030000 */  lhz     r0, 0(r3)
/* 01FAE8 80025088 5400083C */  slwi    r0, r0, 1
/* 01FAEC 8002508C 60000001 */  ori     r0, r0, 1
/* 01FAF0 80025090 B01D0000 */  sth     r0, 0(r29)
/* 01FAF4 80025094 3BBD0002 */  addi    r29, r29, 2
/* 01FAF8 80025098 38840020 */  addi    r4, r4, 0x20
/* 01FAFC 8002509C 38C60001 */  addi    r6, r6, 1
/* 01FB00 800250A0 4200FDD4 */  bdnz    lbl_80024E74
/* 01FB04 800250A4 38A50008 */  addi    r5, r5, 8
/* 01FB08 800250A8 38E70001 */  addi    r7, r7, 1
/* 01FB0C 800250AC 2C070004 */  cmpwi   r7, 4
/* 01FB10 800250B0 4180FDA8 */  blt     lbl_80024E58
lbl_800250B4:
/* 01FB14 800250B4 7C1DF040 */  cmplw   r29, r30
/* 01FB18 800250B8 4180FD7C */  blt     lbl_80024E34
/* 01FB1C 800250BC 80010024 */  lwz     r0, 0x24(r1)
/* 01FB20 800250C0 83E1001C */  lwz     r31, 0x1c(r1)
/* 01FB24 800250C4 83C10018 */  lwz     r30, 0x18(r1)
/* 01FB28 800250C8 7C0803A6 */  mtlr    r0
/* 01FB2C 800250CC 83A10014 */  lwz     r29, 0x14(r1)
/* 01FB30 800250D0 38210020 */  addi    r1, r1, 0x20
/* 01FB34 800250D4 4E800020 */  blr     
