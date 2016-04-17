#ifndef RENDERER_H
#define RENDERER_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include "FontTexture.h"
#include <memory>
#include <vector>
#include <iostream>
#include "../Dirent/dirent.h"
#include "Window.hpp"

namespace Breakout {

	// This class acts as an API for our GameObjects to communicate with the SDL_Renderer. 
	class Renderer
	{
	public:
		Renderer(const Window * window, int font_size = 24);
		~Renderer();

		void set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const;
		void set_render_color_on_mouse(int id, uint8_t r, uint8_t g, uint8_t b)const;
		
		void render_texture(int id, const SDL_Rect * clip, const SDL_Rect * viewport = nullptr) const;
		void render_font_texture(int id, const SDL_Rect * clip, const SDL_Rect * viewport = nullptr)const;

		void update_font_texture_text(int id, std::string text, SDL_Color text_color)const;
		void render_present() const;
		void clear_render() const;
		
		int get_width() const { return m_window_width; }
		int get_height() const { return m_window_height; }

	private:
		SDL_Renderer * m_renderer;

		std::vector<std::shared_ptr<SDL_Texture *>> m_sprites; // sprites
		FontTexture * m_font_texture_creator; // this object creates ttf-textures for us
		int m_font_size; // this is the font_size of the text that our FontTexture object uses to create textures from.

		int m_window_width;
		int m_window_height;
	};
}

#endif
