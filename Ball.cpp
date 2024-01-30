#include "Ball.h"



Ball::Ball(SDL_Renderer* renderer /* , Line* board */)
	: Line(renderer, 100, 700, 100, 30), ball_renderer(renderer), ball{500,500,15,15}, speed(0.2), board(board)
{
    srand(static_cast<unsigned int>(time(nullptr))); // Seed random number generator
    angle = (rand() % 90) * RADIAN;
}


void Ball::render()
{
	SDL_SetRenderDrawColor(ball_renderer, 255, 255, 255, 255);
	SDL_RenderFillRectF(ball_renderer, &ball);
}

SDL_FRect& Ball::get_geometry() 
{
    return ball; // return before object die !
}


void Ball::move(double deltaTime)
{
    
    //speed *= 1.00005f;
    //if (speed >= 2.0f) speed = 2.0f;

    double moveX = speed * cos(angle) * deltaTime;
    double moveY = speed * sin(angle) * deltaTime;

    ball.x += moveX;
    ball.y += moveY;
}

// makes ball bounce around

void Ball::check_collision()
{
  
     if (ball.x <= 20 || ball.x + ball.w >= 780)
        angle = 3.14f - angle; // Reflect the ball on horizontal walls

     /*if(ball.y + ball.h == board->get_board().y && ball.x > board->get_board().x && ball.x < board->get_board().x + board->get_board().w  )
       angle = -angle; */

    if (ball.y <= 20)
        angle =- angle; // Reflect the ball on upper vertical wall

}

// float Ball::get_angle() { return angle };






