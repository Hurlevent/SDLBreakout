#include "FontTexture.h"

namespace Breakout {

	FontTexture::FontTexture()
	{
		m_texture = nullptr;
		m_font = nullptr;
	}

	void FontTexture::add_file(std::string file)
	{
		m_font_files.push_back(file);
	}


	FontTexture::~FontTexture()
	{
		free();
	}

	bool FontTexture::update_font_texture(SDL_Renderer* renderer, int file_id, const char* text, int font_size, SDL_Color text_color)
	{
		free();

		bool success = true;

		m_font = TTF_OpenFont(m_font_files[file_id].c_str(), font_size);

		if(m_font == nullptr)
		{
			std::cerr << "Failed to open file " << m_font_files[file_id] << "! Error: " << TTF_GetError() << std::endl;
			success = false;

		} else
		{
			SDL_Surface * text_surface = TTF_RenderText_Solid(m_font, text, text_color);

			if(text_surface == nullptr)
			{
				std::cerr << "Failed to render text surface! Error: " << TTF_GetError() << std::endl;
				success = false;
			} else
			{
				m_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
				if(m_texture == nullptr)
				{
					std::cerr << "Failed to create texture from surface! Error: " << SDL_GetError() << std::endl;
					success = false;
				}
				SDL_FreeSurface(text_surface);
			}
		}
		return success;
	}

	void FontTexture::free()
	{
		if(m_font != nullptr)
		{
			TTF_CloseFont(m_font);
			m_font = nullptr;

			if(m_texture != nullptr)
			{
				SDL_DestroyTexture(m_texture);
				m_texture = nullptr;

			}
		}
	}

	void FontTexture::render(SDL_Renderer* renderer, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) const
	{
		if(m_texture != nullptr && clip != nullptr)
		{
			SDL_RenderCopyEx(renderer, m_texture, clip, nullptr, angle, center, flip);
		} else
		{
			std::cerr << "Failed to rebnder TTF texture!" << std::endl;
		}
	}

}