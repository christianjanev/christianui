#pragma once

#include <SDL3/SDL.h>
#include "ErrorCode.h"
#include "Event.h"
#include <iostream>

class CUWindow {
    public:
        CUWindow(int w, int h);
        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        void setPosition(int x, int y);
        void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void addEvent(Event event, EventFunction function);
    private:
        SDL_Window* m_window{};
        SDL_Renderer* m_renderer{};
};
