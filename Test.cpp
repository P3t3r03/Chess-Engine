#include "Test.hpp"
#include "Bitboard.hpp"

int main() {
    hello_world();
    uint64_t num1 = 0x0000000000000001;
    uint64_t num2 = 0x0000000000000100;//0b0000000000000000000000000000000000000000000000000000000000000001;
    int rank1, rank2, col1, col2;
    uint8_t index1, index2;
    rank1 = bit_rank(num1);
    std::cout << rank1 << std::endl;
    col1 = bit_col(num1);
    std::cout << col1 << std::endl;
    index1 = coords_to_index(rank1, col1);
    std::cout << static_cast<int>(index1) << std::endl;
    rank2 = bit_rank(num2);
    col2 = bit_col(num2);
    index2 = coords_to_index(rank2, col2);
    uint8_t special = 0;
    uint16_t move = indexs_to_move(index1, index2, special);
    std::cout << static_cast<int>(move) << std::endl;

    return 0;
}