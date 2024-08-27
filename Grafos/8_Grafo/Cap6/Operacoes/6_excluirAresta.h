#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc){

   if (fc == NULL)
       fc = grafo->fc;

}

#endif
