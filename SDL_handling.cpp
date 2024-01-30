#include "SDL_handling.h"



void SDL_handling::initialise_sdl()
{
    // initalise SDL
    SDL_Init(SDL_INIT_VIDEO);

    //renderer and window
    window = SDL_CreateWindow("BREAKOUT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    
}



void SDL_handling::clean_renderer()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

void SDL_handling::init_backorund(){

        SDL_SetRenderDrawColor(renderer, 0,0, 0, 128); // Set the background color to grey
        SDL_RenderClear(renderer); // now render it
        //SDL_RenderPresent(renderer);
}



SDL_handling::SDL_handling() { window = NULL; renderer = NULL; texture = NULL; }

SDL_handling::~SDL_handling() { delete window; delete renderer; delete texture; }