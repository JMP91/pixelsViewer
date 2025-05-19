#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void cropCircleNoMv (PIXELS_Context *pixelsContext) {

    unsigned short circlePosX = pixelsContext->pixelsWidth / 2;
    unsigned short circlePosY = pixelsContext->pixelsHeight / 2;

    for (int y = 0; y < pixelsContext->pixelsHeight; y++) {
        for (int x = 0; x < pixelsContext->pixelsWidth; x++) {

            int i = y * pixelsContext->pixelsWidth + x;

            int dx = x - circlePosX;
            int dy = y - circlePosY ;
            int dist2 = dx*dx + dy*dy;
            int pseudoAngle = (dx + dy) ; // approximation très simple
            
            if (((pseudoAngle + dist2 / 15) % 40) < 20) {
                pixelsContext->pixels[i] = 0xFFFFFFFF;
            } else {
                pixelsContext->pixels[i] = 0x00000000;
            }
        }
    }
}
