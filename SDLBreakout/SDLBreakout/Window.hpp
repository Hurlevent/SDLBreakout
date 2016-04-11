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

namespace Breakout {
   static const int default_width = 1024;
   static const int default_height = 1024;
    
    class Window {
    public:
		Window(const int width = default_width, const int height = default_height);
        
        ~Window();

        void set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const;
        void clear_render() const;
        void render_fill_rect(const SDL_Rect * rect) const;
		void render_texture(int id, const SDL_Rect * clip, const SDL_Rect * viewport = nullptr) const;
		void render_font_texture(int id, std::string text, int font_size, SDL_Color color, SDL_Rect * clip, SDL_Rect * viewport)const;
		void render_present() const;
		 
        void capture_start_of_frame();
        void capture_end_of_frame();
        
        int get_delta_time() const{return delta_time;};
        double get_fps() const;
        void reset_fps();
        
        int get_height()const{return _height;};
        int get_width()const{return _width;};
    
    private:
        int _width;
        int _height;
        SDL_Window * _window;
        SDL_Renderer * _renderer;        

        Timer timer;
        int delta_time;
        int time_start_of_frame;
        int counted_frames;

		bool failedToLoad;

		SDL_Renderer *RendererMenu;
		SDL_Texture *NewGameMenu;

		SDL_Rect BackgroundRect;
		SDL_Rect NewGameRect;

		SDL_Event event;

        std::vector<std::shared_ptr<SDL_Texture *>> textures; // I made it a shared_ptr, it might not be enough to fix the leaks
		
		FontTexture * m_font_texture; // Jeg tar å gjør slik som textures er gjordt, istedetfor. Da kan vi ikke endre størrelsen, men samma faen. 
    };
}



#endif /* Window_hpp */
