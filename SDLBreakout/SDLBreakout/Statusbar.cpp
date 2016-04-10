//
//  Statusbar.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Statusbar.hpp"

namespace Breakout {
    Statusbar::Statusbar(const SDL_Rect * viewport){
        m_viewport = viewport;
        
        auto number_of_items = &m_health - &m_score;
        auto width = viewport->w / number_of_items;
        
        for(struct texture_info * i = &m_score; i <= &m_health; i++){
            i->properties.x = static_cast<int>((i-&m_score)*width);
            i->properties.y = 0;
            i->properties.w = static_cast<int>(width);
            i->properties.h = viewport->h;
        }
    }
    
    Statusbar::~Statusbar(){
    
    }
    
    void Statusbar::render_object(const Window * win, const InputManager * input){
        
    }
}