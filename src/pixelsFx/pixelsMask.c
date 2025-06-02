#include <SDL2/SDL.h>
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsMask.h"


void pixelsMask_fillDest (PIXELS_Context *pixelsContext) {

    //cropCirecles    
    unsigned short circlePosX = pixelsContext->pixelsWidth / 2;                 
    unsigned short circlePosY = pixelsContext->pixelsHeight / 2;                
                                                                                
    for (Uint32 y = 0; y < pixelsContext->pixelsHeight; y++) {
        for (Uint32 x = 0; x < pixelsContext->pixelsWidth; x++) {
            Uint32 i = y * pixelsContext->pixelsWidth + x;              
            Uint32 dx = x - circlePosX;
            Uint32 dy = y - circlePosY;
            Uint32 dist2 = dx*dx + dy*dy;
            Uint32 pseudoAngle = (dx + dy) ; // approximation très simple
            if (((pseudoAngle + dist2 / 15) % 40) < 20) {                       
                pixelsContext->maskDest[i] = 1;                          
            } else {                                                            
                pixelsContext->maskDest[i] = 0;                          
            }                                                                   
        }                                                                       
    } 
}

Uint32 pixelsMask_countBlack(MASK_Context *maskContext,
                          PIXELS_Context *pixelsContext) {

    maskContext->nbrBlackPixelsDestCount = 0;    

    for (Uint32 i = 0; i < pixelsContext->total; i++) {
        if (pixelsContext->maskDest[i] == 0) {
            maskContext->nbrBlackPixelsDestCount++;
        }
    }
    return maskContext->nbrBlackPixelsDestCount;
}

void pixelsMask_fillBlackDestIndices (MASK_Context *maskContext,
                                        PIXELS_Context *pixelsContext) {

    maskContext->blackDestIndices = malloc(maskContext->nbrBlackPixelsDestCount
                                                            * sizeof (Uint32));
    if (!maskContext->blackDestIndices) {
        fprintf(stderr,"er blackDestIndices\n"); 
        return; 
    }        

    Uint32 c = 0;

    for (Uint32 i = 0; i < pixelsContext->total; i++) {
        if(pixelsContext->maskDest[i] == 0 ) {
            maskContext->blackDestIndices[c++] = i;
        }
    }
}
