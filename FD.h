#ifndef FD_H

#define FD_H

typedef struct Nodo{
    char info[100];
    struct Nodo* prox;
}nodo;

typedef struct Fila{
    nodo* inicio;
    nodo* fim;
} fila;

fila* criafila();
void pushf(fila* f, char* x);
char* popf(fila* f);
void liberafila(fila* f);
int cheiaf(fila* f);
int vaziaf(fila* f);
int tamanhof(fila* f);


#endif
