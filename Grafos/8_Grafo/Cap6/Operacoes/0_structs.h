#ifndef STRUCTS_GRAFO_H
#define STRUCTS_GRAFO_H

struct dGrafo{

   pDLista listaVertices;

};

struct vertice{
   void          *info; // id
   int            grau; /* o grau pode ser obtido do descritor da lista de adjacencias */
   pDLista        listaAdjacencias;
};

#endif
