#include "gui/PlayerGameWindow.hpp"
#include "gui/WindowManager.hpp"
#include "core/Game.hpp" 
#include <SDL2/SDL_image.h>
#include <iostream>
#include <filesystem>

using namespace std;;

PlayerGameWindow::PlayerGameWindow(WindowManager* manager_, SDL_Renderer* renderer_)
    : Window(manager_), renderer(renderer_), font(nullptr), moveInfo("")
{
    if (TTF_Init() == -1) {
        throw std::runtime_error("Failed to init SDL_ttf");
    }

    font = TTF_OpenFont("assets/fonts/Roboto-Black.ttf", 20);
    if (!font) {
        throw std::runtime_error("Failed to load font");
    }

    // Initialisation de la partie si nécessaire
    game = std::make_unique<Game>();
}

PlayerGameWindow::~PlayerGameWindow() {
    if (font) TTF_CloseFont(font);
}

void PlayerGameWindow::handleEvent(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        cout << game->GetBoard()->FENtoString() << endl;
        windowManager->switchTo("menu");
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x = event.button.x;
        int y = event.button.y;

        // Click inside the board
        if (x >= 400 && x <= 400+8*60 && y >= 140 && y <= 140+8*60) {
            int squareSize = 60;
            int file = (x - 400) / squareSize;
            int rank = (y - 140) / squareSize;
            int pos = rank * 8 + file;

            Piece* p = game->GetBoard()->getPieceAt(pos);
            
            if (p) {
                if (game->getPlayerTurn() == p->getColor()){
                    holdedPiece = p;
                }
            }
            
            if (holdedPiece != NULL){
                if (p == NULL || (p != NULL && (p->getColor() != holdedPiece->getColor()))){
                    game->PlayMove(holdedPiece, pos);
                    holdedPiece = NULL;
                }
            }
        }
    }
}

void PlayerGameWindow::update() {
    // TODO: logique de jeu, animation, etc.
}

void PlayerGameWindow::render(SDL_Renderer* renderer) {
    // Fond
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    SDL_RenderClear(renderer);

    drawChessBoard(renderer);

    // Afficher les infos de mouvement
    SDL_Color textColor = {255, 255, 255, 255};
    if (!moveInfo.empty()) {
        SDL_Surface* textSurface = TTF_RenderText_Blended(font, moveInfo.c_str(), textColor);
        if (textSurface) {
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_Rect textRect = {10, 500, textSurface->w, textSurface->h};
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }
    }
}

void PlayerGameWindow::drawChessBoard(SDL_Renderer* renderer) {
    const int squareSize = 60;

    for (int pos = 0; pos < 64; ++pos) {
        int file = pos % 8;
        int rank = pos / 8;
        SDL_Rect square = {400+(file * squareSize),140+(rank * squareSize), squareSize, squareSize};

        // Dessiner la case
        if ((file + rank) % 2 == 0)
            SDL_SetRenderDrawColor(renderer, 240, 217, 181, 255); // clair
        else
            SDL_SetRenderDrawColor(renderer, 181, 136, 99, 255);  // foncé
        SDL_RenderFillRect(renderer, &square);

        // Dessiner la pièce si elle existe
        Piece* piece = game->GetBoard()->getPieceAt(pos);
        //printf("Piece %s at position %d\n", piece ? piece->getName().c_str() : "NULL", pos);
        if (piece) {
            std::string path = "assets/images/" + piece->getName() + ".png";
            if (std::filesystem::exists(path)) {
                SDL_Surface* surface = IMG_Load(path.c_str());
                if (surface) {
                    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                    SDL_FreeSurface(surface);
                    if (texture) {
                        SDL_RenderCopy(renderer, texture, nullptr, &square);
                        SDL_DestroyTexture(texture);
                    } else {
                        SDL_Log("Failed to create texture: %s", SDL_GetError());
                    }
                } else {
                    SDL_Log("Failed to load image: %s", path.c_str());
                }
            } else {
                SDL_Log("Image not found: %s", path.c_str());
            }
        }
    }
}
