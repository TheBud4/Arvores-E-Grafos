#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Lista.h"

int main(){
    pDLista pListaInt = criarLista();

    int* pi = alocaInt(5);

    /* teste de inclusao */
    incluirInfoOrdenada(pListaInt, pi, comparaInt);
    incluirInfoOrdenada(pListaInt, alocaInt(3), comparaInt);
    incluirInfoOrdenada(pListaInt, alocaInt(9), comparaInt);
    incluirInfoOrdenada(pListaInt, alocaInt(1), comparaInt);
    incluirInfoOrdenada(pListaInt, alocaInt(2), comparaInt);

    printf("\nResultado da inclusao \n");
    imprimirLista(pListaInt, imprimeInt);
}
