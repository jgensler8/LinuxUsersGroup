#include "tile.h"

#define TILE_BASE_SIZE 10
#define WALL 'X'

Tile::Tile(){
  sizeX = TILE_BASE_SIZE;
  sizeY = TILE_BASE_SIZE;
}

int Tile::get_height(){
  return sizeY;
}

int Tile::get_width(){
  return sizeX;
}

//TODO make tiles into 8+optional "tile types"
void Tile::layout_init( int y, int x, int maxTiles){
  int max = maxTiles*TILE_BASE_SIZE;
  //allocate the layout of a tile
  layout = new char*[TILE_BASE_SIZE];
  for( int i=0; i<sizeX; ++i)
    layout[i] = new char[TILE_BASE_SIZE];
    
  for( int i=0; i<sizeY; ++i){
      if(x==0) layout[i][0] = WALL;  
      //if(x==max-1) layout[i][TILE_BASE_SIZE-1] = WALL;
  }
  for( int j=0; j<sizeX; ++j){
      //if(y==0) layout[0][j] = WALL;
      //if(x==max-1) layout[j][sizeY-1] = WALL;
  }
}

void Tile::print_tile( int y, int x){
  for( int i=0; i<sizeX; ++i)
    for( int j=0; j<sizeY; ++j)
      mvprintw( y+j, x+i, "%c", layout[i][j]);
}

int Tile::is_collision( int y, int x){
  mvprintw(61,0, "char %c", layout[x][y]);
  return layout[x][y] == WALL ? 1 : 0;
} 
