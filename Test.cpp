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
    game.W_bitboards.Colour = 0xFFFF;

    game.B_bitboards.P = 0xFF000000000000;
    game.B_bitboards.N = 0x4200000000000000;
    game.B_bitboards.B = 0x2400000000000000;
    game.B_bitboards.R = 0x8100000000000000;
    game.B_bitboards.Q = 0x800000000000000;
    game.B_bitboards.K = 0x1000000000000000;
    game.B_bitboards.Colour = 0xFFFF000000000000;

    print_bitboard(game.B_bitboards.Colour);

    int rank1, rank2, col1, col2;
    uint8_t index1, index2;

    
    index2 = coords_to_index(3,1);
    std::cout << "Rank 2: " << rank2 << std::endl;
    std::cout << "Column 2: " << col2 << std::endl;
    index1 = coords_to_index(2,1);
    std::cout << "Index 2: " << static_cast<int>(index2) << std::endl;
    uint8_t special = 0;
    uint16_t move = indices_to_move(index1, index2, special);
    std::cout << "Move: " << static_cast<int>(move) << std::endl;
    std::vector<uint8_t> indices = move_to_indices(move);
    std::cout << "Index 2; " << static_cast<int>(indices[1]) << std::endl;
    std::vector<int> coords = index_to_coords(indices[1]);
    std::cout << "Rank/Column 2: " << coords[0] << "/" << coords[1] << std::endl;
    
    print_chessboard(game.W_bitboards, game.B_bitboards);
    move_piece_regular(game.W_bitboards.P, move);
    print_bitboard(game.W_bitboards.P);
    print_chessboard(game.W_bitboards, game.B_bitboards);

    return 0;
}