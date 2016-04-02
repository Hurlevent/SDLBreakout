#ifndef TIMER
#define TIMER

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif


// This is the "Advanced Timer" from the lazyfoo tutorials

namespace Breakout {
	class Timer
	{
	public:
		Timer();
		~Timer();
        
        void start();
        void stop();
        void pause();
        void unpause();
        
        int elapsed_time() const;
        
        bool is_started(){return started;};
        bool is_paused(){return started && paused;};
	private:
        int start_time;
        int paused_time;
        bool started;
        bool paused;
	};
}
#endif