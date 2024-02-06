#pragma once

#include "SDL_mixer.h" 
#include "SDL.h"
#include <iostream>

class Audio
{
public:

	Audio();
	~Audio();

	Mix_Chunk* load_sound(std:: string musicpath);
	void play_sound(std::string musicpath);


private:
	Mix_Chunk* soundEffect;

};
