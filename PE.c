#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PE.h"
#include "FD.h"


int tamanhop(pilha* pilhae){
    return ((pilhae->pos)+1);
}

pilha* criapilha(){
    pilha* pilhae;
    pilhae = (pilha*)malloc(sizeof(pilha*));
    pilhae->pos = 0;
    return pilhae;
}

void pushp(pilha* pilhae,char str[100]){
   pilhae->pos = ((pilhae->pos)+1)%100;
    strcpy(str,(pilhae->dado[pilhae->pos]));

}

char* popp(pilha* pilhae){
    char x[100];

    strncpy(x, pilhae->dado[pilhae->pos], 100);
    pilhae->pos = ((pilhae->pos)-1)%100;
    return x;
}

int cheiap(pilha* pilhae){
    if(pilhae->pos == 99) return 1;
    else return 0;
}

pilha* tira1p(pilha* pilhae){
    fila* aux = malloc(sizeof(fila));
    while(pilhae->pos > 0){
        pushf(aux, popp(pilhae));
    }
    popp(pilhae);
    while(aux->inicio != aux->fim){
        pushp(pilhae, popf(aux));
    }
    return pilhae;
}

int vaziap(pilha* pilhae){
    if(pilhae->pos == 0) return 1;
    else return 0;
}

void liberapilha(pilha* pilhae){
    free(pilhae);
}
