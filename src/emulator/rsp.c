#include "emulator/rsp.h"
#include "emulator/cpu.h"
#include "emulator/frame.h"
#include "emulator/ram.h"
#include "emulator/rdp.h"
#include "emulator/rsp_jumptables.h"
#include "emulator/system.h"
#include "emulator/xlHeap.h"
#include "emulator/xlList.h"

_XL_OBJECTTYPE gClassRSP = {
    "RSP",
    sizeof(Rsp),
    NULL,
    (EventFunc)rspEvent,
};

s32 cmask_tab[8] = {
    0x00000007, 0x0000000E, 0x0000000C, 0x0000000C, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

s32 emask_tab[8] = {
    0x00000000, 0x00000001, 0x00000003, 0x00000003, 0x00000007, 0x00000007, 0x00000007, 0x00000007,
};

static s16 TMEMSIZE[5] = {
    0x0200, 0x0200, 0x0100, 0x0200, 0x0200,
};

char D_800EE27C[40] = "FrameComplete: Yielded task pending...\n";

#ifndef NON_MATCHING
// rspGet32
void* jtbl_800EE2A4[29] = {
    &lbl_800721A4, &lbl_80072218, &lbl_80072218, &lbl_80072218, &lbl_800721B0, &lbl_80072218,
    &lbl_80072218, &lbl_80072218, &lbl_800721BC, &lbl_80072218, &lbl_80072218, &lbl_80072218,
    &lbl_800721C8, &lbl_80072218, &lbl_80072218, &lbl_80072218, &lbl_800721D4, &lbl_80072218,
    &lbl_80072218, &lbl_80072218, &lbl_800721E4, &lbl_80072218, &lbl_80072218, &lbl_80072218,
    &lbl_800721F4, &lbl_80072218, &lbl_80072218, &lbl_80072218, &lbl_80072204,
};
#else
void* jtbl_800EE2A4[29] = {0};
#endif

#ifndef NON_MATCHING
// rspPut32
void* jtbl_800EE318[8] = {
    &lbl_80072718, &lbl_80072580, &lbl_800725B4, &lbl_800725E8,
    &lbl_80072608, &lbl_80072670, &lbl_800726D8, &lbl_800726F8,
};
#else
void* jtbl_800EE318[8] = {0};
#endif

#ifndef NON_MATCHING
// rspPut32
void* jtbl_800EE338[29] = {
    &lbl_8007241C, &lbl_80072948, &lbl_80072948, &lbl_80072948, &lbl_8007242C, &lbl_80072948,
    &lbl_80072948, &lbl_80072948, &lbl_8007243C, &lbl_80072948, &lbl_80072948, &lbl_80072948,
    &lbl_800724AC, &lbl_80072948, &lbl_80072948, &lbl_80072948, &lbl_80072534, &lbl_80072948,
    &lbl_80072948, &lbl_80072948, &lbl_80072998, &lbl_80072948, &lbl_80072948, &lbl_80072948,
    &lbl_80072998, &lbl_80072948, &lbl_80072948, &lbl_80072948, &lbl_8007293C,
};
#else
void* jtbl_800EE338[29] = {0};
#endif

#ifndef NON_MATCHING
// rspParseGBI
void* jtbl_800EE3AC[11] = {
    &lbl_80072AC0, &lbl_80072AC0, &lbl_80072AC0, &lbl_80072AD4, &lbl_80072AE8, &lbl_80072AC0,
    &lbl_80072AD4, &lbl_80072AC0, &lbl_80072AD4, &lbl_80072AC0, &lbl_80072AD4,
};
#else
void* jtbl_800EE3AC[11] = {0};
#endif

void* jtbl_800EE3D8[13] = {
    &lbl_80075608, &lbl_8007600C, &lbl_8007600C, &lbl_8007600C, &lbl_80075630, &lbl_8007600C, &lbl_8007600C,
    &lbl_8007600C, &lbl_8007600C, &lbl_8007600C, &lbl_8007600C, &lbl_8007600C, &lbl_8007600C,
};

void* jtbl_800EE40C[15] = {
    &lbl_8007600C, &lbl_800750A4, &lbl_80074F84, &lbl_800750A4, &lbl_8007600C,
    &lbl_800750A4, &lbl_80074FB0, &lbl_800750A4, &lbl_80074FC4, &lbl_800750A4,
    &lbl_80075020, &lbl_800750A4, &lbl_8007600C, &lbl_800750A4, &lbl_8007600C,
};

void* jtbl_800EE448[13] = {
    &lbl_80074A78, &lbl_80074D04, &lbl_8007600C, &lbl_80074D04, &lbl_80074C44, &lbl_80074D04, &lbl_80074CA4,
    &lbl_80074D04, &lbl_8007600C, &lbl_80074D04, &lbl_8007600C, &lbl_80074D04, &lbl_800749F0,
};

void* jtbl_800EE47C[13] = {
    &lbl_80077440, &lbl_80077778, &lbl_80077778, &lbl_80077778, &lbl_80077468, &lbl_80077778, &lbl_80077778,
    &lbl_80077778, &lbl_80077778, &lbl_80077778, &lbl_80077778, &lbl_80077778, &lbl_80077778,
};

void* jtbl_800EE4B0[15] = {
    &lbl_80076D14, &lbl_80076F5C, &lbl_80076E3C, &lbl_80076F5C, &lbl_80077778,
    &lbl_80076F5C, &lbl_80076E84, &lbl_80076F5C, &lbl_80076E94, &lbl_80076F5C,
    &lbl_80076EF0, &lbl_80076F5C, &lbl_80077778, &lbl_80076F5C, &lbl_80077778,
};

void* jtbl_800EE4EC[31] = {
    &lbl_80076698, &lbl_8007685C, &lbl_800766EC, &lbl_8007685C, &lbl_80076744, &lbl_8007685C, &lbl_8007679C,
    &lbl_8007685C, &lbl_8007679C, &lbl_8007685C, &lbl_8007679C, &lbl_8007685C, &lbl_8007679C, &lbl_8007685C,
    &lbl_8007679C, &lbl_8007685C, &lbl_8007679C, &lbl_8007685C, &lbl_8007679C, &lbl_8007685C, &lbl_8007679C,
    &lbl_8007685C, &lbl_80077778, &lbl_8007685C, &lbl_80077778, &lbl_8007685C, &lbl_80077778, &lbl_8007685C,
    &lbl_80077778, &lbl_8007685C, &lbl_800767FC,
};

void* jtbl_800EE568[27] = {
    &lbl_8008118C, &lbl_80080B40, &lbl_80080B50, &lbl_8008117C, &lbl_80080B6C, &lbl_80080B7C, &lbl_80080B8C,
    &lbl_8008117C, &lbl_80080CF4, &lbl_8008117C, &lbl_80080D20, &lbl_80080D4C, &lbl_80080DB0, &lbl_80080DC0,
    &lbl_80080E2C, &lbl_80080E3C, &lbl_80080E58, &lbl_80080E98, &lbl_80080FFC, &lbl_80081048, &lbl_80081058,
    &lbl_800810A4, &lbl_800810F0, &lbl_8008111C, &lbl_8008112C, &lbl_8008118C, &lbl_8008113C,
};

void* jtbl_800EE5D4[23] = {
    &lbl_80082B60, &lbl_800826C0, &lbl_800826D0, &lbl_80082B50, &lbl_80082B50, &lbl_80082764,
    &lbl_80082B50, &lbl_800827D0, &lbl_800827E4, &lbl_80082B50, &lbl_800827F4, &lbl_80082830,
    &lbl_80082894, &lbl_800828A4, &lbl_8008291C, &lbl_8008292C, &lbl_80082948, &lbl_80082990,
    &lbl_80082B04, &lbl_800826F8, &lbl_80082708, &lbl_80082774, &lbl_80082B40,
};

void* jtbl_800EE630[24] = {
    &lbl_80084950, &lbl_80084338, &lbl_80084360, &lbl_8008437C, &lbl_8008438C, &lbl_8008439C,
    &lbl_800843AC, &lbl_80084514, &lbl_80084524, &lbl_80084550, &lbl_80084590, &lbl_800845BC,
    &lbl_80084620, &lbl_80084630, &lbl_80084640, &lbl_80084650, &lbl_8008466C, &lbl_800846AC,
    &lbl_80084810, &lbl_8008485C, &lbl_8008486C, &lbl_800848B8, &lbl_80084904, &lbl_80084930,
};

void* jtbl_800EE690[16] = {
    &lbl_80088B18, &lbl_80088890, &lbl_8008889C, &lbl_80088AD8, &lbl_800888C4, &lbl_80088AE4,
    &lbl_80088914, &lbl_80088970, &lbl_80088984, &lbl_80088AF0, &lbl_80088990, &lbl_800889CC,
    &lbl_80088A38, &lbl_80088A44, &lbl_80088AFC, &lbl_80088ABC,
};

static s32 nFirstTime_2148 = 0x00000001;
static s32 nFirstTime_2648 = 0x00000001;
static s32 nFirstTime_2757 = 0x00000001;
static s32 nFirstTime_2796 = 0x00000001;

static u16 scissorX1 = 0x500;
static u16 scissorY1 = 0x3C0;

static s16 TMEMMASK[4] = {
    0x01FF,
    0x00FF,
    0x007F,
    0x003F,
};

static s16 TMEMSHIFT[4] = {
    0x0200,
    0x0100,
    0x0080,
    0x0040,
};

static s32 counter;
static u16 scissorX0;
static u16 scissorY0;
static u8 flagBilerp;
static u32 rdpSetTimg_w0;
static u32 rdpSetTile_w0;
static u16 tmemSliceWmax;
static u16 imageSrcWsize;
static u16 flagSplit;
static u16 imagePtrX0;
static s32 imageTop;
static u16 tmemSrcLines;

const f32 D_80136038 = 0.25f;
const f32 D_8013603C = 1024.0f;
const f32 D_80136040 = 0.03125f;
const f64 D_80136048 = 4503601774854144.0;
const f64 D_80136050 = 4503599627370496.0;
const f32 D_80136058 = 1.0f;
const f32 D_8013605C = 0.0f;
const f32 D_80136060 = 0.5f;
const f32 D_80136064 = 2.0f;
const f32 D_80136068 = -1.0;
const f32 D_8013606C = 65536.0f;
const f32 D_80136070 = 0.0009765625f;
const f32 D_80136074 = 1.52587890625e-05;

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspVMUDN.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspVMADN.s")

static bool rspInitAudioDMEM1(Rsp* pRSP) {
    pRSP->anAudioBuffer = pRSP->pDMEM;

    pRSP->anAudioBuffer[0x000] = 0x0000;
    pRSP->anAudioBuffer[0x001] = 0x0001;
    pRSP->anAudioBuffer[0x002] = 0x0002;
    pRSP->anAudioBuffer[0x003] = 0xFFFF;
    pRSP->anAudioBuffer[0x004] = 0x0020;
    pRSP->anAudioBuffer[0x005] = 0x0800;
    pRSP->anAudioBuffer[0x006] = 0x7FFF;
    pRSP->anAudioBuffer[0x007] = 0x4000;
    pRSP->anAudioBuffer[0x008] = 0x1118;
    pRSP->anAudioBuffer[0x009] = 0x1470;
    pRSP->anAudioBuffer[0x00A] = 0x11DC;
    pRSP->anAudioBuffer[0x00B] = 0x1B38;
    pRSP->anAudioBuffer[0x00C] = 0x1214;
    pRSP->anAudioBuffer[0x00D] = 0x187C;
    pRSP->anAudioBuffer[0x00E] = 0x1254;
    pRSP->anAudioBuffer[0x00F] = 0x12D0;
    pRSP->anAudioBuffer[0x010] = 0x12EC;
    pRSP->anAudioBuffer[0x011] = 0x1328;
    pRSP->anAudioBuffer[0x012] = 0x140C;
    pRSP->anAudioBuffer[0x013] = 0x1294;
    pRSP->anAudioBuffer[0x014] = 0x1E24;
    pRSP->anAudioBuffer[0x015] = 0x138C;
    pRSP->anAudioBuffer[0x016] = 0x170C;
    pRSP->anAudioBuffer[0x017] = 0x144C;
    pRSP->anAudioBuffer[0x018] = 0xF000;
    pRSP->anAudioBuffer[0x019] = 0x0F00;
    pRSP->anAudioBuffer[0x01A] = 0x00F0;
    pRSP->anAudioBuffer[0x01B] = 0x000F;
    pRSP->anAudioBuffer[0x01C] = 0x0001;
    pRSP->anAudioBuffer[0x01D] = 0x0010;
    pRSP->anAudioBuffer[0x01E] = 0x0100;
    pRSP->anAudioBuffer[0x01F] = 0x1000;
    pRSP->anAudioBuffer[0x020] = 0x0002;
    pRSP->anAudioBuffer[0x021] = 0x0004;
    pRSP->anAudioBuffer[0x022] = 0x0006;
    pRSP->anAudioBuffer[0x023] = 0x0008;
    pRSP->anAudioBuffer[0x024] = 0x000A;
    pRSP->anAudioBuffer[0x025] = 0x000C;
    pRSP->anAudioBuffer[0x026] = 0x000E;
    pRSP->anAudioBuffer[0x027] = 0x0010;
    pRSP->anAudioBuffer[0x028] = 0x0001;
    pRSP->anAudioBuffer[0x029] = 0x0001;
    pRSP->anAudioBuffer[0x02A] = 0x0001;
    pRSP->anAudioBuffer[0x02B] = 0x0001;
    pRSP->anAudioBuffer[0x02C] = 0x0001;
    pRSP->anAudioBuffer[0x02D] = 0x0001;
    pRSP->anAudioBuffer[0x02E] = 0x0001;
    pRSP->anAudioBuffer[0x02F] = 0x0001;
    pRSP->anAudioBuffer[0x030] = 0x0000;
    pRSP->anAudioBuffer[0x031] = 0x0001;
    pRSP->anAudioBuffer[0x032] = 0x0002;
    pRSP->anAudioBuffer[0x033] = 0x0004;
    pRSP->anAudioBuffer[0x034] = 0x0008;
    pRSP->anAudioBuffer[0x035] = 0x0010;
    pRSP->anAudioBuffer[0x036] = 0x0100;
    pRSP->anAudioBuffer[0x037] = 0x0200;
    pRSP->anAudioBuffer[0x038] = 0x0001;
    pRSP->anAudioBuffer[0x039] = 0x0000;
    pRSP->anAudioBuffer[0x03A] = 0x0000;
    pRSP->anAudioBuffer[0x03B] = 0x0000;
    pRSP->anAudioBuffer[0x03C] = 0x0001;
    pRSP->anAudioBuffer[0x03D] = 0x0000;
    pRSP->anAudioBuffer[0x03E] = 0x0000;
    pRSP->anAudioBuffer[0x03F] = 0x0000;
    pRSP->anAudioBuffer[0x040] = 0x0000;
    pRSP->anAudioBuffer[0x041] = 0x0001;
    pRSP->anAudioBuffer[0x042] = 0x0000;
    pRSP->anAudioBuffer[0x043] = 0x0000;
    pRSP->anAudioBuffer[0x044] = 0x0000;
    pRSP->anAudioBuffer[0x045] = 0x0001;
    pRSP->anAudioBuffer[0x046] = 0x0000;
    pRSP->anAudioBuffer[0x047] = 0x0000;
    pRSP->anAudioBuffer[0x048] = 0x0000;
    pRSP->anAudioBuffer[0x049] = 0x0000;
    pRSP->anAudioBuffer[0x04A] = 0x0001;
    pRSP->anAudioBuffer[0x04B] = 0x0000;
    pRSP->anAudioBuffer[0x04C] = 0x0000;
    pRSP->anAudioBuffer[0x04D] = 0x0000;
    pRSP->anAudioBuffer[0x04E] = 0x0001;
    pRSP->anAudioBuffer[0x04F] = 0x0000;
    pRSP->anAudioBuffer[0x050] = 0x0000;
    pRSP->anAudioBuffer[0x051] = 0x0000;
    pRSP->anAudioBuffer[0x052] = 0x0000;
    pRSP->anAudioBuffer[0x053] = 0x0001;
    pRSP->anAudioBuffer[0x054] = 0x0000;
    pRSP->anAudioBuffer[0x055] = 0x0000;
    pRSP->anAudioBuffer[0x056] = 0x0000;
    pRSP->anAudioBuffer[0x057] = 0x0001;
    pRSP->anAudioBuffer[0x058] = 0x2000;
    pRSP->anAudioBuffer[0x059] = 0x4000;
    pRSP->anAudioBuffer[0x05A] = 0x6000;
    pRSP->anAudioBuffer[0x05B] = 0x8000;
    pRSP->anAudioBuffer[0x05C] = 0xA000;
    pRSP->anAudioBuffer[0x05D] = 0xC000;
    pRSP->anAudioBuffer[0x05E] = 0xE000;
    pRSP->anAudioBuffer[0x05F] = 0xFFFF;
    pRSP->anAudioBuffer[0x060] = 0x0C39;
    pRSP->anAudioBuffer[0x061] = 0x66AD;
    pRSP->anAudioBuffer[0x062] = 0x0D46;
    pRSP->anAudioBuffer[0x063] = 0xFFDF;
    pRSP->anAudioBuffer[0x064] = 0x0B39;
    pRSP->anAudioBuffer[0x065] = 0x6696;
    pRSP->anAudioBuffer[0x066] = 0x0E5F;
    pRSP->anAudioBuffer[0x067] = 0xFFD8;
    pRSP->anAudioBuffer[0x068] = 0x0A44;
    pRSP->anAudioBuffer[0x069] = 0x6669;
    pRSP->anAudioBuffer[0x06A] = 0x0F83;
    pRSP->anAudioBuffer[0x06B] = 0xFFD0;
    pRSP->anAudioBuffer[0x06C] = 0x095A;
    pRSP->anAudioBuffer[0x06D] = 0x6626;
    pRSP->anAudioBuffer[0x06E] = 0x10B4;
    pRSP->anAudioBuffer[0x06F] = 0xFFC8;
    pRSP->anAudioBuffer[0x070] = 0x087D;
    pRSP->anAudioBuffer[0x071] = 0x65CD;
    pRSP->anAudioBuffer[0x072] = 0x11F0;
    pRSP->anAudioBuffer[0x073] = 0xFFBF;
    pRSP->anAudioBuffer[0x074] = 0x07AB;
    pRSP->anAudioBuffer[0x075] = 0x655E;
    pRSP->anAudioBuffer[0x076] = 0x1338;
    pRSP->anAudioBuffer[0x077] = 0xFFB6;
    pRSP->anAudioBuffer[0x078] = 0x06E4;
    pRSP->anAudioBuffer[0x079] = 0x64D9;
    pRSP->anAudioBuffer[0x07A] = 0x148C;
    pRSP->anAudioBuffer[0x07B] = 0xFFAC;
    pRSP->anAudioBuffer[0x07C] = 0x0628;
    pRSP->anAudioBuffer[0x07D] = 0x643F;
    pRSP->anAudioBuffer[0x07E] = 0x15EB;
    pRSP->anAudioBuffer[0x07F] = 0xFFA1;
    pRSP->anAudioBuffer[0x080] = 0x0577;
    pRSP->anAudioBuffer[0x081] = 0x638F;
    pRSP->anAudioBuffer[0x082] = 0x1756;
    pRSP->anAudioBuffer[0x083] = 0xFF96;
    pRSP->anAudioBuffer[0x084] = 0x04D1;
    pRSP->anAudioBuffer[0x085] = 0x62CB;
    pRSP->anAudioBuffer[0x086] = 0x18CB;
    pRSP->anAudioBuffer[0x087] = 0xFF8A;
    pRSP->anAudioBuffer[0x088] = 0x0435;
    pRSP->anAudioBuffer[0x089] = 0x61F3;
    pRSP->anAudioBuffer[0x08A] = 0x1A4C;
    pRSP->anAudioBuffer[0x08B] = 0xFF7E;
    pRSP->anAudioBuffer[0x08C] = 0x03A4;
    pRSP->anAudioBuffer[0x08D] = 0x6106;
    pRSP->anAudioBuffer[0x08E] = 0x1BD7;
    pRSP->anAudioBuffer[0x08F] = 0xFF71;
    pRSP->anAudioBuffer[0x090] = 0x031C;
    pRSP->anAudioBuffer[0x091] = 0x6007;
    pRSP->anAudioBuffer[0x092] = 0x1D6C;
    pRSP->anAudioBuffer[0x093] = 0xFF64;
    pRSP->anAudioBuffer[0x094] = 0x029F;
    pRSP->anAudioBuffer[0x095] = 0x5EF5;
    pRSP->anAudioBuffer[0x096] = 0x1F0B;
    pRSP->anAudioBuffer[0x097] = 0xFF56;
    pRSP->anAudioBuffer[0x098] = 0x022A;
    pRSP->anAudioBuffer[0x099] = 0x5DD0;
    pRSP->anAudioBuffer[0x09A] = 0x20B3;
    pRSP->anAudioBuffer[0x09B] = 0xFF48;
    pRSP->anAudioBuffer[0x09C] = 0x01BE;
    pRSP->anAudioBuffer[0x09D] = 0x5C9A;
    pRSP->anAudioBuffer[0x09E] = 0x2264;
    pRSP->anAudioBuffer[0x09F] = 0xFF3A;
    pRSP->anAudioBuffer[0x0A0] = 0x015B;
    pRSP->anAudioBuffer[0x0A1] = 0x5B53;
    pRSP->anAudioBuffer[0x0A2] = 0x241E;
    pRSP->anAudioBuffer[0x0A3] = 0xFF2C;
    pRSP->anAudioBuffer[0x0A4] = 0x0101;
    pRSP->anAudioBuffer[0x0A5] = 0x59FC;
    pRSP->anAudioBuffer[0x0A6] = 0x25E0;
    pRSP->anAudioBuffer[0x0A7] = 0xFF1E;
    pRSP->anAudioBuffer[0x0A8] = 0x00AE;
    pRSP->anAudioBuffer[0x0A9] = 0x5896;
    pRSP->anAudioBuffer[0x0AA] = 0x27A9;
    pRSP->anAudioBuffer[0x0AB] = 0xFF10;
    pRSP->anAudioBuffer[0x0AC] = 0x0063;
    pRSP->anAudioBuffer[0x0AD] = 0x5720;
    pRSP->anAudioBuffer[0x0AE] = 0x297A;
    pRSP->anAudioBuffer[0x0AF] = 0xFF02;
    pRSP->anAudioBuffer[0x0B0] = 0x001F;
    pRSP->anAudioBuffer[0x0B1] = 0x559D;
    pRSP->anAudioBuffer[0x0B2] = 0x2B50;
    pRSP->anAudioBuffer[0x0B3] = 0xFEF4;
    pRSP->anAudioBuffer[0x0B4] = 0xFFE2;
    pRSP->anAudioBuffer[0x0B5] = 0x540D;
    pRSP->anAudioBuffer[0x0B6] = 0x2D2C;
    pRSP->anAudioBuffer[0x0B7] = 0xFEE8;
    pRSP->anAudioBuffer[0x0B8] = 0xFFAC;
    pRSP->anAudioBuffer[0x0B9] = 0x5270;
    pRSP->anAudioBuffer[0x0BA] = 0x2F0D;
    pRSP->anAudioBuffer[0x0BB] = 0xFEDB;
    pRSP->anAudioBuffer[0x0BC] = 0xFF7C;
    pRSP->anAudioBuffer[0x0BD] = 0x50C7;
    pRSP->anAudioBuffer[0x0BE] = 0x30F3;
    pRSP->anAudioBuffer[0x0BF] = 0xFED0;
    pRSP->anAudioBuffer[0x0C0] = 0xFF53;
    pRSP->anAudioBuffer[0x0C1] = 0x4F14;
    pRSP->anAudioBuffer[0x0C2] = 0x32DC;
    pRSP->anAudioBuffer[0x0C3] = 0xFEC6;
    pRSP->anAudioBuffer[0x0C4] = 0xFF2E;
    pRSP->anAudioBuffer[0x0C5] = 0x4D57;
    pRSP->anAudioBuffer[0x0C6] = 0x34C8;
    pRSP->anAudioBuffer[0x0C7] = 0xFEBD;
    pRSP->anAudioBuffer[0x0C8] = 0xFF0F;
    pRSP->anAudioBuffer[0x0C9] = 0x4B91;
    pRSP->anAudioBuffer[0x0CA] = 0x36B6;
    pRSP->anAudioBuffer[0x0CB] = 0xFEB6;
    pRSP->anAudioBuffer[0x0CC] = 0xFEF5;
    pRSP->anAudioBuffer[0x0CD] = 0x49C2;
    pRSP->anAudioBuffer[0x0CE] = 0x38A5;
    pRSP->anAudioBuffer[0x0CF] = 0xFEB0;
    pRSP->anAudioBuffer[0x0D0] = 0xFEDF;
    pRSP->anAudioBuffer[0x0D1] = 0x47ED;
    pRSP->anAudioBuffer[0x0D2] = 0x3A95;
    pRSP->anAudioBuffer[0x0D3] = 0xFEAC;
    pRSP->anAudioBuffer[0x0D4] = 0xFECE;
    pRSP->anAudioBuffer[0x0D5] = 0x4611;
    pRSP->anAudioBuffer[0x0D6] = 0x3C85;
    pRSP->anAudioBuffer[0x0D7] = 0xFEAB;
    pRSP->anAudioBuffer[0x0D8] = 0xFEC0;
    pRSP->anAudioBuffer[0x0D9] = 0x4430;
    pRSP->anAudioBuffer[0x0DA] = 0x3E74;
    pRSP->anAudioBuffer[0x0DB] = 0xFEAC;
    pRSP->anAudioBuffer[0x0DC] = 0xFEB6;
    pRSP->anAudioBuffer[0x0DD] = 0x424A;
    pRSP->anAudioBuffer[0x0DE] = 0x4060;
    pRSP->anAudioBuffer[0x0DF] = 0xFEAF;
    pRSP->anAudioBuffer[0x0E0] = 0xFEAF;
    pRSP->anAudioBuffer[0x0E1] = 0x4060;
    pRSP->anAudioBuffer[0x0E2] = 0x424A;
    pRSP->anAudioBuffer[0x0E3] = 0xFEB6;
    pRSP->anAudioBuffer[0x0E4] = 0xFEAC;
    pRSP->anAudioBuffer[0x0E5] = 0x3E74;
    pRSP->anAudioBuffer[0x0E6] = 0x4430;
    pRSP->anAudioBuffer[0x0E7] = 0xFEC0;
    pRSP->anAudioBuffer[0x0E8] = 0xFEAB;
    pRSP->anAudioBuffer[0x0E9] = 0x3C85;
    pRSP->anAudioBuffer[0x0EA] = 0x4611;
    pRSP->anAudioBuffer[0x0EB] = 0xFECE;
    pRSP->anAudioBuffer[0x0EC] = 0xFEAC;
    pRSP->anAudioBuffer[0x0ED] = 0x3A95;
    pRSP->anAudioBuffer[0x0EE] = 0x47ED;
    pRSP->anAudioBuffer[0x0EF] = 0xFEDF;
    pRSP->anAudioBuffer[0x0F0] = 0xFEB0;
    pRSP->anAudioBuffer[0x0F1] = 0x38A5;
    pRSP->anAudioBuffer[0x0F2] = 0x49C2;
    pRSP->anAudioBuffer[0x0F3] = 0xFEF5;
    pRSP->anAudioBuffer[0x0F4] = 0xFEB6;
    pRSP->anAudioBuffer[0x0F5] = 0x36B6;
    pRSP->anAudioBuffer[0x0F6] = 0x4B91;
    pRSP->anAudioBuffer[0x0F7] = 0xFF0F;
    pRSP->anAudioBuffer[0x0F8] = 0xFEBD;
    pRSP->anAudioBuffer[0x0F9] = 0x34C8;
    pRSP->anAudioBuffer[0x0FA] = 0x4D57;
    pRSP->anAudioBuffer[0x0FB] = 0xFF2E;
    pRSP->anAudioBuffer[0x0FC] = 0xFEC6;
    pRSP->anAudioBuffer[0x0FD] = 0x32DC;
    pRSP->anAudioBuffer[0x0FE] = 0x4F14;
    pRSP->anAudioBuffer[0x0FF] = 0xFF53;
    pRSP->anAudioBuffer[0x100] = 0xFED0;
    pRSP->anAudioBuffer[0x101] = 0x30F3;
    pRSP->anAudioBuffer[0x102] = 0x50C7;
    pRSP->anAudioBuffer[0x103] = 0xFF7C;
    pRSP->anAudioBuffer[0x104] = 0xFEDB;
    pRSP->anAudioBuffer[0x105] = 0x2F0D;
    pRSP->anAudioBuffer[0x106] = 0x5270;
    pRSP->anAudioBuffer[0x107] = 0xFFAC;
    pRSP->anAudioBuffer[0x108] = 0xFEE8;
    pRSP->anAudioBuffer[0x109] = 0x2D2C;
    pRSP->anAudioBuffer[0x10A] = 0x540D;
    pRSP->anAudioBuffer[0x10B] = 0xFFE2;
    pRSP->anAudioBuffer[0x10C] = 0xFEF4;
    pRSP->anAudioBuffer[0x10D] = 0x2B50;
    pRSP->anAudioBuffer[0x10E] = 0x559D;
    pRSP->anAudioBuffer[0x10F] = 0x001F;
    pRSP->anAudioBuffer[0x110] = 0xFF02;
    pRSP->anAudioBuffer[0x111] = 0x297A;
    pRSP->anAudioBuffer[0x112] = 0x5720;
    pRSP->anAudioBuffer[0x113] = 0x0063;
    pRSP->anAudioBuffer[0x114] = 0xFF10;
    pRSP->anAudioBuffer[0x115] = 0x27A9;
    pRSP->anAudioBuffer[0x116] = 0x5896;
    pRSP->anAudioBuffer[0x117] = 0x00AE;
    pRSP->anAudioBuffer[0x118] = 0xFF1E;
    pRSP->anAudioBuffer[0x119] = 0x25E0;
    pRSP->anAudioBuffer[0x11A] = 0x59FC;
    pRSP->anAudioBuffer[0x11B] = 0x0101;
    pRSP->anAudioBuffer[0x11C] = 0xFF2C;
    pRSP->anAudioBuffer[0x11D] = 0x241E;
    pRSP->anAudioBuffer[0x11E] = 0x5B53;
    pRSP->anAudioBuffer[0x11F] = 0x015B;
    pRSP->anAudioBuffer[0x120] = 0xFF3A;
    pRSP->anAudioBuffer[0x121] = 0x2264;
    pRSP->anAudioBuffer[0x122] = 0x5C9A;
    pRSP->anAudioBuffer[0x123] = 0x01BE;
    pRSP->anAudioBuffer[0x124] = 0xFF48;
    pRSP->anAudioBuffer[0x125] = 0x20B3;
    pRSP->anAudioBuffer[0x126] = 0x5DD0;
    pRSP->anAudioBuffer[0x127] = 0x022A;
    pRSP->anAudioBuffer[0x128] = 0xFF56;
    pRSP->anAudioBuffer[0x129] = 0x1F0B;
    pRSP->anAudioBuffer[0x12A] = 0x5EF5;
    pRSP->anAudioBuffer[0x12B] = 0x029F;
    pRSP->anAudioBuffer[0x12C] = 0xFF64;
    pRSP->anAudioBuffer[0x12D] = 0x1D6C;
    pRSP->anAudioBuffer[0x12E] = 0x6007;
    pRSP->anAudioBuffer[0x12F] = 0x031C;
    pRSP->anAudioBuffer[0x130] = 0xFF71;
    pRSP->anAudioBuffer[0x131] = 0x1BD7;
    pRSP->anAudioBuffer[0x132] = 0x6106;
    pRSP->anAudioBuffer[0x133] = 0x03A4;
    pRSP->anAudioBuffer[0x134] = 0xFF7E;
    pRSP->anAudioBuffer[0x135] = 0x1A4C;
    pRSP->anAudioBuffer[0x136] = 0x61F3;
    pRSP->anAudioBuffer[0x137] = 0x0435;
    pRSP->anAudioBuffer[0x138] = 0xFF8A;
    pRSP->anAudioBuffer[0x139] = 0x18CB;
    pRSP->anAudioBuffer[0x13A] = 0x62CB;
    pRSP->anAudioBuffer[0x13B] = 0x04D1;
    pRSP->anAudioBuffer[0x13C] = 0xFF96;
    pRSP->anAudioBuffer[0x13D] = 0x1756;
    pRSP->anAudioBuffer[0x13E] = 0x638F;
    pRSP->anAudioBuffer[0x13F] = 0x0577;
    pRSP->anAudioBuffer[0x140] = 0xFFA1;
    pRSP->anAudioBuffer[0x141] = 0x15EB;
    pRSP->anAudioBuffer[0x142] = 0x643F;
    pRSP->anAudioBuffer[0x143] = 0x0628;
    pRSP->anAudioBuffer[0x144] = 0xFFAC;
    pRSP->anAudioBuffer[0x145] = 0x148C;
    pRSP->anAudioBuffer[0x146] = 0x64D9;
    pRSP->anAudioBuffer[0x147] = 0x06E4;
    pRSP->anAudioBuffer[0x148] = 0xFFB6;
    pRSP->anAudioBuffer[0x149] = 0x1338;
    pRSP->anAudioBuffer[0x14A] = 0x655E;
    pRSP->anAudioBuffer[0x14B] = 0x07AB;
    pRSP->anAudioBuffer[0x14C] = 0xFFBF;
    pRSP->anAudioBuffer[0x14D] = 0x11F0;
    pRSP->anAudioBuffer[0x14E] = 0x65CD;
    pRSP->anAudioBuffer[0x14F] = 0x087D;
    pRSP->anAudioBuffer[0x150] = 0xFFC8;
    pRSP->anAudioBuffer[0x151] = 0x10B4;
    pRSP->anAudioBuffer[0x152] = 0x6626;
    pRSP->anAudioBuffer[0x153] = 0x095A;
    pRSP->anAudioBuffer[0x154] = 0xFFD0;
    pRSP->anAudioBuffer[0x155] = 0x0F83;
    pRSP->anAudioBuffer[0x156] = 0x6669;
    pRSP->anAudioBuffer[0x157] = 0x0A44;
    pRSP->anAudioBuffer[0x158] = 0xFFD8;
    pRSP->anAudioBuffer[0x159] = 0x0E5F;
    pRSP->anAudioBuffer[0x15A] = 0x6696;
    pRSP->anAudioBuffer[0x15B] = 0x0B39;
    pRSP->anAudioBuffer[0x15C] = 0xFFDF;
    pRSP->anAudioBuffer[0x15D] = 0x0D46;
    pRSP->anAudioBuffer[0x15E] = 0x66AD;
    pRSP->anAudioBuffer[0x15F] = 0x0C39;

    return true;
}

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspDotProduct8x15MatrixBy15x1Vector.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspMultPolef.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspLoadADPCMCoefTable1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspLoadADPCMCoefTable2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAADPCMDec1Fast.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAPoleFilter1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAEnvMixer1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAMix1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAResample1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspASetBuffer1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspASetVolume1.s")

static bool rspParseABI(Rsp* pRSP, RspTask* pTask);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseABI.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseABI1.s")

static bool rspInitAudioDMEM2(Rsp* pRSP) {
    pRSP->anAudioBuffer = pRSP->pDMEM;

    pRSP->anAudioBuffer[0x000] = 0x0000;
    pRSP->anAudioBuffer[0x001] = 0x0001;
    pRSP->anAudioBuffer[0x002] = 0x0002;
    pRSP->anAudioBuffer[0x003] = 0xFFFF;
    pRSP->anAudioBuffer[0x004] = 0x0020;
    pRSP->anAudioBuffer[0x005] = 0x0800;
    pRSP->anAudioBuffer[0x006] = 0x7FFF;
    pRSP->anAudioBuffer[0x007] = 0x4000;

    pRSP->anAudioBuffer[0x020] = 0xF000;
    pRSP->anAudioBuffer[0x021] = 0x0F00;
    pRSP->anAudioBuffer[0x022] = 0x00F0;
    pRSP->anAudioBuffer[0x023] = 0x000F;
    pRSP->anAudioBuffer[0x024] = 0x0001;
    pRSP->anAudioBuffer[0x025] = 0x0010;
    pRSP->anAudioBuffer[0x026] = 0x0100;
    pRSP->anAudioBuffer[0x027] = 0x1000;
    pRSP->anAudioBuffer[0x028] = 0xC000;
    pRSP->anAudioBuffer[0x029] = 0x3000;
    pRSP->anAudioBuffer[0x02A] = 0x0C00;
    pRSP->anAudioBuffer[0x02B] = 0x0300;
    pRSP->anAudioBuffer[0x02C] = 0x0001;
    pRSP->anAudioBuffer[0x02D] = 0x0004;
    pRSP->anAudioBuffer[0x02E] = 0x0010;
    pRSP->anAudioBuffer[0x02F] = 0x0040;
    pRSP->anAudioBuffer[0x030] = 0x0002;
    pRSP->anAudioBuffer[0x031] = 0x0004;
    pRSP->anAudioBuffer[0x032] = 0x0006;
    pRSP->anAudioBuffer[0x033] = 0x0008;
    pRSP->anAudioBuffer[0x034] = 0x000A;
    pRSP->anAudioBuffer[0x035] = 0x000C;
    pRSP->anAudioBuffer[0x036] = 0x000E;
    pRSP->anAudioBuffer[0x037] = 0x0010;
    pRSP->anAudioBuffer[0x038] = 0x0001;
    pRSP->anAudioBuffer[0x039] = 0x0001;
    pRSP->anAudioBuffer[0x03A] = 0x0001;
    pRSP->anAudioBuffer[0x03B] = 0x0001;
    pRSP->anAudioBuffer[0x03C] = 0x0001;
    pRSP->anAudioBuffer[0x03D] = 0x0001;
    pRSP->anAudioBuffer[0x03E] = 0x0001;
    pRSP->anAudioBuffer[0x03F] = 0x0001;
    pRSP->anAudioBuffer[0x040] = 0x0000;
    pRSP->anAudioBuffer[0x041] = 0x0001;
    pRSP->anAudioBuffer[0x042] = 0x0002;
    pRSP->anAudioBuffer[0x043] = 0x0004;
    pRSP->anAudioBuffer[0x044] = 0x0008;
    pRSP->anAudioBuffer[0x045] = 0x0010;
    pRSP->anAudioBuffer[0x046] = 0x0100;
    pRSP->anAudioBuffer[0x047] = 0x0200;
    pRSP->anAudioBuffer[0x048] = 0x0001;
    pRSP->anAudioBuffer[0x049] = 0x0000;
    pRSP->anAudioBuffer[0x04A] = 0x0000;
    pRSP->anAudioBuffer[0x04B] = 0x0000;
    pRSP->anAudioBuffer[0x04C] = 0x0001;
    pRSP->anAudioBuffer[0x04D] = 0x0000;
    pRSP->anAudioBuffer[0x04E] = 0x0000;
    pRSP->anAudioBuffer[0x04F] = 0x0000;
    pRSP->anAudioBuffer[0x050] = 0x0000;
    pRSP->anAudioBuffer[0x051] = 0x0001;
    pRSP->anAudioBuffer[0x052] = 0x0000;
    pRSP->anAudioBuffer[0x053] = 0x0000;
    pRSP->anAudioBuffer[0x054] = 0x0000;
    pRSP->anAudioBuffer[0x055] = 0x0001;
    pRSP->anAudioBuffer[0x056] = 0x0000;
    pRSP->anAudioBuffer[0x057] = 0x0000;
    pRSP->anAudioBuffer[0x058] = 0x0000;
    pRSP->anAudioBuffer[0x059] = 0x0000;
    pRSP->anAudioBuffer[0x05A] = 0x0001;
    pRSP->anAudioBuffer[0x05B] = 0x0000;
    pRSP->anAudioBuffer[0x05C] = 0x0000;
    pRSP->anAudioBuffer[0x05D] = 0x0000;
    pRSP->anAudioBuffer[0x05E] = 0x0001;
    pRSP->anAudioBuffer[0x05F] = 0x0000;
    pRSP->anAudioBuffer[0x060] = 0x0000;
    pRSP->anAudioBuffer[0x061] = 0x0000;
    pRSP->anAudioBuffer[0x062] = 0x0000;
    pRSP->anAudioBuffer[0x063] = 0x0001;
    pRSP->anAudioBuffer[0x064] = 0x0000;
    pRSP->anAudioBuffer[0x065] = 0x0000;
    pRSP->anAudioBuffer[0x066] = 0x0000;
    pRSP->anAudioBuffer[0x067] = 0x0001;
    pRSP->anAudioBuffer[0x068] = 0x2000;
    pRSP->anAudioBuffer[0x069] = 0x4000;
    pRSP->anAudioBuffer[0x06A] = 0x6000;
    pRSP->anAudioBuffer[0x06B] = 0x8000;
    pRSP->anAudioBuffer[0x06C] = 0xA000;
    pRSP->anAudioBuffer[0x06D] = 0xC000;
    pRSP->anAudioBuffer[0x06E] = 0xE000;
    pRSP->anAudioBuffer[0x06F] = 0xFFFF;
    pRSP->anAudioBuffer[0x070] = 0x0C39;
    pRSP->anAudioBuffer[0x071] = 0x66AD;
    pRSP->anAudioBuffer[0x072] = 0x0D46;
    pRSP->anAudioBuffer[0x073] = 0xFFDF;
    pRSP->anAudioBuffer[0x074] = 0x0B39;
    pRSP->anAudioBuffer[0x075] = 0x6696;
    pRSP->anAudioBuffer[0x076] = 0x0E5F;
    pRSP->anAudioBuffer[0x077] = 0xFFD8;
    pRSP->anAudioBuffer[0x078] = 0x0A44;
    pRSP->anAudioBuffer[0x079] = 0x6669;
    pRSP->anAudioBuffer[0x07A] = 0x0F83;
    pRSP->anAudioBuffer[0x07B] = 0xFFD0;
    pRSP->anAudioBuffer[0x07C] = 0x095A;
    pRSP->anAudioBuffer[0x07D] = 0x6626;
    pRSP->anAudioBuffer[0x07E] = 0x10B4;
    pRSP->anAudioBuffer[0x07F] = 0xFFC8;
    pRSP->anAudioBuffer[0x080] = 0x087D;
    pRSP->anAudioBuffer[0x081] = 0x65CD;
    pRSP->anAudioBuffer[0x082] = 0x11F0;
    pRSP->anAudioBuffer[0x083] = 0xFFBF;
    pRSP->anAudioBuffer[0x084] = 0x07AB;
    pRSP->anAudioBuffer[0x085] = 0x655E;
    pRSP->anAudioBuffer[0x086] = 0x1338;
    pRSP->anAudioBuffer[0x087] = 0xFFB6;
    pRSP->anAudioBuffer[0x088] = 0x06E4;
    pRSP->anAudioBuffer[0x089] = 0x64D9;
    pRSP->anAudioBuffer[0x08A] = 0x148C;
    pRSP->anAudioBuffer[0x08B] = 0xFFAC;
    pRSP->anAudioBuffer[0x08C] = 0x0628;
    pRSP->anAudioBuffer[0x08D] = 0x643F;
    pRSP->anAudioBuffer[0x08E] = 0x15EB;
    pRSP->anAudioBuffer[0x08F] = 0xFFA1;
    pRSP->anAudioBuffer[0x090] = 0x0577;
    pRSP->anAudioBuffer[0x091] = 0x638F;
    pRSP->anAudioBuffer[0x092] = 0x1756;
    pRSP->anAudioBuffer[0x093] = 0xFF96;
    pRSP->anAudioBuffer[0x094] = 0x04D1;
    pRSP->anAudioBuffer[0x095] = 0x62CB;
    pRSP->anAudioBuffer[0x096] = 0x18CB;
    pRSP->anAudioBuffer[0x097] = 0xFF8A;
    pRSP->anAudioBuffer[0x098] = 0x0435;
    pRSP->anAudioBuffer[0x099] = 0x61F3;
    pRSP->anAudioBuffer[0x09A] = 0x1A4C;
    pRSP->anAudioBuffer[0x09B] = 0xFF7E;
    pRSP->anAudioBuffer[0x09C] = 0x03A4;
    pRSP->anAudioBuffer[0x09D] = 0x6106;
    pRSP->anAudioBuffer[0x09E] = 0x1BD7;
    pRSP->anAudioBuffer[0x09F] = 0xFF71;
    pRSP->anAudioBuffer[0x0A0] = 0x031C;
    pRSP->anAudioBuffer[0x0A1] = 0x6007;
    pRSP->anAudioBuffer[0x0A2] = 0x1D6C;
    pRSP->anAudioBuffer[0x0A3] = 0xFF64;
    pRSP->anAudioBuffer[0x0A4] = 0x029F;
    pRSP->anAudioBuffer[0x0A5] = 0x5EF5;
    pRSP->anAudioBuffer[0x0A6] = 0x1F0B;
    pRSP->anAudioBuffer[0x0A7] = 0xFF56;
    pRSP->anAudioBuffer[0x0A8] = 0x022A;
    pRSP->anAudioBuffer[0x0A9] = 0x5DD0;
    pRSP->anAudioBuffer[0x0AA] = 0x20B3;
    pRSP->anAudioBuffer[0x0AB] = 0xFF48;
    pRSP->anAudioBuffer[0x0AC] = 0x01BE;
    pRSP->anAudioBuffer[0x0AD] = 0x5C9A;
    pRSP->anAudioBuffer[0x0AE] = 0x2264;
    pRSP->anAudioBuffer[0x0AF] = 0xFF3A;
    pRSP->anAudioBuffer[0x0B0] = 0x015B;
    pRSP->anAudioBuffer[0x0B1] = 0x5B53;
    pRSP->anAudioBuffer[0x0B2] = 0x241E;
    pRSP->anAudioBuffer[0x0B3] = 0xFF2C;
    pRSP->anAudioBuffer[0x0B4] = 0x0101;
    pRSP->anAudioBuffer[0x0B5] = 0x59FC;
    pRSP->anAudioBuffer[0x0B6] = 0x25E0;
    pRSP->anAudioBuffer[0x0B7] = 0xFF1E;
    pRSP->anAudioBuffer[0x0B8] = 0x00AE;
    pRSP->anAudioBuffer[0x0B9] = 0x5896;
    pRSP->anAudioBuffer[0x0BA] = 0x27A9;
    pRSP->anAudioBuffer[0x0BB] = 0xFF10;
    pRSP->anAudioBuffer[0x0BC] = 0x0063;
    pRSP->anAudioBuffer[0x0BD] = 0x5720;
    pRSP->anAudioBuffer[0x0BE] = 0x297A;
    pRSP->anAudioBuffer[0x0BF] = 0xFF02;
    pRSP->anAudioBuffer[0x0C0] = 0x001F;
    pRSP->anAudioBuffer[0x0C1] = 0x559D;
    pRSP->anAudioBuffer[0x0C2] = 0x2B50;
    pRSP->anAudioBuffer[0x0C3] = 0xFEF4;
    pRSP->anAudioBuffer[0x0C4] = 0xFFE2;
    pRSP->anAudioBuffer[0x0C5] = 0x540D;
    pRSP->anAudioBuffer[0x0C6] = 0x2D2C;
    pRSP->anAudioBuffer[0x0C7] = 0xFEE8;
    pRSP->anAudioBuffer[0x0C8] = 0xFFAC;
    pRSP->anAudioBuffer[0x0C9] = 0x5270;
    pRSP->anAudioBuffer[0x0CA] = 0x2F0D;
    pRSP->anAudioBuffer[0x0CB] = 0xFEDB;
    pRSP->anAudioBuffer[0x0CC] = 0xFF7C;
    pRSP->anAudioBuffer[0x0CD] = 0x50C7;
    pRSP->anAudioBuffer[0x0CE] = 0x30F3;
    pRSP->anAudioBuffer[0x0CF] = 0xFED0;
    pRSP->anAudioBuffer[0x0D0] = 0xFF53;
    pRSP->anAudioBuffer[0x0D1] = 0x4F14;
    pRSP->anAudioBuffer[0x0D2] = 0x32DC;
    pRSP->anAudioBuffer[0x0D3] = 0xFEC6;
    pRSP->anAudioBuffer[0x0D4] = 0xFF2E;
    pRSP->anAudioBuffer[0x0D5] = 0x4D57;
    pRSP->anAudioBuffer[0x0D6] = 0x34C8;
    pRSP->anAudioBuffer[0x0D7] = 0xFEBD;
    pRSP->anAudioBuffer[0x0D8] = 0xFF0F;
    pRSP->anAudioBuffer[0x0D9] = 0x4B91;
    pRSP->anAudioBuffer[0x0DA] = 0x36B6;
    pRSP->anAudioBuffer[0x0DB] = 0xFEB6;
    pRSP->anAudioBuffer[0x0DC] = 0xFEF5;
    pRSP->anAudioBuffer[0x0DD] = 0x49C2;
    pRSP->anAudioBuffer[0x0DE] = 0x38A5;
    pRSP->anAudioBuffer[0x0DF] = 0xFEB0;
    pRSP->anAudioBuffer[0x0E0] = 0xFEDF;
    pRSP->anAudioBuffer[0x0E1] = 0x47ED;
    pRSP->anAudioBuffer[0x0E2] = 0x3A95;
    pRSP->anAudioBuffer[0x0E3] = 0xFEAC;
    pRSP->anAudioBuffer[0x0E4] = 0xFECE;
    pRSP->anAudioBuffer[0x0E5] = 0x4611;
    pRSP->anAudioBuffer[0x0E6] = 0x3C85;
    pRSP->anAudioBuffer[0x0E7] = 0xFEAB;
    pRSP->anAudioBuffer[0x0E8] = 0xFEC0;
    pRSP->anAudioBuffer[0x0E9] = 0x4430;
    pRSP->anAudioBuffer[0x0EA] = 0x3E74;
    pRSP->anAudioBuffer[0x0EB] = 0xFEAC;
    pRSP->anAudioBuffer[0x0EC] = 0xFEB6;
    pRSP->anAudioBuffer[0x0ED] = 0x424A;
    pRSP->anAudioBuffer[0x0EE] = 0x4060;
    pRSP->anAudioBuffer[0x0EF] = 0xFEAF;
    pRSP->anAudioBuffer[0x0F0] = 0xFEAF;
    pRSP->anAudioBuffer[0x0F1] = 0x4060;
    pRSP->anAudioBuffer[0x0F2] = 0x424A;
    pRSP->anAudioBuffer[0x0F3] = 0xFEB6;
    pRSP->anAudioBuffer[0x0F4] = 0xFEAC;
    pRSP->anAudioBuffer[0x0F5] = 0x3E74;
    pRSP->anAudioBuffer[0x0F6] = 0x4430;
    pRSP->anAudioBuffer[0x0F7] = 0xFEC0;
    pRSP->anAudioBuffer[0x0F8] = 0xFEAB;
    pRSP->anAudioBuffer[0x0F9] = 0x3C85;
    pRSP->anAudioBuffer[0x0FA] = 0x4611;
    pRSP->anAudioBuffer[0x0FB] = 0xFECE;
    pRSP->anAudioBuffer[0x0FC] = 0xFEAC;
    pRSP->anAudioBuffer[0x0FD] = 0x3A95;
    pRSP->anAudioBuffer[0x0FE] = 0x47ED;
    pRSP->anAudioBuffer[0x0FF] = 0xFEDF;
    pRSP->anAudioBuffer[0x100] = 0xFEB0;
    pRSP->anAudioBuffer[0x101] = 0x38A5;
    pRSP->anAudioBuffer[0x102] = 0x49C2;
    pRSP->anAudioBuffer[0x103] = 0xFEF5;
    pRSP->anAudioBuffer[0x104] = 0xFEB6;
    pRSP->anAudioBuffer[0x105] = 0x36B6;
    pRSP->anAudioBuffer[0x106] = 0x4B91;
    pRSP->anAudioBuffer[0x107] = 0xFF0F;
    pRSP->anAudioBuffer[0x108] = 0xFEBD;
    pRSP->anAudioBuffer[0x109] = 0x34C8;
    pRSP->anAudioBuffer[0x10A] = 0x4D57;
    pRSP->anAudioBuffer[0x10B] = 0xFF2E;
    pRSP->anAudioBuffer[0x10C] = 0xFEC6;
    pRSP->anAudioBuffer[0x10D] = 0x32DC;
    pRSP->anAudioBuffer[0x10E] = 0x4F14;
    pRSP->anAudioBuffer[0x10F] = 0xFF53;
    pRSP->anAudioBuffer[0x110] = 0xFED0;
    pRSP->anAudioBuffer[0x111] = 0x30F3;
    pRSP->anAudioBuffer[0x112] = 0x50C7;
    pRSP->anAudioBuffer[0x113] = 0xFF7C;
    pRSP->anAudioBuffer[0x114] = 0xFEDB;
    pRSP->anAudioBuffer[0x115] = 0x2F0D;
    pRSP->anAudioBuffer[0x116] = 0x5270;
    pRSP->anAudioBuffer[0x117] = 0xFFAC;
    pRSP->anAudioBuffer[0x118] = 0xFEE8;
    pRSP->anAudioBuffer[0x119] = 0x2D2C;
    pRSP->anAudioBuffer[0x11A] = 0x540D;
    pRSP->anAudioBuffer[0x11B] = 0xFFE2;
    pRSP->anAudioBuffer[0x11C] = 0xFEF4;
    pRSP->anAudioBuffer[0x11D] = 0x2B50;
    pRSP->anAudioBuffer[0x11E] = 0x559D;
    pRSP->anAudioBuffer[0x11F] = 0x001F;
    pRSP->anAudioBuffer[0x120] = 0xFF02;
    pRSP->anAudioBuffer[0x121] = 0x297A;
    pRSP->anAudioBuffer[0x122] = 0x5720;
    pRSP->anAudioBuffer[0x123] = 0x0063;
    pRSP->anAudioBuffer[0x124] = 0xFF10;
    pRSP->anAudioBuffer[0x125] = 0x27A9;
    pRSP->anAudioBuffer[0x126] = 0x5896;
    pRSP->anAudioBuffer[0x127] = 0x00AE;
    pRSP->anAudioBuffer[0x128] = 0xFF1E;
    pRSP->anAudioBuffer[0x129] = 0x25E0;
    pRSP->anAudioBuffer[0x12A] = 0x59FC;
    pRSP->anAudioBuffer[0x12B] = 0x0101;
    pRSP->anAudioBuffer[0x12C] = 0xFF2C;
    pRSP->anAudioBuffer[0x12D] = 0x241E;
    pRSP->anAudioBuffer[0x12E] = 0x5B53;
    pRSP->anAudioBuffer[0x12F] = 0x015B;
    pRSP->anAudioBuffer[0x130] = 0xFF3A;
    pRSP->anAudioBuffer[0x131] = 0x2264;
    pRSP->anAudioBuffer[0x132] = 0x5C9A;
    pRSP->anAudioBuffer[0x133] = 0x01BE;
    pRSP->anAudioBuffer[0x134] = 0xFF48;
    pRSP->anAudioBuffer[0x135] = 0x20B3;
    pRSP->anAudioBuffer[0x136] = 0x5DD0;
    pRSP->anAudioBuffer[0x137] = 0x022A;
    pRSP->anAudioBuffer[0x138] = 0xFF56;
    pRSP->anAudioBuffer[0x139] = 0x1F0B;
    pRSP->anAudioBuffer[0x13A] = 0x5EF5;
    pRSP->anAudioBuffer[0x13B] = 0x029F;
    pRSP->anAudioBuffer[0x13C] = 0xFF64;
    pRSP->anAudioBuffer[0x13D] = 0x1D6C;
    pRSP->anAudioBuffer[0x13E] = 0x6007;
    pRSP->anAudioBuffer[0x13F] = 0x031C;
    pRSP->anAudioBuffer[0x140] = 0xFF71;
    pRSP->anAudioBuffer[0x141] = 0x1BD7;
    pRSP->anAudioBuffer[0x142] = 0x6106;
    pRSP->anAudioBuffer[0x143] = 0x03A4;
    pRSP->anAudioBuffer[0x144] = 0xFF7E;
    pRSP->anAudioBuffer[0x145] = 0x1A4C;
    pRSP->anAudioBuffer[0x146] = 0x61F3;
    pRSP->anAudioBuffer[0x147] = 0x0435;
    pRSP->anAudioBuffer[0x148] = 0xFF8A;
    pRSP->anAudioBuffer[0x149] = 0x18CB;
    pRSP->anAudioBuffer[0x14A] = 0x62CB;
    pRSP->anAudioBuffer[0x14B] = 0x04D1;
    pRSP->anAudioBuffer[0x14C] = 0xFF96;
    pRSP->anAudioBuffer[0x14D] = 0x1756;
    pRSP->anAudioBuffer[0x14E] = 0x638F;
    pRSP->anAudioBuffer[0x14F] = 0x0577;
    pRSP->anAudioBuffer[0x150] = 0xFFA1;
    pRSP->anAudioBuffer[0x151] = 0x15EB;
    pRSP->anAudioBuffer[0x152] = 0x643F;
    pRSP->anAudioBuffer[0x153] = 0x0628;
    pRSP->anAudioBuffer[0x154] = 0xFFAC;
    pRSP->anAudioBuffer[0x155] = 0x148C;
    pRSP->anAudioBuffer[0x156] = 0x64D9;
    pRSP->anAudioBuffer[0x157] = 0x06E4;
    pRSP->anAudioBuffer[0x158] = 0xFFB6;
    pRSP->anAudioBuffer[0x159] = 0x1338;
    pRSP->anAudioBuffer[0x15A] = 0x655E;
    pRSP->anAudioBuffer[0x15B] = 0x07AB;
    pRSP->anAudioBuffer[0x15C] = 0xFFBF;
    pRSP->anAudioBuffer[0x15D] = 0x11F0;
    pRSP->anAudioBuffer[0x15E] = 0x65CD;
    pRSP->anAudioBuffer[0x15F] = 0x087D;
    pRSP->anAudioBuffer[0x160] = 0xFFC8;
    pRSP->anAudioBuffer[0x161] = 0x10B4;
    pRSP->anAudioBuffer[0x162] = 0x6626;
    pRSP->anAudioBuffer[0x163] = 0x095A;
    pRSP->anAudioBuffer[0x164] = 0xFFD0;
    pRSP->anAudioBuffer[0x165] = 0x0F83;
    pRSP->anAudioBuffer[0x166] = 0x6669;
    pRSP->anAudioBuffer[0x167] = 0x0A44;
    pRSP->anAudioBuffer[0x168] = 0xFFD8;
    pRSP->anAudioBuffer[0x169] = 0x0E5F;
    pRSP->anAudioBuffer[0x16A] = 0x6696;
    pRSP->anAudioBuffer[0x16B] = 0x0B39;
    pRSP->anAudioBuffer[0x16C] = 0xFFDF;
    pRSP->anAudioBuffer[0x16D] = 0x0D46;
    pRSP->anAudioBuffer[0x16E] = 0x66AD;
    pRSP->anAudioBuffer[0x16F] = 0x0C39;

    return true;
}

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAADPCMDec2Fast.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspANoise2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspANMix2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAResample2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAFirFilter2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAMix2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAInterleave2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspADistFilter2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAEnvMixer2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAPCM8Dec2.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseABI2.s")

static bool rspInitAudioDMEM3(Rsp* pRSP) {
    pRSP->anAudioBuffer = pRSP->pDMEM;

    pRSP->anAudioBuffer[0x000] = 0x0000;
    pRSP->anAudioBuffer[0x001] = 0x0001;
    pRSP->anAudioBuffer[0x002] = 0x0002;
    pRSP->anAudioBuffer[0x003] = 0xFFFF;
    pRSP->anAudioBuffer[0x004] = 0x0020;
    pRSP->anAudioBuffer[0x005] = 0x0800;
    pRSP->anAudioBuffer[0x006] = 0x7FFF;
    pRSP->anAudioBuffer[0x007] = 0x4000;
    pRSP->anAudioBuffer[0x008] = 0x1118;
    pRSP->anAudioBuffer[0x009] = 0x1350;
    pRSP->anAudioBuffer[0x00A] = 0x11DC;
    pRSP->anAudioBuffer[0x00B] = 0x1118;
    pRSP->anAudioBuffer[0x00C] = 0x1118;
    pRSP->anAudioBuffer[0x00D] = 0x175C;
    pRSP->anAudioBuffer[0x00E] = 0x1118;
    pRSP->anAudioBuffer[0x00F] = 0x1214;
    pRSP->anAudioBuffer[0x010] = 0x1230;
    pRSP->anAudioBuffer[0x011] = 0x1118;
    pRSP->anAudioBuffer[0x012] = 0x12EC;
    pRSP->anAudioBuffer[0x013] = 0x1CD0;
    pRSP->anAudioBuffer[0x014] = 0x1A18;
    pRSP->anAudioBuffer[0x015] = 0x126C;
    pRSP->anAudioBuffer[0x016] = 0x15EC;
    pRSP->anAudioBuffer[0x017] = 0x132C;
    pRSP->anAudioBuffer[0x018] = 0x1A8C;
    pRSP->anAudioBuffer[0x019] = 0x1ADC;
    pRSP->anAudioBuffer[0x01A] = 0x1C28;
    pRSP->anAudioBuffer[0x01B] = 0x1B38;
    pRSP->anAudioBuffer[0x01C] = 0x1C94;
    pRSP->anAudioBuffer[0x01D] = 0x1CB8;
    pRSP->anAudioBuffer[0x01E] = 0x1C50;
    pRSP->anAudioBuffer[0x01F] = 0x1118;
    pRSP->anAudioBuffer[0x020] = 0x1118;
    pRSP->anAudioBuffer[0x021] = 0x1118;
    pRSP->anAudioBuffer[0x022] = 0x1118;
    pRSP->anAudioBuffer[0x023] = 0x1118;
    pRSP->anAudioBuffer[0x024] = 0x1118;
    pRSP->anAudioBuffer[0x025] = 0x1118;
    pRSP->anAudioBuffer[0x026] = 0x1118;
    pRSP->anAudioBuffer[0x027] = 0x1118;
    pRSP->anAudioBuffer[0x028] = 0xF000;
    pRSP->anAudioBuffer[0x029] = 0x0F00;
    pRSP->anAudioBuffer[0x02A] = 0x00F0;
    pRSP->anAudioBuffer[0x02B] = 0x000F;
    pRSP->anAudioBuffer[0x02C] = 0x0001;
    pRSP->anAudioBuffer[0x02D] = 0x0010;
    pRSP->anAudioBuffer[0x02E] = 0x0100;
    pRSP->anAudioBuffer[0x02F] = 0x1000;
    pRSP->anAudioBuffer[0x030] = 0x0002;
    pRSP->anAudioBuffer[0x031] = 0x0004;
    pRSP->anAudioBuffer[0x032] = 0x0006;
    pRSP->anAudioBuffer[0x033] = 0x0008;
    pRSP->anAudioBuffer[0x034] = 0x000A;
    pRSP->anAudioBuffer[0x035] = 0x000C;
    pRSP->anAudioBuffer[0x036] = 0x000E;
    pRSP->anAudioBuffer[0x037] = 0x0010;
    pRSP->anAudioBuffer[0x038] = 0x0001;
    pRSP->anAudioBuffer[0x039] = 0x0001;
    pRSP->anAudioBuffer[0x03A] = 0x0001;
    pRSP->anAudioBuffer[0x03B] = 0x0001;
    pRSP->anAudioBuffer[0x03C] = 0x0001;
    pRSP->anAudioBuffer[0x03D] = 0x0001;
    pRSP->anAudioBuffer[0x03E] = 0x0001;
    pRSP->anAudioBuffer[0x03F] = 0x0001;
    pRSP->anAudioBuffer[0x040] = 0x0000;
    pRSP->anAudioBuffer[0x041] = 0x0001;
    pRSP->anAudioBuffer[0x042] = 0x0002;
    pRSP->anAudioBuffer[0x043] = 0x0004;
    pRSP->anAudioBuffer[0x044] = 0x0008;
    pRSP->anAudioBuffer[0x045] = 0x0010;
    pRSP->anAudioBuffer[0x046] = 0x0100;
    pRSP->anAudioBuffer[0x047] = 0x0200;
    pRSP->anAudioBuffer[0x048] = 0x0001;
    pRSP->anAudioBuffer[0x049] = 0x0000;
    pRSP->anAudioBuffer[0x04A] = 0x0000;
    pRSP->anAudioBuffer[0x04B] = 0x0000;
    pRSP->anAudioBuffer[0x04C] = 0x0001;
    pRSP->anAudioBuffer[0x04D] = 0x0000;
    pRSP->anAudioBuffer[0x04E] = 0x0000;
    pRSP->anAudioBuffer[0x04F] = 0x0000;
    pRSP->anAudioBuffer[0x050] = 0x0000;
    pRSP->anAudioBuffer[0x051] = 0x0001;
    pRSP->anAudioBuffer[0x052] = 0x0000;
    pRSP->anAudioBuffer[0x053] = 0x0000;
    pRSP->anAudioBuffer[0x054] = 0x0000;
    pRSP->anAudioBuffer[0x055] = 0x0001;
    pRSP->anAudioBuffer[0x056] = 0x0000;
    pRSP->anAudioBuffer[0x057] = 0x0000;
    pRSP->anAudioBuffer[0x058] = 0x0000;
    pRSP->anAudioBuffer[0x059] = 0x0000;
    pRSP->anAudioBuffer[0x05A] = 0x0001;
    pRSP->anAudioBuffer[0x05B] = 0x0000;
    pRSP->anAudioBuffer[0x05C] = 0x0000;
    pRSP->anAudioBuffer[0x05D] = 0x0000;
    pRSP->anAudioBuffer[0x05E] = 0x0001;
    pRSP->anAudioBuffer[0x05F] = 0x0000;
    // bug? 0x058-0x05F initialized twice with different values
    pRSP->anAudioBuffer[0x058] = 0x0000;
    pRSP->anAudioBuffer[0x059] = 0x0000;
    pRSP->anAudioBuffer[0x05A] = 0x0000;
    pRSP->anAudioBuffer[0x05B] = 0x0001;
    pRSP->anAudioBuffer[0x05C] = 0x0000;
    pRSP->anAudioBuffer[0x05D] = 0x0000;
    pRSP->anAudioBuffer[0x05E] = 0x0000;
    pRSP->anAudioBuffer[0x05F] = 0x0001;
    pRSP->anAudioBuffer[0x060] = 0x2000;
    pRSP->anAudioBuffer[0x061] = 0x4000;
    pRSP->anAudioBuffer[0x062] = 0x6000;
    pRSP->anAudioBuffer[0x063] = 0x8000;
    pRSP->anAudioBuffer[0x064] = 0xA000;
    pRSP->anAudioBuffer[0x065] = 0xC000;
    pRSP->anAudioBuffer[0x066] = 0xE000;
    pRSP->anAudioBuffer[0x067] = 0xFFFF;
    pRSP->anAudioBuffer[0x068] = 0x0000;
    pRSP->anAudioBuffer[0x069] = 0xFFFF;
    pRSP->anAudioBuffer[0x06A] = 0x0000;
    pRSP->anAudioBuffer[0x06B] = 0x0000;
    pRSP->anAudioBuffer[0x06C] = 0x0000;
    pRSP->anAudioBuffer[0x06D] = 0x0000;
    pRSP->anAudioBuffer[0x06E] = 0x0000;
    pRSP->anAudioBuffer[0x06F] = 0x0000;
    pRSP->anAudioBuffer[0x070] = 0x0000;
    pRSP->anAudioBuffer[0x071] = 0x0000;
    pRSP->anAudioBuffer[0x072] = 0x0000;
    pRSP->anAudioBuffer[0x073] = 0x0000;
    pRSP->anAudioBuffer[0x074] = 0x0000;
    pRSP->anAudioBuffer[0x075] = 0x0000;
    pRSP->anAudioBuffer[0x076] = 0x0000;
    pRSP->anAudioBuffer[0x077] = 0x0000;
    pRSP->anAudioBuffer[0x078] = 0x0C39;
    pRSP->anAudioBuffer[0x079] = 0x66AD;
    pRSP->anAudioBuffer[0x07A] = 0x0D46;
    pRSP->anAudioBuffer[0x07B] = 0xFFDF;
    pRSP->anAudioBuffer[0x07C] = 0x0B39;
    pRSP->anAudioBuffer[0x07D] = 0x6696;
    pRSP->anAudioBuffer[0x07E] = 0x0E5F;
    pRSP->anAudioBuffer[0x07F] = 0xFFD8;
    pRSP->anAudioBuffer[0x080] = 0x0A44;
    pRSP->anAudioBuffer[0x081] = 0x6669;
    pRSP->anAudioBuffer[0x082] = 0x0F83;
    pRSP->anAudioBuffer[0x083] = 0xFFD0;
    pRSP->anAudioBuffer[0x084] = 0x095A;
    pRSP->anAudioBuffer[0x085] = 0x6626;
    pRSP->anAudioBuffer[0x086] = 0x10B4;
    pRSP->anAudioBuffer[0x087] = 0xFFC8;
    pRSP->anAudioBuffer[0x088] = 0x087D;
    pRSP->anAudioBuffer[0x089] = 0x65CD;
    pRSP->anAudioBuffer[0x08A] = 0x11F0;
    pRSP->anAudioBuffer[0x08B] = 0xFFBF;
    pRSP->anAudioBuffer[0x08C] = 0x07AB;
    pRSP->anAudioBuffer[0x08D] = 0x655E;
    pRSP->anAudioBuffer[0x08E] = 0x1338;
    pRSP->anAudioBuffer[0x08F] = 0xFFB6;
    pRSP->anAudioBuffer[0x090] = 0x06E4;
    pRSP->anAudioBuffer[0x091] = 0x64D9;
    pRSP->anAudioBuffer[0x092] = 0x148C;
    pRSP->anAudioBuffer[0x093] = 0xFFAC;
    pRSP->anAudioBuffer[0x094] = 0x0628;
    pRSP->anAudioBuffer[0x095] = 0x643F;
    pRSP->anAudioBuffer[0x096] = 0x15EB;
    pRSP->anAudioBuffer[0x097] = 0xFFA1;
    pRSP->anAudioBuffer[0x098] = 0x0577;
    pRSP->anAudioBuffer[0x099] = 0x638F;
    pRSP->anAudioBuffer[0x09A] = 0x1756;
    pRSP->anAudioBuffer[0x09B] = 0xFF96;
    pRSP->anAudioBuffer[0x09C] = 0x04D1;
    pRSP->anAudioBuffer[0x09D] = 0x62CB;
    pRSP->anAudioBuffer[0x09E] = 0x18CB;
    pRSP->anAudioBuffer[0x09F] = 0xFF8A;
    pRSP->anAudioBuffer[0x0A0] = 0x0435;
    pRSP->anAudioBuffer[0x0A1] = 0x61F3;
    pRSP->anAudioBuffer[0x0A2] = 0x1A4C;
    pRSP->anAudioBuffer[0x0A3] = 0xFF7E;
    pRSP->anAudioBuffer[0x0A4] = 0x03A4;
    pRSP->anAudioBuffer[0x0A5] = 0x6106;
    pRSP->anAudioBuffer[0x0A6] = 0x1BD7;
    pRSP->anAudioBuffer[0x0A7] = 0xFF71;
    pRSP->anAudioBuffer[0x0A8] = 0x031C;
    pRSP->anAudioBuffer[0x0A9] = 0x6007;
    pRSP->anAudioBuffer[0x0AA] = 0x1D6C;
    pRSP->anAudioBuffer[0x0AB] = 0xFF64;
    pRSP->anAudioBuffer[0x0AC] = 0x029F;
    pRSP->anAudioBuffer[0x0AD] = 0x5EF5;
    pRSP->anAudioBuffer[0x0AE] = 0x1F0B;
    pRSP->anAudioBuffer[0x0AF] = 0xFF56;
    pRSP->anAudioBuffer[0x0B0] = 0x022A;
    pRSP->anAudioBuffer[0x0B1] = 0x5DD0;
    pRSP->anAudioBuffer[0x0B2] = 0x20B3;
    pRSP->anAudioBuffer[0x0B3] = 0xFF48;
    pRSP->anAudioBuffer[0x0B4] = 0x01BE;
    pRSP->anAudioBuffer[0x0B5] = 0x5C9A;
    pRSP->anAudioBuffer[0x0B6] = 0x2264;
    pRSP->anAudioBuffer[0x0B7] = 0xFF3A;
    pRSP->anAudioBuffer[0x0B8] = 0x015B;
    pRSP->anAudioBuffer[0x0B9] = 0x5B53;
    pRSP->anAudioBuffer[0x0BA] = 0x241E;
    pRSP->anAudioBuffer[0x0BB] = 0xFF2C;
    pRSP->anAudioBuffer[0x0BC] = 0x0101;
    pRSP->anAudioBuffer[0x0BD] = 0x59FC;
    pRSP->anAudioBuffer[0x0BE] = 0x25E0;
    pRSP->anAudioBuffer[0x0BF] = 0xFF1E;
    pRSP->anAudioBuffer[0x0C0] = 0x00AE;
    pRSP->anAudioBuffer[0x0C1] = 0x5896;
    pRSP->anAudioBuffer[0x0C2] = 0x27A9;
    pRSP->anAudioBuffer[0x0C3] = 0xFF10;
    pRSP->anAudioBuffer[0x0C4] = 0x0063;
    pRSP->anAudioBuffer[0x0C5] = 0x5720;
    pRSP->anAudioBuffer[0x0C6] = 0x297A;
    pRSP->anAudioBuffer[0x0C7] = 0xFF02;
    pRSP->anAudioBuffer[0x0C8] = 0x001F;
    pRSP->anAudioBuffer[0x0C9] = 0x559D;
    pRSP->anAudioBuffer[0x0CA] = 0x2B50;
    pRSP->anAudioBuffer[0x0CB] = 0xFEF4;
    pRSP->anAudioBuffer[0x0CC] = 0xFFE2;
    pRSP->anAudioBuffer[0x0CD] = 0x540D;
    pRSP->anAudioBuffer[0x0CE] = 0x2D2C;
    pRSP->anAudioBuffer[0x0CF] = 0xFEE8;
    pRSP->anAudioBuffer[0x0D0] = 0xFFAC;
    pRSP->anAudioBuffer[0x0D1] = 0x5270;
    pRSP->anAudioBuffer[0x0D2] = 0x2F0D;
    pRSP->anAudioBuffer[0x0D3] = 0xFEDB;
    pRSP->anAudioBuffer[0x0D4] = 0xFF7C;
    pRSP->anAudioBuffer[0x0D5] = 0x50C7;
    pRSP->anAudioBuffer[0x0D6] = 0x30F3;
    pRSP->anAudioBuffer[0x0D7] = 0xFED0;
    pRSP->anAudioBuffer[0x0D8] = 0xFF53;
    pRSP->anAudioBuffer[0x0D9] = 0x4F14;
    pRSP->anAudioBuffer[0x0DA] = 0x32DC;
    pRSP->anAudioBuffer[0x0DB] = 0xFEC6;
    pRSP->anAudioBuffer[0x0DC] = 0xFF2E;
    pRSP->anAudioBuffer[0x0DD] = 0x4D57;
    pRSP->anAudioBuffer[0x0DE] = 0x34C8;
    pRSP->anAudioBuffer[0x0DF] = 0xFEBD;
    pRSP->anAudioBuffer[0x0E0] = 0xFF0F;
    pRSP->anAudioBuffer[0x0E1] = 0x4B91;
    pRSP->anAudioBuffer[0x0E2] = 0x36B6;
    pRSP->anAudioBuffer[0x0E3] = 0xFEB6;
    pRSP->anAudioBuffer[0x0E4] = 0xFEF5;
    pRSP->anAudioBuffer[0x0E5] = 0x49C2;
    pRSP->anAudioBuffer[0x0E6] = 0x38A5;
    pRSP->anAudioBuffer[0x0E7] = 0xFEB0;
    pRSP->anAudioBuffer[0x0E8] = 0xFEDF;
    pRSP->anAudioBuffer[0x0E9] = 0x47ED;
    pRSP->anAudioBuffer[0x0EA] = 0x3A95;
    pRSP->anAudioBuffer[0x0EB] = 0xFEAC;
    pRSP->anAudioBuffer[0x0EC] = 0xFECE;
    pRSP->anAudioBuffer[0x0ED] = 0x4611;
    pRSP->anAudioBuffer[0x0EE] = 0x3C85;
    pRSP->anAudioBuffer[0x0EF] = 0xFEAB;
    pRSP->anAudioBuffer[0x0F0] = 0xFEC0;
    pRSP->anAudioBuffer[0x0F1] = 0x4430;
    pRSP->anAudioBuffer[0x0F2] = 0x3E74;
    pRSP->anAudioBuffer[0x0F3] = 0xFEAC;
    pRSP->anAudioBuffer[0x0F4] = 0xFEB6;
    pRSP->anAudioBuffer[0x0F5] = 0x424A;
    pRSP->anAudioBuffer[0x0F6] = 0x4060;
    pRSP->anAudioBuffer[0x0F7] = 0xFEAF;
    pRSP->anAudioBuffer[0x0F8] = 0xFEAF;
    pRSP->anAudioBuffer[0x0F9] = 0x4060;
    pRSP->anAudioBuffer[0x0FA] = 0x424A;
    pRSP->anAudioBuffer[0x0FB] = 0xFEB6;
    pRSP->anAudioBuffer[0x0FC] = 0xFEAC;
    pRSP->anAudioBuffer[0x0FD] = 0x3E74;
    pRSP->anAudioBuffer[0x0FE] = 0x4430;
    pRSP->anAudioBuffer[0x0FF] = 0xFEC0;
    pRSP->anAudioBuffer[0x100] = 0xFEAB;
    pRSP->anAudioBuffer[0x101] = 0x3C85;
    pRSP->anAudioBuffer[0x102] = 0x4611;
    pRSP->anAudioBuffer[0x103] = 0xFECE;
    pRSP->anAudioBuffer[0x104] = 0xFEAC;
    pRSP->anAudioBuffer[0x105] = 0x3A95;
    pRSP->anAudioBuffer[0x106] = 0x47ED;
    pRSP->anAudioBuffer[0x107] = 0xFEDF;
    pRSP->anAudioBuffer[0x108] = 0xFEB0;
    pRSP->anAudioBuffer[0x109] = 0x38A5;
    pRSP->anAudioBuffer[0x10A] = 0x49C2;
    pRSP->anAudioBuffer[0x10B] = 0xFEF5;
    pRSP->anAudioBuffer[0x10C] = 0xFEB6;
    pRSP->anAudioBuffer[0x10D] = 0x36B6;
    pRSP->anAudioBuffer[0x10E] = 0x4B91;
    pRSP->anAudioBuffer[0x10F] = 0xFF0F;
    pRSP->anAudioBuffer[0x110] = 0xFEBD;
    pRSP->anAudioBuffer[0x111] = 0x34C8;
    pRSP->anAudioBuffer[0x112] = 0x4D57;
    pRSP->anAudioBuffer[0x113] = 0xFF2E;
    pRSP->anAudioBuffer[0x114] = 0xFEC6;
    pRSP->anAudioBuffer[0x115] = 0x32DC;
    pRSP->anAudioBuffer[0x116] = 0x4F14;
    pRSP->anAudioBuffer[0x117] = 0xFF53;
    pRSP->anAudioBuffer[0x118] = 0xFED0;
    pRSP->anAudioBuffer[0x119] = 0x30F3;
    pRSP->anAudioBuffer[0x11A] = 0x50C7;
    pRSP->anAudioBuffer[0x11B] = 0xFF7C;
    pRSP->anAudioBuffer[0x11C] = 0xFEDB;
    pRSP->anAudioBuffer[0x11D] = 0x2F0D;
    pRSP->anAudioBuffer[0x11E] = 0x5270;
    pRSP->anAudioBuffer[0x11F] = 0xFFAC;
    pRSP->anAudioBuffer[0x120] = 0xFEE8;
    pRSP->anAudioBuffer[0x121] = 0x2D2C;
    pRSP->anAudioBuffer[0x122] = 0x540D;
    pRSP->anAudioBuffer[0x123] = 0xFFE2;
    pRSP->anAudioBuffer[0x124] = 0xFEF4;
    pRSP->anAudioBuffer[0x125] = 0x2B50;
    pRSP->anAudioBuffer[0x126] = 0x559D;
    pRSP->anAudioBuffer[0x127] = 0x001F;
    pRSP->anAudioBuffer[0x128] = 0xFF02;
    pRSP->anAudioBuffer[0x129] = 0x297A;
    pRSP->anAudioBuffer[0x12A] = 0x5720;
    pRSP->anAudioBuffer[0x12B] = 0x0063;
    pRSP->anAudioBuffer[0x12C] = 0xFF10;
    pRSP->anAudioBuffer[0x12D] = 0x27A9;
    pRSP->anAudioBuffer[0x12E] = 0x5896;
    pRSP->anAudioBuffer[0x12F] = 0x00AE;
    pRSP->anAudioBuffer[0x130] = 0xFF1E;
    pRSP->anAudioBuffer[0x131] = 0x25E0;
    pRSP->anAudioBuffer[0x132] = 0x59FC;
    pRSP->anAudioBuffer[0x133] = 0x0101;
    pRSP->anAudioBuffer[0x134] = 0xFF2C;
    pRSP->anAudioBuffer[0x135] = 0x241E;
    pRSP->anAudioBuffer[0x136] = 0x5B53;
    pRSP->anAudioBuffer[0x137] = 0x015B;
    pRSP->anAudioBuffer[0x138] = 0xFF3A;
    pRSP->anAudioBuffer[0x139] = 0x2264;
    pRSP->anAudioBuffer[0x13A] = 0x5C9A;
    pRSP->anAudioBuffer[0x13B] = 0x01BE;
    pRSP->anAudioBuffer[0x13C] = 0xFF48;
    pRSP->anAudioBuffer[0x13D] = 0x20B3;
    pRSP->anAudioBuffer[0x13E] = 0x5DD0;
    pRSP->anAudioBuffer[0x13F] = 0x022A;
    pRSP->anAudioBuffer[0x140] = 0xFF56;
    pRSP->anAudioBuffer[0x141] = 0x1F0B;
    pRSP->anAudioBuffer[0x142] = 0x5EF5;
    pRSP->anAudioBuffer[0x143] = 0x029F;
    pRSP->anAudioBuffer[0x144] = 0xFF64;
    pRSP->anAudioBuffer[0x145] = 0x1D6C;
    pRSP->anAudioBuffer[0x146] = 0x6007;
    pRSP->anAudioBuffer[0x147] = 0x031C;
    pRSP->anAudioBuffer[0x148] = 0xFF71;
    pRSP->anAudioBuffer[0x149] = 0x1BD7;
    pRSP->anAudioBuffer[0x14A] = 0x6106;
    pRSP->anAudioBuffer[0x14B] = 0x03A4;
    pRSP->anAudioBuffer[0x14C] = 0xFF7E;
    pRSP->anAudioBuffer[0x14D] = 0x1A4C;
    pRSP->anAudioBuffer[0x14E] = 0x61F3;
    pRSP->anAudioBuffer[0x14F] = 0x0435;
    pRSP->anAudioBuffer[0x150] = 0xFF8A;
    pRSP->anAudioBuffer[0x151] = 0x18CB;
    pRSP->anAudioBuffer[0x152] = 0x62CB;
    pRSP->anAudioBuffer[0x153] = 0x04D1;
    pRSP->anAudioBuffer[0x154] = 0xFF96;
    pRSP->anAudioBuffer[0x155] = 0x1756;
    pRSP->anAudioBuffer[0x156] = 0x638F;
    pRSP->anAudioBuffer[0x157] = 0x0577;
    pRSP->anAudioBuffer[0x158] = 0xFFA1;
    pRSP->anAudioBuffer[0x159] = 0x15EB;
    pRSP->anAudioBuffer[0x15A] = 0x643F;
    pRSP->anAudioBuffer[0x15B] = 0x0628;
    pRSP->anAudioBuffer[0x15C] = 0xFFAC;
    pRSP->anAudioBuffer[0x15D] = 0x148C;
    pRSP->anAudioBuffer[0x15E] = 0x64D9;
    pRSP->anAudioBuffer[0x15F] = 0x06E4;
    pRSP->anAudioBuffer[0x160] = 0xFFB6;
    pRSP->anAudioBuffer[0x161] = 0x1338;
    pRSP->anAudioBuffer[0x162] = 0x655E;
    pRSP->anAudioBuffer[0x163] = 0x07AB;
    pRSP->anAudioBuffer[0x164] = 0xFFBF;
    pRSP->anAudioBuffer[0x165] = 0x11F0;
    pRSP->anAudioBuffer[0x166] = 0x65CD;
    pRSP->anAudioBuffer[0x167] = 0x087D;
    pRSP->anAudioBuffer[0x168] = 0xFFC8;
    pRSP->anAudioBuffer[0x169] = 0x10B4;
    pRSP->anAudioBuffer[0x16A] = 0x6626;
    pRSP->anAudioBuffer[0x16B] = 0x095A;
    pRSP->anAudioBuffer[0x16C] = 0xFFD0;
    pRSP->anAudioBuffer[0x16D] = 0x0F83;
    pRSP->anAudioBuffer[0x16E] = 0x6669;
    pRSP->anAudioBuffer[0x16F] = 0x0A44;
    pRSP->anAudioBuffer[0x170] = 0xFFD8;
    pRSP->anAudioBuffer[0x171] = 0x0E5F;
    pRSP->anAudioBuffer[0x172] = 0x6696;
    pRSP->anAudioBuffer[0x173] = 0x0B39;
    pRSP->anAudioBuffer[0x174] = 0xFFDF;
    pRSP->anAudioBuffer[0x175] = 0x0D46;
    pRSP->anAudioBuffer[0x176] = 0x66AD;
    pRSP->anAudioBuffer[0x177] = 0x0C39;

    return true;
}

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAEnvMixer3.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspAMix3.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseABI3.s")

static bool rspInitAudioDMEM4(Rsp* pRSP) {
    pRSP->anAudioBuffer = pRSP->pDMEM;

    pRSP->anAudioBuffer[0x000] = 0x0000;
    pRSP->anAudioBuffer[0x001] = 0x0001;
    pRSP->anAudioBuffer[0x002] = 0x0002;
    pRSP->anAudioBuffer[0x003] = 0xFFFF;
    pRSP->anAudioBuffer[0x004] = 0x0020;
    pRSP->anAudioBuffer[0x005] = 0x0800;
    pRSP->anAudioBuffer[0x006] = 0x7FFF;
    pRSP->anAudioBuffer[0x007] = 0x4000;
    pRSP->anAudioBuffer[0x008] = 0x1118;
    pRSP->anAudioBuffer[0x009] = 0x12E0;
    pRSP->anAudioBuffer[0x00A] = 0x11DC;
    pRSP->anAudioBuffer[0x00B] = 0x1118;
    pRSP->anAudioBuffer[0x00C] = 0x1E8C;
    pRSP->anAudioBuffer[0x00D] = 0x1568;
    pRSP->anAudioBuffer[0x00E] = 0x1EFC;
    pRSP->anAudioBuffer[0x00F] = 0x1118;
    pRSP->anAudioBuffer[0x010] = 0x120C;
    pRSP->anAudioBuffer[0x011] = 0x1118;
    pRSP->anAudioBuffer[0x012] = 0x1298;
    pRSP->anAudioBuffer[0x013] = 0x1B24;
    pRSP->anAudioBuffer[0x014] = 0x1B40;
    pRSP->anAudioBuffer[0x015] = 0x1220;
    pRSP->anAudioBuffer[0x016] = 0x1D30;
    pRSP->anAudioBuffer[0x017] = 0x12D0;
    pRSP->anAudioBuffer[0x018] = 0x1818;
    pRSP->anAudioBuffer[0x019] = 0x18C4;
    pRSP->anAudioBuffer[0x01A] = 0x1A84;
    pRSP->anAudioBuffer[0x01B] = 0x1918;
    pRSP->anAudioBuffer[0x01C] = 0x1AE8;
    pRSP->anAudioBuffer[0x01D] = 0x1B0C;
    pRSP->anAudioBuffer[0x01E] = 0x1AAC;
    pRSP->anAudioBuffer[0x01F] = 0x1BAC;
    pRSP->anAudioBuffer[0x020] = 0x1C5C;
    pRSP->anAudioBuffer[0x021] = 0x1CB0;
    pRSP->anAudioBuffer[0x022] = 0x1860;
    pRSP->anAudioBuffer[0x023] = 0x1118;
    pRSP->anAudioBuffer[0x024] = 0x1118;
    pRSP->anAudioBuffer[0x025] = 0x1118;
    pRSP->anAudioBuffer[0x026] = 0x1118;
    pRSP->anAudioBuffer[0x027] = 0x1118;
    pRSP->anAudioBuffer[0x028] = 0xF000;
    pRSP->anAudioBuffer[0x029] = 0x0F00;
    pRSP->anAudioBuffer[0x02A] = 0x00F0;
    pRSP->anAudioBuffer[0x02B] = 0x000F;
    pRSP->anAudioBuffer[0x02C] = 0x0001;
    pRSP->anAudioBuffer[0x02D] = 0x0010;
    pRSP->anAudioBuffer[0x02E] = 0x0100;
    pRSP->anAudioBuffer[0x02F] = 0x1000;
    pRSP->anAudioBuffer[0x030] = 0x0002;
    pRSP->anAudioBuffer[0x031] = 0x0004;
    pRSP->anAudioBuffer[0x032] = 0x0006;
    pRSP->anAudioBuffer[0x033] = 0x0008;
    pRSP->anAudioBuffer[0x034] = 0x000A;
    pRSP->anAudioBuffer[0x035] = 0x000C;
    pRSP->anAudioBuffer[0x036] = 0x000E;
    pRSP->anAudioBuffer[0x037] = 0x0010;
    pRSP->anAudioBuffer[0x038] = 0x0001;
    pRSP->anAudioBuffer[0x039] = 0x0001;
    pRSP->anAudioBuffer[0x03A] = 0x0001;
    pRSP->anAudioBuffer[0x03B] = 0x0001;
    pRSP->anAudioBuffer[0x03C] = 0x0001;
    pRSP->anAudioBuffer[0x03D] = 0x0001;
    pRSP->anAudioBuffer[0x03E] = 0x0001;
    pRSP->anAudioBuffer[0x03F] = 0x0001;
    pRSP->anAudioBuffer[0x040] = 0x0000;
    pRSP->anAudioBuffer[0x041] = 0x0001;
    pRSP->anAudioBuffer[0x042] = 0x0002;
    pRSP->anAudioBuffer[0x043] = 0x0004;
    pRSP->anAudioBuffer[0x044] = 0x0008;
    pRSP->anAudioBuffer[0x045] = 0x0010;
    pRSP->anAudioBuffer[0x046] = 0x0100;
    pRSP->anAudioBuffer[0x047] = 0x0200;
    pRSP->anAudioBuffer[0x048] = 0x0001;
    pRSP->anAudioBuffer[0x049] = 0x0000;
    pRSP->anAudioBuffer[0x04A] = 0x0000;
    pRSP->anAudioBuffer[0x04B] = 0x0000;
    pRSP->anAudioBuffer[0x04C] = 0x0001;
    pRSP->anAudioBuffer[0x04D] = 0x0000;
    pRSP->anAudioBuffer[0x04E] = 0x0000;
    pRSP->anAudioBuffer[0x04F] = 0x0000;
    pRSP->anAudioBuffer[0x050] = 0x0000;
    pRSP->anAudioBuffer[0x051] = 0x0001;
    pRSP->anAudioBuffer[0x052] = 0x0000;
    pRSP->anAudioBuffer[0x053] = 0x0000;
    pRSP->anAudioBuffer[0x054] = 0x0000;
    pRSP->anAudioBuffer[0x055] = 0x0001;
    pRSP->anAudioBuffer[0x056] = 0x0000;
    pRSP->anAudioBuffer[0x057] = 0x0000;
    pRSP->anAudioBuffer[0x058] = 0x0000;
    pRSP->anAudioBuffer[0x059] = 0x0000;
    pRSP->anAudioBuffer[0x05A] = 0x0001;
    pRSP->anAudioBuffer[0x05B] = 0x0000;
    pRSP->anAudioBuffer[0x05C] = 0x0000;
    pRSP->anAudioBuffer[0x05D] = 0x0000;
    pRSP->anAudioBuffer[0x05E] = 0x0001;
    pRSP->anAudioBuffer[0x05F] = 0x0000;
    // bug? 0x058-0x05F initialized twice with different values
    pRSP->anAudioBuffer[0x058] = 0x0000;
    pRSP->anAudioBuffer[0x059] = 0x0000;
    pRSP->anAudioBuffer[0x05A] = 0x0000;
    pRSP->anAudioBuffer[0x05B] = 0x0001;
    pRSP->anAudioBuffer[0x05C] = 0x0000;
    pRSP->anAudioBuffer[0x05D] = 0x0000;
    pRSP->anAudioBuffer[0x05E] = 0x0000;
    pRSP->anAudioBuffer[0x05F] = 0x0001;
    pRSP->anAudioBuffer[0x060] = 0x2000;
    pRSP->anAudioBuffer[0x061] = 0x4000;
    pRSP->anAudioBuffer[0x062] = 0x6000;
    pRSP->anAudioBuffer[0x063] = 0x8000;
    pRSP->anAudioBuffer[0x064] = 0xA000;
    pRSP->anAudioBuffer[0x065] = 0xC000;
    pRSP->anAudioBuffer[0x066] = 0xE000;
    pRSP->anAudioBuffer[0x067] = 0xFFFF;
    pRSP->anAudioBuffer[0x068] = 0x0000;
    pRSP->anAudioBuffer[0x069] = 0xFFFF;
    pRSP->anAudioBuffer[0x06A] = 0x0000;
    pRSP->anAudioBuffer[0x06B] = 0x0000;
    pRSP->anAudioBuffer[0x06C] = 0x0000;
    pRSP->anAudioBuffer[0x06D] = 0x0000;
    pRSP->anAudioBuffer[0x06E] = 0x0000;
    pRSP->anAudioBuffer[0x06F] = 0x0000;
    pRSP->anAudioBuffer[0x070] = 0x0000;
    pRSP->anAudioBuffer[0x071] = 0x0000;
    pRSP->anAudioBuffer[0x072] = 0x0000;
    pRSP->anAudioBuffer[0x073] = 0x0000;
    pRSP->anAudioBuffer[0x074] = 0x0000;
    pRSP->anAudioBuffer[0x075] = 0x0000;
    pRSP->anAudioBuffer[0x076] = 0x0000;
    pRSP->anAudioBuffer[0x077] = 0x0000;
    pRSP->anAudioBuffer[0x078] = 0x0C39;
    pRSP->anAudioBuffer[0x079] = 0x66AD;
    pRSP->anAudioBuffer[0x07A] = 0x0D46;
    pRSP->anAudioBuffer[0x07B] = 0xFFDF;
    pRSP->anAudioBuffer[0x07C] = 0x0B39;
    pRSP->anAudioBuffer[0x07D] = 0x6696;
    pRSP->anAudioBuffer[0x07E] = 0x0E5F;
    pRSP->anAudioBuffer[0x07F] = 0xFFD8;
    pRSP->anAudioBuffer[0x080] = 0x0A44;
    pRSP->anAudioBuffer[0x081] = 0x6669;
    pRSP->anAudioBuffer[0x082] = 0x0F83;
    pRSP->anAudioBuffer[0x083] = 0xFFD0;
    pRSP->anAudioBuffer[0x084] = 0x095A;
    pRSP->anAudioBuffer[0x085] = 0x6626;
    pRSP->anAudioBuffer[0x086] = 0x10B4;
    pRSP->anAudioBuffer[0x087] = 0xFFC8;
    pRSP->anAudioBuffer[0x088] = 0x087D;
    pRSP->anAudioBuffer[0x089] = 0x65CD;
    pRSP->anAudioBuffer[0x08A] = 0x11F0;
    pRSP->anAudioBuffer[0x08B] = 0xFFBF;
    pRSP->anAudioBuffer[0x08C] = 0x07AB;
    pRSP->anAudioBuffer[0x08D] = 0x655E;
    pRSP->anAudioBuffer[0x08E] = 0x1338;
    pRSP->anAudioBuffer[0x08F] = 0xFFB6;
    pRSP->anAudioBuffer[0x090] = 0x06E4;
    pRSP->anAudioBuffer[0x091] = 0x64D9;
    pRSP->anAudioBuffer[0x092] = 0x148C;
    pRSP->anAudioBuffer[0x093] = 0xFFAC;
    pRSP->anAudioBuffer[0x094] = 0x0628;
    pRSP->anAudioBuffer[0x095] = 0x643F;
    pRSP->anAudioBuffer[0x096] = 0x15EB;
    pRSP->anAudioBuffer[0x097] = 0xFFA1;
    pRSP->anAudioBuffer[0x098] = 0x0577;
    pRSP->anAudioBuffer[0x099] = 0x638F;
    pRSP->anAudioBuffer[0x09A] = 0x1756;
    pRSP->anAudioBuffer[0x09B] = 0xFF96;
    pRSP->anAudioBuffer[0x09C] = 0x04D1;
    pRSP->anAudioBuffer[0x09D] = 0x62CB;
    pRSP->anAudioBuffer[0x09E] = 0x18CB;
    pRSP->anAudioBuffer[0x09F] = 0xFF8A;
    pRSP->anAudioBuffer[0x0A0] = 0x0435;
    pRSP->anAudioBuffer[0x0A1] = 0x61F3;
    pRSP->anAudioBuffer[0x0A2] = 0x1A4C;
    pRSP->anAudioBuffer[0x0A3] = 0xFF7E;
    pRSP->anAudioBuffer[0x0A4] = 0x03A4;
    pRSP->anAudioBuffer[0x0A5] = 0x6106;
    pRSP->anAudioBuffer[0x0A6] = 0x1BD7;
    pRSP->anAudioBuffer[0x0A7] = 0xFF71;
    pRSP->anAudioBuffer[0x0A8] = 0x031C;
    pRSP->anAudioBuffer[0x0A9] = 0x6007;
    pRSP->anAudioBuffer[0x0AA] = 0x1D6C;
    pRSP->anAudioBuffer[0x0AB] = 0xFF64;
    pRSP->anAudioBuffer[0x0AC] = 0x029F;
    pRSP->anAudioBuffer[0x0AD] = 0x5EF5;
    pRSP->anAudioBuffer[0x0AE] = 0x1F0B;
    pRSP->anAudioBuffer[0x0AF] = 0xFF56;
    pRSP->anAudioBuffer[0x0B0] = 0x022A;
    pRSP->anAudioBuffer[0x0B1] = 0x5DD0;
    pRSP->anAudioBuffer[0x0B2] = 0x20B3;
    pRSP->anAudioBuffer[0x0B3] = 0xFF48;
    pRSP->anAudioBuffer[0x0B4] = 0x01BE;
    pRSP->anAudioBuffer[0x0B5] = 0x5C9A;
    pRSP->anAudioBuffer[0x0B6] = 0x2264;
    pRSP->anAudioBuffer[0x0B7] = 0xFF3A;
    pRSP->anAudioBuffer[0x0B8] = 0x015B;
    pRSP->anAudioBuffer[0x0B9] = 0x5B53;
    pRSP->anAudioBuffer[0x0BA] = 0x241E;
    pRSP->anAudioBuffer[0x0BB] = 0xFF2C;
    pRSP->anAudioBuffer[0x0BC] = 0x0101;
    pRSP->anAudioBuffer[0x0BD] = 0x59FC;
    pRSP->anAudioBuffer[0x0BE] = 0x25E0;
    pRSP->anAudioBuffer[0x0BF] = 0xFF1E;
    pRSP->anAudioBuffer[0x0C0] = 0x00AE;
    pRSP->anAudioBuffer[0x0C1] = 0x5896;
    pRSP->anAudioBuffer[0x0C2] = 0x27A9;
    pRSP->anAudioBuffer[0x0C3] = 0xFF10;
    pRSP->anAudioBuffer[0x0C4] = 0x0063;
    pRSP->anAudioBuffer[0x0C5] = 0x5720;
    pRSP->anAudioBuffer[0x0C6] = 0x297A;
    pRSP->anAudioBuffer[0x0C7] = 0xFF02;
    pRSP->anAudioBuffer[0x0C8] = 0x001F;
    pRSP->anAudioBuffer[0x0C9] = 0x559D;
    pRSP->anAudioBuffer[0x0CA] = 0x2B50;
    pRSP->anAudioBuffer[0x0CB] = 0xFEF4;
    pRSP->anAudioBuffer[0x0CC] = 0xFFE2;
    pRSP->anAudioBuffer[0x0CD] = 0x540D;
    pRSP->anAudioBuffer[0x0CE] = 0x2D2C;
    pRSP->anAudioBuffer[0x0CF] = 0xFEE8;
    pRSP->anAudioBuffer[0x0D0] = 0xFFAC;
    pRSP->anAudioBuffer[0x0D1] = 0x5270;
    pRSP->anAudioBuffer[0x0D2] = 0x2F0D;
    pRSP->anAudioBuffer[0x0D3] = 0xFEDB;
    pRSP->anAudioBuffer[0x0D4] = 0xFF7C;
    pRSP->anAudioBuffer[0x0D5] = 0x50C7;
    pRSP->anAudioBuffer[0x0D6] = 0x30F3;
    pRSP->anAudioBuffer[0x0D7] = 0xFED0;
    pRSP->anAudioBuffer[0x0D8] = 0xFF53;
    pRSP->anAudioBuffer[0x0D9] = 0x4F14;
    pRSP->anAudioBuffer[0x0DA] = 0x32DC;
    pRSP->anAudioBuffer[0x0DB] = 0xFEC6;
    pRSP->anAudioBuffer[0x0DC] = 0xFF2E;
    pRSP->anAudioBuffer[0x0DD] = 0x4D57;
    pRSP->anAudioBuffer[0x0DE] = 0x34C8;
    pRSP->anAudioBuffer[0x0DF] = 0xFEBD;
    pRSP->anAudioBuffer[0x0E0] = 0xFF0F;
    pRSP->anAudioBuffer[0x0E1] = 0x4B91;
    pRSP->anAudioBuffer[0x0E2] = 0x36B6;
    pRSP->anAudioBuffer[0x0E3] = 0xFEB6;
    pRSP->anAudioBuffer[0x0E4] = 0xFEF5;
    pRSP->anAudioBuffer[0x0E5] = 0x49C2;
    pRSP->anAudioBuffer[0x0E6] = 0x38A5;
    pRSP->anAudioBuffer[0x0E7] = 0xFEB0;
    pRSP->anAudioBuffer[0x0E8] = 0xFEDF;
    pRSP->anAudioBuffer[0x0E9] = 0x47ED;
    pRSP->anAudioBuffer[0x0EA] = 0x3A95;
    pRSP->anAudioBuffer[0x0EB] = 0xFEAC;
    pRSP->anAudioBuffer[0x0EC] = 0xFECE;
    pRSP->anAudioBuffer[0x0ED] = 0x4611;
    pRSP->anAudioBuffer[0x0EE] = 0x3C85;
    pRSP->anAudioBuffer[0x0EF] = 0xFEAB;
    pRSP->anAudioBuffer[0x0F0] = 0xFEC0;
    pRSP->anAudioBuffer[0x0F1] = 0x4430;
    pRSP->anAudioBuffer[0x0F2] = 0x3E74;
    pRSP->anAudioBuffer[0x0F3] = 0xFEAC;
    pRSP->anAudioBuffer[0x0F4] = 0xFEB6;
    pRSP->anAudioBuffer[0x0F5] = 0x424A;
    pRSP->anAudioBuffer[0x0F6] = 0x4060;
    pRSP->anAudioBuffer[0x0F7] = 0xFEAF;
    pRSP->anAudioBuffer[0x0F8] = 0xFEAF;
    pRSP->anAudioBuffer[0x0F9] = 0x4060;
    pRSP->anAudioBuffer[0x0FA] = 0x424A;
    pRSP->anAudioBuffer[0x0FB] = 0xFEB6;
    pRSP->anAudioBuffer[0x0FC] = 0xFEAC;
    pRSP->anAudioBuffer[0x0FD] = 0x3E74;
    pRSP->anAudioBuffer[0x0FE] = 0x4430;
    pRSP->anAudioBuffer[0x0FF] = 0xFEC0;
    pRSP->anAudioBuffer[0x100] = 0xFEAB;
    pRSP->anAudioBuffer[0x101] = 0x3C85;
    pRSP->anAudioBuffer[0x102] = 0x4611;
    pRSP->anAudioBuffer[0x103] = 0xFECE;
    pRSP->anAudioBuffer[0x104] = 0xFEAC;
    pRSP->anAudioBuffer[0x105] = 0x3A95;
    pRSP->anAudioBuffer[0x106] = 0x47ED;
    pRSP->anAudioBuffer[0x107] = 0xFEDF;
    pRSP->anAudioBuffer[0x108] = 0xFEB0;
    pRSP->anAudioBuffer[0x109] = 0x38A5;
    pRSP->anAudioBuffer[0x10A] = 0x49C2;
    pRSP->anAudioBuffer[0x10B] = 0xFEF5;
    pRSP->anAudioBuffer[0x10C] = 0xFEB6;
    pRSP->anAudioBuffer[0x10D] = 0x36B6;
    pRSP->anAudioBuffer[0x10E] = 0x4B91;
    pRSP->anAudioBuffer[0x10F] = 0xFF0F;
    pRSP->anAudioBuffer[0x110] = 0xFEBD;
    pRSP->anAudioBuffer[0x111] = 0x34C8;
    pRSP->anAudioBuffer[0x112] = 0x4D57;
    pRSP->anAudioBuffer[0x113] = 0xFF2E;
    pRSP->anAudioBuffer[0x114] = 0xFEC6;
    pRSP->anAudioBuffer[0x115] = 0x32DC;
    pRSP->anAudioBuffer[0x116] = 0x4F14;
    pRSP->anAudioBuffer[0x117] = 0xFF53;
    pRSP->anAudioBuffer[0x118] = 0xFED0;
    pRSP->anAudioBuffer[0x119] = 0x30F3;
    pRSP->anAudioBuffer[0x11A] = 0x50C7;
    pRSP->anAudioBuffer[0x11B] = 0xFF7C;
    pRSP->anAudioBuffer[0x11C] = 0xFEDB;
    pRSP->anAudioBuffer[0x11D] = 0x2F0D;
    pRSP->anAudioBuffer[0x11E] = 0x5270;
    pRSP->anAudioBuffer[0x11F] = 0xFFAC;
    pRSP->anAudioBuffer[0x120] = 0xFEE8;
    pRSP->anAudioBuffer[0x121] = 0x2D2C;
    pRSP->anAudioBuffer[0x122] = 0x540D;
    pRSP->anAudioBuffer[0x123] = 0xFFE2;
    pRSP->anAudioBuffer[0x124] = 0xFEF4;
    pRSP->anAudioBuffer[0x125] = 0x2B50;
    pRSP->anAudioBuffer[0x126] = 0x559D;
    pRSP->anAudioBuffer[0x127] = 0x001F;
    pRSP->anAudioBuffer[0x128] = 0xFF02;
    pRSP->anAudioBuffer[0x129] = 0x297A;
    pRSP->anAudioBuffer[0x12A] = 0x5720;
    pRSP->anAudioBuffer[0x12B] = 0x0063;
    pRSP->anAudioBuffer[0x12C] = 0xFF10;
    pRSP->anAudioBuffer[0x12D] = 0x27A9;
    pRSP->anAudioBuffer[0x12E] = 0x5896;
    pRSP->anAudioBuffer[0x12F] = 0x00AE;
    pRSP->anAudioBuffer[0x130] = 0xFF1E;
    pRSP->anAudioBuffer[0x131] = 0x25E0;
    pRSP->anAudioBuffer[0x132] = 0x59FC;
    pRSP->anAudioBuffer[0x133] = 0x0101;
    pRSP->anAudioBuffer[0x134] = 0xFF2C;
    pRSP->anAudioBuffer[0x135] = 0x241E;
    pRSP->anAudioBuffer[0x136] = 0x5B53;
    pRSP->anAudioBuffer[0x137] = 0x015B;
    pRSP->anAudioBuffer[0x138] = 0xFF3A;
    pRSP->anAudioBuffer[0x139] = 0x2264;
    pRSP->anAudioBuffer[0x13A] = 0x5C9A;
    pRSP->anAudioBuffer[0x13B] = 0x01BE;
    pRSP->anAudioBuffer[0x13C] = 0xFF48;
    pRSP->anAudioBuffer[0x13D] = 0x20B3;
    pRSP->anAudioBuffer[0x13E] = 0x5DD0;
    pRSP->anAudioBuffer[0x13F] = 0x022A;
    pRSP->anAudioBuffer[0x140] = 0xFF56;
    pRSP->anAudioBuffer[0x141] = 0x1F0B;
    pRSP->anAudioBuffer[0x142] = 0x5EF5;
    pRSP->anAudioBuffer[0x143] = 0x029F;
    pRSP->anAudioBuffer[0x144] = 0xFF64;
    pRSP->anAudioBuffer[0x145] = 0x1D6C;
    pRSP->anAudioBuffer[0x146] = 0x6007;
    pRSP->anAudioBuffer[0x147] = 0x031C;
    pRSP->anAudioBuffer[0x148] = 0xFF71;
    pRSP->anAudioBuffer[0x149] = 0x1BD7;
    pRSP->anAudioBuffer[0x14A] = 0x6106;
    pRSP->anAudioBuffer[0x14B] = 0x03A4;
    pRSP->anAudioBuffer[0x14C] = 0xFF7E;
    pRSP->anAudioBuffer[0x14D] = 0x1A4C;
    pRSP->anAudioBuffer[0x14E] = 0x61F3;
    pRSP->anAudioBuffer[0x14F] = 0x0435;
    pRSP->anAudioBuffer[0x150] = 0xFF8A;
    pRSP->anAudioBuffer[0x151] = 0x18CB;
    pRSP->anAudioBuffer[0x152] = 0x62CB;
    pRSP->anAudioBuffer[0x153] = 0x04D1;
    pRSP->anAudioBuffer[0x154] = 0xFF96;
    pRSP->anAudioBuffer[0x155] = 0x1756;
    pRSP->anAudioBuffer[0x156] = 0x638F;
    pRSP->anAudioBuffer[0x157] = 0x0577;
    pRSP->anAudioBuffer[0x158] = 0xFFA1;
    pRSP->anAudioBuffer[0x159] = 0x15EB;
    pRSP->anAudioBuffer[0x15A] = 0x643F;
    pRSP->anAudioBuffer[0x15B] = 0x0628;
    pRSP->anAudioBuffer[0x15C] = 0xFFAC;
    pRSP->anAudioBuffer[0x15D] = 0x148C;
    pRSP->anAudioBuffer[0x15E] = 0x64D9;
    pRSP->anAudioBuffer[0x15F] = 0x06E4;
    pRSP->anAudioBuffer[0x160] = 0xFFB6;
    pRSP->anAudioBuffer[0x161] = 0x1338;
    pRSP->anAudioBuffer[0x162] = 0x655E;
    pRSP->anAudioBuffer[0x163] = 0x07AB;
    pRSP->anAudioBuffer[0x164] = 0xFFBF;
    pRSP->anAudioBuffer[0x165] = 0x11F0;
    pRSP->anAudioBuffer[0x166] = 0x65CD;
    pRSP->anAudioBuffer[0x167] = 0x087D;
    pRSP->anAudioBuffer[0x168] = 0xFFC8;
    pRSP->anAudioBuffer[0x169] = 0x10B4;
    pRSP->anAudioBuffer[0x16A] = 0x6626;
    pRSP->anAudioBuffer[0x16B] = 0x095A;
    pRSP->anAudioBuffer[0x16C] = 0xFFD0;
    pRSP->anAudioBuffer[0x16D] = 0x0F83;
    pRSP->anAudioBuffer[0x16E] = 0x6669;
    pRSP->anAudioBuffer[0x16F] = 0x0A44;
    pRSP->anAudioBuffer[0x170] = 0xFFD8;
    pRSP->anAudioBuffer[0x171] = 0x0E5F;
    pRSP->anAudioBuffer[0x172] = 0x6696;
    pRSP->anAudioBuffer[0x173] = 0x0B39;
    pRSP->anAudioBuffer[0x174] = 0xFFDF;
    pRSP->anAudioBuffer[0x175] = 0x0D46;
    pRSP->anAudioBuffer[0x176] = 0x66AD;
    pRSP->anAudioBuffer[0x177] = 0x0C39;

    return true;
}

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseABI4.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspCreateJPEGArrays.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspConvertRGBAtoYUV.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspYUVtoDCTBuf.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspDCT.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspQuantize.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoQuantize.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoDCT.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoYUVtoDCTBuf.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspFormatYUV.s")

static bool rspParseJPEG_Encode(Rsp* pRSP, RspTask* pTask);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseJPEG_Encode.s")

static bool rspParseJPEG_Decode(Rsp* pRSP, RspTask* pTask);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseJPEG_Decode.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspCreateJPEGArraysZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspDCTZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspQuantizeZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspZigzagDataZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoQuantizeZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoZigzagDataZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoDCTZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoLoadColorBufferZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspUndoRecon420Z.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspRecon420Z.s")

static bool rspParseJPEG_EncodeZ(Rsp* pRSP, RspTask* pTask);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseJPEG_EncodeZ.s")

static bool rspParseJPEG_DecodeZ(Rsp* pRSP, RspTask* pTask);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseJPEG_DecodeZ.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/Matrix4by4Identity.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspFillObjSprite.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspFillObjBgScale.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspFillObjBg.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspSetImage.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/tmemLoad_B.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/tmemLoad_A.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/tmemLoad.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/guS2DEmuBgRect1Cyc.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspFillObjTxtr.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspObjLoadTxtr.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspObjRectangle.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspObjSprite.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspObjRectangleR.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspBgRectCopy.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspObjMatrix.s")

static bool rspSetupS2DEX(Rsp* pRSP);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspSetupS2DEX.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspSetGeometryMode1.s")

static bool rspParseGBI_F3DEX1(Rsp* pRSP, u64** ppnGBI, bool* pbDone);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseGBI_F3DEX1.s")

#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspGeometryMode.s")

static bool rspParseGBI_F3DEX2(Rsp* pRSP, u64** ppnGBI, bool* pbDone);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseGBI_F3DEX2.s")

// Matches but data doesn't
#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspLoadMatrix.s")
#else
static bool rspLoadMatrix(Rsp* pRSP, s32 nAddress, Mtx44 matrix) {
    s32* pMtx;
    s32 nDataA;
    s32 nDataB;
    f32 rScale;
    f32 rUpper;
    f32 rLower;
    u16 nUpper;
    u16 nLower;

    rScale = 1.0f / 65536.0f;
    if (!ramGetBuffer(SYSTEM_RAM(pRSP->pHost), &pMtx, nAddress, NULL)) {
        return false;
    }

    nDataA = pMtx[0];
    nDataB = pMtx[8];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[0][0] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[0][1] = rUpper + rLower * rScale;

    nDataA = pMtx[1];
    nDataB = pMtx[9];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[0][2] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[0][3] = rUpper + rLower * rScale;

    nDataA = pMtx[2];
    nDataB = pMtx[10];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[1][0] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[1][1] = rUpper + rLower * rScale;

    nDataA = pMtx[3];
    nDataB = pMtx[11];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[1][2] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[1][3] = rUpper + rLower * rScale;

    nDataA = pMtx[4];
    nDataB = pMtx[12];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[2][0] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[2][1] = rUpper + rLower * rScale;

    nDataA = pMtx[5];
    nDataB = pMtx[13];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[2][2] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[2][3] = rUpper + rLower * rScale;

    nDataA = pMtx[6];
    nDataB = pMtx[14];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[3][0] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[3][1] = rUpper + rLower * rScale;

    nDataA = pMtx[7];
    nDataB = pMtx[15];
    nUpper = nDataA >> 16;
    nLower = nDataB >> 16;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[3][2] = rUpper + rLower * rScale;
    nUpper = nDataA & 0xFFFF;
    nLower = nDataB & 0xFFFF;
    OSs16tof32((s16*)&nUpper, &rUpper);
    OSu16tof32(&nLower, &rLower);
    matrix[3][3] = rUpper + rLower * rScale;

    return true;
}
#endif

inline bool rspSetDL(Rsp* pRSP, s32 nOffsetRDRAM, bool bPush) {
    s32 nAddress;
    s32* pDL;

    nAddress = SEGMENT_ADDRESS(pRSP, nOffsetRDRAM);
    if (!ramGetBuffer(SYSTEM_RAM(pRSP->pHost), &pDL, nAddress, NULL)) {
        return false;
    }

    if (bPush && ++pRSP->iDL >= ARRAY_COUNT(pRSP->apDL)) {
        return false;
    }

    pRSP->apDL[pRSP->iDL] = (u64*)pDL;
    return true;
}

inline bool rspPopDL(Rsp* pRSP) {
    if (pRSP->iDL == 0) {
        return false;
    } else {
        pRSP->iDL--;
        return true;
    }
}

static bool rspFindUCode(Rsp* pRSP, RspTask* pTask);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspFindUCode.s")

static bool rspSaveYield(Rsp* pRSP);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspSaveYield.s")

static bool rspLoadYield(Rsp* pRSP);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspLoadYield.s")

static bool rspParseGBI_Setup(Rsp* pRSP, RspTask* pTask) {
    s32 iSegment;

    if (pRSP->yield.bValid) {
        pRSP->yield.bValid = false;
    }

    pRSP->nGeometryMode = 0;
    pRSP->iDL = 0;

    if (!rspSetDL(pRSP, pTask->nOffsetMBI & 0x7FFFFF, false)) {
        return false;
    }

    for (iSegment = 0; iSegment < ARRAY_COUNT(pRSP->anBaseSegment); iSegment++) {
        pRSP->anBaseSegment[iSegment] = 0;
    }

    if (!rspFindUCode(pRSP, pTask)) {
        return false;
    }

    if (pRSP->eTypeUCode != RUT_ZSORT || pRSP->nPass == 1) {
        if (!frameBegin(SYSTEM_FRAME(pRSP->pHost), pRSP->nCountVertex)) {
            return false;
        }
    }

    PAD_STACK();
    return true;
}

// Matches but data doesn't
#ifndef NON_MATCHING
static bool rspParseGBI(Rsp* pRSP, bool* pbDone, s32 nCount);
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspParseGBI.s")
#else
static bool rspParseGBI(Rsp* pRSP, bool* pbDone, s32 nCount) {
    bool bDone;
    s32 nStatus;
    u64* pDL;
    Cpu* pCPU;

    pCPU = SYSTEM_CPU(pRSP->pHost);
    bDone = false;

    while (!bDone) {
        pDL = pRSP->apDL[pRSP->iDL];
        switch (pRSP->eTypeUCode) {
            case RUT_TURBO:
            case RUT_SPRITE2D:
            case RUT_FAST3D:
            case RUT_F3DEX1:
            case RUT_S2DEX1:
            case RUT_L3DEX1:
                nStatus = rspParseGBI_F3DEX1(pRSP, &pRSP->apDL[pRSP->iDL], &bDone);
                break;
            case RUT_ZSORT:
            case RUT_F3DEX2:
            case RUT_S2DEX2:
            case RUT_L3DEX2:
                nStatus = rspParseGBI_F3DEX2(pRSP, &pRSP->apDL[pRSP->iDL], &bDone);
                break;
            default:
                return false;
        }

        if (nStatus == 0) {
            pRSP->apDL[pRSP->iDL] = pDL;
            if (!rdpParseGBI(SYSTEM_RDP(pRSP->pHost), &pRSP->apDL[pRSP->iDL], pRSP->eTypeUCode)) {
                if (!rspPopDL(pRSP)) {
                    bDone = true;
                }
            }
        }

        if (nCount == -1) {
            if (pCPU->nRetrace != pCPU->nRetraceUsed) {
                break;
            }
        } else if (nCount != 0) {
            if (--nCount == 0) {
                break;
            }
        }
    }

    if (pRSP->eTypeUCode == RUT_ZSORT) {
        if (pRSP->nPass == 1) {
            pRSP->nPass = 2;
        } else {
            pRSP->nPass = 1;
        }
    } else {
        pRSP->nPass = 2;
    }

    if (bDone) {
        pRSP->nMode |= 8;
    }

    if (pbDone != NULL) {
        *pbDone = bDone;
    }

    return true;
}
#endif

bool rspPut8(Rsp* pRSP, u32 nAddress, s8* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *((s8*)pRSP->pDMEM + (nAddress & 0xFFF)) = *pData;
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *((s8*)pRSP->pIMEM + (nAddress & 0xFFF)) = *pData;
            break;
        default:
            return false;
    }

    return true;
}

