#ifndef FE_H

#define FE_H
#define TAMANHO 10

typedef struct Arq{
    char dado[100];
    int tempo;
}arq;


typedef struct Fila{
    arq arquivo[TAMANHO];
    int inicio, fim;
} fila;

fila* criafila();
void pushf(fila* f, arq x);
arq popf(fila* f);
void liberafila(fila* f);
int cheiaf(fila* f);
int vaziaf(fila* f);
int tamanhof(fila* f);

#endif