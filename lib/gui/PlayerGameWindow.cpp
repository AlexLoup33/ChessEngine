#include "gui/PlayerGameWindow.hpp"

using namespace std;;

PlayerGameWindow::PlayerGameWindow(WindowManager* manager_, SDL_Renderer* renderer_) 
: manager(manager_), renderer(renderer_)
{
    if (TTF_Init() == -1){
        throw runtime_error("Failed to init SDL_ttf");
    }

    font = loadFontSafe({
        "assets/fonts/Roboto-Black.ttf",
        "/usr/share/fonts/TTF/DejaVuSans.ttf",
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
    }, 24);

    if (!font){
        throw runtime_error("Failed to load font");
    }

    this->game = new Game();
    this->game->newGame();
}

void PlayerGameWindow::drawChessBoard(SDL_Renderer* renderer) {
    const int squareSize = 60;

    for (int pos = 0; pos < 64; ++pos) {
        int file = pos % 8;
        int rank = pos / 8;
        SDL_Rect square = { file * squareSize, rank * squareSize, squareSize, squareSize };

        // --- 1. Dessiner le fond d'abord ---
        if ((file + rank) % 2 == 0) {
            SDL_SetRenderDrawColor(renderer, 240, 217, 181, 255); // clair
        } else {
            SDL_SetRenderDrawColor(renderer, 181, 136, 99, 255); // foncé
        }
        SDL_RenderFillRect(renderer, &square);

        // --- 2. Dessiner la pièce s’il y en a une ---
        Piece* piece = game->GetBoard()->getPieceAt(pos);
        if (piece) {
            std::string imagePath = "assets/images/" + piece->getName() + ".png";

            if (std::filesystem::exists(imagePath)) {
                SDL_Surface* surface = IMG_Load(imagePath.c_str());
                if (!surface) {
                    SDL_Log("❌ Failed to load image %s: %s", imagePath.c_str(), IMG_GetError());
                    continue;
                }

                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);

                if (texture) {
                    SDL_RenderCopy(renderer, texture, nullptr, &square);
                    SDL_DestroyTexture(texture);
                } else {
                    SDL_Log("❌ Failed to create texture: %s", SDL_GetError());
                }
            } else {
                SDL_Log("⚠️ Image not found: %s", imagePath.c_str());
            }
        }
    }
}
void PlayerGameWindow::handleEvent(const SDL_Event& event){
    // ...
}

void PlayerGameWindow::update(){
    // ...
}

void PlayerGameWindow::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);

    this->drawChessBoard(renderer);

    if (!font) {
        SDL_Log("❌ Font not loaded in PlayerGameWindow::render");
        return;
    }

    if (moveInfo.empty()) {
        SDL_Log("⚠️ moveInfo is empty, skipping text rendering");
        return;
    }

    SDL_Color textColor = {255, 255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, moveInfo.c_str(), textColor);
    if (!textSurface) {
        SDL_Log("❌ TTF_RenderText_Blended failed: %s", TTF_GetError());
        return;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        SDL_Log("❌ SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
        SDL_FreeSurface(textSurface);
        return;
    }

    SDL_Rect textRect = {10, 500, textSurface->w, textSurface->h};
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
    
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}
