#ifndef RENDERER_H
#define RENDERER_H

#include "sdl/sdl_init.h"
#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"

void renderTexture(TEXTURE_Context *textureContext,
                   SDL_Renderer *renderer,
                   PIXELS_Context *pixelsContext);

#endif
