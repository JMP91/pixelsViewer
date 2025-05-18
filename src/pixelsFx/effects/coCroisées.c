#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"

void coCroisées (PIXELS_Context *pixelsContext) {

    for (int y = 0; y < pixelsContext->height; y++) {
        for (int x = 0; x < pixelsContext->width; x++) {
            int i = y * pixelsContext->width + x;
            //Coordonnées croisées
            if ((((x * x + y * x) % 128) < 64)) {
                pixelsContext->pixels[i]  = 0xFFFFFFFF;
            } else {
                pixelsContext->pixels[i] = 0x00000000;
            }
        }
    }
}
