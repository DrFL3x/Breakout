#pragma once

#include "Line.h"
#include <cstdlib>
#include <cmath>
#include <ctime>



#define RADIAN 3.14159f / 180
	


class Ball : public Line
{
public:
	Ball( SDL_Renderer* renderer/* , Line* board */ );
	virtual ~Ball() {};

	void  render() override;
	void move(double deltatime);
	void check_collision();
		
	SDL_FRect& get_geometry();

	float angle;

private:

	SDL_Renderer* ball_renderer;
	SDL_FRect ball;

	Line* board;

	float speed;

};

