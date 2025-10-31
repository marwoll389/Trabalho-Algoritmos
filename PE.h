#ifndef PE_H

#define PE_H

typedef struct pilha{
    int pos;

    char dado[10][100];

}pilha;

pilha* criapilha();

void pushp(pilha* pilhae,char* str);

char* popp(pilha* pilhae);

int cheiap(pilha* pilhae); //verifica se a pilha esta cheia, verificação necessaria para "tira1"

pilha* tira1p(pilha* pilhae); //função para tirar o primeiro elemento da pilha quando chegar no tamanho máximo (10)

int vaziap(pilha* pilhae); //verifica se a pilha esta vazia, usado em "voltar"

int tamanhop(pilha* pilhae); //retorna o tamanho da pilha e imprime em "F"

void liberapilha(pilha* pilhae);

#endif
