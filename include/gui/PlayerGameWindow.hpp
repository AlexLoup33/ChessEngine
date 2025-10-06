#ifndef __PLAYERGAMEWINDOW_HPP__
#define __PLAYERGAMEWINDOW_HPP__

#pragma once

#include "gui/Window.hpp"
#include <SDL2/SDL.h>
#include <string>

class PlayerGameWindow : public Window {
public:
    PlayerGameWindow();
    ~PlayerGameWindow() override = default;

    void handleEvent(const SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    bool whiteTurn;
    std::string moveInfo;
};

#endif // __PLAYERGAMEWINDOW_HPP__
