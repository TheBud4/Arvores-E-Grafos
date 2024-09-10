#ifndef STRUCT_NOH_BTREE_H
#define STRUCT_NOH_BTREE_H

struct nohBTree;

//----------------------------
struct chaveValor {
  void* chave;                  // s
  void* valor;                  // I
  struct nohBTree* filhoMaior;  // p
};

// cada n� da �rvore B possui k chaves e k+1 filhos,
// onde  d <= k <= 2d
//----------------------------
struct nohBTree {
  // lista com as chaves e os valores do nó
  pDLista listaChavesValores;

  struct nohBTree* primeiroFilho;  // p0

  // apontamento para o pai para facilitar a implementa��o das
  // opera��es de particionamento, concatena��o e redistribui��o
  struct nohBTree* pai;
};

#endif
