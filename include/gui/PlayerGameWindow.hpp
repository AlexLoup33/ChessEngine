#ifndef __PLAYERGAMEWINDOW_HPP__
#define __PLAYERGAMEWINDOW_HPP__

#pragma once

#include "gui/Window.hpp"
#include "gui/WindowManager.hpp"
#include "utils/Utils.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <stdexcept>
#include <filesystem>

class PlayerGameWindow : public Window {
public:
    PlayerGameWindow(WindowManager* manager, SDL_Renderer* renderer);
    ~PlayerGameWindow() override = default;

    void drawChessBoard(SDL_Renderer* renderer);
    void handleEvent(const SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    bool whiteTurn;
    std::string moveInfo;

    SDL_Renderer* renderer;
    WindowManager* manager;

    TTF_Font* font;
};

#endif // __PLAYERGAMEWINDOW_HPP__
