#include "../include/CUWindow.h"

CUWindow::CUWindow(int w, int h) : m_window() {
    m_window = SDL_CreateWindow("Joe", w, h, SDL_WINDOW_RESIZABLE);

    if (!m_window)
        std::cerr << "Window creation failed. Error code " << ErrorCode::WINDOW_CREATE_FAIL << ". " << SDL_GetError();

    m_renderer = SDL_CreateRenderer(m_window, NULL);

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

SDL_Window* CUWindow::getWindow() {
    return m_window;
}


SDL_Renderer* CUWindow::getRenderer() {
    return m_renderer;
}

void CUWindow::setPosition(int x, int y) {
    if (m_window)
        SDL_SetWindowPosition(m_window, x, y);
}

void CUWindow::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
}

void CUWindow::addEvent(Event event, EventFunction function) {
    SDL_AddEventWatch(function, &event);
}