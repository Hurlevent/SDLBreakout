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


static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;
static const int STATUSBAR_HEIGHT = 50;

int main(int argc, char ** argv) {
    
    try{
		
		Breakout::GameManager gm(WINDOW_WIDTH, WINDOW_HEIGHT, STATUSBAR_HEIGHT);
		gm.run_gameloop();


    } catch(const char * msg){
        
        std::cerr << msg << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    
   
	system("pause");
    
    return EXIT_SUCCESS;
}

// our old main is pasted below

// viewport for our game-board
/* SDL_Rect gameboard_viewport{0, STATUSBAR_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT - STATUSBAR_HEIGHT};
SDL_Rect statusbar_viewport{0, 0, WINDOW_WIDTH, STATUSBAR_HEIGHT};

Breakout::Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
Breakout::InputManager input;
Breakout::CompositeRenderable game_objects;
Breakout::Menu start(WINDOW_WIDTH, WINDOW_HEIGHT, 2);

Breakout::Ball ball(&gameboard_viewport, WINDOW_WIDTH, WINDOW_HEIGHT);
Breakout::Paddle paddle(&ball, (gameboard_viewport.w - 50) / 2, gameboard_viewport.h - 50);
paddle.set_speed(10);
paddle.set_viewport(&gameboard_viewport);

Breakout::Statusbar statusbar(&statusbar_viewport);
statusbar.set_viewport(&statusbar_viewport);

Breakout::BrickContainer bricks(gameboard_viewport.w, gameboard_viewport.h, 5, 10, 20);
bricks.set_viewport(&gameboard_viewport);

game_objects.add(dynamic_cast<GameObject *>(&paddle));
game_objects.add(dynamic_cast<GameObject *>(&bricks));
game_objects.add(dynamic_cast<GameObject *>(&statusbar));
game_objects.add(dynamic_cast<GameObject *>(&ball));

while (!input.get_flag_quit()) { // this is supposed to be the main game-loop


window.capture_start_of_frame();

// Reads input events from user
input.handle_input_events();

// Clears the renderer
window.set_render_draw_color(0xFF, 0xFF, 0xFF, 0xFF);
window.clear_render();

if (start.get_view() == 0 ) {

//Button = menu.GetClick(&window, &input);
start.render_object(&window, &input);

}
else {


// tells the renderer to render all game_objects
game_objects.render_object(&window, &input);
ball.SetForce();
ball.wall_collision();

paddle.handleBall();
//Her inneholder alle bildene
//window.render_texture(1);


// makes the renderer actually draw a picture on screen

window.render_present();


//Hvis du trykker escape så går du tilbake til menyen
if (input.get_flag_escape() == true) {
start.set_view(0);
}
}
// makes the renderer actually draw a picture on screen

window.render_present();

// Update delta_time
window.capture_end_of_frame();
}*/