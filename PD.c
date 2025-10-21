//pilha dinamica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PD.h"
#include "FD.h"


pilha* criapilha(){
    pilha* pilhad = (pilha*)malloc(sizeof(pilha));
    pilhad = NULL;
    return pilhad;
}

void pushp(pilha* pilhad,char* str){
    pilha* pilhanova = (pilha*)malloc(sizeof(pilha));
    strcpy(pilhanova->dado, str);
    pilhanova->prox = pilhad;
    pilhad = pilhanova;
    return ;
}


char* popp(pilha* pilhad){
    char x[100];
    pilha* pilhaaux ;
    strcpy(x, pilhad->dado);
    pilhaaux = pilhad;
    pilhad = pilhad->prox ;
    free(pilhaaux);
    return x;
}

int cheiap(pilha* pilhad){
    int tamanho = 0;
    while(pilhad != NULL){
        tamanho++;
        pilhad = pilhad->prox;
    }
    if(tamanho == 10) return 1;
    else return 0;
}

pilha* tira1p(pilha* pilhad){
    fila* aux = (fila*)malloc(sizeof(fila));
    while(pilhad->prox != NULL){
        pushf(aux, popp(pilhad));
    }
    popp(pilhad);
    while(aux->inicio != NULL){
        pushp(pilhad, popf(aux));
    }
    return pilhad;
}

int vaziap(pilha* pilhad){
    if(pilhad == NULL) return 1;
    else return 0;
}

int tamanhop(pilha* pilhad){
    int i = 0;
    while(pilhad != NULL){
        i++;
        pilhad = pilhad->prox;
    }
    return i;
}

void liberapilha(pilha* pilhae){
    while(pilhae != NULL){
        pilha* temp = pilhae;
        pilhae = pilhae->prox;
        free(temp);
    }
}
