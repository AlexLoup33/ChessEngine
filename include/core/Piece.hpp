#ifndef __PIECE_H__
#define __PIECE_H__

#include "stdlib.h"
#include <string>
#include <vector>
#include <memory>

#include "core/Color.hpp"

#pragma once

typedef struct move_options_t{
    const bool multiple_move;
    bool can_castle;
    bool en_passant;
}move_options;

class Piece{
    public:
        /**
        * @brief Constructor of class Piece
        * @param name : const name of the piece
        * @param pos : position of the piece
        * @param color : const Color of the piece
        * @param multi_move : const Boolean value to know if the piece can make long movement
        * @param can_castle : Boolean value to know if the piece can make a castle move
        * @param en_passant : Boolean value to know if the pawn can use the "en passant" options
        * @return void
        */
        Piece(const std::string& name, int pos,const Color color, std::vector<int> move_dir, bool multi_move, bool can_castle, bool en_passant);

        /**
        * @brief Destructor of class Piece
        * @param None
        * @return void
        */
        ~Piece();

        /**
         * @brief Update the position of the piece in the board
         * @param value : new position of the piece
         * @return void
         */
        void updatePosition(int value);

        /**
        * @brief Change the value of the variable enPassant in the structure move_options.
        * @param value : The new boolean value of en_passant.
        * @return void
        */
        void setEnPassant(bool value);

        /**
         * @brief Change the value of the variable can_castle in the structure move_options.
         * @param value : The new boolean value of can_castle.
         * @return void
        */
       void setCanCastle(bool value);    

        /**
         * @brief Getter for the name of the piece
         * @return string name
        */
        std::string getName();

        /**
         * @brief Getter for the position of the piece
         * @return int pos
         */
        int getPosition();

        /**
         * @brief Getter for the color of the piece
         * @return Color color
         */
        Color getColor();

        /**
         * @brief Getter for the movement direction of the piece
         * @return vector<int> move_dir
         */
        std::vector<int> getMoveDirection();

        /**
         * @brief Getter for the value of option : multiple_move
         * @return bool multiple_move
         */
        bool getCanMultipleMove();

        /**
         * @brief Getter for the value of option : can_castle
         * @return bool can_castle
         */
        bool getCanCastle();

        /**
         * @brief Getter for the value of option : en_passant
         * @return bool en_passant
         */
        bool getEnPassant();


    private:
        const std::string name;
        int pos;
        const Color color;
        const std::vector<int> movement;
        move_options move_opt;
};

#endif // __PIECE_H__