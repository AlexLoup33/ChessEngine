#include "core/Piece.hpp"
#include "core/Color.hpp"
#include <cstring>

using namespace std;;

bool test_new_piece(){
    Piece* p1 = new Piece("BlackBishop", 50, Color::WHITE, {0}, false, false, false);
    Piece* p2 = new Piece("WhiteKing", 20, Color::BLACK, {1, 2, 3}, false, false, false);
    
    if (!p1 || !p2)
        return false;


    try{
        Piece* p3 = new Piece("Test", -1, Color::WHITE, {}, false, false, false);
        if (p3)
            return false;
    }catch(const exception& e){
        fprintf(stderr, "Valid test: Error on wrong piece init");
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

    if (strcmp(argv[1], "new_piece") == 0)
        pass = test_new_piece();
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