#include <stdlib.h>
#include <string.h>

#include "FE.h"

fila* criafila(){
    fila* novo = (fila*)malloc(sizeof(fila));
    novo->inicio = novo->fim = 0;
    return novo;
}

void pushf(fila* f, arq x){
    strcpy(f->arquivo[f->fim].dado, x.dado);
    f->arquivo[f->fim].tempo = x.tempo;
    f->fim = (f->fim +1) % TAMANHO;
}

arq popf(fila* f){
    arq aux ;
    
    if(f->inicio == f->fim) {
        printf("fila vazia\n");
        return aux;
    }
    strcpy(aux.dado, f->arquivo[f->inicio].dado);
    aux.tempo = f->arquivo[f->inicio].tempo;
    f->inicio = (f->inicio +1) % TAMANHO;
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
    if(f->fim == f->inicio) return 1;
    else return 0;
}

int tamanhof(fila* f){
    if(f->fim < f->inicio) return TAMANHO - (f->inicio - f->fim);
    else return f->fim - f->inicio;
}