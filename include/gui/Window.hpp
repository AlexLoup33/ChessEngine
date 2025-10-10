#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#pragma once

#include <SDL2/SDL.h>
#include <string>

class WindowManager; // déclaration anticipée

class Window {
public:
    explicit Window(WindowManager* manager)
        : windowManager(manager) {}
    virtual ~Window() = default;

    virtual void handleEvent(const SDL_Event& event) = 0;
    virtual void update() = 0;
    virtual void render(SDL_Renderer* renderer) = 0;

protected:
    WindowManager* windowManager; // accessible par toutes les fenêtres
};

#endif // __WINDOW_HPP__