#ifndef COLORACAO_H
#define COLORACAO_H
// lista de listas
pDLista inserirLista(pDLista lista) {
  pDLista novaLista = criarLista();
  incluirInfo(lista, novaLista);
  return lista;
}

void imprimirColoracao(pDGrafo grafo, pDLista Cores) {
  printf("Coloracao dos Vertices:\n");

  pNoh nohCor = Cores->primeiro;
  int corIndex = 1;

  while (nohCor != NULL) {
    pDLista listaCor = (pDLista)nohCor->info;

    pNoh nohVertice = listaCor->primeiro;
    while (nohVertice != NULL) {
      pVertice vAtual = (pVertice)nohVertice->info;

      printf("Vertice: %d, Cor: %d\n", *((int*)vAtual->info), corIndex);

      nohVertice = nohVertice->prox;
    }

    nohCor = nohCor->prox;
    corIndex++;
  }
}

bool verificaAdjacencia(pDGrafo grafo, pVertice v1, pVertice v2) {
  // v1 destino v2 origem
  pNoh nohAdj = v1->listaAdjacencias->primeiro;
  while (nohAdj != NULL) {
    pVertice vAdj = (pVertice)nohAdj->info;
    if (vAdj == v2) {
      return true;
    }
    nohAdj = nohAdj->prox;
  }
  return false;
}
void coloracao(pDGrafo grafo, int numCores) {
  pDLista Cores = criarLista();

  for (int i = 0; i < numCores; i++) {
    pDLista listaCor = criarLista();
    incluirInfo(Cores, listaCor);
  }

  pNoh nAux = grafo->listaVertices->primeiro;
  while (nAux != NULL) {
    pVertice vAtual = (pVertice)nAux->info;
    bool corAtribuida = false;

    pNoh nListaCor = Cores->primeiro;
    while (nListaCor != NULL && !corAtribuida) {
      pDLista listaCor = (pDLista)nListaCor->info;
      bool podeAtribuirCor = true;

      pNoh nohAdj = vAtual->listaAdjacencias->primeiro;
      while (nohAdj != NULL) {
        pVertice vAdj = (pVertice)nohAdj->info;

        // Verifica se o vizinho já foi colorido
        pNoh nohCor = listaCor->primeiro;
        while (nohCor != NULL) {
          if (nohCor->info == vAdj) {
            podeAtribuirCor = false;
            break;
          }
          nohCor = nohCor->prox;
        }

        if (!podeAtribuirCor) break;

        nohAdj = nohAdj->prox;
      }

      pNoh nohCorGeral = Cores->primeiro;
      while (nohCorGeral != NULL) {
        if (nohCorGeral->info != listaCor) {
          pDLista listaCorGeral = (pDLista)nohCorGeral->info;
          pNoh nohVerticeGeral = listaCorGeral->primeiro;
          while (nohVerticeGeral != NULL) {
            pVertice vVerticeGeral = (pVertice)nohVerticeGeral->info;
            if (verificaAdjacencia(grafo, vAtual, vVerticeGeral)) {
              podeAtribuirCor = false;
              break;
            }
            nohVerticeGeral = nohVerticeGeral->prox;
          }
        }
        if (!podeAtribuirCor) break;

        nohCorGeral = nohCorGeral->prox;
      }

      if (podeAtribuirCor) {
        incluirInfo(listaCor, vAtual);
        corAtribuida = true;
      }

      nListaCor = nListaCor->prox;
    }

    if (!corAtribuida) {
      printf("Erro: Nao foi possivel colorir o grafo com %d cores\n", numCores);
      return;
    }

    nAux = nAux->prox;
  }

  imprimirColoracao(grafo, Cores);
  return;
}

#endif  // COLORACAO_H