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
        
        Uint32 elapsed_time() const;
		double get_fps()const;

		void set_delta(double delta);
		void dec_delta();

		void set_frames(int frames);
		int get_frames()const;
		void update();
        
        bool is_started(){return started;};
        bool is_paused(){return started && paused;};
	private:
        Uint32 start_time;
        Uint32 paused_time;
        bool started;
        bool paused;

		double m_delta;
		int m_counted_frames;
		double m_fps;
	};
}
#endif