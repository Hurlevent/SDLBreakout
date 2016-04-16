#ifndef Ball_h
#define Ball_h

#include <iostream>

#include "GameObject.h"
#include "IRenderable.hpp"
#include "Vector.hpp"
#include "Renderer.h"
#include "InputManager.h"
#include "Sprites.h"
#include "PlayerStats.h"


namespace Breakout {
	class Ball : public GameObject
	{
	public:
		Ball(SDL_Rect *viewport, int width = 20, int height = 10);
		~Ball();

		SDL_Rect *GetCollider() { return m_collider; };

		void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;

		void handle_collision(Vector normal);

		double GetSpeedX() { return m_speedX; };
		double GetSpeedY() { return m_speedY; };

		void SetSpeedX(double speedX) { m_speedX = speedX; };
		void SetSpeedY(double speedY) { m_speedY = speedY; };
		
		void set_position_x(int x) { m_properties->x = x; m_collider->x = x; }
		void set_position_y(int y) { m_properties->y = y; m_collider->y = y; }

	

	private:
		void SetForce();
		void wall_collision();

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
