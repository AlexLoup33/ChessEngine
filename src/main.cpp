#include <stdio.h>
#include <stdint.h>

#include <SDL2/SDL.h>

#include "gui/Application.hpp"

using namespace std;;

int main(int argc, char** argv){
    Application app("Chess Engine", 1280, 720);
    app.run();
    /*
    // Initialisation de SDL2
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError());
        return -1;
    }

    
    SDL_Window* pWindow {nullptr};
    pWindow = SDL_CreateWindow("Chess Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN);
    if (pWindow == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Renderer* ren {nullptr};
    ren = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (ren == nullptr){
        if (pWindow == nullptr){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
        }   
    }

    SDL_Event events;
    bool isOpen { true };

    while (isOpen){
        while(SDL_PollEvent(&events)){
            switch (events.type)
            {
            case SDL_QUIT:isOpen = false;
                break;
            
            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();*/
    return EXIT_SUCCESS;
}