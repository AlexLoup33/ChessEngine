#include "gui/MenuWindow.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdexcept>

MenuWindow::MenuWindow(WindowManager* manager_, SDL_Renderer* renderer_)
    : manager(manager_), renderer(renderer_) 
{
    // Init SDL_ttf si ce n'est pas déjà fait
    if (TTF_Init() == -1) {
        throw std::runtime_error("Failed to init SDL_ttf");
    }

    // Charger la police
    font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 24);
    if (!font) {
        throw std::runtime_error("Failed to load font");
    }

    // Définir les boutons
    int btnWidth = 300;
    int btnHeight = 50;
    int startY = 200;
    int gap = 20;

    buttons.push_back({ "Joueur vs Joueur", { 490, startY, btnWidth, btnHeight } });
    buttons.push_back({ "IA / Analyse", { 490, startY + (btnHeight + gap), btnWidth, btnHeight } });
    buttons.push_back({ "Quitter", { 490, startY + 2*(btnHeight + gap), btnWidth, btnHeight } });
}

void MenuWindow::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        handleClick(e.button.x, e.button.y);
    }
}

void MenuWindow::update() {
    // Ici tu peux ajouter hover effect ou animation si besoin
}

void MenuWindow::render(SDL_Renderer* renderer) {
    // Fond
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);

    SDL_Color textColor = { 255, 255, 255, 255 };
    SDL_Color btnColor = { 70, 70, 70, 255 };

    for (const auto& btn : buttons) {
        // Dessiner le rectangle
        SDL_SetRenderDrawColor(renderer, btnColor.r, btnColor.g, btnColor.b, btnColor.a);
        SDL_RenderFillRect(renderer, &btn.rect);

        // Dessiner le texte
        SDL_Surface* textSurface = TTF_RenderText_Blended(font, btn.label.c_str(), textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

        int textW = 0, textH = 0;
        SDL_QueryTexture(textTexture, nullptr, nullptr, &textW, &textH);
        SDL_Rect textRect = { btn.rect.x + (btn.rect.w - textW)/2, btn.rect.y + (btn.rect.h - textH)/2, textW, textH };
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);
    }
}

void MenuWindow::handleClick(int x, int y) {
    for (const auto& btn : buttons) {
        if (x >= btn.rect.x && x <= btn.rect.x + btn.rect.w &&
            y >= btn.rect.y && y <= btn.rect.y + btn.rect.h) 
        {
            if (btn.label == "Quitter") {
                // Fermer l'application
                SDL_Event quitEvent;
                quitEvent.type = SDL_QUIT;
                SDL_PushEvent(&quitEvent);
            } else if (btn.label == "Joueur vs Joueur") {
                manager->switchTo("PlayerGame");
            } else if (btn.label == "IA / Analyse") {
                manager->switchTo("AIgame");
            }
        }
    }
}
