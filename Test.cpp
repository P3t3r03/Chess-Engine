#include "Bitboard.hpp"
#include "Gamestate.hpp"

int main() {
    game_state game;
    game.W_bitboards.P = 0xFF00;
    game.W_bitboards.N = 0x42;
    game.W_bitboards.B = 0x24;
    game.W_bitboards.R = 0x81;
    game.W_bitboards.Q = 0x8;
    game.W_bitboards.K = 0x10;

    game.B_bitboards.P = 0xFF000000000000;
    game.B_bitboards.N = 0x4200000000000000;
    game.B_bitboards.B = 0x2400000000000000;
    game.B_bitboards.R = 0x8100000000000000;
    game.B_bitboards.Q = 0x800000000000000;
    game.B_bitboards.K = 0x1000000000000000;

    print_bitboard(game.B_bitboards.P);
    
    uint64_t num1 = 0x0000000000000200;
    uint64_t num2 = 0x0000800000000000;//0b0000000000000000000000000000000000000000000000000000000000000001;
    int rank1, rank2, col1, col2;
    uint8_t index1, index2;
    rank1 = bit_rank(num1);
    rank2 = bit_rank(num2);
    col2 = bit_col(num2);
    index2 = coords_to_index(rank2, col2);
    std::cout << "Rank 2: " << rank2 << std::endl;
    col1 = bit_col(num1);
    std::cout << "Column 2: " << col2 << std::endl;
    index1 = coords_to_index(rank1, col1);
    std::cout << "Index 2: " << static_cast<int>(index2) << std::endl;
    uint8_t special = 0;
    uint16_t move = indices_to_move(index1, index2, special);
    std::cout << "Move: " << static_cast<int>(move) << std::endl;
    std::vector<uint8_t> indices = move_to_indices(move);
    std::cout << "Index 2; " << static_cast<int>(indices[1]) << std::endl;
    std::vector<int> coords = index_to_coords(indices[1]);
    std::cout << "Rank/Column 2: " << coords[0] << "/" << coords[1] << std::endl;
    print_bitboard(num2);
    
    print_chessboard(game.W_bitboards, game.B_bitboards);
    return 0;
}