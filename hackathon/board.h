#include "tile.h"
#include "ncurses.h"
#include <cstdlib>

#ifndef BOARD_H
#define BOARD_H
class Board{
   public:
    Board();
    Board( int);
    void print_board( int);
    int is_collision( int, int);
  private:
    int tileX;
    int tileY;
    int sizeX;
    int sizeY;
    Tile** layout;
};
#endif
