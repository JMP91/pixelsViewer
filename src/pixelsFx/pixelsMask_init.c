#include <stdio.h>
#include <stdlib.h>
#include "sdl/sdl_init.h"
#include "pixelsFx/pixelsMask_init.h"

PIXELSMASK_Context *pixelsMaskContext_init(SDL_Context *sdlContext) {

    PIXELSMASK_Context *pixelsMaskContext = malloc(sizeof(PIXELSMASK_Context));
    if (!pixelsMaskContext) {
        fprintf(stderr, "Erreur allocation PIXELSMASK_Context\n");
        return NULL;
    }

    int windowWidth, windowHeight;                                              
    SDL_GetRendererOutputSize(sdlContext->renderer,                             
                            &windowWidth, &windowHeight);      
    if (SDL_GetRendererOutputSize(sdlContext->renderer,
                                        &windowWidth, &windowHeight) != 0) {
        fprintf(stderr, "Erreur SDL_GetRendererOutputSize : %s\n",
                                                            SDL_GetError());
        free(pixelsMaskContext);
        return NULL;
    }

    pixelsMaskContext->width = windowWidth;
    pixelsMaskContext->height = windowHeight;
    pixelsMaskContext->mask = malloc(windowWidth * windowHeight
                                                        * sizeof(Uint8));
    if (!pixelsMaskContext->mask) {
      fprintf(stderr, "Erreur : allocation du tableau mask  échouée\n");
        free(pixelsMaskContext);
        return NULL;
    }

    for (int i = 0; i < windowWidth * windowHeight; i++) {
        pixelsMaskContext->mask[i] = 0;
    }

    return pixelsMaskContext;

}

void cleanupPixelsMask(PIXELSMASK_Context *pixelsMaskContext) {
    if (!pixelsMaskContext) return;

    if (pixelsMaskContext->mask) {
        free(pixelsMaskContext->mask);
    }
    free(pixelsMaskContext);
}
/*
PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext){

    cleanupPixels (pixelsContext);

    return pixelsContext_init(sdlContext);
}
*/
