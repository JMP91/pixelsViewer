#ifndef PIXELS_INIT_H
#define PIXELS_INIT_H

#include "sdl/sdl_init.h"

typedef struct PIXELS_Context {
    int pixelsWidth;
    int pixelsHeight;
    int total;
    Uint32 color; 
    Uint32 *pixels;
    Uint8 *stateMap;
    Uint8 *maskDest;
    Uint8 *maskSrc;
} PIXELS_Context;

PIXELS_Context *pixelsContext_init(SDL_Context *sdlContext);
void cleanupPixels(PIXELS_Context *pixelsContext_init);

PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext);
#endif 
