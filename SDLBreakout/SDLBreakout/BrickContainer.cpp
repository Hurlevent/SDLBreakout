//
//  BrickContainer.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "BrickContainer.hpp"


namespace Breakout {
    BrickContainer::BrickContainer(int window_width, int window_height, int rows, int columns, int brick_height){
        
        m_texture_IDs.push_back(BLUE_BRICK);
        m_texture_IDs.push_back(GREEN_BRICK);
        m_texture_IDs.push_back(CYAN_BRICK);
        
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
            
            int texture_id = m_texture_IDs[(i / m_brick_columns) % m_texture_IDs.size()];
            
            m_bricks.push_back(std::unique_ptr<Brick>(new Brick(texture_id, x, y, w, h)));
        }
    }
    
    BrickContainer::~BrickContainer(){
        for(std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); ++iter){
            delete iter->release(); // I have no idea if this is the proper way to free memory,
            //maybe even the smart-pointer will do the job for us.
        }
    }
    // render all bricks
    void BrickContainer::render_object(const Renderer * rend, const InputManager * input, const Timer * timer){
       for(std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); ++iter){
           (*iter)->render_object(rend);
       }
    }

	void BrickContainer::set_viewport(const SDL_Rect* viewport)
	{
		for (std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); ++iter)
		{
			(*iter)->set_viewport(viewport);
		}
	}

    
    void BrickContainer::handle_collision(){
        // if the ball collides with a brick, this function could maybe be usefull. Will change a lot when we implement the ball
    }
}