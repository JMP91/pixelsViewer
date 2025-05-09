#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "core/utils.h"
#include <stdio.h>


void circleMv (PIXELS_Context *pixelsContext) {

    unsigned short circlePosX = pixelsContext->width / 2;
    unsigned short circlePosY = pixelsContext->height / 2;

    static short sens = 1; 
    static unsigned short circleRayon = 1; 
    if (circleRayon >= 200) sens = -1;
    if (circleRayon <= 10) sens = 1; 
    circleRayon += sens * 4;

    unsigned char a = 255; // ne pas utiliser  en BM
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
    
    for (int y = 0; y < pixelsContext->height; y++) {
        for (int x = 0; x < pixelsContext->width; x++) {
            int i = y * pixelsContext->width + x;
            if (((x - circlePosX)*(x - circlePosX)
                                    + (y - circlePosY)
                                    *(y - circlePosY)
                                    < circleRayon*circleRayon)){
                                            r = 255; g = 255; b = 255;}
            else {r = 0; g = 0; b = 0;}
            pixelsContext->pixels[i] = ((a & 0xFF) << 24)
                                 | ((r & 0xFF) << 16)
                                 | ((g & 0xFF) << 8)
                                 | (b & 0xFF);
        }
    }   
}
