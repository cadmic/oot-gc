#ifndef _DOLPHIN__PPC_EABI_INIT
#define _DOLPHIN__PPC_EABI_INIT

#include "dolphin/types.h"
#include "macros.h"

INIT void __init_hardware(void);
INIT void __flush_cache(register void* address, register unsigned int size);

void __init_user(void);
void __init_cpp(void);
extern void __OSFPRInit(void);

#endif // _DOLPHIN__PPC_EABI_INIT
