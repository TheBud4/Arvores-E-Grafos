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

void       mostrarGrafo     (pDGrafo, FuncaoImpressao);

pVertice   buscarVertice           (pDGrafo, void *, FuncaoComparacao);
pDLista    buscarVerticesIncidentes(pDGrafo, pVertice, FuncaoComparacao);

void       buscaProfundidade(pDGrafo, FuncaoComparacao, FuncaoImpressao);
void       buscaAmplitude   (pDGrafo, FuncaoComparacao, FuncaoImpressao);

int        existeCaminho(pDGrafo, void *,  void *, FuncaoComparacao);
pDLista    getCaminho   (pDGrafo, void *,  void *, FuncaoComparacao, FuncaoAlocacao);

int        ehSubGrafo(pDGrafo, pDGrafo, FuncaoComparacao);

// Um grafo é dito conexo se existir pelo menos um caminho entre
// cada par de vértices do grafo. Caso contrário, o grafo é chamado
// de desconexo.
int        grafoConexo(pDGrafo, FuncaoComparacao);

// Um grafo G é bipartido se seus vértices podem ser separados
// em dois conjuntos independentes de tal forma que todas
// arestas do grafo conectam vértices de conjuntos distintos.
int        grafoBipartido(pDGrafo, FuncaoComparacao);

int        existeCaminhoHamiltoniano (pDGrafo, FuncaoComparacao);
int        existeCaminhoEuleriano    (pDGrafo, FuncaoComparacao); // pontes de Königsberg

// Uma coloração de um grafo é válida se as duas pontas de cada aresta
// têm cores diferentes.
int        coloracao(pDGrafo);

// Um emparelhamento (= matching) num grafo não-dirigido G é um
// conjunto M de arestas dotado da seguinte propriedade:
// todo vértice de G incide em no máximo um elemento de M.
// (Um laço não pode fazer parte de um emparelhamento porque incide
// duas vezes em um mesmo vértice.)
// Pode-se dizer que um emparelhamento é um conjunto de arestas duas a duas
// independentes
pDLista    emparelhamento(pDGrafo);



// ----------------------------------------------
// ----------------------------------------------
// ----------------------------------------------

// é o conjunto de todos os vértices que têm algum vizinho na lista de vertices
pDLista    vizinhanca(pDGrafo, pDLista);

// é o conjunto de todas as arestas que têm uma ponta em um vértice da
// lista de vertices
pDLista    corte(pDGrafo, pDLista);

int        isomorfos(pDGrafo, pDGrafo);  // complexidade de ordem fatorial

int        grafoRegular(pDGrafo);

// Um conjunto de vértices de um grafo é estável, se seus elementos são dois a dois
// não-adjacentes, ou seja, se nenhuma aresta tem ambas as pontas no conjunto.
pDLista    conjuntosEstaveis(pDGrafo);

// Um conjunto estável X é maximal se não faz parte de um conjunto estável maior
pDLista    conjuntoEstavelMaximal(pDGrafo);
pDLista    conjuntosEstaveisMaximos(pDGrafo);

//Uma clique ou conjunto completo num grafo é qualquer conjunto de vértices dois
//a dois adjacentes
pDLista    clique(pDGrafo);

// Uma cobertura de um grafo é qualquer conjunto de vértices que contenha
// pelo menos uma das pontas de cada aresta.
pDLista    coberturas(pDGrafo);

#endif

