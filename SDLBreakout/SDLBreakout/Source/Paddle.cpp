//
//  Paddle.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "../Header/Paddle.hpp"
#include <iostream>
namespace Breakout {
    
    Paddle::Paddle(Ball * ball, const int posX, const int posY, const int width, const int height){
        properties = new SDL_Rect{posX, posY, width, height};
        collider = new SDL_Rect{posX, posY, width, height};
        velocity = new Vector(0, 0);
		sound.loadSound("PongDark");

        m_viewport = nullptr;
        m_texture_id = PURPLE_BRICK;
		m_ball = ball;
		
		
    }
    
    Paddle::~Paddle(){
        
       delete velocity;
        velocity = nullptr;
        
        delete properties;
        properties = nullptr;
        
        delete collider;
        collider = nullptr;
		
    }
    
    void Paddle::render_object(const Renderer * rend, const InputManager * input, const Timer * timer){

		
		double deltatime = timer->get_delta();
		
		/*
		std::string deltastr;
		int num_bytes = snprintf(&deltastr[0], deltastr.max_size(), "%.2f", deltatime);
		if (num_bytes < deltastr.max_size())
		{
			deltastr.resize(num_bytes);
		}

		 std::cout << "Deltatime: " << deltastr << std::endl;
        */
	
		if (input->get_flag_space() == true) {
			m_ball->SetBall(false);
		}

		if(input != nullptr){
            if(input->get_flag_right()){
                properties->x += static_cast<int>((deltatime/10 * m_speed));
					

            } else if(input->get_flag_left()){
                properties->x += static_cast<int>((deltatime/10 * -m_speed));
            }
			if (m_ball->GetBall() == true) {
				m_ball->moveBallToPaddle(properties->x + properties->w / 2);
			}
		
        }
        
        // the paddle doesn't need constant movement, so the velocity member variable could be removed
        properties->x += static_cast<int>(velocity->get_x());
        properties->y += static_cast<int>(velocity->get_y());
        
        // Making sure that the paddle can't move out of bounds
        if(properties->x < 0){
            properties->x = 0;
        } else if((properties->x + properties->w) > rend->get_width()){
            properties->x = (rend->get_width() - properties->w);
        }
        
        // updating collider position to match properties
        collider->x = properties->x;
        collider->y = properties->y;
        
		rend->render_texture(m_texture_id, collider, m_viewport);

		handleBall();
	
    }
    
    void Paddle::set_colors(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a){
		m_color.r = r;
		m_color.g = g;
		m_color.b = b;
		m_color.a = a;
    }
	bool Paddle::CheckBallCollision()
	{
		//må sette ballspeed
		int ballspeed = 5;
		//sjekker om ballen beveger mot paddelen og om den kan treffe siden av paddelen
		if ((m_ball->GetCollider()->y + m_ball->GetCollider()->h >= collider->y) && (m_ball->GetCollider()->y + m_ball->GetCollider()->h <= collider->y + collider->h)) {

			if ((m_ball->GetCollider()->x <= collider->x + collider->w) && (m_ball->GetCollider()->x + m_ball->GetCollider()->w >= collider->x)) {
				sound.playSound();
				return true;
			}
		}
		return false;
	}
	void Paddle::handleBall()
	{
		if (CheckBallCollision()) {
			// henter midtpunkte til paddelen
			int paddleCenter = collider->x + collider->w / 2;
			int ballCenter = m_ball->GetCollider()->x + m_ball->GetCollider()->w / 2;
			m_ball->set_position_y(collider->y - m_ball->GetCollider()->h);
			
			// Finner punkte der ballen treffer paddelen
			
			int paddleLocation = ballCenter - paddleCenter;
			double speedx = paddleLocation*0.05;

			m_ball->GetVelocity()->set_x(speedx);
			m_ball->GetVelocity()->set_y(-(m_ball->GetVelocity()->get_y()));
		}
	}
}