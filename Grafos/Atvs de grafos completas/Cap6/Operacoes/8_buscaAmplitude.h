#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */

void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

  if (grafo == NULL || grafo->listaVertices == NULL) {
        return; // O grafo ou a lista de v�rtices est� vazia
    }

    pDLista visitados = criarLista(); // Lista para armazenar v�rtices visitados
    pDLista fila = criarLista();      // Fila para a busca em largura

    pNoh nohInicial = grafo->listaVertices->primeiro;
    if (nohInicial == NULL) {
        return; // N�o h� v�rtices no grafo
    }

    // Adiciona o primeiro v�rtice na fila e na lista de visitados
    incluirInfo(fila, nohInicial->info);
    incluirInfo(visitados, nohInicial->info);

    while (fila->quantidade > 0) {
        pNoh nohAtual = fila->primeiro;
        pVertice verticeAtual = (pVertice) nohAtual->info;

        // Imprime o v�rtice atual
        fi(verticeAtual);

        // Remove o v�rtice da fila
        fila->primeiro = nohAtual->prox;
        if (fila->quantidade == 1) {
            fila->ultimo = NULL;
        }
        fila->quantidade--;
        free(nohAtual);

        // Adiciona os v�rtices adjacentes n�o visitados na fila
        pNoh nohAdj = verticeAtual->listaAdjacencias->primeiro;
        while (nohAdj != NULL) {
            pVertice verticeAdjacente = (pVertice) nohAdj->info;

            // Verifica se o v�rtice adjacente j� foi visitado
            if (buscarNohInfo(visitados, verticeAdjacente, fc) == NULL) {
                // Adiciona o v�rtice adjacente na fila e na lista de visitados
                incluirInfo(fila, verticeAdjacente);
                incluirInfo(visitados, verticeAdjacente);
            }

            nohAdj = nohAdj->prox;
        }
    }

    // Libera a mem�ria alocada para a fila e a lista de visitados
    destruirLista(fila);
    destruirLista(visitados);
}

#endif
