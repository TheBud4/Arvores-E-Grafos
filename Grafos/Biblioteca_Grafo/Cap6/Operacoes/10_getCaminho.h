#ifndef GET_CAMINHO_H
#define GET_CAMINHO_H

/* --------------------------- */
pDLista getCaminhoRecursivo(pDGrafo grafo, pVertice vOrig, pVertice vDest, pDLista caminhoParcial){

   // encontrou o caminho se o vertice de destino coincidir com o de origem
   if (grafo->fc(vOrig, vDest)==0){
       return caminhoParcial;
   }

   // busca todos os vértices que levam a vDestino e
   // dispara uma chamada recursiva para cada um deles
   pDLista verticesIncidentes = buscarVerticesIncidentes(grafo, vDest, grafo->fc);

   if (verticesIncidentes->quantidade == 0)
      // não é um caminho possível
      return NULL;

   int cont = 1;
   int flag = 0;
   while (cont <= verticesIncidentes->quantidade){

      pVertice verticeIncidente  = (pVertice) buscarInfoPos(verticesIncidentes, cont);
      cont++;

      pDLista caminhoIncrementado = duplicarLista(caminhoParcial, grafo->fa);
      incluirInfo(caminhoIncrementado, verticeIncidente);

      // ***** precisa destruir a lista caminhoParcial *******
      if (getCaminhoRecursivo(grafo, vOrig, verticeIncidente, caminhoIncrementado) != NULL){
          // achou um caminho
          flag = 1;
          break;
      }
   }

   if (flag==0)
    return NULL;
}


/* --------------------------- */
pDLista getCaminho(pDGrafo grafo, void *idOrig, void *idDest){

   // busca os vértices para a origem e destino
   pVertice vOrigem  = buscarVertice(grafo, idOrig, grafo->fc);
   pVertice vDestino = buscarVertice(grafo, idDest, grafo->fc);

   if (vOrigem==NULL || vDestino==NULL){
      return 0;
   }

   pDLista caminhoParcial = criarLista();
   incluirInfo(caminhoParcial, vDestino);
   return getCaminhoRecursivo(grafo, vOrigem, vDestino, caminhoParcial);
}
#endif
