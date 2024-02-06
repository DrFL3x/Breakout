#pragma once

#include "Wall.h"
#include "Ball.h"
#include "Bricks.h"
#include "SDL_ttf.h"
#include "Audio.h"



class Collision
{
public:
	Collision(Line* paddle, Wall* wall, Ball* ball, Bricks* brick)
		: board(paddle), wall(wall), ball(ball), brick(brick)
	{}
	~Collision() {}

	void check_collision();
	int  check_bricks_collision(Bricks* field[], SDL_Renderer* renderer, TTF_Font* font, int score);
	void renderScoreText(SDL_Renderer* renderer, TTF_Font* font,int score);
	void renderGameOverText(SDL_Renderer* renderer, TTF_Font* font);

	Wall* wall;
	Line* board;
	Ball* ball;
	Bricks* brick;


private:
	Audio audio;


};

