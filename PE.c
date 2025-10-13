#inclide <stdio.h>
#include <stdlib.h>
#include "PE.h"

//pilha estatica
typedef struct pilha{
    int pos;

    char dado[100][100];
}pilha;

pilha* criapilha(){
    pilha* pilhae;
    pilhae = (pilha*)malloc(sizeof(pilha*));
    pilhae->pos =0;
    return pilhae;
}

void push(pilha* pilhae,char str[100]){
   pilhae->pos = ((pilhae->pos)+1)%100
    pilhae->dado[pilhae->pos] = str;
    return pilhae;
}

char* pop(pilha* pilhae){
    char x[100];

    x = pilhae->dado[pilhae->pos];
    pilhae->pos = ((pilhae->pos)-1)%100;
    return x;
}
