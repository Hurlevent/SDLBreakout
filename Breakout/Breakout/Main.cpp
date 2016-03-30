#include <SDL.h>
#include <iostream>
#include "InputManager.h"

int main(int argc, char **argv)
{
	InputManager *input = new InputManager(); // Could be placed on stack instead
	
	// main game loop (by all means not finished)
	while (!input->GetFlagQuit) {
		input->HandleInputEvents();

	}

	delete input;

	return EXIT_SUCCESS;
}