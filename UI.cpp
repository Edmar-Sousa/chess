#include "UI.hpp"
#include "Board.hpp"
#include "Constants.hpp"
#include <raylib.h>

UI::UI(Board board) {
  this->board = board;

  blackHouse = {183, 192, 216, 255};
  whiteHouse = {232, 237, 249, 255};

  std::cout << "WINDOW: " << WINDOW_WIDTH << 'x' << WINDOW_HEIGHT << std::endl;

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

      DrawRectangle(col * BOARD_TILE_SIZE, row * BOARD_TILE_SIZE,
                    BOARD_TILE_SIZE, BOARD_TILE_SIZE, house);
    }
  }
}
