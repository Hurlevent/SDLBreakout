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

	// The GameManager class Initializes all the object used by our game
	// The run_gameloop function runs the "infinite" loop that we are used to define as the gameloop.

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
		Statusbar m_statusbar;
		Timer m_timer;

		Ball m_ball;
		Paddle m_paddle;
		BrickContainer m_bricks;
		void CheckView();
	
		int m_ticks;
	};
}

#endif
