#ifndef FE_H

#define FE_H
#define TAMANHO 10

typedef struct Fila{
    char v[TAMANHO][100];
    int inicio, fim;
} fila;

fila* criafila();
void pushf(fila* f, char x[]);
char* popf(fila* f);
void liberafila(fila* f);
int cheiaf(fila* f);
int vaziaf(fila* f);
int tamanhof(fila* f);

#endif
