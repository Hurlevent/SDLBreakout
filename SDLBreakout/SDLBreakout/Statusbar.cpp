//
//  Statusbar.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Statusbar.hpp"

#include <sstream>

namespace Breakout {
    Statusbar::Statusbar(const SDL_Rect * viewport){
        m_viewport = viewport;
		m_color = {0x00, 0x00, 0x00};
        
        auto number_of_items = &m_health - &m_score + 1;
        auto width = viewport->w / (number_of_items * 2);
        
        for(struct texture_info * i = &m_score; i <= &m_health; i++){
            i->properties.x = static_cast<int>((i-&m_score)*width * 2);
            i->properties.y = 0;
            i->properties.w = static_cast<int>(width);
            i->properties.h = viewport->h;
			
			i->texture_id = SCORE + (i - &m_score);

			i->value_props.x = (static_cast<int>(i - &m_score) + 1)*width;
			i->value_props.y = 0;
			i->value_props.w = static_cast<int>(width);
			i->value_props.h = viewport->h;
        }

		m_score.text = "Score: ";
		m_health.text = "Health: ";
		m_fps.text = "FPS: ";
		m_speed.text = "Speed: ";
    }
    
    Statusbar::~Statusbar(){
    
    }
    
	template <typename T>
	std::string to_string_with_precition(const T value, const int n = 2)
	{
		std::stringstream out;
		out << std::setprecision(n) << value;
		return out.str();
	}

    void Statusbar::render_object(const Window * win, const InputManager * input){
		auto fps = win->get_fps();
		m_fps.value = std::to_string(fps);
		std::cout << "FPS: " << fps << ", FPSText:" << m_fps.text << ", FPSvalue: " << m_fps.value << std::endl;
        /*for(auto i = &m_score; i <= &m_health; i++)
        {
			win->update_font_texture_text(i->texture_id, i->text, m_color);
			win->render_font_texture(i->texture_id, &i->properties, &i->properties);
        }*/
		//win->update_font_texture_text(m_score.texture_id, m_score.text, m_color);
		//win->render_font_texture(m_score.texture_id, &m_score.properties, &m_score.properties);
		win->update_font_texture_text(m_speed.texture_id, m_speed.text, m_color);
		win->render_font_texture(m_speed.texture_id, &m_speed.properties, &m_speed.properties);
		win->update_font_texture_text(m_fps.texture_id, m_fps.text, m_color);
		win->render_font_texture(m_fps.texture_id, &m_fps.properties);
		win->update_font_texture_text(m_health.texture_id, m_health.text, m_color);
		win->render_font_texture(m_health.texture_id, &m_health.properties, &m_health.properties);

    }
}