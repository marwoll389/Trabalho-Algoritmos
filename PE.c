#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PE.h"


int tamanhop(pilha* pilhae){
    return (pilhae->pos);
}

pilha* criapilha(){
    pilha* pilhae;
    pilhae = (pilha*)malloc(sizeof(pilha));
    pilhae->pos = 0;
    return pilhae;
}

void pushp(pilha* pilhae,char str[100]){
   pilhae->pos = (pilhae->pos)+1;
    strcpy((pilhae->dado[pilhae->pos]), str);

}

char* popp(pilha* pilhae){
    char* x = (char*)malloc(sizeof(pilhae->dado));

    strcpy(x, pilhae->dado[pilhae->pos]);

    pilhae->pos = (pilhae->pos)-1;
    return x;
}

int cheiap(pilha* pilhae){
    if(pilhae->pos == 10) return 1; //tamanho máximo = 10
    else return 0;
}

pilha* tira1p(pilha* pilhae){
    pilha* aux = criapilha();
    //inverte a ordem dos elementos da pilha com uma pilha auxiliar
    while(pilhae->pos != 0){
        pushp(aux, popp(pilhae));
    }
    //libera o primeiro elemento da pilha invertida, correspondne a remover o último elemento da pilha original
    popp(aux);
    //inverte a pilha novamente para restaurar a ordem original
    while(aux->pos != 0){
        pushp(pilhae, popp(aux));
    }
    liberapilha(aux);
    return pilhae;
}

int vaziap(pilha* pilhae){
    if(pilhae->pos == 0) return 1;
    else return 0;
}

void liberapilha(pilha* pilhae){
    free(pilhae);
}
