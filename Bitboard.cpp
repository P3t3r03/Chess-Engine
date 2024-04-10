#include "Bitboard.hpp"

template<typename T>
bool get_bit(const T num, const int index) {
    return num & (static_cast<T>(1) << index);
}

template<typename T>
bool get_bit(const T num, const uint8_t index) {
    return num & (static_cast<T>(1) << index);
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

int bit_rank(uint64_t num) { //Assumes only 1 set bit
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

int bit_col(uint64_t num) { //Assumes only 1 set bit
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

// Coords vector in form [rank, column]
std::vector<int> index_to_coords(const uint8_t index) {
    std::vector<int> coords;
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

// Indices vecotr in form [From, To, Special]
std::vector<uint8_t> move_to_indices(const uint16_t move) {
    std::vector<uint8_t> indices;
    indices.push_back(static_cast<uint8_t>(move & 0x3F));
    indices.push_back(static_cast<uint8_t>((move >> 6) & 0x3F));
    indices.push_back(static_cast<uint8_t>((move >> 12) & 0x3F));
    return indices;
}

void print_bitboard(const uint64_t bitboard) {
    int gridsize = 8;
    std::cout << std::endl << std::string(2*(gridsize)+1, '-') << std::endl;
    for(int rank = gridsize; rank > 0; rank--) {
        for(int col = 1; col < gridsize + 1; col++) { // Have to add 1 here as in coords_to_index we assume 1-8
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