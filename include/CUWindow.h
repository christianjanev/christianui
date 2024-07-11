#include <SDL3/SDL.h>
#include <iostream>

class CUWindow {
    public:
        CUWindow(int w, int h);
        SDL_Window* getWindow();
        void setPosition(int x, int y);
    private:
        SDL_Window* m_window{};
};
