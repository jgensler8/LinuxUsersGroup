#include "board.h"
#include <cstdlib>
#include <cstring>

#ifndef PERSON_H
#define PERSON_H
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
#endif
