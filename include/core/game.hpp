#ifndef __GAME_HPP__
#define __GAME_HPP__

/* Core Headers */
#include "core/board.hpp"
#include "core/color.hpp"

/* Utils Headers*/
#include "utils/utils.hpp"

#pragma once

class Game{
    public:
        Game();
        ~Game();

        void newGame();

    private:
        Board *board;
        Color player_turn;
        int turn;
        int half_move;
        std::vector<int> castle;
};

#endif // __GAME_HPP__