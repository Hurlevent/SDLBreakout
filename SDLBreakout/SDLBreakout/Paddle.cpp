//
//  Paddle.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Paddle.hpp"
#include <iostream>
namespace Breakout {
    
    Paddle::Paddle(const int posX, const int posY, const int width, const int height){
        properties = new SDL_Rect{posX, posY, width, height};
        collider = new SDL_Rect{posX, posY, width, height};
        velocity = new Vector(0, 0);
        m_viewport = nullptr;
        texture_id = PURPLE_BRICK;
    }
    
    Paddle::~Paddle(){
        
       delete velocity;
        velocity = nullptr;
        
        delete properties;
        properties = nullptr;
        
        delete collider;
        collider = nullptr;
		
    }
    
    void Paddle::render_object(const Window * win, const InputManager * input){

		//Her varierer deltatime fra 1-3 tall, spørs helt hvordan frames er på din maskin.
		double deltatime = win->get_delta_time();
		
		std::cout << "Deltatime: " << deltatime << std::endl;
        
		if(input != nullptr){
            if(input->get_flag_right()){
                properties->x += static_cast<int>((deltatime/10 * m_speed));
            } else if(input->get_flag_left()){
                properties->x += static_cast<int>((deltatime/10 * -m_speed));
            }
        }
        
        // the paddle doesn't need constant movement, so the velocity member variable could be removed
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
        
		win->render_texture(texture_id, collider, m_viewport);
		
		//win->set_render_draw_color(color.color_red, color.color_green, color.color_blue, color.color_alpha);	
		//win->render_fill_rect(properties);
    }
    
    void Paddle::set_colors(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a){
        color.color_red = r;
        color.color_green = g;
        color.color_blue = b;
        color.color_alpha = a;
    }
}