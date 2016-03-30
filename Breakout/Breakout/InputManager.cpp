#include "InputManager.h"

namespace Breakout {



	InputManager::InputManager()
	{
	}


	InputManager::~InputManager()
	{
	}

	void InputManager::HandleInputEvents()
	{
		ClearFlags();

		while (SDL_PollEvent(&evntHandler) != 0) {
			if (evntHandler.type == SDL_QUIT) {
				quit = true;
			}
			else if (evntHandler.type == SDL_KEYDOWN) {
				switch (evntHandler.key.keysym.sym)
				{
				case SDLK_UP:
					up = true;
					break;
				case SDLK_DOWN:
					down = true;
					break;
				case SDLK_LEFT:
					left = true;
					break;
				case SDLK_RIGHT:
					right = true;
					break;
				case SDLK_SPACE:
					space = true;
					break;
				case SDLK_ESCAPE:
					escape = true;
					break;
				default:
					break;
				}
			}

		}
	}

	void InputManager::ClearFlags()
	{
		// Should hopefully set all the flags to flase. i must be initialized to the first flag,
		// and must not be greater than the last flag.
		for (bool *i = &up; i <= &quit; i++) {
			*i = false;
		}
	}

	bool InputManager::GetFlagUp() const
	{
		return up;
	}

	bool InputManager::GetFlagDown() const
	{
		return down;
	}

	bool InputManager::GetFlagLeft() const
	{
		return left;
	}

	bool InputManager::GetFlagRight() const
	{
		return right;
	}

	bool InputManager::GetFlagSpace() const
	{
		return space;
	}

	bool InputManager::GetFlagEscape() const
	{
		return escape;
	}

	bool InputManager::GetFlagQuit() const
	{
		return quit;
	}
}