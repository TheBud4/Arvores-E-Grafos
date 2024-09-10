#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
void excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc) {

    pVertice vertice = buscarVertice(grafo, info, fc);

    // Se o v�rtice n�o existir, sair da fun��o
    if (vertice == NULL) {
        return;
    }

    // Remover todas as arestas que partem do v�rtice
    pNoh noh = vertice->listaAdjacencias->primeiro;
    while (noh != NULL) {
        pNoh nohProx = noh->prox; // Salva o pr�ximo n� antes de remover a aresta
        pVertice verticeAdjacente = (pVertice) noh->info;
        removerAresta(vertice, verticeAdjacente); // Remove aresta do v�rtice para o v�rtice adjacente
        noh = nohProx;
    }

    // Remover todas as arestas que chegam ao v�rtice
    pNoh nohVertice = grafo->listaVertices->primeiro;
    while (nohVertice != NULL) {
        pVertice verticeAtual = (pVertice) nohVertice->info;
        removerAresta(verticeAtual, vertice); // Remove aresta do v�rtice atual para o v�rtice a ser exclu�do
        nohVertice = nohVertice->prox;
    }

    // Remover o v�rtice da lista de v�rtices do grafo
    excluirInfo(grafo->listaVertices, vertice, fc);

    // Liberar a mem�ria associada ao v�rtice
    destruirLista(vertice->listaAdjacencias); // A lista de adjac�ncias do v�rtice � liberada
    free(vertice);
}

#endif
