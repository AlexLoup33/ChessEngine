#include "core/Board.hpp"
#include <cstring>

using namespace std;;

bool new_board(){
    Board *board = new Board();
    if (!board)
        return false;
        
    for (int i = 0; i < 64; i++){
        if (board->getPieceAt(i) != NULL)
            return false;
    }
    return true;
}

bool fen_export(){
    Board *b1 = new Board();
    Board *b2 = new Board();
    Board *b3 = new Board();

    if (!b1 || !b2 || !b3)
        return false;

    // Initial FEN
    string fenB2 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    b2->initialize(fenB2);

    // Random FEN
    string fenB3 = "r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R";
    b3->initialize(fenB3);

    if (b1->FENtoString() != "8/8/8/8/8/8/8/8"){
        fprintf(stderr, "FEN1: %s\n", b1->FENtoString().c_str());
        return false;
    }
    if (b2->FENtoString() != fenB2){
        fprintf(stderr, "FEN2: %s\n", b2->FENtoString().c_str());
        return false;
    }
    if (b3->FENtoString() != fenB3){
        fprintf(stderr, "FEN3: %s\n", b3->FENtoString().c_str());
        return false;
    }

    return true; 
}

bool fen_import(){
    Board *b1 = new Board();
    Board *b2 = new Board();
    Board *b3 = new Board();

    if (!b1 || !b2 || !b3)
        return false;
    
    // Initial FEN
    string fenB2 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    b2->initialize(fenB2);

    // Random FEN
    string fenB3 = "r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R";
    b3->initialize(fenB3);

    // Check pieces for b1
    for (int i = 0; i < 64; i++){
        if (b1->getPieceAt(i) != NULL)
            return false;
    }

    // Check pieces for b2 
    // Take random piece (WhiteBishop on C1, BlackKnight on g8, WhitePawn on e2, BlackRook on a8, WhiteKing on e1, BlackQueen on d8)
    const char* c1_str = "C1";
    int c1 = StringPositionToInt(c1_str); // 2
    int g8 = StringPositionToInt("G8"); // 7
    int e2 = StringPositionToInt("E2"); // 52
    int a8 = StringPositionToInt("A8"); // 0
    int e1 = StringPositionToInt("E1"); // 60
    int d8 = StringPositionToInt("D8"); // 3

    if (strcmp(b2->getPieceAt(c1)->getName().c_str(), "WhiteBishop") != 0)
        return false;
    if (strcmp(b2->getPieceAt(g8)->getName().c_str(), "BlackKnight") != 0)
        return false;
    if (strcmp(b2->getPieceAt(e2)->getName().c_str(), "WhitePawn") != 0)
        return false;
    if (strcmp(b2->getPieceAt(a8)->getName().c_str(), "BlackRook") != 0)
        return false;
    if (strcmp(b2->getPieceAt(e1)->getName().c_str(), "WhiteKing") != 0)
        return false;
    if (strcmp(b2->getPieceAt(d8)->getName().c_str(), "BlackQueen") != 0)
        return false;
    

    fprintf(stderr, "All pieces in b2 are correct !\n");
    
    // Check pieces for b3
    // Take random piece (WhiteKnight on f5, BlackRook on a8, blackPawn on a7, WhiteKing on e1, WhiteQueen on d1)
    int f5 = StringPositionToInt("F5"); // 37
    cout << "f5: " << f5 << endl;

    a8 = StringPositionToInt("A8"); // 0
    cout << "a8: " << a8 << endl;

    int a7 = StringPositionToInt("A7"); // 8
    cout << "a7: " << a7 << endl;

    e1 = StringPositionToInt("E1"); // 60
    cout << "e1: " << e1 << endl;

    int d1 = StringPositionToInt("D1"); // 59
    cout << "d1: " << d1 << endl;

    if (strcmp(b3->getPieceAt(f5)->getName().c_str(),"WhiteKnight") != 0)
        return false;
    if (strcmp(b3->getPieceAt(a8)->getName().c_str(), "BlackRook") != 0)
        return false;
    if (strcmp(b3->getPieceAt(a7)->getName().c_str(), "BlackPawn") != 0)
        return false;
    if (strcmp(b3->getPieceAt(e1)->getName().c_str(), "WhiteKing") != 0)
        return false;
    if (strcmp(b3->getPieceAt(d1)->getName().c_str(), "WhiteQueen") != 0)
        return false;
    
    fprintf(stderr, "All pieces in b3 are correct !\n");
    
    return true;
}

void usage(char *argv[]){
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){
    if (argc == 1){
        usage(argv);
    }

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
    bool pass = false;

    if (strcmp("new_board", argv[1]) == 0)
        pass = new_board();
    else if (strcmp("fen_export", argv[1]) == 0)
        pass = fen_export();
    else if (strcmp("fen_import", argv[1]) == 0)
        pass = fen_import();
    else{
        fprintf(stderr, "Error: test \"%s\" not found !\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if (pass == true){
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    }else{
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}