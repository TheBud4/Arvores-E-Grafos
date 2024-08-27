#ifndef INCLUIR_VERTICE_H
#define INCLUIR_VERTICE_H


/* ----------------------- */
void incluirVertice(pDGrafo grafo, void *info, FuncaoComparacao fc){


   if (buscarVertice(grafo, info, fc) == NULL){

      pVertice vertice = malloc(sizeof(Vertice));
      vertice->info = info;
      vertice->grau = 0;
      /* todo vertice terá uma lista de adjacencia*/
      vertice->listaAdjacencias = criarLista();

      /* adiciona o novo vertice na lista de vertices
         do grafo */
       incluirInfo(grafo->listaVertices, vertice);
   }
}

#endif
