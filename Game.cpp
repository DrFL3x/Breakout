#include "Game.h"



void Game::set_window()
{
	game_handler->initialise_sdl();
	game_handler->init_backorund();
}
