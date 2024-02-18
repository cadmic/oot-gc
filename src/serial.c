#include "xlObject.h"
#include "serial.h"
#include "system.h"
#include "ram.h"
#include "cpu.h"

_XL_OBJECTTYPE gClassSerial = {
    "SERIAL",
    sizeof(Serial),
    NULL,
    (EventFunc)serialEvent,
};

BOOL serialPut8(Serial* pSerial, u32 nAddress, s8* pData) { return FALSE; }

BOOL serialPut16(Serial* pSerial, u32 nAddress, s16* pData) { return FALSE; }

BOOL serialPut32(Serial* pSerial, u32 nAddress, s32* pData) {
    u32 nSize;
    void* aData;

    nAddress &= 0x1F;

    switch (nAddress) {
        case 0x00:
            pSerial->nAddress = *pData;
            break;
        case 0x04:
            nSize = 0x40;

            if (!ramGetBuffer(((System*)pSerial->pHost)->apObject[SOT_RAM], &aData, pSerial->nAddress, &nSize)) {
                return FALSE;
            }

            if (!pifGetData(((System*)pSerial->pHost)->apObject[SOT_PIF], aData)) {
                return FALSE;
            }

            xlObjectEvent(pSerial->pHost, 0x1000, (void*)6);
            break;
        case 0x10:
            nSize = 0x40;

            if (!ramGetBuffer(((System*)pSerial->pHost)->apObject[SOT_RAM], &aData, pSerial->nAddress, &nSize)) {
                return FALSE;
            }

            if (!pifSetData(((System*)pSerial->pHost)->apObject[SOT_PIF], aData)) {
                return FALSE;
            }

            xlObjectEvent(pSerial->pHost, 0x1000, (void*)6);
            break;
        case 0x18:
            xlObjectEvent(pSerial->pHost, 0x1001, (void*)6);
            break;
        default:
            return FALSE;
    }

    return TRUE;
}

BOOL serialPut64(Serial* pSerial, u32 nAddress, s64* pData) { return FALSE; }

BOOL serialGet8(Serial* pSerial, u32 nAddress, s8* pData) { return FALSE; }

BOOL serialGet16(Serial* pSerial, u32 nAddress, s16* pData) { return FALSE; }

BOOL serialGet32(Serial* pSerial, u32 nAddress, s32* pData) {
    nAddress &= 0x1F;

    switch (nAddress) {
        case 0x00:
            *pData = pSerial->nAddress;
            break;
        case 0x04:
            *pData = 0;
            break;
        case 0x10:
            *pData = 0;
            break;
        case 0x18:
            *pData = 0;
            break;
        default:
            return FALSE;
    }

    return TRUE;
}

BOOL serialGet64(Serial* pSerial, u32 nAddress, s64* pData) { return FALSE; }

BOOL serialEvent(Serial* pSerial, s32 nEvent, void* pArgument) {
    switch (nEvent) {
        case 2:
            pSerial->pHost = pArgument;
            break;
        case 0x1002:
            if (!cpuSetDevicePut(((System*)pSerial->pHost)->apObject[SOT_CPU], pArgument, (Put8Func)serialPut8,
                                 (Put16Func)serialPut16, (Put32Func)serialPut32, (Put64Func)serialPut64)) {
                return FALSE;
            }

            if (!cpuSetDeviceGet(((System*)pSerial->pHost)->apObject[SOT_CPU], pArgument, (Get8Func)serialGet8,
                                 (Get16Func)serialGet16, (Get32Func)serialGet32, (Get64Func)serialGet64)) {
                return FALSE;
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
