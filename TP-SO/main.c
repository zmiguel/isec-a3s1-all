#include <ncurses.h>

int main(){

	initscr();
	raw();
	printf("Hello world");
	endwin();


	return 0;


}
