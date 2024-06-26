#include "Bitboard.hpp"
#include "Gamestate.hpp"

int main() {
    game_state game;
    game.turn = true;
    game.W_bitboards.P = 0xFF00;
    game.W_bitboards.N = 0x42;
    game.W_bitboards.B = 0x24;
    game.W_bitboards.R = 0x81;
    game.W_bitboards.Q = 0x0;
    game.W_bitboards.K = 0x10;
    game.W_bitboards.Colour = 0xFFFF;

    game.B_bitboards.P = 0xFF000000000000;
    game.B_bitboards.N = 0x4200000000000000;
    game.B_bitboards.B = 0x2400000000000000;
    game.B_bitboards.R = 0x8100000000000000;
    game.B_bitboards.Q = 0x800000000000000;
    game.B_bitboards.K = 0x1000000000000000;
    game.B_bitboards.Colour = 0xFFFF000000000000;
    uint64_t num1 = 0x0000000000000080;
    uint64_t num2 = 0x0400000000000000;
    uint8_t rank1, rank2, col1, col2;
    rank1 = bit_rank(num1);
    rank2 = bit_rank(num2);
    col1 = bit_col(num1);
    col2 = bit_col(num2);
    print_bitboard(game.W_bitboards.N);
    print_bitboard(num1 << 8);
    
    uint8_t index1, index2;

    
    index1 = coords_to_index(rank1,col1);
    std::cout << "Rank 1: " << static_cast<int>(rank1) << std::endl;
    std::cout << "Column 1: " << static_cast<int>(col1) << std::endl;
    index2 = coords_to_index(rank2,col2);
    std::cout << "Index 1: " << static_cast<int>(index1) << std::endl;
    uint8_t special = 0;
    uint16_t move = indices_to_move(index1, index2, special);
    std::cout << "Move: " << static_cast<int>(move) << std::endl;
    std::vector<uint8_t> indices = move_to_indices(move);
    std::cout << "Index 1; " << static_cast<int>(indices[0]) << std::endl;
    std::vector<uint8_t> coords = index_to_coords(indices[0]);
    std::cout << "Rank/Column 1: " << static_cast<int>(coords[0]) << "/" << static_cast<int>(coords[1]) << std::endl;
    std::vector<uint8_t> multiple_indices = multiple_bits_to_indices(0x1000F0000);
    print_bitboard(0x8080808080808080);
    for (int i = 0; i < multiple_indices.size(); i++) {
        std::cout << "Index " << i << ": " << static_cast<int>(multiple_indices[i]) << std::endl;
    }
    /*
    print_chessboard(game.W_bitboards, game.B_bitboards);
    move_piece_regular(game.W_bitboards.P, move);
    print_bitboard(game.W_bitboards.P);
    print_chessboard(game.W_bitboards, game.B_bitboards);
    */

    // Test for Pawn 1 move generation
    
    std::vector<uint16_t> pawn_1_moves = possible_moves(game);
    print_bitboard(game.W_bitboards.P);
    for(int i = 0; i < pawn_1_moves.size(); i++) {
        move_piece_regular(game.W_bitboards.P, pawn_1_moves[i]);
        print_bitboard(game.W_bitboards.P);
    }


    return 0;
}