#ifndef BIPARTIDO_H_INCLUDED
#define BIPARTIDO_H_INCLUDED

int acharBi(pDGrafo grafo, FuncaoComparacao pfc, FuncaoImpressao pfi){

    pDLista todosVertices = grafo->listaVertices;
    pNoh aux = todosVertices->primeiro;
    pVertice atual = aux->info;

    pDLista direita  = criarLista();
    pDLista esquerda = criarLista();

    pNoh aux2;
    pVertice atual2;
    for(int i=0; i<todosVertices->quantidade; i++){

        if(contemInfo(direita, atual->info, pfc)==0 && contemInfo(esquerda, atual->info, pfc)==0){

            //n tem nem na direita nem na esquerda
            incluirInfo(esquerda, atual->info);
            aux2 = atual->listaAdjacencias->primeiro;
            atual2 = aux2->info;
            for(int j=0; j<atual->listaAdjacencias->quantidade; j++){

                if(contemInfo(esquerda, atual2->info, pfc)!=0){
                    return 0;
                }
                if(contemInfo(direita, atual2->info, pfc)==0){
                    incluirInfo(direita, atual2->info);
                }
                if(aux2->prox != NULL){
                    aux2 = aux2->prox;
                    atual2 = aux2->info;
                }
            }
        }
        if(aux->prox != NULL){
            aux = aux->prox;
            atual = aux->info;
        }
    }
    //lista feitas
    //para saber se e bipartido agora veremos a lista da direita
    //se algum integrante da lista da direita tiver um filho que tbm esta na lista da direita ent n e bipartido: return 0
    //se nao return 1;

    //liberar para simplificar

    pNoh     infoDireira = direita->primeiro;
    pNoh     aux3        = grafo->listaVertices->primeiro;
    pVertice atualv2     = aux3->info;
    pDLista  adjacentes  = criarLista();

    pNoh     nohAdjacentes;
    pVertice verticeAdjacente;

    for(int j=0; j<direita->quantidade+2; j++){

        if(infoDireira->info == atualv2->info){

            adjacentes       = atualv2->listaAdjacencias;
            nohAdjacentes    = adjacentes->primeiro;
            verticeAdjacente = nohAdjacentes->info;
            for(int i=0; i<adjacentes->quantidade; i++){

                if(contemInfo(direita, verticeAdjacente->info, pfc)!=0){
                    return 0;
                }
                if(nohAdjacentes->prox != NULL){
                    nohAdjacentes = nohAdjacentes->prox;
                    verticeAdjacente = nohAdjacentes->info;
                }
            }
            if(infoDireira->prox != NULL){
                infoDireira = infoDireira->prox;
            }
        }
        if(aux3->prox != NULL){
            aux3  = aux3->prox;
            atualv2 = aux3->info;
        }

    }
    return 1;

}

#endif // BIPARTIDO_H_INCLUDED
