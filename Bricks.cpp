#include "Bricks.h"


void Bricks::print_brick_data()
{
    // Not working
	ParseData parsemee;
	parsemee.leveldata = parsemee.parseLevel("C:/Users/Eugen/Desktop/Levels.xml");
}

//void Bricks::create_pattern(/*int level_flag*/)
//{
//    for (int i = 0; i < BLOCKS_NUM; i++)
//    {
//        field[i] = new Bricks(brick_renderer);
//    }
//
//}




//void Bricks::place_blocks() 
//
//{
//
//    int x_offset = 50, y_offset =  200; //starting coordinates
//
//    for (int i = 0; i < BLOCKS_NUM ; ++i) {
//        if(field[i]!=NULL)
//        field[i]->place_rectangle(x_offset,y_offset, 40 ,15);
//        field[i]->render(22 + i * 99, 44 + i * 10, 33 + i * 6, 255);
//
//        x_offset += 72; 
//        if (x_offset > 700) {
//            y_offset += 40; //move down
//            x_offset = 50; //reset x offset
//        }
//    }
//}

void Bricks::place_rectangle(int x, int y, int w, int h)
{
    one_brick.x = x;
    one_brick.y = y;
    one_brick.w = w;
    one_brick.h = h;
}

void Bricks::render(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
        SDL_SetRenderDrawColor(brick_renderer, r, g, b, a);
        SDL_RenderFillRect(brick_renderer, &one_brick);
}

bool Bricks::ball_brick_collided(SDL_FRect& ball, SDL_Rect& brick)
	{
#if 0
		float HorizontalEdges = ball.x;
		float VerticalEdges = ball.y;

		//check to see if ball or brick edge is closer
		if (ball.x < brick.x) {
			HorizontalEdges = brick.x; //try left edges
		}
		else if (ball.x > brick.x + brick.w) {
			HorizontalEdges = brick.x + brick.w; //try right edges
		}

		if (ball.y < brick.y) {
			VerticalEdges = brick.y; //top edges
		}
		else if (ball.y > brick.y + brick.h) {
			VerticalEdges = brick.y + brick.h; //bottom edges
		}

		//get distance from closest edges
		float distanceX = ball.x - HorizontalEdges;
		float distanceY = ball.y - VerticalEdges;
		float distance = sqrtf((distanceX * distanceX) + (distanceY * distanceY));

		//if the distance is less than the radius then there is collision
		if (distance <= (ball.w + ball.x) /2) 
        {
            //__debugbreak();
			return true;
        }
		return false;
        // Convert the SDL_FRect to SDL_Rect for collision detection

#endif // 0

    //if(!&brick)
    //{   
    //    std::cout << "field[i] is nullpointer" << std::endl;
    //    return false;
    //}

    SDL_Rect ballRect = { static_cast<int>(ball.x), static_cast<int>(ball.y), static_cast<int>(ball.w), static_cast<int>(ball.h) };

    // Check for collision between the two rectangles
    if (ballRect.x < brick.x + brick.w &&
        ballRect.x + ballRect.w > brick.x &&
        ballRect.y < brick.y + brick.h &&
        ballRect.y + ballRect.h > brick.y) 
    {
        // Collision detected
        return true;
    }

    //__debugbreak();
    // No collision
    return false;
	
    }

void Bricks::create() 
{   
}

















