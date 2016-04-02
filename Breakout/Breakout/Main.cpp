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
#include <memory>
#include "InputManager.h"
#include "Window.hpp"
#include "CompositeRenderable.h"
#include "Paddle.hpp"
#include "Brick.hpp"

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

int main(int argc, const char ** argv) {
    
    try{
        
        Breakout::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
        Breakout::InputManager input;
        Breakout::CompositeRenderable game_objects;
        
        Breakout::Paddle paddle((WINDOW_WIDTH - 50) / 2, WINDOW_HEIGHT - 50);
        paddle.set_speed(10);
        
        int brickWidth = 20;
        
        // add bricks here
        std::shared_ptr<Breakout::Brick> brick_ptr;
        
        
        
        game_objects.add(reinterpret_cast<Breakout::IRenderable *>(&paddle));
        
        
        while (!input.get_flag_quit()) { // this is supposed to be the main game-loop
            input.handle_input_events();
            
            window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
            window.clear_render();
            
            game_objects.render_object(&window, &input);
            
            window.render_present();
        }
        
    } catch(const char * msg){
        
        std::cerr << msg << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    
    
    
    
    return EXIT_SUCCESS;
}