bool rspPut16(Rsp* pRSP, u32 nAddress, s16* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *((s16*)pRSP->pDMEM + ((nAddress & 0xFFF) >> 1)) = *pData;
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *((s16*)pRSP->pIMEM + ((nAddress & 0xFFF) >> 1)) = *pData;
            break;
        default:
            return false;
    }

    return true;
}

// matches but data doesn't
#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspPut32.s")
#else
bool rspPut32(Rsp* pRSP, u32 nAddress, s32* pData) {
    RspTask* pTask;
    s32 nData;
    s32 nSize;
    void* pTarget;
    void* pSource;
    s32 nLength;

    switch ((nAddress >> 12) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *((s32*)pRSP->pDMEM + ((nAddress & 0xFFF) >> 2)) = *pData;
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *((s32*)pRSP->pIMEM + ((nAddress & 0xFFF) >> 2)) = *pData;
            break;
        case RSP_REG_ADDR_HI(SP_BASE_REG):
            switch (nAddress & 0x1F) {
                case RSP_REG_ADDR_LO(SP_MEM_ADDR_REG):
                    pRSP->nAddressSP = *pData & 0x1FFF;
                    break;
                case RSP_REG_ADDR_LO(SP_DRAM_ADDR_REG):
                    pRSP->nAddressRDRAM = *pData & 0x03FFFFFF;
                    break;
                case RSP_REG_ADDR_LO(SP_RD_LEN_REG):
                    pRSP->nSizeGet = *pData;
                    nLength = pRSP->nSizeGet & 0xFFF;
                    if (pRSP->nAddressSP & 0x1000) {
                        pTarget = (u8*)pRSP->pIMEM + (pRSP->nAddressSP & 0xFFF);
                    } else {
                        pTarget = (u8*)pRSP->pDMEM + (pRSP->nAddressSP & 0xFFF);
                    }
                    if (!xlHeapCopy(pTarget, (s8*)SYSTEM_RAM(pRSP->pHost)->pBuffer + pRSP->nAddressRDRAM,
                                    nLength + 1)) {
                        return false;
                    }
                    break;
                case RSP_REG_ADDR_LO(SP_WR_LEN_REG):
                    pRSP->nSizePut = *pData;
                    nLength = pRSP->nSizePut & 0xFFF;
                    if (pRSP->nAddressSP & 0x1000) {
                        pSource = (u8*)pRSP->pIMEM + (pRSP->nAddressSP & 0xFFF);
                    } else {
                        pSource = (u8*)pRSP->pDMEM + (pRSP->nAddressSP & 0xFFF);
                    }
                    nSize = nLength + 1;
                    if (!ramGetBuffer(SYSTEM_RAM(pRSP->pHost), &pTarget, pRSP->nAddressRDRAM, (u32*)&nSize)) {
                        return false;
                    }
                    if (!xlHeapCopy(pTarget, pSource, nSize)) {
                        return false;
                    }
                    break;
                case RSP_REG_ADDR_LO(SP_STATUS_REG):
                    nData = *pData & 0xFFFF;
                    if (nData & 1) {
                        OSGetTick();
                        pRSP->nStatus &= ~0x1;
                        pTask = RSP_TASK(pRSP);
                        switch (pTask->nType) {
                            case 0:
                                break;
                            case 1:
                                if (pRSP->yield.bValid) {
                                    if (!rspLoadYield(pRSP)) {
                                        return false;
                                    }
                                    break;
                                }
                                pRSP->nMode |= 2;
                                break;
                            case 2:
                                if (pRSP->eTypeAudioUCode != RUT_UNKNOWN) {
                                    rspParseABI(pRSP, pTask);
                                }
                                pRSP->nStatus |= 0x201;
                                xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                                break;
                            case 3:
                                pRSP->nStatus |= 0x201;
                                xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                                break;
                            case 4:
                                if (pTask->nOffsetYield == 0) {
                                    if (!rspParseJPEG_Decode(pRSP, pTask)) {
                                        __cpuBreak(SYSTEM_CPU(pRSP->pHost));
                                    }
                                } else {
                                    if (!rspParseJPEG_DecodeZ(pRSP, pTask)) {
                                        __cpuBreak(SYSTEM_CPU(pRSP->pHost));
                                    }
                                }
                                pRSP->nStatus |= 0x201;
                                xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                                break;
                            case 5:
                                if (pTask->nOffsetYield == 0) {
                                    if (!rspParseJPEG_Encode(pRSP, pTask)) {
                                        __cpuBreak(SYSTEM_CPU(pRSP->pHost));
                                    }
                                } else {
                                    if (!rspParseJPEG_EncodeZ(pRSP, pTask)) {
                                        __cpuBreak(SYSTEM_CPU(pRSP->pHost));
                                    }
                                }
                                pRSP->nStatus |= 0x201;
                                xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                                break;
                            case 6:
                                pRSP->nStatus |= 0x201;
                                xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                                break;
                            case 7:
                                pRSP->nStatus |= 0x201;
                                xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                                break;
                            default:
                                return false;
                        }
                    }
                    if (nData & 2) {
                        pRSP->nStatus |= 1;
                    }
                    if (nData & 4) {
                        pRSP->nStatus &= ~0x2;
                    }
                    if (nData & 8) {
                        xlObjectEvent(pRSP->pHost, 0x1001, (void*)5);
                    }
                    if (nData & 0x10) {
                        xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                    }
                    if (nData & 0x20) {
                        pRSP->nStatus &= ~0x20;
                    }
                    if (nData & 0x40) {
                        pRSP->nStatus |= 0x20;
                    }
                    if (nData & 0x80) {
                        pRSP->nStatus &= ~0x40;
                    }
                    if (nData & 0x100) {
                        pRSP->nStatus |= 0x40;
                    }
                    if (nData & 0x200) {
                        pRSP->nStatus &= ~0x180;
                    }
                    if (nData & 0x400) {
                        if (!(pRSP->nStatus & 1)) {
                            pRSP->nStatus = pRSP->nStatus | 0x101;
                            if (!rspSaveYield(pRSP)) {
                                return false;
                            }
                            xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                        }
                    }
                    if (nData & 0x800) {
                        pRSP->nStatus &= ~0x100;
                    }
                    if (nData & 0x1000) {
                        pRSP->nStatus |= 0x100;
                    }
                    if (nData & 0x2000) {
                        pRSP->nStatus &= ~0x200;
                    }
                    if (nData & 0x4000) {
                        pRSP->nStatus |= 0x200;
                    }
                    if (nData & 0x8000) {
                        pRSP->nStatus &= ~0x400;
                    }
                    if (nData & 0x10000) {
                        pRSP->nStatus |= 0x400;
                    }
                    if (nData & 0x20000) {
                        pRSP->nStatus &= ~0x800;
                    }
                    if (nData & 0x40000) {
                        pRSP->nStatus |= 0x800;
                    }
                    if (nData & 0x80000) {
                        pRSP->nStatus &= ~0x1000;
                    }
                    if (nData & 0x100000) {
                        pRSP->nStatus |= 0x1000;
                    }
                    if (nData & 0x200000) {
                        pRSP->nStatus &= ~0x2000;
                    }
                    if (nData & 0x400000) {
                        pRSP->nStatus |= 0x2000;
                    }
                    if (nData & 0x800000) {
                        pRSP->nStatus &= ~0x4000;
                    }
                    if (nData & 0x01000000) {
                        pRSP->nStatus |= 0x4000;
                    }
                    break;
                case RSP_REG_ADDR_LO(SP_DMA_FULL_REG):
                    break;
                case RSP_REG_ADDR_LO(SP_DMA_BUSY_REG):
                    break;
                case RSP_REG_ADDR_LO(SP_SEMAPHORE_REG):
                    pRSP->nSemaphore = 0;
                    break;
                default:
                    return false;
            }
            break;
        case RSP_REG_ADDR_HI(SP_PC_REG):
            switch (nAddress & 0xF) {
                case RSP_REG_ADDR_LO(SP_PC_REG):
                    pRSP->nPC = *pData;
                    break;
                case RSP_REG_ADDR_LO(SP_IBIST_REG):
                    pRSP->nBIST = *pData & 0xFF;
                    break;
                default:
                    return false;
            }
            break;
        default:
            return false;
    }

    PAD_STACK();
    PAD_STACK();
    PAD_STACK();
    return true;
}
#endif

