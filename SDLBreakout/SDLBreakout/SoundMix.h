
#include <SDL.h>
#include <string>
#include <cmath>
#include <iostream>
#include "SDL_mixer.h"
#ifndef SoundMix_h
#define SoundMix_h


namespace Breakout {
	class SoundMix{
	public:
		SoundMix();
		~SoundMix();
		bool loadSound(std::string nameSound);
		void playSound();
		
	private:
		//Dette er for lyder ikke musikk
		Mix_Chunk *SoundEffect;

	};
}
#endif // ! SoundMix_h