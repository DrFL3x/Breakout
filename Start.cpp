#include "Start.h"
#include "Collision.h"
#include "Ball.h"
#include "Bricks.h"
#include <intrin.h>

int score = 0;


void Start::Run()
{

	// first set window
	Game* start_handler = new Game();
	start_handler->set_window();

	// main objects

	Wall wall(start_handler->game_handler->renderer);
	Line line(start_handler->game_handler->renderer,340, 700, 100, 30);
	Ball ball(start_handler->game_handler->renderer);
	Bricks brick(start_handler->game_handler->renderer);

	Collision collision(&line,&wall, &ball, &brick); 

	Bricks* field[60] = {0};


	for (int i = 0; i < BLOCKS_NUM; i++)
	{
		field[i] = new Bricks(start_handler->game_handler->renderer);
	}


	///// Init the SDL_ttf
	TTF_Init();

	// load the font
	

	TTF_Font* game_font = TTF_OpenFont("C:/Users/Eugen/Desktop/ProjeXt/Breakout/x64/Debug/arcadeclassic.ttf", 72);

	if (!game_font) 
	{
		SDL_GetError();
		std::cout << "not good path, :" << TTF_GetError() << std::endl;
	}


	
	bool quit = false;
	SDL_Event e;

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	//////////////////
	/// Game_looop ///
	//////////////////

	while (!quit)
	{


		collision.check_collision();

		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;
			

			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym){

				case SDLK_LEFT:

					//line.calculate_movement<void>('-');

					collision.check_collision();
					line.move_left();
					break;

				case SDLK_RIGHT:


					collision.check_collision();
					line.move_right();
					break;

				//case SDLK_SPACE:
				//__debugbreak();
				//break;
				}
			}

		}




		start_handler->game_handler->init_backorund();
		wall.render();
		line.render();

		//////////////////////
		// initalise bricks //
		//////////////////////

		//starting coordinates
		int x_offset = 50, y_offset =  200;

		for (int i = 0; i < BLOCKS_NUM ; ++i) 
		{
			if (field[i] != NULL)
			{ 
				field[i]->place_rectangle(x_offset,y_offset, 40 ,15);
				field[i]->render(22 + i * 99, 44 + i * 10, 33 + i * 6, 255);
			}


			x_offset += 72; 
			if (x_offset > 700) 
			{
				y_offset += 40; //move down
				x_offset = 50;  //reset x offset
			}
		}
		
		ball.check_collision();

		// now calculate time - delta
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());


		ball.move( deltaTime); 
		ball.render();

		score=collision.check_bricks_collision(field, start_handler->game_handler->renderer, game_font, score);
		
		collision.renderScoreText(start_handler->game_handler->renderer,game_font, score); 

		SDL_RenderPresent(start_handler->game_handler->renderer);

	}

	start_handler->game_handler->clean_renderer();

	//delete start_handler;
}


