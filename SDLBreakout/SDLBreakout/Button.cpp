#include "Button.h"

namespace Breakout {
		Button::Button(int texture_id, int posX, int posY, int width, int height)
		{
			m_texture_id = texture_id;
			m_properties = {posX, posY, width, height};

			std::cout << "PROPS: " << m_properties.x << ", " << m_properties.y << ", " << m_properties.w << ", " << m_properties.h << std::endl;
		}

		int Button::listen_to_click(const Renderer * rend, const InputManager * input)
		{
			int clicked = 0;
			SDL_Point mouse_pos;
			input->get_mouse_position(mouse_pos);

			if (mouse_pos.x >= m_properties.x && mouse_pos.x <= m_properties.x + m_properties.w && mouse_pos.y >= m_properties.y && mouse_pos.y <= m_properties.y + m_properties.h) {
				rend->set_render_color_on_mouse(0, 250, 0, 0);
				if (input->handle_mouse_events() == true)
				{
					clicked = 1;
				}
			}
			else {
				rend->set_render_color_on_mouse(0, 0, 250, 0);
			}
			return clicked;
		}
		
		void Button::render_object(const Renderer * rend, const InputManager * input)
		{
			// std::cout << "Rendering Texture: " << m_texture_id << ", Rect: " << m_properties.x << ", " << m_properties.y << ", " << m_properties.w << ", " << m_properties.h << std::endl;
			rend->render_texture(m_texture_id, &m_properties, nullptr);
		}
}