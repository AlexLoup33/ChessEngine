#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#pragma once

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    SDL_Window* getSDLWindow() const { return win; }
    SDL_Renderer* getRenderer() const { return ren; }

    void clear();
    void present();

private:
    SDL_Window* win;
    SDL_Renderer* ren;
};

#endif // __WINDOW_HPP__