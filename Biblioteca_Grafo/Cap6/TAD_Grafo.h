#ifndef GRAFO_TAD_H
#define GRAFO_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct vertice  Vertice;
typedef Vertice*       pVertice;

typedef struct dGrafo  DGrafo;
typedef DGrafo*       pDGrafo;

/* tipos referentes aos ponteiros para funcao */
typedef int   (*FuncaoComparacao)(void*, void*);
typedef void  (*FuncaoImpressao) (void*);
typedef void* (*FuncaoAlocacao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDGrafo    criarGrafo();
pDGrafo    criarGrafoPlus(FuncaoComparacao, FuncaoImpressao, FuncaoAlocacao);

void       incluirVertice   (pDGrafo, void *, FuncaoComparacao);
//void     incluirVertice   (pDGrafo, void *);
void       incluirAresta    (pDGrafo, void*, void*, FuncaoComparacao);
//void     incluirAresta    (pDGrafo, void*, void*);

void       excluirVertice   (pDGrafo, void*, FuncaoComparacao);
//void     excluirVertice   (pDGrafo, void*);
void       excluirAresta    (pDGrafo, void*, void*, FuncaoComparacao);
//void     excluirAresta    (pDGrafo, void*, void*);

void       mostrarGrafo     (pDGrafo, FuncaoImpressao);
//void     mostrarGrafo     (pDGrafo);

pVertice   buscarVertice           (pDGrafo, void *, FuncaoComparacao);
//pVertice buscarVertice           (pDGrafo, void *);
pDLista    buscarVerticesIncidentes(pDGrafo, pVertice, FuncaoComparacao);
//pDLista  buscarVerticesIncidentes(pDGrafo, pVertice);

void       buscaProfundidade(pDGrafo, FuncaoComparacao, FuncaoImpressao);
//void     buscaProfundidade(pDGrafo);
void       buscaAmplitude   (pDGrafo, FuncaoComparacao, FuncaoImpressao);
//void     buscaAmplitude   (pDGrafo);

int        existeCaminho(pDGrafo, void *,  void *);
pDLista    getCaminho   (pDGrafo, void *,  void *);

int        existeCaminhoHamiltoniano (pDGrafo);
int        existeCaminhoEuleriano    (pDGrafo); // pontes de Königsberg

int        ehSubGrafo(pDGrafo, pDGrafo);

#endif

