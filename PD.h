#ifndef PD_H

#define PD_H
typedef struct Nodop{
    char dado[100];
    struct Nodop* prox;
} nodop;

typedef struct Pilha{
    nodop* topo;
}pilha;


pilha* criapilha();

void pushp(pilha* pilhad,char* str);

char* popp(pilha* pilhad);

int cheiap(pilha* pilhad); //verifica se a pilha esta cheia, verificação necessaria para "tira1"

pilha* tira1p(pilha* pilhad); //função para tirar o primeiro elemento da pilha quando chegar no tamanho máximo (10)

int vaziap(pilha* pilhad); //verifica se a pilha esta vazia, usado em "voltar"

int tamanhop(pilha* pilhad); //retorna o tamanho da pilha e imprime em "F"

void liberapilha(pilha* pilhad);

#endif
