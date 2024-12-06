#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Constants.hpp"
#include <cstdint>

// temporary to show image from pieces
// change to bitboard
enum Pieces {
  BLACK_PAWN,
  BLACK_ROOK,
  BLACK_BISHOP,
  BLACK_KNIGHT,
  BLACK_KING,
  BLACK_QUEEN,

  WHITE_PAWN,
  WHITE_ROOK,
  WHITE_BISHOP,
  WHITE_KNIGHT,
  WHITE_KING,
  WHITE_QUEEN,

  EMPTY,
};

class Board {
  int boardColors[COLS * ROWS];

  uint64_t pawnsWhite;
  uint64_t rooksWhite;
  uint64_t knightsWhite;
  uint64_t bishopsWhite;
  uint64_t queensWhite;
  uint64_t kingsWhite;

public:
  Board();

  int *getBoard();

  uint64_t getPiecesWhite();
  uint64_t getPawnsWhite();
  uint64_t getRooksWhite();
  uint64_t getBishopsWhite();
  uint64_t getKnightsWhite();
  uint64_t getQueensWhite();
  uint64_t getKingsWhite();

  void draw();
};

#endif