#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FD.h"
#include "FD.c"
#include "PE.h"
#include "PE.c"

int verifstring(char* x){
    if(strcmp(x, "visitar") == 0)
        return 1;
    else if(strcmp(x, "voltar") == 0)
        return 2;
    else if(strcmp(x, "download") == 0)
        return 3;
    else if(strcmp(x, "F") == 0)
        return 4;
        else return 0;
}

void next(fila* download,fila* contador){
    int x;
    char str[100];

    x = (int)popf(contador);

    if(x == 0){

        strcpy(popf(download), str);
        printf("download %s concluido\n",str);


        strcpy(str, popf(download));
        if(strcmp(str,"NULL")) {
            x = (int)popf(contador);
            printf(" iniciando download %s Termino em %d comandos",str,x);
            pushf(contador,(char*)x);
            pushf(download,str);
        }
        else{
          return;

        }
    }


    else{
        return;

    }
}

int main()
{
    int tempo;
    int loop = 1;
    pilha* obj = criapilha();
    fila* download = criafila();
    fila* contador = criafila();
    char opcao[20];
    char url[100];
    int opcaof;

    do{

        scanf("%s %s", opcao, url);
        opcaof = verifstring(opcao);

        switch(opcaof){
            case 1:
                printf("visitar %s\n", url);
                printf("visualizando %s\n\n", url);
                if(cheiap(obj) == 1)
                    obj = tira1p(obj);
                pushp(obj, opcao);
                break;

            case 2:
                printf("voltar\n");
                if(vaziap(obj) == 1){
                    printf("visualizando pagina em branco.\n");
                    break;
                }
                popp(obj);
                char aux[20];
                strcpy(aux, popp(obj));
                printf("visitando %s\n\n", aux);
                pushp(obj, aux);

                break;

            case 3:
                scanf("%d", &tempo);
                printf("download %s %d\n", url, tempo);
                printf("inserido %s na fila\n", url);
                while(tempo >= 0){
                    //pushf(contador, tempo);
                    tempo--;
                }
                break;

            case 4:
                printf("F\n\n");
                printf("arquivos na fila de download: %d", tamanhof(download));
                printf("paginas no historico: %d", tamanhop(obj));
                loop = 0;
                break;

            default:
                break;
        }
        next(download,contador);
    } while(loop == 1);
    liberafila(download);
    liberafila(contador);
    liberapilha(obj);
}
