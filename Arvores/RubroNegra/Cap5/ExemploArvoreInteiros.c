#include <stdio.h>
#include "Utils.h"
#include "ArvoreRubroNegra.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvore(2);
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
    }

    return arvore;
}


int main(){

  //  int ex1[]   = {5, 10, 3, 2};   // caso 1
  //  int ex1_1[] = {5, 3, 2};       // caso 2.1
  //  int ex1_2[] = {5, 10, 12};     // caso 2.2
  //  int ex1_3[] = {5, 3, 4};       // caso 2.3
  //  int ex2[]   = {5, 10, 3, 2, 12, 11};  // caso 1 e caso 2.3
  //  int ex3[]   = {5, 10, 3, 2, 7, 8};    // caso 2.2
  //  int ex4[]   = {5, 10, 3, 2, 14, 12};  // caso 2.4
   int ex5[]   = {8, 3, 21, 16, 27, 9, 18, 29, 10}; // v�rios casos juntos

 //pDArvore arvore = constroiArvore(ex1, 4);
 // pDArvore arvore = constroiArvore(ex1_1, 3);
 // pDArvore arvore = constroiArvore(ex1_3, 3);
 // pDArvore arvore = constroiArvore(ex2, 6);
 // pDArvore arvore = constroiArvore(ex3, 6);
 // pDArvore arvore = constroiArvore(ex4, 6);
  pDArvore arvore = constroiArvore(ex5, 9);  
  
  
    int inteiro = 9;
  
     pNohArvore noh = buscarInfo(arvore, alocaInt(inteiro), comparaInt);

    // Faz o casting do valor buscado para int e imprime
    int *pi = (int *) noh->info;

    // printf("Buscando %d: ", *pi);
    
    // printf("%d\n", *pi);

    excluirInfo(arvore, alocaInt(inteiro), comparaInt);

    printf("Excluindo %d: ", *pi);

    desenhaArvore(arvore, imprimeInt);

   return 0;
 }


