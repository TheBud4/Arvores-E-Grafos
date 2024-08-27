#ifndef BUSCAR_INFO_POS_H
#define BUSCAR_INFO_POS_H

/* --------------------------------- */
void* buscarInfoPos(pDLista lista, int pos){

   pNoh atual = lista->primeiro;
   int  cont  = 1;
   while (atual!=NULL){
      if (cont==pos)
        return atual->info;
      atual = atual->prox;
      cont++;
   }
   return NULL;
}

#endif
