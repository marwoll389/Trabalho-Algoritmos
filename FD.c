#include <stdlib.h>
#include "FD.h"


fila* cria(){
    fila* novo = (fila*)malloc(sizeof(fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return novo;
}

void push(fila* f, int x){
    nodo* novo = (nodo*)malloc(sizeof(nodo));
    novo->info = x;
    novo->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = f->fim = novo;
    else{
        f->fim->prox = novo;
        f->fim = novo;
        }
}

int pop(fila* f){
    int aux = f->inicio->info;
    nodo* temp = f->inicio;
    if( f->inicio == f->fim)
        f->fim == NULL;
    f->inicio = f->inicio->prox;
    free(temp);
    return aux;
}

void libera(fila* f){
    if(f == NULL) return;
    fila* temp = f->inicio;
    f->inicio = f->inicio->prox;
    free(temp);
    libera_fila(f->inicio);
}
