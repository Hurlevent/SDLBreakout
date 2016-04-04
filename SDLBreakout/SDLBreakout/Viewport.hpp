//
//  Viewport.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 02.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// Hmm, i might revisit this class in the future, when we begin with real sprites

#ifndef Viewport_hpp
#define Viewport_hpp

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

namespace Breakout {
    class Viewport{
    public:
        Viewport();
        ~Viewport();
    private:
        SDL_Rect properties;
    };
}

#endif /* Viewport_hpp */
