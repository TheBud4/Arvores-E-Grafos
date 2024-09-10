#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc){

    // Buscar os vértices de origem e destino
    pVertice verticeOrigem = buscarVertice(grafo, vOrig, fc);
    pVertice verticeDestino = buscarVertice(grafo, vDest, fc);

    // Verificar se ambos os vértices existem
    if (verticeOrigem == NULL || verticeDestino == NULL) {
        // Um dos vértices não existe
        return;
    }

    // Remover a aresta da lista de adjacências do vértice de origem
    excluirInfo(verticeOrigem->listaAdjacencias, verticeDestino, fc);

    // Remover a aresta da lista de adjacências do vértice de destino (se o grafo for não-direcional)
    excluirInfo(verticeDestino->listaAdjacencias, verticeOrigem, fc);
}


#endif
