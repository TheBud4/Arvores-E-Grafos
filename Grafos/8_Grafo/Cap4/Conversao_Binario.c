#include <stdio.h>
#include "Pilha.h"



void imprimeInteiro(void *info){
   printf("%d - ", *((int *) info));
}


/* --------------------------*/
void main(){

    pDPilha pilha;

    int    n;

    scanf ("%d", &n);

    pilha = criarPilha();

    int *r;

    while (n > 0){

        r = (int *) malloc(sizeof(int));
        *r = n % 2;

        empilharInfo (pilha, r);

        n = n / 2;
    }

    /* teste de desempilhamento */
    void *info = desempilharInfo(pilha);
    printf("\nDesempilhou o inteiro = %d \n", *((int*)info));

    while (pilhaVazia(pilha)!=0){
        info = desempilharInfo(pilha);
        printf("\nDesempilhou o inteiro = %d \n", *((int*)info));
    }

  /*  void *info;

    info = desempilha(pilha);
    printf("\n");
    imprimeInteiro(info);

    printf("\n");
    mostrarPilha(pilha, imprimeInteiro);
    */
}




