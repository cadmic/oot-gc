#include "xlObject.h"
#include "system.h"
#include "cpu.h"
#include "disk.h"

_XL_OBJECTTYPE gClassDisk = {
    "DISK",
    sizeof(Disk),
    NULL,
    (EventFunc)diskEvent,
};

BOOL diskPutROM8(Disk* pDisk, u32 nAddress, s8* pData) { return TRUE; }

BOOL diskPutROM16(Disk* pDisk, u32 nAddress, s16* pData) { return TRUE; }

BOOL diskPutROM32(Disk* pDisk, u32 nAddress, s32* pData) { return TRUE; }

BOOL diskPutROM64(Disk* pDisk, u32 nAddress, s64* pData) { return TRUE; }

BOOL diskGetROM8(Disk* pDisk, u32 nAddress, s8* pData) {
    *pData = 0;
    return TRUE;
}

BOOL diskGetROM16(Disk* pDisk, u32 nAddress, s16* pData) {
    *pData = 0;
    return TRUE;
}

BOOL diskGetROM32(Disk* pDisk, u32 nAddress, s32* pData) {
    *pData = 0;
    return TRUE;
}

BOOL diskGetROM64(Disk* pDisk, u32 nAddress, s64* pData) {
    *pData = 0;
    return TRUE;
}

BOOL diskPutDrive8(Disk* pDisk, u32 nAddress, s8* pData) { return TRUE; }

BOOL diskPutDrive16(Disk* pDisk, u32 nAddress, s16* pData) { return TRUE; }

BOOL diskPutDrive32(Disk* pDisk, u32 nAddress, s32* pData) {
    nAddress &= 0x00FFFFFF;

    switch (nAddress) {
        case 0x508:
            return FALSE;
        case 0x510:
        default:
            break;
    }

    return TRUE;
}

BOOL diskPutDrive64(Disk* pDisk, u32 nAddress, s64* pData) { return TRUE; }

BOOL diskGetDrive8(Disk* pDisk, u32 nAddress, s8* pData) { return TRUE; }

BOOL diskGetDrive16(Disk* pDisk, u32 nAddress, s16* pData) { return TRUE; }

BOOL diskGetDrive32(Disk* pDisk, u32 nAddress, s32* pData) {
    nAddress &= 0x00FFFFFF;

    switch (nAddress) {
        case 0x508:
            *pData = 0;
            break;
        case 0x510:
            return FALSE;
        default:
            break;
    }

    return TRUE;
}

BOOL diskGetDrive64(Disk* pDisk, u32 nAddress, s64* pData) { return TRUE; }

BOOL diskEvent(Disk* pDisk, s32 nEvent, void* pArgument) {
    switch (nEvent) {
        case 2:
            pDisk->pHost = pArgument;
            break;
        case 0x1002:
            switch (((CpuDevice*)pArgument)->nType) {
                case 0:
                    if (!cpuSetDevicePut(((System*)pDisk->pHost)->apObject[SOT_CPU], pArgument, (Put8Func)diskPutDrive8,
                                         (Put16Func)diskPutDrive16, (Put32Func)diskPutDrive32,
                                         (Put64Func)diskPutDrive64)) {
                        return FALSE;
                    }

                    if (!cpuSetDeviceGet(((System*)pDisk->pHost)->apObject[SOT_CPU], pArgument, (Get8Func)diskGetDrive8,
                                         (Get16Func)diskGetDrive16, (Get32Func)diskGetDrive32,
                                         (Get64Func)diskGetDrive64)) {
                        return FALSE;
                    }
                    break;
                case 1:
                    if (!cpuSetDevicePut(((System*)pDisk->pHost)->apObject[SOT_CPU], pArgument, (Put8Func)diskPutROM8,
                                         (Put16Func)diskPutROM16, (Put32Func)diskPutROM32, (Put64Func)diskPutROM64)) {
                        return FALSE;
                    }

                    if (!cpuSetDeviceGet(((System*)pDisk->pHost)->apObject[SOT_CPU], pArgument, (Get8Func)diskGetROM8,
                                         (Get16Func)diskGetROM16, (Get32Func)diskGetROM32, (Get64Func)diskGetROM64)) {
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
