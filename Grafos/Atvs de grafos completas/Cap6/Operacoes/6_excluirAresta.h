#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc){

    // Buscar os v�rtices de origem e destino
    pVertice verticeOrigem = buscarVertice(grafo, vOrig, fc);
    pVertice verticeDestino = buscarVertice(grafo, vDest, fc);

    // Verificar se ambos os v�rtices existem
    if (verticeOrigem == NULL || verticeDestino == NULL) {
        // Um dos v�rtices n�o existe
        return;
    }

    // Remover a aresta da lista de adjac�ncias do v�rtice de origem
    excluirInfo(verticeOrigem->listaAdjacencias, verticeDestino, fc);

    // Remover a aresta da lista de adjac�ncias do v�rtice de destino (se o grafo for n�o-direcional)
    excluirInfo(verticeDestino->listaAdjacencias, verticeOrigem, fc);
}


#endif
