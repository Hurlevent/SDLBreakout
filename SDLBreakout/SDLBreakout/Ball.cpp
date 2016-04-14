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
	void Ball::render_object(const Renderer * rend, const InputManager * input)
	{
		
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
		if (((m_collider->x<0) && (m_collider->x <= 0)) || ((m_collider->x > 0) && (m_collider->x+m_collider->w >= m_viewport->w))) {
			m_speedX = -m_speedX;
		}
		if((m_collider->y < 0) && m_collider->y <= (screen_Height-m_viewport->h)){
			m_speedY = -m_speedY;
		}

	}
	
}