#define TAM 10
//----------RANDOM-FUNC----------------------
int obtem_rand(int min, int max){
    int random;
    random = min + (rand() % (max - min + 1));
    return random;
}
//----------ESTRUTURA-MENSAGEM---------------
typedef struct mensagem{
	char op1[TAM], op2[TAM];
	char resposta[1000];
    char endereco[20];
    int desliga;
}MENSAGEM;