#ifndef __PLAYERGAMEWINDOW_HPP__
#define __PLAYERGAMEWINDOW_HPP__

#pragma once

#include "gui/Window.hpp"
#include "gui/WindowManager.hpp"
#include "utils/Utils.hpp"
#include "core/Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <stdexcept>
#include <filesystem>

class PlayerGameWindow : public Window {
public:
    PlayerGameWindow(WindowManager* manager, SDL_Renderer* renderer);
    ~PlayerGameWindow() override;

    void handleEvent(const SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
    
    private:
    SDL_Renderer* renderer;
    std::unique_ptr<Game> game;
    TTF_Font* font;
    std::string moveInfo;
    Piece* holdedPiece = NULL;
    
    void drawChessBoard(SDL_Renderer* renderer);
};

#endif // __PLAYERGAMEWINDOW_HPP__
