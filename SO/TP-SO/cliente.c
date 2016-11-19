#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define TAM 10

#include "util.h"

void display_campo(struct campo *campo1){
    int i=0, lin, col;
    for(lin=0;lin<21;lin++){
        for(col=0;col<51;col++){
            printf("%s ",campo1[i].cont);
            i++;
        }
        printf("\n");
    }
    printf("\n");
}

int fd_servidor, fd_cliente;
struct campo *campocliente = campo1;

int main(void){
    char str[80], *palavra[TAM];
    int i;

    MENSAGEM msg;

    /* VERIFICAR SE EXISTE "CP" NO SERVIDOR(access) */
    if(access("CPservidor", F_OK)!=0){
        printf("[ERRO] O servidor nao esta em execucao!\n");
        exit(1);
    };
    /* CRIAR "CP" DO CLIENTE - MINHA (mkfifo) */
    sprintf(msg.endereco, "CPcliente %d", getpid());
    mkfifo(msg.endereco, 0600); //0600 READ && WRITE
    /* ABRIR "CP" DO SERVIDOR (open - O_WRONLY) */
    fd_servidor = open("CPservidor", O_WRONLY);

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
                        printf("%s\n", msg.resposta);//ver recebimento
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
                    else if(strcmp(palavra[0],"campo")==0){
                        display_campo(campocliente);
                    }
                    else if(strcmp(palavra[0],"set")==0){
                        strcpy(msg.op1, palavra[0]);
                        strcpy(msg.op2, palavra[1]);
                        strcpy(msg.op3, palavra[2]);
                        strcpy(msg.op4, palavra[3]);
                        
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
                        //campocliente = msg.campojogo;  EXISTE UM ERRO AQUI, HEEEELLLPPPP
                    }
                    else
                        printf("Comando invalido, tenta novamente!\n");
                }
        }while(strcmp(str,"desistir")!=0);
    /* FECHAR "CP" DO SERVIDOR (close) */
    close(fd_servidor);
    /* REMOVER "cp" DO CLIENTE - EU (UNLINK) */
    unlink(msg.endereco);

    exit(0);
}