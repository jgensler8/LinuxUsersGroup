#include "tile.h"

class Board{
   public:
    Board();
    Board( int);
    void print_board( int);
  private:
    int sizeX;
    int sizeY;
    Tile** layout;
};

