#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int p;
    
    if(argc!=2){
        printf("[ERRO] nr. args! (=2)\n");
        exit(7);
    }
    p = atoi(argv[1]);
    printf("Vou enviar um SIGUSR1 ao PID: %d\n", p);
    kill(p, SIGUSR1);
    
    exit(0);
}
