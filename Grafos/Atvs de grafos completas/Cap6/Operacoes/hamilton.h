#ifndef HAMILTON_H_INCLUDED
#define HAMILTON_H_INCLUDED
#include "../Grafo.h"
#include <math.h>
int canAddToPath(pVertice v, pDLista path, int pos, FuncaoComparacao fc){

    // Verifica se o vértice já está no caminho
    if (contemInfo(path, v, fc) > 0){
        return 0;
    }

    // Se não é o primeiro vértice, verifica se há uma aresta com o vértice anterior
    if (pos > 0)
    {
        pVertice lastVertex = buscarInfoPos(path, pos); // Corrigido: Posição ajustada
        if (!contemInfo(lastVertex->listaAdjacencias, v, fc)){
            return 0;
        }
    }
    return 1;
}

int hamiltonianPathUtil(pDGrafo grafo, pDLista path, int pos, FuncaoComparacao fc){

    if (pos == grafo->listaVertices->quantidade){
        return 1;
    }

    // Tenta diferentes vértices como próximo candidato no caminho
    pNoh atual = grafo->listaVertices->primeiro;
    while (atual != NULL)
    {
        pVertice v = atual->info;

        if (canAddToPath(v, path, pos, fc))
        {
            incluirInfo(path, v);

            if (hamiltonianPathUtil(grafo, path, pos + 1, fc) == 1)
                return 1;

            // Se adicionar v não leva a uma solução, remove-o
            excluirInfoPos(path, pos); // Corrigido: Remover na posição correta
        }

        atual = atual->prox;
    }
    return 0;
}

int ehHamilton(pDGrafo grafo, FuncaoComparacao fc){
    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0){
        printf("Grafo vazio ou invalido\n");
        return 0;
    }

    if (grafo->listaVertices->quantidade == 1){
        return 1; // Grafo com um vértice é hamiltoniano
    }

    pDLista path = criarLista();
    pNoh primeiroVertice = grafo->listaVertices->primeiro;
    incluirInfo(path, primeiroVertice->info);

    int result = hamiltonianPathUtil(grafo, path, 1, fc);
    destruirLista(path);

    return result;
}

#endif // HAMILTON_H_INCLUDED
