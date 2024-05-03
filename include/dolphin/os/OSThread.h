#ifndef _DOLPHIN_OSTHREAD
#define _DOLPHIN_OSTHREAD

#include "dolphin/os/OSContext.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OS_THREAD_SPECIFIC_MAX 2

typedef struct OSThread OSThread;
typedef struct OSThreadQueue OSThreadQueue;
typedef struct OSThreadLink OSThreadLink;
typedef s32 OSPriority; //  0 highest, 31 lowest

typedef struct OSMutex OSMutex;
typedef struct OSMutexQueue OSMutexQueue;
typedef struct OSMutexLink OSMutexLink;
typedef struct OSCond OSCond;

typedef void (*OSIdleFunction)(void* param);
typedef void (*OSSwitchThreadCallback)(OSThread* from, OSThread* to);

struct OSThreadQueue {
    OSThread* head;
    OSThread* tail;
};

struct OSThreadLink {
    OSThread* next;
    OSThread* prev;
};

struct OSMutexQueue {
    OSMutex* head;
    OSMutex* tail;
};

struct OSMutexLink {
    OSMutex* next;
    OSMutex* prev;
};

struct OSThread {
    OSContext context;
    u16 state;
    u16 attr;
    s32 suspend;
    OSPriority priority;
    OSPriority base;
    void* val;
    OSThreadQueue* queue;
    OSThreadLink link;
    OSThreadQueue queueJoin;
    OSMutex* mutex;
    OSMutexQueue queueMutex;
    OSThreadLink linkActive;
    u8* stackBase;
    u32* stackEnd;
    s32 error;
    void* specific[OS_THREAD_SPECIFIC_MAX];
};

enum OS_THREAD_STATE {
    OS_THREAD_STATE_READY = 1,
    OS_THREAD_STATE_RUNNING = 2,
    OS_THREAD_STATE_WAITING = 4,
    OS_THREAD_STATE_MORIBUND = 8
};

#define OS_THREAD_ATTR_DETACH 0x0001u

#define OS_THREAD_STACK_MAGIC 0xDEADBABE

#define OS_PRIORITY_MIN 0 // highest
#define OS_PRIORITY_MAX 31 // lowest
#define OS_PRIORITY_IDLE OS_PRIORITY_MAX

OSThread* __OSCurrentThread AT_ADDRESS(OS_BASE_CACHED | 0x00E4);
OSThreadQueue __OSActiveThreadQueue AT_ADDRESS(OS_BASE_CACHED | 0x00DC);
volatile OSContext* __OSFPUContext AT_ADDRESS(OS_BASE_CACHED | 0x00D8);

void __OSThreadInit(void);
void OSInitThreadQueue(OSThreadQueue* queue);
OSThread* OSGetCurrentThread(void);
s32 OSDisableScheduler(void);
s32 OSEnableScheduler(void);
OSPriority __OSGetEffectivePriority(OSThread* thread);
void __OSReschedule(void);
bool OSCreateThread(OSThread* thread, void* (*func)(void*), void* param, void* stack, u32 stackSize,
                    OSPriority priority, u16 attr);
void OSExitThread(void* val);
void OSCancelThread(OSThread* thread);
s32 OSResumeThread(OSThread* thread);
s32 OSSuspendThread(OSThread* thread);
void OSSleepThread(OSThreadQueue* queue);
void OSWakeupThread(OSThreadQueue* queue);
void OSClearStack(u8 val);

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_OSTHREAD
