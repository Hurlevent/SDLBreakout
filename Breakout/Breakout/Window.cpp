#include "Window.h"
#include <iostream>

namespace Breakout {

	bool create_window(SDL_Window ** window, const int width, const int height) {
		bool success = true;

		*window = nullptr;
		
		*window = SDL_CreateWindow("Breakout",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_SHOWN
			);

		if (*window == nullptr) {
			success = false;
		}

		return success;
	}
	// window is pass by value (pass pointer by value. We discard the value set to window)
	bool create_renderer(SDL_Window ** window, SDL_Renderer ** renderer) {
		bool success = true;

		*renderer = nullptr;

		*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);

		if(*renderer == nullptr){
			success = false;
		}
		else {
			SDL_SetRenderDrawColor(*renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		}

		return success;
	}

	bool load_media() {
		bool success = true;


		return success;
	}

	Window::Window()
	{
	}

	Window::Window(const int width, const int height)
	{
		_width = width;
		_height = height;

		SDL_Init(SDL_INIT_VIDEO);

		
		if(!create_window(&_window, width, height)){
			std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
			throw "Failure";
		}

		if (!create_renderer(&_window, &_renderer)) {
			std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
			throw "Failure";
		}
		
		if (!load_media()) {
			std::cerr << "Failed to load sprites: " << SDL_GetError() << std::endl;
			throw "Failure";
		}

	}


	Window::~Window()
	{
		SDL_DestroyRenderer(_renderer);
		_renderer = nullptr;

		SDL_DestroyWindow(_window);
		_window = nullptr;

		SDL_Quit();
	}

	void Window::set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
	{

	}
}