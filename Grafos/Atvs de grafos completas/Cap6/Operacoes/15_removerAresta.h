#ifndef REMOVER_ARESTA_H
#define REMOVER_ARESTA_H

/* ----------------------- */
void removerAresta(pVertice origem, pVertice destino) {
    if (origem == NULL || destino == NULL) {
        return;
    }

    pNoh nohAtual = origem->listaAdjacencias->primeiro;
    pNoh nohAnterior = NULL;

    // Percorrer a lista de adjac�ncias da origem para encontrar o destino
    while (nohAtual != NULL) {
        if (nohAtual->info == destino) { // Encontrou o v�rtice destino
            // Ajustar os ponteiros para remover o nohAtual da lista
            if (nohAnterior == NULL) {
                // Se o nohAtual � o primeiro da lista
                origem->listaAdjacencias->primeiro = nohAtual->prox;
            } else {
                nohAnterior->prox = nohAtual->prox;
            }

            if (nohAtual == origem->listaAdjacencias->ultimo) {
                // Se o nohAtual � o �ltimo da lista
                origem->listaAdjacencias->ultimo = nohAnterior;
            }

            // Liberar o n� removido
            free(nohAtual);
            origem->listaAdjacencias->quantidade--;
            return;
        }

        nohAnterior = nohAtual;
        nohAtual = nohAtual->prox;
    }
}

#endif
