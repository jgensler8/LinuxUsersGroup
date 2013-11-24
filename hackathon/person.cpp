#include "person.h"

#define BASE_HEALTH 100
#define NAME_LEN 100
#define ENTITY_SYMBOL '&'

Person::Person(){
  health = BASE_HEALTH;
  name = new char[NAME_LEN+1];
  strcpy( name, "USER");
  entit = ENTITY_SYMBOL;
  locX = 2;
  locY = 2;
}

Person::Person(char* input_name){
  health = 1000;
  name = new char[101];
  strcpy(name, input_name);
  entit = ENTITY_SYMBOL;
  locX = 1;
  locY = 1;
}

void Person::move( int y, int x, Board board){
  if( !board.is_collision( locY+y, locX+x) && board.not_terrain(locY+y, locX+x)){
    locX += x;
    locY += y;
  }
}

void Person::print_person(){
  mvprintw(locY, locX, "%c", entit);
}

void Person::print_health(){
  char healthBar[BASE_HEALTH +1];
  healthBar[BASE_HEALTH] = '\0';
  for(int i=0; i<BASE_HEALTH; ++i){
    if( health >= i) healthBar[i] = '$';
    else healthBar[i] = '_';
  } 
  mvprintw(63, 0, "HEALTH: %s", healthBar);
}

void Person::activateBomb(Board board){
  int bombSize = rand()%10;
  health -= bombSize/2;
  for( int i=-bombSize; i<bombSize; ++i){
    if( !board.is_collision( locY+i, locX) ) board.set_layout( locY+i, locX, '_');
    if( !board.is_collision( locY, locX+i) ) board.set_layout( locY, locX+i, '_');
    if( board.is_bomb( locY+i, locX) ) board.detonate_bomb( locY+i, locX, '_');
    if( board.is_bomb( locY, locX+i) ) board.detonate_bomb( locY, locX+i, '_');
  } 
  for( int i=-bombSize/2; i<bombSize/2; ++i){
    if( !board.is_collision( locY+i, locX+i) ) board.set_layout( locY+i, locX+i, '_');
    if( !board.is_collision( locY-i, locX-i) ) board.set_layout( locY-i, locX-i, '_');
    if( board.is_bomb( locY+i, locX+i) ) board.detonate_bomb( locY+i, locX, '_');
    if( board.is_bomb( locY-i, locX-i) ) board.detonate_bomb( locY, locX+i, '_');
  } 
  for( int i=-bombSize/2; i<bombSize/2; ++i){
    if( !board.is_collision( locY-i, locX-i) ) board.set_layout( locY-i, locX-i, '_');
    if( !board.is_collision( locY+i, locX+i) ) board.set_layout( locY+i, locX+i, '_');
    if( board.is_bomb( locY-i, locX-i) ) board.detonate_bomb( locY+i, locX, '_');
    if( board.is_bomb( locY+i, locX+i) ) board.detonate_bomb( locY, locX+i, '_');
  } 
}

int Person::is_alive(){
 return health >= 0 ? 1 : 0;
}
