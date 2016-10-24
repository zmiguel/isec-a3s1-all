#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void diz(int s){
    if(s==SIGINT){
        printf("\nOLA\n");
    }else if(s==SIGUSR1){
        printf("Adeus!\n");
        exit(3);
    }

}

int main(int argc, char *argv[]){
    int n, i;

    signal(SIGINT, diz);
    signal(SIGUSR1, diz);

    if(argc!=3){
        printf("[ERRO] nr. args! (=3)\n");
        exit(7);
    }
    n = atoi(argv[1]);
    for(i=0;i<n;i++){
        printf("%c", argv[2][0]);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    
    exit(0);
}
