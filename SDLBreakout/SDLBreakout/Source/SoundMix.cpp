//
//  Created by Oliver Eftevaag, Alexander Larsen & Gunnar A. Holst
//	04.2016
//  Copyright © 2016 SDLBreakout. All rights reserved.
//

#include "../Header/SoundMix.h"
#include <iostream>

namespace Breakout {

	SoundMix::SoundMix()
	{
		SoundEffect = nullptr;
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			std::cout << "ERROR: " << Mix_GetError() << std::endl;
		}

	}
	SoundMix::~SoundMix()
	{
		Mix_FreeChunk(SoundEffect);
		Mix_CloseAudio();
		Mix_Quit();
		SoundEffect = nullptr;
	}
	bool SoundMix::loadSound(std::string nameSound)
	{
		bool load = true;
		std::string path = "Sounds/" + nameSound + ".wav";
		SoundEffect = Mix_LoadWAV(path.c_str());
		if (SoundEffect == nullptr) {
			load = false;
		}
		return load;
	}

	void SoundMix::playSound()
	{
		Mix_PlayChannel(-1,SoundEffect, 0);
	}
}