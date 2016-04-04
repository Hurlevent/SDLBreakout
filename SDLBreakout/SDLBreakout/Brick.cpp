//
//  Brick.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 01.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Brick.hpp"

namespace Breakout {
    Brick::Brick(const int posX, const int posY, const int width, const int height){
        properties = new SDL_Rect{posX, posY, width, height};
        collider = new SDL_Rect{posX, posY, width, height};
    }
    
    Brick::~Brick(){
        delete properties;
        properties = nullptr;
        
        delete collider;
        collider = nullptr;
    }
    
    void Brick::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
        color.color_red = r;
        color.color_green = g;
        color.color_blue = b;
        color.color_alpha = a;
    }
    
    void Brick::render_object(const Window * win, const InputManager * input){
        
        win->set_render_draw_color(color.color_red, color.color_green, color.color_blue, color.color_alpha);
        win->render_fill_rect(properties);
    }
    
}