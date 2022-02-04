#include "stdio.c"
#include "memory.c"
#include <SDL/SDL.h>
#undef main

int mySDL_Init() {
    return SDL_Init(SDL_INIT_EVERYTHING);
}
