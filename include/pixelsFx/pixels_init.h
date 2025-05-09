#ifndef PIXELS_INIT_H
#define PIXELS_INIT_H

#include <stdint.h>
#include "sdl/sdl_init.h"

typedef struct PIXELS_Context {
    int width;
    int height;
    uint32_t *pixels;
} PIXELS_Context;

PIXELS_Context *pixelsContext_init(SDL_Context *sdlContext);
void cleanupPixels(PIXELS_Context *pixelsContext_init);

PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext);
#endif 
