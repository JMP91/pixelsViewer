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
    SDL_GetRendererOutputSize(sdlContext->renderer,                             
                            &windowWidth, &windowHeight);      
    if (SDL_GetRendererOutputSize(sdlContext->renderer,
                                        &windowWidth, &windowHeight) != 0) {
        fprintf(stderr, "Erreur SDL_GetRendererOutputSize : %s\n",
                                                            SDL_GetError());
        free(pixelsContext);
        return NULL;
    }

    pixelsContext->width = windowWidth;
    pixelsContext->height = windowHeight;
    pixelsContext->pixels = malloc(windowWidth * windowHeight
                                                        * sizeof(uint32_t));
    if (!pixelsContext->pixels) {
      fprintf(stderr, "Erreur : allocation du tableau de pixels échouée\n");
        free(pixelsContext);
        return NULL;
    }
    pixelsContext->a = 255;
    pixelsContext->r = 0;
    pixelsContext->g = 0;
    pixelsContext->b = 0;

    return pixelsContext;
}

void cleanupPixels(PIXELS_Context *pixelsContext) {
    if (!pixelsContext) return;

    if (pixelsContext->pixels) {
        free(pixelsContext->pixels);
    }
    free(pixelsContext);
}

PIXELS_Context *pixelsContext_refresh (PIXELS_Context *pixelsContext,
                                                    SDL_Context *sdlContext){

    cleanupPixels (pixelsContext);

    return pixelsContext_init(sdlContext);
}


