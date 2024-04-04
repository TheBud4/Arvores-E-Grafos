#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include <stdlib.h>

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc) {

    if (raiz == NULL)
    {
        printf("raiz nula\n");
        return raiz;
    }
    printf("Passou aqui 1\n");

    //Caso 1 e 2 - Nó com nenhum ou 1 filho
    int comparacao = pfc(info, raiz->info);

    if (comparacao > 0) {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else if (comparacao < 0) {
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }
    else {

        if (raiz->esquerda == NULL) {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        //Caso 3 - Noh com 2 filhos
        pNohArvore temp = raiz->direita ;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->info = temp->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, pfc);
    }

    raiz->fb = alturaRecursiva(raiz->direita) -
               alturaRecursiva(raiz->esquerda);

    if (raiz->fb == 2 || raiz->fb == -2) {

        if (raiz->fb == 2) {
            if ((raiz->direita  != NULL && (raiz->direita->fb  == 1 || raiz->direita->fb  == 0)) ||
                    (raiz->esquerda !=NULL  && (raiz->esquerda->fb == 1 || raiz->esquerda->fb == 0))) {

                pNohArvore novaRaiz = rotacaoEsquerda(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

            if ((raiz->direita != NULL && raiz->direita->fb  == -1) ||
                    (raiz->esquerda != NULL && raiz->esquerda->fb == -1)) {

                pNohArvore novaRaiz = rotacaoDireitaEsquerda(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }
        }


        if (raiz->fb == -2) {

            if ((raiz->direita != NULL && (raiz->direita->fb  == -1 || raiz->direita->fb  == 0)) ||
                    (raiz->esquerda !=NULL && (raiz->esquerda->fb == -1 || raiz->esquerda->fb == 0))) {
                
                pNohArvore novaRaiz = rotacaoDireita(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

            if ((raiz->direita != NULL && raiz->direita->fb  == 1) ||
                    (raiz->esquerda != NULL && raiz->esquerda->fb == 1)) {

                pNohArvore novaRaiz = rotacaoEsquerdaDireita(raiz);
                recalcularFB_Recursivo(novaRaiz);
                return novaRaiz;
            }

        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {

    printf("Excluindo...\n");
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 0;
}



#endif
