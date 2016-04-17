//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Paddle_hpp
#define Paddle_hpp

#include "IRenderable.hpp"
#include "Vector.hpp"
#include "InputManager.h"
#include "Sprites.h"
#include "Ball.h"
#include "SoundMix.h"
#include <iostream>

namespace Breakout {
    
    
    class Paddle : public GameObject {
    public:
        
        Paddle(Ball * ball, const int posX, const int posY, const int width = 100, const int height = 50);
        ~Paddle();
        
        void set_speed(const double speed){m_speed = speed;};
		void set_colors(const uint8_t red, const uint8_t green, const uint8_t blue, const uint8_t alpha);
		void set_viewport(const SDL_Rect * viewport) { m_viewport = viewport; }

        void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;
 
    private:
        SDL_Rect * properties;
        SDL_Rect * collider; 
		const SDL_Rect * m_viewport;
		SoundMix sound;
        
		Vector * velocity; // paddle doesn't really need constant movement. I should remove this
		Ball * m_ball;
		double m_speed;
   
		bool CheckBallCollision();
		void handleBall();
    };
}

#endif /* Paddle_hpp */
