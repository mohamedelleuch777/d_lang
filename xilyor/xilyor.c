#include "stdio.c"
#include "memory.c"
#include <SDL2/SDL.h>
#undef main

int mySDL_Init() {

    SDL_Window *screen;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    screen = SDL_CreateWindow("My Game Window",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
    if (!screen) {
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    int running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                running = 0;
                break;
            case SDL_KEYDOWN:
                running = 0;
                break;
            default:
                break;
            }
        }
    }

    SDL_Quit();
    return 0;
}
