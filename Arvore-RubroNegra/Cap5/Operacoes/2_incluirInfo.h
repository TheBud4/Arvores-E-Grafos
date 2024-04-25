#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H

/* ---------------------------------------------------------------------*/
pNohArvore avo(pNohArvore raiz){
    if (raiz == NULL)
        return NULL;

    if (raiz->pai == NULL)
        return NULL;

    return raiz->pai->pai;
}

/* ---------------------------------------------------------------------*/
pNohArvore tio(pNohArvore raiz){
   if (raiz == NULL || raiz->pai == NULL)
     return NULL;

  // o filho da esquerda do pai da raiz � a pr�pria raiz,
  // ent�o retorna o filho da direita
  if (avo(raiz) != NULL && avo(raiz)->esquerda == raiz->pai)
    return avo(raiz)->direita;

  return avo(raiz)->esquerda;
}

/* ---------------------------------------------------------------------*/
char corTio(pNohArvore raiz){
   pNohArvore tioRaiz = tio(raiz);
   if (tioRaiz == NULL)
       return 'X';

   return tioRaiz->cor;
}

/* ---------------------------------------------------------------------*/
void inverteCor(pNohArvore raiz){
    if (raiz == NULL)
        return;

    if(raiz->cor == RED)
        raiz->cor = BLACK;
    else
        raiz->cor = RED;
}

//----------------------------------
pNohArvore rotacaoDireita(pNohArvore raiz){ // a raiz � o filho

    // se n�o tem pai e av�, n�o rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
        return NULL;

    pNohArvore avoRaiz = avo(raiz);

    // altera a paternidade do filho e do pai
    avoRaiz->pai   = raiz->pai;
    raiz->pai->pai = avoRaiz->pai;

    // ajusta as sub-arvores da raiz
    avoRaiz->esquerda  = raiz->pai->direita;
    raiz->pai->direita = avoRaiz;

    // ajusta as cores
    raiz->pai->cor  = BLACK;
    avoRaiz->cor    = RED;

    return raiz->pai;
}

//----------------------------------
pNohArvore rotacaoEsquerda(pNohArvore raiz){

     // se n�o tem pai e av�, n�o rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
        return NULL;

    pNohArvore avoRaiz = avo(raiz);

    // altera a paternidade do filho e do pai
    raiz->pai->pai = avoRaiz->pai;
    avoRaiz->pai   = raiz->pai;


    // ajusta as sub-arvores da raiz
    avoRaiz->direita    = raiz->pai->esquerda;
    raiz->pai->esquerda = avoRaiz;

    // ajusta as cores
    raiz->pai->cor  = BLACK;
    avoRaiz->cor    = RED;

    return raiz->pai;
}


//----------------------------------
pNohArvore rotacaoDireitaEsquerda(pNohArvore raiz){

    // se n�o tem pai e nem av�, n�o rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
        return NULL;

    pNohArvore avoRaiz = avo(raiz);
    pNohArvore paiRaiz = raiz->pai;

    // altera a paternidade do filho e do pai
    paiRaiz->pai = raiz;
    raiz->pai    = avoRaiz;

    // ajusta as sub-arvores do filho(raiz) e do pai
    paiRaiz->esquerda = raiz->direita;
    raiz->direita     = paiRaiz;

    // rota��o simples a esquerda
    return rotacaoEsquerda(paiRaiz);


}
//----------------------------------
pNohArvore rotacaoEsquerdaDireita(pNohArvore raiz){

  // se n�o tem pai e nem av�, n�o rotaciona
    if(raiz == NULL || raiz->pai == NULL || avo(raiz) == NULL)
       return NULL;

    pNohArvore avoRaiz = avo(raiz);
    pNohArvore paiRaiz = raiz->pai;

    // altera a paternidade do filho e do pai
    paiRaiz->pai = raiz;
    raiz->pai    = avoRaiz;

    // ajusta as sub-arvores do filho(raiz) e do pai
    paiRaiz->direita = raiz->esquerda;
    raiz->esquerda   = paiRaiz;

    // rota��o simples a direita
    return rotacaoDireita(paiRaiz);
}


/* ---------------------------------------------------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    // caso base
    if (raiz == NULL){
       raiz = malloc(sizeof(NohArvore));
       raiz->info     = info;
       raiz->esquerda = NULL;
       raiz->direita  = NULL;
       raiz->cor      = RED;
       return raiz;
    }
    else{
       pNohArvore filho;
       /* caso recursivo */
       if (pfc(info, raiz->info) >= 0){
           filho = incluirInfoRecursivo(raiz->esquerda, info, pfc);
           if (filho->direita == raiz){
               // houve rota��o a direita, n�o precisa alterar o filho esquerda,
               // somente ajusta a raiz para apontar para o filho
               raiz = filho;
           } else {
               filho->pai     = raiz;
               raiz->esquerda = filho;
           }

        }
        else {
           filho = incluirInfoRecursivo(raiz->direita, info, pfc);
           if (filho->esquerda == raiz){
               // houve rota��o a esquerda, n�o precisa alterar o filho esquerda,
               // somente ajusta a raiz para apontar para o filho
               raiz = filho;
           } else {
               filho->pai    = raiz;
               raiz->direita = filho;
           }
        }

        if (raiz->pai == NULL){
            // � a raiz da �rvore, tem que ser BLACK
            raiz->cor = BLACK;
            return raiz;
        }

        // verifica a cor do pai
        if (raiz->cor == BLACK ||
            (raiz->cor == RED && filho->cor == BLACK)){
            // n�o precisa fazer nada, n�o tem como violar alguma das regras
             return raiz;
        }

         // ----------------------------------------------
        // caso 1: verifica se ambos o pai e o tio sao RED,
        //         muda a cor de ambos para BLACK e a cor do
        //         av� para RED
        // ----------------------------------------------
        if (raiz->cor == RED && corTio(filho) == RED){

             raiz->cor       = BLACK;
             tio(filho)->cor = BLACK;
             if (avo(filho) != NULL){
                 avo(filho)->cor = RED;
             }

             return raiz;
          }

          // ----------------------------------------------
          // Caso 2: pai e tio com cores diferentes
                // S�o 4 possibilidades:
          if (raiz->cor == RED && corTio(filho) != RED){

              pNohArvore novaRaiz;

              if (raiz->esquerda == filho && raiz->pai->esquerda == raiz) {
                  // caso 2.1 - Left-Left
                  novaRaiz = rotacaoDireita(filho);

              } else if (raiz->direita == filho && raiz->pai->esquerda == raiz){
                        // caso 2.2 - Left-Right
                        novaRaiz = rotacaoEsquerdaDireita(filho);

              } else if (raiz->direita == filho && raiz->pai->direita == raiz){
                        // caso 2.3 - Right-Right
                        novaRaiz = rotacaoEsquerda(filho);

              } else if (raiz->esquerda == filho && raiz->pai->direita == raiz){
                        // caso 2.4 - Left-Right
                        novaRaiz = rotacaoDireitaEsquerda(filho);
              }
              return novaRaiz;
            }
    }
    return raiz;
}

/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("\n ----------- Incluindo info: %d ---\n", *((int*)info));
    arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;

    printf("\n -----------------------------------------");
    char path[255] = {};
    desenhaArvore(arvore, imprimeInt);
    printf("\n ----------------------------------------- \n");
}

#endif