bool rspPut64(Rsp* pRSP, u32 nAddress, s64* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *((s64*)pRSP->pDMEM + ((nAddress & 0xFFF) >> 3)) = *pData;
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *((s64*)pRSP->pIMEM + ((nAddress & 0xFFF) >> 3)) = *pData;
            break;
        default:
            return false;
    }

    return true;
}

bool rspGet8(Rsp* pRSP, u32 nAddress, s8* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *pData = *((s8*)pRSP->pDMEM + (nAddress & 0xFFF));
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *pData = *((s8*)pRSP->pIMEM + (nAddress & 0xFFF));
            break;
        default:
            return false;
    }

    return true;
}

bool rspGet16(Rsp* pRSP, u32 nAddress, s16* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *pData = *((s16*)pRSP->pDMEM + ((nAddress & 0xFFF) >> 1));
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *pData = *((s16*)pRSP->pIMEM + ((nAddress & 0xFFF) >> 1));
            break;
        default:
            return false;
    }

    return true;
}

// matches but data doesn't
#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/non_matchings/rsp/rspGet32.s")
#else
bool rspGet32(Rsp* pRSP, u32 nAddress, s32* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *pData = *((s32*)pRSP->pDMEM + ((nAddress & 0xFFC) >> 2));
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *pData = *((s32*)pRSP->pIMEM + ((nAddress & 0xFFC) >> 2));
            break;
        case RSP_REG_ADDR_HI(SP_BASE_REG):
            switch (nAddress & 0x1F) {
                case RSP_REG_ADDR_LO(SP_MEM_ADDR_REG):
                    *pData = pRSP->nAddressSP;
                    break;
                case RSP_REG_ADDR_LO(SP_DRAM_ADDR_REG):
                    *pData = pRSP->nAddressRDRAM;
                    break;
                case RSP_REG_ADDR_LO(SP_RD_LEN_REG):
                    *pData = pRSP->nSizeGet;
                    break;
                case RSP_REG_ADDR_LO(SP_WR_LEN_REG):
                    *pData = pRSP->nSizePut;
                    break;
                case RSP_REG_ADDR_LO(SP_STATUS_REG):
                    *pData = pRSP->nStatus & 0xFFFF;
                    break;
                case RSP_REG_ADDR_LO(SP_DMA_FULL_REG):
                    *pData = pRSP->nFullDMA & 1;
                    break;
                case RSP_REG_ADDR_LO(SP_DMA_BUSY_REG):
                    *pData = pRSP->nBusyDMA & 1;
                    break;
                case RSP_REG_ADDR_LO(SP_SEMAPHORE_REG):
                    pRSP->nSemaphore = 1;
                    *pData = 0;
                    break;
                default:
                    return false;
            }
            break;
        case RSP_REG_ADDR_HI(SP_PC_REG):
            switch (nAddress & 0xF) {
                case RSP_REG_ADDR_LO(SP_PC_REG):
                    *pData = pRSP->nPC;
                    break;
                case RSP_REG_ADDR_LO(SP_IBIST_REG):
                    *pData = pRSP->nBIST & 0xFF;
                    break;
                default:
                    return false;
            }
            break;
        default:
            return false;
    }

    return true;
}
#endif

