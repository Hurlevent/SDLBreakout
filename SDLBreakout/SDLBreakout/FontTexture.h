#pragma once

//#ifndef FONTTEXTURE_H
//#define FONTTEXTURE_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#endif

#include <string>
#include "Window.hpp"
#include <vector>

namespace Breakout {
	class FontTexture
	{
	public:
		FontTexture();
		~FontTexture();

		void free();
		void add_file(std::string file);
		bool update_font_texture(SDL_Renderer * renderer, int file_id, const char * text, int font_size, SDL_Color text_color);
		void render(SDL_Renderer * renderer, SDL_Rect * clip, double angle = 0.0, SDL_Point * center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE)const;
	private:
		std::vector<std::string> m_font_files;
		SDL_Texture * m_texture;
		TTF_Font * m_font;
	};
}

//#endif
