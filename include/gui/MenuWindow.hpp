#ifndef __MENU_WINDOW_HPP__
#define __MENU_WINDOW_HPP__

#include "Window.hpp"
#include "WindowManager.hpp"
#include "utils/Utils.hpp"

#include <stdexcept>
#include <filesystem>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <memory>

class MenuWindow : public Window {
public:
    MenuWindow(WindowManager* manager, SDL_Renderer* renderer);
    ~MenuWindow() override = default;

    void handleEvent(const SDL_Event& e) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;

private:
    struct Button {
        std::string label;
        SDL_Rect rect;
    };

    std::vector<Button> buttons;
    SDL_Renderer* renderer;
    WindowManager* manager;
    TTF_Font* font;

    void handleClick(int x, int y);
};

#endif // __MENU_WINDOW_HPP__
