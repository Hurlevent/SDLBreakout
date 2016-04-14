//
//  Statusbar.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Statusbar.hpp"

#include <sstream>
#include <boost/format.hpp>

namespace Breakout {
    Statusbar::Statusbar(const SDL_Rect * viewport){
        m_viewport = viewport;
		m_color = {0x00, 0x00, 0x00};
        
        auto number_of_items = &m_health - &m_score + 1;
        auto width = viewport->w / (number_of_items * 2);

        for(auto i = &m_score; i <= &m_health; i++){
            i->properties.x = static_cast<int>((i-&m_score)*width * 2);
            i->properties.y = 0;
            i->properties.w = static_cast<int>(width);
            i->properties.h = viewport->h;
			
			i->texture_id = SCORE + (i - &m_score) * 2;

			i->value_properties.x = i->properties.x + width;
			i->value_properties.y = 0;
			i->value_properties.w = static_cast<int>(width);
			i->value_properties.h = viewport->h;
        }

		m_score.text = "Score: ";
		m_health.text = "HP: ";
		m_fps.text = "FPS: ";
		m_time.text = "Time: ";
		m_score.value = std::to_string(1); // Test-verdi
		m_time.value = std::to_string(1); // Test-verdi
		m_health.value = std::to_string(3); // Test-verdi

    }
    
    Statusbar::~Statusbar(){
    
    }
    
	void Statusbar::to_string(std::string& str, double value)
	{
		int num_bytes = snprintf(&str[0], str.max_size(), "%.2f", value);
		if(num_bytes < str.max_size())
		{
			str.resize(num_bytes);
		}
	}


    void Statusbar::render_object(const Renderer * rend, const InputManager * input){
		auto fps = rend->get_fps();
		to_string(m_fps.value, fps);
		//std::cout << "FPS: " << fps << ", FPSText:" << m_fps.text << ", FPSvalue: " << m_fps.value << std::endl;
		
		for(auto i = &m_score; i <= &m_health; i++)
        {
			rend->update_font_texture_text(i->texture_id, i->text, m_color);
			rend->render_font_texture(i->texture_id, &i->properties);
			rend->update_font_texture_text(i->texture_id + 1, i->value, m_color);
			rend->render_font_texture(i->texture_id + 1, &i->value_properties);
        }
    }
}