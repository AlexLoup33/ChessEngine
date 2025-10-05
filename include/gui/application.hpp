#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <memory>

#include "gui/window.hpp"
#include "gui/scene.hpp"

class Application{
    public:
        Application(const std::string& name, int width, int height);
        ~Application();

        void run();
    
    private:
        std::unique_ptr<Window> window;
        std::unique_ptr<Scene> currentScene;
        bool quit;

        void initSDL();
        void cleanupSDL();
};

#endif // __APPLICATION_HPP__