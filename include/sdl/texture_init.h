#ifndef TEXTURE_INIT 
#define TEXTURE_INIT 

#include <sdl_init.h>

typedef struct TEXTURE_Context {
    SDL_Texture *fx_TxStr;
    int width;
    int height;
} TEXTURE_Context;

TEXTURE_Context *texture_init (SDL_Context *sdlContext);

void cleanupTexture (TEXTURE_Context *textureContext);

TEXTURE_Context *texture_refresh (SDL_Context *sdlContext, 
                                    TEXTURE_Context *textureContext); 

#endif

