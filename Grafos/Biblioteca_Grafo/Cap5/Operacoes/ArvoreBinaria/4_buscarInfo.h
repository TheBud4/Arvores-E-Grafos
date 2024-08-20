#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore buscarInfoRecursivo (pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    /* caso recursivo */
    if (raiz != NULL){
        if (pfc(info, raiz->info) == 0)
            return raiz;

        if (pfc(info, raiz->info) >= 0)
            return buscarInfoRecursivo(raiz->esquerda, info, pfc);
        else
            return buscarInfoRecursivo(raiz->direita, info, pfc);
    }

    /* caso base */
    return NULL;

}


/* ----------------------------------------------------------*/
pNohArvore buscarInfo (pDArvore arvore, void *info, FuncaoComparacao pfc)
{
   return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif

