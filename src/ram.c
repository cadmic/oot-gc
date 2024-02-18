#include "cpu.h"
#include "ram.h"
#include "system.h"
#include "xlObject.h"

BOOL ramEvent(Ram* pRAM, s32 nEvent, void* pArgument);

_XL_OBJECTTYPE gClassRAM = {
    "RAM",
    sizeof(Ram),
    NULL,
    (EventFunc)ramEvent,
};

static BOOL ramPutControl8(Ram* pRAM, u32 nAddress, s8* pData) { return FALSE; }

static BOOL ramPutControl16(Ram* pRAM, u32 nAddress, s32* pData) { return FALSE; }

static BOOL ramPutControl32(Ram* pRAM, u32 nAddress, s16* pData) {
    nAddress &= 0x3F;

    switch (nAddress) {
        default:
            return FALSE;
        case 0x00:
        case 0x04:
        case 0x08:
        case 0x0C:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
        case 0x20:
        case 0x24:
            return TRUE;
    }
}

static BOOL ramPutControl64(Ram* pRAM, u32 nAddress, s64* pData) { return FALSE; }

static BOOL ramGetControl8(Ram* pRAM, u32 nAddress, s8* pData) { return FALSE; }

static BOOL ramGetControl16(Ram* pRAM, u32 nAddress, s32* pData) { return FALSE; }

static BOOL ramGetControl32(Ram* pRAM, u32 nAddress, s16* pData) {
    nAddress &= 0x3F;

    switch (nAddress) {
        default:
            return FALSE;
        case 0x00:
        case 0x04:
        case 0x08:
        case 0x0C:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
        case 0x20:
        case 0x24:
            return TRUE;
    }
}

static BOOL ramGetControl64(Ram* pRAM, u32 nAddress, s64* pData) { return FALSE; }

static BOOL ramPutRI8(Ram* pRAM, u32 nAddress, s8* pData) { return FALSE; }

static BOOL ramPutRI16(Ram* pRAM, u32 nAddress, s32* pData) { return FALSE; }

static BOOL ramPutRI32(Ram* pRAM, u32 nAddress, s16* pData) {
    nAddress &= 0x1F;

    switch (nAddress) {
        default:
            return FALSE;
        case 0x00:
        case 0x04:
        case 0x08:
        case 0x0C:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
            return TRUE;
    }
}

static BOOL ramPutRI64(Ram* pRAM, u32 nAddress, s64* pData) { return FALSE; }

static BOOL ramGetRI8(Ram* pRAM, u32 nAddress, s8* pData) { return FALSE; }

static BOOL ramGetRI16(Ram* pRAM, u32 nAddress, s32* pData) { return FALSE; }

static BOOL ramGetRI32(Ram* pRAM, u32 nAddress, s16* pData) {
    nAddress &= 0x1F;

    switch (nAddress) {
        default:
            return FALSE;
        case 0x00:
        case 0x04:
        case 0x08:
        case 0x0C:
        case 0x10:
        case 0x14:
        case 0x18:
        case 0x1C:
            return TRUE;
    }
}

static BOOL ramGetRI64(Ram* pRAM, u32 nAddress, s64* pData) { return FALSE; }

static BOOL ramPut8(Ram* pRAM, u32 nAddress, s8* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *((s8*)pRAM->pBuffer + nAddress) = *pData;
    }

    return TRUE;
}

static BOOL ramPut16(Ram* pRAM, u32 nAddress, s16* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *((u16*)pRAM->pBuffer + (nAddress >> 1)) = *pData;
    }

    return TRUE;
}

static BOOL ramPut32(Ram* pRAM, u32 nAddress, s32* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *((s32*)pRAM->pBuffer + (nAddress >> 2)) = *pData;
    }

    return TRUE;
}

static BOOL ramPut64(Ram* pRAM, u32 nAddress, s64* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *((s64*)pRAM->pBuffer + (nAddress >> 3)) = *pData;
    }

    return TRUE;
}

static BOOL ramGet8(Ram* pRAM, u32 nAddress, s8* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *pData = *((s8*)pRAM->pBuffer + nAddress);
    } else {
        *pData = 0;
    }

    return TRUE;
}

static BOOL ramGet16(Ram* pRAM, u32 nAddress, s16* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *pData = *((s16*)pRAM->pBuffer + (nAddress >> 1));
    } else {
        *pData = 0;
    }

    return TRUE;
}

