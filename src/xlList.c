#include <dolphin/types.h>

#include "xlList.h"
#include "xlHeap.h"

static tXL_LIST gListList;

#pragma GLOBAL_ASM("asm/non_matchings/xlList/xlListMake.s")

static inline BOOL xlListWipe(tXL_LIST* pList) {
    tXL_NODE* pNode;
    tXL_NODE* pNodeNext;

    pNode = pList->pNodeHead;
    while (pNode != NULL) {
        pNodeNext = pNode->next;
        if (!xlHeapFree((void**)&pNode)) {
            return FALSE;
        }
        pNode = pNodeNext;
    }

    pList->nItemCount = 0;
    pList->pNodeNext = NULL;
    pList->pNodeHead = NULL;
    return TRUE;
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/non_matchings/xlList/xlListFree.s")
#else
BOOL xlListFree(tXL_LIST** ppList) {
    if (!xlListWipe(*ppList)) {
        return FALSE;
    }

    if (!xlListFreeItem(&gListList, (void**)ppList)) {
        return FALSE;
    }

    return TRUE;
}
#endif

BOOL xlListMakeItem(tXL_LIST* pList, void** ppItem) {
    BOOL nSize;
    tXL_NODE* pListNode;
    tXL_NODE* pNode;
    tXL_NODE* pNodeNext;

    nSize = pList->nItemSize + 4;
    if (!xlHeapTake((void**)&pListNode, nSize)) {
        return FALSE;
    }

    pListNode->next = NULL;
    *ppItem = (void*)pListNode->data;
    pNode = (tXL_NODE*)&pList->pNodeHead;
    while (pNode != NULL) {
        pNodeNext = pNode->next;
        if (pNodeNext == NULL) {
            pNode->next = pListNode;
            pList->nItemCount++;
            return TRUE;
        }
        pNode = pNodeNext;
    }

    return FALSE;
}

BOOL xlListFreeItem(tXL_LIST* pList, void** ppItem) {
    tXL_NODE* pNode;
    tXL_NODE* pNodeNext;

    if (pList->pNodeHead == NULL) {
        return FALSE;
    }

    pNode = (tXL_NODE*)&pList->pNodeHead;
    while (pNode != NULL) {
        pNodeNext = pNode->next;
        if (*ppItem == (void*)pNodeNext->data) {
            pNode->next = pNodeNext->next;
            *ppItem = NULL;
            if (!xlHeapFree((void**)&pNodeNext)) {
                return FALSE;
            }
            pList->nItemCount--;
            return TRUE;
        }
        pNode = pNodeNext;
    }

    return FALSE;
}

static inline BOOL xlListTest(tXL_LIST* pList) {
    tXL_NODE* pNode;

    if (pList == &gListList) {
        return TRUE;
    }

    pNode = gListList.pNodeHead;
    while (pNode != NULL) {
        if (pList == (tXL_LIST*)pNode->data) {
            return TRUE;
        }
        pNode = pNode->next;
    }

    return FALSE;
}

BOOL xlListTestItem(tXL_LIST* pList, void* pItem) {
    tXL_NODE* pListNode;

    if (!xlListTest(pList) || pItem == NULL) {
        return FALSE;
    }

    pListNode = pList->pNodeHead;
    while (pListNode != NULL) {
        if (pItem == pListNode->data) {
            return TRUE;
        }
        pListNode = pListNode->next;
    }

    return FALSE;
}

BOOL xlListSetup(void) {
    gListList.nItemCount = 0;
    gListList.nItemSize = sizeof(tXL_LIST);
    gListList.pNodeNext = NULL;
    gListList.pNodeHead = NULL;
    return TRUE;
}

BOOL xlListReset(void) { return TRUE; }