bool rspGet64(Rsp* pRSP, u32 nAddress, s64* pData) {
    switch ((nAddress >> 0xC) & 0xFFF) {
        case RSP_REG_ADDR_HI(SP_DMEM_START):
            *pData = *((s64*)pRSP->pDMEM + ((nAddress & 0xFFF) >> 3));
            break;
        case RSP_REG_ADDR_HI(SP_IMEM_START):
            *pData = *((s64*)pRSP->pIMEM + ((nAddress & 0xFFF) >> 3));
            break;
        default:
            return false;
    }

    return true;
}

bool rspInvalidateCache(Rsp* pRSP, s32 nOffset0, s32 nOffset1) {
    __anon_0x5B8F2* pUCode;
    void* pListNode;
    s32 nOffsetUCode0;
    s32 nOffsetUCode1;

    nOffsetUCode0 = nOffset1 & 0x7FFFFF;
    nOffsetUCode1 = nOffset0 & 0x7FFFFF;
    pListNode = pRSP->pListUCode->pNodeHead;

    while (pListNode != NULL) {
        s32 offset0;
        s32 offset1;

        pUCode = (__anon_0x5B8F2*)NODE_DATA(pListNode);
        pListNode = NODE_NEXT(pListNode);

        if (pUCode->nOffsetCode < pUCode->nOffsetData) {
            offset0 = pUCode->nOffsetCode;
            offset1 = pUCode->nOffsetData + pUCode->nLengthData;
        } else {
            offset0 = pUCode->nOffsetData;
            offset1 = pUCode->nOffsetCode + pUCode->nLengthCode;
        }

        if ((nOffsetUCode1 <= offset0 && offset0 <= nOffsetUCode0) ||
            (nOffsetUCode1 <= offset1 && offset1 <= nOffsetUCode0)) {
            if (!xlListFreeItem(pRSP->pListUCode, &pUCode)) {
                return false;
            }
        }
    }

    return true;
}

