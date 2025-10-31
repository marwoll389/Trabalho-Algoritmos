#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PD.h"


pilha *criapilha() {
    pilha *pilhanova = (pilha *)malloc(sizeof(pilha));
    pilhanova->topo = NULL;
    return pilhanova;
}

int vaziap(pilha *pilhad) {
    if(pilhad->topo == NULL) return 1;
    else return 0;

}

void pushp(pilha *p, char* str) {
    nodop *novo = (nodop*)malloc(sizeof(nodop));
    strcpy(novo->dado, str);
    novo->prox = p->topo;
    p->topo = novo;
}

char* popp(pilha *p) {
    if(vaziap(p)) return NULL;
    char* x = (char*)malloc(sizeof(p->topo->dado));
    strcpy(x, p->topo->dado);
    nodop *aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
    return x;
}


int cheiap(pilha* p){
    int tamanho = 0;
    nodop* aux = p->topo;

    while(aux != NULL){
        tamanho++;
        aux = aux->prox;
    }

    return tamanho == 10;// tamanho máximo da pilha do histórico = 10
}

pilha* tira1p(pilha* pilhad){
    pilha* aux = criapilha();
    //inverte a ordem dos elementos da pilha com uma pilha auxiliar
    while(pilhad->topo != NULL){
        pushp(aux, popp(pilhad));
    }
    //libera o primeiro elemento da pilha invertida, correspondne a remover o último elemento da pilha original
    popp(aux);
    //inverte a pilha novamente para restaurar a ordem original
    while(aux->topo != NULL){
        pushp(pilhad, popp(aux));
    }
    liberapilha(aux);
    return pilhad;
}



int tamanhop(pilha* pilhad){
    int i = 0;
    nodop* aux = pilhad->topo;
    while(aux != NULL){
        i++;
        aux = aux->prox;
    }
    return i;
}

void liberapilha(pilha* pilhae){
    nodop* aux = pilhae->topo;
    while(aux != NULL){
        nodop* temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(pilhae);
}
