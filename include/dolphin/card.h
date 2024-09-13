#ifndef _DOLPHIN_CARD_H_
#define _DOLPHIN_CARD_H_

#include "dolphin/dsp.h"
#include "dolphin/dvd.h"
#include "dolphin/os/OSAlarm.h"

#define CARD_WORKAREA_SIZE (5 * 8 * 1024) // 0xA000 (5 * 0x2000)
#define CARD_READ_SIZE 512
#define CARD_MAX_FILE 127
#define CARD_COMMENT_SIZE 64
#define CARD_FILENAME_MAX 32
#define CARD_ICON_MAX 8
#define CARD_ICON_WIDTH 32
#define CARD_ICON_HEIGHT 32
#define CARD_BANNER_WIDTH 96
#define CARD_BANNER_HEIGHT 32

#define CARD_RESULT_UNLOCKED 1
#define CARD_RESULT_READY 0
#define CARD_RESULT_BUSY -1
#define CARD_RESULT_WRONGDEVICE -2
#define CARD_RESULT_NOCARD -3
#define CARD_RESULT_NOFILE -4
#define CARD_RESULT_IOERROR -5
#define CARD_RESULT_BROKEN -6
#define CARD_RESULT_EXIST -7
#define CARD_RESULT_NOENT -8
#define CARD_RESULT_INSSPACE -9
#define CARD_RESULT_NOPERM -10
#define CARD_RESULT_LIMIT -11
#define CARD_RESULT_NAMETOOLONG -12
#define CARD_RESULT_ENCODING -13
#define CARD_RESULT_CANCELED -14
#define CARD_RESULT_FATAL_ERROR -128

// Icon animation modes.
#define CARD_MODE_NORMAL 0
#define CARD_MODE_FAST 1

// Icon status codes.
#define CARD_STAT_ICON_NONE 0
#define CARD_STAT_ICON_C8 1
#define CARD_STAT_ICON_RGB5A3 2
#define CARD_STAT_ICON_MASK 3

// Banner status codes.
#define CARD_STAT_BANNER_NONE 0
#define CARD_STAT_BANNER_C8 1
#define CARD_STAT_BANNER_RGB5A3 2
#define CARD_STAT_BANNER_MASK 3

// Animation status codes.
#define CARD_STAT_ANIM_LOOP 0x00
#define CARD_STAT_ANIM_BOUNCE 0x04
#define CARD_STAT_ANIM_MASK 0x04

// Animation speed status codes.
#define CARD_STAT_SPEED_END 0
#define CARD_STAT_SPEED_FAST 1
#define CARD_STAT_SPEED_MIDDLE 2
#define CARD_STAT_SPEED_SLOW 3
#define CARD_STAT_SPEED_MASK 3

// CARD attribute codes.
#define CARD_ATTR_PUBLIC 0x04u
#define CARD_ATTR_NO_COPY 0x08u
#define CARD_ATTR_NO_MOVE 0x10u
#define CARD_ATTR_GLOBAL 0x20u
#define CARD_ATTR_COMPANY 0x40u

// Private info defines.
#define CARD_FAT_AVAIL 0x0000u
#define CARD_FAT_CHECKSUM 0x0000u
#define CARD_FAT_CHECKSUMINV 0x0001u
#define CARD_FAT_CHECKCODE 0x0002u
#define CARD_FAT_FREEBLOCKS 0x0003u
#define CARD_FAT_LASTSLOT 0x0004u

#define CARD_PAGE_SIZE 128u
#define CARD_SEG_SIZE 512u

#define CARD_NUM_SYSTEM_BLOCK 5
#define CARD_SYSTEM_BLOCK_SIZE (8 * 1024u)

#define CARD_MAX_MOUNT_STEP (CARD_NUM_SYSTEM_BLOCK + 2)

// Useful conversion macros.
#define TRUNC(n, a) (((u32)(n)) & ~((a) - 1))
#define OFFSET(n, a) (((u32)(n)) & ((a) - 1))

#define CARDIsValidBlockNo(card, iBlock) (CARD_NUM_SYSTEM_BLOCK <= (iBlock) && (iBlock) < (card)->cBlock)

#define __CARDGetDirCheck(dir) ((CARDDirCheck*)&(dir)[CARD_MAX_FILE])

#define CARDGetBannerFormat(stat) (((stat)->bannerFormat) & CARD_STAT_BANNER_MASK)
#define CARDGetIconAnim(stat) (((stat)->bannerFormat) & CARD_STAT_ANIM_MASK)
#define CARDGetIconFormat(stat, n) (((stat)->iconFormat >> (2 * (n))) & CARD_STAT_ICON_MASK)
#define CARDGetIconSpeed(stat, n) (((stat)->iconSpeed >> (2 * (n))) & CARD_STAT_SPEED_MASK)
#define CARDSetBannerFormat(stat, f) \
    ((stat)->bannerFormat = (u8)(((stat)->bannerFormat & ~CARD_STAT_BANNER_MASK) | (f)))

