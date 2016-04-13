//
//  main.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//
#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#endif


#include <iostream>
#include <memory>
#include "InputManager.h"
#include "Window.hpp"
#include "CompositeRenderable.h"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Statusbar.hpp"
#include "Menu.h"
#include "Ball.h"

#include "BrickContainer.hpp"


static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;
static const int STATUSBAR_HEIGHT = 50;

int main(int argc, char ** argv) {
    
    try{
        // viewport for our game-board
        SDL_Rect gameboard_viewport{0, STATUSBAR_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT - STATUSBAR_HEIGHT};
        SDL_Rect statusbar_viewport{0, 0, WINDOW_WIDTH, STATUSBAR_HEIGHT};
        
        Breakout::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
        Breakout::InputManager input;
        Breakout::CompositeRenderable game_objects;
		Breakout::Menu start(WINDOW_WIDTH, WINDOW_HEIGHT);
		Breakout::Menu options(WINDOW_WIDTH, WINDOW_HEIGHT);

		Breakout::Ball ball(gameboard_viewport.w, gameboard_viewport.h, 100, 100);
        Breakout::Paddle paddle(&ball, (gameboard_viewport.w - 50) / 2, gameboard_viewport.h - 50);
        paddle.set_viewport(&gameboard_viewport);
        paddle.set_speed(10);

		Breakout::Statusbar statusbar(&statusbar_viewport);
        
        Breakout::BrickContainer bricks(gameboard_viewport.w, gameboard_viewport.h, 5, 10, 20);
        bricks.set_viewport(&gameboard_viewport);


        game_objects.add(dynamic_cast<Breakout::IRenderable *>(&paddle));
        game_objects.add(dynamic_cast<Breakout::IRenderable *>(&bricks));
		game_objects.add(dynamic_cast<Breakout::IRenderable *>(&statusbar));
		game_objects.add(dynamic_cast<Breakout::IRenderable *>(&ball));
		

		int Menu = 0;
        while (!input.get_flag_quit()) { // this is supposed to be the main game-loop
			

            window.capture_start_of_frame();
            
            // Reads input events from user
            input.handle_input_events();
			if (Menu == 0 ) {
				
				// Clears the renderer
				window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
				window.clear_render();
				
				start.SetPosition(2,3);
				
				//Menu = menu.GetClick(&window, &input);
				Menu = start.GetClick(&window, &input);
				start.render_object(&window, &input);
				
				std::cout << "Menu: " << Menu << std::endl;
				
				options.SetPosition(2,2);
				Menu = options.GetClick(&window, &input);
				options.render_object(&window, &input);
				
				window.render_present();
				
				
			}
			else {
				// Clears the renderer
				window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
				window.clear_render();

				// tells the renderer to render all game_objects
				game_objects.render_object(&window, &input);

				//Her inneholder alle bildene
				//window.render_texture(1);

				// makes the renderer actually draw a picture on screen

				window.render_present();

				//Hvis du trykker escape så går du tilbake til menyen
				if (input.get_flag_escape() == true) {
					Menu = 0;
				}

				// Update delta_time
				window.capture_end_of_frame();
			}
        }
        
    } catch(const char * msg){
        
        std::cerr << msg << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    
   
	system("pause");
    
    return EXIT_SUCCESS;
}
