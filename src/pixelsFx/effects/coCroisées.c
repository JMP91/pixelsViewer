#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>

void coCroisées (PIXELS_Context *pixelsContext) {

    for (int y = 0; y < pixelsContext->height; y++) {
        for (int x = 0; x < pixelsContext->width; x++) {
            int i = y * pixelsContext->width + x;
            //Coordonnées croisées
            if ((((x * x + y * x) % 128) < 64)) {
                pixelsContext->r = 255;
                pixelsContext->g = 255;
                pixelsContext->b = 255;
            } else {
                pixelsContext->r = 0;
                pixelsContext->g = 0;
                pixelsContext->b = 0;
            }
            pixelsContext->pixels[i] = (( pixelsContext->a & 0xFF) << 24)
                                     | (( pixelsContext->r & 0xFF) << 16)
                                     | (( pixelsContext->g & 0xFF) << 8)
                                     | ( pixelsContext->b & 0xFF);
        }
    }
}

