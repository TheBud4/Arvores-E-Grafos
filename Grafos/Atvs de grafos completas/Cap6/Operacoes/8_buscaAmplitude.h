#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */

void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

  if (grafo == NULL || grafo->listaVertices == NULL) {
        return; // O grafo ou a lista de vértices está vazia
    }

    pDLista visitados = criarLista(); // Lista para armazenar vértices visitados
    pDLista fila = criarLista();      // Fila para a busca em largura

    pNoh nohInicial = grafo->listaVertices->primeiro;
    if (nohInicial == NULL) {
        return; // Não há vértices no grafo
    }

    // Adiciona o primeiro vértice na fila e na lista de visitados
    incluirInfo(fila, nohInicial->info);
    incluirInfo(visitados, nohInicial->info);

    while (fila->quantidade > 0) {
        pNoh nohAtual = fila->primeiro;
        pVertice verticeAtual = (pVertice) nohAtual->info;

        // Imprime o vértice atual
        fi(verticeAtual);

        // Remove o vértice da fila
        fila->primeiro = nohAtual->prox;
        if (fila->quantidade == 1) {
            fila->ultimo = NULL;
        }
        fila->quantidade--;
        free(nohAtual);

        // Adiciona os vértices adjacentes não visitados na fila
        pNoh nohAdj = verticeAtual->listaAdjacencias->primeiro;
        while (nohAdj != NULL) {
            pVertice verticeAdjacente = (pVertice) nohAdj->info;

            // Verifica se o vértice adjacente já foi visitado
            if (buscarNohInfo(visitados, verticeAdjacente, fc) == NULL) {
                // Adiciona o vértice adjacente na fila e na lista de visitados
                incluirInfo(fila, verticeAdjacente);
                incluirInfo(visitados, verticeAdjacente);
            }

            nohAdj = nohAdj->prox;
        }
    }

    // Libera a memória alocada para a fila e a lista de visitados
    destruirLista(fila);
    destruirLista(visitados);
}

#endif
