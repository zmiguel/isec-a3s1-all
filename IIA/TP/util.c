#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"

#define MAX_ITEMS 125000

struct item {
    int ponto1;
    int ponto2;
    float distanc;
};

int max = 0;

struct item myItems[MAX_ITEMS];
struct item mySol[MAX_ITEMS];

int init_dados(char *nome){

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
	conta=0;
	return total;
}

void guardaEstrutura(char *nome,int totalSol){
  FILE *f;
	int i=0;
  float dist;

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

float dist_med(int nr_pontos, int sum, struct item *sol){
	float res=0, c1=0, med=0;
	int i;
	printf("%d - %d \n", nr_pontos, sum);

	for(i=0;i<sum;i++){
		med += sol[i].distanc;
	}
	res = med / nr_pontos;
	med=0;
	nr_pontos=0;
	return res;
}

int give_rand(int n1, int n2){
	int random;
	random = n1 + (rand() % (n2 - n1 + 1));
	return random;
}
