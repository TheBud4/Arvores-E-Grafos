#include <stdio.h>
#include "Utils.h"
#include "Lista.h"

int main(){
    pDLista pListaData = criarLista();

    /* teste de inclusao */
    incluirInfo(pListaData, alocaData(05, 03, 2007));
    incluirInfo(pListaData, alocaData(12, 05, 2012));
    incluirInfo(pListaData, alocaData(10,  8, 2006));
    incluirInfo(pListaData, alocaData(01, 12, 2015));
    incluirInfo(pListaData, alocaData(23,  9, 2020));
    incluirInfo(pListaData, alocaData(18, 04, 2003));
    printf("\nResultado da inclusao \n");
    imprimirLista(pListaData, imprimeData);

    /* teste de exclusao */
    excluirInfo(pListaData, alocaData(18,04,2003), comparaData);
    printf("\nResultado da exclusao \n");
    imprimirLista(pListaData, imprimeData);

    /* teste de busca */
    int result = contemInfo(pListaData, alocaData(18,04,2003), comparaData);
    printf("\nResultado da busca: 0-[Nao encontrou], 1-[ok] -> %d\n", result);

    /* teste de duplicacao de lista */
    pDLista copia = duplicarLista(pListaData, alocaInfoData);
    printf("\nResultado da duplicacao \n");
    imprimirLista(copia, imprimeData);

    /* teste de divisao de lista */
    pDLista novaLista = dividirLista(pListaData, 1);
    printf("\nResultado da divisao \n");
    printf("    Lista Original: ");
    imprimirLista(pListaData, imprimeData);
    printf("\n    Nova Lista: ");
    imprimirLista(novaLista, imprimeData);

    /* teste de destruicao da lista */
    destruirLista(pListaData);
    printf("\nResultado da destruicao da lista \n");
    imprimirLista(pListaData, imprimeData);
}
