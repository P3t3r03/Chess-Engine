#ifndef __bit_operations__
#define __bit_operations__

#include<stdint.h>
#include <cstdint>
#include<iostream>
#include<vector>

template<typename T, typename I>
bool get_bit(const T num, const I index) {
    return num & (static_cast<T>(1) << index);
}

template<typename T>
void set_bit_true(T &num, const int index) {
    T mask = (static_cast<T>(1)) << index; 
    num |= mask;
}

template<typename T>
void set_bit_false(T &num, const int index) {
    T mask = (static_cast<T>(1)) << index; 
    num &= ~mask;
}
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

int bit_rank(uint64_t num); // Assumes 1 set bit

int bit_col(uint64_t num); // Assumes 1 set bit

uint8_t coords_to_index(const int rank, const int col);


// Coords vector in form [rank, column]
std::vector<int> index_to_coords(const uint8_t index);

// Assembles into form SSSS TTTT TTFF FFFF
uint16_t indices_to_move(uint8_t index_from, uint8_t index_to, uint8_t specials);

// Indices vecotr in form [From, To, Special]
std::vector<uint8_t> move_to_indices(const uint16_t move);

void print_bitboard(const uint64_t bitboard);


#endif