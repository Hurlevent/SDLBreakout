#include "Button.h"

namespace Breakout {
		Button::Button(int texture_id, int posX, int posY, int width, int height)
		{
			m_texture_id = texture_id;
			m_properties = {posX, posY, width, height};

			std::cout << "PROPS: " << m_properties.x << ", " << m_properties.y << ", " << m_properties.w << ", " << m_properties.h << std::endl;
		}

		bool Button::listen_to_click(const Renderer * rend, const InputManager * input)
		{
			bool clicked = false;
			SDL_Point mouse_pos;
			input->get_mouse_position(mouse_pos);

			if (mouse_pos.x >= m_properties.x && mouse_pos.x <= m_properties.x + m_properties.w && mouse_pos.y >= m_properties.y && mouse_pos.y <= m_properties.y + m_properties.h) {
				rend->set_render_color_on_mouse(0, 250, 0, 0);
				if (input->handle_mouse_events() == true)
				{
					clicked = true;
				}
			}
			else {
				rend->set_render_color_on_mouse(0, 0, 250, 0);
			}
			return clicked;
		}
		
		void Button::render_object(const Renderer * rend, const InputManager * input, const Timer * timer)
		{
			rend->update_font_texture_text(m_texture_id, text.c_str(), SDL_Color{ 0,0,0 });
			rend->render_font_texture(m_texture_id, &m_properties, nullptr);
		}
}