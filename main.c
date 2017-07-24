#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h"

int main()
{
    FILE *arq;
    arq = fopen("dadosPesquisadores.txt","r");

    if(arq == NULL){
        printf("\nERRO NA ABERTURA DO ARQUIVO!");
        return 0;
    }

    Hash* trabPesq;
    trabPesq = criaHash(500009);

    char *pont;
    char linha[600];
    char nome[100];
    char trab[500];

    char trabalho[500];
    int ret;
    int idPesquisadores[150];
    int qtdadePesquisadores;
    int k;

    insereHash(trabPesq, "microstructure and wear of a cu-si-b alloy and diamond composites obtained in high pressure and high temperature conditions",200);
    insereHash(trabPesq, "microstructure and wear of a cu-si-b alloy and diamond composites obtained in high pressure and high temperature conditions",201);
    insereHash(trabPesq, "microstructure and wear of a cu-si-b alloy and diamond composites obtained in high pressure and high temperature conditions",20154);

    buscaHash(trabPesq, "microstructure and wear of a cu-si-b alloy and diamond composites obtained in high pressure and high temperature conditions", &idPesquisadores, &qtdadePesquisadores);

    for(k = 0; k < qtdadePesquisadores; k++){
        printf("\nId = %d", idPesquisadores[k]);
    }
    system("pause");

//CRIAR ARQUIVO COM TODOS OS NOMES

////    FILE *names;
////    names = fopen("nomes2.txt","w");
////    if(names == NULL){
////        printf("ERRO");
////        exit(0);
////    }
////
////    struct i{
////        char nome[300];
////    };
////    typedef struct i nomePesq;
////
////    nomePesq pesq[2];
////    int nomes = 0;
////    int j = 1;
////
////
////    while(1){
////        fgets(linha, 600, arq);
////        pont = strtok(linha, "\t");
////        strcpy(nome,pont);
////        pont = strtok(NULL,"\t");
////        strcpy(trab,pont);
////        strcpy(pesq[j%2].nome, nome);
////
////        if(strcmp(pesq[0].nome, pesq[1].nome) != 0){
////            fprintf(names,"%s\n",nome);
////            j++;
////            nomes++;
////        }
////
////        if(feof(arq))
////            break;
////    }


    liberaHash(trabPesq);

    fclose(arq);
    //fclose(names);

    return(0);
}
