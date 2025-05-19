#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void coCroisées (PIXELS_Context *pixelsContext) {

    for (int y = 0; y < pixelsContext->pixelsHeight; y++) {
        for (int x = 0; x < pixelsContext->pixelsWidth; x++) {
            int i = y * pixelsContext->pixelsWidth + x;
            //Coordonnées croisées
            if ((((x * x + y * x) % 128) < 64)) {
                pixelsContext->pixels[i]  = 0xFFFFFFFF;
            } else {
                pixelsContext->pixels[i] = 0x00000000;
            }
        }
    }
}
