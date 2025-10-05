#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>

#include "cstddef"

#include "piece.hpp"
#include "utils/utils.hpp"

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
        * the FEN notation given.
        * @param fen a string representing the board state in FEN notation.
        */
        void initialize(const std::string& fen);
        
        /**
        * @brief Resets the board to the initial state when initialized.
        */
        void reset();

    private:
        Piece **squares; // Array of Pieces

};

#endif // __BOARD_HPP__