#ifndef __chess_state__
#define __chess_state__

#include "Bitboard.hpp"
#include<stdint.h>


struct colour_bitboards {
    uint64_t P = 0;
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
    bool turn; //true for White false for Black
};

void print_chessboard(const colour_bitboards &White, const colour_bitboards &Black);

std::vector<std::vector<uint8_t> > regular_move_onto_another_piece_check(std::vector<uint8_t> &current_squares,
                                                         std::vector<uint8_t> &to_squares, uint64_t &bitboard_all);

std::vector<uint16_t> possible_moves(game_state &game);

#endif