#define FUNCOES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>



struct info init_data(char *s, int mat[][2]);

//pchrom init_pop(struct info d);

//void print_pop(pchrom pop, struct info d);

//chrom get_best(pchrom pop, struct info d, chrom best);

//void write_best(chrom x, struct info d);

int init_dados(char *nome);

void guardaEstrutura(struct item *myItems, char *nome, int totalSol);

int random_l_h(int min, int max);
