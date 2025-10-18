#include <stdlib.h>
#include <string.h>
#include "FD.h"


fila* criafila(){
    fila* novo = (fila*)malloc(sizeof(fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return novo;
}

void pushf(fila* f, char x[]){
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

char* popf(fila* f){
    if(f->inicio == NULL) return "NULL";
    
    
    strcpy(aux, f->inicio->info);
    nodo* temp = f->inicio;
    if(f->inicio == f->fim)
        f->fim == NULL;
    f->inicio = f->inicio->prox;
    free(temp);
    return aux;
}

void liberafila(fila* f){
    if(f == NULL) return;
    fila* temp = f->inicio;
    f->inicio = f->inicio->prox;
    free(temp);
    liberafila(f->inicio);
}

int tamanhof(fila* f){
    int i = 0;
    while(f->inicio != f->fim){
        i++;
        f->inicio = f->inicio->prox;
    }
    return i;
}
