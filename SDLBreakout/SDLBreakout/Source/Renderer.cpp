#include "../Header/Renderer.h"

namespace Breakout {

	/////////////////////////////////////////////////
	// START OF UTIL FUNCTIONS
	/////////////////////////////////////////////////

	SDL_Texture * load_texture(std::string path, SDL_Renderer * renderer)
	{
		//The final texture
		SDL_Texture * new_texture = nullptr;

		//Load image at specified path
		SDL_Surface * loaded_surface = IMG_Load(path.c_str());
		if (loaded_surface == nullptr)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			//Create texture from surface pixels
			new_texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
			if (new_texture == nullptr)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loaded_surface);
		}

		return new_texture;
	}

	bool load_media(SDL_Renderer * renderer, std::vector<std::shared_ptr<SDL_Texture *>> &sprite_textures, FontTexture * font_textures, int font_size)
	{
		bool success = true;

		DIR * dir = nullptr;

		struct dirent * ent = nullptr;

		const char * sprites_directory = "Sprites/";

		if ((dir = opendir(sprites_directory))) { // Det er viktig at working directory er satt riktig!

			while ((ent = readdir(dir))) { // Read all files from directory

				std::string filename = ent->d_name;

				if (filename[0] != '.') { // if file is not "hidden"
					std::cout << "Found file: " << filename.c_str() << std::endl;

					SDL_Texture * texture = load_texture(sprites_directory + filename, renderer);

					if (texture == nullptr) {

						success = false;

					}
					else {

						sprite_textures.push_back(std::make_shared<SDL_Texture *>(texture));
					}
				}
			}

			closedir(dir);

			dir = nullptr;
			ent = nullptr;

		}
		else
		{
			std::cerr << "Failed to open directory: " << sprites_directory << std::endl;
			success = false;
		}

		std::string ttf_directory = "TTF/";

		if ((dir = opendir(ttf_directory.c_str()))) {

			while ((ent = readdir(dir))) {

				std::string filename = ent->d_name;

				if (filename[0] != '.') { // We don't want to read hidden files

					std::cout << "Found file: " << filename.c_str() << std::endl;

					if (!font_textures->load_font_from_file((ttf_directory + filename).c_str(), font_size)) {

						std::cerr << "Failed to load TTF! Error: " << TTF_GetError() << std::endl;
						success = false;

					}
				}
			}

			closedir(dir);
			dir = nullptr;
			ent = nullptr;

		}
		else {

			std::cerr << "Failed to open directory " << ttf_directory.c_str() << std::endl;
			success = false;
		}

		return success;
	}

	void init_timer(Timer * timer, int * counted_frames) {

		timer->start();
		*counted_frames = 0;
	}

	/////////////////////////////////////////////////
	//	CONSTRUCTOR AND DESTRUCTOR
	/////////////////////////////////////////////////

	Renderer::Renderer(const Window * window, int font_size) : m_font_size(font_size)
	{
		m_renderer = nullptr;

		m_renderer = SDL_CreateRenderer(window->get_window(), -1, SDL_RENDERER_ACCELERATED);

		if(m_renderer == nullptr)
		{
			std::cerr << "Error: " << SDL_GetError() << std::endl;
			throw "Failed to create renderer!";
		} 
		
		SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		std::cout << "Created renderer!" << std::endl;

		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags)) {
			std::cerr << "Error: " << IMG_GetError() << std::endl;
			throw "Failed to initialize SDL2_Image";
		}

		if(TTF_Init() == -1)
		{
			std::cerr << "Error: " << TTF_GetError() << std::endl;
			throw "Failed to initialize SDL2_TTF";
		}

		m_font_texture_creator = new FontTexture();

		if(!load_media(m_renderer, m_sprites, m_font_texture_creator, m_font_size))
		{
			throw "Failed to load resource files!";
		}

		std::cout << "Loaded sprites!" << std::endl;

		m_window_width = window->get_width();
		m_window_height = window->get_height();

		//init_timer(&m_timer, &m_counted_frames);
	}



	Renderer::~Renderer()
	{
		for (std::vector<std::shared_ptr<SDL_Texture *>>::iterator iter = m_sprites.begin(); iter != m_sprites.end(); ++iter) {
			SDL_DestroyTexture(**iter);
		}

		delete m_font_texture_creator;
		m_font_texture_creator = nullptr;

		SDL_DestroyRenderer(m_renderer);

		IMG_Quit();
		TTF_Quit();
	}

	/////////////////////////////////////////////////
	// START OF RENDERING RELATED FUNCTIONS
	/////////////////////////////////////////////////

	void Renderer::render_texture(int id, const SDL_Rect * clip, const SDL_Rect * viewport) const
	{
		//Set rendering space to screen
		SDL_Rect renderQuad = { 0, 0, m_window_width, m_window_height };

		//Set clip rendering dimensions
		if (clip != nullptr)
		{
			renderQuad.x = clip->x;
			renderQuad.y = clip->y;
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		// if viewport is null, we set viewport to be the entire window
		if (viewport == nullptr) {
			SDL_Rect wholescreen{ 0, 0, m_window_width, m_window_height };
			viewport = &wholescreen;
			SDL_RenderSetViewport(m_renderer, viewport);
		}
		else {
			SDL_RenderSetViewport(m_renderer, viewport);
		}

		//Render to screen
		SDL_RenderCopy(m_renderer, *(m_sprites[id]), nullptr, &renderQuad);
	}

	void Renderer::render_font_texture(int id, const SDL_Rect* clip, const SDL_Rect* viewport) const
	{
		SDL_Rect renderQuad{ 0, 0, m_window_width, m_window_height };

		if (clip != nullptr)
		{
			renderQuad.x = clip->x;
			renderQuad.y = clip->y;
			renderQuad.w = clip->w;
			renderQuad.h = clip->h;
		}

		if (viewport == nullptr)
		{
			SDL_Rect wholescreen{ 0, 0, m_window_width, m_window_height };
			viewport = &wholescreen;
			SDL_RenderSetViewport(m_renderer, viewport);
		}
		else
		{
			SDL_RenderSetViewport(m_renderer, viewport);
		}
		m_font_texture_creator->render(m_renderer, id, &renderQuad);
	}

	void Renderer::update_font_texture_text(int id, std::string text, SDL_Color text_color) const
	{
		if (!m_font_texture_creator->update_font_texture(m_renderer, id, text.c_str(), text_color))
		{
			std::cerr << "Failed to create texture from TTF!" << std::endl;
		}
	}
	
	void Renderer::set_render_color_on_mouse(int id, uint8_t r, uint8_t g, uint8_t b) const
	{
		SDL_SetTextureColorMod(*m_sprites[id], r, g, b);
	}

	void Renderer::render_present() const
	{
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::set_render_draw_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) const
	{
		SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
	}

	void Renderer::clear_render() const
	{
		SDL_RenderClear(m_renderer);
	}


	/////////////////////////////////////////////////
	// START OF TIME RELATED FUNCTIONS
	/////////////////////////////////////////////////

	/*
	void Renderer::capture_end_of_frame()
	{
		m_delta_time = static_cast<int>(SDL_GetTicks()) - m_time_start_of_frame;
		m_counted_frames++;
	}
	void Renderer::capture_start_of_frame()
	{
		m_time_start_of_frame = static_cast<int>(SDL_GetTicks());
	}
	*/
	/*
	void Renderer::reset_fps()
	{
		m_timer.stop();
		init_timer(&m_timer, &m_counted_frames);
	}

	double Renderer::get_fps() const
	{
		double fps = m_counted_frames / (m_timer.elapsed_time() / 1000.f);
		if (fps > 0xFFFFFFFF) {
			fps = -1;
		}
		return fps;
	}

	*/
}