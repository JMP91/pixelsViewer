#ifndef PIXELSMASK_H
#define PIXELSMASK_H

#include <SDL2/SDL.h>
#include "pixels_init.h"


typedef struct {
    int *blackStateIndices;
    int *blackDestIndices; // indices dans les buffers binaires (pas pixels)
    int nbrBlackPixelsDestCount;
} MASK_Context;

void pixelsMask_fillDest(PIXELS_Context *pixelsContext);

int  pixelsMask_countBlack(MASK_Context *maskContext,
                            PIXELS_Context *pixelsContext);

void pixelsMask_copyDestToState(PIXELS_Context *pixelsContext);

void pixelsMask_stateToPixels(PIXELS_Context *pixelsContext);

// Fonction “master” qui orchestre tout
void pixelsMask_renderBinaire(PIXELS_Context *pixelsContext);

#endif
