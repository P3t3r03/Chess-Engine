#ifndef __bit_operations__
#define __bit_operations__

#include<stdint.h>
#include<iostream>

template<typename T>
bool get_bit(const T num, const int index) {
    bool bit = num & ((static_cast<T>(1)) << index);
    return bit;
}

template<typename T>
T set_bit_true(T num, const int index) {
    T mask = (static_cast<T>(1)) << index; 
    return mask | num;
}
template<typename T>
T set_bit_false(T num, const int index) {
    T mask = (static_cast<T>(1)) << index; 
    return (~mask) & num;
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
template<typename T>
int bit_rank(T num) { //Assumes only 1 set bit
    if(num == 0) {
        return -1;
    }
    int rank = 1;
    while ((num & 0xFF) == 0) {
        rank++;
        num >>= 8;
    }
    return rank;
}
template<typename T>
int bit_col(T num) { //Assumes only 1 set bit
    if(num == 0) {
        return -1;
    }
    int col = 1;
    while ((num & 0x0101010101010101) == 0) {
        col++;
        num >>= 1;
    }
    return col;
}
uint8_t coords_to_index(const int rank, const int col) {
    uint8_t index = static_cast<uint8_t>((rank-1)*8 + (col - 1));
    return index;
}
// Assembles into form SSSS TTTT TTFF FFFF
uint16_t indexs_to_move(uint8_t index_from, uint8_t index_to, uint8_t specials) {
    uint16_t move = (static_cast<uint16_t>(specials)) << 12;
    move = move | ((static_cast<uint16_t>(index_to)) << 6);
    move = move | (static_cast<uint16_t>(index_from));
    return move;
}




#endif