#include <stdint.h>
#include "sdl/renderer.h"
#include "sdl/texture_init.h"
#include "pixelsFx/pixels_init.h"

void renderTexture(TEXTURE_Context *textureContext,
                   SDL_Renderer *renderer,
                   PIXELS_Context *pixelsContext) {
                              SDL_UpdateTexture(textureContext->fx_TxStr,
                              NULL,
                              pixelsContext->pixels,
                              textureContext->width * sizeof(uint32_t));

    SDL_RenderCopy(renderer, textureContext->fx_TxStr, NULL, NULL);
}
