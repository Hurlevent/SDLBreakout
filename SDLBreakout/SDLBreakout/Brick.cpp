//
//  Brick.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 01.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Brick.hpp"

namespace Breakout {
    Brick::Brick(const int texture_id, int posX, int posY, int width, int height){
        m_properties = new SDL_Rect{posX, posY, width, height};
        m_collider = new SDL_Rect{posX, posY, width, height};
        m_active = true;
        m_texture_id = texture_id;
        m_viewport = nullptr;
    }
    
    Brick::~Brick(){
        delete m_properties;
        m_properties = nullptr;
        
        delete m_collider;
        m_collider = nullptr;
    }
    
    void Brick::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
        m_color.color_red = r;
        m_color.color_green = g;
        m_color.color_blue = b;
        m_color.color_alpha = a;
    }
    
    void Brick::render_object(const Window * win, const InputManager * input){
        if(m_active){
            /*
            win->set_render_draw_color(color.color_red, color.color_green, color.color_blue, color.color_alpha);
            win->render_fill_rect(properties);
            */
            win->render_texture(m_texture_id, m_collider, m_viewport);
        }
    }
    
}