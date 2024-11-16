#ifndef __UI_HPP__
#define __UI_HPP__

#include "Board.hpp"
#include "Constants.hpp"

#define FPS 60

class UI {
  Board board;

  void drawTiles();

public:
  UI(Board board);
  ~UI();

  void drawBoard();
};

#endif