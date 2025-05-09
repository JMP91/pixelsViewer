#include "sdl/sdl_init.h"
#include "sdl/texture_init.h"

TEXTURE_Context *texture_init (SDL_Context *sdlContext) {

    TEXTURE_Context *textureContext = malloc (sizeof(TEXTURE_Context));
    if (!textureContext) {
        fprintf(stderr, " allocation impossible\n");
        return NULL;
    }
 
    int windowWidth, windowHeight;                                              
    SDL_GetRendererOutputSize(sdlContext->renderer,                             
                            &windowWidth, &windowHeight);      

    textureContext->width = windowWidth;
    textureContext->height = windowHeight;
   
    textureContext->fx_TxStr = SDL_CreateTexture (sdlContext->renderer,
                                               SDL_PIXELFORMAT_ARGB8888,
                                               SDL_TEXTUREACCESS_STREAMING,
                                               textureContext->width,
                                               textureContext->height); 
    if (!textureContext->fx_TxStr) {
      fprintf(stderr,"sdl:could not create texture : %s\n", SDL_GetError());
      free(textureContext);
      return NULL;
    }
   
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    
    return textureContext;
}

void cleanupTexture (TEXTURE_Context *textureContext) {
    if (textureContext) {
       if (textureContext->fx_TxStr) {
          SDL_DestroyTexture (textureContext->fx_TxStr);
       }
    } 
    free (textureContext); 
}

TEXTURE_Context *texture_refresh(SDL_Context *sdlContext, 
                                            TEXTURE_Context *textureContext) {
    if (!textureContext || !sdlContext) return NULL;

    cleanupTexture(textureContext);

    return texture_init(sdlContext);
}


