#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void xOr (PIXELS_Context *pixelsContext) {

    for (int y = 0; y < pixelsContext->pixelsHeight; y++) {
        for (int x = 0; x < pixelsContext->pixelsWidth; x++) {
            int i = y * pixelsContext->pixelsWidth + x;
            if ((x  ^ y ) %  19 < 15 ){
                pixelsContext->pixels[i] = 0xFFFFFFFF;
            } else {
                pixelsContext->pixels[i] = 0x00000000;
              }
        }
    }
}
