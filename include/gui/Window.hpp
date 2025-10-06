#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#pragma once

#include <SDL2/SDL.h>

class Window{
    public:
        virtual ~Window() = default;

        virtual void handleEvent(const SDL_Event& event) = 0;
        virtual void update() = 0;
        virtual void render(SDL_Renderer* renderer) = 0;
};

#endif // __WINDOW_HPP__