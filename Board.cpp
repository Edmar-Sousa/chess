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

  pawnsWhite = 0x00FF000000000000;
  rooksWhite = 0x8100000000000000;
  knightsWhite = 0x4200000000000000;
  bishopsWhite = 0x2400000000000000;
  queensWhite = 0x0800000000000000;
  kingsWhite = 0x1000000000000000;
}

void Board::draw() {
  std::cout << "\n";

  for (int index = 0; index < COLS * ROWS; index++)
    std::cout << ' ' << boardColors[index] << ((index + 1) % ROWS == 0 ? '\n' : ' ');

  std::cout << "\n";
}

int *Board::getBoard() { return this->boardColors; }

uint64_t Board::getPiecesWhite() {
  return pawnsWhite & rooksWhite & knightsWhite & bishopsWhite & kingsWhite & queensWhite;
}

uint64_t Board::getPawnsWhite() { return pawnsWhite; }
uint64_t Board::getRooksWhite() { return rooksWhite; }
uint64_t Board::getBishopsWhite() { return bishopsWhite; }
uint64_t Board::getKnightsWhite() { return knightsWhite; }
uint64_t Board::getQueensWhite() { return queensWhite; }
uint64_t Board::getKingsWhite() { return kingsWhite; }

uint64_t Board::getPawnsBlack() { return pawnsBlack; }
uint64_t Board::getRooksBlack() { return rooksBlack; }
uint64_t Board::getBishopsBlack() { return bishopsBlack; }
uint64_t Board::getKnightsBlack() { return knightsBlack; }
uint64_t Board::getQueensBlack() { return queensBlack; }
uint64_t Board::getKingsBlack() { return kingsBlack; }