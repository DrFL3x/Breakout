#include "Collision.h"
#include<string>
#include <cmath>

// checks collision of objects  //


void Collision::check_collision()
{
    //pad sound
    std::string paddle_sound = "C:/Users/Eugen/Desktop/ProjeXt/Breakout/x64/Debug/mouth-sound-ping-pong.wav";

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
        audio.play_sound(paddle_sound);
        return;
    }



}



int Collision::check_bricks_collision(Bricks* field[], SDL_Renderer * renderer, TTF_Font* font, int score)
{
    std::string string = "C:/Users/Eugen/Desktop/ProjeXt/Breakout/x64/Debug/zap-fx_120bpm_F_minor.wav";

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
                    score += 1;
                    audio.play_sound(string);
                }
                ball->angle = -ball->angle;

            }
        }
    }

    // "Game over" box display 
    if (ball->get_geometry().y > 780)
    {
        renderGameOverText(renderer,font);
        board->board_stop();
    }

    return score;
}



void Collision:: renderGameOverText(SDL_Renderer* renderer, TTF_Font* font)
{
    SDL_Color textColor = { 238, 75, 43 }; // Red color

    // Render text surface

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Game Over", textColor);
    if (textSurface == nullptr)
        return;
   

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface); 

    if (textTexture == nullptr)
        return;
   
    //text width & height
    int textWidth, textHeight;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &textWidth, &textHeight);

    int posX = ( 800 - textWidth) / 2;
    int posY = 500;

    // Now render 
    SDL_Rect text_destination = { posX, 500, textWidth, textHeight };
    SDL_RenderCopy(renderer, textTexture, nullptr, &text_destination);

    SDL_DestroyTexture(textTexture);
}


void Collision::renderScoreText(SDL_Renderer* renderer, TTF_Font* font, int score)
{
    // Convert score to string
    std::string scoreText = "Score       " + std::to_string(score);

    SDL_Color textColor = { 255, 255, 255 }; // Red color

    SDL_Surface* score_surface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
    if (score_surface == nullptr)
        return;

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, score_surface);
    SDL_FreeSurface(score_surface);

    if (textTexture == nullptr)
        return;

    // Get text width & height
    int width, height;
    SDL_QueryTexture(textTexture, nullptr, nullptr, &width, &height);

    int posX = 50;
    int posY = 50;

    // Render text
    SDL_Rect textDestination = { posX, posY, width, height };
    SDL_RenderCopy(renderer, textTexture, nullptr, &textDestination);

    SDL_DestroyTexture(textTexture);
}









