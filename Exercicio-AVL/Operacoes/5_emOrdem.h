#ifndef EMORDEM_ARVORE_BINARIA_H
#define EMORDEM_ARVORE_BINARIA_H

/* --------------------------*/
void emOrdem(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){

       emOrdem(raiz->esquerda, fi);
       fi(raiz->info);
       emOrdem(raiz->direita, fi);
   }
}

#endif
