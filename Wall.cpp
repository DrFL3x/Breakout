#include "Wall.h"



Wall::Wall(SDL_Renderer* renderer)
	: Line(renderer, 100, 700, 100, 30),
	wall_renderer(renderer),
	left_wall{ 0, 0, 20, 800 },
	right_wall{ 780, 0, 20, 800 }, 
	up_wall{ 0, 0, 800, 20 },
	down_wall{ 0, 780, 800, 20 }
{

}

void Wall::render(){

		SDL_SetRenderDrawColor( wall_renderer, 255, 255, 255, 255);		
		SDL_RenderFillRect(wall_renderer, &right_wall);
			
		SDL_SetRenderDrawColor(wall_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(wall_renderer, &up_wall);

		SDL_SetRenderDrawColor(wall_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(wall_renderer, &left_wall);

		SDL_SetRenderDrawColor(wall_renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(wall_renderer, &down_wall);
}

SDL_Rect Wall::get_left_w() { return left_wall;}

SDL_Rect Wall::get_right_w() { return right_wall;}