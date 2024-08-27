#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   if (fc == NULL)
       fc = grafo->fc;

   if (fi == NULL)
       fi = grafo->fi;

}
#endif
