glabel frameEnd
/* 020418 800259B8 7C0802A6 */  mflr    r0
/* 02041C 800259BC 90010004 */  stw     r0, 4(r1)
/* 020420 800259C0 9421FFE0 */  stwu    r1, -0x20(r1)
/* 020424 800259C4 93E1001C */  stw     r31, 0x1c(r1)
/* 020428 800259C8 93C10018 */  stw     r30, 0x18(r1)
/* 02042C 800259CC 93A10014 */  stw     r29, 0x14(r1)
/* 020430 800259D0 7C7E1B78 */  mr      r30, r3
/* 020434 800259D4 800D89AC */  lwz     r0, gbFrameBegin@sda21(r13)
/* 020438 800259D8 806D8920 */  lwz     r3, gpSystem@sda21(r13)
/* 02043C 800259DC 2C000000 */  cmpwi   r0, 0
/* 020440 800259E0 83E30024 */  lwz     r31, 0x24(r3)
/* 020444 800259E4 41820014 */  beq     lbl_800259F8
/* 020448 800259E8 3C60800F */  lis     r3, D_800EB1B8@ha
/* 02044C 800259EC 4CC63182 */  crclr   6
/* 020450 800259F0 3863B1B8 */  addi    r3, r3, D_800EB1B8@l
/* 020454 800259F4 48078C05 */  bl      OSReport
lbl_800259F8:
/* 020458 800259F8 38000001 */  li      r0, 1
/* 02045C 800259FC 900D89AC */  stw     r0, gbFrameBegin@sda21(r13)
/* 020460 80025A00 7FC6F378 */  mr      r6, r30
/* 020464 80025A04 38E00000 */  li      r7, 0
/* 020468 80025A08 48000004 */  b       lbl_80025A0C
lbl_80025A0C:
/* 02046C 80025A0C 3C7E0004 */  addis   r3, r30, 4
/* 020470 80025A10 48000004 */  b       lbl_80025A14
lbl_80025A14:
/* 020474 80025A14 48000024 */  b       lbl_80025A38
lbl_80025A18:
/* 020478 80025A18 3CA60004 */  addis   r5, r6, 4
/* 02047C 80025A1C 8085C820 */  lwz     r4, -0x37e0(r5)
/* 020480 80025A20 2C040000 */  cmpwi   r4, 0
/* 020484 80025A24 4180000C */  blt     lbl_80025A30
/* 020488 80025A28 3804FFFF */  addi    r0, r4, -1
/* 02048C 80025A2C 9005C820 */  stw     r0, -0x37e0(r5)
lbl_80025A30:
/* 020490 80025A30 38C60024 */  addi    r6, r6, 0x24
/* 020494 80025A34 38E70001 */  addi    r7, r7, 1
lbl_80025A38:
/* 020498 80025A38 8003C4C8 */  lwz     r0, -0x3b38(r3)
/* 02049C 80025A3C 7C070000 */  cmpw    r7, r0
/* 0204A0 80025A40 4180FFD8 */  blt     lbl_80025A18
/* 0204A4 80025A44 807E0088 */  lwz     r3, 0x88(r30)
/* 0204A8 80025A48 38000001 */  li      r0, 1
/* 0204AC 80025A4C 38630001 */  addi    r3, r3, 1
/* 0204B0 80025A50 907E0088 */  stw     r3, 0x88(r30)
/* 0204B4 80025A54 900D89A8 */  stw     r0, gbFrameValid@sda21(r13)
/* 0204B8 80025A58 801E00D8 */  lwz     r0, 0xd8(r30)
/* 0204BC 80025A5C 2C000000 */  cmpwi   r0, 0
/* 0204C0 80025A60 41820054 */  beq     lbl_80025AB4
/* 0204C4 80025A64 3C608011 */  lis     r3, sTempZBuf@ha
/* 0204C8 80025A68 380385C0 */  addi    r0, r3, sTempZBuf@l
/* 0204CC 80025A6C 7C1D0378 */  mr      r29, r0
/* 0204D0 80025A70 38600000 */  li      r3, 0
/* 0204D4 80025A74 38800000 */  li      r4, 0
/* 0204D8 80025A78 38A00280 */  li      r5, 0x280
/* 0204DC 80025A7C 38C001E0 */  li      r6, 0x1e0
/* 0204E0 80025A80 48085E5D */  bl      GXSetTexCopySrc
/* 0204E4 80025A84 38600140 */  li      r3, 0x140
/* 0204E8 80025A88 388000F0 */  li      r4, 0xf0
/* 0204EC 80025A8C 38A00013 */  li      r5, 0x13
/* 0204F0 80025A90 38C00001 */  li      r6, 1
/* 0204F4 80025A94 48085EF9 */  bl      GXSetTexCopyDst
/* 0204F8 80025A98 7FA3EB78 */  mr      r3, r29
/* 0204FC 80025A9C 38800000 */  li      r4, 0
/* 020500 80025AA0 48086799 */  bl      GXCopyTex
/* 020504 80025AA4 3C800002 */  lis     r4, 2
/* 020508 80025AA8 7FA3EB78 */  mr      r3, r29
/* 02050C 80025AAC 38845800 */  addi    r4, r4, 0x5800
/* 020510 80025AB0 48077CA1 */  bl      DCInvalidateRange
lbl_80025AB4:
/* 020514 80025AB4 806D8920 */  lwz     r3, gpSystem@sda21(r13)
/* 020518 80025AB8 80030020 */  lwz     r0, 0x20(r3)
/* 02051C 80025ABC 2C00000B */  cmpwi   r0, 0xb
/* 020520 80025AC0 40820088 */  bne     lbl_80025B48
/* 020524 80025AC4 801E0074 */  lwz     r0, 0x74(r30)
/* 020528 80025AC8 2C000000 */  cmpwi   r0, 0
/* 02052C 80025ACC 4182007C */  beq     lbl_80025B48
/* 020530 80025AD0 3C7E0004 */  addis   r3, r30, 4
/* 020534 80025AD4 83A3D13C */  lwz     r29, -0x2ec4(r3)
/* 020538 80025AD8 38600000 */  li      r3, 0
/* 02053C 80025ADC 38800000 */  li      r4, 0
/* 020540 80025AE0 38A00280 */  li      r5, 0x280
/* 020544 80025AE4 38C001E0 */  li      r6, 0x1e0
/* 020548 80025AE8 48085DF5 */  bl      GXSetTexCopySrc
/* 02054C 80025AEC 38600140 */  li      r3, 0x140
/* 020550 80025AF0 388000F0 */  li      r4, 0xf0
/* 020554 80025AF4 38A00004 */  li      r5, 4
/* 020558 80025AF8 38C00001 */  li      r6, 1
/* 02055C 80025AFC 48085E91 */  bl      GXSetTexCopyDst
/* 020560 80025B00 3C800002 */  lis     r4, 2
/* 020564 80025B04 7FA3EB78 */  mr      r3, r29
/* 020568 80025B08 38845800 */  addi    r4, r4, 0x5800
/* 02056C 80025B0C 48077C45 */  bl      DCInvalidateRange
/* 020570 80025B10 7FA3EB78 */  mr      r3, r29
/* 020574 80025B14 38800000 */  li      r4, 0
/* 020578 80025B18 48086721 */  bl      GXCopyTex
/* 02057C 80025B1C 38000000 */  li      r0, 0
/* 020580 80025B20 900D89C4 */  stw     r0, sCopyFrameSyncReceived@sda21(r13)
/* 020584 80025B24 38607D00 */  li      r3, 0x7d00
/* 020588 80025B28 48085395 */  bl      GXSetDrawSync
/* 02058C 80025B2C 48000004 */  b       lbl_80025B30
lbl_80025B30:
/* 020590 80025B30 48000004 */  b       lbl_80025B34
lbl_80025B34:
/* 020594 80025B34 800D89C4 */  lwz     r0, sCopyFrameSyncReceived@sda21(r13)
/* 020598 80025B38 2C000000 */  cmpwi   r0, 0
/* 02059C 80025B3C 4182FFF8 */  beq     lbl_80025B34
/* 0205A0 80025B40 38000000 */  li      r0, 0
/* 0205A4 80025B44 901E0074 */  stw     r0, 0x74(r30)
lbl_80025B48:
/* 0205A8 80025B48 38600001 */  li      r3, 1
/* 0205AC 80025B4C 38800003 */  li      r4, 3
/* 0205B0 80025B50 38A00001 */  li      r5, 1
/* 0205B4 80025B54 48088991 */  bl      GXSetZMode
/* 0205B8 80025B58 38600001 */  li      r3, 1
/* 0205BC 80025B5C 48088931 */  bl      GXSetColorUpdate
/* 0205C0 80025B60 806D8DAC */  lwz     r3, DemoCurrentBuffer@sda21(r13)
/* 0205C4 80025B64 38800001 */  li      r4, 1
/* 0205C8 80025B68 48086569 */  bl      GXCopyDisp
/* 0205CC 80025B6C 48085411 */  bl      GXSetDrawDone
/* 0205D0 80025B70 48085015 */  bl      GXFlush
/* 0205D4 80025B74 806D8920 */  lwz     r3, gpSystem@sda21(r13)
/* 0205D8 80025B78 80030020 */  lwz     r0, 0x20(r3)
/* 0205DC 80025B7C 2C000005 */  cmpwi   r0, 5
/* 0205E0 80025B80 40820078 */  bne     lbl_80025BF8
/* 0205E4 80025B84 38E00000 */  li      r7, 0
/* 0205E8 80025B88 90FE002C */  stw     r7, 0x2c(r30)
/* 0205EC 80025B8C 38600000 */  li      r3, 0
/* 0205F0 80025B90 38800016 */  li      r4, 0x16
/* 0205F4 80025B94 80DE0030 */  lwz     r6, 0x30(r30)
/* 0205F8 80025B98 38A00000 */  li      r5, 0
/* 0205FC 80025B9C 38060001 */  addi    r0, r6, 1
/* 020600 80025BA0 901E0030 */  stw     r0, 0x30(r30)
/* 020604 80025BA4 90FE0050 */  stw     r7, 0x50(r30)
/* 020608 80025BA8 90FE0054 */  stw     r7, 0x54(r30)
/* 02060C 80025BAC 90FE0048 */  stw     r7, 0x48(r30)
/* 020610 80025BB0 90FE0058 */  stw     r7, 0x58(r30)
/* 020614 80025BB4 90FE005C */  stw     r7, 0x5c(r30)
/* 020618 80025BB8 801E0060 */  lwz     r0, 0x60(r30)
/* 02061C 80025BBC 901E0064 */  stw     r0, 0x64(r30)
/* 020620 80025BC0 90FE0060 */  stw     r7, 0x60(r30)
/* 020624 80025BC4 90FE0068 */  stw     r7, 0x68(r30)
/* 020628 80025BC8 48088129 */  bl      GXSetZTexture
/* 02062C 80025BCC 807E0040 */  lwz     r3, 0x40(r30)
/* 020630 80025BD0 5460073E */  clrlwi  r0, r3, 0x1c
/* 020634 80025BD4 2C000000 */  cmpwi   r0, 0
/* 020638 80025BD8 4082000C */  bne     lbl_80025BE4
/* 02063C 80025BDC 5460001E */  rlwinm  r0, r3, 0, 0, 0xf
/* 020640 80025BE0 901E0040 */  stw     r0, 0x40(r30)
lbl_80025BE4:
/* 020644 80025BE4 807E0040 */  lwz     r3, 0x40(r30)
/* 020648 80025BE8 38000000 */  li      r0, 0
/* 02064C 80025BEC 5463002E */  rlwinm  r3, r3, 0, 0, 0x17
/* 020650 80025BF0 907E0040 */  stw     r3, 0x40(r30)
/* 020654 80025BF4 901E0044 */  stw     r0, 0x44(r30)
lbl_80025BF8:
/* 020658 80025BF8 806D8920 */  lwz     r3, gpSystem@sda21(r13)
/* 02065C 80025BFC 80030020 */  lwz     r0, 0x20(r3)
/* 020660 80025C00 2C00000B */  cmpwi   r0, 0xb
/* 020664 80025C04 4082000C */  bne     lbl_80025C10
/* 020668 80025C08 38000000 */  li      r0, 0
/* 02066C 80025C0C 901E0070 */  stw     r0, 0x70(r30)
lbl_80025C10:
/* 020670 80025C10 3C7F0001 */  addis   r3, r31, 1
/* 020674 80025C14 808312A0 */  lwz     r4, 0x12a0(r3)
/* 020678 80025C18 38000000 */  li      r0, 0
/* 02067C 80025C1C 38600001 */  li      r3, 1
/* 020680 80025C20 90040074 */  stw     r0, 0x74(r4)
/* 020684 80025C24 80010024 */  lwz     r0, 0x24(r1)
/* 020688 80025C28 83E1001C */  lwz     r31, 0x1c(r1)
/* 02068C 80025C2C 83C10018 */  lwz     r30, 0x18(r1)
/* 020690 80025C30 7C0803A6 */  mtlr    r0
/* 020694 80025C34 83A10014 */  lwz     r29, 0x14(r1)
/* 020698 80025C38 38210020 */  addi    r1, r1, 0x20
/* 02069C 80025C3C 4E800020 */  blr     