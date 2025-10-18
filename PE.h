#ifndef PE_H

#define PE_H

typedef struct pilha{
    int pos;

    char dado[100][100];
}pilha;

pilha* criapilha();

void pushp(pilha* pilhae,char* str);

char* popp(pilha* pilhae);

int cheiap(pilha* pilhae);

pilha* tira1p(pilha* pilhae);

int vaziap(pilha* pilhae);

int tamanhop(pilha* pilhae);

void liberapilha(pilha* pilhae);

#endif
