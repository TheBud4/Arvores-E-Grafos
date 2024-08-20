#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H

/* --------------------------*/
pDArvore criarArvore(int grau){
    pDArvore dArvore = malloc(sizeof(DArvore));
    dArvore->raiz = NULL;
    dArvore->quantidadeNohs = 0;
    dArvore->grau  = grau;

    return dArvore;
};

#endif
