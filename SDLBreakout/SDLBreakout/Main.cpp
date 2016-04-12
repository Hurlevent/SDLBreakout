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

#include "BrickContainer.hpp"


static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;
static const int STATUSBAR_HEIGHT = 100;

int main(int argc, char ** argv) {
    
    try{
        // viewport for our game-board
        SDL_Rect gameboard_viewport{0, STATUSBAR_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT - STATUSBAR_HEIGHT};
        SDL_Rect statusbar_viewport{0, 0, WINDOW_WIDTH, STATUSBAR_HEIGHT};
        
        Breakout::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
        Breakout::InputManager input;
        Breakout::CompositeRenderable game_objects;
		Breakout::CompositeRenderable game_menu;
		Breakout::Menu menu(WINDOW_WIDTH, WINDOW_HEIGHT);

        Breakout::Paddle paddle((gameboard_viewport.w - 50) / 2, gameboard_viewport.h - 50);
        paddle.set_viewport(&gameboard_viewport);
        paddle.set_speed(10);

		Breakout::Statusbar statusbar(&statusbar_viewport);
        
        Breakout::BrickContainer bricks(gameboard_viewport.w, gameboard_viewport.h);
        bricks.set_viewport(&gameboard_viewport);

        
        game_objects.add(dynamic_cast<Breakout::IRenderable *>(&paddle));
        game_objects.add(dynamic_cast<Breakout::IRenderable *>(&bricks));
		game_objects.add(dynamic_cast<Breakout::IRenderable *>(&statusbar));
		game_menu.add(reinterpret_cast<Breakout::IRenderable *>(&menu));
		game_menu.addMenu(reinterpret_cast<Breakout::IMenu *>(&menu));
        
		int Menu = 0;

        while (!input.get_flag_quit()) { // this is supposed to be the main game-loop
			

            window.capture_start_of_frame();
            
            // Reads input events from user
            input.handle_input_events();
			if (Menu == 0 ) {
				// Clears the renderer
				window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
				window.clear_render();
				Menu = menu.GetClick(&window, &input);
				game_menu.render_object(&window, &input);

				
				window.render_present();
				// std::cout << "Dette er verdie:" << Menu << std::endl;
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

				// just a temporary way to view the fps
				std::cout << "FPS: " << window.get_fps() << std::endl;

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
