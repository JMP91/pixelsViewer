#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsMask.h"


void pixelsMask_fillDest (PIXELS_Context *pixelsContext) {

    //cropCirecles    
    unsigned short circlePosX = pixelsContext->pixelsWidth / 2;                 
    unsigned short circlePosY = pixelsContext->pixelsHeight / 2;                
                                                                                
    for (int y = 0; y < pixelsContext->pixelsHeight; y++) {                     
        for (int x = 0; x < pixelsContext->pixelsWidth; x++) {                  
            int i = y * pixelsContext->pixelsWidth + x;                         
            int dx = x - circlePosX;                                            
            int dy = y - circlePosY ;                                           
            int dist2 = dx*dx + dy*dy;                                          
            int pseudoAngle = (dx + dy) ; // approximation très simple          
            if (((pseudoAngle + dist2 / 15) % 40) < 20) {                       
                pixelsContext->maskDest[i] = 1;                          
            } else {                                                            
                pixelsContext->maskDest[i] = 0;                          
            }                                                                   
        }                                                                       
    } 
}

int pixelsMask_countBlack(MASK_Context *maskContext,
                          PIXELS_Context *pixelsContext) {

    maskContext->nbrBlackPixelsDestCount = 0;    

    for (int i = 0; i < pixelsContext->total; i++) {
        if (pixelsContext->maskDest[i] == 0) {
            maskContext->nbrBlackPixelsDestCount++;
        }
    }
    return maskContext->nbrBlackPixelsDestCount;
}
