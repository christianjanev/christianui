#include "../include/CUWindow.h"

bool isRunning;
CUWindow* window;

void Quit(const Event& event) {
    isRunning = false;
}

void MouseMotion(const Event& event) {
    if (event.motion.x > 640)
        window->setColor(255, 0, 0, 255);
    else
        window->setColor(0, 0, 0, 255);
}

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    window = new CUWindow(1280, 720);

    window->setPosition(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    isRunning = true;

    window->registerHandler(EventType::QUIT, Quit);
    window->registerHandler(EventType::MOUSE_MOVEMENT, MouseMotion);

    while (isRunning) {
        Event event;

        while (SDL_PollEvent(&event))
            window->dispatchEvent(event);

        SDL_RenderClear(window->getRenderer());
        SDL_RenderPresent(window->getRenderer());
    }

    SDL_Quit();
    return ErrorCode::SUCCESS;
}