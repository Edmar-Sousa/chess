#include "UI.hpp"
#include "Board.hpp"
#include "Constants.hpp"
#include <cstdint>
#include <cstdlib>
#include <ostream>
#include <raylib.h>

UI::UI(Board board) {
  this->board = board;

  blackHouseColor = {183, 192, 216, 255};
  whiteHouseColor = {232, 237, 249, 255};
  labelColor = {52, 54, 76, 255};
  selectedHouseColor = {177, 166, 252, 255};

  boardState = UI_STATE::HOUSE_UNSELECTED;

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

    // Update
    getHouseClicked();

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    drawTiles();
    drawPieces();

    EndDrawing();
    // End Draw
  }
}

int inline UI::clickInsideBoard(int position, int margin) {
  return (position - margin >= 0) && (position <= BOARD_TILE_SIZE * COLS + margin);
}

std::ostream& operator<<(std::ostream& os, BoardHouses house) {
  char file = (int) 'A' + 7 - (house % 8);
  int rank = house / 8 + 1;

  os << file << rank;
  return os;
}

void UI::calculateHouseFromPosition(Vector2 &position) {
  int rank = (position.x - BOARD_LEFT_PADDING) / BOARD_TILE_SIZE;
  int file = (position.y - BOARD_TOP_PADDING) / BOARD_TILE_SIZE;

  uint64_t whiteBitboard = board.getPiecesWhite();

  BoardHouses house = static_cast<BoardHouses>((7 - file) * 8 + 7 - rank);
  
  if (whiteBitboard >> house & 1) {
    boardState = UI_STATE::HOUSE_SELECTED;
    selectedHouseX = rank;
    selectedHouseY = file;
    
    std::cout << house << std::endl;
  }

}

void UI::getHouseClicked() {
  if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
    Vector2 mousePosition = GetMousePosition();

    if (clickInsideBoard(mousePosition.x, BOARD_LEFT_PADDING) && clickInsideBoard(mousePosition.y, BOARD_TOP_PADDING))
      calculateHouseFromPosition(mousePosition);
  }
}

void UI::drawTiles() {
  int *table = board.getBoard();
  int index = 0;

  Color house;

  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      house = table[index] ? whiteHouseColor : blackHouseColor;

      if (boardState == UI_STATE::HOUSE_SELECTED && col == selectedHouseX && row == selectedHouseY)
        house = selectedHouseColor;

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
}

void UI::drawPieces() {
  uint64_t pawnsWhite = board.getPawnsWhite();
  uint64_t rooksWhite = board.getRooksWhite();
  uint64_t bishopsWhite = board.getBishopsWhite();
  uint64_t knightsWhite = board.getKnightsWhite();
  uint64_t queenWhite = board.getQueensWhite();
  uint64_t kingWhite = board.getKingsWhite();

  uint64_t pawnsBlack = board.getPawnsBlack();
  uint64_t rooksBlack = board.getRooksBlack();
  uint64_t bishopsBlack = board.getBishopsBlack();
  uint64_t knightsBlack = board.getKnightsBlack();
  uint64_t queenBlack = board.getQueensBlack();
  uint64_t kingBlack = board.getKingsBlack();

  int square = 0;

  Rectangle source;
  Vector2 position;

  for (int rank = ROWS - 1; rank >= 0; --rank) {
    for (int file = 0; file < COLS; file++) {
      square = rank * 8 + file;
      position = POSITION_PIECE(rank, file);

      if (pawnsWhite >> square & 1) {
        source = CLIP_TEXTURE(PAWN_TEXTURE_OFFSET_X, WHITE_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (rooksWhite >> square & 1) {
        source = CLIP_TEXTURE(ROOK_TEXTURE_OFFSET_X, WHITE_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (knightsWhite >> square & 1) {
        source = CLIP_TEXTURE(KNIGHT_TEXTURE_OFFSET_X, WHITE_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (bishopsWhite >> square & 1) {
        source = CLIP_TEXTURE(BISHOPS_TEXTURE_OFFSET_X, WHITE_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (queenWhite >> square & 1) {
        source = CLIP_TEXTURE(QUEEN_TEXTURE_OFFSET_X, WHITE_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (kingWhite >> square & 1) {
        source = CLIP_TEXTURE(KING_TEXTURE_OFFSET_X, WHITE_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      if (pawnsBlack >> square & 1) {
        source = CLIP_TEXTURE(PAWN_TEXTURE_OFFSET_X, BLACK_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (rooksBlack >> square & 1) {
        source = CLIP_TEXTURE(ROOK_TEXTURE_OFFSET_X, BLACK_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (knightsBlack >> square & 1) {
        source = CLIP_TEXTURE(KNIGHT_TEXTURE_OFFSET_X, BLACK_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (bishopsBlack >> square & 1) {
        source = CLIP_TEXTURE(BISHOPS_TEXTURE_OFFSET_X, BLACK_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (queenBlack >> square & 1) {
        source = CLIP_TEXTURE(QUEEN_TEXTURE_OFFSET_X, BLACK_TEXTURE_OFFSET_Y);
        DrawTextureRec(piecesTexture, source, position, WHITE);
      }

      else if (kingBlack >> square & 1) {
        source = CLIP_TEXTURE(KING_TEXTURE_OFFSET_X, BLACK_TEXTURE_OFFSET_Y);
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
