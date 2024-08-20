#ifndef POSORDEM_ARVORE_BINARIA_H
#define POSORDEM_ARVORE_BINARIA_H

/* --------------------------*/
void posOrdem(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){
       posOrdem(raiz->esquerda, fi);
       posOrdem(raiz->direita, fi);
       fi(raiz->info);
   }
}

#endif





