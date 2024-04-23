#ifndef INCLUIR_INFO_H
#define INCLUIR_INFO_H

void incluirInfo(pDLista pd, void *info){

    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }
    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informacao no campo "info" do novo noh alocado */
    pNovo->info = info;
    /* como a nova info ficar na ultima posicao da lista,
       nao tera proximo */
    pNovo->prox = NULL;

    /* salva a referencia ao ultimo noh da lista antes de atualizar o descritor */
    pNoh auxUltimo  = pd->ultimo;

    /* o novo noh sera identificado como ultimo da lista pelo descritor */
    pd->ultimo      = pNovo;
    /* a lista tem mais um noh */
    pd->quantidade++;

    /* Se o novo noh eh o unico da lista, o descritor
       precisa atualizar tambem o ponteiro para o primeiro noh da lista */
    if (pd->primeiro == NULL)
        pd->primeiro = pNovo;
    else{
        /* se nao for o unico da lista, coloca-o no final da lista */
        auxUltimo->prox = pNovo;
    }
}

#endif
