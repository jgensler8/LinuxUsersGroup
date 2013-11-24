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

  init_pair( 1, COLOR_RED, COLOR_WHITE);
  init_pair( 2, COLOR_YELLOW, COLOR_BLUE);
  init_pair( 3, COLOR_BLUE, COLOR_GREEN);

  int begin =0;
  int future_size = 20;
  mvprintw(0,62,"CONTROLS:");
  mvprintw(1,62,"q: quit at any time");
  mvprintw(2,62,"a: detonate a bomb at any time");
  mvprintw(3,62,"MISSION:");
  mvprintw(4,62,"get the highest land to bomb ratio!");
  mvprintw(5,62,"play the game and compete with friends.");
  mvprintw(6,62,"bombs 'B' should help you accomplishes this.");
  do{
    attron( COLOR_PAIR( 1 ) );
    mvprintw(4,4,"$$$$$$$$$$$$  (s)mall  $$$$$$$$$$$$$$$");
    attroff( COLOR_PAIR( 1 ) );
    attron( COLOR_PAIR( 2 ) );
    mvprintw(8,4,"$$$$$$$$$$$$  (m)edium $$$$$$$$$$$$$$$");
    attroff( COLOR_PAIR( 2 ) );
    attron( COLOR_PAIR( 3 ) );
    mvprintw(12,4,"$$$$$$$$$$$  (l)arge  $$$$$$$$$$$$$$$");
    attroff( COLOR_PAIR( 3 ) );
    int in_ch = getch();
    switch( (char)in_ch){
      case 's': future_size = 42; begin = 1; break;
      case 'm': future_size = 50; begin = 1; break;
      case 'l': future_size = 60; begin = 1; break;
    }
  }while( !begin);

  int in_ch, bombCounter = 1, totalDestroyed = 0; 
  Person Player;
  Board mBoard( future_size);
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
    totalDestroyed = mBoard.count_destroyed();
    mvprintw( 61, 10, "Ratio: %f", (float)(totalDestroyed/bombCounter));
    print_time( start, now);
    refresh();
    mvprintw(65,1, "%d", Player.is_alive() && still_playing(now,start) && (char)in_ch != 'q');
    mvprintw(65,3, "%d", Player.is_alive() );
    mvprintw(65,5, "%d", still_playing(now,start) );
    mvprintw(65,7, "%d", (char)in_ch != 'q' );
  }while( Player.is_alive() && still_playing(now,start) && (char)in_ch != 'q');
  
  mvprintw( 61, 10, "Ratio: %f", (float)(totalDestroyed/bombCounter));
  mBoard.print_board();
  Player.print_person();
  Player.print_health();
  for( int i = 0; i<40; ++i){
    mvprintw( 20+i*i, i, "***********************ALL DONE*****************************************");
  }  
  in_ch = getch();


  endwin(); 

  return 0;
}
