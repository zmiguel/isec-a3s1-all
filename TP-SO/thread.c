#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include <stdlib.h>
#include <unistd.h>

typedef struct{
	int continua;
	int pausa;
	pthread_t tid;
	void * retval;
} TDados;

void * relogio(void *arg){
	time_t hora;
	TDados *dados = (TDados*) arg;

	while (dados->continua == 1){
		hora = time(NULL);
		printf("%s",ctime(&hora));
		fflush(stdout);
		sleep(dados->pausa);
}
printf("Relógio a encerrar");
return NULL;

}

int main(){
	int res;
	char msg[11];
	TDados trelog;
	printf("\nInicio (sair) para encerrar\n");

	trelog.continua = 1;
	trelog.pausa = 1;
	res = pthread_create(& trelog.tid,NULL,relogio,(void *) & trelog);

if(res != 0){
perror("\nErro na criação da thread");
exit(1);
}

while(1){
	scanf(" %10[^\n]", msg);
	printf("disseste: [%s]\n", msg);
	if(strcmp(msg,"sair")==0)
	break;

}

trelog.continua = 0;
pthread_join(trelog.tid, & trelog.retval);
printf("\n\n");
return 0;
}

