//
//  Window.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Window.hpp"
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;
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

	SDL_Texture * loadTexture(std::string path, SDL_Renderer ** renderer)
	{
		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(*renderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}
    
    // This is were all our sprites and TTF's should be loaded
    bool load_media(vector<SDL_Texture*> &textures, SDL_Renderer ** renderer){
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
        
      
		int numberOfTextures = 8;
	  
		string path;

        textures = new SDL_Texture[numberOfTextures];
        

        for (int i = 0; i < numberOfTextures; i++) {
			//Kanskje ikke lage ss for vær gang?! dårlig? ss = i, går ikke.
			stringstream ss;
			
			ss << i;
			path = "Sprites/" + ss.str();
			textures.push_back(loadTexture(path + ".png", &*renderer));	

			if (&textures == nullptr) {
				success = false;
			}
			
        }
        return success;
    }

    void init_timer(Timer * timer, int * counted_frames){
        
        timer->start();
        *counted_frames = 0;
    }
    
    Window::Window(const int width, const int height){
        _width = width;
        _height = height;
		failedToLoad = true;
        SDL_Init(SDL_INIT_VIDEO);
        
        if(!create_window(&_window, width, height)){
            cerr << "Failed to create window: " << SDL_GetError() << endl;
            throw "Failure";
        }
        
        cout << "Created window!" << endl;
        
        if(!create_renderer(&_window, &_renderer)){
            cerr << "Failed to create renderer: " << SDL_GetError() << endl;
            throw "Failure";
        }
        
        cout << "Created renderer!" << endl;
                
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags )) {
			cout << "SDL image could not initilaize!" << SDL_GetError() << endl;
			failedToLoad = false;
		}
		if (!load_media(textures, &_renderer)) {
			cout << "Error, cant rendrer the image." << endl;
		}
        cout << "Loaded sprites!" << endl;
        
        init_timer(&timer, &counted_frames);
    }
    
    Window::~Window(){
        
		//SDL_DestroyTexture(textures);
		//textures = nullptr;
		
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

	void Window::render_texture(int id, SDL_Rect* clip)const
	{
		//Set rendering space and render to screen
		SDL_Rect renderQuad = { clip->x, clip->y, 640, 480 };

		//Set clip rendering dimensions
		if (clip != NULL)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		//Render to screen
		SDL_RenderCopy(_renderer, textures[id], NULL, &renderQuad);
			
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