#include "gui/MenuWindow.hpp"
#include "gui/WindowManager.hpp"
#include <SDL2/SDL_image.h>
#include <iostream>

MenuWindow::MenuWindow(WindowManager* manager_, SDL_Renderer* renderer_)
    : Window(manager_), renderer(renderer_), font(nullptr)
{
    if (TTF_Init() == -1) {
        throw std::runtime_error("Failed to init SDL_ttf");
    }

    font = TTF_OpenFont("assets/fonts/Roboto-Black.ttf", 24);
    if (!font) {
        throw std::runtime_error("Failed to load font");
    }

    // Création des boutons
    buttons = {
        {"Joueur vs Joueur", {100, 100, 300, 50}},
        {"IA / Analyse",      {100, 200, 300, 50}},
        {"Quitter",           {100, 300, 300, 50}}
    };
}

MenuWindow::~MenuWindow() {
    if (font) TTF_CloseFont(font);
}

void MenuWindow::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        handleClick(event.button.x, event.button.y);
    }
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        windowManager->switchTo("menu"); // utile si on vient d'une autre fenêtre
    }
}

void MenuWindow::update() {
    // Rien pour l'instant
}

void MenuWindow::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    drawButtons();
}

void MenuWindow::drawButtons() {
    SDL_Color textColor = {255, 255, 255, 255};
    for (const auto& btn : buttons) {
        SDL_SetRenderDrawColor(renderer, 70, 70, 70, 255);
        SDL_RenderFillRect(renderer, &btn.rect);

        SDL_Surface* textSurface = TTF_RenderText_Blended(font, btn.label.c_str(), textColor);
        if (!textSurface) continue;

        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_FreeSurface(textSurface);
        if (!textTexture) continue;

        int texW = 0, texH = 0;
        SDL_QueryTexture(textTexture, nullptr, nullptr, &texW, &texH);
        SDL_Rect dstRect = {btn.rect.x + 10, btn.rect.y + (btn.rect.h - texH)/2, texW, texH};
        SDL_RenderCopy(renderer, textTexture, nullptr, &dstRect);
        SDL_DestroyTexture(textTexture);
    }
}

void MenuWindow::handleClick(int x, int y) {
    for (size_t i = 0; i < buttons.size(); ++i) {
        const auto& btn = buttons[i];
        if (x >= btn.rect.x && x <= btn.rect.x + btn.rect.w &&
            y >= btn.rect.y && y <= btn.rect.y + btn.rect.h) {
            switch (i) {
                case 0: windowManager->switchTo("player_game"); break;
                case 1: windowManager->switchTo("AIgame"); break;
                case 2: SDL_Event quitEvent; quitEvent.type = SDL_QUIT; SDL_PushEvent(&quitEvent); break;
            }
        }
    }
}
