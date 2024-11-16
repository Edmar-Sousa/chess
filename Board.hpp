#ifndef  __BOARD_HPP__
#define  __BOARD_HPP__

#include "Contants.hpp"


class Board
{
    int board[COLS * ROWS];

public:
    Board();

    void draw();
};

#endif