#include <cstdlib>
#include <cstring>
#define BASE_HEALTH 1000
#define NAME_LEN 100

class Person{
  public:
    Person();
    Person(char*);
    int get_health();
  private:
    int health;
    char* name;  
};

Person::Person(){
  health = BASE_HEALTH;
  name = new char[NAME_LEN+1];
  strcpy( name, "USER");
}

Person::Person(char* input_name){
  health = 1000;
  name = new char[101];
  strcpy(name, input_name);
}

int Person::get_health(){
  return health;
}
