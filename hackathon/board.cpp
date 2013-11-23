#include <cstdlib>
#include "ncurses.h"
#include "tile.h"
#define BOARD_BASE_SIZE 5

class Board{
  public:
    Board();
    Board( int);
    void print_board( int);
  private:
    int sizeX;
    int sizeY;
    Tile** layout;
};

Board::Board(){
  sizeX = BOARD_BASE_SIZE;
  sizeY = BOARD_BASE_SIZE;
  layout = new Tile*[BOARD_BASE_SIZE];
  for( int i=0; i<BOARD_BASE_SIZE; ++i)
    layout[i] = new Tile[BOARD_BASE_SIZE];
  
  for( int i=0; i<BOARD_BASE_SIZE; ++i)
    for( int j=0; j<BOARD_BASE_SIZE; ++j)
      layout[i][j].layout_init( i, j, BOARD_BASE_SIZE-1);
}

Board::Board( int size){
  sizeX = size;
  sizeY = size;
  layout = new Tile*[BOARD_BASE_SIZE];
  for( int i=0; i<BOARD_BASE_SIZE; ++i)
    layout[i] = new Tile;

  for( int i=0; i<BOARD_BASE_SIZE; ++i)
    for( int j=0; j<BOARD_BASE_SIZE; ++j)
      layout[i][j].layout_init( i, j, BOARD_BASE_SIZE-1);
}

void Board::print_board( int farDown){
  int height = layout[0][0].get_height();
  int width = layout[0][0].get_width();

  for( int i=0; i<sizeX; ++i) // i tiles wide
    for( int j=0; j<sizeY; ++j) // j tiles tall
      layout[i][j].print_tile( farDown+i*height, j*width);
}
