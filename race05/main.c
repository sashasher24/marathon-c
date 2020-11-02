//#include <windows.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    initscr();
//    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    char *phrases[] = {"Wake up Neo", "The Matrix has you ....", "Follow the white rabbit !"}; 
    attron(COLOR_PAIR(1));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; phrases[i][j]; j++) {
            move(10, 10+j);
            addch(phrases[i][j]);
            getch();
            usleep(1000 * 150);
        }
        clear();
        usleep(1000 * 200);
    }
    int maxx, maxy;
    getmaxyx(stdscr, maxx, maxy);
    while (1) {
        int i = 0;
        while (i < maxy){	        
            for(int j = 0; j < maxx; j++){
		if (j == 6 && i > 3 && i < 14) {
		    mvaddch(i, j, ' ');
		    getch();
		}
                mvaddch(j, i, 32 + rand() % 94);
                getch();
            }
            usleep(1000 * 30);
            i++;
        }
    }
    
    getch();
    endwin();
    return 0;
}
