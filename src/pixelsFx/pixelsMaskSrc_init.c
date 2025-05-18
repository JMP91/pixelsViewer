#include <stdio.h>
#include <stdlib.h>
#include "sdl/sdl_init.h"
#include "pixelsFx/pixelsMaskSrc_init.h"

PIXELSMASKSRC_Context *pixelsMaskSrcContext_init(SDL_Context *sdlContext) {

    PIXELSMASKSRC_Context *pixelsMaskSrcContext =
                                        malloc(sizeof(PIXELSMASKSRC_Context));
    if (!pixelsMaskSrcContext) {
        fprintf(stderr, "Erreur allocation PIXELSMASKSRC_Context\n");
        return NULL;
    }

    int windowWidth, windowHeight;                                              
    SDL_GetRendererOutputSize(sdlContext->renderer,                             
                            &windowWidth, &windowHeight);      
    if (SDL_GetRendererOutputSize(sdlContext->renderer,
                                        &windowWidth, &windowHeight) != 0) {
        fprintf(stderr, "Erreur SDL_GetRendererOutputSize : %s\n",
                                                            SDL_GetError());
        free(pixelsMaskSrcContext);
        return NULL;
    }

    pixelsMaskSrcContext->width = windowWidth;
    pixelsMaskSrcContext->height = windowHeight;
    pixelsMaskSrcContext->mask = malloc(windowWidth * windowHeight
                                                        * sizeof(Uint8));
    if (!pixelsMaskSrcContext->mask) {
      fprintf(stderr, "Erreur : allocation du tableau mask  échouée\n");
        free(pixelsMaskSrcContext);
        return NULL;
    }

    for (int i = 0; i < windowWidth * windowHeight; i++) {
        pixelsMaskSrcContext->mask[i] = 0;
    }

    return pixelsMaskSrcContext;

}

void cleanupPixelsMaskSrc(PIXELSMASKSRC_Context *pixelsMaskSrcContext) {
    if (!pixelsMaskSrcContext) return;

    if (pixelsMaskSrcContext->mask) {
        free(pixelsMaskSrcContext->mask);
    }
    free(pixelsMaskSrcContext);
}
/*
PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext){

    cleanupPixels (pixelsContext);

    return pixelsContext_init(sdlContext);
}
*/
