//
//  Paddle.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Paddle.hpp"

namespace Breakout {
    
    Paddle::Paddle(const int posX, const int posY, const int width, const int height){
        properties = new SDL_Rect{posX, posY, width, height};
        collider = new SDL_Rect{posX, posY, width, height};
        velocity = new Vector(0, 0);
    }
    
    Paddle::~Paddle(){
        
        delete velocity;
        velocity = nullptr;
        
        delete properties;
        properties = nullptr;
        
        delete collider;
        collider = nullptr;
    }
    
    void Paddle::update_position(const Window * win){
        
        properties->x += static_cast<int>(velocity->get_x());
        properties->y += static_cast<int>(velocity->get_y());
        
        // Making sure that the paddle can't move out of bounds
        if(properties->x < 0){
            properties->x = 0;
        } else if((properties->x + properties->w) > win->get_width()){
            properties->x = (win->get_width() - properties->w);
        }
        
        // updating collider position to match properties
        collider->x = properties->x;
        collider->y = properties->y;
        
        win->set_render_draw_color(color.color_red, color.color_green, color.color_blue, color.color_alpha);
        win->render_fill_rect(properties);
    }
    
    // it is important to understand that _speed is an integer, we should probably replace it with double
    void Paddle::calculate_velocity(const InputManager * input){
        if(input->get_flag_right()){
            properties->x += (1 * _speed);
        } else if(input->get_flag_left()){
            properties->x += (-1 * _speed);
        }
    }
}