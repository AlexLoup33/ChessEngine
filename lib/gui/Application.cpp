#include "gui/Application.hpp"
#include "gui/MenuWindow.hpp"
#include "gui/PlayerGameWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdexcept>

using namespace std;;

Application::Application(const string& title, int width, int height){
    SDL_Init(SDL_INIT_VIDEO);

    if (TTF_Init() == -1){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", TTF_GetError());
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window)
        throw runtime_error("Failed to create SDL window");
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
        throw runtime_error("Failed to create SDL renderer");

    manager.addWindow("menu", make_shared<MenuWindow>(&manager, renderer));
    manager.addWindow("PlayerGame", make_shared<PlayerGameWindow>(&manager, renderer));
    manager.addWindow("AIGame", shared_ptr<Window>(nullptr));

    manager.switchTo("menu");
}

Application::~Application(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Application::run(){
    running = true;
    SDL_Event e; 

    while(running){
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            if (auto current = manager.getCurrent()){
                current->handleEvent(e);
            }
        }

        if (auto current = manager.getCurrent()){
            current->update();
            current->render(renderer);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}