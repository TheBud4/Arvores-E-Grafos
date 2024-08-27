#ifndef BUSCAR_VERTICE_H
#define BUSCAR_VERTICE_H

/* --------------------------- */
/* ----------------------- */
pVertice buscarVertice(pDGrafo grafo, void *idVertice, FuncaoComparacao fc){

    Vertice v;
    v.info = idVertice;
    return buscarNohInfo(grafo->listaVertices, &v, fc);
};

#endif
