#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#pragma once

#include "gui/WindowManager.hpp"
#include <SDL2/SDL.h>

class Application{
    public:
        Application(const std::string& title, int width, int height);
        ~Application();

        void run();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool running; 
        WindowManager manager;
};

#endif