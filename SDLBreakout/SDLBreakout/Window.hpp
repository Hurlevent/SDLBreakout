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
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

#include <iostream>
#include <vector>
#include "Timer.h"

namespace Breakout {
   static const int default_width = 1024;
   static const int default_height = 1024;
    
    class Window {
    public:
		

		Window(const int width = default_width, const int height = default_height);
        ~Window();

        void set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const;
        void clear_render();
        void render_fill_rect(const SDL_Rect * rect) const;
		void render_texture(int id, const SDL_Rect * clip)const;
		void render_present();
		 
        void capture_start_of_frame();
        void capture_end_of_frame();
        
        int get_delta_time() const{return delta_time;};
        float get_fps() const;
        void reset_fps();
        
        int get_height()const{return _height;};
        int get_width()const{return _width;};
    
    private:
        int _width;
        int _height;
        SDL_Window * _window;
        SDL_Renderer * _renderer;
		SDL_Renderer * _paddle;
        
        Timer timer;
        int delta_time;
        int time_start_of_frame;
        int counted_frames;
        
        std::vector<std::shared_ptr<SDL_Texture *>> textures; // I made it a shared_ptr, it might not be enough to fix the leaks
    };
}



#endif /* Window_hpp */
