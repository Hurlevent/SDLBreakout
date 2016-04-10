#ifndef  Menu_h
#define Menu_h

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
namespace Breakout {
	class Menu {

	public:
		Menu(SDL_Renderer *Renderer, SDL_Texture *NewGame);
		int MenuShow();
		void MenuSetup(int ScreenWidht, int ScreenHeight);

	private:
		SDL_Renderer *RendererMenu;
		SDL_Texture *NewGameMenu;

		int x;
		int y;

		bool Play = false;

		SDL_Rect BackgroundRect;
		SDL_Rect NewGameRect;

		SDL_Event event;
	};
}
#endif // ! Menu_h

