#ifndef USERKEYCOMMAND_H
#define USERKEYCOMMAND_H

#include "sdl/sdl_init.h"
#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"

void userKeyCommand (SDL_Context *sdlContext, 
                    TEXTURE_Context **textureContext,
                    PIXELS_Context **pixelsContext); 
                    
#endif
