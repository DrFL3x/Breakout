#include "Line.h"



//Line::Line(SDL_Renderer * renderer, int x, int y, int width, int height)
//	: renderer(renderer)
//{
//	paddle.x = x;
//	paddle.y = y;
//	paddle.w = width;
//	paddle.h = height;
//}

Line :: Line(SDL_Renderer* renderer, int x, int y, int width, int height)
	: renderer(renderer), paddle{ x,y,width, height}, stop(false)
{}

void Line::render()
{
	//SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 13, 71, 255);		//color used for drawing operations
	SDL_RenderFillRect(renderer,&paddle);
}

	// see inline


 void Line::move_left()
{
	if (!stop )
	paddle.x-=20;

}

void Line::move_right()
{
	if(!stop)
	paddle.x +=20;
}

SDL_Rect Line::get_board()
{
	return paddle;
}

void Line::board_stop() { stop = true; }
void Line::board_resume() { stop = false; }
bool Line::board_is_stopped() { return stop; }





