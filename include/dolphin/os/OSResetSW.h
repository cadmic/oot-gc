#ifndef _DOLPHIN_OSRESETSW
#define _DOLPHIN_OSRESETSW

#include "dolphin/os/OSContext.h"
#include "dolphin/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*OSResetCallback)(void);

bool OSGetResetButtonState(void);

#ifdef __cplusplus
}
#endif

#endif // _DOLPHIN_OSRESETSW
