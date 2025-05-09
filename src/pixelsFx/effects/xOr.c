#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>

void xOr (PIXELS_Context *pixelsContext) {

    unsigned char a = 255;
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    static unsigned char offset = 0;
    static char sens = 1;
    offset += sens;
    if (offset >= 255) {
        sens = -1;
    } else if (offset <= 0) {
        sens = 1;
    }
    for (int y = 0; y < pixelsContext->height; y++) {
        for (int x = 0; x < pixelsContext->width; x++) {
            int i = y * pixelsContext->width + x;

            if ((((x + (offset + sens)) ^ (y + (offset + sens))) %  19) < 15) {
                r = 255; g = 255; b = 255;
            } else {
                r = 0; g = 0; b = 0;
              }
            pixelsContext->pixels[i] = ((a & 0xFF) << 24)
                                     | ((r & 0xFF) << 16)
                                     | ((g & 0xFF) << 8)
                                     | (b & 0xFF);
        }
    }
}

