#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvore(int grau){

   pDArvore arvore        = malloc(sizeof(DArvore));
   arvore->raiz           = NULL;
   arvore->quantidadeNohs = 0;
   arvore->grau           = grau;

   return arvore;
};

#endif
