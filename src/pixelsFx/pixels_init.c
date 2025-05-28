#include <stdio.h>
#include <stdlib.h>
#include "sdl/sdl_init.h"
#include "pixelsFx/pixels_init.h"

PIXELS_Context *pixelsContext_init(SDL_Context *sdlContext) {
    PIXELS_Context *pixelsContext = malloc(sizeof(PIXELS_Context));
    if (!pixelsContext) {
        fprintf(stderr, "Erreur allocation PIXELS_Context\n");
        return NULL;
    }

    int windowWidth, windowHeight;
    if (SDL_GetRendererOutputSize(sdlContext->renderer,
                                &windowWidth, &windowHeight) != 0) {
        fprintf(stderr, "Er SDL_GetRendererOutputSize : %s\n", SDL_GetError());
        free(pixelsContext);
        return NULL;
    }

    pixelsContext->pixelsWidth = windowWidth;
    pixelsContext->pixelsHeight = windowHeight;

    int total = windowWidth * windowHeight;

    pixelsContext->pixels = malloc(total * sizeof(Uint32));
    pixelsContext->stateMap = malloc(total * sizeof(Uint8));
    pixelsContext->maskDest = malloc(total * sizeof(Uint8));
    pixelsContext->maskSrc = malloc(total * sizeof(Uint8));

    if (!pixelsContext->pixels 
                        || !pixelsContext->stateMap 
                        || !pixelsContext->maskDest 
                        || !pixelsContext->maskSrc) {
        fprintf(stderr, "Erreur allocation des tableaux du contexte\n");
        cleanupPixels(pixelsContext); // free tout proprement
        return NULL;
    }

    for (int i = 0; i < total; i++) {
        pixelsContext->stateMap[i] = 0;
        pixelsContext->maskDest[i] = 0;
        pixelsContext->maskSrc[i] = 0;
    }

    return pixelsContext;
}

void cleanupPixels(PIXELS_Context *pixelsContext) {
    if (!pixelsContext) return;
    free(pixelsContext->pixels);
    free(pixelsContext->stateMap);
    free(pixelsContext->maskDest);
    free(pixelsContext->maskSrc);
    free(pixelsContext);
}

PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext){

    cleanupPixels (pixelsContext);

    return pixelsContext_init(sdlContext);
}
