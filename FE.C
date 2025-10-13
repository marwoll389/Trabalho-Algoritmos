#include <stdlib.h>
#include "FE.c"

fila* cria_fila(){
    fila* novo = (fila*)malloc(sizeof(fila));
    f->inicio = f->fim = 0;
}

void push(fila* f, int x){
    f->v[f->topo] = x;
    f->topo = (f->topo % TAMANHO) + 1;
}

int pop(fila* f){
    int aux = f->v[f->inicio];
    f->inicio = (f->inicio & TAMANHO) + 1;
    return aux;
}

void libera_fila(fila* f){
    free(f);s
}
