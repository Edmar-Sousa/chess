#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__

#include <iostream>
#include <raylib.h>


#define COLS               8
#define ROWS               8

#define BOARD_TILE_SIZE       72

#define BOARD_TOP_PADDING     12
#define BOARD_BOTTOM_PADDING  48
#define BOARD_LEFT_PADDING    48
#define BOARD_RIGHT_PADDING   12


#define WINDOW_WIDTH   BOARD_LEFT_PADDING + (BOARD_TILE_SIZE * COLS) + BOARD_RIGHT_PADDING
#define WINDOW_HEIGHT  BOARD_TOP_PADDING + (BOARD_TILE_SIZE * ROWS) + BOARD_BOTTOM_PADDING

typedef unsigned long long U64;

#endif