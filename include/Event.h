#pragma once

#include <SDL3/SDL_events.h>

typedef SDL_EventFilter EventFunction;
typedef SDL_Event Event;

enum EventType {
    QUIT = SDL_EVENT_QUIT,
    MOUSE_MOVEMENT = SDL_EVENT_MOUSE_MOTION
};