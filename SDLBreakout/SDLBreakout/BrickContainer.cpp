//
//  BrickContainer.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 08.04.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "BrickContainer.hpp"


namespace Breakout {
    BrickContainer::BrickContainer(Ball *ball,int window_width, int window_height, int rows, int columns, int brick_height){
        
        m_texture_IDs.push_back(BLUE_BRICK);
        m_texture_IDs.push_back(GREEN_BRICK);
        m_texture_IDs.push_back(CYAN_BRICK);
		m_ball = ball;
        m_brick_rows = rows;
        m_brick_columns = columns;
        m_brick_height = brick_height;
        m_window_width = window_width;
        m_window_height = window_height;
        
        for(int i = 0; i < (m_brick_rows * m_brick_columns); i++){
            int x = (m_window_width / m_brick_columns) * (i % m_brick_columns);
            int y = m_brick_height * (i / m_brick_columns);
            int w = m_window_width / m_brick_columns;
            int h = m_brick_height;
            
            int texture_id = m_texture_IDs[(i / m_brick_columns) % m_texture_IDs.size()];
            
            m_bricks.push_back(std::unique_ptr<Brick>(new Brick(texture_id, x, y, w, h)));
			Sound.loadSound("PongLight");
        }
    }
    
    BrickContainer::~BrickContainer(){
        for(std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); ++iter){
            delete iter->release(); // I have no idea if this is the proper way to free memory,
            //maybe even the smart-pointer will do the job for us.
        }
    }
    // render all bricks
    void BrickContainer::render_object(const Renderer * rend, const InputManager * input, const Timer * timer){
		handle_collision();
       
		for(std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); ++iter){
           (*iter)->render_object(rend);
		}
    }

	void BrickContainer::set_viewport(const SDL_Rect* viewport)
	{
		for (std::vector<std::unique_ptr<Brick>>::iterator iter = m_bricks.begin(); iter != m_bricks.end(); ++iter)
		{
			(*iter)->set_viewport(viewport);
		}
	}

    
    void BrickContainer::handle_collision(){
        // if the ball collides with a brick, this function could maybe be usefull. Will change a lot when we implement the ball
		int leftX = m_ball->GetCollider()->x;
		int leftY = m_ball->GetCollider()->y + m_ball->GetCollider()->h / 2;

		int rightX = m_ball->GetCollider()->x + m_ball->GetCollider()->w;
		int rightY = m_ball->GetCollider()->y + m_ball->GetCollider()->h / 2;

		int topX = m_ball->GetCollider()->x + m_ball->GetCollider()->w / 2;
		int topY = m_ball->GetCollider()->y;

		int bottomX = m_ball->GetCollider()->x + m_ball->GetCollider()->w / 2;
		int bottomY = m_ball->GetCollider()->y + m_ball->GetCollider()->h;
			
		bool top = false;
		bool bottom = false;
		bool left = false;
		bool right = false;
		

		//kanskje bytte ut med en iterator?
		for (std::vector<std::unique_ptr<Brick>>::iterator it = m_bricks.begin(); it != m_bricks.end(); it++) {
				//top
				if (check_ball_hit_brick(topX, topY, (*it)->GetCollider()) == true) {
					top = true;
					//m_ball->set_position_y((*it)->GetCollider()->y + (*it)->GetCollider()->h);
					delete_block_on_hit((it)->get());
				}
				//bottom
				if (check_ball_hit_brick(bottomX, bottomY, (*it)->GetCollider()) == true) {
					bottom = true;
					//m_ball->set_position_y((*it)->GetCollider()->y);
					delete_block_on_hit((it)->get());
				}
				//left
				if (check_ball_hit_brick(leftX, leftY, (*it)->GetCollider()) == true) {
					left = true;
					//m_ball->set_position_x((*it)->GetCollider()->x);
					delete_block_on_hit((it)->get());
				}
				//right
				if (check_ball_hit_brick(rightX, rightY, (*it)->GetCollider()) == true) {
					left = true;
					//m_ball->set_position_x((*it)->GetCollider()->x + (*it)->GetCollider()->w);
					delete_block_on_hit((it)->get());
				}
		}
		double speedX = m_ball->GetSpeedY();
		double speedY = m_ball->GetSpeedY();

		if (top == true) {
			m_ball->SetSpeedY(-speedY);
		}
		if (bottom == true) {
			m_ball->SetSpeedY(-speedY);
		}
		if (left == true) {
			m_ball->SetSpeedX(-speedX);
		}	
		if (right == true) {
			m_ball->SetSpeedX(-speedX);
		}
    }
	bool BrickContainer::check_ball_hit_brick(int ballX, int ballY, SDL_Rect *rectBrick)
	{
		bool hit = false;
		if ((ballX >= rectBrick->x) && (ballX<=rectBrick->x + rectBrick->w) && (ballY >= rectBrick->y)&&(ballY <= rectBrick->y + rectBrick->h)) {
			hit = true;
			Sound.playSound();
		}
		return hit;
	}
	//Prøvde ~brick(), men da klagde den, fordi den blir drept før du får sjekket
	void BrickContainer::delete_block_on_hit(Brick *brick)
	{
		PlayerStats::Instance().score++;
		brick->SetDestroy();
	}
}