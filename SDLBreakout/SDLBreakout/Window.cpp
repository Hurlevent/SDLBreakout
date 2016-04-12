//
//  Window.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "Window.hpp"


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

	SDL_Texture * load_texture(std::string path, SDL_Renderer * renderer){
		//The final texture
		SDL_Texture * newTexture = nullptr;

		//Load image at specified path
		SDL_Surface * loadedSurface = IMG_Load(path.c_str());
		if (loadedSurface == nullptr)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == nullptr)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}
    
    // This is were all our sprites and TTF's should be loaded
	bool load_media(std::vector<std::shared_ptr<SDL_Texture *>> &textures, FontTexture * font_texture, int font_size, SDL_Renderer * renderer) {
        bool success = true;
     
		
        DIR * dir = nullptr;
        struct dirent * ent = nullptr;
        
        const char * sprites_directory = "Sprites/";
        
        if((dir = opendir(sprites_directory))){ // Det er viktig at working directory er satt riktig!
            
            while ((ent = readdir(dir))) { // Read all files from directory
                
                std::string filename = ent->d_name;
                
                if(filename[0] != '.'){ // if file is not "hidden"
                    std::cout << "Found file: " << filename.c_str() << std::endl;

                    SDL_Texture * texture = load_texture(sprites_directory + filename, renderer);
                    
                    if(texture == nullptr){
                        
                        success = false;
                    
                    } else {
                        
                        textures.push_back(std::make_shared<SDL_Texture *>(texture));
                    }
                }
            }
            
            closedir(dir);
            
            dir = nullptr;
            ent = nullptr;
            
        } else {
            
             success = false;
        }
	        
        std::string ttf_directory = "TTF/";
        
        if((dir = opendir(ttf_directory.c_str()))){
        
            while((ent = readdir(dir))){
                
                std::string filename = ent->d_name;
                
                if(filename[0] != '.'){ // We don't want to read hidden files
                    
                    std::cout << "Found file: " << filename.c_str() << std::endl;
                    
                    if(!font_texture->load_font_from_file((ttf_directory + filename).c_str(), font_size)){
                        
                        std::cerr << "Failed to load TTF! Error: " << TTF_GetError() << std::endl;
                        success = false;
                    
                    }
                }
            }
            
            closedir(dir);
            dir = nullptr;
            ent = nullptr;
            
        } else {
            
            std::cerr << "Failed to open directory " << ttf_directory.c_str() << std::endl;
            success = false;
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
        
		m_font_size = 24;

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
        
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags )) {
            std::cerr << "SDL_IMAGE could not initilaize! Error: " << IMG_GetError() << std::endl;
            throw "Failure";
        }
        
        if(TTF_Init() == -1){
            std::cerr << "SDL_TTF could not initialize! Error: " << TTF_GetError() << std::endl;
            throw "Failure";
        }
        
		m_font_texture_creator = new FontTexture();

		if (!load_media(textures, m_font_texture_creator, m_font_size, _renderer)) {
            std::cerr << "Failed to load resource files!" << std::endl;
            throw "Failure";
		}
        
        std::cout << "Loaded sprites!" << std::endl;
        
        init_timer(&timer, &counted_frames);
    }
    
    Window::~Window(){
        
        for(std::vector<std::shared_ptr<SDL_Texture *>>::iterator iter = textures.begin(); iter != textures.end(); iter++){
            SDL_DestroyTexture(**iter);
        }
		
		delete m_font_texture_creator;
		m_font_texture_creator = nullptr;

		SDL_DestroyRenderer(_renderer);
        _renderer = nullptr;
        
        SDL_DestroyWindow(_window);
        _window = nullptr;
        
        
        IMG_Quit();
        SDL_Quit();
    }
    
    void Window::set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)const{
        SDL_SetRenderDrawColor(_renderer, r, g, b, a);
    }
    void Window::clear_render() const{
        SDL_RenderClear(_renderer);
    }
    void Window::render_fill_rect(const SDL_Rect *rect)const{
        SDL_RenderFillRect(_renderer, rect);
    }

	void Window::render_texture(int id, const SDL_Rect * clip, const SDL_Rect * viewport) const
	{
		//Set rendering space and render to screen
		SDL_Rect renderQuad = { clip->x, clip->y, _width, _height };

		//Set clip rendering dimensions
		if (clip != nullptr)
		{
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}
        
        // if viewport is null, we set viewport to be the entire window
        if(viewport == nullptr){
            SDL_Rect wholescreen{0, 0, _width, _height};
            viewport = &wholescreen;
            SDL_RenderSetViewport(_renderer, viewport);
        } else {
            SDL_RenderSetViewport(_renderer, viewport);
        }

		//Render to screen
		SDL_RenderCopy(_renderer, *(textures[id]), nullptr, &renderQuad);
			
	}

	void Window::render_font_texture(int id, const SDL_Rect * clip, const SDL_Rect * viewport)const
    {
		SDL_Rect renderQuad{0, 0, _width, _height};
		
		if(clip != nullptr)
		{
			renderQuad.x = clip->x;
			renderQuad.y = clip->y;
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		if(viewport == nullptr)
		{
			SDL_Rect wholescreen{0, 0, _width, _height};
			viewport = &wholescreen;
			SDL_RenderSetViewport(_renderer, viewport);
		} else
		{
			SDL_RenderSetViewport(_renderer, viewport);
		}
		m_font_texture_creator->render(_renderer, id, &renderQuad);
    }
	
	void Window::update_font_texture_text(int id, std::string text, SDL_Color text_color) const
	{
		if(!m_font_texture_creator->update_font_texture(_renderer, id, text.c_str(), text_color))
		{
			std::cerr << "Failed to create texture from TTF!" << std::endl;
		}
	}


	void Window::set_render_color_on_mouse(int id, uint8_t r, uint8_t g, uint8_t b)const
	{
		SDL_SetTextureColorMod(*(textures[id]), r, g, b);
	}

	
    void Window::render_present() const{
        SDL_RenderPresent(_renderer);
    }    
    
    void Window::capture_start_of_frame(){
        time_start_of_frame = static_cast<int>(SDL_GetTicks());
    }
    
    void Window::capture_end_of_frame(){
        delta_time = static_cast<int>(SDL_GetTicks()) - time_start_of_frame;
        counted_frames++;
    }
    
    double Window::get_fps()const{
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