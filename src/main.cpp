#include "../include/CUWindow.h"

SDL_bool isRunning;

void Quit(const Event& event) {
    isRunning = false;
}

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    CUWindow window(1280, 720);

    window.setPosition(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    isRunning = SDL_TRUE;

    window.registerHandler(EventType::QUIT, Quit);

    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event))
            window.dispatchEvent(event);

        SDL_RenderClear(window.getRenderer());
        SDL_RenderPresent(window.getRenderer());
    }

    SDL_Quit();
    return ErrorCode::SUCCESS;
}