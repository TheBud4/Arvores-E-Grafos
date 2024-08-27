#ifndef DESENHA_ARVORE_BTREE_H
#define DESENHA_ARVORE_BTREE_H

#define ESPACO 5

void desenhaArvoreBTreeRecursivo(pNohBTree raiz, FuncaoImpressao fi) {
  if (raiz == NULL) {
    printf("?");
    return;
  }

  if (raiz->listaChavesValores == NULL ||
      raiz->listaChavesValores->quantidade == 0) {
    printf("[ ?-? ]");
    return;
  }

  int i;

  printf("[ ");

  desenhaArvoreBTreeRecursivo(raiz->primeiroFilho, fi);

  for (i = 0; i < raiz->listaChavesValores->quantidade; i++) {
    pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i + 1);
    fi(pcv->chave);
    desenhaArvoreBTreeRecursivo(pcv->filhoMaior, fi);
  }

  printf(" ]");
}

void desenhaArvore(pDBTree arvore, FuncaoImpressao fi) {
  desenhaArvoreBTreeRecursivo(arvore->raiz, fi);
}

#endif
