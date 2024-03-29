#ifndef RECALCULAR_FB_ARVORE_H
#define RECALCULAR_FB_ARVORE_H

void recalcularFB_Recursivo(pNohArvore raiz) {

    if (raiz == NULL)
        return;

    raiz->fb = alturaRecursiva(raiz->direita) - alturaRecursiva(raiz->esquerda);
    recalcularFB_Recursivo(raiz->esquerda);
    recalcularFB_Recursivo(raiz->direita);
}

void recalcularFB(pDArvore arvore) {
   recalcularFB_Recursivo(arvore->raiz);
}

#endif
