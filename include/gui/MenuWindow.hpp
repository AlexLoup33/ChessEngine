#ifndef __MENU_WINDOW_HPP__
#define __MENU_WINDOW_HPP__

#pragma once
#include "gui/Window.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>

struct Button {
    std::string label;
    SDL_Rect rect;
};

class MenuWindow : public Window {
public:
    MenuWindow(WindowManager* manager, SDL_Renderer* renderer);
    ~MenuWindow() override;

    void handleEvent(const SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    SDL_Renderer* renderer;
    TTF_Font* font;
    std::vector<Button> buttons;

    void drawButtons();
    void handleClick(int x, int y);
};

#endif // __MENU_WINDOW_HPP__
