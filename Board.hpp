#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Constants.hpp"

class Board {
  int boardColors[COLS * ROWS];

public:
  Board();

  int *getBoard();
  void draw();
};

#endif