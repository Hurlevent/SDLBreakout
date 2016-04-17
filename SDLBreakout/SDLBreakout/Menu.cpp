#include "Menu.h"

namespace Breakout
{
	Menu::Menu(int window_width, int window_height, int number_of_buttons, int button_width, int button_height)
	{
		m_window_width = window_width;
		m_window_height = window_height;
		m_button_width = button_width;
		m_button_height = button_height;

		m_padding_y = 10;
		m_title_h = 50;
		m_number_of_buttons = number_of_buttons;
		m_view = 0;

		for (int i = 0; i < number_of_buttons; i++)
		{
			m_texture_IDs.push_back(START + i);

			int x = (window_width - button_width) / 2;
			int y = (window_height - ((button_height + m_padding_y) * number_of_buttons * i) - m_title_h ) / 2;
			
			m_buttons.push_back(std::make_unique<Button *>(new Button(m_texture_IDs[i], x, y, m_button_width, m_button_height)));
		}
		(*m_buttons[0])->text = "Exit";
		(*m_buttons[1])->text = "Start";
	}


	Menu::~Menu()
	{
		for (std::vector<std::unique_ptr<Button *>>::iterator itr = m_buttons.begin(); itr != m_buttons.end(); ++itr)
		{
			delete (*itr).release();
		}
	}

	void Menu::render_object(const Renderer * rend, const InputManager * input, const Timer * timer)
	{
		bool pressedStart = false;
		for(std::vector<std::unique_ptr<Button *>>::iterator itr = m_buttons.begin(); itr != m_buttons.end(); ++itr)
		{
			
			pressedStart = (**itr)->listen_to_click(rend, input);

			(**itr)->render_object(rend, input);
		}
		if (pressedStart == true) {
			m_view = 1;
		}
		rend->update_font_texture_text(BREAKOUT, "Breakout", SDL_Color{ 0,0,0 });
		SDL_Rect clip = SDL_Rect{ m_window_width / 3, m_padding_y, m_window_width / 3, m_title_h };
		rend->render_font_texture(BREAKOUT, &clip);
	}

}
