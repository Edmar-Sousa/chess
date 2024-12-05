#include "Board.hpp"
#include "Constants.hpp"

Board::Board() {
  int invert = 1;

  for (int index = 0; index < COLS * ROWS; index++) {
    boardColors[index] = (index + invert) % 2;

    if ((index + 1) % ROWS == 0)
      invert = !invert;
  }

  pawnsWhite = 0x000000000000FF00;
  rooksWhite = 0x0000000000000081;
  knightsWhite = 0x0000000000000042;
  bishopsWhite = 0x0000000000000024;
  queensWhite = 0x0000000000000008;
  kingsWhite = 0x0000000000000010;
}

void Board::draw() {
  std::cout << "\n";

  for (int index = 0; index < COLS * ROWS; index++)
    std::cout << ' ' << boardColors[index]
              << ((index + 1) % ROWS == 0 ? '\n' : ' ');

  std::cout << "\n";
}

int *Board::getBoard() { return this->boardColors; }

uint64_t Board::getPieces() {
  return pawnsWhite & rooksWhite & knightsWhite & bishopsWhite & kingsWhite &
         queensWhite;
}

uint64_t Board::getPawns() { return pawnsWhite; }
uint64_t Board::getRooks() { return rooksWhite; }
