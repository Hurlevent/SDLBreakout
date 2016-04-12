#include "FontTexture.h"

namespace Breakout {

	FontTexture::FontTexture()
	{
		m_font = nullptr;
	}


	FontTexture::~FontTexture()
	{
		if(m_font != nullptr)
		{
			TTF_CloseFont(m_font);
		}

		free();
	}

	bool FontTexture::load_font_from_file(const char* filepath, int text_size)
	{
		if(m_font != nullptr)
		{
			TTF_CloseFont(m_font);
			m_font = nullptr;
		}
		m_font = TTF_OpenFont(filepath, text_size);
		return m_font != nullptr;
	}


	bool FontTexture::update_font_texture(SDL_Renderer* renderer, int id, const char* text, SDL_Color text_color)
	{


		bool success = true;

		SDL_Surface * text_surface = TTF_RenderText_Solid(m_font, text, text_color);

		if(text_surface == nullptr)
		{
			std::cerr << "Failed to render text surface! Error: " << TTF_GetError() << std::endl;
			success = false;
		} else
		{
			SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, text_surface);
			if(texture == nullptr)
			{
				std::cerr << "Failed to create texture from surface! Error: " << SDL_GetError() << std::endl;
				success = false;
			} else
			{
				if(m_textures[id] != nullptr)
				{
					SDL_DestroyTexture(m_textures[id]);
				}

				m_textures[id] = texture;
			}
			SDL_FreeSurface(text_surface);
		}
		return success;
	}

	void FontTexture::free()
	{
		for (int i = 0; i < NUMBER_OF_TTF_TEXTURES; i++)
		{
			SDL_DestroyTexture(m_textures[i]);
			m_textures[i] = nullptr;
		}
	}

	void FontTexture::render(SDL_Renderer* renderer, int id, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) const
	{
		if(m_textures[id] != nullptr && clip != nullptr)
		{
			SDL_RenderCopyEx(renderer, m_textures[id], nullptr, clip, angle, center, flip);
		} else
		{
			std::cerr << "Failed to rebnder TTF texture!" << std::endl;
		}
	}

}