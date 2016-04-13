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
		Ball(int win_width, int win_height, int width = 20, int height = 10);
		~Ball();
		void render_object(const Window * win, const InputManager * input = nullptr);
		void SetForce(double speed);
		SDL_Rect *GetCollider() { return m_collider; };
		void handle_collision(Vector normal);


	private:
		double m_speed;
		Vector velocity;

		bool m_hit;

		SDL_Rect * m_collider;
		SDL_Rect * m_properties;
		int m_texture_id;
		const SDL_Rect * m_viewport;
	};
}
#endif // !Ball_h
