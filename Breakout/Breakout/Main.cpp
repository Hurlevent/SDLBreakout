#include <SDL.h>
#include <iostream>
#include "InputManager.h"
#include "Window.h"

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 1024;

int main(int argc, char ** argv)
{
	try {
		Breakout::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	catch (const char * msg) {
		std::cerr << msg << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}

	Breakout::InputManager input;
	while (!input.GetFlagQuit()) // Intended to be the main game loop
	{
		input.HandleInputEvents();
		SDL_Delay(3000);
	}

	return EXIT_SUCCESS;
}