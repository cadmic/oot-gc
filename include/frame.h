#ifndef _FRAME_H
#define _FRAME_H

#include "dolphin.h"

// __anon_0x23B04
typedef struct Viewport {
    /* 0x0 */ f32 rX;
    /* 0x4 */ f32 rY;
    /* 0x8 */ f32 rSizeX;
    /* 0xC */ f32 rSizeY;
} Viewport; // size = 0x10

// __anon_0x23B9E
typedef struct FrameBuffer {
    /* 0x00 */ s32 nSize;
    /* 0x04 */ s32 nWidth;
    /* 0x08 */ s32 nFormat;
    /* 0x0C */ void* pData;
    /* 0x10 */ s32 nAddress;
} FrameBuffer; // size = 0x14

// __anon_0x274AD
typedef struct Vect3F {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vect3F; // size = 0xC

// __anon_0x23CAB
typedef struct Light {
    /* 0x00 */ s32 bTransformed;
    /* 0x04 */ struct Vect3F rVecOrigTowards;
    /* 0x10 */ f32 rColorR;
    /* 0x14 */ f32 rColorG;
    /* 0x18 */ f32 rColorB;
    /* 0x1C */ f32 rVectorX;
    /* 0x20 */ f32 rVectorY;
    /* 0x24 */ f32 rVectorZ;
    /* 0x28 */ f32 kc;
    /* 0x2C */ f32 kl;
    /* 0x30 */ f32 kq;
    /* 0x34 */ s16 coordX;
    /* 0x36 */ s16 coordY;
    /* 0x38 */ s16 coordZ;
} Light; // size = 0x3C

// __anon_0x23EDB
typedef struct LookAt {
    /* 0x00 */ s32 bTransformed;
    /* 0x04 */ struct Vect3F rS;
    /* 0x10 */ struct Vect3F rT;
    /* 0x1C */ struct Vect3F rSRaw;
    /* 0x28 */ struct Vect3F rTRaw;
} LookAt; // size = 0x34

// __anon_0x23FC4
typedef struct Vertex {
    /* 0x00 */ f32 rSum;
    /* 0x04 */ f32 rS;
    /* 0x08 */ f32 rT;
    /* 0x0C */ struct Vect3F vec;
    /* 0x18 */ u8 anColor[4];
} Vertex; // size = 0x1C

// __anon_0x24123
typedef union TMEM_Block {
    /* 0x0 */ u8 u8[4096];
    /* 0x0 */ u16 u16[2048];
    /* 0x0 */ u32 u32[1024];
    /* 0x0 */ u64 u64[512];
} TMEM_Block;

// __anon_0x241C0
typedef struct TextureMemory {
    /* 0x0 */ union TMEM_Block data;
} TextureMemory; // size = 0x1000

// _FRAME_TEXTURE
// __anon_0x24462
typedef struct FrameTexture {
    /* 0x00 */ s32 nMode;
    /* 0x04 */ s32 iPackPixel;
    /* 0x08 */ s32 iPackColor;
    /* 0x0C */ s32 nFrameLast;
    /* 0x10 */ s16 nSizeX;
    /* 0x12 */ s16 nSizeY;
    /* 0x14 */ u32 nAddress;
    /* 0x18 */ u32 nCodePixel;
    /* 0x1C */ u32 nCodeColor;
    /* 0x20 */ struct _FRAME_TEXTURE* pTextureNext;
    /* 0x24 */ u32 nData0;
    /* 0x28 */ u32 nData1;
    /* 0x2C */ u32 nData2;
    /* 0x30 */ u32 nData3;
    /* 0x34 */ enum _GXTexFmt eFormat;
    /* 0x38 */ struct _GXTlutObj objectTLUT;
    /* 0x44 */ struct _GXTexObj objectTexture;
    /* 0x64 */ enum _GXTexWrapMode eWrapS;
    /* 0x68 */ enum _GXTexWrapMode eWrapT;
} FrameTexture; // size = 0x6C

// __anon_0x247BF
typedef struct Tile {
    /* 0x00 */ s32 nSize;
    /* 0x04 */ s32 nTMEM;
    /* 0x08 */ s32 iTLUT;
    /* 0x0C */ s32 nSizeX;
    /* 0x10 */ s32 nFormat;
    /* 0x14 */ s16 nMaskS;
    /* 0x16 */ s16 nMaskT;
    /* 0x18 */ s16 nModeS;
    /* 0x1A */ s16 nModeT;
    /* 0x1C */ s16 nShiftS;
    /* 0x1E */ s16 nShiftT;
    /* 0x20 */ s16 nX0;
    /* 0x22 */ s16 nY0;
    /* 0x24 */ s16 nX1;
    /* 0x26 */ s16 nY1;
    /* 0x28 */ u32 nCodePixel;
} Tile; // size = 0x2C

// __anon_0x25D5E
typedef enum TypeProjection {
    FMP_NONE = -1,
    FMP_PERSPECTIVE = 0,
    FMP_ORTHOGRAPHIC = 1,
} TypeProjection;

// __anon_0x24A81
typedef struct MatrixHint {
    /* 0x00 */ s32 nCount;
    /* 0x04 */ f32 rScale;
    /* 0x08 */ f32 rAspect;
    /* 0x0C */ f32 rFieldOfViewY;
    /* 0x10 */ f32 rClipNear;
    /* 0x14 */ f32 rClipFar;
    /* 0x18 */ u32 nAddressFloat;
    /* 0x1C */ u32 nAddressFixed;
    /* 0x20 */ TypeProjection eProjection;
} MatrixHint; // size = 0x24

// __anon_0x24C38
typedef struct Frame {
    /* 0x00000 */ u32 anCIMGAddresses[8];
    /* 0x00020 */ u16 nNumCIMGAddresses;
    /* 0x00024 */ s32 bBlurOn;
    /* 0x00028 */ s32 bHackPause;
    /* 0x0002C */ s32 nHackCount;
    /* 0x00030 */ s32 nFrameCounter;
    /* 0x00034 */ s32 bPauseThisFrame;
    /* 0x00038 */ s32 bCameFromBomberNotes;
    /* 0x0003C */ s32 bInBomberNotes;
    /* 0x00040 */ s32 bShrinking;
    /* 0x00044 */ s32 bSnapShot;
    /* 0x00048 */ s32 bUsingLens;
    /* 0x0004C */ u8 cBlurAlpha;
    /* 0x00050 */ s32 bBlurredThisFrame;
    /* 0x00054 */ s32 nFrameCIMGCalls;
    /* 0x00058 */ s32 bModifyZBuffer;
    /* 0x0005C */ s32 bOverrideDepth;
    /* 0x00060 */ s32 nZBufferSets;
    /* 0x00064 */ s32 nLastFrameZSets;
    /* 0x00068 */ s32 bPauseBGDrawn;
    /* 0x0006C */ s32 bFrameOn;
    /* 0x00070 */ s32 bBackBufferDrawn;
    /* 0x00074 */ s32 bGrabbedFrame;
    /* 0x00078 */ u64* pnGBI;
    /* 0x0007C */ u32 nFlag;
    /* 0x00080 */ f32 rScaleX;
    /* 0x00084 */ f32 rScaleY;
    /* 0x00088 */ u32 nCountFrames;
    /* 0x0008C */ u32 nMode;
    /* 0x00090 */ u32 aMode[10];
    /* 0x000B8 */ struct Viewport viewport;
    /* 0x000C8 */ struct FrameBuffer aBuffer[4];
    /* 0x00118 */ u32 nOffsetDepth0;
    /* 0x0011C */ u32 nOffsetDepth1;
    /* 0x00120 */ s32 nWidthLine;
    /* 0x00124 */ f32 rDepth;
    /* 0x00128 */ f32 rDelta;
    /* 0x0012C */ s32 (*aDraw[4])(void*, void*);
    /* 0x0013C */ s32 nCountLight;
    /* 0x00140 */ struct Light aLight[8];
    /* 0x00320 */ struct LookAt lookAt;
    /* 0x00354 */ s32 nCountVertex;
    /* 0x00358 */ struct Vertex aVertex[80];
    /* 0x00C18 */ struct TextureMemory TMEM;
    /* 0x01C18 */ void* aPixelData;
    /* 0x01C1C */ void* aColorData;
    /* 0x01C20 */ s32 nBlocksPixel;
    /* 0x01C24 */ s32 nBlocksMaxPixel;
    /* 0x01C28 */ s32 nBlocksColor;
    /* 0x01C2C */ s32 nBlocksMaxColor;
    /* 0x01C30 */ s32 nBlocksTexture;
    /* 0x01C34 */ s32 nBlocksMaxTexture;
    /* 0x01C38 */ u32 anPackPixel[48];
    /* 0x01CF8 */ u32 anPackColor[320];
    /* 0x021F8 */ u32 nAddressLoad;
    /* 0x021FC */ u32 nCodePixel;
    /* 0x02200 */ u32 nTlutCode[16];
    /* 0x02240 */ struct FrameTexture aTexture[2048];
    /* 0x38240 */ u32 anTextureUsed[64];
    /* 0x38340 */ struct FrameTexture* apTextureCached[4096];
    /* 0x3C340 */ s32 iTileLoad;
    /* 0x3C344 */ u32 n2dLoadTexType;
    /* 0x3C348 */ s32 nLastX0;
    /* 0x3C34C */ s32 nLastY0;
    /* 0x3C350 */ s32 nLastX1;
    /* 0x3C354 */ s32 nLastY1;
    /* 0x3C358 */ struct Tile aTile[8];
    /* 0x3C4B8 */ s32 anSizeX[2];
    /* 0x3C4C0 */ s32 anSizeY[2];
    /* 0x3C4C8 */ s32 iHintMatrix;
    /* 0x3C4CC */ s32 iMatrixModel;
    /* 0x3C4D0 */ s32 iHintProjection;
    /* 0x3C4D4 */ f32 matrixView[4][4];
    /* 0x3C514 */ s32 iHintLast;
    /* 0x3C518 */ s32 iHintHack;
    /* 0x3C51C */ enum TypeProjection eTypeProjection;
    /* 0x3C520 */ f32 aMatrixModel[10][4][4];
    /* 0x3C7A0 */ f32 matrixProjection[4][4];
    /* 0x3C7E0 */ f32 matrixProjectionExtra[4][4];
    /* 0x3C820 */ struct MatrixHint MatrixHint[64];
    /* 0x3D120 */ u8 primLODmin;
    /* 0x3D121 */ u8 primLODfrac;
    /* 0x3D122 */ u8 lastTile;
    /* 0x3D123 */ u8 iTileDrawn;
    /* 0x3D124 */ struct _GXColor aColor[5];
    /* 0x3D138 */ u32 nModeVtx;
    /* 0x3D13C */ u16* nTempBuffer;
    /* 0x3D140 */ u16* nCopyBuffer;
    /* 0x3D144 */ u32* nLensBuffer;
    /* 0x3D148 */ u16* nCameraBuffer;
} Frame; // size = 0x3D150

// __anon_0x2614E
typedef enum FBTType {
    FBT_NONE = -1,
    FBT_DEPTH = 0,
    FBT_IMAGE = 1,
    FBT_COLOR_SHOW = 2,
    FBT_COLOR_DRAW = 3,
    FBT_COUNT = 4,
} FBTType;

// __anon_0x2625D
typedef enum ColorHeat {
    FRT_NONE = -1,
    FRT_COLD = 0,
    FRT_WARM = 1,
} ColorHeat;

// __anon_0x26C3F
typedef enum FLTType {
    FLT_NONE = -1,
    FLT_TILE = 0,
    FLT_BLOCK = 1,
} FLTType;

// __anon_0x2D45B
typedef struct Primitive {
    /* 0x0 */ s32 nCount;
    /* 0x4 */ u8 anData[768];
} Primitive; // size = 0x304

// __anon_0x27B8C
typedef enum ViewType {
    FMT_MODELVIEW = 0,
    FMT_PROJECTION = 1,
} ViewType;

// __anon_0x27E96
typedef enum Etype {
    FMT_NONE = -1,
    FMT_FOG = 0,
    FMT_GEOMETRY = 1,
    FMT_TEXTURE1 = 2,
    FMT_TEXTURE2 = 3,
    FMT_OTHER0 = 4,
    FMT_OTHER1 = 5,
    FMT_COMBINE_COLOR1 = 6,
    FMT_COMBINE_COLOR2 = 7,
    FMT_COMBINE_ALPHA1 = 8,
    FMT_COMBINE_ALPHA2 = 9,
    FMT_COUNT = 10,
} Etype;

// __anon_0x2813A
typedef enum ESize {
    FS_NONE = -1,
    FS_SOURCE = 0,
    FS_TARGET = 1,
    FS_COUNT = 2,
} ESize;

// Range: 0x8002113C -> 0x80021204
s32 frameScaleMatrix(f32 (*matrixResult)[4], f32 (*matrix)[4], f32 rScale) ;

// Erased
static s32 frameConcatenateMatrix(f32 (*matrixResult)[4], f32 (*matrixA)[4], f32 (*matrixB)[4]) ;

// Range: 0x80021070 -> 0x8002113C
static s32 frameConvertYUVtoRGB(u32* YUV, u32* RGB) ;

// Range: 0x80020FA4 -> 0x80021070
static s32 packTakeBlocks(s32* piPack, u32* anPack, s32 nPackCount, s32 nBlockCount) ;

// Range: 0x80020F3C -> 0x80020FA4
static s32 packFreeBlocks(s32* piPack, u32* anPack) ;

// Erased
static s32 packReset(u32* anPack, s32 nPackCount) ;

// Range: 0x80020E20 -> 0x80020F3C
static s32 frameMakeTexture(struct Frame* pFrame, struct _FRAME_TEXTURE** ppTexture) ;

// Erased
static s32 frameFreeTexture(struct Frame* pFrame, struct _FRAME_TEXTURE* pTexture) ;

// Range: 0x80020958 -> 0x80020E20
static s32 frameSetupCache(struct Frame* pFrame) ;

// Erased
static s32 frameResetCache(struct Frame* pFrame) ;

// Range: 0x80020764 -> 0x80020958
static s32 frameUpdateCache(struct Frame* pFrame) ;

// Erased
static s32 frameMultiTexture(struct Frame* pFrame) ;

// Range: 0x80020340 -> 0x80020764
static s32 frameLoadTile(struct Frame* pFrame, struct _FRAME_TEXTURE** ppTexture, s32 iTileCode) ;

// Erased
static s32 frameSetupTrackBuffer() ;

// Erased
static s32 frameCheckTrackBuffer() ;

// Erased
static s32 frameUpdateTrackBuffer() ;

// Range: 0x800202FC -> 0x80020340
s32 frameDrawReset(struct Frame* pFrame, s32 nFlag) ;

// Range: 0x800202D0 -> 0x800202FC
s32 frameSetFill(struct Frame* pFrame, s32 bFill) ;

// Erased
static s32 frameGetFill(struct Frame* pFrame, s32* pbFill) ;

// Erased
static s32 frameSetWire(struct Frame* pFrame, s32 bWire) ;

// Erased
static s32 frameGetWire(struct Frame* pFrame, s32* pbWire) ;

// Range: 0x800201A8 -> 0x800202D0
s32 frameSetSize(struct Frame* pFrame, ESize eSize, s32 nSizeX, s32 nSizeY) ;

// Erased
static s32 frameGetSize(struct Frame* pFrame, ESize eSize, s32* pnSizeX, s32* pnSizeY) ;

// Range: 0x80020014 -> 0x800201A8
s32 frameSetMode(struct Frame* pFrame, Etype eType, u32 nMode) ;

// Range: 0x8001FFFC -> 0x80020014
s32 frameGetMode(struct Frame* pFrame, Etype eType, u32* pnMode) ;

// Range: 0x8001F970 -> 0x8001FFFC
s32 frameSetMatrix(struct Frame* pFrame, f32 (*matrix)[4], ViewType eType, s32 bLoad, s32 bPush,
                   s32 nAddressN64) ;

// Range: 0x8001F850 -> 0x8001F970
s32 frameGetMatrix(struct Frame* pFrame, f32 (*matrix)[4], ViewType eType, s32 bPull) ;

// Erased
static s32 frameProjectVertex(struct Frame* pFrame, s32 iVertex, f32* prX, f32* prY, f32* prZ) ;

// Range: 0x8001EDCC -> 0x8001F850
s32 frameLoadVertex(struct Frame* pFrame, void* pBuffer, s32 iVertex0, s32 nCount) ;

// Range: 0x8001EC80 -> 0x8001EDCC
s32 frameCullDL(struct Frame* pFrame, s32 nVertexStart, s32 nVertexEnd) ;

// Range: 0x8001EBA0 -> 0x8001EC80
s32 frameLoadTLUT(struct Frame* pFrame, s32 nCount, s32 iTile) ;

// Range: 0x8001DC58 -> 0x8001EBA0
s32 frameLoadTMEM(struct Frame* pFrame, FLTType eType, s32 iTile) ;

// Range: 0x8001DC4C -> 0x8001DC58
s32 frameSetLightCount(struct Frame* pFrame, s32 nCount) ;

// Range: 0x8001DB24 -> 0x8001DC4C
s32 frameSetLight(struct Frame* pFrame, s32 iLight, char* pData) ;

// Range: 0x8001DA74 -> 0x8001DB24
s32 frameSetLookAt(struct Frame* pFrame, s32 iLookAt, char* pData) ;

// Range: 0x8001D8E0 -> 0x8001DA74
s32 frameSetViewport(struct Frame* pFrame, s16* pData) ;

// Range: 0x8001D830 -> 0x8001D8E0
s32 frameResetUCode(struct Frame* pFrame, ColorHeat eType) ;

// Range: 0x8001D7F8 -> 0x8001D830
s32 frameSetBuffer(struct Frame* pFrame, FBTType eType) ;

// Range: 0x8001D740 -> 0x8001D7F8
s32 frameFixMatrixHint(struct Frame* pFrame, s32 nAddressFloat, s32 nAddressFixed) ;

// Erased
static s32 frameGetMatrixHint(struct Frame* pFrame, u32 nAddress, s32* piHint) ;

// Range: 0x8001D624 -> 0x8001D740
s32 frameSetMatrixHint(struct Frame* pFrame, TypeProjection eProjection, s32 nAddressFloat,
                       s32 nAddressFixed, f32 rNear, f32 rFar, f32 rFOVY, f32 rAspect, f32 rScale) ;

// Range: 0x8001D4B8 -> 0x8001D624
s32 frameInvalidateCache(struct Frame* pFrame, s32 nOffset0, s32 nOffset1) ;

// Range: 0x8001D39C -> 0x8001D4B8
s32 frameGetTextureInfo(struct Frame* pFrame, struct __anon_0x25A82* pInfo) ;

// Range: 0x8001D34C -> 0x8001D39C
void PSMTX44MultVecNoW(f32 (*m)[4], struct __anon_0x239BA* src, struct __anon_0x239BA* dst) ;

s32 _frameDrawRectangle(Frame* pFrame, u32 nColor, s32 nX, s32 nY, s32 nSizeX, s32 nSizeY);
s32 frameEvent(Frame* pFrame, s32 nEvent);
s32 frameDrawTriangle_C0T0(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawTriangle_C1T0(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawTriangle_C3T0(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawTriangle_C0T3(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawTriangle_C1T3(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawTriangle_C3T3(struct Frame* pFrame, struct Primitive* pPrimitive);

s32 frameDrawLine_C0T0(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawLine_C1T0(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawLine_C2T0(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawLine_C0T2(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawLine_C1T2(struct Frame* pFrame, struct Primitive* pPrimitive);
s32 frameDrawLine_C2T2(struct Frame* pFrame, struct Primitive* pPrimitive);

#endif
