#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void effect_clear(PIXELS_Context *pixelsContext) {

    int total = pixelsContext->width * pixelsContext->height;

    for (int i = 0; i < total; i++) {
        pixelsContext->pixels[i] = 0x00000000; 
    }
}
