//
//  Window.hpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif


namespace Breakout {
   static const int default_width = 1024;
   static const int default_height = 1024;
    
    class Window {
    public:
        Window(const int width = default_width, const int height = default_height);
        ~Window();
        void set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const;
        void clear_render();
        void render_fill_rect(const SDL_Rect *rect) const;
        void render_present();
        int get_height;
        int get_width;
    private:
        int _width;
        int _height;
        SDL_Window * _window;
        SDL_Renderer * _renderer;
    };
}



#endif /* Window_hpp */
