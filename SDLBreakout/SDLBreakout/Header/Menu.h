//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright � 2016 SDLBreakout. All rights reserved.
//

#ifndef Menu_h
#define Menu_h

#include <vector>
#include <memory>
#include "Button.h"
#include "IRenderable.hpp"
#include "Sprites.h"

namespace Breakout {

	// This class decides how our menu will look and behave.
	class Menu : public IRenderable
	{
	public:
		Menu(int window_width, int window_height, int number_of_buttons, int button_width = 100, int button_height = 20);
		~Menu();

		void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;
		void set_view(int view) { m_view = view; }
		int get_view() { return m_view;};
		
	private:
		int m_window_width;
		int m_window_height;
		int m_button_width;
		int m_button_height;
		int m_padding_y;

		int m_number_of_buttons;
		int m_title_h;
		
		int m_view; // This is a temp variable that will be replaced

		std::vector<int> m_texture_IDs;
		std::vector<std::unique_ptr<Button *>> m_buttons;
	};
}

#endif
