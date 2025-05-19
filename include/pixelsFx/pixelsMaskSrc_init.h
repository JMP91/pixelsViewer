#ifndef PIXELSMASKSRC_INIT_H
#define PIXELSMASKSRC_INIT_H


typedef struct PIXELSMASKSRC_Context {
    int widthSrc;
    int heightSrc;
    uint8_t *maskSrc;
} PIXELSMASKSRC_Context;

PIXELSMASKSRC_Context *pixelsMaskSrcContext_init(SDL_Context *sdlContext);

void cleanupPixelsMaskSrc(PIXELSMASKSRC_Context *pixelsMaskSrcContext);

PIXELSMASKSRC_Context *pixelsSrcMaskContext_refresh (
                                  PIXELSMASKSRC_Context *pixelsMaskSrcContext,
                                  SDL_Context *sdlContext);
#endif 
