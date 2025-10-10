#ifndef __WINDOWMANAGER_HPP__
#define __WINDOWMANAGER_HPP__

#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <string>
#include <unordered_map>

#include "gui/Window.hpp"

class WindowManager {
public:
    explicit WindowManager(SDL_Renderer* renderer);
    ~WindowManager();

    void handleEvent(const SDL_Event& event);
    void render();
    void update();

    void switchTo(const std::string& windowName);
    Window* getCurrentWindow();

private:
    SDL_Renderer* renderer;
    std::unique_ptr<Window> currentWindow;
    std::unordered_map<std::string, std::unique_ptr<Window>> cache;
    std::string currentName;

    std::unique_ptr<Window> createWindow(const std::string& name);
};

#endif // __WINDOWMANAGER_HPP__
