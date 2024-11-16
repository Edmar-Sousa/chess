#ifndef  __BOARD_HPP__
#define  __BOARD_HPP__

#include "Constants.hpp"


class Board
{
    int board[COLS * ROWS];

public:
    Board();

    void draw();
};

#endif