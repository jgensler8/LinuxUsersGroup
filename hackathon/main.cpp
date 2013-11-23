#include <cstdlib>
#include "ncurses.h"
#include "person.h"
#include "board.h"
#include <ctime>

#define FAR_DOWN 3

void print_time( time_t start, time_t now){
  time( &now);
  mvprintw(1,0,"%f", difftime( now, start) );
}

void print_health( Person Player){
  mvprintw( 1, 10, "%d", Player.get_health() ); 
}

int main()
{
  initscr();
  raw();
  keypad( stdscr, TRUE);
  
  int in_ch; 
  Person Player;
  Board mBoard;
  time_t start; time( &start);
  time_t now; time( &now);
  double seconds;

  do{
    in_ch = getch();
    if( in_ch == KEY_LEFT){
      Player.move( 0, -1, mBoard);
    }
    else if( in_ch == KEY_RIGHT){
      Player.move( 0, 1, mBoard);
    }
    else if( in_ch == KEY_UP){ //axis increases goin down
      Player.move( -1, 0, mBoard);
    }
    else if( in_ch == KEY_DOWN){
      Player.move( 1, 0, mBoard);
    }
    print_time( start, now);
    print_health( Player);
    mBoard.print_board( FAR_DOWN);
    Player.print_person( FAR_DOWN);
    refresh();
  }while( (char)in_ch != 'q');

  endwin(); 

  return 0;
}
