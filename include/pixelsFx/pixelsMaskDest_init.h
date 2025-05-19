#ifndef PIXELSMASKDEST_INIT_H
#define PIXELSMASKDEST_INIT_H


typedef struct PIXELSMASKDEST_Context {
    int widthDest;
    int heightDest;
    uint8_t *maskDest;
} PIXELSMASKDEST_Context;

PIXELSMASKDEST_Context *pixelsMaskDestContext_init(SDL_Context *sdlContext);

void cleanupPixelsMaskDest(PIXELSMASKDEST_Context *pixelsMaskDestContext);

PIXELSMASKDEST_Context *pixelsMaskDestContext_refresh (
                                PIXELSMASKDEST_Context *pixelsMaskDestContext,
                                SDL_Context *sdlContext);
#endif 
