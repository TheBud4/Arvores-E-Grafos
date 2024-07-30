#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

pNohArvore obterIrmao(pNohArvore noh){
    if(noh->pai == NULL){
        return NULL;
    }
    if(noh == noh->pai->esquerda)
        return noh->pai->direita;

    return noh->pai->esquerda;   
}
/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc){

    if(raiz == NULL){
        return NULL;
    }

    int comparacao = fc(info, raiz->info);
    if (comparacao > 0) {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);

    } else if (comparacao < 0) {
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);
    } else {
        pNohArvore temp;
    //caso 1 e 2 - Se o noh a ser deletado só tem um filho
    //caso 2.1 - Se ou direita ou esquerda for vermelho nós marcamos o filho que foi substituido de preto   
        if (raiz->esquerda == NULL) {
         temp = raiz->direita;
        free(raiz);
        return temp;
        } else if (raiz->direita == NULL) {
         temp = raiz->esquerda;
        free(raiz);
        return temp;
        }

    //caso simples 
        if(raiz->cor == RED || temp->cor == RED){
            temp->cor = BLACK;
        }
        if(raiz->cor == BLACK && temp->cor == BLACK){
            temp->cor = DOUBLE_BLACK;
         }
         

    //Caso 3.2 
        if(temp->cor = DOUBLE_BLACK && temp->pai != NULL){
            //  Caso A
            pNohArvore pai = temp->pai;
            pNohArvore irmao = obterIrmao(temp);
            if(irmao->cor == BLACK && irmao->esquerda->cor == RED || irmao->direita->cor == RED){
                if(irmao == pai->esquerda){
                    // Caso I 
                    if(irmao->esquerda != NULL && irmao->esquerda == RED){
                        rotacaoDireita(temp);
                        irmao->esquerda->cor = BLACK;       
                }
                // Caso II
                else if(irmao->direita != NULL && irmao->direita == RED){
                    rotacaoEsquerdaDireita(temp);
                    irmao->direita->cor = BLACK;
                }
            }else if(irmao == pai->direita){
                // Caso III
                if(irmao->direita != NULL && irmao->direita == RED){
                        rotacaoEsquerda(temp);
                        irmao->direita->cor = BLACK;       
                }
                // Caso IV
                else if(irmao->esquerda != NULL && irmao->esquerda == RED){
                    rotacaoDireitaEsquerda(temp);
                    irmao->esquerda->cor = BLACK;
                }
            }

                


        }
        // Caso B
        if(irmao->cor == BLACK && irmao->esquerda->cor == BLACK || irmao->direita->cor == BLACK){
            irmao->cor = RED;
            if(irmao->pai->cor == BLACK){
                irmao->pai->cor = DOUBLE_BLACK;
            }else if(irmao->pai->cor == RED){
                irmao->pai->cor = BLACK;
            }
        }
        // Caso C
        if(irmao->cor == RED){
            // Caso I
            if(irmao = pai->esquerda){
                rotacaoDireita(pai);
            }
            // Caso II
            else if(irmao = pai->direita){
                rotacaoEsquerda(pai);
            }
        }
            // Caso 3.3
            if(temp->pai == NULL){
                temp->cor = BLACK;
                return temp;
            }
    
        }
    }
    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

    printf("Excluindo...\n");
 
    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 0;
}

#endif
