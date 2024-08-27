#ifndef BTREE_TAD_H
#define BTREE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore B */
typedef struct chaveValor ChaveValor;
typedef ChaveValor*       pChaveValor;

/* estrutura do noh da arvore B */
typedef struct nohBTree NohBTree;
typedef NohBTree*       pNohBTree;

/* descritor da arvore B */
typedef struct dBTree  DBTree;
typedef DBTree*       pDBTree;

/* tipos referentes aos ponteiros para funcao */
typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDBTree  criarBTree(int);

int    incluirInfoBTree (pDBTree, void*, void*, FuncaoComparacao);
int    excluirInfoBTree (pDBTree, void*, FuncaoComparacao);
void*  buscarInfoBTree  (pDBTree, void*, FuncaoComparacao);

void desenhaArvore(pDBTree, FuncaoImpressao);
#endif

