#pragma once

#include "SDL.h"


class SDL_handling
{
public:

	
	int WINDOW_WIDTH = 800;
	int WINDOW_HEIGHT = 800;

	//int SQUARE_SIZE = 100;

	SDL_handling();
	~SDL_handling();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	void initialise_sdl();
	void clean_renderer();
	void init_backorund();

private:

};