bool rspEnableABI(Rsp* pRSP, bool bFlag) {
    pRSP->eTypeAudioUCode = bFlag ? RUT_NOCODE : RUT_UNKNOWN;
    return true;
}

bool rspFrameComplete(Rsp* pRSP) {
    if (pRSP->yield.bValid) {
        OSReport(D_800EE27C);
    }

    pRSP->nMode |= 4;
    return true;
}

bool rspUpdate(Rsp* pRSP, RspUpdateMode eMode) {
    RspTask* pTask;
    bool bDone;
    s32 nCount = 0;
    Frame* pFrame = SYSTEM_FRAME(pRSP->pHost);

    if ((pRSP->nMode & 4) && (pRSP->nMode & 8)) {
        if (pRSP->nMode & 0x10) {
            gNoSwapBuffer = true;
            pRSP->nMode |= 0x20;
        }
        if (!frameEnd(pFrame)) {
            return false;
        }
        pRSP->nMode &= ~0xC;
    }

    if (!(pRSP->nStatus & 1)) {
        if (pRSP->nMode & 0x20) {
            pRSP->nMode &= ~0x30;
            pRSP->nStatus |= 0x201;
            xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
            xlObjectEvent(pRSP->pHost, 0x1000, (void*)10);
        } else {
            if (pRSP->nMode & 2) {
                if (frameBeginOK(pFrame) && eMode == RUM_IDLE) {
                    pRSP->nMode &= ~0x2;
                    pRSP->nMode |= 0x10;

                    pTask = RSP_TASK(pRSP);
                    if (!rspParseGBI_Setup(pRSP, pTask)) {
                        return false;
                    }
                } else {
                    return true;
                }
            }

            if (eMode == RUM_IDLE) {
                nCount = -1;
            }

            if (nCount != 0) {
                if (rspParseGBI(pRSP, &bDone, nCount)) {
                    if (bDone) {
                        pRSP->nMode &= ~0x10;
                        pRSP->nStatus |= 0x201;
                        xlObjectEvent(pRSP->pHost, 0x1000, (void*)5);
                        xlObjectEvent(pRSP->pHost, 0x1000, (void*)10);
                    }
                } else {
                    __cpuBreak(SYSTEM_CPU(pRSP->pHost));
                }
                pRSP->nTickLast = OSGetTick();
            }
        }
    }

    return true;
}

