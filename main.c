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
    //criação de variaveis auxiliares para a função
    fila* aux = criafila();
    arq arqaux ;

    if(vaziaf(download) == 1){//checa caso não haja nenhum download na fila
        return;
    }

    arqaux = popf(download);//recebe a struct do download da fila

    

    if(arqaux.tempo == 0){
        //caso o tempo do download seja 0, o download é concluido e a função retorna
        printf("download %s concluido\n", arqaux.dado);

        if(vaziaf(download) == 1){//caso não haja mais nenhum download na fila, a função retorna
            
            return;}
        //caso haja mais downloads na fila, o próximo download é iniciado
        arqaux = popf(download);

        printf("iniciando download %s Termino em %d comandos\n",arqaux.dado,arqaux.tempo);
        //reduz o tempo do próximo download em 1
         arqaux.tempo = (arqaux.tempo) - 1;

        //coloca o download com o tempo reduzido de volta na fila, para que ele volte a primeira posição a fila é movida, o download inserido e depois a fila é retornada
        while(vaziaf(download)==0){
            pushf(aux, popf(download));
        }

        pushf(download, arqaux);

        while(vaziaf(aux)==0){
            pushf(download , popf(aux));
        }
    }
    else{
        //caso o tempo do download não seja 0, o tempo é reduzido em 1 e o download é colocado de volta na fila
        arqaux.tempo = arqaux.tempo - 1;
        while(vaziaf(download)==0){
            pushf(aux, popf(download));
        }

        pushf(download, arqaux);

        while(vaziaf(aux)==0){
            pushf(download , popf(aux));
        }
    }

    liberafila(aux);//libera a fila auxiliar
    return;
}

int main()
{
    int loop = 1; //variável controladora do laço principal
    pilha* obj = criapilha(); //pilha do histórico
    fila* download = criafila(); //fila dos downloads
    arq urld ;// struct do arquivo de download
    char opcao[20]; //string da opção que vai ser convertida
    int opcaof;// int auxiliar para converter a string opção em um número para o switch case
    char url[100];// string da entrada do url
    char aux[20];// string auxiliar em "voltar" que é  utiizada para colocar na pilha o valor rec-em retirado
    int p = 0; //variavel para imprimir as informações do primeiro download da fila
    
    do{
        //recebe a entrada de opção do usuário e converte para um número
        scanf("%s", opcao);
        opcaof = verifstring(opcao);

        switch(opcaof){
            case 1: //caso "visitar"
                scanf("%s", url);
                printf("visualizando %s\n", url);
                //se a pilha estiver cheia, tamanho = 10, tira o primeiro elemento antes de colocar o novo
                if(cheiap(obj) == 1)
                    obj = tira1p(obj);
                pushp(obj, url);
                break;

            case 2:
                //mensagem de retorno caso não haja urls no histórico
                if(vaziap(obj) == 1){
                    printf("visualizando pagina em branco.\n");
                    break;
                }
                popp(obj);
                //segunda verificação do histórico, "voltar" precisa de uma pilha de tamanho >= 2
                if(vaziap(obj) == 1){
                    printf("visualizando pagina em branco.\n");
                    break;
                }
                //uso da string aux para tirar e colocar de volta o url da pilha
                strcpy(aux, popp(obj));
                printf("visitando %s\n", aux);
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
                if(p == 0){// printa as informações do primeiro download da fila, depois isso é gerido pela next()
                    printf("iniciando download %s Termino em %d comandos\n", urld.dado, urld.tempo);
                    p = 1;
                    
                }
                pushf(download, urld);

                break;

            case 4:
                //retorna o tamanho atual da pilha do histórico e da fila de download
                printf("arquivos na fila de download: %d\n", tamanhof(download));
                printf("paginas no historico: %d", tamanhop(obj));
                liberapilha(obj);
                liberafila(download);
                //libera as pilhas e filas e encerra o programa
                //variável controladora do loop principal tem o valor alterado, fim do loop
                loop = 0;
                break;

            default:
                break;//caso em que o uduário insere algum comando inválido, apenas continua o loop
        }
        //invoca a função que controla a fila de download
        next(download);
        printf("\n");
    }while(loop == 1);
}
