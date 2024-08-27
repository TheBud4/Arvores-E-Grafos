#ifndef CRIAR_ARVORE_BTREE_H
#define CRIAR_ARVORE_BTREE_H

/* --------------------------*/
pDBTree criarBTree(int ordem){
    pDBTree bTree = malloc(sizeof(DBTree));
    bTree->raiz   = NULL;
    bTree->ordem  = ordem;

    return bTree;
};

#endif