bool rspEvent(Rsp* pRSP, s32 nEvent, void* pArgument) {
    switch (nEvent) {
        case 2:
            pRSP->nPC = 0;
            pRSP->pHost = pArgument;
            pRSP->nPass = 1;
            pRSP->nMode = 0;
            pRSP->yield.bValid = false;
            pRSP->nStatus = 1;
            pRSP->pfUpdateWaiting = NULL;
            if (!xlListMake(&pRSP->pListUCode, 0x60)) {
                return false;
            }
            if (!xlHeapTake(&pRSP->pDMEM, 0x1000)) {
                return false;
            }
            if (!xlHeapTake(&pRSP->pIMEM, 0x1000)) {
                return false;
            }
            if (!rspSetupS2DEX(pRSP)) {
                return false;
            }
            if (!rspInitAudioDMEM1(pRSP)) {
                return false;
            }
            pRSP->eTypeAudioUCode = RUT_NOCODE;
            break;
        case 3:
            xlHeapFree(&pRSP->pIMEM);
            xlHeapFree(&pRSP->pDMEM);
            if (!xlListFree(&pRSP->pListUCode)) {
                return false;
            }
            break;
        case 0x1002:
            if (!cpuSetDevicePut(SYSTEM_CPU(pRSP->pHost), pArgument, (Put8Func)rspPut8, (Put16Func)rspPut16,
                                 (Put32Func)rspPut32, (Put64Func)rspPut64)) {
                return false;
            }
            if (!cpuSetDeviceGet(SYSTEM_CPU(pRSP->pHost), pArgument, (Get8Func)rspGet8, (Get16Func)rspGet16,
                                 (Get32Func)rspGet32, (Get64Func)rspGet64)) {
                return false;
            }
            break;
        case 0:
        case 1:
        case 0x1003:
            break;
        default:
            return false;
    }

    return true;
}
