#ifndef _SIMGCN_H
#define _SIMGCN_H

#include "system.h"
#include <dolphin/types.h>

extern s32 gDVDResetToggle;
extern BOOL gbDisplayedError;

extern System* gpSystem;

BOOL simulatorShowLoad(s32 /* unknown */, char* szNameFile, f32 rProgress);

#endif
