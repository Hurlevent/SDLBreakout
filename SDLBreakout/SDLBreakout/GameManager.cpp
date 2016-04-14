#include "GameManager.h"

namespace Breakout {

	GameManager::GameManager(int window_width, int window_height, int statusbar_height) :
		m_window(window_width, window_height),
		m_gameboard_viewport{0, statusbar_height, window_width, window_height - statusbar_height},
		m_statusbar_viewport{0, 0, window_width, statusbar_height}, 
		m_main_menu(window_width, window_height, 2), 
		m_statusbar(&m_statusbar_viewport), 
		m_ball(&m_gameboard_viewport), 
		m_paddle(&m_ball, (m_gameboard_viewport.w - 50) / 2, m_gameboard_viewport.h - 50),
		m_bricks(window_width, window_height, 5, 10, 20)
	{
		m_paddle.set_speed(10);
		m_paddle.set_viewport(&m_gameboard_viewport);
		m_statusbar.set_viewport(&m_statusbar_viewport);
		m_bricks.set_viewport(&m_gameboard_viewport);

		m_game_objects.add(dynamic_cast<GameObject *>(&m_paddle));
		m_game_objects.add(dynamic_cast<GameObject *>(&m_ball));
		m_game_objects.add(dynamic_cast<GameObject *>(&m_bricks));
		m_game_objects.add(dynamic_cast<GameObject *>(&m_statusbar));

	}

	void GameManager::run_gameloop()
	{
		while(!m_input.get_flag_quit())
		{

			m_window.capture_start_of_frame();

			// Reads input events from user

			m_input.handle_input_events();

			// Clears the renderer
			m_window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
			m_window.clear_render();

			if(m_main_menu.get_view() == 0)
			{

				m_main_menu.render_object(&m_window, &m_input);

			} else
			{
				// Update the picture of the screen in memory
				m_game_objects.render_object(&m_window, &m_input);


				// for the ball physics
				m_ball.SetForce();
				m_ball.wall_collision();
				m_paddle.handleBall();


				// temporary, press escape to return to the menu
				if(m_input.get_flag_escape())
				{
					m_main_menu.set_view(0);
				}

			}

			// makes the renderer actually draw a picture on the screen
			m_window.render_present();

			// update delta_time
			m_window.capture_end_of_frame();
		}
	}


	GameManager::~GameManager()
	{
	}
}