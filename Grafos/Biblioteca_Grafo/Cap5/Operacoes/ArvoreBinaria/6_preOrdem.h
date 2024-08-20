#ifndef PREORDEM_ARVORE_BINARIA_H
#define PREORDEM_ARVORE_BINARIA_H

/* --------------------------*/
void preOrdem(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){
       fi(raiz->info);
       preOrdem(raiz->esquerda, fi);
       preOrdem(raiz->direita, fi);
   }
}

#endif
