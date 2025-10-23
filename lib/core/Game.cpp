#include "core/Game.hpp"

using namespace std;;

Game::Game(){
    this->board = new Board();
    this->board->initialize("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
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

Board *Game::GetBoard(){
    return this->board;
}

void Game::SwitchPlayerTurn(){
    this->player_turn = (this->player_turn == Color::WHITE) ? Color::BLACK : Color::WHITE;
}

Color Game::getPlayerTurn(){
    return this->player_turn;
}

void Game::PlayMove(Piece* piece, int position){
    int init_pos = piece->getPosition();

    board->MovePiece(init_pos, position);

    SwitchPlayerTurn();
}