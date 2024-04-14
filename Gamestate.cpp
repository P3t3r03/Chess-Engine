#include "Gamestate.hpp"
#include <string>
#include <algorithm>


void print_chessboard(const colour_bitboards &White, const colour_bitboards &Black) { // Doesn't need to be efficient as only used for debugging
    int gridsize = 8;
    if ((White.Colour & Black.Colour) == 0) { 
        std::cout << std::endl << "  " << std::string(2*(gridsize)+1, '-') << std::endl;
        std::string piecesymbols = "PNBRQKpnbrqk";
        for (int rank = gridsize; rank > 0; rank--) {
            std::cout << rank << " ";
            for (int col = 1; col < gridsize + 1; col++) { //gridsize + 1 due to how the coords to index is calculated.
                std::cout << "|";
                char piece = ' ';
                if(get_bit(White.P, coords_to_index(rank, col))) piece = piecesymbols[0];
                else if(get_bit(White.N, coords_to_index(rank, col))) piece = piecesymbols[1];
                else if(get_bit(White.B, coords_to_index(rank, col))) piece = piecesymbols[2];
                else if(get_bit(White.R, coords_to_index(rank, col))) piece = piecesymbols[3];
                else if(get_bit(White.Q, coords_to_index(rank, col))) piece = piecesymbols[4];
                else if(get_bit(White.K, coords_to_index(rank, col))) piece = piecesymbols[5];
                else if(get_bit(Black.P, coords_to_index(rank, col))) piece = piecesymbols[6];
                else if(get_bit(Black.N, coords_to_index(rank, col))) piece = piecesymbols[7];
                else if(get_bit(Black.B, coords_to_index(rank, col))) piece = piecesymbols[8];
                else if(get_bit(Black.R, coords_to_index(rank, col))) piece = piecesymbols[9];
                else if(get_bit(Black.Q, coords_to_index(rank, col))) piece = piecesymbols[10];
                else if(get_bit(Black.K, coords_to_index(rank, col))) piece = piecesymbols[11];
                std::cout << piece;
            }
            std::cout << "|" << std::endl << "  " << std::string(2*(gridsize)+1, '-') << std::endl;
        }
        std::cout << "   A B C D E F G H" << std::endl;

    }
}

// vector[0] is the updated current squares vector[1] is the updated to squares this function checks if
// there are pieces of any colour on the to square and removes it from the list Can be used for 1 moves or Knights
std::vector<std::vector<uint8_t> > regular_move_onto_another_piece_check(std::vector<uint8_t> &current_squares,
                                                         std::vector<uint8_t> &to_squares, const uint64_t &bitboard_all) {
        for(int i = current_squares.size() - 1; i >= 0; i--){  // Iterates in reverse so we don't skip over any elements
            if (get_bit(bitboard_all, to_squares[i])) {
                current_squares.erase(current_squares.begin() + i);
                to_squares.erase(to_squares.begin() + i);
            }
        }
        std::vector<std::vector<uint8_t> > valid_to_and_from;
        valid_to_and_from.push_back(current_squares);
        valid_to_and_from.push_back(to_squares);
        return valid_to_and_from;
}

