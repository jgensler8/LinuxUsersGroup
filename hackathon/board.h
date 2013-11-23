class Board{
   public:
    Board();
    Board( int x);
    void print_board();
  private:
    int sizeX;
    int sizeY;
    Tile** layout;
};

