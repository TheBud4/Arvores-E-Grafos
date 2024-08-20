#ifndef BUSCA_PROFUNDIDADE_H
#define BUSCA_PROFUNDIDADE_H

/* --------------------------- */
void buscaEmProfundidade(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   if (fc == NULL)
       fc = grafo->fc;

   if (fi == NULL)
       fi = grafo->fi;

   pDPilha verticesPendentes;
   pDLista verticesVisitados;

   verticesPendentes = criarPilha();
   verticesVisitados = criarLista();

   /* empilha o primeiro v�rtice do grafo (ou seja, o primeiro v�rtice da lista) */
   empilharInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

   /* processa todos os v�rtices da pilha */
   while(pilhaVazia(verticesPendentes)!=0)
   {
       pVertice vAtual = desempilharInfo(verticesPendentes);

       /* visita o vertice se ainda n�o foi visitado */
       if (contemInfo(verticesVisitados, vAtual, fc) == 0){
          fi(vAtual);
          incluirInfo(verticesVisitados, vAtual);
       }

       /* empilha todas as adjac�ncias do v�rtice atual que n�o foram visitadas */
       pNoh atual = vAtual->listaAdjacencias->primeiro;
       while(atual != NULL){
          pVertice vAux = (pVertice) atual->info;
          if (contemInfo(verticesVisitados, vAux, fc) == 0){
             empilharInfo(verticesPendentes, atual->info);
          }
          atual = atual->prox;
       }
   }
}

#endif
