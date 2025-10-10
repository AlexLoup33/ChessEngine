#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>

#include "gui/WindowManager.hpp"

class Application {
public:
    Application(const std::string& title, int width, int height);
    ~Application();

    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::unique_ptr<WindowManager> windowManager;
};

#endif // __APPLICATION_HPP__