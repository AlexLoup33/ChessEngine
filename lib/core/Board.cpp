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
        char element; 
        while((element = fen_element[fen_index]) != '\0'){
            if (isdigit(element)){
                int empty_squares = element - '0';
                for (int j = 0; j < empty_squares; j++){
                    this->squares[rank * 8 + file] = NULL;
                    file++;
                }
            }else{
                int pos = rank * 8 + file;
                Piece *p;
                switch (element){
                    case 'R': p = new Piece("WhiteRook", pos, Color::WHITE, {-8, -1, 1, 8}, true, true, false); break;
                    case 'N': p = new Piece("WhiteKnight", pos, Color::WHITE, {-17, -15, -11, -6, 6, 11, 15, 17}, false, false, false); break;
                    case 'B': p = new Piece("WhiteBishop", pos, Color::WHITE, {-9, -7, 7, 9}, true, false, false); break;
                    case 'Q': p = new Piece("WhiteQueen", pos, Color::WHITE, {-9, -8, -7, -1, 1, 7, 8, 9}, true, false, false); break;
                    case 'K': p = new Piece("WhiteKing", pos, Color::WHITE, {-9, -8, -7, -1, 1, 7, 8, 9}, false, true, false); break;
                    case 'P': p = new Piece("WhitePawn", pos, Color::WHITE, {-16, -9, -8, -7}, false, false, false); break;
                    case 'r': p = new Piece("BlackRook", pos, Color::BLACK, {-8, -1, 1, 8}, true, true, false); break;
                    case 'n': p = new Piece("BlackKnight", pos, Color::BLACK, {-17, -15, -11, -6, 6, 11, 15, 17}, false, false, false); break;
                    case 'b': p = new Piece("BlackBishop", pos, Color::BLACK, {-9, -7, 7, 9}, true, false, false); break;
                    case 'q': p = new Piece("BlackQueen", pos, Color::BLACK, {-9, -8, -7, -1, 1, 7, 8, 9}, true, false, false); break;
                    case 'k': p = new Piece("BlackKing", pos, Color::BLACK, {-9, -8, -7, -1, 1, 7, 8, 9}, false, true, false); break;
                    case 'p': p = new Piece("BlackPawn", pos, Color::BLACK, {-16, -9, -8, -7}, false, false, false); break;
                    default: p = NULL; break;
                }
                this->squares[rank * 8 + file] = p;
                file++;
            }
            fen_index++;
        }
        rank++;
        file = 0;
    }
}

string Board::FENtoString(){
    string FEN = "";
    for (int file = 0; file < 8; file++){
        int digit = 0;
        for (int rank = 0; rank < 8; rank++){
            int pos = file*8+rank;
            if (squares[pos] != NULL){
                if (digit != 0){
                    FEN += to_string(digit);
                    digit = 0;
                }
                Piece* p = getPieceAt(pos);
                if (p == NULL){
                    throw runtime_error("ERROR: INVALID PIECE");
                }
                const char* name = p->getName().c_str();
                string element = "el";
                

                // SWITCH CASE A LA MANO
                if (strcmp(name, "BlackRook") == 0) 
                    element = string("r");
                else if (strcmp(name, "BlackKnight") == 0) 
                    element = string("n");
                else if (strcmp(name, "BlackBishop") == 0) 
                    element = string("b");
                else if (strcmp(name, "BlackQueen") == 0) 
                    element = string("q");
                else if (strcmp(name, "BlackKing") == 0) 
                    element = string("k");
                else if (strcmp(name, "BlackPawn") == 0) 
                    element = string("p");
                else if (strcmp(name, "WhiteRook") == 0) 
                    element = string("R");
                else if (strcmp(name, "WhiteKnight") == 0) 
                    element = string("N");
                else if (strcmp(name, "WhiteBishop") == 0) 
                    element = string("B");
                else if (strcmp(name, "WhiteQueen") == 0) 
                    element = string("Q");
                else if (strcmp(name, "WhiteKing") == 0) 
                    element = string("K");
                else if (strcmp(name, "WhitePawn") == 0) 
                    element = string("P");


                FEN += element;
            }else{
                digit++;
                if (digit == 8 || rank == 7){
                    FEN += to_string(digit);
                }
            }
        }
        FEN += (file != 7) ? "/" : "";
    }
    return FEN;
}

void Board::reset(){
    for (int pos = 0; pos < 64; pos++)
        this->squares[pos] = NULL;
    this->initialize((string)"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
}

Piece *Board::getPieceAt(int pos){
    if (pos < 0 || pos >= 64) return nullptr;
    return squares[pos];
}