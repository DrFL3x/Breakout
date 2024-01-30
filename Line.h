#pragma once

//#include "Game.h"
#include "SDL_handling.h"
#include "SDL.h"
#include <iostream>


class Line
{
public:

	bool stop;

	Line(SDL_Renderer* renderer, int x, int y, int width, int height);
	virtual ~Line() {}; // virtual decons


	// left || right movement func
	
	virtual void render();
	void  move_left(),move_right(), board_stop(), board_resume();
	bool board_is_stopped();



	SDL_Rect get_board();

	template <typename T>
	T calculate_movement(char symbol)
	{
			if (symbol == '+')
				paddle.x +=5;
			else if (symbol == '-')
				paddle.x -= 5;
			else
				std::cout << "Not correct operator" << std::endl;
	}

private:

	SDL_Rect paddle; // rect consists of x,y,w,h
	SDL_Renderer* renderer;

};




