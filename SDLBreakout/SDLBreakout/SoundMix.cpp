#include "SoundMix.h"
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

	void SoundMix::stopSound()
	{
		
	}


}