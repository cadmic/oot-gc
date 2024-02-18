#ifndef _XL_CORE_GCN_H
#define _XL_CORE_GCN_H

#include <dolphin/types.h>

void xlCoreBeforeRender(void);
BOOL xlCoreHiResolution(void);
BOOL xlCoreGetArgument(s32 iArgument, char** pszArgument);
s32 xlCoreGetArgumentCount(void);
BOOL xlCoreReset(void);

#endif
