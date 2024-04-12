#include "Gamestate.hpp"
#include <string>

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

std::vector<uint16_t> possible_moves(game_state &game) {
    colour_bitboards current;
    colour_bitboards opposition;
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
    
}