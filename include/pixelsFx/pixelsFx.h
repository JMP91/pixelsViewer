#ifndef PIXELSFX_H
#define PIXELSFX_H

#include <stdint.h>
#include "pixelsFx/pixels_init.h"
#include "sdl/texture_init.h"


void effect_clear(PIXELS_Context *pixelsContext);
void coCroisées (PIXELS_Context *pixelsContext);
void cropCircleNoMv (PIXELS_Context *pixelsContext);
void neige (PIXELS_Context *pixelsContext);
void xOr (PIXELS_Context *pixelsContext);
void effect_test(PIXELS_Context *pixelsContext);

#endif

