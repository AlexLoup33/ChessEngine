#include "gui/Application.hpp"
#include "gui/WindowManager.hpp"
#include <iostream>

Application::Application(const std::string& title, int width, int height)
    : window(nullptr), renderer(nullptr) {
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        throw std::runtime_error(std::string("Failed to init SDL: ") + SDL_GetError());

    if (TTF_Init() == -1)
        throw std::runtime_error("Failed to init SDL_ttf");

    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_SHOWN);

    if (!window)
        throw std::runtime_error("Failed to create window");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        throw std::runtime_error("Failed to create renderer");

    windowManager = std::make_unique<WindowManager>(renderer);

    // ✅ Démarre directement sur le menu principal
    windowManager->switchTo("menu");
}

Application::~Application() {
    windowManager.reset();
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Application::run() {
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            if (windowManager->getCurrentWindow())
                windowManager->getCurrentWindow()->handleEvent(event);
        }

        if (windowManager->getCurrentWindow())
            windowManager->getCurrentWindow()->update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        windowManager->render();

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }
}
