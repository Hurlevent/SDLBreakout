//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Statusbar_hpp
#define Statusbar_hpp

#include <string>
#include <iomanip>
#include "GameObject.h"
#include "PlayerStats.h"

namespace Breakout {
    
    struct texture_info{
        int texture_id;

		std::string text;
		std::string value;

        SDL_Rect properties;
		SDL_Rect value_properties;
    };
    
    class Statusbar : public GameObject {
    public:
        Statusbar(const SDL_Rect * viewport);
        ~Statusbar();
        
        void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr)override;
        
        void set_viewport(const SDL_Rect * viewport){m_viewport = viewport;};
        
    private:
		SDL_Color m_color;
        const SDL_Rect * m_viewport;

        struct texture_info m_score;
        struct texture_info m_time;
        struct texture_info m_fps;
        struct texture_info m_health;

		void to_string(std::string & str, double value);
    };
}

#endif /* Statusbar_hpp */
