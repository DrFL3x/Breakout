#pragma once
#include"Line.h"


class Wall : public Line
{
public:

	Wall( SDL_Renderer* renderer );
	~Wall() {};

	void render() override;
	//void render_wall( Line* object);

	SDL_Rect get_left_w();
	SDL_Rect get_right_w();


private:

	SDL_Rect left_wall, right_wall, up_wall, down_wall;
	SDL_Renderer* wall_renderer;

};



