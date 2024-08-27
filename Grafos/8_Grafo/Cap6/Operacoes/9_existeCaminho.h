#ifndef EXISTE_CAMINHO_H
#define EXISTE_CAMINHO_H

/* ----------------------------------------------------------------
A estratégia empregada para a verificação de existência do caminho
parte do vértice de destino e procede com a busca pelos vértices
que incidem sobre este, e assim sucessivamente, até o momento
que um dos vértices incidentes seja o vértice de origem.
Resumindo, a busca é feita no sentido do vértice de destino para o
vértice de origem.
-------------------------------------------------------------------*/
int existeCaminhoRecursivo(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc){

   // encontrou o caminho se o vertice de destino coincidir com o de origem
   if (fc(vOrig, vDest)==0){
       return 1; // return true
   }

   // busca todos os vértices que levam a vDestino e
   // dispara uma chamada recursiva para cada um deles
   pDLista verticesIncidentes = buscarVerticesIncidentes(grafo, vDest, fc);

   // não é um caminho possível
   if (verticesIncidentes->quantidade == 0){
      return 0;   // return false
   }

   int cont = 1;
   int flag = 0;
   while (cont <= verticesIncidentes->quantidade){

      pVertice verticeIncidente  = (pVertice) buscarInfoPos(verticesIncidentes, cont);
      cont++;

      if (existeCaminhoRecursivo(grafo, vOrig, verticeIncidente, fc) != 0){
          flag = 1;
          break;
      }
   }

   return flag;
}


/* --------------------------- */
int existeCaminho(pDGrafo grafo, void *idOrig, void *idDest, FuncaoComparacao fc){

   // busca os vértices para a origem e destino
   pVertice vOrigem  = buscarVertice(grafo, idOrig, fc);
   pVertice vDestino = buscarVertice(grafo, idDest, fc);

   if (vOrigem==NULL || vDestino==NULL){
      return 0;
   }
   return existeCaminhoRecursivo(grafo, vOrigem, vDestino, fc);

}
#endif
