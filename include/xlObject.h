#ifndef _XL_OBJECT_H
#define _XL_OBJECT_H

#include <dolphin/types.h>

typedef struct _XL_OBJECTTYPE _XL_OBJECTTYPE;

typedef BOOL (*EventFunc)(void* pObject, s32 nEvent, void* pArgument);

struct _XL_OBJECTTYPE {
    /* 0x0 */ char* szName;
    /* 0x4 */ s32 nSizeObject;
    /* 0x8 */ _XL_OBJECTTYPE* pClassBase;
    /* 0xC */ EventFunc pfEvent;
}; // size: 0x10

BOOL xlObjectReset(void);
BOOL xlObjectSetup(void);
BOOL xlObjectEvent(void* pObject, s32 nEvent, void* pArgument);
BOOL xlObjectTest(void* pObject, _XL_OBJECTTYPE* pType);
BOOL xlObjectFree(void** ppObject);
BOOL xlObjectMake(void** ppObject, void* pArgument, _XL_OBJECTTYPE* pType);

#endif