std::vector<std::vector<uint8_t> > double_pawn_move_check(std::vector<uint8_t> &current_squares, const uint64_t &bitboard_all) {
    std::vector<uint8_t> to_squares_1(current_squares.size()); // Initialize with the same size as current_squares
    std::vector<std::vector<uint8_t> > valid_to_square_1;


    // PROblem is Somewhere here
    if (bit_rank(current_squares[0]) == 2) { // Use bit_rank to get the rank of the first square
        std::transform(
                current_squares.begin(), current_squares.end(),             // The input source
                to_squares_1.begin(),                      // The output destination
                [](uint8_t x) { return x + 8; } );
        valid_to_square_1 = regular_move_onto_another_piece_check(current_squares, to_squares_1, bitboard_all);
    } else {
        std::transform(
                current_squares.begin(), current_squares.end(),             // The input source
                to_squares_1.begin(),                      // The output destination
                [](uint8_t x) { return x - 8; } ); 
        valid_to_square_1 = regular_move_onto_another_piece_check(current_squares, to_squares_1, bitboard_all);
    }

    // Check if single pawn move is valid
    std::vector<uint8_t> to_squares_2(valid_to_square_1[0].size());
    std::cout << valid_to_square_1[0].size() << std::endl;
    if (valid_to_square_1[0].size() > 0) {
        std::vector<std::vector<uint8_t> > valid_to_square_2;
        if (bit_rank(current_squares[0]) == 2) { // Use bit_rank to get the rank of the first square
            std::transform(
                valid_to_square_1[1].begin(), valid_to_square_1[1].end(),             // The input source
                to_squares_2.begin(),                      // The output destination
                [](uint8_t x) { return x + 8; } );    // The transforming function
            valid_to_square_2 = regular_move_onto_another_piece_check(valid_to_square_1[0], to_squares_2, bitboard_all);
            std::transform(
                valid_to_square_2[0].begin(), valid_to_square_2[0].end(),
                valid_to_square_2[0].begin(),
                [](uint8_t x) { return x - 8; } );
        } else {
            std::transform(
                valid_to_square_1[1].begin(), valid_to_square_1[1].end(),             // The input source
                to_squares_2.begin(),                      // The output destination
                [](uint8_t x) { return x - 8; } );    // The transforming function
            valid_to_square_2 = regular_move_onto_another_piece_check(valid_to_square_1[0], to_squares_2, bitboard_all);
            std::transform(
                valid_to_square_2[0].begin(), valid_to_square_2[0].end(),
                valid_to_square_2[0].begin(),
                [](uint8_t x) { return x + 8; } );
        }

        return valid_to_square_2;
    } else {
        // If single pawn move is not valid, return an empty vector
        return {};
    }
}



std::vector<uint16_t> possible_moves(game_state &game) {
    colour_bitboards current;
    colour_bitboards opposition;
    std::vector<uint16_t> moves;
    if (game.turn) {
        current = game.W_bitboards;
        opposition = game.B_bitboards;
    }
    else {
        current = game.B_bitboards;
        opposition = game.W_bitboards;
    }
    current.Colour = current.P | current.N | current.B | current.R | current.Q | current.K;
    opposition.Colour = opposition.P | opposition.N | opposition.B | opposition.R | opposition.Q | opposition.K;
    uint64_t bitboard_all = current.Colour | opposition.Colour;

    // Generate Current Pawn Moves
    std::vector<uint8_t> Current_Pawn_squares = multiple_bits_to_indices(current.P);
    std::vector<uint8_t> Current_pawn_to_squares;
    std::vector<uint8_t> Current_Pawn_squares_double_move;
    if(game.turn) {
        Current_pawn_to_squares = multiple_bits_to_indices(current.P << 8);
        Current_Pawn_squares_double_move = multiple_bits_to_indices(current.P & Rank_Mask[1]);
    }
    else {
        Current_pawn_to_squares = multiple_bits_to_indices(current.P >> 8);
        Current_Pawn_squares_double_move = multiple_bits_to_indices(current.P & Rank_Mask[6]);
    }
    std::vector<std::vector<uint8_t> > pawn_1_move_valid_indices = regular_move_onto_another_piece_check(Current_Pawn_squares,
                                                                            Current_pawn_to_squares, bitboard_all);
    std::vector<std::vector<uint8_t> > pawn_2_move_valid_indices = double_pawn_move_check(Current_Pawn_squares_double_move, bitboard_all);               
    uint8_t special = 0;
    std::cout << pawn_1_move_valid_indices[0].size() << pawn_1_move_valid_indices[1].size() << std::endl;
    std::cout << pawn_2_move_valid_indices[0].size() << pawn_2_move_valid_indices[1].size() << std::endl;
    for(int i = 0; i < pawn_1_move_valid_indices[0].size(); i++) {
        std::cout << static_cast<int>(pawn_1_move_valid_indices[1][i]) << std::endl;
        moves.push_back(indices_to_move(pawn_1_move_valid_indices[0][i], pawn_1_move_valid_indices[1][i], special));
        std::cout << static_cast<int>(pawn_1_move_valid_indices[1][i]) << std::endl;
    }
    std::cout << "here";
    for(int i = 0; i < pawn_2_move_valid_indices[0].size(); i++) {
        std::cout << static_cast<int>(pawn_2_move_valid_indices[1][i]) << std::endl;
        moves.push_back(indices_to_move(pawn_2_move_valid_indices[0][i], pawn_2_move_valid_indices[1][i], special));
    }
    return moves;
}
