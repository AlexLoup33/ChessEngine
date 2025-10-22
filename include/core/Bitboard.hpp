#ifndef __BITBOARD_HPP__
#define __BITBOARD_HPP__

#include <stdio.h>
#include <string>
#include <stdint.h>

class Bitboard {
    public:
        Bitboard();
        ~Bitboard();

    private:
        uint64_t board[8];
};

#endif // __BITBOARD_HPP__