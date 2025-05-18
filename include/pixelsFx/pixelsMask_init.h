#ifndef PIXELSMASK_INIT_H
#define PIXELSMASK_INIT_H


typedef struct PIXELSMASK_Context {
    int width;
    int height;
    uint8_t *mask;
} PIXELSMASK_Context;

PIXELSMASK_Context *pixelsMaskContext_init(SDL_Context *sdlContext);

void cleanupPixelsMask(PIXELSMASK_Context *pixelsMaskContext);

PIXELSMASK_Context *pixelsMaskContext_refresh (
                                        PIXELSMASK_Context *pixelsMaskContext,
                                        SDL_Context *sdlContext);
#endif 
