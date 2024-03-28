#ifndef CRIAR_ARVORE_NARIA_H
#define CRIAR_ARVORE_NARIA_H

NohArvore incluirInfoRecursivo (NohArvore raiz, void *info, FuncaoComparacao pfc, int grau)
{
   int i;
   /* verifica se a raiz atual tem todos os filhos preenchidos */
   if (raiz->filhos->quantidade == grau){

      /* escolher o filho da raiz atual que receberá o novo noh */
      for(i=1; i <= raiz->filhos->quantidade){
         /* próximo filho da raiz */
         pNohArvore filho = (pNohArvore) obtemInfo(raiz->filhos, i);
         /* verifica se achou a posicao do novo noh */
         if (pfc(filho->info, info) > 0){
            incluirInfo(*filho, info, pfc, grau);
         }
        /*  pNohArvore novoNoh = malloc(sizeof(NohArvore));
            novoNoh->info      = info;
            novoNoh->filhos    = criarLista();
         */
         return novoNoh;
      }

   }



};

/* --------------------------*/
void incluirInfo (pDArvore arvore, void *info, FuncaoComparacao fc){

   if (arvore != NULL)
       incluirInfoRecursivo(arvore->raiz, info, fc, arvore->grau);
};

#endif
