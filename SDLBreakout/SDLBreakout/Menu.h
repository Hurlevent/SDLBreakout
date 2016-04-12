#ifndef  Menu_h
#define Menu_h

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Window.hpp"
#include "IRenderable.hpp"
#include "Sprites.h"
#include "IMenu.h"

namespace Breakout {
	class Menu : public IRenderable, public IMenu {

	public:
		Menu(int Width, int Height);
		int MenuShow(const Window * win, const InputManager * input);
		void MenuSetup(int ScreenWidht, int ScreenHeight);
		int GetClick(const Window * win, const InputManager * input);
		bool PressEsc(const InputManager * input);
		void SetPosition(const int posx, const int posy);

	private:
	
		void render_object(const Window * win, const InputManager * input = nullptr);
		
		int ScreenWidth;
		int ScreenHeight;


		int x;
		int y;
		int PositionX;
		int PositionY;

		bool Play = false;

		SDL_Rect *NewGameRect;

		SDL_Event event;
	};
}
#endif // ! Menu_h

