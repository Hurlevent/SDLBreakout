//
//  Window.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Window.hpp"
#include <iostream>
namespace Breakout {
    
    // Creates an SDL_Window
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
    
    // Creates an SDL_Renderer, and sets it's color to white
    bool create_renderer(SDL_Window ** window, SDL_Renderer ** renderer){
        bool success = true;
        
        *renderer = nullptr;
        
        *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
        
        if(*renderer == nullptr){
            success = false;
        } else {
            SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        
        return success;
    }
    
    // This is were all our sprites and TTF's should be loaded
    bool load_media(SDL_Texture ** textures){
        bool success = true;
        
        DIR * dir;
        struct dirent * ent = nullptr;
        
        // So this function is not working as intended yet, will hopefully get it to work soon
        
        if((dir = opendir("Sprites"))){ // da er det viktig at programmet tar utgangspunkt i et directory som har et directory som heter resources/
            
            while ((ent = readdir(dir))) { // Read all files from directory
                std::string filename = ent->d_name;
                //if(filename[0] != '.'){ // if file is not "hidden"
                    std::cout << "File" << filename << std::endl;
                //}
            }
            closedir(dir);
            
            ent = nullptr;
        } else {
            // success = false;
        }
        
        /*int numberOfTextures;
        
        textures = new SDL_Texture[numberOfTextures];
        
        for (int i = 0; i < numberOfTextures; i++) {
            textures[i] = IMG_Load();
        }
        */
        
        
        return success;
    }
    
    void init_timer(Timer * timer, int * counted_frames){
        
        timer->start();
        *counted_frames = 0;
    }
    
    Window::Window(const int width, const int height){
        _width = width;
        _height = height;
        
        SDL_Init(SDL_INIT_VIDEO);
        
        if(!create_window(&_window, width, height)){
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            throw "Failure";
        }
        
        std::cout << "Created window!" << std::endl;
        
        if(!create_renderer(&_window, &_renderer)){
            std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
            throw "Failure";
        }
        
        std::cout << "Created renderer!" << std::endl;
        
        if(!load_media(textures)){
            std::cerr << "Failed to load sprites: " << SDL_GetError() << std::endl;
        }
        
        std::cout << "Loaded sprites!" << std::endl;
        
        init_timer(&timer, &counted_frames);
    }
    
    Window::~Window(){
        SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
        
        SDL_DestroyWindow(_window);
        _window = nullptr;
        
        SDL_Quit();
    }
    
    void Window::set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)const{
        SDL_SetRenderDrawColor(_renderer, r, g, b, a);
    }
    void Window::clear_render(){
        SDL_RenderClear(_renderer);
    }
    void Window::render_fill_rect(const SDL_Rect *rect)const{
        SDL_RenderFillRect(_renderer, rect);
    }
    void Window::render_present(){
        SDL_RenderPresent(_renderer);
    }
    
    
    void Window::capture_start_of_frame(){
        time_start_of_frame = static_cast<int>(SDL_GetTicks());
    }
    
    void Window::capture_end_of_frame(){
        delta_time = static_cast<int>(SDL_GetTicks()) - time_start_of_frame;
        counted_frames++;
    }
    
    float Window::get_fps()const{
        double fps = counted_frames / (timer.elapsed_time() / 1000.f);
        if(fps > 0xFFFFFFFF){
            fps = -1;
        }
        return fps;
    }
    
    void Window::reset_fps(){
        timer.stop();
        init_timer(&timer, &counted_frames);
    }
}