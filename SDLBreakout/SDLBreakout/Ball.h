#ifndef Ball_h
#define Ball_h

#include <iostream>
#include "IRenderable.hpp"
#include "Vector.hpp"
#include "Window.hpp"
#include "InputManager.h"
#include "IViewport.h"
#include <SDL.h>
#include "Sprites.h"


namespace Breakout {
	class Ball : public IRenderable
	{
	public:
		Ball(SDL_Rect *viewport, int width = 20, int height = 10);
		~Ball();
		void render_object(const Window * win, const InputManager * input = nullptr);
		void SetForce();
		SDL_Rect *GetCollider() { return m_collider; };
		void handle_collision(Vector normal);
		void wall_collision();
		void BallBefore() { before = m_collider; };
		void BallAfter() { after = m_collider; };
	

	private:
		double m_speedX;
		double m_speedY;

		Vector velocity;
		double screen_Width;
		double screen_Height;
		bool m_hit;	
		SDL_Rect * m_collider;
		SDL_Rect * m_properties;
		SDL_Rect *before;
		SDL_Rect *after;
	
		int m_texture_id;
		const SDL_Rect * m_viewport;
	};
}
#endif // !Ball_h
