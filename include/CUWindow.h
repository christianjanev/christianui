#pragma once

#include <SDL3/SDL.h>
#include "ErrorCode.h"
#include "Event.h"
#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

using EventHandler = std::function<void(const SDL_Event&)>;

class CUWindow {
    public:
        CUWindow(int w, int h);
        ~CUWindow();
        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        void setPosition(int x, int y);
        void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void registerHandler(Uint32 eventType, EventHandler handler);
        void dispatchEvent(const SDL_Event& event);
    private:
        SDL_Window* m_window{};
        SDL_Renderer* m_renderer{};
        std::unordered_map<Uint32, std::vector<EventHandler>> handlers;
};
