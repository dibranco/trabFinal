#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
        li->MAX = 150; //máximo de pesquisadores por trabalho
        strcpy(li->trabalho, "NULL");
        li->nomes = malloc(150*sizeof(int));
    }
    return li;
}

void libera_lista(Lista* li){
    free(li->nomes);
    free(li);
}

int insere_lista_final(Lista* li, char trabalho[], int IdNome){

    if(li == NULL)
        return 0;

    if(li->qtd == 150)//lista cheia
        return 0;

    if(strcmp(li->trabalho, "NULL") == 0){
        strcpy(li->trabalho, trabalho);
    }

    li->nomes[li->qtd] = IdNome;

    li->qtd++;
    return 1;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return 0;
    int i;
    for(i = 0; i < li->qtd; i++){
        printf("TRABALHO: %s\n",li->trabalho);
        printf("idNome: %d\n",li->nomes[i]);
        printf("-------------------------------\n");
    }
}

int lista_retorno(Lista* li, int *retorno[], int *qtdadePesq){
    if(li == NULL)
        return 0;

    int i;
    for(i = 0; i < li->qtd; i++){
        retorno[i] = li->nomes[i];
    }

    *qtdadePesq = li->qtd;

    return 1;
}
