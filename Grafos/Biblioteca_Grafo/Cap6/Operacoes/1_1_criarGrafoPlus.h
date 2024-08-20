#ifndef CRIAR_GRAFO_PLUS_H
#define CRIAR_GRAFO_PLUS_H

/* --------------------------- */
pDGrafo criarGrafoPlus(FuncaoComparacao fc, FuncaoImpressao fi, FuncaoAlocacao fa){

  pDGrafo grafo = malloc(sizeof(DGrafo));
  grafo->listaVertices = criarLista();
  grafo->fc = fc;
  grafo->fi = fi;
  grafo->fa = fa;
  return grafo;

}

#endif
