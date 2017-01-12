#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

#define MAX_ITEMS 1000

struct item {
    int ponto1;
    int ponto2;
    float distanc;
};

int max = 0;

struct item myItems[MAX_ITEMS];

int* init_dados(char *nome){

	FILE *f;
	int i=0;
  float dist;
  int conta=0;
  int total = 0;
  int cool, pool;

	f=fopen(nome, "r");
	if(!f){
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}

  do{
  fscanf(f," %d", &cool);
  fscanf(f," %d", &pool);
  fscanf(f," %f", &dist);
  conta++;

  }while(cool == 1);
	//printf("conta %d\n", conta);
	max = conta;
	printf("nr pontos: %d\n", max);
	conta--;

  //MAXIMO DE SOLU��ES
  do{
    total += conta;
    conta--;
  }while(conta != 0);
  //printf("total: %d\n", total);
	fclose(f);
	return total;
}

void guardaEstrutura(char *nome,int totalSol){
  FILE *f;
	int i=0;
  float dist;

  struct item mySol[MAX_ITEMS];

  //printf("TOTAL: %d\n", totalSol);
	f=fopen(nome, "r");
	if(!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}

  while(i != totalSol){
		fscanf(f,"%d %d %f", &myItems[i].ponto1,&myItems[i].ponto2,&myItems[i].distanc);
		//printf("%d:\t %d %d %f\n", i, myItems[i].ponto1,myItems[i].ponto2,myItems[i].distanc);
		i++;
	}
	fclose(f);
}
