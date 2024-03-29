//
//  BrickContainer.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// The purpose of this class is to "hide" all bricks in a single object. This enables us to treat all the bricks as a single game object
// Because in Breakout, levels are often defined by the layout of the bricks, you could consider this class to be the level in our game. 


#ifndef BrickContainer_hpp
#define BrickContainer_hpp

#include "IRenderable.hpp"
#include "Brick.hpp"
#include <memory>
#include "Sprites.h"
#include <iterator>
#include "PlayerStats.h"
#include "SoundMix.h"

namespace Breakout {

    class BrickContainer : public GameObject{
    public:
        BrickContainer(Ball *ball,int window_width, int window_height, int rows = 3, int colums = 5, int brick_height = 10);
        ~BrickContainer();
        
        void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;

		void set_viewport(const SDL_Rect * viewport);
        
		bool NoBricks() { return NoBricksLeft; };
	
		void resetBricks();
    private:
        int m_window_width;
        int m_window_height;
        
        int m_brick_columns;
        int m_brick_rows;
        int m_brick_height;
		bool NoBricksLeft;


		Ball *m_ball;
		SoundMix Sound;

        std::vector<int> m_texture_IDs;
        std::vector<std::unique_ptr<Brick>> m_bricks;

		void handle_collision();
		bool check_ball_hit_brick(int ballX, int ballY, SDL_Rect *rectBrick);
		void delete_block_on_hit(Brick *brick);
    };
}


#endif /* BrickContainer_hpp */
