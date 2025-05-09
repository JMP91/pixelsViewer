#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>

void cropCircleNoMv (PIXELS_Context *pixelsContext) {

    unsigned short circlePosX = pixelsContext->width / 2;
    unsigned short circlePosY = pixelsContext->height / 2;

    unsigned char a = 255; // ne pas toucher en BM
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;

    for (int y = 0; y < pixelsContext->height; y++) {
        for (int x = 0; x < pixelsContext->width; x++) {

            int i = y * pixelsContext->width + x;

            int dx = x - circlePosX;
            int dy = y - circlePosY ;
            int dist2 = dx*dx + dy*dy;
            int pseudoAngle = (dx + dy) ; // approximation très simple
            if (((pseudoAngle + dist2 / 15) % 40) < 20) {
                r = 200; g = 200; b = 200;
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

