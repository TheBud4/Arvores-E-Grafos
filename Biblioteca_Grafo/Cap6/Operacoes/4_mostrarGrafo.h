#ifndef MOSTRA_GRAFO_H
#define MOSTRA_GRAFO_H

/* --------------------------- */
void mostrarGrafo(pDGrafo grafo, FuncaoImpressao fi){

     if (fi == NULL)
       fi = grafo->fi;

     imprimirLista (grafo->listaVertices, fi);

}
#endif
