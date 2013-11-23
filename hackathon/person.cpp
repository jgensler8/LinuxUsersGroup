#include <cstdlib>
#include <cstring>
#include "board.h"
#define BASE_HEALTH 1000
#define NAME_LEN 100
#define ENTITY_SYMBOL '&'

class Person{
  public:
    Person();
    Person(char*);
    int get_health();
    void move(int, int, Board);
  private:
    int locX;
    int locY;
    int health;
    char* name;
    int entit;  
};

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
