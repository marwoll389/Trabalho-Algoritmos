#ifndef

#define FILDA_DINAMICA

typedef struct Nodo{
    char info[100];
    struct Nodo* prox;
}nodo;

typedef struct Fila{
    nodo* inicio;
    nodo* fim;
}fila;

fila* cria();
void push(fila* f, char x[]);
char pop(fila* f);
void libera(fila* f);

#endif
