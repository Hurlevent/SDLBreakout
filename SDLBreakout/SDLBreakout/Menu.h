#ifndef  Menu_h
#define Menu_h

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Window.hpp"
#include "IRenderable.hpp"
#include "Sprites.h"


namespace Breakout {
	class Menu : public IRenderable {

	public:
		Menu(int Width, int Height);
		void MenuSetup(int ScreenWidht, int ScreenHeight);
		int GetClick(const Window * win, const InputManager * input);
		bool PressEsc(const InputManager * input);
		void SetPosition(const int posx, const int posy);
		void render_object(const Window * win, const InputManager * input);

	private:
	
		
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

