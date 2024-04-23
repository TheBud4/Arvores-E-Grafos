#ifndef EXCLUIR_INFO_POS_H
#define EXCLUIR_INFO_POS_H

void* excluirInfoPos(pDLista pd, int pos){

    int cont=1;

    pNoh atual, ant;

    atual = pd->primeiro;
    ant   = NULL;

    /* encontra o noh correspondente a posicao informada */
    while(atual != NULL && cont < pos){
       ant   = atual;
       atual = atual->prox;
       cont++;
    }

    /* verifica se a info existe na lista */
    if (atual != NULL){
        /* eh o primeiro da lista */
        if (atual == pd->primeiro)
            pd->primeiro = atual->prox;
        else
        /* eh o ultimo da lista */
        if (atual == pd->ultimo){
            pd->ultimo = ant;
            ant->prox  = NULL;
        } else
             /* estah no meio da lista */
             ant->prox = atual->prox;

        /* se tinha somente uma info na lista, zera os campos primeiro e ultimo */
        if (pd->quantidade == 1){
            pd->primeiro = NULL;
            pd->ultimo   = NULL;
        }

        pd->quantidade--;
        void * auxInfo = atual->info;
        free(atual);
        return auxInfo;
    }

    return NULL;
}

#endif // EXCLUIR_INFO_POS_H
