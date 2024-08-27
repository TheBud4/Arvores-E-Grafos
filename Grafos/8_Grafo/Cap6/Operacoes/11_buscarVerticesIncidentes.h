#ifndef BUSCAR_VERTICES_INCIDENTES_H
#define BUSCAR_VERTICES_INCIDENTES_H

/* --------------------------- */
pDLista buscarVerticesIncidentes(pDGrafo grafo, pVertice vDest, FuncaoComparacao fc){

   pDLista verticesIncidentes = criarLista();

   pNoh atual = grafo->listaVertices->primeiro;
   while (atual != NULL){
      pVertice vAtual = (pVertice) atual->info;
      if (contemInfo(vAtual->listaAdjacencias, vDest, fc) != 0)
          incluirInfo(verticesIncidentes, vAtual);

      atual = atual->prox;
   }

   return verticesIncidentes;
}
#endif
