#include <stdlib.h>
#include <string.h>
#include "FD.h"


fila* criafila(){
    fila* novo = (fila*)malloc(sizeof(fila));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

void pushf(fila* f, char* x){
    nodo* novo = (nodo*)malloc(sizeof(nodo));
    strcpy(novo->info, x);
    novo->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = f->fim = novo;
    else{
        f->fim->prox = novo;
        f->fim = novo;
        }
}

char* popf(fila* f){
    char aux[20];
    strcpy(aux, f->inicio->info);
    nodo* temp = f->inicio;
    if(f->inicio == f->fim)
        f->fim == NULL;
    f->inicio = f->inicio->prox;
    free(temp);
    return aux;
}

void liberafila(fila* f){
    while(f != NULL){
        nodo* temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
    }
    f->fim == NULL;
}

int cheiaf(fila* f){
    int i = 0;
    while(f->inicio != f->fim){
        i++;
        f->inicio = f->inicio->prox;
    }
    if(i == 10) return 1;
    else return 0;
}

int vaziaf(fila* f){
    if(f->inicio == NULL) return 1;
    else return 0;
}

int tamanhof(fila* f){
    int i = 0;
    while(f->inicio != f->fim){
        i++;
        f->inicio = f->inicio->prox;
    }
    return i;
}
