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
		void render_present() const;
		 
        void capture_start_of_frame();
        void capture_end_of_frame();
        
        int get_delta_time() const{return delta_time;};
        float get_fps() const;
        void reset_fps();
        
        int get_height()const{return _height;};
        int get_width()const{return _width;};
<<<<<<< HEAD
        
		SDL_Texture *getTexture(int id);
		SDL_Renderer *getRendrer();

		int MenuShow(int id);

		void MenuSetup(int ScreenWidth, int ScreenHeight);
=======
>>>>>>> 3d24f410509648da4872867d79df4210ef498138
    
    private:
        int _width;
        int _height;
        SDL_Window * _window;
        SDL_Renderer * _renderer;
<<<<<<< HEAD
=======
		SDL_Renderer * _paddle;
        
>>>>>>> 3d24f410509648da4872867d79df4210ef498138
        Timer timer;
        int delta_time;
        int time_start_of_frame;
        int counted_frames;
<<<<<<< HEAD
		bool failedToLoad;
		std::vector<SDL_Texture*> textures;
        //SDL_Texture ** textures;
		//SDL_Texture * text;
		SDL_Renderer *RendererMenu;
		SDL_Texture *NewGameMenu;

		int x;
		int y;

		bool Play = false;

		SDL_Rect BackgroundRect;
		SDL_Rect NewGameRect;

		SDL_Event event;
=======
        
        std::vector<std::shared_ptr<SDL_Texture *>> textures; // I made it a shared_ptr, it might not be enough to fix the leaks
>>>>>>> 3d24f410509648da4872867d79df4210ef498138
    };
}



#endif /* Window_hpp */
