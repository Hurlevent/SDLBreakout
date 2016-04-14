#ifndef Ball_h
#define Ball_h

#include <iostream>

#include "GameObject.h"
#include "IRenderable.hpp"
#include "Vector.hpp"
#include "Renderer.h"
#include "InputManager.h"
#include "Sprites.h"


namespace Breakout {
	class Ball : public GameObject
	{
	public:
		Ball(SDL_Rect *viewport, int width = 20, int height = 10);
		~Ball();

		void SetForce();
		SDL_Rect *GetCollider() { return m_collider; };

		void render_object(const Renderer * rend, const InputManager * input = nullptr) override;

		void handle_collision(Vector normal);
		void wall_collision();

		double GetSpeedX() { return m_speedX; };
		double GetSpeedY() { return m_speedY; };

		void SetSpeedX(double speedX) { m_speedX = speedX; };
		void SetSpeedY(double speedY) { m_speedY = speedY; };

	

	private:
		double m_speedX;
		double m_speedY;

		Vector velocity;
		double screen_Width;
		double screen_Height;
		bool m_hit;	
		SDL_Rect * m_collider;
		SDL_Rect * m_properties;


	
		int m_texture_id;
		const SDL_Rect * m_viewport;
	};
}
#endif // !Ball_h
