#ifndef EXCLUIRINFO_BTREE_H
#define EXCLUIRINFO_BTREE_H

/* --------------------------*/
pNohBTree excluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, FuncaoComparacao fc){
   if(raiz == NULL){
      return NULL;
   }
   int comparacao = fc(raiz,chave);

   if(comparacao > 0){
      
   }

   return NULL;
}

/* ----------------------------------------------------------*/
int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc){

     pNohBTree novaRaiz = excluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, pfc);
     if (novaRaiz == NULL){
        printf(" -->> Erro! Chave informada n�o existe na �rvore!!! <<--");
     }
     else{
        arvore->raiz = novaRaiz;
     }

    return 1;

}

#endif
