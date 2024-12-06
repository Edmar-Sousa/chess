#include "UI.hpp"
#include "Board.hpp"
#include "Constants.hpp"
#include <cstdint>
#include <cstdlib>
#include <raylib.h>

UI::UI(Board board) {
  this->board = board;

  blackHouse = {183, 192, 216, 255};
  whiteHouse = {232, 237, 249, 255};
  labelColor = {52, 54, 76, 255};

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Engine");

  piecesTexture = LoadTexture("./assets/pieces.png");
  SetTargetFPS(FPS);
}

UI::~UI() {
  UnloadTexture(piecesTexture);
  CloseWindow();
}

void UI::drawBoard() {
  while (!WindowShouldClose()) {

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    drawTiles();

    EndDrawing();
    // End Draw
  }
}

void UI::drawTiles() {
  int *table = board.getBoard();
  int index = 0;

  Color house;

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      house = table[index] ? whiteHouse : blackHouse;

      DrawText(std::to_string(8 - col).c_str(), BOARD_LEFT_PADDING / 2, POSITION_TILE(col, BOARD_TILE_SIZE / 2),
               BOARD_LABEL_SIZE, labelColor);

      char labelColumn = 'A' + col;
      char labelText[2] = {labelColumn, '\0'};

      DrawText(labelText, POSITION_TILE(col, BOARD_TILE_SIZE / 2 + BOARD_LEFT_PADDING),
               WINDOW_HEIGHT - BOARD_BOTTOM_PADDING / 2, BOARD_LABEL_SIZE, labelColor);

      DrawRectangle(POSITION_TILE(col, BOARD_LEFT_PADDING), POSITION_TILE(row, BOARD_TOP_PADDING), BOARD_TILE_SIZE,
                    BOARD_TILE_SIZE, house);

      index += 1;
    }
  }

  drawPawns();
}

void UI::drawPawns() {
  uint64_t pawnsBitboard = board.getPawns();
  uint64_t rooksBitboard = board.getRooks();

  int square = 0;

  Rectangle source;
  Vector2 position;

  for (int rank = ROWS - 1; rank >= 0; --rank) {
    for (int file = 0; file < COLS; file++) {
      square = rank * 8 + file;
      position = POSITION_PIECE(rank, file);

      if (pawnsBitboard >> square & 1) {
        source = CLIP_TEXTURE(PAWN_TEXTURE_OFFSET_X, PAWN_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (rooksBitboard >> square & 1) {
        source = CLIP_TEXTURE(ROOK_TEXTURE_OFFSET_X, ROOK_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }
    }
  }
}

void UI::drawPiece(int col, int row, int piece) {
  float posx = 0.0;
  float posy = 0.0;

  switch (piece) {
  case Pieces::BLACK_PAWN:
  case Pieces::BLACK_ROOK:
  case Pieces::BLACK_KNIGHT:
  case Pieces::BLACK_BISHOP:
  case Pieces::BLACK_KING:
  case Pieces::BLACK_QUEEN:
    posx = (float)BOARD_TILE_SIZE * piece;
    posy = 0.0;
    break;

  case Pieces::WHITE_PAWN:
  case Pieces::WHITE_ROOK:
  case Pieces::WHITE_KNIGHT:
  case Pieces::WHITE_BISHOP:
  case Pieces::WHITE_KING:
  case Pieces::WHITE_QUEEN:
    posx = (float)BOARD_TILE_SIZE * (piece - 6);
    posy = BOARD_TILE_SIZE;
    break;

  case Pieces::EMPTY:
    return;
  }

  Rectangle source = {posx, posy, BOARD_TILE_SIZE, BOARD_TILE_SIZE};
  Vector2 position = {(float)col * BOARD_TILE_SIZE + BOARD_LEFT_PADDING,
                      (float)row * BOARD_TILE_SIZE + BOARD_TOP_PADDING};

  DrawTextureRec(piecesTexture, source, position, WHITE);
}
