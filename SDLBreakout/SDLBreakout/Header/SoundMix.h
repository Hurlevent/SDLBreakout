//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include <SDL.h>
#include <string>
#include <cmath>
#include <iostream>
#include "SDL_mixer.h"
#ifndef SoundMix_h
#define SoundMix_h

// This class allows us to play sounds
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