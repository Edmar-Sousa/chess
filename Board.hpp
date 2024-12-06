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

  uint64_t pawnsBlack;
  uint64_t rooksBlack;
  uint64_t knightsBlack;
  uint64_t bishopsBlack;
  uint64_t queensBlack;
  uint64_t kingsBlack;

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

  uint64_t getPiecesBlack();
  uint64_t getPawnsBlack();
  uint64_t getRooksBlack();
  uint64_t getBishopsBlack();
  uint64_t getKnightsBlack();
  uint64_t getQueensBlack();
  uint64_t getKingsBlack();

  void draw();
};

#endif