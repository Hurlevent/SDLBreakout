//
//  Brick.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 01.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Brick_hpp
#define Brick_hpp

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include "Color.h"
#include "IRenderable.hpp"

namespace Breakout {
    class Brick : public IRenderable {
    public:
        Brick(const int posX, const int posY, const int width = 20, const int height = 10);
        ~Brick();
        
        void set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        
        void set_active(bool active){_active = active;};
        
        void render_object(const Window * win, const InputManager * input = nullptr);
        
    private:
        bool _active;
        Color color;
        SDL_Rect * collider;
        SDL_Rect * properties;
    };
}

#endif /* Brick_hpp */
