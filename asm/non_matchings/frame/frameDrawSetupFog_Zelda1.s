glabel frameDrawSetupFog_Zelda1
/* 0270DC 8002C67C 7C0802A6 */  mflr    r0
/* 0270E0 8002C680 90010004 */  stw     r0, 4(r1)
/* 0270E4 8002C684 9421FFC0 */  stwu    r1, -0x40(r1)
/* 0270E8 8002C688 80030090 */  lwz     r0, 0x90(r3)
/* 0270EC 8002C68C 3C830004 */  addis   r4, r3, 4
/* 0270F0 8002C690 8104C4D0 */  lwz     r8, -0x3b30(r4)
/* 0270F4 8002C694 3CC04330 */  lis     r6, 0x4330
/* 0270F8 8002C698 5405843E */  srwi    r5, r0, 0x10
/* 0270FC 8002C69C 5400043E */  clrlwi  r0, r0, 0x10
/* 027100 8002C6A0 C8428110 */  lfd     f2, D_80135E10@sda21(r2)
/* 027104 8002C6A4 7CA50734 */  extsh   r5, r5
/* 027108 8002C6A8 7C000734 */  extsh   r0, r0
/* 02710C 8002C6AC 6CA78000 */  xoris   r7, r5, 0x8000
/* 027110 8002C6B0 6C058000 */  xoris   r5, r0, 0x8000
/* 027114 8002C6B4 90E1003C */  stw     r7, 0x3c(r1)
/* 027118 8002C6B8 3C080001 */  addis   r0, r8, 1
/* 02711C 8002C6BC 90A10034 */  stw     r5, 0x34(r1)
/* 027120 8002C6C0 2800FFFF */  cmplwi  r0, 0xffff
/* 027124 8002C6C4 90C10038 */  stw     r6, 0x38(r1)
/* 027128 8002C6C8 90C10030 */  stw     r6, 0x30(r1)
/* 02712C 8002C6CC C8210038 */  lfd     f1, 0x38(r1)
/* 027130 8002C6D0 C8010030 */  lfd     f0, 0x30(r1)
/* 027134 8002C6D4 ECC11028 */  fsubs   f6, f1, f2
/* 027138 8002C6D8 ECE01028 */  fsubs   f7, f0, f2
/* 02713C 8002C6DC 41820020 */  beq     lbl_8002C6FC
/* 027140 8002C6E0 1C080024 */  mulli   r0, r8, 0x24
/* 027144 8002C6E4 C02281D8 */  lfs     f1, D_80135ED8@sda21(r2)
/* 027148 8002C6E8 7C840214 */  add     r4, r4, r0
/* 02714C 8002C6EC C004C830 */  lfs     f0, -0x37d0(r4)
/* 027150 8002C6F0 C044C834 */  lfs     f2, -0x37cc(r4)
/* 027154 8002C6F4 EC010032 */  fmuls   f0, f1, f0
/* 027158 8002C6F8 4800000C */  b       lbl_8002C704
lbl_8002C6FC:
/* 02715C 8002C6FC C04281CC */  lfs     f2, D_80135ECC@sda21(r2)
/* 027160 8002C700 C0028138 */  lfs     f0, D_80135E38@sda21(r2)
lbl_8002C704:
/* 027164 8002C704 C0228100 */  lfs     f1, D_80135E00@sda21(r2)
/* 027168 8002C708 FC013000 */  fcmpu   cr0, f1, f6
/* 02716C 8002C70C 4082002C */  bne     lbl_8002C738
/* 027170 8002C710 3C630004 */  addis   r3, r3, 4
/* 027174 8002C714 FC400890 */  fmr     f2, f1
/* 027178 8002C718 8003D124 */  lwz     r0, -0x2edc(r3)
/* 02717C 8002C71C FC600890 */  fmr     f3, f1
/* 027180 8002C720 C08281C8 */  lfs     f4, D_80135EC8@sda21(r2)
/* 027184 8002C724 38810014 */  addi    r4, r1, 0x14
/* 027188 8002C728 90010014 */  stw     r0, 0x14(r1)
/* 02718C 8002C72C 38600000 */  li      r3, 0
/* 027190 8002C730 48081811 */  bl      GXSetFog
/* 027194 8002C734 480002CC */  b       lbl_8002CA00
lbl_8002C738:
/* 027198 8002C738 FC073000 */  fcmpu   cr0, f7, f6
/* 02719C 8002C73C 40820030 */  bne     lbl_8002C76C
/* 0271A0 8002C740 EC273024 */  fdivs   f1, f7, f6
/* 0271A4 8002C744 C0028230 */  lfs     f0, D_80135F30@sda21(r2)
/* 0271A8 8002C748 C0428138 */  lfs     f2, D_80135E38@sda21(r2)
/* 0271AC 8002C74C 38A00002 */  li      r5, 2
/* 0271B0 8002C750 C06281E8 */  lfs     f3, D_80135EE8@sda21(r2)
/* 0271B4 8002C754 EC220828 */  fsubs   f1, f2, f1
/* 0271B8 8002C758 C08281C8 */  lfs     f4, D_80135EC8@sda21(r2)
/* 0271BC 8002C75C EC003024 */  fdivs   f0, f0, f6
/* 0271C0 8002C760 EC230072 */  fmuls   f1, f3, f1
/* 0271C4 8002C764 EC40082A */  fadds   f2, f0, f1
/* 0271C8 8002C768 4800022C */  b       lbl_8002C994
lbl_8002C76C:
/* 0271CC 8002C76C C0228234 */  lfs     f1, D_80135F34@sda21(r2)
/* 0271D0 8002C770 FC013800 */  fcmpu   cr0, f1, f7
/* 0271D4 8002C774 40820040 */  bne     lbl_8002C7B4
/* 0271D8 8002C778 C0228238 */  lfs     f1, D_80135F38@sda21(r2)
/* 0271DC 8002C77C FC013000 */  fcmpu   cr0, f1, f6
/* 0271E0 8002C780 40820034 */  bne     lbl_8002C7B4
/* 0271E4 8002C784 C022823C */  lfs     f1, D_80135F3C@sda21(r2)
/* 0271E8 8002C788 FC011000 */  fcmpu   cr0, f1, f2
/* 0271EC 8002C78C 40820028 */  bne     lbl_8002C7B4
/* 0271F0 8002C790 ECC20028 */  fsubs   f6, f2, f0
/* 0271F4 8002C794 C0228240 */  lfs     f1, D_80135F40@sda21(r2)
/* 0271F8 8002C798 C0A28244 */  lfs     f5, D_80135F44@sda21(r2)
/* 0271FC 8002C79C FC600090 */  fmr     f3, f0
/* 027200 8002C7A0 FC801090 */  fmr     f4, f2
/* 027204 8002C7A4 EC2101BA */  fmadds  f1, f1, f6, f0
/* 027208 8002C7A8 38A00004 */  li      r5, 4
/* 02720C 8002C7AC EC4501BA */  fmadds  f2, f5, f6, f0
/* 027210 8002C7B0 480001E4 */  b       lbl_8002C994
lbl_8002C7B4:
/* 027214 8002C7B4 C0228248 */  lfs     f1, D_80135F48@sda21(r2)
/* 027218 8002C7B8 FC013800 */  fcmpu   cr0, f1, f7
/* 02721C 8002C7BC 4082003C */  bne     lbl_8002C7F8
/* 027220 8002C7C0 C022824C */  lfs     f1, D_80135F4C@sda21(r2)
/* 027224 8002C7C4 FC013000 */  fcmpu   cr0, f1, f6
/* 027228 8002C7C8 40820030 */  bne     lbl_8002C7F8
/* 02722C 8002C7CC C0228200 */  lfs     f1, D_80135F00@sda21(r2)
/* 027230 8002C7D0 FC011000 */  fcmpu   cr0, f1, f2
/* 027234 8002C7D4 40820024 */  bne     lbl_8002C7F8
/* 027238 8002C7D8 ECA20028 */  fsubs   f5, f2, f0
/* 02723C 8002C7DC C02281D8 */  lfs     f1, D_80135ED8@sda21(r2)
/* 027240 8002C7E0 FC600090 */  fmr     f3, f0
/* 027244 8002C7E4 38A00004 */  li      r5, 4
/* 027248 8002C7E8 FC801090 */  fmr     f4, f2
/* 02724C 8002C7EC EC21017A */  fmadds  f1, f1, f5, f0
/* 027250 8002C7F0 EC45002A */  fadds   f2, f5, f0
/* 027254 8002C7F4 480001A0 */  b       lbl_8002C994
lbl_8002C7F8:
/* 027258 8002C7F8 808D8920 */  lwz     r4, gpSystem@sda21(r13)
/* 02725C 8002C7FC 80040020 */  lwz     r0, 0x20(r4)
/* 027260 8002C800 2C000005 */  cmpwi   r0, 5
/* 027264 8002C804 40820048 */  bne     lbl_8002C84C
/* 027268 8002C808 C0228250 */  lfs     f1, D_80135F50@sda21(r2)
/* 02726C 8002C80C FC013800 */  fcmpu   cr0, f1, f7
/* 027270 8002C810 4082003C */  bne     lbl_8002C84C
/* 027274 8002C814 C0228254 */  lfs     f1, D_80135F54@sda21(r2)
/* 027278 8002C818 FC013000 */  fcmpu   cr0, f1, f6
/* 02727C 8002C81C 40820030 */  bne     lbl_8002C84C
/* 027280 8002C820 C0228200 */  lfs     f1, D_80135F00@sda21(r2)
/* 027284 8002C824 FC011000 */  fcmpu   cr0, f1, f2
/* 027288 8002C828 40820024 */  bne     lbl_8002C84C
/* 02728C 8002C82C ECA20028 */  fsubs   f5, f2, f0
/* 027290 8002C830 C0228258 */  lfs     f1, D_80135F58@sda21(r2)
/* 027294 8002C834 FC600090 */  fmr     f3, f0
/* 027298 8002C838 38A00004 */  li      r5, 4
/* 02729C 8002C83C FC801090 */  fmr     f4, f2
/* 0272A0 8002C840 EC21017A */  fmadds  f1, f1, f5, f0
/* 0272A4 8002C844 EC45002A */  fadds   f2, f5, f0
/* 0272A8 8002C848 4800014C */  b       lbl_8002C994
lbl_8002C84C:
/* 0272AC 8002C84C 2C000005 */  cmpwi   r0, 5
/* 0272B0 8002C850 40820048 */  bne     lbl_8002C898
/* 0272B4 8002C854 C022825C */  lfs     f1, D_80135F5C@sda21(r2)
/* 0272B8 8002C858 FC013800 */  fcmpu   cr0, f1, f7
/* 0272BC 8002C85C 4082003C */  bne     lbl_8002C898
/* 0272C0 8002C860 C0228260 */  lfs     f1, D_80135F60@sda21(r2)
/* 0272C4 8002C864 FC013000 */  fcmpu   cr0, f1, f6
/* 0272C8 8002C868 40820030 */  bne     lbl_8002C898
/* 0272CC 8002C86C C0228200 */  lfs     f1, D_80135F00@sda21(r2)
/* 0272D0 8002C870 FC011000 */  fcmpu   cr0, f1, f2
/* 0272D4 8002C874 40820024 */  bne     lbl_8002C898
/* 0272D8 8002C878 ECA20028 */  fsubs   f5, f2, f0
/* 0272DC 8002C87C C0228258 */  lfs     f1, D_80135F58@sda21(r2)
/* 0272E0 8002C880 FC600090 */  fmr     f3, f0
/* 0272E4 8002C884 38A00004 */  li      r5, 4
/* 0272E8 8002C888 FC801090 */  fmr     f4, f2
/* 0272EC 8002C88C EC21017A */  fmadds  f1, f1, f5, f0
/* 0272F0 8002C890 EC45002A */  fadds   f2, f5, f0
/* 0272F4 8002C894 48000100 */  b       lbl_8002C994
lbl_8002C898:
/* 0272F8 8002C898 C0228230 */  lfs     f1, D_80135F30@sda21(r2)
/* 0272FC 8002C89C ECA20028 */  fsubs   f5, f2, f0
/* 027300 8002C8A0 C0828264 */  lfs     f4, D_80135F64@sda21(r2)
/* 027304 8002C8A4 ECC13024 */  fdivs   f6, f1, f6
/* 027308 8002C8A8 C06281E8 */  lfs     f3, D_80135EE8@sda21(r2)
/* 02730C 8002C8AC C0228268 */  lfs     f1, D_80135F68@sda21(r2)
/* 027310 8002C8B0 ECC701B2 */  fmuls   f6, f7, f6
/* 027314 8002C8B4 EC66193C */  fnmsubs f3, f6, f4, f3
/* 027318 8002C8B8 FC030840 */  fcmpo   cr0, f3, f1
/* 02731C 8002C8BC 4C401382 */  cror    2, 0, 2
/* 027320 8002C8C0 40820010 */  bne     lbl_8002C8D0
/* 027324 8002C8C4 C0E28100 */  lfs     f7, D_80135E00@sda21(r2)
/* 027328 8002C8C8 C122826C */  lfs     f9, D_80135F6C@sda21(r2)
/* 02732C 8002C8CC 4800003C */  b       lbl_8002C908
lbl_8002C8D0:
/* 027330 8002C8D0 ECC30828 */  fsubs   f6, f3, f1
/* 027334 8002C8D4 C0628270 */  lfs     f3, D_80135F70@sda21(r2)
/* 027338 8002C8D8 C0828278 */  lfs     f4, D_80135F78@sda21(r2)
/* 02733C 8002C8DC C022827C */  lfs     f1, D_80135F7C@sda21(r2)
/* 027340 8002C8E0 ECE61824 */  fdivs   f7, f6, f3
/* 027344 8002C8E4 C0628274 */  lfs     f3, D_80135F74@sda21(r2)
/* 027348 8002C8E8 EC8401F2 */  fmuls   f4, f4, f7
/* 02734C 8002C8EC EC2101F2 */  fmuls   f1, f1, f7
/* 027350 8002C8F0 EC8401F2 */  fmuls   f4, f4, f7
/* 027354 8002C8F4 EC2101F2 */  fmuls   f1, f1, f7
/* 027358 8002C8F8 EC870132 */  fmuls   f4, f7, f4
/* 02735C 8002C8FC EC270072 */  fmuls   f1, f7, f1
/* 027360 8002C900 ED27193A */  fmadds  f9, f7, f4, f3
/* 027364 8002C904 ECE70072 */  fmuls   f7, f7, f1
lbl_8002C908:
/* 027368 8002C908 C0228200 */  lfs     f1, D_80135F00@sda21(r2)
/* 02736C 8002C90C ED400032 */  fmuls   f10, f0, f0
/* 027370 8002C910 C0C28138 */  lfs     f6, D_80135E38@sda21(r2)
/* 027374 8002C914 ED020824 */  fdivs   f8, f2, f1
/* 027378 8002C918 C08281D8 */  lfs     f4, D_80135ED8@sda21(r2)
/* 02737C 8002C91C C0628280 */  lfs     f3, D_80135F80@sda21(r2)
/* 027380 8002C920 C8228288 */  lfd     f1, D_80135F88@sda21(r2)
/* 027384 8002C924 ED064028 */  fsubs   f8, f6, f8
/* 027388 8002C928 ED080232 */  fmuls   f8, f8, f8
/* 02738C 8002C92C ED080232 */  fmuls   f8, f8, f8
/* 027390 8002C930 ED080232 */  fmuls   f8, f8, f8
/* 027394 8002C934 EC840232 */  fmuls   f4, f4, f8
/* 027398 8002C938 ED0800F2 */  fmuls   f8, f8, f3
/* 02739C 8002C93C ED4A0132 */  fmuls   f10, f10, f4
/* 0273A0 8002C940 ED08302A */  fadds   f8, f8, f6
/* 0273A4 8002C944 FD4A0072 */  fmul    f10, f10, f1
/* 0273A8 8002C948 ED290232 */  fmuls   f9, f9, f8
/* 0273AC 8002C94C FD405018 */  frsp    f10, f10
/* 0273B0 8002C950 FC093040 */  fcmpo   cr0, f9, f6
/* 0273B4 8002C954 ED4A302A */  fadds   f10, f10, f6
/* 0273B8 8002C958 40810008 */  ble     lbl_8002C960
/* 0273BC 8002C95C FD203090 */  fmr     f9, f6
lbl_8002C960:
/* 0273C0 8002C960 ECE702B2 */  fmuls   f7, f7, f10
/* 0273C4 8002C964 C0228138 */  lfs     f1, D_80135E38@sda21(r2)
/* 0273C8 8002C968 FC070840 */  fcmpo   cr0, f7, f1
/* 0273CC 8002C96C 40810008 */  ble     lbl_8002C974
/* 0273D0 8002C970 FCE00890 */  fmr     f7, f1
lbl_8002C974:
/* 0273D4 8002C974 FC074840 */  fcmpo   cr0, f7, f9
/* 0273D8 8002C978 40810008 */  ble     lbl_8002C980
/* 0273DC 8002C97C FCE04890 */  fmr     f7, f9
lbl_8002C980:
/* 0273E0 8002C980 FC600090 */  fmr     f3, f0
/* 0273E4 8002C984 38A00004 */  li      r5, 4
/* 0273E8 8002C988 FC801090 */  fmr     f4, f2
/* 0273EC 8002C98C EC27017A */  fmadds  f1, f7, f5, f0
/* 0273F0 8002C990 EC49017A */  fmadds  f2, f9, f5, f0
lbl_8002C994:
/* 0273F4 8002C994 808300A0 */  lwz     r4, 0xa0(r3)
/* 0273F8 8002C998 548037BE */  rlwinm  r0, r4, 6, 0x1e, 0x1f
/* 0273FC 8002C99C 28000001 */  cmplwi  r0, 1
/* 027400 8002C9A0 4182001C */  beq     lbl_8002C9BC
/* 027404 8002C9A4 548017BE */  srwi    r0, r4, 0x1e
/* 027408 8002C9A8 28000003 */  cmplwi  r0, 3
/* 02740C 8002C9AC 41820010 */  beq     lbl_8002C9BC
/* 027410 8002C9B0 548057BE */  rlwinm  r0, r4, 0xa, 0x1e, 0x1f
/* 027414 8002C9B4 28000003 */  cmplwi  r0, 3
/* 027418 8002C9B8 40820020 */  bne     lbl_8002C9D8
lbl_8002C9BC:
/* 02741C 8002C9BC 3C630004 */  addis   r3, r3, 4
/* 027420 8002C9C0 8003D124 */  lwz     r0, -0x2edc(r3)
/* 027424 8002C9C4 38810010 */  addi    r4, r1, 0x10
/* 027428 8002C9C8 7CA32B78 */  mr      r3, r5
/* 02742C 8002C9CC 90010010 */  stw     r0, 0x10(r1)
/* 027430 8002C9D0 48081571 */  bl      GXSetFog
/* 027434 8002C9D4 4800002C */  b       lbl_8002CA00
lbl_8002C9D8:
/* 027438 8002C9D8 C0228100 */  lfs     f1, D_80135E00@sda21(r2)
/* 02743C 8002C9DC 3C630004 */  addis   r3, r3, 4
/* 027440 8002C9E0 8003D124 */  lwz     r0, -0x2edc(r3)
/* 027444 8002C9E4 3881000C */  addi    r4, r1, 0xc
/* 027448 8002C9E8 FC400890 */  fmr     f2, f1
/* 02744C 8002C9EC FC600890 */  fmr     f3, f1
/* 027450 8002C9F0 C08281C8 */  lfs     f4, D_80135EC8@sda21(r2)
/* 027454 8002C9F4 9001000C */  stw     r0, 0xc(r1)
/* 027458 8002C9F8 38600000 */  li      r3, 0
/* 02745C 8002C9FC 48081545 */  bl      GXSetFog
lbl_8002CA00:
/* 027460 8002CA00 38600001 */  li      r3, 1
/* 027464 8002CA04 80010044 */  lwz     r0, 0x44(r1)
/* 027468 8002CA08 38210040 */  addi    r1, r1, 0x40
/* 02746C 8002CA0C 7C0803A6 */  mtlr    r0
/* 027470 8002CA10 4E800020 */  blr     
