#include <stdint.h>
#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void effect_clear(PIXELS_Context *pixelsContext) {
    int total = pixelsContext->width * pixelsContext->height;

    for (int i = 0; i < total; i++) {
        pixelsContext->pixels[i] = (pixelsContext->a << 24)
                                | (pixelsContext->r << 16)
                                | (pixelsContext->g << 8) |
                                pixelsContext->b;
    }
}
