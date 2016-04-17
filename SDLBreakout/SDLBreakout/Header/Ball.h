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
#include "SoundMix.h"

namespace Breakout {
	class Ball : public GameObject
	{
	public:
		
		Ball(SDL_Rect *viewport, int width = 20, int height = 10);
		~Ball();

		SDL_Rect *GetCollider() { return m_collider; };
		Vector *GetVelocity() { return &velocity; };
		
		void render_object(const Renderer * rend, const InputManager * input = nullptr, const Timer * timer = nullptr) override;
		void handle_collision(Vector normal);
		
		void set_position_x(int x) { m_properties->x = x; m_collider->x = x; }
		void set_position_y(int y) { m_properties->y = y; m_collider->y = y; }
		
		void moveBallToPaddle(int force);
		void SetBall(bool ball);
		bool GetBall();

		bool m_gameover;

	private:
		
		void SetForce();
		void wall_collision();

		double screen_Width;
		double screen_Height;
		
		bool m_hit;	
		bool GoBall;
		
		SDL_Rect * m_collider;
		SDL_Rect * m_properties;
		SDL_Rect * m_colliderOld;
		Vector velocity;
		SoundMix m_sound;

		const SDL_Rect * m_viewport;
		int m_texture_id;
	};
}
#endif // !Ball_h
