#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
void excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc) {

    pVertice vertice = buscarVertice(grafo, info, fc);

    // Se o vértice não existir, sair da função
    if (vertice == NULL) {
        return;
    }

    // Remover todas as arestas que partem do vértice
    pNoh noh = vertice->listaAdjacencias->primeiro;
    while (noh != NULL) {
        pNoh nohProx = noh->prox; // Salva o próximo nó antes de remover a aresta
        pVertice verticeAdjacente = (pVertice) noh->info;
        removerAresta(vertice, verticeAdjacente); // Remove aresta do vértice para o vértice adjacente
        noh = nohProx;
    }

    // Remover todas as arestas que chegam ao vértice
    pNoh nohVertice = grafo->listaVertices->primeiro;
    while (nohVertice != NULL) {
        pVertice verticeAtual = (pVertice) nohVertice->info;
        removerAresta(verticeAtual, vertice); // Remove aresta do vértice atual para o vértice a ser excluído
        nohVertice = nohVertice->prox;
    }

    // Remover o vértice da lista de vértices do grafo
    excluirInfo(grafo->listaVertices, vertice, fc);

    // Liberar a memória associada ao vértice
    destruirLista(vertice->listaAdjacencias); // A lista de adjacências do vértice é liberada
    free(vertice);
}

#endif
