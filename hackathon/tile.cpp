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
  private:
    int sizeX;
    int sizeY;
    char** layout;
    void layout_init();
};

Tile::Tile(){
  sizeX = TILE_BASE_SIZE;
  sizeY = TILE_BASE_SIZE;
  layout_init();
}

Tile::Tile( int size){
  sizeX = size;
  sizeY = size;
  layout_init();
}

int Tile::get_height(){
  return sizeY;
}

int Tile::get_width(){
  return sizeX;
}

void Tile::layout_init(){
  for( int i=0; i<sizeX; ++i)
    for( int j=0; j<sizeY; ++j)
      layout[i][j] = WALL;
}

void Tile::print_tile( int x, int y){
  for( int i=0; i<sizeX; ++i){
    for( int j=0; j<sizeY; ++j){
      mvprintw( x+i, y+j, "%c", layout[i][j]);
    }
  }
}
