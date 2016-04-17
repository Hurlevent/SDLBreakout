// This class listens to input events

#ifndef INPUTMANAGER
#define INPUTMANAGER

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif
namespace Breakout {
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();

        void handle_input_events();
		bool handle_mouse_events()const;
		
		void get_mouse_position(SDL_Point & position)const;

        void clear_flags();
        bool get_flag_up() const {return up;}
        bool get_flag_down() const{return down;}
        bool get_flag_left() const{return left;}
        bool get_flag_right() const{return right;}
        bool get_flag_space() const{return space;}
        bool get_flag_escape() const{return escape;}
        bool get_flag_quit() const{return quit;}


    private:
        bool up;
        bool down;
        bool left;
        bool right;
        bool space;
        bool escape;
        bool quit;
        SDL_Event evntHandler;
    };
}

#endif