static BOOL ramGet32(Ram* pRAM, u32 nAddress, s32* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *pData = *((s32*)pRAM->pBuffer + (nAddress >> 2));
    } else {
        *pData = 0;
    }

    return TRUE;
}

static BOOL ramGet64(Ram* pRAM, u32 nAddress, s64* pData) {
    nAddress &= 0x03FFFFFF;

    if (nAddress < pRAM->nSize) {
        *pData = *((s64*)pRAM->pBuffer + (nAddress >> 3));
    } else {
        *pData = 0;
    }

    return TRUE;
}

BOOL ramGetBuffer(Ram* pRAM, void** ppRAM, u32 nOffset, u32* pnSize) {
    s32 nSize;

    nOffset &= 0x03FFFFFF;

    if (pRAM->nSize == 0) {
        return FALSE;
    }

    if ((pnSize != NULL) && ((u32)(nOffset + *pnSize) >= pRAM->nSize)) {
        nSize = pRAM->nSize - nOffset;
        *pnSize = nSize;

        if (nSize < 0) {
            *pnSize = 0;
        }
    }

    *((u8**)ppRAM) = (u8*)pRAM->pBuffer + nOffset;
    return TRUE;
}

BOOL ramWipe(Ram* pRAM) {
    if (pRAM->nSize != 0 && !xlHeapFill32(pRAM->pBuffer, pRAM->nSize, 0)) {
        return FALSE;
    }

    return TRUE;
}

BOOL ramSetSize(Ram* pRAM, s32 nSize) {
    s32 nSizeRAM;

    if (pRAM->pBuffer != NULL) {
        return FALSE;
    }

    nSizeRAM = (nSize + 0x3FF) & 0xFFFFFC00;

    if (!xlHeapTake(&pRAM->pBuffer, nSizeRAM | 0x30000000)) {
        return FALSE;
    }

    pRAM->nSize = nSizeRAM;

    return TRUE;
}

BOOL ramGetSize(Ram* pRAM, s32* nSize) {
    if (nSize != NULL) {
        *nSize = pRAM->nSize;
    }

    return TRUE;
}

BOOL ramEvent(Ram* pRAM, s32 nEvent, void* pArgument) {
    switch (nEvent) {
        case 2:
            pRAM->nSize = 0;
            pRAM->pBuffer = NULL;
            pRAM->pHost = pArgument;
            break;
        case 0x1002:
            switch (((CpuDevice*)pArgument)->nType & 0xFF) {
                case 0:
                    if (!cpuSetDevicePut(((System*)pRAM->pHost)->apObject[SOT_CPU], pArgument, (Put8Func)ramPut8,
                                         (Put16Func)ramPut16, (Put32Func)ramPut32, (Put64Func)ramPut64)) {
                        return FALSE;
                    }

                    if (!cpuSetDeviceGet(((System*)pRAM->pHost)->apObject[SOT_CPU], pArgument, (Get8Func)ramGet8,
                                         (Get16Func)ramGet16, (Get32Func)ramGet32, (Get64Func)ramGet64)) {
                        return FALSE;
                    }
                    break;
                case 1:
                    if (!cpuSetDevicePut(((System*)pRAM->pHost)->apObject[SOT_CPU], pArgument, (Put8Func)ramPutRI8,
                                         (Put16Func)ramPutRI16, (Put32Func)ramPutRI32, (Put64Func)ramPutRI64)) {
                        return FALSE;
                    }

                    if (!cpuSetDeviceGet(((System*)pRAM->pHost)->apObject[SOT_CPU], pArgument, (Get8Func)ramGetRI8,
                                         (Get16Func)ramGetRI16, (Get32Func)ramGetRI32, (Get64Func)ramGetRI64)) {
                        return FALSE;
                    }
                    break;
                case 2:
                    if (!cpuSetDevicePut(((System*)pRAM->pHost)->apObject[SOT_CPU], pArgument, (Put8Func)ramPutControl8,
                                         (Put16Func)ramPutControl16, (Put32Func)ramPutControl32,
                                         (Put64Func)ramPutControl64)) {
                        return FALSE;
                    }

                    if (!cpuSetDeviceGet(((System*)pRAM->pHost)->apObject[SOT_CPU], pArgument, (Get8Func)ramGetControl8,
                                         (Get16Func)ramGetControl16, (Get32Func)ramGetControl32,
                                         (Get64Func)ramGetControl64)) {
                        return FALSE;
                    }
                    break;
            }
            break;
        case 0:
        case 1:
        case 3:
        case 0x1003:
            break;
        default:
            return FALSE;
    }

    return TRUE;
}
