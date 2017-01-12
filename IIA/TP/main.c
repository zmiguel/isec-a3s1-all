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

  //abrir ficheiro aqui
  //perguntar ao utilizador o nome do ficheiro a usar
  printf("Introduza o nome do ficheiro: ");
  fgets(nome_fich, sizeof(nome_fich), stdin);
  nome_fich[strlen(nome_fich)-1]='\0';

  totalSol = init_dados(nome_fich);

  //array inicial
  for(j=0;j<max;j++){
    str[j] = j+1;
  }
  //escolher aleatoriamente quantos sao os numeros aleatorios
  srand((unsigned)time(&t));
  pontos = 2+rand()%max;

  //descobrir o nr de somas entre os pontos escolhidos
  somar = pontos-1;
  do{
    soma += somar;
    somar--;
  }while(somar != 0);

  printf("\n"); // cenas
  //cria array sem numeros aleatorios repetidos
  for(k=0;0==0;k++){
    p = 1+rand()%(max+1);//meter max aqui
    novoArr[k] = p;

    for(a = 0; a<max; a++){
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
  printf("Pontos escolhidos aleatoriamente:\n");
  //mostra o novo array nao organizado
  for(i=0; i<pontos; i++){
    printf("%d ", auxi[i]);
  }

  printf("\n");
  printf("Nr pontos aleatorios: %d\n", contador);
  //novo array organizado
  for(i=0; i<pontos; i++){
    for(j= 0; j<pontos;j++){
      if(auxi[i] < auxi[j]){
        w = auxi[i];
        auxi[i] = auxi[j];
        auxi[j] = w;
      }
    }
  }
  //mostrar novo array auxi
  for(i=0; i<pontos; i++){
    printf("%d ", auxi[i]);
  }
  printf("\n");

  guardaEstrutura(nome_fich, totalSol);

  for(i=0;i<pontos;i++){
      for(j=0;j<pontos;j++){
          if(auxi[i] < auxi[j]){
            //printf("(%d , %d)\n", auxi[i], auxi[j]);
            int temp1=0, temp2=0;
            temp2 = (auxi[j]-auxi[i]);
            for(k=auxi[i]-1;k>=1;k--){
              temp2 += (max-(k));
            }
            temp1 = temp2 - 1;
            mySol[i].ponto1 = myItems[temp1].ponto1;
    				mySol[i].ponto2 = myItems[temp1].ponto2;
    				mySol[i].distanc = myItems[temp1].distanc;
      			printf("(%d,%d,%f)\n", mySol[i].ponto1,mySol[i].ponto2,mySol[i].distanc);
        }
    }
  }
}
