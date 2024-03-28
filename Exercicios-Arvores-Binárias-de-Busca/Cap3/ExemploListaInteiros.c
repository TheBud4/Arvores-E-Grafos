#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Lista.h"

int main(){
    pDLista pListaInt = criarLista();

    int* pi = alocaInt(5);

    /* teste de inclusao */
    incluirInfo(pListaInt, pi);
    incluirInfo(pListaInt, alocaInt(3));
    incluirInfo(pListaInt, alocaInt(9));
    incluirInfo(pListaInt, alocaInt(1));
    incluirInfo(pListaInt, alocaInt(2));

    printf("\nResultado da inclusao \n");
    imprimirLista(pListaInt, imprimeInt);

    /* teste de exclusao */
    excluirInfo(pListaInt, alocaInt(9), comparaInt);
    printf("\nResultado da exclusao \n");
    imprimirLista(pListaInt, imprimeInt);

    /* teste de busca */
    int result = contemInfo(pListaInt, alocaInt(5), comparaInt);
    printf("\nResultado da busca do numero 5: 0-[Nao encontrou], 1-[ok] -> %d\n", result);

    /* teste de duplicacao de lista */
    pDLista copia = duplicarLista(pListaInt, alocaInfoInt);
    printf("\nResultado da duplicacao \n");
    imprimirLista(copia, imprimeInt);

    /* teste de divisao de lista */
    pDLista novaLista = dividirLista(pListaInt, 3);
    printf("\nResultado da divisao \n");
    printf("    Lista Original: ");
    imprimirLista(pListaInt, imprimeInt);
    printf("\n    Nova Lista: ");
    imprimirLista(novaLista, imprimeInt);

    /* teste de destruicao da lista */
    //destruirListaInfo(pListaInt, liberaInt);
    //printf("\nResultado da destruicao da lista \n");
    //imprimirLista(pListaInt, imprimeInt);

  //  unirListas(pListaInt, pListaInt, comparaInt);


}
