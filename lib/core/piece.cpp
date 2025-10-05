#include "core/piece.hpp"

using namespace std;

Piece::Piece(const string& name, int pos, const Color color, vector<int> move_dir, bool multi_move, bool can_castle, bool en_passant)
    : name(name), color(color), movement(move_dir), move_opt{multi_move}{
        this->pos = pos;
        this->move_opt.can_castle = can_castle;
        this->move_opt.en_passant = en_passant;
}

Piece::~Piece(){
    // ...
}

void Piece::updatePosition(int value){
    this->pos = value;
}

void Piece::setEnPassant(bool value){
    this->move_opt.en_passant = value;
}

void Piece::setCanCastle(bool value){
    this->move_opt.can_castle = value;
}

string Piece::getName(){
    return this->name;
}

int Piece::getPosition(){
    return this->pos;
}

Color Piece::getColor(){
    return this->color;
}

vector<int> Piece::getMoveDirection(){
    return this->movement;
}

bool Piece::getCanMultipleMove(){
    return this->move_opt.multiple_move;
}

bool Piece::getCanCastle(){
    return this->move_opt.can_castle;
}

bool Piece::getEnPassant(){
    return this->move_opt.en_passant;
}
