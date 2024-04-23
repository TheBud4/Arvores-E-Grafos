#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

   // caso base
   if (raiz == NULL)
   {
       pNohArvore pnh = malloc(sizeof(NohArvore));
       pnh->info = info;
       pnh->esquerda = NULL;
       pnh->direita = NULL;
       return pnh;
   }

   // caso recursivo
   if (pfc(raiz->info, info) <= 0)
       raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);
   else
       raiz->direita = incluirInfoRecursivo(raiz->direita, info, pfc);
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){
   if(arvore->raiz == NULL)
      arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
    else
        incluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif

