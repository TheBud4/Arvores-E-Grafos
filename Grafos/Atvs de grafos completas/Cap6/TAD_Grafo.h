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

void       incluirVertice   (pDGrafo, void *, FuncaoComparacao);
void       incluirAresta    (pDGrafo, void*, void*, FuncaoComparacao);

void       excluirVertice   (pDGrafo, void*, FuncaoComparacao);
void       excluirAresta    (pDGrafo, void*, void*, FuncaoComparacao);

void       removerAresta    (pVertice origem, pVertice destino);

void       mostrarGrafo     (pDGrafo, FuncaoImpressao);

pVertice   buscarVertice           (pDGrafo, void *, FuncaoComparacao);
pDLista    buscarVerticesIncidentes(pDGrafo, pVertice, FuncaoComparacao);

void       buscaProfundidade(pDGrafo, FuncaoComparacao, FuncaoImpressao);
void       buscaAmplitude   (pDGrafo, FuncaoComparacao, FuncaoImpressao);

int        existeCaminho(pDGrafo, void *,  void *, FuncaoComparacao);
pDLista    getCaminho   (pDGrafo, void *,  void *, FuncaoComparacao, FuncaoAlocacao);

int        ehSubGrafo(pDGrafo, pDGrafo, FuncaoComparacao);

// Um grafo � dito conexo se existir pelo menos um caminho entre
// cada par de v�rtices do grafo. Caso contr�rio, o grafo � chamado
// de desconexo.
int        grafoConexo(pDGrafo, FuncaoComparacao);

// Um grafo G � bipartido se seus v�rtices podem ser separados
// em dois conjuntos independentes de tal forma que todas
// arestas do grafo conectam v�rtices de conjuntos distintos.
int        grafoBipartido(pDGrafo, FuncaoComparacao);

int        existeCaminhoHamiltoniano (pDGrafo, FuncaoComparacao);
int        existeCaminhoEuleriano    (pDGrafo, FuncaoComparacao); // pontes de K�nigsberg

// Uma colora��o de um grafo � v�lida se as duas pontas de cada aresta
// t�m cores diferentes.
void        coloracao(pDGrafo,int);

// Um emparelhamento (= matching) num grafo n�o-dirigido G � um
// conjunto M de arestas dotado da seguinte propriedade:
// todo v�rtice de G incide em no m�ximo um elemento de M.
// (Um la�o n�o pode fazer parte de um emparelhamento porque incide
// duas vezes em um mesmo v�rtice.)
// Pode-se dizer que um emparelhamento � um conjunto de arestas duas a duas
// independentes
pDLista emparelhamento(pDGrafo, pDGrafo);

// ----------------------------------------------
// ----------------------------------------------
// ----------------------------------------------

// � o conjunto de todos os v�rtices que t�m algum vizinho na lista de vertices
pDLista    vizinhanca(pDGrafo, pDLista);

// � o conjunto de todas as arestas que t�m uma ponta em um v�rtice da
// lista de vertices
pDLista    corte(pDGrafo, pDLista);

int        isomorfos(pDGrafo, pDGrafo);  // complexidade de ordem fatorial

int        grafoRegular(pDGrafo);

// Um conjunto de v�rtices de um grafo � est�vel, se seus elementos s�o dois a dois
// n�o-adjacentes, ou seja, se nenhuma aresta tem ambas as pontas no conjunto.
pDLista    conjuntosEstaveis(pDGrafo);

// Um conjunto est�vel X � maximal se n�o faz parte de um conjunto est�vel maior
pDLista    conjuntoEstavelMaximal(pDGrafo);
pDLista    conjuntosEstaveisMaximos(pDGrafo);

//Uma clique ou conjunto completo num grafo � qualquer conjunto de v�rtices dois
//a dois adjacentes
pDLista    clique(pDGrafo);

// Uma cobertura de um grafo � qualquer conjunto de v�rtices que contenha
// pelo menos uma das pontas de cada aresta.
pDLista    coberturas(pDGrafo);

#endif

