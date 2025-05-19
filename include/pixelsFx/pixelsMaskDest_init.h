#ifndef PIXELSMASKDEST_INIT_H
#define PIXELSMASKDEST_INIT_H

#include "sdl/sdl_init.h" 

typedef struct PIXELSMASKDEST_Context {
    int widthDest;
    int heightDest;
    Uint8 *maskDest;
} PIXELSMASKDEST_Context;

PIXELSMASKDEST_Context *pixelsMaskDestContext_init(SDL_Context *sdlContext);

void cleanupPixelsMaskDest(PIXELSMASKDEST_Context *pixelsMaskDestContext);

PIXELSMASKDEST_Context *pixelsMaskDestContext_refresh (
                                PIXELSMASKDEST_Context *pixelsMaskDestContext,
                                SDL_Context *sdlContext);
#endif 
