#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

/* ------------------------------------------------------------*/
pNohArvore paiFolhaMaisAEsquerda(pNohArvore raiz){

    if (raiz->esquerda == NULL)
        return raiz;

    if (raiz->esquerda != NULL)
    {
        if (raiz->esquerda->esquerda == NULL)
            return raiz;
    }
    return paiFolhaMaisAEsquerda(raiz->esquerda);
}

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc){

    if (raiz != NULL){

     if (fc(raiz->info, info) == 0) {
        /* antes de liberar a memoria do noh, salva a esquerda e a direita */
        pNohArvore auxEsquerda = raiz->esquerda;
        pNohArvore auxDireita  = raiz->direita;
        free(raiz);

        /* caso 1 - remover noh folha*/
        if (auxEsquerda == NULL && auxDireita == NULL){
           return NULL;
        }

        /* caso 3 - remover noh interno com 2 filhos */
        if (auxEsquerda != NULL && auxDireita != NULL){
            pNohArvore paiFolhaEsquerda;
            paiFolhaEsquerda = paiFolhaMaisAEsquerda(auxDireita);

            if (paiFolhaEsquerda->esquerda != NULL)
            {
              pNohArvore auxFolhaEsquerda = paiFolhaEsquerda->esquerda;
              auxFolhaEsquerda->esquerda  = auxEsquerda;
              auxFolhaEsquerda->direita   = auxDireita;

              paiFolhaEsquerda->esquerda = NULL;

              return auxFolhaEsquerda;
            }
            else{
               auxDireita->esquerda = auxEsquerda;
               return auxDireita;
            }


        }
        else{
           /* caso 2 - remover noh interno com 1 filho*/
           if (auxEsquerda != NULL)
              return auxEsquerda;

           return auxDireita;
        }
    }
    else{
        if (fc(info, raiz->info) > 0)
          raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);
        else
          raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);
    }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

   arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
   /* estah assumindo que sempre excluira */
   arvore->quantidadeNohs--;
   return 1;
}

#endif
