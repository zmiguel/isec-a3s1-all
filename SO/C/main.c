#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int p;
    
    if(argc!=3){
        printf("[ERRO] nr. args! (=3)\n");
        exit(7);
    }
    p = atoi(argv[1]);
    printf("Vou enviar um SIGUSR1 ao PID: %d", p)
    
    exit(0);
}
