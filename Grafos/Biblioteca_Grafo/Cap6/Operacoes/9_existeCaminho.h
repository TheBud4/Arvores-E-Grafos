#ifndef EXISTE_CAMINHO_H
#define EXISTE_CAMINHO_H

/* ----------------------------------------------------------------
A estrat�gia empregada para a verifica��o de exist�ncia do caminho
parte do v�rtice de destino e procede com a busca pelos v�rtices
que incidem sobre este, e assim sucessivamente, at� o momento
que um dos v�rtices incidentes seja o v�rtice de origem.
Resumindo, a busca � feita no sentido do v�rtice de destino para o
v�rtice de origem.
-------------------------------------------------------------------*/
int existeCaminhoRecursivo(pDGrafo grafo, pVertice vOrig, pVertice vDest){

   // encontrou o caminho se o vertice de destino coincidir com o de origem
   if (grafo->fc(vOrig, vDest)==0){
       return 1;
   }

   // busca todos os v�rtices que levam a vDestino e
   // dispara uma chamada recursiva para cada um deles
   pDLista verticesIncidentes = buscarVerticesIncidentes(grafo, vDest, grafo->fc);

   // n�o � um caminho poss�vel
   if (verticesIncidentes->quantidade == 0){
      return 0;
   }

   int cont = 1;
   int flag = 0;
   while (cont <= verticesIncidentes->quantidade){

      pVertice verticeIncidente  = (pVertice) buscarInfoPos(verticesIncidentes, cont);
      cont++;

      if (existeCaminhoRecursivo(grafo, vOrig, verticeIncidente) != 0){
          flag = 1;
          break;
      }
   }

   return flag;
}


/* --------------------------- */
int existeCaminho(pDGrafo grafo, void *idOrig, void *idDest){

   // busca os v�rtices para a origem e destino
   pVertice vOrigem  = buscarVertice(grafo, idOrig, grafo->fc);
   pVertice vDestino = buscarVertice(grafo, idDest, grafo->fc);

   if (vOrigem==NULL || vDestino==NULL){
      return 0;
   }
   return existeCaminhoRecursivo(grafo, vOrigem, vDestino);

}
#endif
