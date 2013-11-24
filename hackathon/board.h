#include "ncurses.h"
#include <cstdlib>
#include "time.h"

#ifndef BOARD_H
#define BOARD_H
class Board{
  public:
    Board( int);
    void print_board();
    int is_collision( int, int);
    int not_terrain( int, int);
    void set_layout( int, int, char);
    int is_bomb( int, int);
    void detonate_bomb( int, int, char);
    int count_destroyed();
  private:
    char** layout;
    int base_size;
};
#endif
