#include "core/Game.hpp"

using namespace std;;

Game::Game(){
    this->board = new Board();
    this->player_turn = Color::WHITE;
    this->turn = 1;
    this->half_move = 0;
    this->castle = {1, 1, 1, 1}; // KQkq
}

Game::~Game(){
    delete this->board;
}

void Game::newGame(){
    board->reset();
    this->player_turn = Color::WHITE;
    this->turn = 1;
    this->half_move = 0;
    this->castle = {1, 1, 1, 1};
}

Board *Game::GetBoard()
{
    return this->board;
}