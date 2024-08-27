#include <stdio.h>
#include "Utils.h"
#include "Pilha.h"

int main(){
    pDPilha pPilhaInt = criarPilha();

    /* teste de empilhamento */
    empilharInfo(pPilhaInt, alocaInt(5));
    empilharInfo(pPilhaInt, alocaInt(3));
    empilharInfo(pPilhaInt, alocaInt(9));
    empilharInfo(pPilhaInt, alocaInt(1));
    empilharInfo(pPilhaInt, alocaInt(2));

    /* teste de desempilhamento */
    void *info = desempilharInfo(pPilhaInt);
    printf("\nDesempilhou o inteiro = %d \n", *((int*)info));

    while (pilhaVazia(pPilhaInt)==0){
        info = desempilharInfo(pPilhaInt);
        printf("\nDesempilhou o inteiro = %d \n", *((int*)info));
    }

}
