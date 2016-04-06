#include "InputManager.h"

namespace Breakout {
    
    
    
    InputManager::InputManager()
    {
		clear_flags();
    }
    
    
    InputManager::~InputManager()
    {
    }
    
    void InputManager::handle_input_events()
    {
        
        while(SDL_PollEvent(&evntHandler) != 0){
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
			else {
                clear_flags();
			}    
        }
    }
    
    
    
    void InputManager::clear_flags()
    {
        // Should hopefully set all the flags to flase. i must be initialized to the first flag,
        // and must not be greater than the last flag.
        for (bool * i = &up; i <= &quit; i++) {
				*i = false;
        }
        
    }
}


