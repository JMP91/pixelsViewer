#include <stdio.h>
#include <stdbool.h>
#include "sdl/sdl_init.h"
#include "sdl/texture_init.h"
#include "sdl/userKeyCommand.h"
#include "pixelsFx/pixels_init.h"
#include "pixelsFx/pixelsFx.h"
#include "pixelsFx/tabChoice.h"

void userKeyCommand (SDL_Context *sdlContext, 
                     TEXTURE_Context **textureContext,
                     PIXELS_Context **pixelsContext) { 

    switch (sdlContext->userEvent.type) {
        case SDL_KEYDOWN:
            switch (sdlContext->userEvent.key.keysym.sym) {
                case SDLK_a:
                    tabChoice = xOr;
                    break;
                case SDLK_z:
                    tabChoice = coCroisées;
                    break;
                case SDLK_e:
                    tabChoice = cropCircleNoMv;
                    break;
                case SDLK_r:
                    tabChoice = neige;
                    break;

                case SDLK_SPACE:
                    tabChoice = effect_clear;
                    break;
                    case SDLK_p:
                    break;
					case SDLK_f:
                        if (sdlContext->fullScreen == false) {
                           SDL_SetWindowFullscreen(sdlContext->window, 
                                   SDL_WINDOW_FULLSCREEN_DESKTOP);
                           SDL_ShowCursor(SDL_DISABLE);
                           *textureContext = 
                               texture_refresh (sdlContext, *textureContext);
                           *pixelsContext = 
                               pixelsContext_refresh(*pixelsContext, sdlContext);
                        }
                        else {
                            SDL_SetWindowFullscreen(sdlContext->window, 0);
                            SDL_ShowCursor(SDL_ENABLE);
                           *textureContext = 
                               texture_refresh (sdlContext, *textureContext);
                           *pixelsContext = 
                               pixelsContext_refresh(*pixelsContext, sdlContext);
                        }
                	sdlContext->fullScreen = !sdlContext->fullScreen;
                	break;
                default:
                    break;
            }
            break; // Sortir du switch SDL_KEYDOWN
        }
}
