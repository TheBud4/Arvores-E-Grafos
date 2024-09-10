#ifndef EULERIANO_H_INCLUDED
#define EULERIANO_H_INCLUDED

char todosPar(pDGrafo grafo)
{
    //1 condiçao: todos par
    pDLista vertices = grafo->listaVertices;
    pNoh atual = vertices->primeiro;

    while (atual != NULL)
    {
        pVertice v = atual->info;
        pDLista adjacents = v->listaAdjacencias;

        if (adjacents->quantidade % 2 != 0)
        {
            return 'b'; // alguem n par
        }

        atual = atual->prox;
    }

    return 'a'; // Tudo par
}
//-----------------------------------------------------------------------
char ehConexo(pDGrafo grafo, FuncaoComparacao pfc, FuncaoImpressao pfi){
    pDLista verticesLigados = buscaEmProfundidade(grafo, pfc, pfi);
    if(verticesLigados->quantidade == grafo->listaVertices->quantidade)
        return 'a';

    return 'b';
}
//-----------------------------------------------------------------------
int ehEuleriano(pDGrafo grafo, FuncaoComparacao pfc, FuncaoImpressao pfi){
    char ret = todosPar(grafo);
    if(ret == 'b')
        return 0;//n cumpriu a primeira condicao

    ret = ehConexo(grafo, pfc, pfi);
    if(ret == 'b')
        return 0;//n cumpriu a segunda condicao

    return 1;

}
#endif // EULERIANO_H_INCLUDED
