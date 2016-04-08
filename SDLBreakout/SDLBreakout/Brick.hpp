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

#include <memory>
#include "Color.h"
#include "IRenderable.hpp"

namespace Breakout {
    class Brick : public IRenderable {
    public:
        Brick(int texture_id, int posX, int posY, int width = 20, int height = 10);
        ~Brick();
        
        void set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        
        void set_active(bool active){m_active = active;};
        
        void render_object(const Window * win, const InputManager * input = nullptr);
        
    private:
        bool m_active;
        Color m_color;
        SDL_Rect * m_collider;
        SDL_Rect * m_properties;
        int m_texture_id;
    };
}

#endif /* Brick_hpp */
