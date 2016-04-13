#include "Ball.h"
namespace Breakout {
	Ball::Ball(int win_width, int win_height, int width, int height)
	{
		m_properties = new SDL_Rect{ (win_width-width)/2 , (win_height-width)/2, width, height };
		m_collider = new SDL_Rect{ (win_width-width)/2, (win_height-width)/2, width, height };
		m_hit = false;
		m_texture_id = RED_HEART;
		m_viewport = nullptr;
	}
	Ball::~Ball()
	{
		delete(m_properties);
		delete(m_collider);
		m_properties = nullptr;
		m_collider = nullptr;
	}
	void Ball::render_object(const Window * win, const InputManager * input)
	{
		
		win->render_texture(m_texture_id, m_collider, m_viewport);
	}
	void Ball::SetForce(double speed)
	{
	}
	void Ball::handle_collision(Vector normal)
	{
	}
}