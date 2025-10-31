#ifndef FD_H

#define FD_H

typedef struct Arq{
    char dado[100];
    int tempo;
}arq;

typedef struct Nodo{
    arq arquivo;
    struct Nodo* prox;
}nodo;

typedef struct Fila{
    nodo* inicio;
    nodo* fim;
} fila;

fila* criafila();
void pushf(fila* f, arq x);
arq popf(fila* f);
void liberafila(fila* f);
int cheiaf(fila* f);
int vaziaf(fila* f);
int tamanhof(fila* f);


#endif
