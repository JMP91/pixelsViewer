#include <stdio.h>
#include <stdlib.h>
#include "sdl/sdl_init.h"
#include "pixelsFx/pixelsMaskDest_init.h"

PIXELSMASKDEST_Context *pixelsMaskDestContext_init(SDL_Context *sdlContext) {

    PIXELSMASKDEST_Context *pixelsMaskDestContext =
                                        malloc(sizeof(PIXELSMASKDEST_Context));
    if (!pixelsMaskDestContext) {
        fprintf(stderr, "Erreur allocation PIXELSMASKDEST_Context\n");
        return NULL;
    }

    int windowWidth, windowHeight;                                              
    SDL_GetRendererOutputSize(sdlContext->renderer,                             
                            &windowWidth, &windowHeight);      
    if (SDL_GetRendererOutputSize(sdlContext->renderer,
                                        &windowWidth, &windowHeight) != 0) {
        fprintf(stderr, "Erreur SDL_GetRendererOutputSize : %s\n",
                                                            SDL_GetError());
        free(pixelsMaskDestContext);
        return NULL;
    }

    pixelsMaskDestContext->widthDest = windowWidth;
    pixelsMaskDestContext->heightDest = windowHeight;
    pixelsMaskDestContext->maskDest = malloc(windowWidth * windowHeight
                                                        * sizeof(Uint8));
    if (!pixelsMaskDestContext->maskDest) {
      fprintf(stderr, "Erreur : allocation du tableau mask  échouée\n");
        free(pixelsMaskDestContext);
        return NULL;
    }

    for (int i = 0; i < windowWidth * windowHeight; i++) {
        pixelsMaskDestContext->maskDest[i] = 0;
    }

    return pixelsMaskDestContext;

}

void cleanupPixelsMaskDest(PIXELSMASKDEST_Context *pixelsMaskDestContext) {
    if (!pixelsMaskDestContext) return;

    if (pixelsMaskDestContext->maskDest) {
        free(pixelsMaskDestContext->maskDest);
    }
    free(pixelsMaskDestContext);
}
/*
PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext){

    cleanupPixels (pixelsContext);

    return pixelsContext_init(sdlContext);
}
*/
