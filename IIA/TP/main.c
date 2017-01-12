#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "util.h"
#include "util.c"

#define MAX_ITEMS 1000

int main(){

int k,i,j,a=1,p,w=0;
int str[2000];
int conta =0;
int contador =0;
int pontos;
int nova;
int auxi[2000];
time_t t;
int novoArr[2000];
int soma =0;
int somar=0;
char nome_fich[100];
int totalSol;
struct item item[MAX_ITEMS];
struct item mySol[MAX_ITEMS];


    for(j=0;j<20;j++){

        str[j] = j+1;
    }
srand((unsigned)time(&t));

pontos = 2+rand()%20;


somar = pontos-1;
do{
    soma += somar;
    somar--;

}while(somar != 0);


printf("TESTE: \n");

    for(k=0;0==0;k++){

        p = 1+rand()%21;
        novoArr[k] = p;

        for(a = 0; a<20; a++){
            if(novoArr[k] == str[a]){

                auxi[contador] = novoArr[k];
                str[a] = -1;
                contador++;
                            }
            }
        if(contador == pontos){
            break;
            }
        }
printf("Novo Array:\n");
for(i=0; i<pontos; i++){

    printf("%d\n", auxi[i]);
}

printf("\n");
printf("Contagem: %d\n", contador);


    for(i=0; i<pontos; i++){

        for(j= 0; j<pontos;j++){
        if(auxi[i] < auxi[j]){


        w = auxi[i];
        auxi[i] = auxi[j];
        auxi[j] = w;
        }
        }

    }
    for(i=0; i<pontos; i++){

        printf("%d\n", auxi[i]);
    }
    printf("NUMERO DE SOMAS: %d\n\n", soma);

        printf("Introduza o nome do ficheiro: ");
        fgets(nome_fich, sizeof(nome_fich), stdin);
        nome_fich[strlen(nome_fich)-1]='\0';

        totalSol = init_dados(nome_fich);
        printf("total main: %d\n", totalSol);

        guardaEstrutura(nome_fich, totalSol);

    for(i=0;i<pontos;i++){
        for(j=0;j<pontos;j++){
            if(auxi[i] < auxi[j]){
                printf("(%d , %d)\n", auxi[i], auxi[j]);
                int temp1=0, temp2=0;
                temp2 = (auxi[j]-auxi[i]);
                //printf("%d", temp2);
                for(k=auxi[i]-1;k>=1;k--){
                  temp2 += (20-(k));
                  //printf("+(20-%d)", k);
                }
                //printf("-1\n");
                temp1 = temp2 - 1;
                mySol[i].ponto1 = myItems[temp1].ponto1;
        				mySol[i].ponto2 = myItems[temp1].ponto2;
        				mySol[i].distanc = myItems[temp1].distanc;
          			printf(" %d %d %f\n", mySol[i].ponto1,mySol[i].ponto2,mySol[i].distanc);
            }
        }
    }

printf("\n");
printf("PONTOS: %d", pontos);

	/*/ = malloc(sizeof(int)*(*n)*(*n));
	if(!p)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	q=p;
	// Preenchimento da matriz
	for(i=0; i<*n; i++)
        for(j=0; j<*n; j++)
            fscanf(f, " %d", q++);/*/
}
