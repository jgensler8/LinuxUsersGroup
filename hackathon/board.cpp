#include "board.h"

#define BASE_SIZE 60
#define WALL 'X'
#define GROUND '%'
#define BOMB 'B'
#define NUM_BOMBS 40

Board::Board(){
  layout = new char*[BASE_SIZE];
  for( int i=0; i<BASE_SIZE; ++i)
    layout[i] = new char[BASE_SIZE];
  
  for( int i=0; i<BASE_SIZE; ++i)
    for( int j=0; j<BASE_SIZE; ++j){
      if( j==0){
        attrset( COLOR_PAIR(1) );
        layout[j][i] = WALL;
        attrset( A_NORMAL );
      }
      else if( j==BASE_SIZE-1) layout[j][i] = WALL;
      else if( i==0){
        attron(COLOR_PAIR(2)); 
        layout[j][i] = WALL;
        attrset( A_NORMAL );
      }
      else if( i==BASE_SIZE-1) layout[j][i] = WALL;
      else layout[i][j] = GROUND;
    }
  
  for( int i=0; i<NUM_BOMBS; ++i){
    srand(time(NULL));
    int randx = rand()%BASE_SIZE;
    int randy = rand()%BASE_SIZE;
    layout[randy][randx] = BOMB;
  }

}

void Board::print_board(){
  for( int i=0; i<BASE_SIZE; ++i) // i tiles wide
    for( int j=0; j<BASE_SIZE; ++j) // j tiles tall
      mvprintw( j, i, "%c", layout[j][i] );
}

int Board::is_collision( int y, int x){
  if( y <= 0 || y >= BASE_SIZE - 1) return 1;
  else if ( x <= 0 || x >= BASE_SIZE -1) return 1;
  else return 0;
}

int Board::not_terrain(int y, int x){
  if( y <= 0 && y >= BASE_SIZE - 1 && x <= 0 && x >= BASE_SIZE -1)
    return ( layout[y][x] != GROUND && layout[y][x] != BOMB) ? 1 : 0;
  return 0;
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
  for( int i=0; i<BASE_SIZE; ++i)
    for( int j=0; j<BASE_SIZE; ++j)
      if( layout[j][i] == '_' ) ++total;
  return total;
}
