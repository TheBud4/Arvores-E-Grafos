#include <stdio.h>
#include "Utils.h"
#include "Fila.h"

int main(){
    pDFila pFilaInt   = criarFila();

    pDFila pFilaCopia = criarFila();

    /* teste de enfileiramento */
    enfileirarInfo(pFilaInt, alocaInt(5));
    enfileirarInfo(pFilaInt, alocaInt(3));
    enfileirarInfo(pFilaInt, alocaInt(9));
    enfileirarInfo(pFilaInt, alocaInt(1));
    enfileirarInfo(pFilaInt, alocaInt(2));

    /* teste de desenfileiramento */
    void *info = desenfileirarInfo(pFilaInt);
    enfileirarInfo(pFilaCopia, info);
    printf("\nRetirou o inteiro = %d \n", *((int*)info));

    while (filaVazia(pFilaInt)!=0){
        info = desenfileirarInfo(pFilaInt);
        enfileirarInfo(pFilaCopia, info);
        printf("\nRetirou o inteiro = %d \n", *((int*)info));
    }

    /* Como ficou a fila original? ficou vazia!
       Mas temos uma cópia dela na outra fila */
}
