#ifndef INCLUIR_INFO_INICIO_H
#define INCLUIR_INFO_INICIO_H

void incluirInfoInicio(pDLista pd, void *info){

    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }
    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informacao no campo "info" do novo noh alocado */
    pNovo->info = info;

    // concluir implementação!
}

#endif
