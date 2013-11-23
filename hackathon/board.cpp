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
      layout[j][i].layout_init( j, i, BOARD_BASE_SIZE);
}

void Board::print_board( int farDown){
  for( int i=0; i<sizeX; ++i) // i tiles wide
    for( int j=0; j<sizeY; ++j) // j tiles tall
      layout[i][j].print_tile( farDown+j*tileY, i*tileX);
}

int collision_helper( int totalDist, int tileLen){
  int k = 1;
  while( tileLen*k < totalDist) ++k;
  return k-1; //finds the actual tile
}
int Board::is_collision( int y, int x){
  int squareI = x%tileX;
  int squareJ = y%tileX;
  int tileI = collision_helper( x, tileX);
  int tileJ = collision_helper( y, tileY);

  mvprintw( 60, 0, "sqi%d sqj%d ti%d tj%d", squareJ, squareI, tileJ, tileI);

  return layout[tileI][tileJ].is_collision(squareJ, squareI);
}
