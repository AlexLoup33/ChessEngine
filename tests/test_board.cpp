#include "core/Board.hpp"
#include <cstring>

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