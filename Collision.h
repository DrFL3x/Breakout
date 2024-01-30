#pragma once

#include "Wall.h"
#include "Ball.h"
#include "Bricks.h"

class Collision
{
public:
	Collision(Line* paddle, Wall* wall, Ball* ball, Bricks* brick)
		: board(paddle), wall(wall), ball(ball), brick(brick)
	{}
	~Collision() {}

	void check_collision();
	void check_bricks_collision(Bricks* field[], SDL_Renderer* renderer);
	void renderScoreText(SDL_Renderer* renderer, int score);

	Wall* wall;
	Line* board;
	Ball* ball;
	Bricks* brick;


private:


};

