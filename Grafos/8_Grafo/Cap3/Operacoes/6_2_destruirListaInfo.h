#ifndef DESTRUIR_LISTA_INFO_H
#define DESTRUIR_LISTA_INFO_H
/* -------------------------------------*/
void destruirListaInfo(pDLista pd, FuncaoLiberacao fl){

   pNoh atual, aux;
   atual = pd->prineiro;

   while (atual !=NULL){

      aux = atual->prox;
      fl(atual->info);
      free(atual);
      atual = aux;
   }

   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

#endif

