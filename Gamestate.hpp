#ifndef __chess_state__
#define __chess_state__

#include "Bitboard.hpp"
#include<stdint.h>


struct colour_bitboards {
    uint64_t P = 0; // using as I want to use a uint64 for a chess engine in the future
    uint64_t N = 0;
    uint64_t B = 0;
    uint64_t R = 0;
    uint64_t Q = 0;
    uint64_t K = 0;
    uint64_t Colour = 0; // This bitboard simply all of these bitboards Or'd together
};
struct game_state {
    colour_bitboards W_bitboards;
    colour_bitboards B_bitboards;
    bool turn; //true for O false for X 
    bool won; 
    int gridsize;
};

void print_chessboard(const colour_bitboards &White, const colour_bitboards &Black);

bool game_won(const uint64_t &board, const int &gridsize);

bool is_tie(const game_state &game);

void take_turn(game_state &game, int depth);

#endif