#ifndef

#define FILHA_ESTATICA
#define TAMANHO 101

typedef struct Fila{
    int v[TAMANHO];
    int inicio, fim;
}fila;

fila* cria_fila();
void push(fila* f, int x);
int pop(fila* f);
void libera_fila(fila* f);

#endif
