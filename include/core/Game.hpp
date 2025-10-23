#ifndef __GAME_HPP__
#define __GAME_HPP__

/* Core Headers */
#include "core/Board.hpp"
#include "core/Color.hpp"

/* Utils Headers*/
#include "utils/Utils.hpp"

#pragma once

class Game{
    public:
        Game();
        ~Game();

        void newGame();
        
        Board* GetBoard();

        void SwitchPlayerTurn();

        Color getPlayerTurn();

        void PlayMove(Piece* piece, int destination);

    private:
        Board *board;
        Color player_turn;
        int turn;
        int half_move;
        std::vector<int> castle;

        bool isLegalMove(Piece* piece, int destination);
};

#endif // __GAME_HPP__