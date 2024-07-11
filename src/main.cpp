#include "../include/CUWindow.h"
#include <stdlib.h>
#include <time.h>

SDL_bool isRunning = SDL_TRUE;

int ChangeColor(void* userdata, SDL_Event* event) {
    if (event->type == Event::MOUSE_MOVEMENT) {
        CUWindow window = *(CUWindow*)userdata;
        window.setColor(255,0,0,255);
        return ErrorCode::SUCCESS;
    }
    return 0;
}

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    CUWindow window(1280, 720);

    window.setPosition(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    window.addEvent(Event::MOUSE_MOVEMENT, ChangeColor);

    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case Event::QUIT:
                    isRunning = false;
                    break;
            }
        }

        SDL_RenderClear(window.getRenderer());
        SDL_RenderPresent(window.getRenderer());
    }

    SDL_DestroyWindow(window.getWindow());

    SDL_Quit();
    return ErrorCode::SUCCESS;
}