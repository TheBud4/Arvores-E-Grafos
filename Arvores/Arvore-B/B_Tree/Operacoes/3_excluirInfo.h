#ifndef EXCLUIRINFO_BTREE_H
#define EXCLUIRINFO_BTREE_H

/* Funcao para substituir um nó pelo outro */
int encontrarIndice(void **listaChaves, void *chave, FuncaoComparacao fc,
                    int numChaves) {
  int i = 0;
  while (i < numChaves && fc(listaChaves[i], chave) < 0) {
    ++i;
  }
  return i;
}

/* --------------------------*/
pNohBTree excluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave,
                                    FuncaoComparacao fc) {
  pChaveValor pValorAtual, pValorAnterior;
  int i = 1;

  if (raiz == NULL) {
    return NULL;
  }

  //--------------------------------------------------------
  int aux = contemInfo(raiz->listaChavesValores, chave, fc);
  if (aux == 0) {
    if (ehFolha(raiz)) {
      excluirInfo(raiz->listaChavesValores, chave, fc);
      return raiz;
    } else {
      // outros casos

      pChaveValor pcvAtual, pcvAnt = NULL;
      while (i <= raiz->listaChavesValores->quantidade) {
        pcvAnt = pcvAtual;
        pcvAtual = buscarInfoPos(raiz->listaChavesValores, i);

        int r = fc(pcvAtual, chave);
        if (r == 0) {
          pcvAnt = pcvAtual;
          pcvAtual->chave = raiz->primeiroFilho;
          excluirInfoBTreeRecursivo(pcvAnt->valor, ordem, chave, fc);
          return pcvAtual->chave;
        }
        if (r == 0 && i > 1 && i < raiz->listaChavesValores->quantidade) {
          pcvAnt = pcvAtual;
          pcvAtual->chave = raiz->primeiroFilho;
          excluirInfoBTreeRecursivo(pcvAnt->filhoMaior, ordem, chave, fc);
          break;
        }

        if (r < 0) {
          return NULL;
        }
        if (r > 0) {
          i++;
        }
      }

      return NULL;
    }
  }

  while (i <= raiz->listaChavesValores->quantidade) {
    pValorAtual = buscarInfoPos(raiz->listaChavesValores, i);

    if (fc(pValorAtual, chave) > 0) pValorAnterior = pValorAtual;

    if (fc(pValorAtual, chave) < 0) break;

    i++;
  }

  if (i > 1) {
    return excluirInfoBTreeRecursivo(pValorAnterior->filhoMaior, ordem, chave,
                                     fc);
  } else {
    return excluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, fc);
  }
}

/* ----------------------------------------------------------*/
int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
  pNohBTree novaRaiz =
      excluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, pfc);
  if (novaRaiz == NULL) {
    printf(" -->> Erro! Chave informada n o existe na  rvore!!! <<--");
  } else {
    arvore->raiz = novaRaiz;
  }

  return 1;
}

#endif