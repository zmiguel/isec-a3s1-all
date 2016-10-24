#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){
    int p, i;
    srand(time(NULL));
    
    if(argc!=2){
        printf("[ERRO] nr. args! (=2)\n");
        exit(7);
    }
    p= atoi(argv[1]);
    for(i=0;i<p;i++){
        printf("%d rand: %d\n",i+1, rand()%100);
    }
    
    exit(0);
}
