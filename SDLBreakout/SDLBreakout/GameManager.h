#ifndef GameManager_h
#define GameManager_h
#include "Window.hpp"
#include "InputManager.h"
#include "CompositeRenderable.h"
#include "Menu.h"
#include "Ball.h"
#include "Paddle.hpp"
#include "Statusbar.hpp"
#include "BrickContainer.hpp"
#include "Renderer.h"

namespace Breakout {
	class GameManager
	{
	public:
		GameManager(int window_width, int window_height, int statusbar_height);
		void run_gameloop();
		void render();
		~GameManager();
	private:
		Window m_window;
		Renderer m_renderer;
		SDL_Rect m_gameboard_viewport;
		SDL_Rect m_statusbar_viewport;
		InputManager m_input;
		CompositeRenderable m_game_objects;
		Menu m_main_menu;
		Statusbar m_statusbar;
		Ball m_ball;
		Paddle m_paddle;
		BrickContainer m_bricks;
		
		Timer m_timer;
		int m_ticks;

	};
}

#endif
