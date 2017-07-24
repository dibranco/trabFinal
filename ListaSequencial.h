

struct lista{
    int qtd, MAX;
    char trabalho[500];
    int *nomes
};
typedef struct lista Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, char trabalho[], int idNome);
void imprime_lista(Lista* li);
int lista_retorno(Lista* li, int *retorno[], int *qtdadePesq);
