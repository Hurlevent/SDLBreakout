//
//  Paddle.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// This class represents the paddle which the player is controlling.

#ifndef Paddle_hpp
#define Paddle_hpp

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include "IRenderable.hpp"
#include "Vector.hpp"
#include "InputManager.h"
#include "Color.h"

namespace Breakout {
    
    
    class Paddle : public IRenderable {
    public:
        
        Paddle(const int posX, const int posY, const int width = 100, const int height = 50);
        ~Paddle();
        
        void set_speed(const double speed){_speed = speed;};
        
        void render_object(const Window * win, const InputManager * input = nullptr);
        
        void set_colors(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha);

    private:
        Color color;
        SDL_Rect * properties;
        SDL_Rect * collider;
        Vector * velocity; // paddle doesn't really need constant movement. I should remove this
        double _speed;
    };
}

#endif /* Paddle_hpp */