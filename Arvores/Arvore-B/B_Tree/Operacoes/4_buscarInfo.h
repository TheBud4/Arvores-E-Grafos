#ifndef BUSCAR_INFO_BTREE_H
#define BUSCAR_INFO_BTREE_H

pNohBTree buscarInfoBTreeRecursivo(pNohBTree raiz, void *chave,
                                   FuncaoComparacao pfc) {
  if (raiz == NULL) return NULL;

  pChaveValor pValorAtual;
  int i;
  for (i = 1; i <= raiz->listaChavesValores->quantidade; i++) {
    pValorAtual = buscarInfoPos(raiz->listaChavesValores, i);
    int comparacao = pfc(pValorAtual, chave);
    if (comparacao == 0) {
      return raiz;
    }
    if (comparacao < 0) {
      printf("Volta: %d\n", i);
      return buscarInfoBTreeRecursivo(raiz->primeiroFilho, chave, pfc);
    }
  }

  return buscarInfoBTreeRecursivo(pValorAtual->filhoMaior, chave, pfc);
}

/* ----------------------------------------------------------*/
void *buscarInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
  return buscarInfoBTreeRecursivo(arvore->raiz, chave, pfc);
}

#endif