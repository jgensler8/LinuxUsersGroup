#include "person.h"

#define BASE_HEALTH 1000
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
  locX = 2;
  locY = 2;
}

int Person::get_health(){
  return health;
}

void Person::move( int x, int y, Board board){
  if( !board.is_collision( locX+x, locY+y) ){
    locX += x;
    locY += y;
  }
  

}
