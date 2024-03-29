//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright � 2016 SDLBreakout. All rights reserved.
//

#ifndef Button_h
#define Button_h

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Window.hpp"
#include "IRenderable.hpp"
#include "Sprites.h"
#include <string>

// This class represents a clickable button and is used by our menu. (Our menu contains an std::vector of buttons)

namespace Breakout {
	class Button : public IRenderable {

	public:
		Button(int texture_id, int posX, int posY, int width = 100, int height = 20);

		bool listen_to_click(const Renderer * rend, const InputManager * input);
		void render_object(const Renderer * rend, const InputManager * input, const Timer * timer = nullptr);

		std::string text;
	private:

		int m_texture_id;
		SDL_Rect m_properties;
	};
}
#endif 

