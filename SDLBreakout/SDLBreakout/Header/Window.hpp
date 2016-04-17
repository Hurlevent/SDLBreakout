//
//  Window.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

// The purpose of this class is to initialize SDL and create a simple SDL_Window, bundled together with a renderer.
// This way, all the complex details on how a window is created will be hidden in this class.


#ifndef Window_hpp
#define Window_hpp

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include <iostream>
#include <vector>
#include "Timer.h"
#include <memory>
#include <dirent.h>
#include "FontTexture.h"

// This class creates an SDL_Window and is used to simplify the window-creation task for our GameManager

namespace Breakout {
   
    class Window {
    public:
		Window(const int width = 1024, const int height = 1024);
        
        ~Window();
		
        int get_height()const{return _height;};
        int get_width()const{return _width;};

		SDL_Window * get_window()const { return _window; };
    
    private:
        int _width;
        int _height;
        SDL_Window * _window;
    };
}



#endif /* Window_hpp */
