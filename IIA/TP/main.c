#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "vars.h"
#include "util.h"
#include "util.c"

int main(int argc, char *argv[]){
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

  //ler nr linhas ficheiro
  nr_linhas = init_dados(nome_fich);
  //alocamento dinamico de arrays
  unsigned long long *str = malloc(nr_linhas * sizeof(long long));
  unsigned long long *auxi = malloc(nr_linhas * sizeof(long long));
  unsigned long long *novoArr = malloc(nr_linhas * sizeof(long long));
  unsigned long long *melhorArr = malloc(nr_linhas * sizeof(long long));
  struct item *item = malloc(nr_linhas * sizeof(item));

  //ciclo para analisar dados
  for(ii=0;ii<itera;ii++){

      //array inicial
      for(j=0;j<nr_pontos;j++){
        str[j] = j+1;
      }
      //escolher aleatoriamente quantos numeros vao ser selecionados
      pontos = give_rand(2,nr_pontos);

      //descobrir o nr combinaçoes possiveis dentro dos numeros escolhidos
      temp1 = pontos - 1;
      for(nr_comb=0;temp1!=0;temp1--){
        nr_comb += temp1;
      }

      printf("\n"); // cenas
      //cria array sem numeros aleatorios repetidos
      for(k=0;0==0;k++){
        p =  give_rand(1,nr_pontos);
        novoArr[k] = p;

        for(a = 0; a<nr_pontos; a++){
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
      /*printf("Pontos escolhidos aleatoriamente:\n");
      //mostra o novo array nao organizado
      for(i=0; i<pontos; i++){
        printf("%I64d ", auxi[i]);
      }

      printf("\n");*/
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
      /*for(i=0; i<pontos; i++){
        printf("%I64d ", auxi[i]);
      }*/
      printf("sum: %d\n", nr_comb * nr_pontos);
      struct item *mySol = malloc((nr_comb * nr_pontos) * sizeof(item));

      guardaEstrutura(nome_fich, nr_linhas);

      for(i=0;i<pontos;i++){
        for(j=0;j<pontos;j++){
            if(auxi[i] < auxi[j]){
              //printf("(%I64d,%I64d)", auxi[i], auxi[j]);
              temp2 = (auxi[j]-auxi[i]);

              for(k=auxi[i]-1;k>=1;k--){
                temp2 += (nr_pontos-(k));
              }

              temp1 = temp2 - 1;
              mySol[temp3].ponto1 = myItems[temp1].ponto1;
      				mySol[temp3].ponto2 = myItems[temp1].ponto2;
      				mySol[temp3].distanc = myItems[temp1].distanc;
              temp3++;
          }
        }
        //printf("\n");
      }
      /*for(i=0;i<nr_comb;i++){
        printf("%d:\t %d %d %f\n", i+1, mySol[i].ponto1,mySol[i].ponto2,mySol[i].distanc);
      }*/
      temp4 = dist_med(pontos, nr_comb, mySol);
      if(temp4 > melhor){
        melhor = temp4;
        melhor_nr = pontos;
        melhor_itera = ii+1;
        for(i=0; i<pontos; i++){
            melhorArr[i] = auxi[i];
        }
      }

      printf("Distancia media para %d pontos, iteracao %d: %f\n", pontos, ii+1, temp4);
      log("LOGFILE.txt", ii, pontos, nr_pontos, auxi, temp4);
      //reset tudo a zero
      free(mySol);
      pontos=0;
      contador=0;
      temp1=0;
      temp2=0;
      temp3=0;
      temp4=0;
  }

  printf("\n\n");
  printf("RELATORIO DA EXPERIENCIA:\n\n");
  printf("MELHOR RESULTADO TEM %d NUMEROS \nVALOR DE DISTANCIA MEDIA %f \nOCORREU NA ITERACAO NUMERO: %d", melhor_nr, melhor, melhor_itera);
  printf("\nPONTOS DA MELHOR SOLUCAO: ");
  for(i=0; i<melhor_nr; i++){
    printf("%I64d ", melhorArr[i]);
  }


}
