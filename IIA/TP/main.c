#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"
#include "util.c"

#define MAX_ITEMS 125000

//struct item item[MAX_ITEMS];

int main(int argc, char *argv[]){
    //variaveis
  int itera=0, k=0, i=0, j=0, a=0, p=0, w=0, conta=0, contador=0, pontos=0, nova=0, soma=0, somar=0, totalSol=0, temp1=0, temp2=0, temp3=0, ii=0, melhor_nr=0;
  char nome_fich[100];
  float melhor=0, temp4=0;
  bool runs = false, fiile = false;
  unsigned long long *str = malloc(MAX_ITEMS * sizeof(long long));
  unsigned long long *auxi = malloc(MAX_ITEMS * sizeof(long long));
  unsigned long long *novoArr = malloc(MAX_ITEMS * sizeof(long long));
  struct item *item = malloc(MAX_ITEMS * sizeof(item));
    //setup random
  time_t t;
  srand((unsigned)time(&t));

    //verificar argumentos de linha de commandos
  if(argc==2){
    printf("Args = 2\n");
    if(isdigit(*argv[1])){
      printf("Arg is Digit\n");
      itera = strtol(argv[1], NULL, 10);
      runs = true;
    }else{
      printf("Arg ISN'T digit\n");
      memcpy(nome_fich, argv[1], sizeof(nome_fich));
      //fgets(nome_fich, sizeof(nome_fich), *argv[1]);
      fiile = true;
    }
  }else if(argc==3){
    printf("Args = 3\n");
    if(isdigit(*argv[1])){
      printf("Arg 1 IS digit\n");
      itera = strtol(argv[1], NULL, 10);
      memcpy(nome_fich, argv[2], sizeof(nome_fich));
      //fgets(nome_fich, sizeof(nome_fich), *argv[2]);
      runs = true;
      fiile = true;
    }else{
      printf("Arg 1 ISN'T digit\n");
      itera = strtol(argv[2], NULL, 10);
      memcpy(nome_fich, argv[1], sizeof(nome_fich));
      //fgets(nome_fich, sizeof(nome_fich), *argv[1]);
      runs = true;
      fiile = true;
    }
  }else if(argc > 3){
    printf("Demasiados argumentos ao iniciar o programa %s\n", argv[0]);
    return 0;
  }

  if(runs==false){
    itera = 50;
    //numero standard de iteraçoes a correr!
  }
  if(fiile==false){
    //perguntar ao utilizador o nome do ficheiro a usar
    printf("Introduza o nome do ficheiro: ");
    fgets(nome_fich, sizeof(nome_fich), stdin);
    nome_fich[strlen(nome_fich)-1]='\0';
  }

  //ciclo para analisar dados
  for(ii=0;ii<itera;ii++){

      totalSol = init_dados(nome_fich);

      //array inicial
      for(j=0;j<max;j++){
        str[j] = j+1;
      }
      //escolher aleatoriamente quantos sao os numeros aleatorios
      pontos = give_rand(2,max);

      //descobrir o nr de somas entre os pontos escolhidos
      somar = pontos-1;
      do{
        soma += somar;
        somar--;
      }while(somar != 0);

      printf("\n"); // cenas
      //cria array sem numeros aleatorios repetidos
      for(k=0;0==0;k++){
        p =  give_rand(1,max);
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
        printf("%I64d ", auxi[i]);
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
        printf("%I64d ", auxi[i]);
      }
      printf("\n");

      guardaEstrutura(nome_fich, totalSol);

      for(i=0;i<pontos;i++){
        for(j=0;j<pontos;j++){
            if(auxi[i] < auxi[j]){
              //printf("(%d , %d)--", auxi[i], auxi[j]);
              temp2 = (auxi[j]-auxi[i]);

              for(k=auxi[i]-1;k>=1;k--){
                temp2 += (max-(k));
              }

              temp1 = temp2 - 1;
              mySol[temp3].ponto1 = myItems[temp1].ponto1;
      				mySol[temp3].ponto2 = myItems[temp1].ponto2;
      				mySol[temp3].distanc = myItems[temp1].distanc;
        			//printf("(%d,%d,%f)\n", mySol[temp3].ponto1, mySol[temp3].ponto2, mySol[temp3].distanc);
              temp3++;
          }
        }
      }
      temp4 = dist_med(pontos, soma, mySol);
      if(temp4 > melhor){
        melhor = temp4;
        melhor_nr = pontos;
      }
      printf("Distancia media para %d pontos, iteracao %d: %f\n", pontos, ii+1, temp4);
      //reset tudo a zero
        soma=0;
        somar=0;
        contador=0;
        temp1=0;
        temp2=0;
        temp3=0;
        temp4=0;
        totalSol=0;
  }

  printf("Melhor com %d numeros: %f pontos\n", melhor_nr, melhor);

}
