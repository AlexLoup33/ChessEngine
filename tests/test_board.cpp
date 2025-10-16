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

bool fen_import() {
    Board b1, b2, b3;

    // Initial FEN
    string fenB2 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    b2.initialize(fenB2);

    // Random FEN
    string fenB3 = "r1bqkbnr/pppp1ppp/2n5/4p3/2B1P3/5N2/PPPP1PPP/RNBQK2R";
    b3.initialize(fenB3);

    // --- Vérif 1 : plateau vide ---
    for (int i = 0; i < 64; i++) {
        if (b1.getPieceAt(i) != nullptr)
            return false;
    }

    // --- Vérif 2 : FEN initial ---
    // (rangs comptés depuis le haut, donc A8 = 0, H1 = 63)
    auto checkPiece = [&](Board& board, const string& pos, const string& expectedName) {
        int idx = StringPositionToInt(pos.c_str());
        auto piece = board.getPieceAt(idx);
        if (!piece) {
            fprintf(stderr, "Missing piece at %s\n", pos.c_str());
            return false;
        }
        if (piece->getName() != expectedName) {
            fprintf(stderr, "Expected %s at %s, got %s\n",
                    expectedName.c_str(), pos.c_str(), piece->getName().c_str());
            return false;
        }
        return true;
    };

    if (!checkPiece(b2, "C8", "BlackBishop")) return false;
    if (!checkPiece(b2, "G8", "BlackKnight")) return false;
    if (!checkPiece(b2, "E2", "WhitePawn")) return false;
    if (!checkPiece(b2, "A8", "BlackRook")) return false;
    if (!checkPiece(b2, "E1", "WhiteKing")) return false;
    if (!checkPiece(b2, "D8", "BlackQueen")) return false;

    fprintf(stderr, "All pieces in b2 are correct !\n");

    // --- Vérif 3 : FEN aléatoire ---
    if (!checkPiece(b3, "F3", "WhiteKnight")) return false;
    if (!checkPiece(b3, "A8", "BlackRook")) return false;
    if (!checkPiece(b3, "A7", "BlackPawn")) return false;
    if (!checkPiece(b3, "E1", "WhiteKing")) return false;
    if (!checkPiece(b3, "D1", "WhiteQueen")) return false;

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