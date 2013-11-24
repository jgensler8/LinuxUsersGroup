#include "board.h"

#define WALL 'X'
#define GROUND '%'
#define BOMB 'B'
#define NUM_BOMBS 40

Board::Board( int future_base_size){
  base_size = future_base_size;
  layout = new char*[base_size];
  for( int i=0; i<base_size; ++i)
    layout[i] = new char[base_size];
  
  for( int i=0; i<base_size; ++i)
    for( int j=0; j<base_size; ++j){
      if( j==0){
        attrset( COLOR_PAIR(1) );
        layout[j][i] = WALL;
        attrset( A_NORMAL );
      }
      else if( j==base_size-1) layout[j][i] = WALL;
      else if( i==0){
        attron(COLOR_PAIR(2)); 
        layout[j][i] = WALL;
        attrset( A_NORMAL );
      }
      else if( i==base_size-1) layout[j][i] = WALL;
      else layout[i][j] = GROUND;
    }
  
  for( int i=0; i<NUM_BOMBS; ++i){
    srand(time(NULL));
    int randx = rand()%base_size;
    int randy = rand()%base_size;
    layout[randy][randx] = BOMB;
  }

}

void Board::print_board(){
  for( int i=0; i<base_size; ++i) // i tiles wide
    for( int j=0; j<base_size; ++j) // j tiles tall
      mvprintw( j, i, "%c", layout[j][i] );
}

int Board::is_collision( int y, int x){
  if( y <= 0 || y >= base_size - 1) return 1;
  else if ( x <= 0 || x >= base_size -1) return 1;
  else return 0;
}

int Board::not_terrain(int y, int x){
  return ( layout[y][x] != GROUND && layout[y][x] != BOMB) ? 1 : 0;
}

void Board::set_layout(int y, int x, char c){
  layout[y][x] = c;
}

int Board::is_bomb( int y, int x){
  return !is_collision( y,x) && layout[y][x] == BOMB;
}

void Board::detonate_bomb( int y, int x, char c){
  layout[y][x] = c;
  int bombSize = rand()%30 +10;
  for( int i=-bombSize; i<bombSize; ++i){
    if( !is_collision( y+i, x) ) set_layout( y+i, x, '_');
    if( !is_collision( y, x+i) ) set_layout( y, x+i, '_');
    if( is_bomb( y+i, x) ) detonate_bomb( y+i, x, '_');
    if( is_bomb( y, x+i) ) detonate_bomb( y, x+i, '_');
    
  } 
  for( int i=-bombSize/2; i<bombSize/2; ++i){
    if( !is_collision( y+i, x+i) ) set_layout( y+i, x+i, '_');
    if( !is_collision( y-i, x-i) ) set_layout( y-i, x-i, '_');
    if( is_bomb( y+i, x+i) ) detonate_bomb( y+i, x, '_');
    if( is_bomb( y-i, x-i) ) detonate_bomb( y, x+i, '_');
  } 
  for( int i=-bombSize/2; i<bombSize/2; ++i){
    if( !is_collision( y-i, x-i) ) set_layout( y-i, x-i, '_');
    if( !is_collision( y+i, x+i) ) set_layout( y+i, x+i, '_');
    if( is_bomb( y-i, x-i) ) detonate_bomb( y+i, x, '_');
    if( is_bomb( y+i, x+i) ) detonate_bomb( y, x+i, '_');
  } 
}

int Board::count_destroyed(){
  int total = 0;
  for( int i=0; i<base_size; ++i)
    for( int j=0; j<base_size; ++j)
      if( layout[j][i] == '_' ) ++total;
  return total;
}
