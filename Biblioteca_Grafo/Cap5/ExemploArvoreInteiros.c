#include <stdio.h>
#include "Utils.h"
#include "ArvoreBinaria.h"

int main(){
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(3), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(9), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(1), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(2), comparaInt);

    emOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");

    desenhaArvore(pArvoreInt, imprimeInt);
/*
    preOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");
    posOrdem(pArvoreInt->raiz, imprimeInt);
*/
    /* teste de exclusao */
    int res = excluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    printf("\nExcluiu? = %d \n", res);
    desenhaArvore(pArvoreInt, imprimeInt);

    emOrdem(pArvoreInt->raiz, imprimeInt);
    printf("\n");

    int folhas = quantidadeFolhas(pArvoreInt->raiz);
    printf("\nQuantidade de folhas = %d \n", folhas);
}
