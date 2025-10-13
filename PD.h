#ifndef

#define "PD.h"

typedef struct pilha{
    char dado[100];
    struct pilha* prox;
}pilha;


pilha* criapilha()

void push(pilha* pilhae,char str[100])

char* pop(pilha* pilhae)

#endif
