//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "../Header/InputManager.h"

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
					case SDLK_RCTRL|SDLK_SPACE:
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

	bool InputManager::handle_mouse_events()const
	{
		bool mouseDown = false;
		if (evntHandler.type == SDL_MOUSEBUTTONDOWN)
		{

			if (evntHandler.button.button == SDL_BUTTON_LEFT) {
				mouseDown = true;
			}
		}
		return mouseDown;
		
	}

	void InputManager::get_mouse_position(SDL_Point& position) const
	{
		SDL_GetMouseState(&position.x, &position.y);
	}
	    
	// sets all flags to false
    void InputManager::clear_flags()
    {
        for (auto i = &up; i <= &quit; i++) {
				*i = false;
        }
        
    }
}


