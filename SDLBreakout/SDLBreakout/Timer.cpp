#include "Timer.h"

namespace Breakout {

	Timer::Timer()
	{
        start_time = 0;
        paused_time = 0;
        started = false;
        paused = false;
		m_counted_frames = 0;
		m_fps = 0;
	}


	Timer::~Timer()
	{
	}
    
    void Timer::start(){
        started = true;
        paused = false;
        start_time = SDL_GetTicks();
        paused_time = 0;
		m_fps = 1;
    }
    
    
    void Timer::stop(){
        started = false;
        paused = false;
        start_time = 0;
        paused_time = 0;
		m_counted_frames = 0;
    }
    
    void Timer::pause(){
        if(started && !paused){
            paused = true;
            
            paused_time = SDL_GetTicks() - start_time;
            
            start_time = 0;
        }
    }
    
    void Timer::unpause(){
        if(started && paused){
            paused = false;
            
            start_time = SDL_GetTicks() - paused_time;
            
            paused_time = 0;
        }
    }
    
    Uint32 Timer::elapsed_time() const{
        
        Uint32 time = 0;
        
        if(started){
            if(paused){
                time = paused_time;
            } else {
                time = SDL_GetTicks() - start_time;
            }
        }
        return time;
    }

	
	double Timer::get_fps() const
	{
		return m_fps;
	}

	double Timer::get_delta() const
	{
		//return m_delta;

		return 3.0; // THIS IS HOW THE PADDLE IS CURRENTLY MOVING!!! WE NEED TO CHANGE THIS!
	}

	void Timer::set_delta(double delta)
	{
		m_delta = delta;
	}

	// Decrements the delta_time
	void Timer::dec_delta()
	{
		m_delta--;
	}

	void Timer::set_frames(int frames)
	{
		m_counted_frames = frames;
	}

	int Timer::get_frames() const
	{
		return m_counted_frames;
	}

	void Timer::update()
	{
		if (!paused) {
			m_counted_frames++;
		}
		
		double elapsed_ms = static_cast<double>(SDL_GetTicks() - start_time);

		double elapsed_secounds = elapsed_ms / 1000.0;

		m_fps = m_counted_frames / elapsed_secounds;
	}




}