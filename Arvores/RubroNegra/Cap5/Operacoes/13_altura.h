#ifndef ALTURA_ARVORE_BINARIA_H
#define ALTURA_ARVORE_BINARIA_H

/* -------------------------------------------*/
int alturaRecursiva(pNohArvore raiz){
    if (raiz == NULL)
      return 0;

    // é uma folha
    if (raiz->esquerda == NULL && raiz->direita == NULL)
       return 1;

    int alturaEsq, alturaDir;

    alturaEsq = 1 + alturaRecursiva(raiz->esquerda);
    alturaDir = 1 + alturaRecursiva(raiz->direita);

    if (alturaEsq > alturaDir)
        return alturaEsq;

    return alturaDir;


}


int altura(pDArvore arvore){
   return alturaRecursiva(arvore->raiz);
}
#endif







