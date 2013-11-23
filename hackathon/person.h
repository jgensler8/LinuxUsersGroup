#include "board.h"
class Person{
  public:
    Person();
    Person(char*);
    int get_health();
    void move(int, int, Board);
  private:
    int health;
    char* name;
};
