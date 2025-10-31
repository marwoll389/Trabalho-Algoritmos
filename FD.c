#include <stdlib.h>
#include <string.h>
#include "FD.h"


fila* criafila(){
    fila* novo = (fila*)malloc(sizeof(fila));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

void pushf(fila* f, arq x){
    nodo* novo = (nodo*)malloc(sizeof(nodo));
    strcpy(novo->arquivo.dado, x.dado);
    novo->arquivo.tempo = x.tempo;
    novo->prox = NULL;
    if(f->inicio == NULL)
        f->inicio = f->fim = novo;
    else{
        f->fim->prox = novo;
        f->fim = novo;
        }
}

arq popf(fila* f){
    arq aux;

    strcpy(aux.dado, f->inicio->arquivo.dado);
    aux.tempo = f->inicio->arquivo.tempo;
    if(f->inicio == f->fim)
        f->fim = NULL;
    f->inicio = f->inicio->prox;
    return aux;
}
//libera a fila de nodo em nodo
void liberafila(fila* f){
    while(f->inicio != NULL){
        nodo* temp = f->inicio;
        f->inicio = f->inicio->prox;
        free(temp);
    }
    f->fim = NULL;
    free(f);
}
// checa se a fila atingiu a capacidade máxima, 10
int cheiaf(fila* f){
    if(tamanhof(f) == 10) return 1;
    else return 0;
}
// checa se a fila está vazia
int vaziaf(fila* f){
    if(f->inicio == NULL) return 1;
    else return 0;
}
// retorna o tamanho da fila
int tamanhof(fila* f) {
    int i = 0;
    nodo* aux = f->inicio;

    while (aux != NULL) {
        i++;
        aux = aux->prox;
    }

    return i;
}
