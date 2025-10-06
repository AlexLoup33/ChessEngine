#ifndef __AIGAMEWINDOW_HPP__
#define __AIGAMEWINDOW_HPP__

#pragma once

#include "gui/Window.hpp"
#include <SDL2/SDL.h>
#include <string>

class AIGameWindow : public Window {
public:
    AIGameWindow();
    ~AIGameWindow() override = default;

    void handleEvent(const SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    bool paused;
    std::string statusText;
};

#endif // __AIGAMEWINDOW_HPP__
