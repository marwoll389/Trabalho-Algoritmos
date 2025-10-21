#ifndef PD_H

#define PD_H

typedef struct pilha{
    char dado[100];
    struct pilha* prox;
}pilha;


pilha* criapilha();

void pushp(pilha* pilhad,char* str);

char* popp(pilha* pilhad);

int cheiap(pilha* pilhad);

pilha* tira1p(pilha* pilhad);

int vaziap(pilha* pilhad);

int tamanhop(pilha* pilhad);

void liberapilha(pilha* pilhad);

#endif
