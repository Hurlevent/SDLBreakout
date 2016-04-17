//
//  Color.h
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 01.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Color_h
#define Color_h

// This struct not being used for anything. We have discovered that SDL_Color makes this struct obsolete. (Default color: Red)
typedef struct {
    uint8_t color_red = 0xFF;
    uint8_t color_green = 0x00;
    uint8_t color_blue = 0x00;
    uint8_t color_alpha = 0xFF;
} Color;

#endif /* Color_h */
