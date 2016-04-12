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
#include <iostream>
#include "Sprites.h"

namespace Breakout {
	class FontTexture
	{
	public:
		FontTexture();                              
		~FontTexture();

		void free();
		bool load_font_from_file(const char * filepath, int text_size);
		bool update_font_texture(SDL_Renderer * renderer, int id, const char * text, SDL_Color text_color);
		void render(SDL_Renderer * renderer, int id, SDL_Rect * clip, double angle = 0.0, SDL_Point * center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE)const;
	private:
		TTF_Font * m_font;
		SDL_Texture * m_textures[NUMBER_OF_TTF_TEXTURES];
	};
}

//#endif
