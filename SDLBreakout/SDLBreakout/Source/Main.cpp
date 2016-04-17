//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#endif


#include <iostream>
#include "../Header/GameManager.h"
#include <memory>
#include "../Header/InputManager.h"
#include "../Header/Window.hpp"
#include "../Header/CompositeRenderable.h"
#include "../Header/Paddle.hpp"
#include "../Header/Brick.hpp"
#include "../Header/Statusbar.hpp"
#include "../Header/Menu.h"
#include "../Header/Ball.h"

#include "../Header/BrickContainer.hpp"
#include <vld.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;
static const int STATUSBAR_HEIGHT = 50;

int main(int argc, char ** argv) {
    
		Breakout::GameManager gm(WINDOW_WIDTH, WINDOW_HEIGHT, STATUSBAR_HEIGHT);
		gm.run_gameloop();

   
	system("pause");
    
    return EXIT_SUCCESS;
}
