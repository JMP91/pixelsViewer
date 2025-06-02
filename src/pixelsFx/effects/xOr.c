#include <SDL2/SDL.h>
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void xOr (PIXELS_Context *pixelsContext) {

    for (Uint32 y = 0; y < pixelsContext->pixelsHeight; y++) {
        for (Uint32 x = 0; x < pixelsContext->pixelsWidth; x++) {
            Uint32 i = y * pixelsContext->pixelsWidth + x;
            if ((x  ^ y ) %  19 < 15 ){
                pixelsContext->pixels[i] = 0xFFFFFFFF;
            } else {
                pixelsContext->pixels[i] = 0x00000000;
              }
        }
    }
}
