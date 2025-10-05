#include "core/game.hpp"

using namespace std;;

Game::Game(){
    this->board = new Board();
    this->player_turn = Color::WHITE;
}

Game::~Game(){
    delete this->board;
}