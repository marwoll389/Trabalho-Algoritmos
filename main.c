#include <stdio.h>
#include <stdlib.h>

//Apenas alterar para o nome de arquivo correspondente conforme a preferência de execução entre pilha/fila estática/dinâmica
#include "FE.h"
#include "FE.c"

//O código atual é apenas um breve esqueleto que não conta com nenhuma aplicação das filhas/pilhas,
//lógica do algoritmo não iniciada também

int main()
{
    int aux = 1;
    fila* obj = cria();
    do{
        char opcao[20];
        char url[100];
        scanf("%s %s", &opcao, &url);
        switch(opcao){
            case "visitar\0":
                printf("visitar %s\n", url);
                printf("visualizando %s\n\n", url);  //breve esboço, vai definitivamente ser alterado
                if(cheia == 1) pop(obj);
                push(obj, opcao);
                break;

            case "voltar\0":
                printf("voltar\n");
                char aux =
                printf("visitando %s\n\n", urlanterior); //a ser alterado

                break;

            case "download\0": //pensar em como fazer a lógica para o contador, possivelmente quebra a ideia de usar um switch case
                printf("download %s %d\n", urlatual, tempo);
                printf("inserido %s na fila", url);
                printf("iniciando %s. Termino em %d comandos", urlatual, tempo); //a ser alterado
                break;

            case "F\0":
                printf("F\n\n");
                printf("arquivos na fila de download: %d", numarquivos);//a ser alterado
                printf("paginas no historico: %d", historico);// a ser alterado
                aux = 0;
                break:

            case default:
                printf("%s");
                printf("Comando invalido, insira outro comando\n\n");
                break;
        }
    } while(aux == 1);
}
