#include <SDL2/SDL.h>
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void cropCircleNoMv (PIXELS_Context *pixelsContext) {

    unsigned short circlePosX = pixelsContext->pixelsWidth / 2;
    unsigned short circlePosY = pixelsContext->pixelsHeight / 2;

    for (Uint32 y = 0; y < pixelsContext->pixelsHeight; y++) {
        for (Uint32 x = 0; x < pixelsContext->pixelsWidth; x++) {

            Uint32 i = y * pixelsContext->pixelsWidth + x;

            Uint32 dx = x - circlePosX;
            Uint32 dy = y - circlePosY ;
            Uint32 dist2 = dx*dx + dy*dy;
            Uint32 pseudoAngle = (dx + dy) ; // approximation très simple
            
            if (((pseudoAngle + dist2 / 15) % 40) < 20) {
                pixelsContext->pixels[i] = 0xFFFFFFFF;
            } else {
                pixelsContext->pixels[i] = 0x00000000;
            }
        }
    }
}
