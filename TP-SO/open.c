#include <stdio.h>
#include <stdlib.h>

int main(){

	char ch,  campo.txt[25];
	FILE *fp;

	printf("Introduz o nome do fcheiro");
	gets(campo.txt);

	fp = fopen(campo.txt,"r");

	if( fp == NULL){

	perror("Error while opening the file.\n");
	exit(EXIT_FAILURE);
}
	printf("The contents of %s file are: \n", campo.txt);

	while((ch = fgetc(fp)) != EOF )
		printf("%c", ch);

	fclose(fp);
return 0;

}
