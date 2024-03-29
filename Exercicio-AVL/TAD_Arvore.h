#ifndef ARVORE_TAD_H
#define ARVORE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct nohArvore  NohArvore;
typedef NohArvore*        pNohArvore;

/* descritor da arvore */
typedef struct dArvore  DArvore;
typedef DArvore*        pDArvore;

/* tipos referentes aos ponteiros para funcao */
typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDArvore  criarArvore(int);

void       incluirInfo    (pDArvore, void *, FuncaoComparacao);
int        excluirInfo    (pDArvore, void *, FuncaoComparacao);
pNohArvore buscarInfo     (pDArvore, void *, FuncaoComparacao);
int        quantidadeNohs (pDArvore);

/* percursos */
void      emOrdem  (pNohArvore, FuncaoImpressao);
void      preOrdem (pNohArvore, FuncaoImpressao);
void      posOrdem (pNohArvore, FuncaoImpressao);

int       altura          (pDArvore);
int       grau            (pDArvore);
int       nivel           (pDArvore, void *, FuncaoComparacao);
int       quantidadeFolhas(pDArvore);
int       ehFolha         (pDArvore, void *, FuncaoComparacao);
int       arvoreVazia     (pDArvore);

void desenhaArvore(pDArvore, FuncaoImpressao);

//void balancear(pDArvore);
void recalcularFB(pDArvore);

#endif

