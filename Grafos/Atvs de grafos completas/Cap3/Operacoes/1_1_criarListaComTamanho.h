#ifndef CRIAR_LISTA_COM_TAMANHO_H
#define CRIAR_LISTA_COM_TAMANHO_H

pDLista criarListaComTamanho(int tam){
    /* aloca memoria para o descritor */
    pDLista pd = malloc(sizeof(DLista));

    /* seta os campos com os valores default */
    pd->quantidade = 0;
    pd->primeiro   = NULL;
    pd->ultimo     = NULL;

    int i;
    for(i=1; i<=tam; i++){
       incluirInfoMeio(pd, NULL, i);
    }

    return pd;
}

#endif
