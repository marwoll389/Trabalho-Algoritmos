#ifndef

#define FILHA_ESTATICA
#define TAMANHO 100

typedef struct Fila{
    int v[TAMANHO];
    int inicio, fim;
}fila;

fila* cria();
void push(fila* f, int x);
int pop(fila* f);
void libera(fila* f);

#endif
