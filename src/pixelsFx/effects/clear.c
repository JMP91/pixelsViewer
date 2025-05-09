#include <stdint.h>
#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void effect_clear(PIXELS_Context *pixelsContext) {
    int total = pixelsContext->width * pixelsContext->height;

    uint8_t a = 255; // ne pas toucher en BM
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;

    for (int i = 0; i < total; i++) {
        pixelsContext->pixels[i] = (a << 24) | (r << 16) | (g << 8) | b;
    }
}
