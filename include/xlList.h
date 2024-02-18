#ifndef _XL_LIST_H
#define _XL_LIST_H

#include <dolphin/types.h>

typedef struct tXL_NODE tXL_NODE;

struct tXL_NODE {
    /* 0x0 */ tXL_NODE* next;
    /* 0x4 */ u8 data[];
}; // size = 0x4

typedef struct tXL_LIST {
    /* 0x0 */ s32 nItemSize;
    /* 0x4 */ s32 nItemCount;
    /* 0x8 */ void* pNodeHead;
    /* 0xC */ void* pNodeNext;
} tXL_LIST; // size = 0x10

BOOL xlListReset(void);
BOOL xlListSetup(void);
BOOL xlListTestItem(tXL_LIST* pList, void* pItem);
BOOL xlListFreeItem(tXL_LIST* pList, void** ppItem);
BOOL xlListMakeItem(tXL_LIST* pList, void** ppItem);
BOOL xlListFree(tXL_LIST** ppList);
BOOL xlListMake(tXL_LIST** ppList);

#endif
