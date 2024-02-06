#include "Audio.h"
    

Audio::Audio()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) 
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) 
        std::cerr << "SDL_mixer initialization failed: " << Mix_GetError() << std::endl;            
}
    
Audio::~Audio()
{
    Mix_FreeChunk(soundEffect);
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit();
}

Mix_Chunk* Audio::load_sound(std:: string musicpath )
{
    // Load sound effect
    Mix_Chunk* sound = Mix_LoadWAV(musicpath.c_str());
    if (!sound) 
    {
        std::cout << "Failed to load soundd -> " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
    }

    return sound;
}
    
void Audio::play_sound(std::string musicpath)
{
    soundEffect=load_sound(musicpath);

    // Play sound effect
    if (Mix_PlayChannel(-1, soundEffect, 0) == -1) 
        std::cout << "Failed to play sound effect -> " << Mix_GetError() << std::endl;
    
    //while (Mix_Playing(-1))
    //{
    //    SDL_Delay(100);
    //}

}