#include "GameManager.h"

namespace Breakout {

	/////////////////////////////////////////////////
	// CONSTRUCTOR
	/////////////////////////////////////////////////
	GameManager::GameManager(int window_width, int window_height, int statusbar_height) :
		m_window(window_width, window_height),
		m_renderer(&m_window),
		m_gameboard_viewport{0, statusbar_height, window_width, window_height - statusbar_height},
		m_statusbar_viewport{0, 0, window_width, statusbar_height}, 
		m_game_objects(window_width, window_height, 2, 100, 20),
		m_statusbar(&m_statusbar_viewport), 
		m_ball(&m_gameboard_viewport), 
		m_paddle(&m_ball, (m_gameboard_viewport.w - 50) / 2, m_gameboard_viewport.h -m_statusbar_viewport.h),
		m_bricks(&m_ball,window_width, window_height, 5, 10, 20)
	{
		m_paddle.set_speed(10);
		m_paddle.set_viewport(&m_gameboard_viewport);
		m_statusbar.set_viewport(&m_statusbar_viewport);
		m_bricks.set_viewport(&m_gameboard_viewport);

		m_game_objects.add(dynamic_cast<GameObject *>(&m_paddle));
		m_game_objects.add(dynamic_cast<GameObject *>(&m_ball));
		m_game_objects.add(dynamic_cast<GameObject *>(&m_bricks));
		m_game_objects.add(dynamic_cast<GameObject *>(&m_statusbar));

		m_ticks = 0;
		m_game_objects.ChangeView(0);
	}

	/////////////////////////////////////////////////
	// GAME LOOP
	/////////////////////////////////////////////////
	void GameManager::run_gameloop()
	{
		
		Uint32 lastTime = SDL_GetTicks();
		double msPerTick = 1000 / 60;

		m_ticks = 0;

		double delta = 0;

		m_timer.start();

		while(!m_input.get_flag_quit())
		{
			CheckView();
			Uint32 now = SDL_GetTicks();

			delta += (now - lastTime) / msPerTick;

			//m_timer.set_delta(m_timer.get_delta() + (now - lastTime)); // it would be nice if we could store this information on our Timer object

			lastTime = now;

			m_input.handle_input_events();

			while (delta >= 1) {
				delta -= 1;
				
				//m_timer.dec_delta(); // It would be nice to use our timer-object

				// Clears the renderer
				m_renderer.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
				m_renderer.clear_render();

				// Executes all the game logic and creates an image in memory
				m_game_objects.Update(&m_renderer, &m_input, &m_timer);

				// Draw screen
				m_renderer.render_present();

				// update timer!
				m_timer.update();
			}
		}
		
		m_timer.stop();
	}

	void GameManager::CheckView() {
		if (m_ball.m_gameover) {
			m_game_objects.ChangeView(0);
		}
		if (m_game_objects.menu.get_view()==1) {
			m_game_objects.ChangeView(1);
			m_game_objects.menu.set_view(0);
			m_timer.unpause();
		}
		if (m_input.get_flag_escape()) {
			m_game_objects.ChangeView(0);
			m_timer.pause();
		}
	}

	void GameManager::render() {

	}

	/////////////////////////////////////////////////
	// DESTRUCTOR
	/////////////////////////////////////////////////
	GameManager::~GameManager()
	{
	}
}