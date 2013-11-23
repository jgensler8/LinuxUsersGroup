#include "board.h"

#define BOARD_BASE_SIZE 5

Board::Board(){
  sizeX = BOARD_BASE_SIZE;
  sizeY = BOARD_BASE_SIZE;
  layout = new Tile*[BOARD_BASE_SIZE];
  for( int i=0; i<BOARD_BASE_SIZE; ++i)
    layout[i] = new Tile[BOARD_BASE_SIZE];
  
  tileX = layout[0][0].get_width();
  tileY = layout[0][0].get_height();

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
  for( int i=0; i<sizeX; ++i) // i tiles wide
    for( int j=0; j<sizeY; ++j) // j tiles tall
      layout[i][j].print_tile( farDown+i*tileX, j*tileY);
}

int Board::is_collision( int x, int y){
  if( x > tileX*BOARD_BASE_SIZE-1 || x < 1) return 0;
  else if( y > tileY*BOARD_BASE_SIZE-1 || y < 1) return 0;
  else return 1;
}
