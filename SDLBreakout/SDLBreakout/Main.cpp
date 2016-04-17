//
//  main.cpp
//  SDLBreakout
//
//  Created by Oliver Eftevaag on 31.03.2016.
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
#include "GameManager.h"
#include <memory>
#include "InputManager.h"
#include "Window.hpp"
#include "CompositeRenderable.h"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "Statusbar.hpp"
#include "Menu.h"
#include "Ball.h"

#include "BrickContainer.hpp"
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
