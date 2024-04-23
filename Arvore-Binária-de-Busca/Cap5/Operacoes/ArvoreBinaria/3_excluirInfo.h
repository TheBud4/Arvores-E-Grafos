#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

pNohArvore BuscarPaiFolhaMaisEsquerda(pNohArvore raiz){
        
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->esquerda == NULL){
        return NULL;
    }
    if(raiz->esquerda->esquerda == NULL){
        return raiz;
    }

    return BuscarPaiFolhaMaisEsquerda(raiz->esquerda);
}

/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    pNohArvore novaRaiz;
    pNohArvore auxEsq;
    pNohArvore auxDir;
    pNohArvore pai;
    
    if(raiz == NULL){
        return NULL;
    }

    if (pfc(raiz->info, info) == 0) {
       
       auxDir = raiz->direita;
        auxEsq = raiz->esquerda;
        free(raiz);

      //caso 1
      if(auxDir == NULL && auxEsq == NULL){
        return NULL;
      }
      //caso 2
      if(auxDir == NULL){
         novaRaiz = auxEsq;
        
        return novaRaiz;
      }
      if(auxEsq == NULL){
         novaRaiz = auxDir;
        
        return novaRaiz;
      }
      //caso 3
        pai = BuscarPaiFolhaMaisEsquerda(auxDir);
        if( pai == NULL){
            novaRaiz = auxDir;
        }else{
            novaRaiz = pai->esquerda;
        }
        pai->esquerda = pai->esquerda->direita;
        novaRaiz->esquerda = auxEsq;
        novaRaiz->direita = auxDir;
        return novaRaiz;
    }

    if(pfc(raiz->info, info) < 0 ){
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
        
    }else{
     raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info,pfc);
}

#endif
