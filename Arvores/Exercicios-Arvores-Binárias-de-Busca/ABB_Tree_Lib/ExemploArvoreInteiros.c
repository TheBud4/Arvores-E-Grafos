#include <stdio.h>
#include "Utils.h"
#include ""

int main(){
    pDArvore pArvoreInt = criarArvore(2);

    /* teste de inclusao */
    incluirInfo(pArvoreInt, alocaInt(9),comparaInt); 
    incluirInfo(pArvoreInt, alocaInt(5), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(2),comparaInt);
    incluirInfo(pArvoreInt, alocaInt(20),comparaInt);
    incluirInfo(pArvoreInt, alocaInt(10), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(18), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(17),comparaInt);
    incluirInfo(pArvoreInt, alocaInt(4), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(1), comparaInt);
    incluirInfo(pArvoreInt, alocaInt(80),comparaInt);  
    desenhaArvore(pArvoreInt, imprimeInt);
    //printf("\n Altura: %d \n",      altura(pArvoreInt));
    //printf("Qtde Folhas: %d \n", quantidadeFolhas(pArvoreInt));
    //printf("Qtde Nohs: %d \n",   quantidadeNohs(pArvoreInt));
    //printf("Info: %d\n",buscarInfo(pArvoreInt, alocaInt(1), comparaInt));
    excluirInfo(pArvoreInt, alocaInt(9),comparaInt);

    desenhaArvore(pArvoreInt, imprimeInt);


}