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
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <memory>
#include "Color.h"
#include "GameObject.h"
#include "IRenderable.hpp"
#include "Ball.h"

// This class represents a brick in Breakout. When the ball hits a brick, the brick will disappear. 

namespace Breakout {
    class Brick : public GameObject{
    public:
        Brick(int texture_id, int posX, int posY, int width = 20, int height = 10);
        ~Brick();
        
        void set_color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        void set_active(bool active){m_active = active;};        
		void set_viewport(const SDL_Rect * viewport) { m_viewport = viewport; }
		void SetDestroy();
		
		SDL_Rect *GetCollider() { return m_collider; };
		
		void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;

		bool m_active;

    private:

        SDL_Rect * m_collider;
        SDL_Rect * m_properties;
        const SDL_Rect * m_viewport;
    };
}

#endif /* Brick_hpp */
