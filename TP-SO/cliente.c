#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#define TAM 10

#include "util.h"


//gcc -o main main.c -lncurses

int fd_servidor, fd_cliente;

int main(void){

    char str[80], *palavra[TAM];
    int i,a,x;
    int aux;
    int res;
    char mensg[11];
    char c[1000];
    FILE *fp;
initscr();
start_color();
clear();
cbreak();
endwin();
    MENSAGEM msg;
		
    /* VERIFICAR SE EXISTE "CP" NO SERVIDOR(access) */
    if(access("CPservidor", F_OK)!=0){
        printf("[ERRO] O servidor nao esta em execucao!\n");
        exit(1);
    };
    /* CRIAR "CP" DO CLIENTE - MINHA (mkfifo) */
    sprintf(msg.endereco, "CPcliente %d\n", getpid());
    mkfifo(msg.endereco, 0600); //0600 READ && WRITE
    /* ABRIR "CP" DO SERVIDOR (open - O_WRONLY) */
    fd_servidor = open("CPservidor", O_WRONLY);
	system("clear");
    printf("-----BEM-VINDO-----\n");
    printf("'help' para ajuda\n\n");
	
        do{
            printf("> ");
            fgets(str, 80, stdin);
            str[strlen(str)-1]='\0';
            i = 0;
            palavra[i]=strtok(str, " ");
            while(palavra[i]!=NULL){
                i++;
                palavra[i] = strtok(NULL," ");
            }
                if(palavra[0]!=NULL){
                    if(strcmp(palavra[0], "desistir")==0){
                        strcpy(str,"jogar");
                        printf("O jogador 1 não pode desistir!\n");
                    }
                    else if(strcmp(palavra[0],"desligar")==0){
                        strcpy(msg.op1, "Desligar");
                        /*PEDIDO DE SHUTDOWN DO SERVIDOR*/
                        msg.desliga = 1;
                        /* ENVIAR PEDIDO PARA "CP" DO SERVIDOR (write) */
                        i = write(fd_servidor, &msg, sizeof(msg));
                        /* ABRIR "CP" DO CLIENTE - MINHA (open - O_RDONLY) */
                        fd_cliente = open(msg.endereco, O_RDONLY);
                        /* RECEBER RESPOSTA NA "CP" DO CLIENTE - MINHA (read) */
                        i = read(fd_cliente, &msg, sizeof(msg));
                        /* FECHAR "CP" DO CLIENTE - MINHA (close) */
                        close(fd_cliente);

                        /*DESLIGAR O CLIENTE*/
                        strcpy(str, "desistir");

                        printf("SERVIDOR DESLIGADO\n");
                    }
                    else if(strcmp(palavra[0],"test")==0){
                        strcpy(msg.op1, palavra[0]);
                            //strcpy(msg.op2, palavra[1]);
                        /* ENVIAR PEDIDO PARA "CP" DO SERVIDOR (write) */
                        write(fd_servidor, &msg, sizeof(msg));
                        /* ABRIR "CP" DO CLIENTE - MINHA (open - O_RDONLY) */
                        fd_cliente = open(msg.endereco, O_RDONLY);
                        /* RECEBER RESPOSTA NA "CP" DO CLIENTE - MINHA (read) */
                        read(fd_cliente, &msg, sizeof(msg));//ver recebimento.
                        /* FECHAR "CP" DO CLIENTE - MINHA (close) */
                        close(fd_cliente);
                        //FAZER RECEBIMENTO - PERGUNTAR AO ZÉ A IMPLEMENTACAO
			

		fp = fopen("campo.txt", "r");
			if(fp == NULL){
				printf("ERRO");
				exit(1);
				}
			fscanf(fp,"%[^\n]", c);
			printf("%s", c);
			fclose(fp);
                       // printf("%s\n", msg.resposta);//ver recebimento
		                    }

                    else if(strcmp(palavra[0],"help")==0){
                        strcpy(msg.op1, palavra[0]);
                        if(palavra[1]!=NULL){
                            strcpy(msg.op2, palavra[1]);
                        }
                        /* ENVIAR PEDIDO PARA "CP" DO SERVIDOR (write) */
                        write(fd_servidor, &msg, sizeof(msg));
                        /* ABRIR "CP" DO CLIENTE - MINHA (open - O_RDONLY) */
                        fd_cliente = open(msg.endereco, O_RDONLY);
                        /* RECEBER RESPOSTA NA "CP" DO CLIENTE - MINHA (read) */
                        read(fd_cliente, &msg, sizeof(msg));//ver recebimento.
                        /* FECHAR "CP" DO CLIENTE - MINHA (close) */
                        close(fd_cliente);
                        //FAZER RECEBIMENTO - PERGUNTAR AO ZÉ A IMPLEMENTACAO
                        printf("%s\n", msg.resposta);//ver recebimento
                    }
                    else
                        printf("Comando invalido, tenta novamente!\n");
                }
        }while(strcmp(str,"desistir")!=0);
    //}while(play1.permissao != 1);
    /* FECHAR "CP" DO SERVIDOR (close) */
    close(fd_servidor);
    /* REMOVER "cp" DO CLIENTE - EU (UNLINK) */
    unlink(msg.endereco);

    exit(0);
}
