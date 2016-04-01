//
//  main.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//
#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include <iostream>
#include "InputManager.h"
#include "Window.hpp"
#include "CompositeMovable.h"
#include "Paddle.hpp"

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

int main(int argc, const char ** argv) {
    
    try{
        
        Breakout::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
        Breakout::InputManager input;
        Breakout::CompositeMovable game_objects;
        
        Breakout::Paddle paddle((WINDOW_WIDTH - 50) / 2, WINDOW_HEIGHT - 50);
        paddle.set_speed(10);
        
        game_objects.add(reinterpret_cast<Breakout::IMovable *>(&paddle));
        
        
        while (!input.get_flag_quit()) { // this is supposed to be the main game-loop
            input.handle_input_events();
            
            window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
            window.clear_render();
        
            SDL_Rect fillrect = {WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
            window.set_render_draw_color(0xFF, 0x00, 0x00, 0x00);
            window.render_fill_rect(&fillrect);
            
            paddle.calculate_velocity(&input);
            
            game_objects.update_position(&window);
            
            window.render_present();
        }
        
    } catch(const char * msg){
        
        std::cerr << msg << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    
    
    
    
    return EXIT_SUCCESS;
}
