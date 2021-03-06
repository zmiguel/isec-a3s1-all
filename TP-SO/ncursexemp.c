#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

typedef struct{
	int continua;
	int pausa;
	int l,c;
	pthread_t tid;
	void * retval;
}TDados;


void *relogio(void *arg){
	time_t hora;
	TDados *dados =(TDados*) arg;
	int al,ac;

	while(dados->continua == 1){
		hora=time(NULL);
		getyx(stdscr, al, ac);
		mvprintw(dados->l,dados->c,"%s", ctime(&hora));
		move(al,ac);
		refresh();
		sleep(dados->pausa);
}
	return NULL;

}

int main(){
	int res;
	char msg[11];
	TDados trelog;

initscr();
start_color();
clear();
cbreak();

trelog.continua = 1;
trelog.pausa = 1;
trelog.l = 30;
trelog.c = 35;
res = pthread_create(&trelog.tid, NULL,relogio,(void*)&trelog);
if(res != 0){

endwin();
perror("\nErro na criacao da thread");
exit(1);


}


while(1){

printw("\nInicio (sair) para encerrar\n");
printw("> ");
scanw(" %10[^\n]", msg);
printw("disseste: [%s]\n", msg);
refresh();
if(strcmp(msg, "sair")==0)
break;
}


trelog.continua = 0;
pthread_join(trelog.tid, &trelog.retval);
printw("\ncarrega numa tecla\n");
wgetch(stdscr);
endwin();
return 0;

}
