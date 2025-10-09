#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>

#include "cstddef"

#include "Piece.hpp"
#include "utils/Utils.hpp"

class Board{
    public:
        /**
        * @brief Constructor of the Board class.
        */
        Board();

        /**
        * @brief Destructor of the Board class, used to free memory.
        */
        ~Board();

        /**
        * @brief Initializes the board with pieces in their starting position according
        * @param the FEN notation given.
        * @return void
        */
        void initialize(const std::string& fen);
        
        /**
        * @brief Resets the board to the initial state when initialized.
        */
        void reset();

        /**
         * @brief Getter for the piece at a specifi position
         * @param pos
         * @return Piece* : the value in the board at the position pos
         */
        Piece* getPieceAt(int pos);

    private:
        Piece **squares; // Array of Pieces
};

#endif // __BOARD_HPP__