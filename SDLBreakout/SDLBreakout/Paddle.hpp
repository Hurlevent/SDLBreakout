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
#elif __APPLE__
//#include <SDL2/SDL.h>
#endif

#include "IRenderable.hpp"
#include "Vector.hpp"
#include "InputManager.h"
#include "Sprites.h"
#include "Ball.h"

namespace Breakout {
    
    
    class Paddle : public GameObject {
    public:
        
        Paddle(Ball * ball, const int posX, const int posY, const int width = 100, const int height = 50);
        ~Paddle();
        
        void set_speed(const double speed){m_speed = speed;};
        
        void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;
        
        void set_colors(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha);

		void set_viewport(const SDL_Rect * viewport) { m_viewport = viewport; }
		
		

    private:
        SDL_Rect * properties;
        SDL_Rect * collider;
        Vector * velocity; // paddle doesn't really need constant movement. I should remove this
        double m_speed;
        const SDL_Rect * m_viewport;
		Ball * m_ball;
		bool CheckBallCollision();
		void handleBall();

    };
}

#endif /* Paddle_hpp */
