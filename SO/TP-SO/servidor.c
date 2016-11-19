#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define MAX 5

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
struct campo *camposervidor = campo1;

int main(void){
    char movimento[20];
    int m, n, permissao = 0, x, y;
    int i, j, k;

    MENSAGEM msg;

    srand(time(NULL));

    /* VERIFICAR SE EXISTE "CP" DO SERVIDOR (access) -- APENAS UM!!!*/
    if(access("CPservidor", F_OK)==0){
        printf("[SERVIDOR] Ja existe um servidor!\n");
        exit(1);
    }
    /* CRIAR "CP" DO SERVIDOR - MINHA (mkfifo) */
    mkfifo("CPservidor", 0600);
    /* ABRIR "CP" DO SERVIDOR - MINHA (open - O_RDONLY) */
    fd_servidor = open("CPservidor", O_RDWR);

    printf("[SERVIDOR] Servidor Iniciado!\n");
        do{
            /* RECEBER PEDIDO NA "CP" DO SERVIDOR - MINHA (n = read();) */
            n = read(fd_servidor, &msg, sizeof(msg));

            if(n == 0){
                printf("[SERVIDOR] Fiquei sem jogadores!\n");
                sleep(1);
                continue;
            }
            //-------------------COMANDO-TESTE----------------
            else if(strcmp(msg.op1,"test")==0){
                strcpy(msg.resposta,"FUNCIONA CARALHO\n");
                printf("[SERVIDOR] Teste funcionou [%s]\n", msg.endereco);
                
            }
            //-------------------COMANDO-HELP----------------
            else if(strcmp(msg.op1,"help")==0){
                if(msg.op2 == ""){
                    printf("%s\n",msg.op2);
                }else{
                    strcpy(msg.resposta,"AJUDA:\n\tdesligar:\tdesliga o cliente e servidor corretamente.\n\ttest:\t\ttesta o servidor.\n\thelp:\t\teste comando\n");
                    printf("[SERVIDOR] A mostrar ajuda [%s]\n", msg.endereco);
                }
            }
            //-------------------COMANDO-set----------------
            else if(strcmp(msg.op1,"set")==0){
                int temp;
                char ctemp;
                ctemp = msg.op4[0];
                temp = ((atoi(msg.op2) - 1) * 51  + atoi(msg.op3));
                printf("[SERVIDOR] character %c adicionado a %d [%s]\n", ctemp, temp, msg.endereco); 
                camposervidor[temp-1].cont[0] = ctemp;
                display_campo(camposervidor);
                strcpy(msg.resposta,"mudado\n");
                msg.campojogo = camposervidor;
            }
            /* ABRIR "CP" DO CLIENTE (open - O_WRONLY) */
            fd_cliente = open(msg.endereco, O_WRONLY);
            /* ENVIAR RESPOSTA PARA A "CP" DO CLIENTE (write) */
            write(fd_cliente, &msg, sizeof(msg));
            /* FECHAR "CP" DO CLIENTE (close) */
            close(fd_cliente);
        }while(msg.desliga != 1);

    printf("[SERVIDOR] SERVIDOR DESLIGADO\n");

    /* FECHAR "CP" DO SERVIDOR - MINHA (close) */
    close(fd_servidor);
    /* REMOVER "CP" DO SERVIDOR- MINHA (UNLINK) */
    unlink("CPservidor");
    exit(0);
}