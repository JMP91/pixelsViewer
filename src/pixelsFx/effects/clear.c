#include <SDL2/SDL.h>
#include "pixelsFx/pixelsFx.h"

void effect_clear(PIXELS_Context *pixelsContext) {

    Uint32 total = pixelsContext->
                                pixelsWidth * pixelsContext->pixelsHeight;

    for (Uint32 i = 0; i < total; i++) {
        pixelsContext->pixels[i] = 0xFFFFFFFF; 
    }
}
