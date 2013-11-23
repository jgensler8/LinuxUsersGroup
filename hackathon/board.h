#include "tile.h"
#include "ncurses.h"
#include <cstdlib>

#ifndef BOARD_H
#define BOARD_H
class Board{
   public:
    Board();
    void print_board( int);
    int is_collision( int, int);
  private:
    int tileX; // size of tile in X direction
    int tileY; // size of tile in Y direction
    int sizeX; // # of tiles in X direction (width)
    int sizeY; // # of tiles in Y direction (height)
    Tile** layout;
};
#endif
