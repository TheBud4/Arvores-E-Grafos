#ifndef INCLUIR_INFO_BTREE_H
#define INCLUIR_INFO_BTREE_H

//pNohBTree buscarInfoBTreeRecursivo(pNohBTree , void *, FuncaoComparacao);

//---------------------------------
int comparaChaveValor(void *info1, void *info2){
    pChaveValor  p1 = (pChaveValor) info1;
    pChaveValor  p2 = (pChaveValor) info2;
    return *((int*)(p2->chave)) - *((int*)(p1->chave));
}

//---------------------------------
pNohBTree criaNoh(){

    pNohBTree pNovo           = malloc(sizeof(NohBTree));
    pNovo->listaChavesValores = criarLista();
    pNovo->primeiroFilho      = NULL;
    pNovo->pai                = NULL;
    return pNovo;
}

//---------------------------------
ChaveValor* criaChaveValor(void* chave, void* valor, pNohBTree filhoMaior){

    ChaveValor* pcv = malloc(sizeof(struct chaveValor));
    pcv->chave      = chave;
    pcv->valor      = valor;
    pcv->filhoMaior = filhoMaior;
    return pcv;
}

/* --------------------------*/
int ehFolha(pNohBTree raiz){

   if(raiz == NULL)
      return 0;

   if(raiz->primeiroFilho != NULL)
      return 0;

   int i=1;
   while (i <= raiz->listaChavesValores->quantidade){

        pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i);

        if(pcv->filhoMaior != NULL){
           return 0;
        }

        i++;
    }
    // eh folha, retorna 1 [true]
    return 1;
}

/* --------------------------*/
pNohBTree incluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void* chave, void* valor, FuncaoComparacao pfc){

   // caso base 1
   if (raiz == NULL){
       pNohBTree novo = criaNoh();
       pChaveValor pcv = criaChaveValor(chave, valor, NULL);
       incluirInfoOrdenada(novo->listaChavesValores, pcv, comparaChaveValor);
       return novo;
   }

   pNohBTree novaRaiz = raiz;

   // caso base 2 - encontrou a folha que deve receber a nova chave
   if (ehFolha(raiz)){

       // verificar antes se a chave j� est� na folha
       // ??
       int resultado = contemInfo(raiz->listaChavesValores, chave, pfc);
       if(resultado != 0)
          return NULL;

       pChaveValor pcv = criaChaveValor(chave, valor, NULL);
       incluirInfoOrdenada(raiz->listaChavesValores, pcv, comparaChaveValor);
       //return raiz;
   }
   else{
       // caso recursivo

       pChaveValor pcvAtual, pcvAnt=NULL;
       int i=1;
       while(i <= raiz->listaChavesValores->quantidade){
            pcvAnt = pcvAtual;
            pcvAtual = buscarInfoPos(raiz->listaChavesValores, i);

            int r = pfc(pcvAtual, chave);

            if(r == 0)
                return NULL;

            if(r < 0 && i==1){
                  novaRaiz = incluirInfoBTreeRecursivo(raiz->primeiroFilho, ordem, chave, valor, pfc);
                   break;
            }

            if(r < 0 && i > 1 && i < raiz->listaChavesValores->quantidade){
                  novaRaiz = incluirInfoBTreeRecursivo(pcvAnt->filhoMaior, ordem, chave, valor, pfc);
                  break;
            }

            if(i == raiz->listaChavesValores->quantidade){
                   novaRaiz = incluirInfoBTreeRecursivo(pcvAtual->filhoMaior, ordem, chave, valor, pfc);
                     break;
            }
          i++;
       }

   }

   // verifica se a chave foi encontrada na �rvore - novaRaiz == NULL
   if(novaRaiz == NULL)
      return NULL;

   // verifica se a folha tem mais que 2d chaves
   if(raiz->listaChavesValores->quantidade > 2*ordem){
       // precisa particionar o n�h
       pNohBTree novaPagina = criaNoh();

       pDLista d1 = dividirLista(raiz->listaChavesValores, ordem);

       novaPagina->listaChavesValores = d1;

       pChaveValor pcvD1 = excluirInfoPos(d1, 1);
       pcvD1->filhoMaior = novaPagina;

       pNohBTree pai = raiz->pai;
       if(pai == NULL){
           pai = criaNoh();
           pai->primeiroFilho = raiz;
       }

       raiz->pai       = pai;
       novaPagina->pai = pai;

       incluirInfoOrdenada(pai->listaChavesValores, pcvD1, comparaChaveValor);
       return pai;
    }


   if (novaRaiz->pai == NULL)
       return novaRaiz;

   return novaRaiz->pai;
}

/* ----------------------------------------------------------*/
int incluirInfoBTree(pDBTree arvore, void *chave, void *valor, FuncaoComparacao pfc){

    // desenhaArvore(arvore, imprimeInt);
     //printf("\n ---> Incluindo ....: %d [ ", *((int*)chave));

     pNohBTree novaRaiz = incluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, valor, pfc);
     if (novaRaiz == NULL){
        printf(" -->> Erro! Chave informada j� existe na �rvore!!! <<--");
     }
     else{
        arvore->raiz = novaRaiz;
     }

     //printf(" ] \n\n");
     return 1;
}

#endif

