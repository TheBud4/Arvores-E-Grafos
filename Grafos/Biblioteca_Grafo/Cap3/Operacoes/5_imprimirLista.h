#ifndef IMPRIMIR_LISTA_H
#define IMPRIMIR_LISTA_H

void imprimirLista(pDLista pd, FuncaoImpressao pfi){

    pNoh aux;
    aux = pd->primeiro;

    while(aux != NULL){
       /*printf("%d", *(((int *)aux->info)));*/
       pfi(aux->info);

       aux = aux->prox;
    }
}

#endif
