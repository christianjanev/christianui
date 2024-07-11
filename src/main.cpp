#include "../include/CUWindow.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    CUWindow window(1280, 720);

    SDL_bool isRunning = SDL_TRUE;

    SDL_Renderer* renderer = SDL_CreateRenderer(window.getWindow(), NULL);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    window.setPosition(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    srand(time(NULL));

    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    isRunning = SDL_FALSE;
                    break;
                case SDL_EVENT_MOUSE_MOTION:
                    if (event.motion.x > 640)
                        SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, SDL_ALPHA_OPAQUE);
                    break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window.getWindow());

    SDL_Quit();
    return 0;
}