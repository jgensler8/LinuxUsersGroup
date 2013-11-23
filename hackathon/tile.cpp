#include <cstdlib>
#include "ncurses.h"
#define TILE_BASE_SIZE 10
#define WALL 'X'

class Tile{
  public:
    Tile();
    Tile( int);
    int get_width();
    int get_height();
    void print_tile(int, int);
    void layout_init(int, int, int);
  private:
    int sizeX;
    int sizeY;
    char** layout;
};

Tile::Tile(){
  sizeX = TILE_BASE_SIZE;
  sizeY = TILE_BASE_SIZE;
}

Tile::Tile( int size){
  sizeX = size;
  sizeY = size;
}

int Tile::get_height(){
  return sizeY;
}

int Tile::get_width(){
  return sizeX;
}

//TODO make tiles into 8+optional "tile types"
void Tile::layout_init( int x, int y, int max){
  layout = new char*[TILE_BASE_SIZE];
  for( int i=0; i<sizeX; ++i)
    layout[i] = new char[TILE_BASE_SIZE];
    
  for( int j=0; j<sizeY; ++j){
      if(x==0) layout[0][j] = WALL; //top wall
      if(x==max) layout[TILE_BASE_SIZE-1][j] = WALL; //bottom wall
  }
  for( int i=0; i<sizeX; ++i){
      if(y==0) layout[i][0] = WALL; //left wall
      if(y==max) layout[i][sizeY-1] = WALL; // right wall
  }
}

void Tile::print_tile( int x, int y){
  for( int i=0; i<sizeX; ++i){
    for( int j=0; j<sizeY; ++j){
      mvprintw( x+i, y+j, "%c", layout[i][j]);
    }
  }
}
