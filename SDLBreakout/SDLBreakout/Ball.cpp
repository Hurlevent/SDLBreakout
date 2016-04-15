#include "Ball.h"
namespace Breakout {
	Ball::Ball(SDL_Rect *viewport, int width, int height)
	{
		m_properties = new SDL_Rect{ (viewport->w)/2 , (viewport->h)/2, 10, 10 };
		m_collider = new SDL_Rect{ (viewport->w)/2, (viewport->h)/2, 10, 10 };
		m_hit = false;
		m_texture_id = BALL;
		m_viewport = viewport;
		screen_Height = height;
		screen_Width = width;
		
		m_speedX = -1;
		m_speedY = -1;
	}
	Ball::~Ball()
	{
		delete m_properties;
		delete m_collider;
		m_properties = nullptr;
		m_collider = nullptr;
	}
	void Ball::render_object(const Renderer * rend, const InputManager * input, const Timer * timer)
	{
		SetForce();
		wall_collision();

		rend->render_texture(m_texture_id, m_collider, m_viewport);
	}
	void Ball::SetForce()
	{
		m_properties->x += m_speedX;
		m_properties->y += m_speedY;
		m_collider->x += m_speedX;
		m_collider->y += m_speedY;

	}

	void Ball::handle_collision(Vector normal)
	{
	}
	void Ball::wall_collision()
	{
		//Treffer ballen venstre vegg eller høyere så skal den bevege seg med en speilvinkel i motsatt retning

		if (m_collider->x <= m_viewport->x && m_speedX < 0)
		{
			set_position_x(m_viewport->x);
			m_speedX = -m_speedX;
		}

		if(m_collider->x + m_collider->w >= m_viewport->w && m_speedX >= 0)
		{
			set_position_x(m_viewport->w - m_collider->w);
			m_speedX = -m_speedX;
		}

		if(m_collider->y <= 0 && m_speedY < 0)
		{
			set_position_y(0);
			m_speedY = -m_speedY;
		}

		if(m_collider->y + m_collider->h >= m_viewport->h)
		{
			m_speedY = -m_speedY;
			
			if(PlayerStats::Instance().health > 0)
			{
				PlayerStats::Instance().health--;
			} else
			{
				std::cout << "GAME OVER!!" << std::endl;
			}
		}

	}
	
}