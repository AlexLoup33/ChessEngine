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