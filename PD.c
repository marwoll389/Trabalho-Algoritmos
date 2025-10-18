//pilha dinamica

#inclide <stdio.h>
#include <stdlib.h>

#include "PD.h"
#include "FE.h"




pilha* criapilha(){
    pilha* pilhad = (pilha*)malloc(sizeof(pilha));
    pilhad = NULL;
    return pilhad;
}

void pushp(pilha* pilhad,char str[100]){
    pilha* pilhanova = (pilha*)malloc(sizeof(pilha));

    pilhanova->dado = str;
    pilhanova->prox = pilhad;
    pilhad = pilhanova;
    return ;
}


char* popp(pilha* pilhad){
    char x[100];
    pilha* pilhaaux ;

    x = pilhad->dado;
    pilhaaux = pilhad;
    pilhad = pilhad->prox ;
    free(pilhaaux);
    return x;
}

int cheiap(pilha* pilhad){
    int tamanho = 0;
    while(p != NULL){
        tamanho++;
        pilhad = pilhad->prox;
    }
    if(tamanho == 10) return 1
    else return 0;
}

pilha* tira1(pilha* pilhad){
    fila* aux = (fila*)malloc(sizeof(fila));
    while(pilhad->prox != NULL){
        pushf(aux, popp(pilhad));
    }
    pop(p);
    while(aux->inicio aux->fim){
        pushp(pilhad, popf(aux));
    }
    return p;
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

void liberap(pilha* pilhae){
    while(pilhad != NULL){
        pilha* aux = pilhad;   
        pilhad = pilhad->prox;
        free(aux);
        libera(pilhad);

        return;
    
    }
}