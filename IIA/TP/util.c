#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct item {
   int ponto1;
   int ponto2;
   float distanc;
};

struct item myItems[250000]; //tentei criar este array com alocação de memoria dinamica como os outros mas nao consegui :(

int init_dados(char *nome){

	FILE *f;
  float dist;
  int p1=0, p2=0;

	f=fopen(nome, "r");
	if(!f){
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}

  do{
  fscanf(f," %d", &p1);
  fscanf(f," %d", &p2);
  fscanf(f," %f", &dist);
  nr_pontos++;

  }while(p1 == 1);
	printf("nr pontos: %d\n", nr_pontos);

  temp1 = nr_pontos - 1;

  //MAXIMO DE SOLUCOES
  do{
    total_sol += temp1;
    temp1--;
  }while(temp1 != 0);
	fclose(f);
	return total_sol;
}

void guardaEstrutura(char *nome, int totalSol){
  FILE *f;
	int i=0;
  float dist;

	f=fopen(nome, "r");
	if(!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}

  while(i != totalSol){
		fscanf(f,"%d %d %f", &myItems[i].ponto1,&myItems[i].ponto2,&myItems[i].distanc);
		i++;
	}
	fclose(f);
}

float dist_med(int pontos_sel, int sum, struct item *sol){
	float res=0, c1=0, med=0;
	int i;
	printf("%d - %d \n", pontos_sel, sum);

	for(i=0;i<sum;i++){
		med += sol[i].distanc;
	}
	res = med / pontos_sel;
	med=0;
	pontos_sel=0;
	return res;
}

int give_rand(int n1, int n2){
	int random;
	random = n1 + (rand() % (n2 - n1 + 1));
	return random;
}

void log(char *filename, int id_itera, int id_pontos, int total_pontos, long long p_list[], float dist_res){
  FILE *f;
  int i=0, j=0;

  f=fopen(filename, "a+");
  if(!f){
		printf("Erro no acesso ao ficheiro de logs\n");
		exit(1);
	}

  //criar sctring com lista de pontos

  if(id_itera == 0){
    fprintf(f, "ITERAÇÃO,NR PONTOS SELECIONADOS,TOTAL PONTOS,LISTA DE PONTOS,RESULTADO\n");
    fprintf(f, "%d,%d,%d",id_itera+1, id_pontos, total_pontos);
    for(j=0;j<id_pontos;j++){
      fprintf(f, "%I64d ", p_list[j]);
    }
    fprintf(f, ",%f\n", dist_res);
  }else if(id_itera > 0){
    fprintf(f, "%d,%d,%d,",id_itera+1, id_pontos, total_pontos);
    for(j=0;j<id_pontos;j++){
      fprintf(f, "%I64d ", p_list[j]);
    }
    fprintf(f, ",%f\n", dist_res);
  }else if(id_itera == -1){
    fprintf(f, "RELATORIO DA EXPERIENCIA:\n");
    fprintf(f, "MELHOR RESULTADO: %f, COM %d NUMEROS\n", dist_res, id_pontos);
    fprintf(f, "POSTOS DA MELHOR SOLUÇÃO: ");
    for(j=0;j<id_pontos;j++){
      fprintf(f, "%I64d,", p_list[j]);
    }
  }
}
