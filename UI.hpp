#ifndef __UI_HPP__
#define __UI_HPP__

#include "Board.hpp"
#include "Constants.hpp"
#include <raylib.h>

#define FPS 60
#define POSITION_TILE(pos, padding) pos *BOARD_TILE_SIZE + padding

#define BOARD_LABEL_SIZE 18

#define BOARD_TILE_SIZE 72

#define BOARD_TOP_PADDING 12
#define BOARD_BOTTOM_PADDING 48
#define BOARD_LEFT_PADDING 48
#define BOARD_RIGHT_PADDING 12

#define WINDOW_WIDTH BOARD_LEFT_PADDING + (BOARD_TILE_SIZE * COLS) + BOARD_RIGHT_PADDING
#define WINDOW_HEIGHT BOARD_TOP_PADDING + (BOARD_TILE_SIZE * ROWS) + BOARD_BOTTOM_PADDING

#define CLIP_TEXTURE(row, col)                                                                                         \
  { row *BOARD_TILE_SIZE, col *BOARD_TILE_SIZE, BOARD_TILE_SIZE, BOARD_TILE_SIZE }

#define POSITION_PIECE(row, col)                                                                                       \
  { (float)col *BOARD_TILE_SIZE + BOARD_LEFT_PADDING, (float)(ROWS - row - 1) * BOARD_TILE_SIZE + BOARD_TOP_PADDING }

#define WHITE_TEXTURE_OFFSET_Y 1

#define PAWN_TEXTURE_OFFSET_X 0
#define ROOK_TEXTURE_OFFSET_X 1
#define BISHOPS_TEXTURE_OFFSET_X 2
#define KNIGHT_TEXTURE_OFFSET_X 3
#define QUEEN_TEXTURE_OFFSET_X 5

class UI {
  Board board;

  Color blackHouse;
  Color whiteHouse;
  Color labelColor;

  Texture2D piecesTexture;

  void drawTiles();
  void drawPawns();

  void drawPiece(int col, int row, int piece);

public:
  UI(Board board);
  ~UI();

  void drawBoard();
};

#endif