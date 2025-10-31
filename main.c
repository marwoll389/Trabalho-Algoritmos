#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FD.h"
//#include "FD.c"
#include "PE.h"
//#include "PE.c"


int verifstring(char* x){
    //função necessária para possibilitar o uso indireto de strings para o switch case do laço principal
    // cada if verifica a entrada da opção e converte para um número correspondente
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

void next(fila* download){
    fila* aux = criafila();
    arq arqaux ;

    if(vaziaf(download) == 1){
        return;
    }

    arqaux = popf(download);

    //printf("%d\n",arqaux.tempo);

    if(arqaux.tempo == 0){
        printf("download %s concluido\n\n", arqaux.dado);

        if(vaziaf(download) == 1){
            //printf("nao ha mais downloads");
            return;}
        arqaux = popf(download);

        printf("iniciando download %s Termino em %d comandos\n\n",arqaux.dado,arqaux.tempo);

         arqaux.tempo = (arqaux.tempo) - 1;

        while(vaziaf(download)==0){
            pushf(aux, popf(download));
        }

        pushf(download, arqaux);

        while(vaziaf(aux)==0){
            pushf(download , popf(aux));
        }
    }
    else{
        arqaux.tempo = arqaux.tempo - 1;
        while(vaziaf(download)==0){
            pushf(aux, popf(download));
        }

        pushf(download, arqaux);

        while(vaziaf(aux)==0){
            pushf(download , popf(aux));
        }
    }

    liberafila(aux);
    return;
}

int main()
{
    int loop = 1; //variável controladora do laço principal
    pilha* obj = criapilha(); //pilha do histórico
    fila* download = criafila(); //fila dos downloads
    arq urld ;
    char opcao[20]; //string da opção que vai ser convertida
    int opcaof;// int auxiliar para converter a string opção em um número para o switch case
    char url[100];// string da entrada do url
    char aux[20];// string auxiliar em "voltar" que é  utiizada para colocar na pilha o valor rec-em retirado

    do{
        //recebe a entrada de opção do usuário e converte para um número
        scanf("%s", opcao);
        opcaof = verifstring(opcao);

        switch(opcaof){
            case 1: //caso "visitar"
                scanf("%s", url);
                printf("visualizando %s\n\n", url);
                //se a pilha estiver cheia, tamanho = 10, tira o primeiro elemento antes de colocar o novo
                if(cheiap(obj) == 1)
                    obj = tira1p(obj);
                pushp(obj, url);
                break;

            case 2:
                //mensagem de retorno caso não haja urls no hisstórico
                if(vaziap(obj) == 1){
                    printf("visualizando pagina em branco.\n");
                    break;
                }
                popp(obj);
                //segunda verificação do histórico, "voltar" precisa de uma pilha de tamanho >= 2
                if(vaziap(obj) == 1){
                    printf("visualizando pagina em branco.\n\n");
                    break;
                }
                //uso da string aux para tirar e colocar de volta o url da pilha
                strcpy(aux, popp(obj));
                printf("visitando %s\n\n", aux);
                pushp(obj, aux);

                break;

            case 3:

                // recebe o url de download e a quantidade de comandos e coloca na fila de download
                scanf("%s %d", urld.dado, &urld.tempo);
                // mensagem de retorno caso a fila de download esteja cheia, tamanho = 10
                if(cheiaf(download) == 1){
                    printf("fila cheia; arquivo nao inserido na fila\n");
                    break;
                }
                printf("inserido %s na fila\n", urld.dado);
                pushf(download, urld);

                break;

            case 4:
                //retorna o tamanho atual da pilha do histórico e da fila de download
                printf("arquivos na fila de download: %d\n\n", tamanhof(download));
                printf("paginas no historico: %d", tamanhop(obj));
                //variável controladora do loop principal tem o valor alterado, fim do loop
                loop = 0;
                break;

            default:
                break;//caso em que o uduário insere algum comando inválido, apenas continua o loop
        }
        //invoca a função que controla a fila de download
        next(download);
    }while(loop == 1);
}
