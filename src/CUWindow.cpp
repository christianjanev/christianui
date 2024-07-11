#include "../include/CUWindow.h"

CUWindow::CUWindow(int w, int h) : m_window() {
    m_window = SDL_CreateWindow("Joe", w, h, SDL_WINDOW_RESIZABLE);
}

SDL_Window* CUWindow::getWindow() {
    return m_window;
}

void CUWindow::setPosition(int x, int y) {
    if (m_window)
        SDL_SetWindowPosition(m_window, x, y);
}