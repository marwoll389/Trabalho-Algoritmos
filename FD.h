#ifndef

#define FILDA_DINAMICA

typedef struct Nodo{
    int info;
    struct Nodo* prox;
}nodo;

typedef struct Fila{
    nodo* inicio;
    nodo* fim;
}fila;

fila* cria_fila();
void push(fila* f, int x);
int pop(fila* f);
void libera_fila(fila* f);

#endif
