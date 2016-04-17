#include "Ball.h"
namespace Breakout {
	Ball::Ball(SDL_Rect *viewport, int width, int height)
	{
		m_properties = new SDL_Rect{ (viewport->w)/2 , (viewport->h-100), 10, 10 };
		m_collider = new SDL_Rect{ (viewport->w)/2, (viewport->h-100), 10, 10 };
		m_hit = false;
		m_texture_id = BALL;
		m_viewport = viewport;
		m_sound.loadSound("PongDark");
		m_gameover = false;
		m_colliderOld = m_collider;

		screen_Height = height;
		screen_Width = width;

		velocity.set_x(-1);
		velocity.set_y(-1);
	
		GoBall = true;
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
	void Ball::moveBallToPaddle(int force)
	{

		m_properties->x = force;
		m_collider->x = force;
		m_properties->y = (m_viewport->h - 100);
		m_collider->y = (m_viewport->h - 100);

	}
	void Ball::SetBall(bool ball)
	{
		GoBall = false;
	}
	bool Ball::GetBall()
	{
		return GoBall;
	}

	void Ball::SetForce()
	{
		Vector vel = velocity;
		
		if (GoBall == false) {
			m_properties->x += vel.get_x();
			m_properties->y += vel.get_y();
			m_collider->x += vel.get_x();
			m_collider->y += vel.get_y();
		}
	}

	void Ball::handle_collision(Vector normal)
	{
	}
	void Ball::wall_collision()
	{
		//Treffer ballen venstre vegg eller høyere så skal den bevege seg med en speilvinkel i motsatt retning

		if (m_collider->x <= m_viewport->x && velocity.get_x() < 0)
		{
			set_position_x(m_viewport->x);
			velocity.set_x(-velocity.get_x());
			m_sound.playSound();
		}

		if(m_collider->x + m_collider->w >= m_viewport->w && velocity.get_x() >= 0)
		{
			set_position_x(m_viewport->w - m_collider->w);
			velocity.set_x(-velocity.get_x());
			m_sound.playSound();
		}

		if(m_collider->y <= 0 && velocity.get_y() < 0)
		{
			set_position_y(0);
			velocity.set_y(-velocity.get_y());
			m_sound.playSound();
		}

		if(m_collider->y + m_collider->h >= m_viewport->h)
		{
			GoBall = true;
			velocity.set_y(-velocity.get_y());
			if(PlayerStats::Instance().health > 0)
			{
				PlayerStats::Instance().health--;
			} else
			{
				std::cout << "GAME OVER!!" << std::endl;
				m_gameover = true;
			}
		}

	}
	
}