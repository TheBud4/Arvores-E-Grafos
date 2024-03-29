#include <stdio.h>
#include "Utils.h"
#include "ArvoreAVL.h"

pDArvore constroiArvore(int dados[], int tam){

    pDArvore arvore = criarArvore(2);
    int i;
    for(i=0; i<tam; i++){
        incluirInfo(arvore, alocaInt(dados[i]),comparaInt);
        desenhaArvore(arvore, imprimeInt);
    }

    return arvore;
}


int main(){

   int ex1[] = {5, 10, 3, 7, 6};             // rotacao simples - direita
   int ex2[] = {5, 10, 3, 12, 14};           // rotacao simples - esquerda
   int ex3[] = {5, 10, 3, 7, 8};             // rotacao dupla - esquerda/direita
   int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; // rotacao dupla - direita/esquerda
   int ex5[] = {5, 10, 3, 4, 12, 9, 14};     // Não precisa rotacionar

   //constroiArvore(ex1, 5);
   //constroiArvore(ex2, 5);
   constroiArvore(ex3, 5);
   //constroiArvore(ex4, 8);
   //constroiArvore(ex5, 7);

 }
