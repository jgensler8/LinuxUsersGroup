#include "ncurses.h"
#include <cstdlib>

#ifndef TILE_H
#define TILE_H
class Tile{
  public:
    Tile();
    int get_width();
    int get_height();
    void print_tile( int, int);
    void layout_init( int, int, int);
    int is_collision( int, int);
  private:
    int sizeX;
    int sizeY;
    char** layout;
};
#endif