#define CARDSetIconAnim(stat, f) ((stat)->bannerFormat = (u8)(((stat)->bannerFormat & ~CARD_STAT_ANIM_MASK) | (f)))

#define CARDSetIconFormat(stat, n, f) \
    ((stat)->iconFormat = (u16)(((stat)->iconFormat & ~(CARD_STAT_ICON_MASK << (2 * (n)))) | ((f) << (2 * (n)))))

#define CARDSetIconSpeed(stat, n, f) \
    ((stat)->iconSpeed = (u16)(((stat)->iconSpeed & ~(CARD_STAT_SPEED_MASK << (2 * (n)))) | ((f) << (2 * (n)))))

#define CARDSetIconAddress(stat, addr) ((stat)->iconAddr = (u32)(addr))
#define CARDSetCommentAddress(stat, addr) ((stat)->commentAddr = (u32)(addr))
#define CARDGetFileNo(fileInfo) ((fileInfo)->fileNo)

#define CARDGetDirectoryBlock(card, i) ((CARDDir*)((u8*)card->workArea + (1 + i) * CARD_SYSTEM_BLOCK_SIZE))
#define CARDGetFatBlock(card, i) ((u16*)((u8*)card->workArea + (3 + i) * CARD_SYSTEM_BLOCK_SIZE))
#define CARDGetDirCheck(dir) ((CARDDirCheck*)&(dir)[CARD_MAX_FILE])

typedef void (*CARDCallback)(s32 chan, s32 result);

typedef struct CARDFileInfo {
    /* 0x00 */ s32 chan;
    /* 0x04 */ s32 fileNo;
    /* 0x08 */ s32 offset;
    /* 0x0C */ s32 length;
    /* 0x10 */ u16 iBlock;
} CARDFileInfo;

typedef struct CARDStat {
    /* 0x00 */ char fileName[CARD_FILENAME_MAX];
    /* 0x20 */ u32 length;
    /* 0x24 */ u32 time;
    /* 0x28 */ u8 gameName[4];
    /* 0x2C */ u8 company[2];
    /* 0x2E */ u8 bannerFormat;
    /* 0x30 */ u32 iconAddr;
    /* 0x34 */ u16 iconFormat;
    /* 0x36 */ u16 iconSpeed;
    /* 0x38 */ u32 commentAddr;
    /* 0x3C */ u32 offsetBanner;
    /* 0x40 */ u32 offsetBannerTlut;
    /* 0x44 */ u32 offsetIcon[CARD_ICON_MAX];
    /* 0x64 */ u32 offsetIconTlut;
    /* 0x68 */ u32 offsetData;
} CARDStat;

typedef struct CARDDir {
    /* 0x00 */ u8 gameName[4];
    /* 0x04 */ u8 company[2];
    /* 0x06 */ u8 _padding0;
    /* 0x07 */ u8 bannerFormat;
    /* 0x08 */ u8 fileName[CARD_FILENAME_MAX];
    /* 0x28 */ u32 time; // seconds since 01/01/2000 midnight
    /* 0x2C */ u32 iconAddr; // 0xFFFFFFFF if not used
    /* 0x30 */ u16 iconFormat;
    /* 0x32 */ u16 iconSpeed;
    /* 0x34 */ u8 permission;
    /* 0x35 */ u8 copyTimes;
    /* 0x36 */ u16 startBlock;
    /* 0x38 */ u16 length;
    /* 0x3A */ u8 _padding1[2];
    /* 0x3C */ u32 commentAddr; // 0xFFFFFFFF if not used
} CARDDir;

typedef struct CARDDirCheck {
    /* 0x00 */ u8 padding[0x3A];
    /* 0x3A */ s16 checkCode;
    /* 0x3C */ u16 checkSum;
    /* 0x3E */ u16 checkSumInv;
} CARDDirCheck;

