/*TOTALS AS VARIAVEIS AQUI, A EXPLICAR O QUE CADA UMA FAZ */

int itera=0, //nr de vezes que o ciclo principal vai correr, ietraçoes
    k=0,  // usada para ciclos for()
    i=0,  // usada para ciclos for()
    j=0,  // usada para ciclos for()
    a=0,  // usada para ciclos for()
    p=0,  // usada para ciclos for()
    w=0,  // temporaria
    contador=0, // temporaria para contar pontos
    pontos=0, //nr pontos escolhidos
    pontos2=0, //nr pontos escolhidos para a iteraçao vizinha
    temp1=0,  //temp1
    temp2=0,  //temp2
    temp3=0,  //temp3
    ii=0,  // usada para ciclos for()
    melhor_nr=0, //melhor numero encontrado
    nr_pontos=0, // numero de pontos total no ficheiro aberto
    melhor_itera=0,
    total_sol=0; // numero total de combinaçoes para o ficheiro aberto


long nr_linhas=0, //numero de linhas
     nr_comb=0; //numero de combinaçoes possiveis para os numeros selecionados


char nome_fich[100], // nome do ficheiro a abrir
     save_file[250];


float melhor=0, //melhor valor encontrado
      temp4=0, //temp para guardar o melhor valor encontrado
      temp5=0, // mais uma variave para guardar o melhor resultado
      finalMelhor=0; //guarda o melhor valor no final de cada iteraçao


bool runs = false, //check se foi dado nr de vezes a corrrer na linha de comandos
     fiile = false; //check se foi dado nome do ficheiro a abrir na linha de comandos
