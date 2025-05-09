#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>

void effect_test(PIXELS_Context *pixelsContext) {
    static uint32_t color = 0xffffffff;
    static int factor = 0;     // facteur d'éloignement
    static char sens = 1;

    // Mise à jour du facteur et de la couleur
    factor += sens;
    if (factor >= 145) {
        sens = -1;
        color = 0x00000000;
    } else if (factor <= 0) {
        sens = 1;
        color = 0xffffffff;
    }

    // Centre de l'écran
    int cx = pixelsContext->width / 2;
    int cy = pixelsContext->height / 2;

    // Taille du carré (20x20 pixels)
    int squareSize = 20;
    int halfSize = squareSize / 2;

    // Boucle sur chaque pixel du carré centré
    for (int y = -halfSize; y < halfSize; y++) {
        for (int x = -halfSize; x < halfSize; x++) {
            int nx = cx + x * factor;
            int ny = cy + y * factor;

            // Vérifie que le pixel est à l’intérieur de l’écran
            if (nx >= 0 && nx < pixelsContext->width &&
                ny >= 0 && ny < pixelsContext->height) {
                int index = ny * pixelsContext->width + nx;
                pixelsContext->pixels[index] = color;
            }
        }
    }
}

