#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>

void cropCircleNoMv (PIXELS_Context *pixelsContext) {

    unsigned short circlePosX = pixelsContext->width / 2;
    unsigned short circlePosY = pixelsContext->height / 2;


    for (int y = 0; y < pixelsContext->height; y++) {
        for (int x = 0; x < pixelsContext->width; x++) {

            int i = y * pixelsContext->width + x;

            int dx = x - circlePosX;
            int dy = y - circlePosY ;
            int dist2 = dx*dx + dy*dy;
            int pseudoAngle = (dx + dy) ; // approximation très simple
            if (((pseudoAngle + dist2 / 15) % 40) < 20) {
                pixelsContext->r = 255;
                pixelsContext->g = 255;
                pixelsContext->b = 255;
            } else {
                pixelsContext->r = 0;
                pixelsContext->g = 0;
                pixelsContext->b = 0;
            }
            pixelsContext->pixels[i] = ((pixelsContext->a & 0xFF) << 24)
                                     | ((pixelsContext->r & 0xFF) << 16)
                                     | ((pixelsContext->g & 0xFF) << 8)
                                     | (pixelsContext->b & 0xFF);
        }
    }
}
