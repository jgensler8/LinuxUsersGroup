#include <cstdlib>
#include "ncurses.h"
#include "tile.h"
#define BOARD_BASE_SIZE 10

class Board{
  public:
    Board();
    Board( int);
    void print_board();
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
    layout[i] = new Tile;
}

Board::Board( int size){
  sizeX = size;
  sizeY = size;
}

void Board::print_board(){
  int height = layout[0][0].get_height();
  int width = layout[0][0].get_width();

  for( int i=0; i<sizeX; ++i){
    for( int j=0; j<sizeY; ++j){
      layout[i][j].print_tile( i*height, j*width);
    }
  } 
}
