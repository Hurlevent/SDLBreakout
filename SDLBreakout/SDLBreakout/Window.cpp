//
//  Window.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Window.hpp"


namespace Breakout {
    
	/////////////////////////////////////////////////
	// START OF UTIL FUNCTIONS
	/////////////////////////////////////////////////

    bool create_window(SDL_Window ** window, const int width, const int height){
        bool success = true;
        
        *window = nullptr;
        
        *window = SDL_CreateWindow("Breakout",
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   width,
                                   height,
                                   SDL_WINDOW_SHOWN
                                   );
        if(*window == nullptr){
            success = false;
        }
        
        return success;
    }
    
	/////////////////////////////////////////////////
	// CONSTRUCTOR AND DESTRUCTOR
	/////////////////////////////////////////////////

    Window::Window(const int width, const int height){
        _width = width;
        _height = height;

        SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
        
        if(!create_window(&_window, width, height)){
            std::cerr << "Error: " << SDL_GetError() << std::endl;
            throw "Failed to create window!";
        }
        
        std::cout << "Created window!" << std::endl;
    }
    
    Window::~Window(){
        SDL_DestroyWindow(_window);
        _window = nullptr;
        
        SDL_Quit();
    }
}