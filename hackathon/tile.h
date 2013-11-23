class Tile{
  public:
    Tile();
    Tile( int);
    int get_width();
    int get_height();
    int print_tile( int, int);
  private:
    int sizeX;
    int sizeY;
    char** layout;
    void layout_init();
};

