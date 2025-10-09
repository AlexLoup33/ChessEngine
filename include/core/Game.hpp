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

    private:
        Board *board;
        Color player_turn;
        int turn;
        int half_move;
        std::vector<int> castle;
};

#endif // __GAME_HPP__