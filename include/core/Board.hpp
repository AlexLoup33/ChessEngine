#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>
#include <cstring>

#include "cstddef"

#include "core/Piece.hpp"
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
         * @brief Take the current state of the board and convert it into a FEN string representation
         * @param self: the board
         * @return string : the FEN string
         */
        std::string FENtoString();
        
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

        /**
         * @brief Change the position of a piece in the board
         * @param piece : the pointer of the piece
         * @param destination : the new Position of the Piece
         * @return void
         */
        void MovePiece(int start, int end);

    private:
        Piece **squares; // Array of Pieces
};

#endif // __BOARD_HPP__