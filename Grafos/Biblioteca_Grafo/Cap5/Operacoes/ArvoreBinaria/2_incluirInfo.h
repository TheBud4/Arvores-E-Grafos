#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    /* caso recursivo */
    if (raiz != NULL){
        if (pfc(info, raiz->info) >= 0)
            raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);
        else
            raiz->direita  = incluirInfoRecursivo(raiz->direita, info, pfc);

        return raiz;
    }
    else{
       /* caso base */
       pNohArvore novo = malloc(sizeof(NohArvore));
       novo->info     = info;
       novo->esquerda = NULL;
       novo->direita  = NULL;
       return novo;
    }
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

   arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
   arvore->quantidadeNohs++;
}

#endif

