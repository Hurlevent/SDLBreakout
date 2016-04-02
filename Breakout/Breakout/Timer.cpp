#include "Timer.h"

namespace Breakout {

	Timer::Timer()
	{
        start_time = 0;
        paused_time = 0;
        started = false;
        paused = false;
	}


	Timer::~Timer()
	{
	}
    
    void Timer::start(){
        started = true;
        paused = false;
        start_time = static_cast<int>(SDL_GetTicks());
        paused_time = 0;
    }
    
    
    void Timer::stop(){
        started = false;
        paused = false;
        start_time = 0;
        paused_time = 0;
    }
    
    void Timer::pause(){
        if(started && !paused){
            paused = true;
            
            paused_time = static_cast<int>(SDL_GetTicks()) - start_time;
            
            start_time = 0;
        }
    }
    
    void Timer::unpause(){
        if(started && paused){
            paused = false;
            
            start_time = static_cast<int>(SDL_GetTicks()) - paused_time;
            
            paused_time = 0;
        }
    }
    
    int Timer::elapsed_time() const{
        
        int time = 0;
        
        if(started){
            if(paused){
                time = paused_time;
            } else {
                time = static_cast<int>(SDL_GetTicks()) - start_time;
            }
        }
        return time;
    }
}