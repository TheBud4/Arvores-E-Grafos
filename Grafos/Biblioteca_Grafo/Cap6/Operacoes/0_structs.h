#ifndef STRUCTS_GRAFO_H
#define STRUCTS_GRAFO_H

struct dGrafo{
   pDLista listaVertices;
   FuncaoComparacao fc;
   FuncaoImpressao  fi;
   FuncaoAlocacao   fa;
};

struct vertice{
   void          *info;
   int            grau; /* o grau pode ser obtido do descritor da lista de adjacencias */
   pDLista        listaAdjacencias;
};

#endif
