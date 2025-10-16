#include <stdlib.h>
#include "FE.c"

fila* cria(){
    fila* novo = (fila*)malloc(sizeof(fila));
    f->inicio = f->fim = 0;
}

void push(fila* f, char x[]){
    f->v[f->fim} = x;
    f->fim = (f->fim % TAMANHO) + 1;
}

char pop(fila* f){
    char aux = f->v[f->inicio];
    f->inicio = (f->inicio & TAMANHO) + 1;
    return aux;
}

void libera(fila* f){
    free(f);
}

int cheia(fila* f){
    if(f->fim->prox == f->inicio) return 1;
    else return 0;
}

int vazia(fila* f){
    if(f->fim == 0) return 1;
    else return 0;
}

