#include "Menu.h"
namespace Breakout {
		Menu::Menu(SDL_Renderer * Renderer, SDL_Texture * NewGame)
		{
			RendererMenu = Renderer;
			NewGameMenu = NewGame;
		}
		int Menu::MenuShow()
		{
			SDL_GetMouseState(&x,&y);

			if (x >= NewGameRect.x && x <= NewGameRect.x + NewGameRect.w && y >= NewGameRect.y && y <= NewGameRect.y + NewGameRect.h) {
				SDL_SetTextureColorMod(NewGameMenu, 250, 0, 0);
	
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button ==  SDL_BUTTON_LEFT) {
						return 1;
					}
				}
				else {
					SDL_SetTextureColorMod(NewGameMenu, 250, 250, 250);
				}
			}
		}
		void Menu::MenuSetup(int ScreenWidth, int ScreenHeight)
		{
			BackgroundRect.x = 0;
			BackgroundRect.y = 0;
			BackgroundRect.w = ScreenWidth;
			BackgroundRect.h = ScreenHeight;

			NewGameRect.x = ScreenWidth/2;
			NewGameRect.y = ScreenHeight / 2;
			NewGameRect.w = 100;
			NewGameRect.h = 20;
		}
}