#ifndef PIXELSMASK_H
#define PIXELSMASK_H

#include <SDL2/SDL.h>
#include "pixels_init.h"
#include "core/utils.h"

typedef struct {
    Uint32 *blackStateIndices;
    Uint32 *blackDestIndices; // indices buffers binaires (pas pixels)
    Uint32 nbrBlackPixelsDestCount;
} MASK_Context;

void pixelsMask_fillDest(PIXELS_Context *pixelsContext);

Uint32  pixelsMask_countBlack(MASK_Context *maskContext,
                            PIXELS_Context *pixelsContext);

void pixelsMask_fillBlackDestIndices (MASK_Context *maskContext,
                                        PIXELS_Context *pixelsContext);

void pixelsMask_fillBlackStateIndices (MASK_Context *maskContext,
                                        PIXELS_Context *pixelsContext);


#endif
