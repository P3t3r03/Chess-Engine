#include "Bitboard.hpp"

/* Chess Board
 These represent the bits e.g the white king is on bit 3

8   56  57  58  59  60  61  62  63
7
6
5
4
3   16  17 ETC
2   8   9   10  11  12  13  14  15  
1   0   1   2   3   4   5   6   7
    A   B   C   D   E   F   G   H


Moves 16 bit representation
S is any special flag
T is the square being moved too
F is the square being moved from
6 bits represent 64 different states same as above.

SSSS TTTT TTFF FFFF
*/

// File and Rank Masks

const uint64_t Rank_Mask[8] = {
    0xFF, 0xFF00, 0xFF0000, 0xFF000000, 0xFF00000000, 0xFF0000000000,
    0xFF000000000000, 0xFF00000000000000
};

const uint64_t File_Mask[8] = {
    0x101010101010101, 0x202020202020202, 0x404040404040404, 0x808080808080808,
    0x1010101010101010, 0x2020202020202020, 0x4040404040404040, 0x8080808080808080,
};

uint8_t bit_rank(uint64_t num) {
    uint8_t rank = 0;
    if (num == 0) {
        return rank;
    }
    while ((num & Rank_Mask[rank]) == 0) {
        ++rank;
    }
    return rank + 1; // Adjust to convert rank index to rank number (1-indexed)
}

uint8_t bit_col(uint64_t num) { //Assumes only 1 set bit
    uint8_t col = 0;
    if(num == 0) {
        return col;
    }
    while ((num & File_Mask[col]) == 0) {
        ++col;
    }
    return col+ 1;
}

uint8_t coords_to_index(const uint8_t rank, const uint8_t col) {
    uint8_t index = static_cast<uint8_t>((rank-1)*8 + (col - 1));
    return index;
}

std::vector<uint8_t> multiple_bits_to_indices(uint64_t bitboard) {
    std::vector<uint8_t> indices;
    uint8_t rank, col, index;
    while(bitboard != 0){
        rank = bit_rank(bitboard);
        col = bit_col(bitboard & Rank_Mask[rank - 1]);
        index = coords_to_index(rank, col);
        indices.push_back(index);
        set_bit_false(bitboard, index);
    }
    return indices;
    
}

// Coords vector in form [rank, column]
std::vector<uint8_t> index_to_coords(const uint8_t index) {
    std::vector<uint8_t> coords;
    coords.push_back(1 + index/8);
    coords.push_back(1 + index%8);
    return coords;
}

// Assembles into form SSSS TTTT TTFF FFFF
uint16_t indices_to_move(uint8_t index_from, uint8_t index_to, uint8_t specials) {
    uint16_t move = (static_cast<uint16_t>(specials)) << 12;
    move |= ((static_cast<uint16_t>(index_to)) << 6);
    move |= (static_cast<uint16_t>(index_from));
    return move;
}

// Indices vector in form [From, To, Special]
std::vector<uint8_t> move_to_indices(const uint16_t move) {
    std::vector<uint8_t> indices;
    indices.push_back(static_cast<uint8_t>(move & 0x3F));
    indices.push_back(static_cast<uint8_t>((move >> 6) & 0x3F));
    indices.push_back(static_cast<uint8_t>((move >> 12) & 0x3F));
    return indices;
}

void print_bitboard(const uint64_t &bitboard) {
    int gridsize = 8;
    std::cout << std::endl << std::string(2*(gridsize)+1, '-') << std::endl;
    for(uint8_t rank = gridsize; rank > 0; rank--) {
        for(uint8_t col = 1; col < gridsize + 1; col++) { // Have to add 1 here as in coords_to_index we assume 1-8
            std::cout << "|";
            if(get_bit(bitboard, coords_to_index(rank, col))) {
                std::cout << "X";
            }
            else {
                std::cout << " ";
            }                
        }
        std::cout << "|" << std::endl << std::string(2*(gridsize)+1, '-') << std::endl;
    }
}

void move_piece_regular(uint64_t &bitboard, const uint16_t move) {
    std::vector<uint8_t> indices = move_to_indices(move);
    set_bit_false(bitboard, indices[0]);
    set_bit_true(bitboard, indices[1]);
}
void move_piece_capture(uint64_t &bitboard_move, uint64_t &bitboard_remove, uint16_t move) {
    std::vector<uint8_t> indices = move_to_indices(move);
    set_bit_false(bitboard_move, indices[0]);
    set_bit_false(bitboard_remove, indices[1]);
    set_bit_true(bitboard_move, indices[1]);
}