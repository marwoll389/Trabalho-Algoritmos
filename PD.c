//pilha dinamica

#inclide <stdio.h>
#include <stdlib.h>

#include "PD.h"


typedef struct pilha{
    char dado[100];
    struct pilha* prox;
}pilha;

pilha* criapilha(){
    pilha* pilhad = (pilha*)malloc(sizeof(pilha));
    pilhad = NULL;
    return pilhad;
}

void push(pilha* pilhad,char str[100]){
    pilha* pilhanova = (pilha*)malloc(sizeof(pilha));

    pilhanova->dado = str;
    pilhanova->prox = pilhad;
    pilhad = pilhanova;
    return ;
}


char* pop(pilha* pilhad){
    char x[100];
    pilha* pilhaaux ;

    x = pilhad->dado;
    pilhaaux = pilhad;
    pilhad = pilhad->prox ;
    free(pilhaaux);
    return x;
}