typedef struct CARDControl {
    /* 0x000 */ bool attached;
    /* 0x004 */ s32 result;
    /* 0x008 */ u16 size;
    /* 0x00A */ u16 pageSize;
    /* 0x00C */ s32 sectorSize;
    /* 0x010 */ u16 cBlock;
    /* 0x012 */ u16 vendorID;
    /* 0x014 */ s32 latency;
    /* 0x018 */ u8 id[12];
    /* 0x024 */ s32 mountStep;
    /* 0x028 */ s32 formatStep;
    /* 0x02C */ u32 scramble;
    /* 0x030 */ DSPTaskInfo task;
    /* 0x080 */ void* workArea;
    /* 0x084 */ CARDDir* currentDir;
    /* 0x088 */ u16* currentFat;
    /* 0x08C */ OSThreadQueue threadQueue;
    /* 0x094 */ u8 cmd[9];
    /* 0x0A0 */ s32 cmdlen;
    /* 0x0A4 */ volatile u32 mode;
    /* 0x0A8 */ s32 retry;
    /* 0x0AC */ s32 repeat;
    /* 0x0B0 */ u32 addr;
    /* 0x0B4 */ void* buffer;
    /* 0x0B8 */ s32 xferred;
    /* 0x0BC */ u16 freeNo;
    /* 0x08E */ u16 startBlock;
    /* 0x0C0 */ CARDFileInfo* fileInfo;
    /* 0x0C4 */ CARDCallback extCallback;
    /* 0x0C8 */ CARDCallback txCallback;
    /* 0x0CC */ CARDCallback exiCallback;
    /* 0x0D0 */ CARDCallback apiCallback;
    /* 0x0D4 */ CARDCallback xferCallback;
    /* 0x0D8 */ CARDCallback eraseCallback;
    /* 0x0DC */ CARDCallback unlockCallback;
    /* 0x0E0 */ OSAlarm alarm;
    /* 0x108 */ u32 cid;
    /* 0x10C */ const DVDDiskID* diskID;
} CARDControl;

typedef struct CARDID {
    /* 0x000 */ u8 serial[0x20]; //  flashID(0xC), timebase(8), counterBias(4), lang(4), XXX(4).
    /* 0x020 */ u16 deviceID;
    /* 0x022 */ u16 size;
    /* 0x024 */ u16 encode;
    /* 0x026 */ u8 padding[0x1D4];
    /* 0x1FA */ s16 checkCode;
    /* 0x1FC */ u16 checkSum;
    /* 0x1FE */ u16 checkSumInv;
} CARDID;

typedef struct CARDDecodeParameters {
    /* 0x00 */ u8* inputAddr;
    /* 0x04 */ u32 inputLength;
    /* 0x08 */ u32 aramAddr;
    /* 0x0C */ u8* outputAddr;
} CARDDecodeParameters;

extern CARDControl __CARDBlock[2];
extern DVDDiskID __CARDDiskNone;
extern u16 __CARDVendorID;
extern u8 __CARDPermMask;

void __CARDDefaultApiCallback(s32 channel, s32 result);
void __CARDSyncCallback(s32 channel, s32 result);
void __CARDExtHandler(s32 channel, OSContext* context);
void __CARDExiHandler(s32 channel, OSContext* context);
void __CARDTxHandler(s32 channel, OSContext* context);
void __CARDUnlockedHandler(s32 channel, OSContext* context);
u16* __CARDGetFatBlock(CARDControl* card);
CARDDir* __CARDGetDirBlock(CARDControl* card);
u16 __CARDGetFontEncode();
void __CARDCheckSum(void* ptr, int length, u16* checksum, u16* checksumInv);
s32 __CARDGetFileNo(CARDControl* card, char* fileName, s32* outFileNo);
s32 __CARDAccess(CARDControl* card, CARDDir* entry);
s32 __CARDIsPublic(CARDDir* entry);

void CARDInit(void);
s32 CARDFormatAsync(s32 channel, CARDCallback callback);
s32 CARDOpen(s32 chan, char* fileName, CARDFileInfo* fileInfo);
s32 CARDClose(CARDFileInfo* fileInfo);
s32 CARDProbeEx(s32 chan, s32* memSize, s32* sectorSize);
s32 CARDMountAsync(s32 chan, void* workArea, CARDCallback detachCallback, CARDCallback attachCallback);
s32 CARDGetResultCode(s32 chan);
s32 CARDFreeBlocks(s32 chan, s32* byteNotUsed, s32* filesNotUsed);
s32 CARDGetXferredBytes(s32 chan);
s32 CARDCheck(s32 chan);
s32 CARDCheckExAsync(s32 chan, s32* xferBytes, CARDCallback callback);
s32 CARDCreateAsync(s32 chan, char* fileName, u32 size, CARDFileInfo* fileInfo, CARDCallback callback);
s32 CARDWriteAsync(CARDFileInfo* fileInfo, void* addr, s32 length, s32 offset, CARDCallback callback);
s32 CARDSetStatusAsync(s32 chan, s32 fileNo, CARDStat* stat, CARDCallback callback);
s32 CARDReadAsync(CARDFileInfo* fileInfo, void* addr, s32 length, s32 offset, CARDCallback callback);
s32 CARDRead(CARDFileInfo* fileInfo, void* addr, s32 length, s32 offset);
s32 CARDGetStatus(s32 chan, s32 fileNo, CARDStat* stat);
s32 CARDDeleteAsync(s32 chan, char* fileName, CARDCallback callback);
s32 CARDMount(s32 chan, void* workArea, CARDCallback detachCallback);
s32 CARDUnmount(s32 chan);

#endif
