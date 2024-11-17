#include "Board.hpp"
#include "Constants.hpp"

Board::Board() {
  int invert = 1;

  for (int index = 0; index < COLS * ROWS; index++) {
    boardColors[index] = (index + invert) % 2;

    if ((index + 1) % ROWS == 0)
      invert = !invert;
  }
}

void Board::draw() {
  std::cout << "\n";

  for (int index = 0; index < COLS * ROWS; index++)
    std::cout << ' ' << boardColors[index]
              << ((index + 1) % ROWS == 0 ? '\n' : ' ');

  std::cout << "\n";
}

int *Board::getBoard() { return this->boardColors; }
int *Board::getPieces() { return this->pieces; }
