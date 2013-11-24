#include <cstdlib>
#include "person.h"
#include "board.h"
#include "ncurses.h"
#include <ctime>

void print_time( time_t start, time_t now){
  time( &now);
  mvprintw(60,0,"%f", difftime( now, start) );
}

int still_playing( time_t start, time_t now){
  return difftime( now, start) >= 30.000 ? 0 : 1;
}

int main()
{
  initscr();
  raw();
  cbreak();
  keypad( stdscr, TRUE);
  start_color();

  int in_ch, bombCounter = 1; 
  Person Player;
  Board mBoard;
  time_t start; time( &start);
  time_t now; time( &now);
  double seconds;

  do{
    mBoard.print_board();
    Player.print_person();
    Player.print_health();
    in_ch = getch();
    //~~~MOVEMENT
    if( in_ch == KEY_LEFT)
      Player.move( 0, -1, mBoard);
    else if( in_ch == KEY_RIGHT)
      Player.move( 0, 1, mBoard);
    else if( in_ch == KEY_UP) //axis increases goin down
      Player.move( -1, 0, mBoard);
    else if( in_ch == KEY_DOWN)
      Player.move( 1, 0, mBoard);
    //~~~COMMANDS
    if( in_ch == 'a'){
      Player.activateBomb( mBoard);
      ++bombCounter;
    }
    int totalDestroyed = mBoard.count_destroyed();
    mvprintw( 61, 10, "Ratio: %f", (float)(totalDestroyed/bombCounter));
    print_time( start, now);
    refresh();
    mvprintw(65,0, "%d", Player.is_alive() && still_playing(now,start) && (char)in_ch != 'q');
    mvprintw(66,0, "%d", Player.is_alive() );
    mvprintw(67,0, "%d", still_playing(now,start) );
    mvprintw(68,0, "%d", (char)in_ch != 'q' );
  }while( Player.is_alive() && still_playing(now,start) && (char)in_ch != 'q');


  endwin(); 

  return 0;
}
