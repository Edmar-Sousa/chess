#include "Board.hpp"
#include "Contants.hpp"


Board::Board() 
{
    int invert = 1;

    for (int index = 0; index < COLS * ROWS; index++) {
        board[index] = (index + invert) % 2;

        if ((index + 1) % ROWS == 0) 
            invert = !invert;
    }
}


void Board::draw() 
{
    std::cout << "\n";

    for (int index = 0; index < COLS * ROWS; index++)
        std::cout << ' ' << board[index] << ((index + 1) % ROWS == 0 ? '\n' : ' ');
    
    std::cout << "\n";
}

