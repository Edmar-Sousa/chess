#ifndef  __UI_HPP__
#define  __UI_HPP__

#include "Board.hpp"
#include "Constants.hpp"


class UI {
    Board board;

public:
    UI(Board board): board(board) {}

    void drawBoard();
};


#endif