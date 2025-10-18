#include <stdlib.h>
#include <string.h>

#include "FE.h"

fila* criafila(){
    fila* novo = (fila*)malloc(sizeof(fila));
    novo->inicio = novo->fim = 0;
    return novo;
}

void pushf(fila* f, char* x){
    strcpy(f->v[f->fim], x);
    f->fim = (f->fim % TAMANHO) + 1;
}

char* popf(fila* f){
    char* aux = f->v[f->inicio];
    f->inicio = (f->inicio & TAMANHO) + 1;
    return aux;
}

void liberafila(fila* f){
    free(f);
}

int cheiaf(fila* f){
    if(f->fim + 1 == f->inicio) return 1;
    else return 0;
}

int vaziaf(fila* f){
    if(f->fim == 0) return 1;
    else return 0;
}

int tamanhof(fila* f){
    if(f->fim < f->inicio) return TAMANHO - (f->inicio - f->fim);
    else return f->fim - f->inicio;
}