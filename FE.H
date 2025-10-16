#ifndef

#define FILHA_ESTATICA
#define TAMANHO 10

typedef struct Fila{
    char v[100][TAMANHO];
    int inicio, fim;
}fila;

fila* cria();
void push(fila* f, char x[]);
char pop(fila* f);
void libera(fila* f);
int cheia(fila* f);
int vazia(fila* f);
char voltar(fila* f);

#endif
