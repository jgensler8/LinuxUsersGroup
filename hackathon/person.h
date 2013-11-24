#include "board.h"
#include "ncurses.h"
#include <cstdlib>
#include <cstring>

#ifndef PERSON_H
#define PERSON_H
class Person{
  public:
    Person();
    Person(char*);
    void move(int, int, Board);
    void print_person();
    void activateBomb( Board);
    void print_health();
    int is_alive();
  private:
    int locX;
    int locY;
    int health;
    char* name;
    int entit;
};
#endif
