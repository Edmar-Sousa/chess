#include "UI.hpp"
#include "Constants.hpp"
#include <raylib.h>

UI::UI(Board board) {
  this->board = board;

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

    DrawText("Basic Window", BOARD_LEFT_PADDING, 0, 20, LIGHTGRAY);
    EndDrawing();
    // End Draw
  }
}

void UI::drawTiles() {}
