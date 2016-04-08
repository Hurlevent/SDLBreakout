//
//  BrickContainer.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "BrickContainer.hpp"


namespace Breakout {
    BrickContainer::BrickContainer(const std::vector<SDL_Texture *> textures, int window_width, int window_height, int rows, int columns, int brick_height){
        m_textures = textures;
        m_brick_rows = rows;
        m_brick_columns = columns;
        m_brick_height = brick_height;
        m_window_width = window_width;
        m_window_height = window_height;
        
        for(int i = 0; i < (m_brick_rows * m_brick_columns); i++){
            int x = (m_window_width / m_brick_columns) * (i % m_brick_columns);
            int y = m_brick_height * (i / m_brick_columns);
            int w = m_window_width / m_brick_columns;
            int h = m_brick_height;
            
            m_bricks.push_back(std::unique_ptr<Brick>(new Brick(x, y, w, h)));
        }
    }
    
    BrickContainer::~BrickContainer(){
        for(std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); iter++){
            delete iter->release(); // I have no idea if this is the proper way to free memory,
            //maybe even the smart-pointer will do the job for us.
        }
    }
    // render all bricks
    void BrickContainer::render_object(const Breakout::Window * win, const Breakout::InputManager * input){
       for(std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); iter++){
           (*iter)->render_object(win);
       }
    }
    
    void BrickContainer::handle_collision(){
        // if the ball collides with a brick, this function could maybe be usefull. Will change a lot when we implement the ball
    }
}