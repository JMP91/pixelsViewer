#include "pixelsFx/pixelsFx.h"

void effect_clear(PIXELS_Context *pixelsContext) {

    int total = pixelsContext->
                                pixelsWidth * pixelsContext->pixelsHeight;

    for (int i = 0; i < total; i++) {
        pixelsContext->pixels[i] = 0x00000000; 
    }
}
