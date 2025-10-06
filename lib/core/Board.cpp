#include "core/Board.hpp"

using namespace std;;

Board::Board(){
    this->squares = new Piece*[64];
    for (int pos = 0; pos < 64; pos++)
        this->squares[pos] = NULL;
}

Board::~Board(){
    delete [] squares;
}

void Board::initialize(const string& fen){
    vector<string> fen_array = split(fen, "/");
    
    int file = 0; // row index
    int rank = 0; // column index

    for (int i = 0; i < 8; i++){
        string fen_element = fen_array[i];

        int fen_index = 0;
        while(char element = fen_element[fen_index] != '\0'){
        }
        file++;
    }
}

void Board::reset(){
    for (int pos = 0; pos < 64; pos++)
        this->squares[pos] = NULL;
    this->initialize((string)"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}