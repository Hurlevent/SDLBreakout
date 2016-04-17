#include "Time.h"

namespace Breakout {

	Time::Time()
	{
        start_time = 0;
        paused_time = 0;

        running = false;
        paused = false;
		
		m_counted_frames = 0;
		m_fps = 0;

		// Refactored time
		lastTime = 0;
		msPerTick = 1000 / 60;

		m_ticks = 0;

		m_deltaTime = 0;


	}


	Time::~Time()
	{
	}
    
    void Time::Start(){
        running = true;
        paused = false;
        lastTime = start_time = SDL_GetTicks();
        paused_time = 0;
		m_fps = 1;


    }
    
    
    void Time::Stop(){
        running = false;
        paused = false;
        start_time = 0;
        paused_time = 0;
		m_counted_frames = 0;
    }
    
    void Time::Pause(){
        if(running && !paused){
            paused = true;
            
            paused_time = SDL_GetTicks() - start_time;
            
            start_time = 0;
        }
    }
    
    void Time::Continue(){
        if(running && paused){
            paused = false;
            
            start_time = SDL_GetTicks() - paused_time;
            
            paused_time = 0;
        }
    }
    
    Uint32 Time::GetElapsedTime() const{
        
        Uint32 time = 0;
        
        if(running){
            if(paused){
                time = paused_time;
            } else {
                time = SDL_GetTicks() - start_time;
            }
        }
        return time;
    }

	
	double Time::GetFps() const
	{
		return m_fps;
	}

	double Time::GetDeltatime() const
	{
		return m_deltaTime;
	}

	int Time::GetFrames() const
	{
		return m_counted_frames;
	}

	void Time::UpdateDeltatime()
	{
		Uint32 now = SDL_GetTicks();
		m_deltaTime += (now - lastTime) / msPerTick;
		lastTime = now;
	}

	void Time::DecDeltatime()
	{
		m_deltaTime -= 1;
	}

	void Time::UpdateFps()
	{
		if (!paused) {
			m_counted_frames++;
		}
		
		double elapsed_ms = static_cast<double>(SDL_GetTicks() - start_time);

		double elapsed_secounds = elapsed_ms / 1000.0;

		m_fps = m_counted_frames / elapsed_secounds;

		
	}




}