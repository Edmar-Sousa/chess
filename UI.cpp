#include "UI.hpp"
#include "Board.hpp"
#include "Constants.hpp"
#include <raylib.h>
#include <string>

UI::UI(Board board) {
  this->board = board;

  blackHouse = {183, 192, 216, 255};
  whiteHouse = {232, 237, 249, 255};
  labelColor = {52, 54, 76};

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Chess Engine");
  SetTargetFPS(FPS);
}

UI::~UI() { CloseWindow(); }

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

  for (int col = 0; col < COLS; col++) {
    for (int row = 0; row < ROWS; row++) {
      house = table[index++] ? whiteHouse : blackHouse;

      DrawText(std::to_string(8 - col).c_str(), BOARD_LEFT_PADDING / 2,
               POSITION_TILE(col, BOARD_TILE_SIZE / 2), BOARD_LABEL_SIZE,
               labelColor);

      char labelColumn = 'A' + col;
      char labelText[2] = {labelColumn, '\0'};

      DrawText(labelText,
               POSITION_TILE(col, BOARD_TILE_SIZE / 2 + BOARD_LEFT_PADDING),
               WINDOW_HEIGHT - BOARD_BOTTOM_PADDING / 2, BOARD_LABEL_SIZE,
               labelColor);

      DrawRectangle(POSITION_TILE(col, BOARD_LEFT_PADDING),
                    POSITION_TILE(row, BOARD_TOP_PADDING), BOARD_TILE_SIZE,
                    BOARD_TILE_SIZE, house);
    }
  }
}
