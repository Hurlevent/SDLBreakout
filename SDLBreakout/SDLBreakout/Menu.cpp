#include "Menu.h"
namespace Breakout {
		Menu::Menu(int Width, int Height)
		{
			ScreenHeight = Height;
			ScreenWidth = Width;
			NewGameRect = new SDL_Rect{ 0, 0, 0, 0 };;
		}

		int Menu::MenuShow(const Window * win, const InputManager * input)
		{
			SDL_GetMouseState(&x, &y);

			if (x >= NewGameRect->x && x <= NewGameRect->x + NewGameRect->w && y >= NewGameRect->y && y <= NewGameRect->y + NewGameRect->h) {
				win->set_render_color_on_mouse(0, 250, 0, 0);

				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button == SDL_BUTTON_LEFT) {

					}
				}
			}
			else {
				win->set_render_color_on_mouse(0, 0, 250, 0);
			}
			return 0;
		}
		void Menu::MenuSetup(int ScreenWidth, int ScreenHeight)
		{
			
			
		}
		int Menu::GetClick(const Window * win, const InputManager * input)
		{
			int EnterButton = 0;
			SDL_GetMouseState(&x, &y);

			if (x >= NewGameRect->x && x <= NewGameRect->x + NewGameRect->w && y >= NewGameRect->y && y <= NewGameRect->y + NewGameRect->h) {
				win->set_render_color_on_mouse(0, 250, 0, 0);

				if (input->handle_mouse_events() == true)
				{
						EnterButton = 1;					
				}
			}
			else {
				win->set_render_color_on_mouse(0, 0, 250, 0);
			}
			return EnterButton;
		}
		void Menu::render_object(const Window * win, const InputManager * input)
		{
			NewGameRect->x = ScreenWidth/2;
			NewGameRect->y = ScreenHeight / 2;
			NewGameRect->w = 100;
			NewGameRect->h = 20;
			
			win->render_texture(0, NewGameRect, nullptr);
		}
}