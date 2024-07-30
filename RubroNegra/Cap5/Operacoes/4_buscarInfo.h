#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore buscarInfoRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc) {
    if (raiz == NULL) {

        return NULL;
    }

    int comparacao = pfc(info, raiz->info);

    if (comparacao == 0) {

        return raiz;
    }
    else if (comparacao > 0) {

        return buscarInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else {

        return buscarInfoRecursivo(raiz->direita, info, pfc);
    }
}


/* ----------------------------------------------------------*/
pNohArvore buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc) {
    return buscarInfoRecursivo(arvore->raiz, info, pfc);

}

#endif

