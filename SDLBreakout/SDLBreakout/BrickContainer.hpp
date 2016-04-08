//
//  BrickContainer.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// the purpose of this class is to enable us treat all bricks as a single game_object


#ifndef BrickContainer_hpp
#define BrickContainer_hpp

#include "IRenderable.hpp"
#include "Brick.hpp"
#include <memory>
#include "Sprites.h"

namespace Breakout {
    class BrickContainer : public IRenderable{
    public:
        BrickContainer(int window_width, int window_height, int rows = 3, int colums = 5, int brick_height = 10);
        ~BrickContainer();
        
        void render_object(const Window * win, const InputManager * input = nullptr);
        
        void handle_collision();
        
    private:
        int m_window_width;
        int m_window_height;
        
        int m_brick_columns;
        int m_brick_rows;
        int m_brick_height;
        
        std::vector<int> m_texture_IDs;
        std::vector<std::unique_ptr<Brick>> m_bricks;
    };
}


#endif /* BrickContainer_hpp */
