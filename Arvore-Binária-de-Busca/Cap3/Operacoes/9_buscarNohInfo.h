#ifndef BUSCAR_NOH_INFO_H
#define BUSCAR_NOH_INFO_H

/* --------------------------------- */
void* buscarNohInfo(pDLista lista, void *info, FuncaoComparacao fc){

   pNoh atual = lista->primeiro;

   while (atual != NULL){
      if (fc(atual->info, info) == 0)
          return atual->info;

      atual = atual->prox;
   }

   return NULL;

}

#endif
