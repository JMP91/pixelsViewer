#include <stdio.h>
#include <stdlib.h>
#include "sdl/sdl_init.h"
#include "sdl/userKeyCommand.h"
#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "sdl/renderer.h"
#include "pixelsFx/pixelsTabFx_Choice.h"
#include "pixelsFx/tabChoice.h"
#include "pixelsFx/pixelsMask_init.h"

int main(void) {
    SDL_Context *sdlContext = initSDL(800, 800);
    if (!sdlContext) return -1;

    TEXTURE_Context *textureContext = texture_init(sdlContext); 
    if (!textureContext) return -1; 

    PIXELS_Context *pixelsContext = pixelsContext_init(sdlContext);
    if (!pixelsContext) return -1;

    PIXELSMASK_Context *pixelsMaskContext = pixelsMaskContext_init(sdlContext);
    if (!pixelsMaskContext) return -1;

    int lastFrameDisplay = SDL_GetTicks(); 
    int currentTime = 0;
    int elapsedTime = 0;    

    while (sdlContext->running) {

        userEvent (sdlContext);
        userKeyCommand (sdlContext, &textureContext, &pixelsContext);

        currentTime = SDL_GetTicks();
        elapsedTime = currentTime - lastFrameDisplay;

        if (elapsedTime >= 41) {        
        SDL_RenderClear(sdlContext->renderer);
        tabChoice(pixelsContext);
        renderTexture(textureContext, sdlContext->renderer, pixelsContext);
        SDL_RenderPresent(sdlContext->renderer);
        lastFrameDisplay = SDL_GetTicks();
        }   

        SDL_Delay (1);
    }

    cleanupPixelsMask(pixelsMaskContext);
    cleanupPixels(pixelsContext);
    cleanupTexture(textureContext);
    cleanupSDL(sdlContext);
    return 0;
}
