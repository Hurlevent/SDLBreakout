#include "Menu.h"

namespace Breakout
{
	Menu::Menu(int window_width, int window_height, int number_of_buttons, int button_width, int button_height)
	{
		m_window_width = window_width;
		m_button_height = window_height;
		m_button_width = button_width;
		m_button_height = button_height;

		m_padding_y = 10;

		m_view = 0;

		for (int i = 0; i < number_of_buttons; i++)
		{
			m_texture_IDs.push_back(i);

			int x = (window_width - button_width) / 2;
			int y = (window_height - ((button_height + m_padding_y) * number_of_buttons * i)) / 2;
			
			m_buttons.push_back(std::make_unique<Button *>(new Button(m_texture_IDs[i], x, y, m_button_width, m_button_height)));
		}
	}


	Menu::~Menu()
	{
		for (std::vector<std::unique_ptr<Button *>>::iterator itr = m_buttons.begin(); itr != m_buttons.end(); itr++)
		{
			delete (*itr).release();
		}
	}

	void Menu::render_object(const Window* win, const InputManager* input)
	{
		for(std::vector<std::unique_ptr<Button *>>::iterator itr = m_buttons.begin(); itr != m_buttons.end(); itr++)
		{
			m_view = (**itr)->listen_to_click(win, input);
			(**itr)->render_object(win, input);
		}
	}

}
