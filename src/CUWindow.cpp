#include "../include/CUWindow.h"

CUWindow::CUWindow(int w, int h) : m_window() {
    m_window = SDL_CreateWindow("Joe", w, h, SDL_WINDOW_RESIZABLE);

    if (!m_window)
        std::cerr << "Window creation failed. Error code " << ErrorCode::WINDOW_CREATE_FAIL << ". " << SDL_GetError() << "\n";

    m_renderer = SDL_CreateRenderer(m_window, NULL);

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

CUWindow::~CUWindow() {
    std::cout << "Destructor\n";
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
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

void CUWindow::registerHandler(Uint32 eventType, EventHandler handler) {
    handlers[eventType].push_back(handler);
}

void CUWindow::dispatchEvent(const SDL_Event& event) {
    auto it = handlers.find(event.type);
    if (it != handlers.end()) {
        for (const auto& handler : it->second) {
            handler(event);
        }
    }
}