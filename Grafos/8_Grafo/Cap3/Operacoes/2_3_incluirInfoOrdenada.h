#ifndef INCLUIR_INFO_ORDENADA_H
#define INCLUIR_INFO_ORDENADA_H

void incluirInfoOrdenada(pDLista pd, void *info, FuncaoComparacao pfc){

    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }

    pNoh atual = pd->primeiro;
    pNoh ant   = NULL;
    // encontra a posição na lista onde colocar a nova info
    while(atual != NULL){

       if (pfc(info, atual->info) > 0){
          // achou a posição onde colocar a nova info
          break;
       }

       ant   = atual;
       atual = atual->prox;
    }

    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));
    /* guarda a informacao no campo "info" do novo noh alocado */
    pNovo->info = info;
    /* a lista tem mais um noh */
    pd->quantidade++;

    /* Se o novo noh eh o unico da lista, o descritor
       precisa atualizar tambem o ponteiro para o primeiro noh da lista */

    if(ant == NULL && atual == NULL){
        // a lista está vazia
        //printf("Lista vaziaaa!");
        pd->primeiro = pNovo;
        pd->ultimo   = pNovo;
        pNovo->prox  = NULL;
        return;
    }

    if(ant == NULL){
       // tem que incluir no inicio da lista
        pd->primeiro = pNovo;
        pNovo->prox  = atual;
        return;
    }

    if(atual == NULL){
       // tem que incluir no final da lista
       pd->ultimo   = pNovo;
       ant->prox    = pNovo;
       pNovo->prox  = NULL;
       return;
    }

     if(ant != NULL && atual != NULL){
       // tem que incluir no meio da lista
       ant->prox    = pNovo;
       pNovo->prox  = atual;
       return;
    }
}

#endif
