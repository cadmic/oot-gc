glabel cpuExecuteLoadStoreF
/* 0321FC 8003779C 7C0802A6 */  mflr    r0
/* 032200 800377A0 3CE0800F */  lis     r7, gClassCPU@ha
/* 032204 800377A4 90010004 */  stw     r0, 4(r1)
/* 032208 800377A8 9421FFB8 */  stwu    r1, -0x48(r1)
/* 03220C 800377AC BEC10020 */  stmw    r22, 0x20(r1)
/* 032210 800377B0 7C7F1B78 */  mr      r31, r3
/* 032214 800377B4 381F002C */  addi    r0, r31, 0x2c
/* 032218 800377B8 7C9F0050 */  subf    r4, r31, r0
/* 03221C 800377BC 3B260000 */  addi    r25, r6, 0
/* 032220 800377C0 3F0490C3 */  addis   r24, r4, 0x90c3
/* 032224 800377C4 3AC50000 */  addi    r22, r5, 0
/* 032228 800377C8 3BC7B658 */  addi    r30, r7, gClassCPU@l
/* 03222C 800377CC 3881001C */  addi    r4, r1, 0x1c
/* 032230 800377D0 3BA00000 */  li      r29, 0
/* 032234 800377D4 3B800000 */  li      r28, 0
/* 032238 800377D8 3B600000 */  li      r27, 0
/* 03223C 800377DC 38C00000 */  li      r6, 0
/* 032240 800377E0 80630008 */  lwz     r3, 8(r3)
/* 032244 800377E4 8063002C */  lwz     r3, 0x2c(r3)
/* 032248 800377E8 480358B9 */  bl      ramGetBuffer
/* 03224C 800377EC 8081001C */  lwz     r4, 0x1c(r1)
/* 032250 800377F0 3C7F0001 */  addis   r3, r31, 1
/* 032254 800377F4 80032060 */  lwz     r0, 0x2060(r3)
/* 032258 800377F8 81040000 */  lwz     r8, 0(r4)
/* 03225C 800377FC 540405EF */  rlwinm. r4, r0, 0, 0x17, 0x17
/* 032260 80037800 55037638 */  rlwinm  r3, r8, 0xe, 0x18, 0x1c
/* 032264 80037804 7CDF1A14 */  add     r6, r31, r3
/* 032268 80037808 5505043E */  clrlwi  r5, r8, 0x10
/* 03226C 8003780C 80C60044 */  lwz     r6, 0x44(r6)
/* 032270 80037810 7CA50734 */  extsh   r5, r5
/* 032274 80037814 7CC62A14 */  add     r6, r6, r5
/* 032278 80037818 54C5843E */  srwi    r5, r6, 0x10
/* 03227C 8003781C 7CBF2A14 */  add     r5, r31, r5
/* 032280 80037820 88A50F64 */  lbz     r5, 0xf64(r5)
/* 032284 80037824 55005EFE */  rlwinm  r0, r8, 0xb, 0x1b, 0x1f
/* 032288 80037828 41820018 */  beq     lbl_80037840
/* 03228C 8003782C 3899FFF4 */  addi    r4, r25, -12
/* 032290 80037830 3AE40000 */  addi    r23, r4, 0
/* 032294 80037834 3B44FFF8 */  addi    r26, r4, -8
/* 032298 80037838 3B390010 */  addi    r25, r25, 0x10
/* 03229C 8003783C 48000014 */  b       lbl_80037850
lbl_80037840:
/* 0322A0 80037840 3899FFF4 */  addi    r4, r25, -12
/* 0322A4 80037844 3AE40000 */  addi    r23, r4, 0
/* 0322A8 80037848 3B44FFF8 */  addi    r26, r4, -8
/* 0322AC 8003784C 3B39000C */  addi    r25, r25, 0xc
lbl_80037850:
/* 0322B0 80037850 54C4273E */  srwi    r4, r6, 0x1c
/* 0322B4 80037854 28040008 */  cmplwi  r4, 8
/* 0322B8 80037858 40800008 */  bge     lbl_80037860
/* 0322BC 8003785C 3B600001 */  li      r27, 1
lbl_80037860:
/* 0322C0 80037860 2C1B0000 */  cmpwi   r27, 0
/* 0322C4 80037864 408207C4 */  bne     lbl_80038028
/* 0322C8 80037868 28050080 */  cmplwi  r5, 0x80
/* 0322CC 8003786C 418007BC */  blt     lbl_80038028
/* 0322D0 80037870 550536BE */  srwi    r5, r8, 0x1a
/* 0322D4 80037874 38E5FFCF */  addi    r7, r5, -49
/* 0322D8 80037878 2807000E */  cmplwi  r7, 0xe
/* 0322DC 8003787C 550586FE */  rlwinm  r5, r8, 0x10, 0x1b, 0x1f
/* 0322E0 80037880 41810790 */  bgt     lbl_80038010
/* 0322E4 80037884 3CC0800F */  lis     r6, jtbl_800EC1EC@ha
/* 0322E8 80037888 38C6C1EC */  addi    r6, r6, jtbl_800EC1EC@l
/* 0322EC 8003788C 54E7103A */  slwi    r7, r7, 2
/* 0322F0 80037890 7CC6382E */  lwzx    r6, r6, r7
/* 0322F4 80037894 7CC903A6 */  mtctr   r6
/* 0322F8 80037898 4E800420 */  bctr    
glabel lbl_8003789C
/* 0322FC 8003789C 5400103A */  slwi    r0, r0, 2
/* 032300 800378A0 7CDE0214 */  add     r6, r30, r0
/* 032304 800378A4 80C60818 */  lwz     r6, 0x818(r6)
/* 032308 800378A8 54C005EF */  rlwinm. r0, r6, 0, 0x17, 0x17
/* 03230C 800378AC 41820030 */  beq     lbl_800378DC
/* 032310 800378B0 38030040 */  addi    r0, r3, 0x40
/* 032314 800378B4 7C1F0214 */  add     r0, r31, r0
/* 032318 800378B8 7C7F0050 */  subf    r3, r31, r0
/* 03231C 800378BC 38030004 */  addi    r0, r3, 4
/* 032320 800378C0 5403043E */  clrlwi  r3, r0, 0x10
/* 032324 800378C4 38000000 */  li      r0, 0
/* 032328 800378C8 3C6380C3 */  addis   r3, r3, 0x80c3
/* 03232C 800378CC 5400103A */  slwi    r0, r0, 2
/* 032330 800378D0 7C77012E */  stwx    r3, r23, r0
/* 032334 800378D4 38C00006 */  li      r6, 6
/* 032338 800378D8 3BA00001 */  li      r29, 1
lbl_800378DC:
/* 03233C 800378DC 3C7F0001 */  addis   r3, r31, 1
/* 032340 800378E0 80032060 */  lwz     r0, 0x2060(r3)
/* 032344 800378E4 540005EF */  rlwinm. r0, r0, 0, 0x17, 0x17
/* 032348 800378E8 41820030 */  beq     lbl_80037918
/* 03234C 800378EC 2804000A */  cmplwi  r4, 0xa
/* 032350 800378F0 41800028 */  blt     lbl_80037918
/* 032354 800378F4 54C0A814 */  slwi    r0, r6, 0x15
/* 032358 800378F8 64047C00 */  oris    r4, r0, 0x7c00
/* 03235C 800378FC 60840038 */  ori     r4, r4, 0x38
/* 032360 80037900 54C3801E */  slwi    r3, r6, 0x10
/* 032364 80037904 7C831B78 */  or      r3, r4, r3
/* 032368 80037908 57A0103A */  slwi    r0, r29, 2
/* 03236C 8003790C 60634800 */  ori     r3, r3, 0x4800
/* 032370 80037910 7C77012E */  stwx    r3, r23, r0
/* 032374 80037914 3BBD0001 */  addi    r29, r29, 1
lbl_80037918:
/* 032378 80037918 7CA00E70 */  srawi   r0, r5, 1
/* 03237C 8003791C 7C000194 */  addze   r0, r0
/* 032380 80037920 54C4801E */  slwi    r4, r6, 0x10
/* 032384 80037924 5400083C */  slwi    r0, r0, 1
/* 032388 80037928 64847CE0 */  oris    r4, r4, 0x7ce0
/* 03238C 8003792C 7C002810 */  subfc   r0, r0, r5
/* 032390 80037930 2C000001 */  cmpwi   r0, 1
/* 032394 80037934 57A0103A */  slwi    r0, r29, 2
/* 032398 80037938 60844214 */  ori     r4, r4, 0x4214
/* 03239C 8003793C 7C97012E */  stwx    r4, r23, r0
/* 0323A0 80037940 3BBD0001 */  addi    r29, r29, 1
/* 0323A4 80037944 4082004C */  bne     lbl_80037990
/* 0323A8 80037948 8061001C */  lwz     r3, 0x1c(r1)
/* 0323AC 8003794C 389D0000 */  addi    r4, r29, 0
/* 0323B0 80037950 3805FFFF */  addi    r0, r5, -1
/* 0323B4 80037954 80A30000 */  lwz     r5, 0(r3)
/* 0323B8 80037958 54031838 */  slwi    r3, r0, 3
/* 0323BC 8003795C 38630140 */  addi    r3, r3, 0x140
/* 0323C0 80037960 54A5043E */  clrlwi  r5, r5, 0x10
/* 0323C4 80037964 7C7F1A14 */  add     r3, r31, r3
/* 0323C8 80037968 3BBD0001 */  addi    r29, r29, 1
/* 0323CC 8003796C 7C7F1850 */  subf    r3, r31, r3
/* 0323D0 80037970 57A0103A */  slwi    r0, r29, 2
/* 0323D4 80037974 64A580A7 */  oris    r5, r5, 0x80a7
/* 0323D8 80037978 5484103A */  slwi    r4, r4, 2
/* 0323DC 8003797C 7CB7212E */  stwx    r5, r23, r4
/* 0323E0 80037980 3C6390A3 */  addis   r3, r3, 0x90a3
/* 0323E4 80037984 3BBD0001 */  addi    r29, r29, 1
/* 0323E8 80037988 7C77012E */  stwx    r3, r23, r0
/* 0323EC 8003798C 480006F0 */  b       lbl_8003807C
lbl_80037990:
/* 0323F0 80037990 80C1001C */  lwz     r6, 0x1c(r1)
/* 0323F4 80037994 54A31838 */  slwi    r3, r5, 3
/* 0323F8 80037998 389D0000 */  addi    r4, r29, 0
/* 0323FC 8003799C 80A60000 */  lwz     r5, 0(r6)
/* 032400 800379A0 38030140 */  addi    r0, r3, 0x140
/* 032404 800379A4 7C7F0214 */  add     r3, r31, r0
/* 032408 800379A8 54A5043E */  clrlwi  r5, r5, 0x10
/* 03240C 800379AC 7C7F1850 */  subf    r3, r31, r3
/* 032410 800379B0 3BBD0001 */  addi    r29, r29, 1
/* 032414 800379B4 3C6390A3 */  addis   r3, r3, 0x90a3
/* 032418 800379B8 57A0103A */  slwi    r0, r29, 2
/* 03241C 800379BC 64A580A7 */  oris    r5, r5, 0x80a7
/* 032420 800379C0 5484103A */  slwi    r4, r4, 2
/* 032424 800379C4 7CB7212E */  stwx    r5, r23, r4
/* 032428 800379C8 38630004 */  addi    r3, r3, 4
/* 03242C 800379CC 3BBD0001 */  addi    r29, r29, 1
/* 032430 800379D0 7C77012E */  stwx    r3, r23, r0
/* 032434 800379D4 480006A8 */  b       lbl_8003807C
glabel lbl_800379D8
/* 032438 800379D8 5400103A */  slwi    r0, r0, 2
/* 03243C 800379DC 7CDE0214 */  add     r6, r30, r0
/* 032440 800379E0 80C60818 */  lwz     r6, 0x818(r6)
/* 032444 800379E4 54C005EF */  rlwinm. r0, r6, 0, 0x17, 0x17
/* 032448 800379E8 41820030 */  beq     lbl_80037A18
/* 03244C 800379EC 38030040 */  addi    r0, r3, 0x40
/* 032450 800379F0 7C1F0214 */  add     r0, r31, r0
/* 032454 800379F4 7C7F0050 */  subf    r3, r31, r0
/* 032458 800379F8 38030004 */  addi    r0, r3, 4
/* 03245C 800379FC 5403043E */  clrlwi  r3, r0, 0x10
/* 032460 80037A00 38000000 */  li      r0, 0
/* 032464 80037A04 3C6380C3 */  addis   r3, r3, 0x80c3
/* 032468 80037A08 5400103A */  slwi    r0, r0, 2
/* 03246C 80037A0C 7C77012E */  stwx    r3, r23, r0
/* 032470 80037A10 38C00006 */  li      r6, 6
/* 032474 80037A14 3BA00001 */  li      r29, 1
lbl_80037A18:
/* 032478 80037A18 3C7F0001 */  addis   r3, r31, 1
/* 03247C 80037A1C 80032060 */  lwz     r0, 0x2060(r3)
/* 032480 80037A20 540005EF */  rlwinm. r0, r0, 0, 0x17, 0x17
/* 032484 80037A24 41820030 */  beq     lbl_80037A54
/* 032488 80037A28 2804000A */  cmplwi  r4, 0xa
/* 03248C 80037A2C 41800028 */  blt     lbl_80037A54
/* 032490 80037A30 54C0A814 */  slwi    r0, r6, 0x15
/* 032494 80037A34 64047C00 */  oris    r4, r0, 0x7c00
/* 032498 80037A38 60840038 */  ori     r4, r4, 0x38
/* 03249C 80037A3C 54C3801E */  slwi    r3, r6, 0x10
/* 0324A0 80037A40 7C831B78 */  or      r3, r4, r3
/* 0324A4 80037A44 57A0103A */  slwi    r0, r29, 2
/* 0324A8 80037A48 60634800 */  ori     r3, r3, 0x4800
/* 0324AC 80037A4C 7C77012E */  stwx    r3, r23, r0
/* 0324B0 80037A50 3BBD0001 */  addi    r29, r29, 1
lbl_80037A54:
/* 0324B4 80037A54 7CA00E70 */  srawi   r0, r5, 1
/* 0324B8 80037A58 7C000194 */  addze   r0, r0
/* 0324BC 80037A5C 54C4801E */  slwi    r4, r6, 0x10
/* 0324C0 80037A60 5400083C */  slwi    r0, r0, 1
/* 0324C4 80037A64 64847CE0 */  oris    r4, r4, 0x7ce0
/* 0324C8 80037A68 7C002810 */  subfc   r0, r0, r5
/* 0324CC 80037A6C 2C000001 */  cmpwi   r0, 1
/* 0324D0 80037A70 57A0103A */  slwi    r0, r29, 2
/* 0324D4 80037A74 60844214 */  ori     r4, r4, 0x4214
/* 0324D8 80037A78 7C97012E */  stwx    r4, r23, r0
/* 0324DC 80037A7C 3BBD0001 */  addi    r29, r29, 1
/* 0324E0 80037A80 4082002C */  bne     lbl_80037AAC
/* 0324E4 80037A84 3805FFFF */  addi    r0, r5, -1
/* 0324E8 80037A88 54031838 */  slwi    r3, r0, 3
/* 0324EC 80037A8C 38030140 */  addi    r0, r3, 0x140
/* 0324F0 80037A90 7C7F0214 */  add     r3, r31, r0
/* 0324F4 80037A94 7C7F1850 */  subf    r3, r31, r3
/* 0324F8 80037A98 57A0103A */  slwi    r0, r29, 2
/* 0324FC 80037A9C 3C6380A3 */  addis   r3, r3, 0x80a3
/* 032500 80037AA0 7C77012E */  stwx    r3, r23, r0
/* 032504 80037AA4 3BBD0001 */  addi    r29, r29, 1
/* 032508 80037AA8 48000028 */  b       lbl_80037AD0
lbl_80037AAC:
/* 03250C 80037AAC 54A31838 */  slwi    r3, r5, 3
/* 032510 80037AB0 38030140 */  addi    r0, r3, 0x140
/* 032514 80037AB4 7C1F0214 */  add     r0, r31, r0
/* 032518 80037AB8 7C7F0050 */  subf    r3, r31, r0
/* 03251C 80037ABC 3C6380A3 */  addis   r3, r3, 0x80a3
/* 032520 80037AC0 57A0103A */  slwi    r0, r29, 2
/* 032524 80037AC4 38630004 */  addi    r3, r3, 4
/* 032528 80037AC8 7C77012E */  stwx    r3, r23, r0
/* 03252C 80037ACC 3BBD0001 */  addi    r29, r29, 1
lbl_80037AD0:
/* 032530 80037AD0 8061001C */  lwz     r3, 0x1c(r1)
/* 032534 80037AD4 57A0103A */  slwi    r0, r29, 2
/* 032538 80037AD8 3BBD0001 */  addi    r29, r29, 1
/* 03253C 80037ADC 80630000 */  lwz     r3, 0(r3)
/* 032540 80037AE0 5463043E */  clrlwi  r3, r3, 0x10
/* 032544 80037AE4 646390A7 */  oris    r3, r3, 0x90a7
/* 032548 80037AE8 7C77012E */  stwx    r3, r23, r0
/* 03254C 80037AEC 48000590 */  b       lbl_8003807C
glabel lbl_80037AF0
/* 032550 80037AF0 5400103A */  slwi    r0, r0, 2
/* 032554 80037AF4 7CDE0214 */  add     r6, r30, r0
/* 032558 80037AF8 80C60818 */  lwz     r6, 0x818(r6)
/* 03255C 80037AFC 54C005EF */  rlwinm. r0, r6, 0, 0x17, 0x17
/* 032560 80037B00 41820030 */  beq     lbl_80037B30
/* 032564 80037B04 38030040 */  addi    r0, r3, 0x40
/* 032568 80037B08 7C1F0214 */  add     r0, r31, r0
/* 03256C 80037B0C 7C7F0050 */  subf    r3, r31, r0
/* 032570 80037B10 38030004 */  addi    r0, r3, 4
/* 032574 80037B14 5403043E */  clrlwi  r3, r0, 0x10
/* 032578 80037B18 38000000 */  li      r0, 0
/* 03257C 80037B1C 3C6380C3 */  addis   r3, r3, 0x80c3
/* 032580 80037B20 5400103A */  slwi    r0, r0, 2
/* 032584 80037B24 7C77012E */  stwx    r3, r23, r0
/* 032588 80037B28 38C00006 */  li      r6, 6
/* 03258C 80037B2C 3BA00001 */  li      r29, 1
lbl_80037B30:
/* 032590 80037B30 3C7F0001 */  addis   r3, r31, 1
/* 032594 80037B34 80032060 */  lwz     r0, 0x2060(r3)
/* 032598 80037B38 540005EF */  rlwinm. r0, r0, 0, 0x17, 0x17
/* 03259C 80037B3C 41820030 */  beq     lbl_80037B6C
/* 0325A0 80037B40 2804000A */  cmplwi  r4, 0xa
/* 0325A4 80037B44 41800028 */  blt     lbl_80037B6C
/* 0325A8 80037B48 54C0A814 */  slwi    r0, r6, 0x15
/* 0325AC 80037B4C 64047C00 */  oris    r4, r0, 0x7c00
/* 0325B0 80037B50 60840038 */  ori     r4, r4, 0x38
/* 0325B4 80037B54 54C3801E */  slwi    r3, r6, 0x10
/* 0325B8 80037B58 7C831B78 */  or      r3, r4, r3
/* 0325BC 80037B5C 57A0103A */  slwi    r0, r29, 2
/* 0325C0 80037B60 60634800 */  ori     r3, r3, 0x4800
/* 0325C4 80037B64 7C77012E */  stwx    r3, r23, r0
/* 0325C8 80037B68 3BBD0001 */  addi    r29, r29, 1
lbl_80037B6C:
/* 0325CC 80037B6C 54C3801E */  slwi    r3, r6, 0x10
/* 0325D0 80037B70 64637CE0 */  oris    r3, r3, 0x7ce0
/* 0325D4 80037B74 57A0103A */  slwi    r0, r29, 2
/* 0325D8 80037B78 60634214 */  ori     r3, r3, 0x4214
/* 0325DC 80037B7C 7C77012E */  stwx    r3, r23, r0
/* 0325E0 80037B80 54A31838 */  slwi    r3, r5, 3
/* 0325E4 80037B84 38030140 */  addi    r0, r3, 0x140
/* 0325E8 80037B88 80C1001C */  lwz     r6, 0x1c(r1)
/* 0325EC 80037B8C 3BBD0001 */  addi    r29, r29, 1
/* 0325F0 80037B90 7C7F0214 */  add     r3, r31, r0
/* 0325F4 80037B94 80A60000 */  lwz     r5, 0(r6)
/* 0325F8 80037B98 389D0000 */  addi    r4, r29, 0
/* 0325FC 80037B9C 7C7F1850 */  subf    r3, r31, r3
/* 032600 80037BA0 54A5043E */  clrlwi  r5, r5, 0x10
/* 032604 80037BA4 3CC390A3 */  addis   r6, r3, 0x90a3
/* 032608 80037BA8 3BBD0001 */  addi    r29, r29, 1
/* 03260C 80037BAC 57A0103A */  slwi    r0, r29, 2
/* 032610 80037BB0 64A580A7 */  oris    r5, r5, 0x80a7
/* 032614 80037BB4 5483103A */  slwi    r3, r4, 2
/* 032618 80037BB8 7CB7192E */  stwx    r5, r23, r3
/* 03261C 80037BBC 3BBD0001 */  addi    r29, r29, 1
/* 032620 80037BC0 57A4103A */  slwi    r4, r29, 2
/* 032624 80037BC4 7CD7012E */  stwx    r6, r23, r0
/* 032628 80037BC8 3BBD0001 */  addi    r29, r29, 1
/* 03262C 80037BCC 57A0103A */  slwi    r0, r29, 2
/* 032630 80037BD0 8061001C */  lwz     r3, 0x1c(r1)
/* 032634 80037BD4 3BBD0001 */  addi    r29, r29, 1
/* 032638 80037BD8 80A30000 */  lwz     r5, 0(r3)
/* 03263C 80037BDC 38660004 */  addi    r3, r6, 4
/* 032640 80037BE0 54A5043E */  clrlwi  r5, r5, 0x10
/* 032644 80037BE4 38A50004 */  addi    r5, r5, 4
/* 032648 80037BE8 64A580A7 */  oris    r5, r5, 0x80a7
/* 03264C 80037BEC 7CB7212E */  stwx    r5, r23, r4
/* 032650 80037BF0 7C77012E */  stwx    r3, r23, r0
/* 032654 80037BF4 48000488 */  b       lbl_8003807C
glabel lbl_80037BF8
/* 032658 80037BF8 5400103A */  slwi    r0, r0, 2
/* 03265C 80037BFC 7CDE0214 */  add     r6, r30, r0
/* 032660 80037C00 80C60818 */  lwz     r6, 0x818(r6)
/* 032664 80037C04 54C005EF */  rlwinm. r0, r6, 0, 0x17, 0x17
/* 032668 80037C08 41820030 */  beq     lbl_80037C38
/* 03266C 80037C0C 38030040 */  addi    r0, r3, 0x40
/* 032670 80037C10 7C1F0214 */  add     r0, r31, r0
/* 032674 80037C14 7C7F0050 */  subf    r3, r31, r0
/* 032678 80037C18 38030004 */  addi    r0, r3, 4
/* 03267C 80037C1C 5403043E */  clrlwi  r3, r0, 0x10
/* 032680 80037C20 38000000 */  li      r0, 0
/* 032684 80037C24 3C6380C3 */  addis   r3, r3, 0x80c3
/* 032688 80037C28 5400103A */  slwi    r0, r0, 2
/* 03268C 80037C2C 7C77012E */  stwx    r3, r23, r0
/* 032690 80037C30 38C00006 */  li      r6, 6
/* 032694 80037C34 3BA00001 */  li      r29, 1
lbl_80037C38:
/* 032698 80037C38 3C7F0001 */  addis   r3, r31, 1
/* 03269C 80037C3C 80032060 */  lwz     r0, 0x2060(r3)
/* 0326A0 80037C40 540005EF */  rlwinm. r0, r0, 0, 0x17, 0x17
/* 0326A4 80037C44 41820030 */  beq     lbl_80037C74
/* 0326A8 80037C48 2804000A */  cmplwi  r4, 0xa
/* 0326AC 80037C4C 41800028 */  blt     lbl_80037C74
/* 0326B0 80037C50 54C0A814 */  slwi    r0, r6, 0x15
/* 0326B4 80037C54 64047C00 */  oris    r4, r0, 0x7c00
/* 0326B8 80037C58 60840038 */  ori     r4, r4, 0x38
/* 0326BC 80037C5C 54C3801E */  slwi    r3, r6, 0x10
/* 0326C0 80037C60 7C831B78 */  or      r3, r4, r3
/* 0326C4 80037C64 57A0103A */  slwi    r0, r29, 2
/* 0326C8 80037C68 60634800 */  ori     r3, r3, 0x4800
/* 0326CC 80037C6C 7C77012E */  stwx    r3, r23, r0
/* 0326D0 80037C70 3BBD0001 */  addi    r29, r29, 1
lbl_80037C74:
/* 0326D4 80037C74 54C0801E */  slwi    r0, r6, 0x10
/* 0326D8 80037C78 38FD0000 */  addi    r7, r29, 0
/* 0326DC 80037C7C 54A31838 */  slwi    r3, r5, 3
/* 0326E0 80037C80 64087CE0 */  oris    r8, r0, 0x7ce0
/* 0326E4 80037C84 38030140 */  addi    r0, r3, 0x140
/* 0326E8 80037C88 3BBD0001 */  addi    r29, r29, 1
/* 0326EC 80037C8C 389D0000 */  addi    r4, r29, 0
/* 0326F0 80037C90 7C1F0214 */  add     r0, r31, r0
/* 0326F4 80037C94 7C7F0050 */  subf    r3, r31, r0
/* 0326F8 80037C98 61084214 */  ori     r8, r8, 0x4214
/* 0326FC 80037C9C 54E5103A */  slwi    r5, r7, 2
/* 032700 80037CA0 7D17292E */  stwx    r8, r23, r5
/* 032704 80037CA4 3CC380A3 */  addis   r6, r3, 0x80a3
/* 032708 80037CA8 5484103A */  slwi    r4, r4, 2
/* 03270C 80037CAC 7CD7212E */  stwx    r6, r23, r4
/* 032710 80037CB0 38860004 */  addi    r4, r6, 4
/* 032714 80037CB4 3BBD0001 */  addi    r29, r29, 1
/* 032718 80037CB8 387D0000 */  addi    r3, r29, 0
/* 03271C 80037CBC 80C1001C */  lwz     r6, 0x1c(r1)
/* 032720 80037CC0 5465103A */  slwi    r5, r3, 2
/* 032724 80037CC4 80C60000 */  lwz     r6, 0(r6)
/* 032728 80037CC8 3BBD0001 */  addi    r29, r29, 1
/* 03272C 80037CCC 57A3103A */  slwi    r3, r29, 2
/* 032730 80037CD0 54C6043E */  clrlwi  r6, r6, 0x10
/* 032734 80037CD4 64C690A7 */  oris    r6, r6, 0x90a7
/* 032738 80037CD8 7CD7292E */  stwx    r6, r23, r5
/* 03273C 80037CDC 3BBD0001 */  addi    r29, r29, 1
/* 032740 80037CE0 57A0103A */  slwi    r0, r29, 2
/* 032744 80037CE4 7C97192E */  stwx    r4, r23, r3
/* 032748 80037CE8 3BBD0001 */  addi    r29, r29, 1
/* 03274C 80037CEC 8061001C */  lwz     r3, 0x1c(r1)
/* 032750 80037CF0 80630000 */  lwz     r3, 0(r3)
/* 032754 80037CF4 5463043E */  clrlwi  r3, r3, 0x10
/* 032758 80037CF8 38630004 */  addi    r3, r3, 4
/* 03275C 80037CFC 646390A7 */  oris    r3, r3, 0x90a7
/* 032760 80037D00 7C77012E */  stwx    r3, r23, r0
/* 032764 80037D04 48000378 */  b       lbl_8003807C
glabel lbl_80037D08
/* 032768 80037D08 54A5103A */  slwi    r5, r5, 2
/* 03276C 80037D0C 7CBE2A14 */  add     r5, r30, r5
/* 032770 80037D10 80A50818 */  lwz     r5, 0x818(r5)
/* 032774 80037D14 54A605EF */  rlwinm. r6, r5, 0, 0x17, 0x17
/* 032778 80037D18 41820008 */  beq     lbl_80037D20
/* 03277C 80037D1C 38A00005 */  li      r5, 5
lbl_80037D20:
/* 032780 80037D20 5400103A */  slwi    r0, r0, 2
/* 032784 80037D24 7CDE0214 */  add     r6, r30, r0
/* 032788 80037D28 80060818 */  lwz     r0, 0x818(r6)
/* 03278C 80037D2C 540605EF */  rlwinm. r6, r0, 0, 0x17, 0x17
/* 032790 80037D30 41820030 */  beq     lbl_80037D60
/* 032794 80037D34 38030040 */  addi    r0, r3, 0x40
/* 032798 80037D38 7C1F0214 */  add     r0, r31, r0
/* 03279C 80037D3C 7C7F0050 */  subf    r3, r31, r0
/* 0327A0 80037D40 38030004 */  addi    r0, r3, 4
/* 0327A4 80037D44 5403043E */  clrlwi  r3, r0, 0x10
/* 0327A8 80037D48 38000000 */  li      r0, 0
/* 0327AC 80037D4C 3C6380C3 */  addis   r3, r3, 0x80c3
/* 0327B0 80037D50 5400103A */  slwi    r0, r0, 2
/* 0327B4 80037D54 7C77012E */  stwx    r3, r23, r0
/* 0327B8 80037D58 38000006 */  li      r0, 6
/* 0327BC 80037D5C 3BA00001 */  li      r29, 1
lbl_80037D60:
/* 0327C0 80037D60 3C7F0001 */  addis   r3, r31, 1
/* 0327C4 80037D64 80C32060 */  lwz     r6, 0x2060(r3)
/* 0327C8 80037D68 54C305EF */  rlwinm. r3, r6, 0, 0x17, 0x17
/* 0327CC 80037D6C 41820060 */  beq     lbl_80037DCC
/* 0327D0 80037D70 54C304E7 */  rlwinm. r3, r6, 0, 0x13, 0x13
/* 0327D4 80037D74 4182002C */  beq     lbl_80037DA0
/* 0327D8 80037D78 5403A814 */  slwi    r3, r0, 0x15
/* 0327DC 80037D7C 64667C00 */  oris    r6, r3, 0x7c00
/* 0327E0 80037D80 60C60038 */  ori     r6, r6, 0x38
/* 0327E4 80037D84 5404801E */  slwi    r4, r0, 0x10
/* 0327E8 80037D88 7CC42378 */  or      r4, r6, r4
/* 0327EC 80037D8C 57A3103A */  slwi    r3, r29, 2
/* 0327F0 80037D90 60844800 */  ori     r4, r4, 0x4800
/* 0327F4 80037D94 7C97192E */  stwx    r4, r23, r3
/* 0327F8 80037D98 3BBD0001 */  addi    r29, r29, 1
/* 0327FC 80037D9C 48000030 */  b       lbl_80037DCC
lbl_80037DA0:
/* 032800 80037DA0 2804000A */  cmplwi  r4, 0xa
/* 032804 80037DA4 41800028 */  blt     lbl_80037DCC
/* 032808 80037DA8 5403A814 */  slwi    r3, r0, 0x15
/* 03280C 80037DAC 64667C00 */  oris    r6, r3, 0x7c00
/* 032810 80037DB0 60C60038 */  ori     r6, r6, 0x38
/* 032814 80037DB4 5404801E */  slwi    r4, r0, 0x10
/* 032818 80037DB8 7CC42378 */  or      r4, r6, r4
/* 03281C 80037DBC 57A3103A */  slwi    r3, r29, 2
/* 032820 80037DC0 60844800 */  ori     r4, r4, 0x4800
/* 032824 80037DC4 7C97192E */  stwx    r4, r23, r3
/* 032828 80037DC8 3BBD0001 */  addi    r29, r29, 1
lbl_80037DCC:
/* 03282C 80037DCC 5403801E */  slwi    r3, r0, 0x10
/* 032830 80037DD0 64637CE0 */  oris    r3, r3, 0x7ce0
/* 032834 80037DD4 57A0103A */  slwi    r0, r29, 2
/* 032838 80037DD8 60634214 */  ori     r3, r3, 0x4214
/* 03283C 80037DDC 7C77012E */  stwx    r3, r23, r0
/* 032840 80037DE0 3BBD0001 */  addi    r29, r29, 1
/* 032844 80037DE4 381D0000 */  addi    r0, r29, 0
/* 032848 80037DE8 8061001C */  lwz     r3, 0x1c(r1)
/* 03284C 80037DEC 54A7A814 */  slwi    r7, r5, 0x15
/* 032850 80037DF0 3BBD0001 */  addi    r29, r29, 1
/* 032854 80037DF4 80630000 */  lwz     r3, 0(r3)
/* 032858 80037DF8 389D0000 */  addi    r4, r29, 0
/* 03285C 80037DFC 5400103A */  slwi    r0, r0, 2
/* 032860 80037E00 5463043E */  clrlwi  r3, r3, 0x10
/* 032864 80037E04 646380A7 */  oris    r3, r3, 0x80a7
/* 032868 80037E08 7C77012E */  stwx    r3, r23, r0
/* 03286C 80037E0C 3BBD0001 */  addi    r29, r29, 1
/* 032870 80037E10 387D0000 */  addi    r3, r29, 0
/* 032874 80037E14 80A1001C */  lwz     r5, 0x1c(r1)
/* 032878 80037E18 3BBD0001 */  addi    r29, r29, 1
/* 03287C 80037E1C 57A0103A */  slwi    r0, r29, 2
/* 032880 80037E20 80A50000 */  lwz     r5, 0(r5)
/* 032884 80037E24 5484103A */  slwi    r4, r4, 2
/* 032888 80037E28 64E68007 */  oris    r6, r7, 0x8007
/* 03288C 80037E2C 54A59E38 */  rlwinm  r5, r5, 0x13, 0x18, 0x1c
/* 032890 80037E30 38A50040 */  addi    r5, r5, 0x40
/* 032894 80037E34 7CBF2A14 */  add     r5, r31, r5
/* 032898 80037E38 7CBF2850 */  subf    r5, r31, r5
/* 03289C 80037E3C 3CA590A3 */  addis   r5, r5, 0x90a3
/* 0328A0 80037E40 7CB7212E */  stwx    r5, r23, r4
/* 0328A4 80037E44 5463103A */  slwi    r3, r3, 2
/* 0328A8 80037E48 64E49003 */  oris    r4, r7, 0x9003
/* 0328AC 80037E4C 80A1001C */  lwz     r5, 0x1c(r1)
/* 0328B0 80037E50 3BBD0001 */  addi    r29, r29, 1
/* 0328B4 80037E54 80A50000 */  lwz     r5, 0(r5)
/* 0328B8 80037E58 54A5043E */  clrlwi  r5, r5, 0x10
/* 0328BC 80037E5C 38A50004 */  addi    r5, r5, 4
/* 0328C0 80037E60 7CC52B78 */  or      r5, r6, r5
/* 0328C4 80037E64 7CB7192E */  stwx    r5, r23, r3
/* 0328C8 80037E68 8061001C */  lwz     r3, 0x1c(r1)
/* 0328CC 80037E6C 80630000 */  lwz     r3, 0(r3)
/* 0328D0 80037E70 54639E38 */  rlwinm  r3, r3, 0x13, 0x18, 0x1c
/* 0328D4 80037E74 38630040 */  addi    r3, r3, 0x40
/* 0328D8 80037E78 7C7F1A14 */  add     r3, r31, r3
/* 0328DC 80037E7C 7C7F1850 */  subf    r3, r31, r3
/* 0328E0 80037E80 7C632214 */  add     r3, r3, r4
/* 0328E4 80037E84 38630004 */  addi    r3, r3, 4
/* 0328E8 80037E88 7C77012E */  stwx    r3, r23, r0
/* 0328EC 80037E8C 480001F0 */  b       lbl_8003807C
glabel lbl_80037E90
/* 0328F0 80037E90 5400103A */  slwi    r0, r0, 2
/* 0328F4 80037E94 7CBE0214 */  add     r5, r30, r0
/* 0328F8 80037E98 80050818 */  lwz     r0, 0x818(r5)
/* 0328FC 80037E9C 540505EF */  rlwinm. r5, r0, 0, 0x17, 0x17
/* 032900 80037EA0 41820030 */  beq     lbl_80037ED0
/* 032904 80037EA4 38030040 */  addi    r0, r3, 0x40
/* 032908 80037EA8 7C1F0214 */  add     r0, r31, r0
/* 03290C 80037EAC 7C7F0050 */  subf    r3, r31, r0
/* 032910 80037EB0 38030004 */  addi    r0, r3, 4
/* 032914 80037EB4 5403043E */  clrlwi  r3, r0, 0x10
/* 032918 80037EB8 38000000 */  li      r0, 0
/* 03291C 80037EBC 3C6380E3 */  addis   r3, r3, 0x80e3
/* 032920 80037EC0 5400103A */  slwi    r0, r0, 2
/* 032924 80037EC4 7C77012E */  stwx    r3, r23, r0
/* 032928 80037EC8 38000007 */  li      r0, 7
/* 03292C 80037ECC 3BA00001 */  li      r29, 1
lbl_80037ED0:
/* 032930 80037ED0 3C7F0001 */  addis   r3, r31, 1
/* 032934 80037ED4 80A32060 */  lwz     r5, 0x2060(r3)
/* 032938 80037ED8 54A305EF */  rlwinm. r3, r5, 0, 0x17, 0x17
/* 03293C 80037EDC 41820060 */  beq     lbl_80037F3C
/* 032940 80037EE0 54A304E7 */  rlwinm. r3, r5, 0, 0x13, 0x13
/* 032944 80037EE4 4182002C */  beq     lbl_80037F10
/* 032948 80037EE8 5403A814 */  slwi    r3, r0, 0x15
/* 03294C 80037EEC 64657C00 */  oris    r5, r3, 0x7c00
/* 032950 80037EF0 60A50038 */  ori     r5, r5, 0x38
/* 032954 80037EF4 5404801E */  slwi    r4, r0, 0x10
/* 032958 80037EF8 7CA42378 */  or      r4, r5, r4
/* 03295C 80037EFC 57A3103A */  slwi    r3, r29, 2
/* 032960 80037F00 60844800 */  ori     r4, r4, 0x4800
/* 032964 80037F04 7C97192E */  stwx    r4, r23, r3
/* 032968 80037F08 3BBD0001 */  addi    r29, r29, 1
/* 03296C 80037F0C 48000030 */  b       lbl_80037F3C
lbl_80037F10:
/* 032970 80037F10 2804000A */  cmplwi  r4, 0xa
/* 032974 80037F14 41800028 */  blt     lbl_80037F3C
/* 032978 80037F18 5403A814 */  slwi    r3, r0, 0x15
/* 03297C 80037F1C 64657C00 */  oris    r5, r3, 0x7c00
/* 032980 80037F20 60A50038 */  ori     r5, r5, 0x38
/* 032984 80037F24 5404801E */  slwi    r4, r0, 0x10
/* 032988 80037F28 7CA42378 */  or      r4, r5, r4
/* 03298C 80037F2C 57A3103A */  slwi    r3, r29, 2
/* 032990 80037F30 60844800 */  ori     r4, r4, 0x4800
/* 032994 80037F34 7C97192E */  stwx    r4, r23, r3
/* 032998 80037F38 3BBD0001 */  addi    r29, r29, 1
lbl_80037F3C:
/* 03299C 80037F3C 5403801E */  slwi    r3, r0, 0x10
/* 0329A0 80037F40 64637CE0 */  oris    r3, r3, 0x7ce0
/* 0329A4 80037F44 57A0103A */  slwi    r0, r29, 2
/* 0329A8 80037F48 60634214 */  ori     r3, r3, 0x4214
/* 0329AC 80037F4C 7C77012E */  stwx    r3, r23, r0
/* 0329B0 80037F50 3BBD0001 */  addi    r29, r29, 1
/* 0329B4 80037F54 387D0000 */  addi    r3, r29, 0
/* 0329B8 80037F58 8081001C */  lwz     r4, 0x1c(r1)
/* 0329BC 80037F5C 3BBD0001 */  addi    r29, r29, 1
/* 0329C0 80037F60 57A0103A */  slwi    r0, r29, 2
/* 0329C4 80037F64 80840000 */  lwz     r4, 0(r4)
/* 0329C8 80037F68 5463103A */  slwi    r3, r3, 2
/* 0329CC 80037F6C 3BBD0001 */  addi    r29, r29, 1
/* 0329D0 80037F70 54849E38 */  rlwinm  r4, r4, 0x13, 0x18, 0x1c
/* 0329D4 80037F74 38840040 */  addi    r4, r4, 0x40
/* 0329D8 80037F78 7C9F2214 */  add     r4, r31, r4
/* 0329DC 80037F7C 7C9F2050 */  subf    r4, r31, r4
/* 0329E0 80037F80 3C8480C3 */  addis   r4, r4, 0x80c3
/* 0329E4 80037F84 7C97192E */  stwx    r4, r23, r3
/* 0329E8 80037F88 8061001C */  lwz     r3, 0x1c(r1)
/* 0329EC 80037F8C 80630000 */  lwz     r3, 0(r3)
/* 0329F0 80037F90 5463043E */  clrlwi  r3, r3, 0x10
/* 0329F4 80037F94 646390C7 */  oris    r3, r3, 0x90c7
/* 0329F8 80037F98 7C77012E */  stwx    r3, r23, r0
/* 0329FC 80037F9C 8061001C */  lwz     r3, 0x1c(r1)
/* 032A00 80037FA0 80030000 */  lwz     r0, 0(r3)
/* 032A04 80037FA4 540486FE */  rlwinm  r4, r0, 0x10, 0x1b, 0x1f
/* 032A08 80037FA8 5400967A */  rlwinm  r0, r0, 0x12, 0x19, 0x1d
/* 032A0C 80037FAC 7C7E0214 */  add     r3, r30, r0
/* 032A10 80037FB0 80A30818 */  lwz     r5, 0x818(r3)
/* 032A14 80037FB4 54A005EF */  rlwinm. r0, r5, 0, 0x17, 0x17
/* 032A18 80037FB8 4182002C */  beq     lbl_80037FE4
/* 032A1C 80037FBC 54831838 */  slwi    r3, r4, 3
/* 032A20 80037FC0 38030040 */  addi    r0, r3, 0x40
/* 032A24 80037FC4 7C1F0214 */  add     r0, r31, r0
/* 032A28 80037FC8 7C7F0050 */  subf    r3, r31, r0
/* 032A2C 80037FCC 3C6380C3 */  addis   r3, r3, 0x80c3
/* 032A30 80037FD0 57A0103A */  slwi    r0, r29, 2
/* 032A34 80037FD4 38630004 */  addi    r3, r3, 4
/* 032A38 80037FD8 7C77012E */  stwx    r3, r23, r0
/* 032A3C 80037FDC 38A00006 */  li      r5, 6
/* 032A40 80037FE0 3BBD0001 */  addi    r29, r29, 1
lbl_80037FE4:
/* 032A44 80037FE4 8061001C */  lwz     r3, 0x1c(r1)
/* 032A48 80037FE8 54A4A814 */  slwi    r4, r5, 0x15
/* 032A4C 80037FEC 57A0103A */  slwi    r0, r29, 2
/* 032A50 80037FF0 80630000 */  lwz     r3, 0(r3)
/* 032A54 80037FF4 64849007 */  oris    r4, r4, 0x9007
/* 032A58 80037FF8 3BBD0001 */  addi    r29, r29, 1
/* 032A5C 80037FFC 5463043E */  clrlwi  r3, r3, 0x10
/* 032A60 80038000 38630004 */  addi    r3, r3, 4
/* 032A64 80038004 7C831B78 */  or      r3, r4, r3
/* 032A68 80038008 7C77012E */  stwx    r3, r23, r0
/* 032A6C 8003800C 48000070 */  b       lbl_8003807C
glabel lbl_80038010
/* 032A70 80038010 387E0B88 */  addi    r3, r30, 0xb88
/* 032A74 80038014 4CC63182 */  crclr   6
/* 032A78 80038018 3880143D */  li      r4, 0x143d
/* 032A7C 8003801C 38AD857C */  addi    r5, r13, D_8013525C@sda21
/* 032A80 80038020 48066659 */  bl      OSPanic
/* 032A84 80038024 48000058 */  b       lbl_8003807C
lbl_80038028:
/* 032A88 80038028 56C5843E */  srwi    r5, r22, 0x10
/* 032A8C 8003802C 38800000 */  li      r4, 0
/* 032A90 80038030 56C3043E */  clrlwi  r3, r22, 0x10
/* 032A94 80038034 38000001 */  li      r0, 1
/* 032A98 80038038 64A53CA0 */  oris    r5, r5, 0x3ca0
/* 032A9C 8003803C 5484103A */  slwi    r4, r4, 2
/* 032AA0 80038040 3BA00002 */  li      r29, 2
/* 032AA4 80038044 7CB7212E */  stwx    r5, r23, r4
/* 032AA8 80038048 57A4103A */  slwi    r4, r29, 2
/* 032AAC 8003804C 646360A5 */  oris    r3, r3, 0x60a5
/* 032AB0 80038050 5400103A */  slwi    r0, r0, 2
/* 032AB4 80038054 7C77012E */  stwx    r3, r23, r0
/* 032AB8 80038058 7C772214 */  add     r3, r23, r4
/* 032ABC 8003805C 3B600001 */  li      r27, 1
/* 032AC0 80038060 801F0B40 */  lwz     r0, 0xb40(r31)
/* 032AC4 80038064 3BA00003 */  li      r29, 3
/* 032AC8 80038068 7C030050 */  subf    r0, r3, r0
/* 032ACC 8003806C 540001BA */  rlwinm  r0, r0, 0, 6, 0x1d
/* 032AD0 80038070 64004800 */  oris    r0, r0, 0x4800
/* 032AD4 80038074 60000001 */  ori     r0, r0, 1
/* 032AD8 80038078 7C17212E */  stwx    r0, r23, r4
lbl_8003807C:
/* 032ADC 8003807C 3C7F0001 */  addis   r3, r31, 1
/* 032AE0 80038080 80032060 */  lwz     r0, 0x2060(r3)
/* 032AE4 80038084 540005EF */  rlwinm. r0, r0, 0, 0x17, 0x17
/* 032AE8 80038088 418200D8 */  beq     lbl_80038160
/* 032AEC 8003808C 201D0007 */  subfic  r0, r29, 7
/* 032AF0 80038090 2C000002 */  cmpwi   r0, 2
/* 032AF4 80038094 41800028 */  blt     lbl_800380BC
/* 032AF8 80038098 57A4103A */  slwi    r4, r29, 2
/* 032AFC 8003809C 7C772214 */  add     r3, r23, r4
/* 032B00 800380A0 3817001C */  addi    r0, r23, 0x1c
/* 032B04 800380A4 7C030050 */  subf    r0, r3, r0
/* 032B08 800380A8 5400043E */  clrlwi  r0, r0, 0x10
/* 032B0C 800380AC 64004800 */  oris    r0, r0, 0x4800
/* 032B10 800380B0 3B9D0000 */  addi    r28, r29, 0
/* 032B14 800380B4 7C17212E */  stwx    r0, r23, r4
/* 032B18 800380B8 3BBD0001 */  addi    r29, r29, 1
lbl_800380BC:
/* 032B1C 800380BC 2C1D0006 */  cmpwi   r29, 6
/* 032B20 800380C0 207D0007 */  subfic  r3, r29, 7
/* 032B24 800380C4 3C806000 */  lis     r4, 0x6000
/* 032B28 800380C8 41810090 */  bgt     lbl_80038158
/* 032B2C 800380CC 5460E8FF */  rlwinm. r0, r3, 0x1d, 3, 0x1f
/* 032B30 800380D0 7C0903A6 */  mtctr   r0
/* 032B34 800380D4 41820070 */  beq     lbl_80038144
lbl_800380D8:
/* 032B38 800380D8 57A0103A */  slwi    r0, r29, 2
/* 032B3C 800380DC 7C97012E */  stwx    r4, r23, r0
/* 032B40 800380E0 3BBD0001 */  addi    r29, r29, 1
/* 032B44 800380E4 57A0103A */  slwi    r0, r29, 2
/* 032B48 800380E8 7C97012E */  stwx    r4, r23, r0
/* 032B4C 800380EC 3BBD0001 */  addi    r29, r29, 1
/* 032B50 800380F0 57A0103A */  slwi    r0, r29, 2
/* 032B54 800380F4 7C97012E */  stwx    r4, r23, r0
/* 032B58 800380F8 3BBD0001 */  addi    r29, r29, 1
/* 032B5C 800380FC 57A0103A */  slwi    r0, r29, 2
/* 032B60 80038100 7C97012E */  stwx    r4, r23, r0
/* 032B64 80038104 3BBD0001 */  addi    r29, r29, 1
/* 032B68 80038108 57A0103A */  slwi    r0, r29, 2
/* 032B6C 8003810C 7C97012E */  stwx    r4, r23, r0
/* 032B70 80038110 3BBD0001 */  addi    r29, r29, 1
/* 032B74 80038114 57A0103A */  slwi    r0, r29, 2
/* 032B78 80038118 7C97012E */  stwx    r4, r23, r0
/* 032B7C 8003811C 3BBD0001 */  addi    r29, r29, 1
/* 032B80 80038120 57A0103A */  slwi    r0, r29, 2
/* 032B84 80038124 7C97012E */  stwx    r4, r23, r0
/* 032B88 80038128 3BBD0001 */  addi    r29, r29, 1
/* 032B8C 8003812C 57A0103A */  slwi    r0, r29, 2
/* 032B90 80038130 7C97012E */  stwx    r4, r23, r0
/* 032B94 80038134 3BBD0001 */  addi    r29, r29, 1
/* 032B98 80038138 4200FFA0 */  bdnz    lbl_800380D8
/* 032B9C 8003813C 70630007 */  andi.   r3, r3, 7
/* 032BA0 80038140 41820018 */  beq     lbl_80038158
lbl_80038144:
/* 032BA4 80038144 7C6903A6 */  mtctr   r3
lbl_80038148:
/* 032BA8 80038148 57A0103A */  slwi    r0, r29, 2
/* 032BAC 8003814C 7C97012E */  stwx    r4, r23, r0
/* 032BB0 80038150 3BBD0001 */  addi    r29, r29, 1
/* 032BB4 80038154 4200FFF4 */  bdnz    lbl_80038148
lbl_80038158:
/* 032BB8 80038158 3BC00007 */  li      r30, 7
/* 032BBC 8003815C 480000D4 */  b       lbl_80038230
lbl_80038160:
/* 032BC0 80038160 201D0006 */  subfic  r0, r29, 6
/* 032BC4 80038164 2C000002 */  cmpwi   r0, 2
/* 032BC8 80038168 41800028 */  blt     lbl_80038190
/* 032BCC 8003816C 57A4103A */  slwi    r4, r29, 2
/* 032BD0 80038170 7C772214 */  add     r3, r23, r4
/* 032BD4 80038174 38170018 */  addi    r0, r23, 0x18
/* 032BD8 80038178 7C030050 */  subf    r0, r3, r0
/* 032BDC 8003817C 5400043E */  clrlwi  r0, r0, 0x10
/* 032BE0 80038180 64004800 */  oris    r0, r0, 0x4800
/* 032BE4 80038184 3B9D0000 */  addi    r28, r29, 0
/* 032BE8 80038188 7C17212E */  stwx    r0, r23, r4
/* 032BEC 8003818C 3BBD0001 */  addi    r29, r29, 1
lbl_80038190:
/* 032BF0 80038190 2C1D0005 */  cmpwi   r29, 5
/* 032BF4 80038194 207D0006 */  subfic  r3, r29, 6
/* 032BF8 80038198 3C806000 */  lis     r4, 0x6000
/* 032BFC 8003819C 41810090 */  bgt     lbl_8003822C
/* 032C00 800381A0 5460E8FF */  rlwinm. r0, r3, 0x1d, 3, 0x1f
/* 032C04 800381A4 7C0903A6 */  mtctr   r0
/* 032C08 800381A8 41820070 */  beq     lbl_80038218
lbl_800381AC:
/* 032C0C 800381AC 57A0103A */  slwi    r0, r29, 2
/* 032C10 800381B0 7C97012E */  stwx    r4, r23, r0
/* 032C14 800381B4 3BBD0001 */  addi    r29, r29, 1
/* 032C18 800381B8 57A0103A */  slwi    r0, r29, 2
/* 032C1C 800381BC 7C97012E */  stwx    r4, r23, r0
/* 032C20 800381C0 3BBD0001 */  addi    r29, r29, 1
/* 032C24 800381C4 57A0103A */  slwi    r0, r29, 2
/* 032C28 800381C8 7C97012E */  stwx    r4, r23, r0
/* 032C2C 800381CC 3BBD0001 */  addi    r29, r29, 1
/* 032C30 800381D0 57A0103A */  slwi    r0, r29, 2
/* 032C34 800381D4 7C97012E */  stwx    r4, r23, r0
/* 032C38 800381D8 3BBD0001 */  addi    r29, r29, 1
/* 032C3C 800381DC 57A0103A */  slwi    r0, r29, 2
/* 032C40 800381E0 7C97012E */  stwx    r4, r23, r0
/* 032C44 800381E4 3BBD0001 */  addi    r29, r29, 1
/* 032C48 800381E8 57A0103A */  slwi    r0, r29, 2
/* 032C4C 800381EC 7C97012E */  stwx    r4, r23, r0
/* 032C50 800381F0 3BBD0001 */  addi    r29, r29, 1
/* 032C54 800381F4 57A0103A */  slwi    r0, r29, 2
/* 032C58 800381F8 7C97012E */  stwx    r4, r23, r0
/* 032C5C 800381FC 3BBD0001 */  addi    r29, r29, 1
/* 032C60 80038200 57A0103A */  slwi    r0, r29, 2
/* 032C64 80038204 7C97012E */  stwx    r4, r23, r0
/* 032C68 80038208 3BBD0001 */  addi    r29, r29, 1
/* 032C6C 8003820C 4200FFA0 */  bdnz    lbl_800381AC
/* 032C70 80038210 70630007 */  andi.   r3, r3, 7
/* 032C74 80038214 41820018 */  beq     lbl_8003822C
lbl_80038218:
/* 032C78 80038218 7C6903A6 */  mtctr   r3
lbl_8003821C:
/* 032C7C 8003821C 57A0103A */  slwi    r0, r29, 2
/* 032C80 80038220 7C97012E */  stwx    r4, r23, r0
/* 032C84 80038224 3BBD0001 */  addi    r29, r29, 1
/* 032C88 80038228 4200FFF4 */  bdnz    lbl_8003821C
lbl_8003822C:
/* 032C8C 8003822C 3BC00006 */  li      r30, 6
lbl_80038230:
/* 032C90 80038230 2C1B0000 */  cmpwi   r27, 0
/* 032C94 80038234 40820090 */  bne     lbl_800382C4
/* 032C98 80038238 807A0000 */  lwz     r3, 0(r26)
/* 032C9C 8003823C 3C03C740 */  addis   r0, r3, 0xc740
/* 032CA0 80038240 28000000 */  cmplwi  r0, 0
/* 032CA4 80038244 40820080 */  bne     lbl_800382C4
/* 032CA8 80038248 801A0004 */  lwz     r0, 4(r26)
/* 032CAC 8003824C 7C00C000 */  cmpw    r0, r24
/* 032CB0 80038250 40820074 */  bne     lbl_800382C4
/* 032CB4 80038254 381A0008 */  addi    r0, r26, 8
/* 032CB8 80038258 7C1A0050 */  subf    r0, r26, r0
/* 032CBC 8003825C 5400043E */  clrlwi  r0, r0, 0x10
/* 032CC0 80038260 64004800 */  oris    r0, r0, 0x4800
/* 032CC4 80038264 901A0000 */  stw     r0, 0(r26)
/* 032CC8 80038268 3C006000 */  lis     r0, 0x6000
/* 032CCC 8003826C 387A0000 */  addi    r3, r26, 0
/* 032CD0 80038270 901A0004 */  stw     r0, 4(r26)
/* 032CD4 80038274 38800008 */  li      r4, 8
/* 032CD8 80038278 48065535 */  bl      DCStoreRange
/* 032CDC 8003827C 387A0000 */  addi    r3, r26, 0
/* 032CE0 80038280 38800008 */  li      r4, 8
/* 032CE4 80038284 480655B1 */  bl      ICInvalidateRange
/* 032CE8 80038288 2C1C0000 */  cmpwi   r28, 0
/* 032CEC 8003828C 41820020 */  beq     lbl_800382AC
/* 032CF0 80038290 5780103A */  slwi    r0, r28, 2
/* 032CF4 80038294 7C770214 */  add     r3, r23, r0
/* 032CF8 80038298 38190008 */  addi    r0, r25, 8
/* 032CFC 8003829C 7C030050 */  subf    r0, r3, r0
/* 032D00 800382A0 5400043E */  clrlwi  r0, r0, 0x10
/* 032D04 800382A4 64004800 */  oris    r0, r0, 0x4800
/* 032D08 800382A8 90030000 */  stw     r0, 0(r3)
lbl_800382AC:
/* 032D0C 800382AC 3C606000 */  lis     r3, 0x6000
/* 032D10 800382B0 90790000 */  stw     r3, 0(r25)
/* 032D14 800382B4 3800FFFF */  li      r0, -1
/* 032D18 800382B8 3BDE0002 */  addi    r30, r30, 2
/* 032D1C 800382BC 90790004 */  stw     r3, 4(r25)
/* 032D20 800382C0 901F002C */  stw     r0, 0x2c(r31)
lbl_800382C4:
/* 032D24 800382C4 57D6103A */  slwi    r22, r30, 2
/* 032D28 800382C8 38770000 */  addi    r3, r23, 0
/* 032D2C 800382CC 38960000 */  addi    r4, r22, 0
/* 032D30 800382D0 480654DD */  bl      DCStoreRange
/* 032D34 800382D4 38770000 */  addi    r3, r23, 0
/* 032D38 800382D8 38960000 */  addi    r4, r22, 0
/* 032D3C 800382DC 48065559 */  bl      ICInvalidateRange
/* 032D40 800382E0 7EE3BB78 */  mr      r3, r23
/* 032D44 800382E4 BAC10020 */  lmw     r22, 0x20(r1)
/* 032D48 800382E8 8001004C */  lwz     r0, 0x4c(r1)
/* 032D4C 800382EC 38210048 */  addi    r1, r1, 0x48
/* 032D50 800382F0 7C0803A6 */  mtlr    r0
/* 032D54 800382F4 4E800020 */  blr     