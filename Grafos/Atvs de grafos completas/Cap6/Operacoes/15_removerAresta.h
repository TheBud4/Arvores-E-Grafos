#ifndef REMOVER_ARESTA_H
#define REMOVER_ARESTA_H

/* ----------------------- */
void removerAresta(pVertice origem, pVertice destino) {
    if (origem == NULL || destino == NULL) {
        return;
    }

    pNoh nohAtual = origem->listaAdjacencias->primeiro;
    pNoh nohAnterior = NULL;

    // Percorrer a lista de adjacências da origem para encontrar o destino
    while (nohAtual != NULL) {
        if (nohAtual->info == destino) { // Encontrou o vértice destino
            // Ajustar os ponteiros para remover o nohAtual da lista
            if (nohAnterior == NULL) {
                // Se o nohAtual é o primeiro da lista
                origem->listaAdjacencias->primeiro = nohAtual->prox;
            } else {
                nohAnterior->prox = nohAtual->prox;
            }

            if (nohAtual == origem->listaAdjacencias->ultimo) {
                // Se o nohAtual é o último da lista
                origem->listaAdjacencias->ultimo = nohAnterior;
            }

            // Liberar o nó removido
            free(nohAtual);
            origem->listaAdjacencias->quantidade--;
            return;
        }

        nohAnterior = nohAtual;
        nohAtual = nohAtual->prox;
    }
}

#endif
