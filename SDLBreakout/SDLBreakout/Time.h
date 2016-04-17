#ifndef TIME
#define TIME

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif


// This is the "Advanced Timer" from the lazyfoo tutorials

namespace Breakout {
	class Time
	{
	public:
		Time();
		~Time();
        
        void Start();
        void Stop();
        void Pause();
        void Continue();
        
        Uint32 GetElapsedTime() const;
		double GetFps() const;
		double GetDeltatime() const;

		int GetFrames() const;

		void UpdateDeltatime();
		void DecDeltatime();
		void UpdateFps();
        
        bool IsStarted(){ return running; };
        bool Paused(){ return running && paused; };

	private:
        Uint32 start_time;
        Uint32 paused_time;
        bool running;
        bool paused;

		double m_delta;
		int m_counted_frames;
		double m_fps;


		Uint32 lastTime;
		double msPerTick;

		int m_ticks;

		double m_deltaTime;

	};
}
#endif