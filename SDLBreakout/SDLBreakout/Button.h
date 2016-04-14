#ifndef Button_h
#define Button_h

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Window.hpp"
#include "IRenderable.hpp"
#include "Sprites.h"


namespace Breakout {
	class Button : public IRenderable {

	public:
		Button(int texture_id, int posX, int posY, int width = 100, int height = 20);
		int listen_to_click(const Window * win, const InputManager * input);
		void render_object(const Window * win, const InputManager * input);

	private:

		int m_texture_id;
		SDL_Rect m_properties;
	};
}
#endif // ! Button_h

