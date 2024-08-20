#ifndef INCLUIR_ARESTA_H
#define INCLUIR_ARESTA_H

/* --------------------------- */
void incluirAresta (pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc){

     if (fc == NULL)
         fc = grafo->fc;

     pVertice vOrigem  = buscarVertice(grafo, vOrig, fc);
     pVertice vDestino = buscarVertice(grafo, vDest, fc);

     if (vOrigem == NULL || vDestino == NULL){
        printf("Um dos v�rtices n�o existe! \n");
        return;
     }
     incluirInfo(vOrigem->listaAdjacencias, vDestino);
}

#endif
