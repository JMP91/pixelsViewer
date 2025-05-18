#ifndef PIXELSMASKSRC_INIT_H
#define PIXELSMASKSRC_INIT_H


typedef struct PIXELSMASKSRC_Context {
    int width;
    int height;
    uint8_t *mask;
} PIXELSMASKSRC_Context;

PIXELSMASKSRC_Context *pixelsMaskSrcContext_init(SDL_Context *sdlContext);

void cleanupPixelsMask(PIXELSMASKSRC_Context *pixelsMaskSrcContext);

PIXELSMASKSRC_Context *pixelsSrcMaskContext_refresh (
                                      PIXELSMASKSRC_Context *pixelsMaskContext,
                                      SDL_Context *sdlContext);
#endif 
