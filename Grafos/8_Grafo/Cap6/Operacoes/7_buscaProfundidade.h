#ifndef BUSCA_PROFUNDIDADE_H
#define BUSCA_PROFUNDIDADE_H

/* --------------------------- */
void buscaEmProfundidade(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   pDPilha verticesPendentes;
   pDLista verticesVisitados;

   verticesPendentes = criarPilha();
   verticesVisitados = criarLista();

   /* empilha o primeiro vértice do grafo (ou seja, o primeiro vértice da lista) */
   empilharInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

   /* processa todos os vértices da pilha */
   while(pilhaVazia(verticesPendentes)!=0)
   {
       pVertice vAtual = desempilharInfo(verticesPendentes);

       /* visita o vertice se ainda não foi visitado */
       if (contemInfo(verticesVisitados, vAtual, fc) == 0){
          fi(vAtual);
          incluirInfo(verticesVisitados, vAtual);
       }

       /* empilha todas as adjacências do vértice atual que não foram visitadas */
       pNoh atual = vAtual->listaAdjacencias->primeiro;
       while(atual != NULL){
          if (contemInfo(verticesVisitados, atual->info, fc) == 0){
             empilharInfo(verticesPendentes, atual->info);
          }
          atual = atual->prox;
       }
   }
}

#endif
