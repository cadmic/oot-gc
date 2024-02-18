#ifndef _XL_HEAP_H
#define _XL_HEAP_H

BOOL xlHeapReset(void);
BOOL xlHeapSetup(void* pHeap, s32 nSizeBytes);
BOOL xlHeapGetFree(s32* pnFreeBytes);
BOOL xlHeapFill32(void* pHeap, s32 nByteCount, u32 nData);
BOOL xlHeapCopy(void* pHeapTarget, void* pHeapSource, s32 nByteCount);
BOOL xlHeapCompact(void);
BOOL xlHeapFree(void** ppHeap);
BOOL xlHeapTake(void** ppHeap, s32 nByteCount);

#endif
