#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>

void freeSquare (PIXELS_Context *pixelsContext) {

    static int color = 0xffffffff;
    int cx = 409; // centre du carré en x
    int cy = 409; // centre du carré en y
    static int factor = 0; // facteur d'éloignement
    static char sens = 1;
    factor += sens;
    if (factor >= 145){
        sens = -1;
        color = 0x00000000;
    }
    else if (factor <= 0) {
        sens = 1;
        color = 0xffffffff;
    }
    // Parcourt les 100 pixels du carré d'origine
    for (int y = 400; y <= 419; y++) {
        for (int x = 400; x <= 419; x++) {
            int dx = x - cx;
            int dy = y - cy;
            int nx = cx + dx * factor;
            int ny = cy + dy * factor;
            // Vérifie que le pixel déplacé reste dans l'écran
            if (nx >= 0 && nx < pixelsContext->width &&
                ny >= 0 && ny < pixelsContext->height) {
                int index = ny * pixelsContext->width + nx;
                pixelsContext->pixels[index] = color; 
            }
        }
    }
}
