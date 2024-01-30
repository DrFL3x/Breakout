#include "Collision.h"
#include<string>
#include <cmath>


// checks collision of objects 

void Collision::check_collision()
{
    //stops the board from moving thorugh the l& r walls
    // board & left wall collision checkk
    if (board->get_board().x == wall->get_left_w().x + wall->get_left_w().w && board->get_board().x + board->get_board().w >= wall->get_left_w().x)
    {
        board->board_stop();

        if ((board->board_is_stopped()) && SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT])
            board->board_resume();

    }

    // baord & right wall 
    if (board->get_board().x + board->get_board().w >= wall->get_right_w().x)
    {
        board->board_stop();

        if ((board->board_is_stopped()) && SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT])
            board->board_resume();
    }


    // ball & board
    bool isBallAboveBoard = ball->get_geometry().y + ball->get_geometry().h > board->get_board().y;
    bool isBallTooRight = ball->get_geometry().x > board->get_board().x + board->get_board().w;
    bool isBallTooLeft = ball->get_geometry().x + ball->get_geometry().w < board->get_board().x;

    bool isBallTooUp = ball->get_geometry().y + ball->get_geometry().h < board->get_board().y;
    bool isBallTooBelow = ball->get_geometry().y > board->get_board().y + board->get_board().h;

    if (isBallAboveBoard && !isBallTooRight && !isBallTooLeft && !isBallTooUp && !isBallTooBelow)
    {
        ball->angle = -ball->angle;
        return;
    }

    if (ball->get_geometry().y > 780)
    {
        // Display "Game Over" message
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over", "Game Over", NULL);
        SDL_Quit();
    }

}



void Collision::check_bricks_collision(Bricks* field[], SDL_Renderer * renderer)
{

// CHECK WHEN BALL HITS THE SIDE OF THE BOARD
    // ball & bricks
    for (int i = 0; i < BLOCKS_NUM; ++i)
    {
        if (field[i])
        {

            //if (brick->field[i]->ball_brick_collided(ball->get_geometry(), brick->get_geometry()))

            if(brick->ball_brick_collided(ball->get_geometry(), field[i]->get_geometry()))
            {
                
                // Play sound, display score
                // PlaySFX();
                
                if (!(i % 3 == 0)) 
                {
                    delete field[i];
                    field[i] = nullptr;
                }
                ball->angle = -ball->angle;

            }

        }
    }

}


#if 0

void Collision::renderScoreText(SDL_Renderer* renderer, int score) {
    SDL_Color textColor = { 255, 255, 255 }; // White color

    // Convert score to string
    std::string scoreStr = "Score: " + std::to_string(score);

    // Assume you have a font size and style
    int fontSize = 24;

    // Render text surface
    SDL_Surface* textSurface = SDL_CreateRGBSurface(0, 100, 50, 32, 0, 0, 0, 0); // Adjust surface size as needed
    if (textSurface == nullptr) {
        std::cerr << "Error creating text surface: " << SDL_GetError() << std::endl;
        return;
    }

    // Use SDL functions to draw text onto the surface (e.g., SDL_RenderDrawText)
    // Note: SDL_RenderDrawText is a fictional function; you'll need to implement your own text rendering logic

    // Create texture from surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface); // Free surface

    if (textTexture == nullptr) {
        std::cerr << "Error creating text texture: " << SDL_GetError() << std::endl;
        return;
    }

    // Get text width and height
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);

    // Set position to render text (e.g., top-left corner of the screen)
    int posX = 400;
    int posY = 40;

    // Render text texture
    SDL_Rect dstRect = { posX, posY, textWidth, textHeight };
    SDL_RenderCopy(renderer, textTexture, nullptr, &dstRect);
    SDL_DestroyTexture(textTexture);
}
#endif // 0









