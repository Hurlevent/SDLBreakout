//
//  Statusbar.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Statusbar_hpp
#define Statusbar_hpp

#include "IViewport.h"
#include "IRenderable.hpp"

namespace Breakout {
    
    struct texture_info{
        int texture_id;
        SDL_Rect properties;
    };
    
    class Statusbar : public IViewport, public IRenderable {
    public:
        Statusbar(const SDL_Rect * viewport);
        ~Statusbar();
        
        void render_object(const Window * win, const InputManager * input = nullptr);
        
        void set_viewport(const SDL_Rect * viewport){m_viewport = viewport;};
        
    private:
        const SDL_Rect * m_viewport;
        struct texture_info m_score;
        struct texture_info m_speed;
        struct texture_info m_sound;
        struct texture_info m_health;
    };
}

#endif /* Statusbar_hpp */
