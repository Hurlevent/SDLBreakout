#ifndef WINDOW
#define WINDOW
#include <SDL.h>
namespace Breakout {

	class Window
	{
	public:
		Window();
		Window(const int width, const int height);
		~Window();
		int get_height() { return _height; }
		int get_width() { return _width; }
	private:
		int _width;
		int _height;
		SDL_Window * _window;
		SDL_Renderer * _renderer;
		const int default_width = 1024;
		const int default_height = 1024;
	};
}
#endif
