#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int n, i;

    signal(SIGINT, SIG_IGN);
    
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
