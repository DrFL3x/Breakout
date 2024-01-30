#pragma once
//#include "SDL_handling.h"
//#include "SDL.h"
#include "Wall.h"

class Game
{
public:

	void set_window();

	//void set_platform();
	//void set_the_ball();

	SDL_handling* game_handler;

	Game() { game_handler = new SDL_handling(); }
	~Game() { delete game_handler; }


private:

};

