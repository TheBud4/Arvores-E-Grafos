#include <stdio.h>
#include <stdlib.h>

#include "../Cap3/Utils.h"
#include "./Grafo.h"
#include "Utils.h"


int comparaVertice(void *info1, void *info2) {
  pVertice v1 = (pVertice)info1;
  pVertice v2 = (pVertice)info2;

  int *id1 = (int *)v1->info;
  int *id2 = (int *)v2->info;

  return *id2 - *id1;
}

/* ----------------------------- */
int chamadaConexo(pDGrafo grafo, FuncaoComparacao pfc, FuncaoImpressao pfi) {
  char resp = ehConexo(grafo, pfc, pfi);
  if (resp == 'a') {
    printf("\n   O grafo e conexo\n");
    return 1;
  } else {
    printf("\n   Nao conexo\n");
    return 0;
  }
}
/* ----------------------------- */
void imprimeAdjacencia(void *info1) {
  pVertice v = (pVertice)info1;
  printf("%d - ", *((int *)(v->info)));
}

/* ----------------------------- */
void imprimeVertice(void *info1) {
  pVertice v = (pVertice)info1;
  printf("\nVertice %d - Adjacencias [", *((int *)v->info));
  imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
  printf("]\n");
}

/* ----------------------------- */
void imprimeVerticeSemAdjacencias(void *info1) {
  pVertice v = (pVertice)info1;
  printf("\nVertice %d - ", *((int *)v->info));
}

/* ---------------------------------------- */
void *alocaInfoVertice(void *info) {
  pVertice pv = (pVertice)malloc(sizeof(Vertice));
  pv->info = alocaInfoInt(((pVertice)info)->info);
  return pv;
}
/* ---------------------------------------- */
void imprimeVerticeLargura(void *info1) {
  pVertice v = (pVertice)info1;
  printf("%d ", *((int *)v->info));
}
/* ---------------------------------------- */
void main() {
  int vertices[] = {1, 2, 3, 4, 5};
  char resp;
  int opcao, vOrigem, result, vDestino;
  int *pv;

  pDGrafo grafo = criarGrafo();

  do {
    printf("\n  1   - Criar grafo \n");
    printf("  2   - Incluir Vertice \n");
    printf("  3   - Incluir Aresta \n");
    printf("  4   - Excluir Vertice  \n");
    printf("  5   - Excluir Aresta   \n");
    printf("  6   - Mostrar grafo \n");
    printf("  7   - Busca em profundidade \n");
    printf("  8   - Busca em amplitude \n");
    printf("  9   - Existe caminho?  (entre dois vertices) \n");
    printf("  10   - Encontra caminho (entre dois vertices) \n");
    printf("  11  - Eh hamiltoniano? \n");
    printf("  12  - Eh euleriano?\n");
    printf("  13  - Conexo?\n");
    printf("  14  - Bipartido?\n");
    printf("  15  - Coloracao\n");
    printf("  16  - Emparelhamento\n");

    printf("  0 - Sair \n");

    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        incluirVertice(grafo, &vertices[0], comparaVertice);
        incluirVertice(grafo, &vertices[1], comparaVertice);
        incluirVertice(grafo, &vertices[2], comparaVertice);
        incluirVertice(grafo, &vertices[3], comparaVertice);
        incluirVertice(grafo, &vertices[4], comparaVertice);

        incluirAresta(grafo, &vertices[0], &vertices[2], comparaVertice);
        incluirAresta(grafo, &vertices[0], &vertices[3], comparaVertice);
        incluirAresta(grafo, &vertices[1], &vertices[2], comparaVertice);
        incluirAresta(grafo, &vertices[1], &vertices[4], comparaVertice);
        incluirAresta(grafo, &vertices[2], &vertices[0], comparaVertice);
        incluirAresta(grafo, &vertices[2], &vertices[1], comparaVertice);
        incluirAresta(grafo, &vertices[3], &vertices[0], comparaVertice);
        incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice);
        incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);
        incluirAresta(grafo, &vertices[1], &vertices[0], comparaVertice);
        incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice);
        incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice);
        incluirAresta(grafo, &vertices[2], &vertices[4], comparaVertice);
        incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice);
        incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice);
        incluirAresta(grafo, &vertices[4], &vertices[0], comparaVertice);
        incluirAresta(grafo, &vertices[0], &vertices[2], comparaVertice);
        incluirAresta(grafo, &vertices[3], &vertices[2], comparaVertice);

        mostrarGrafo(grafo, imprimeVertice);
        break;

      case 2:

        pv = (int *)malloc(sizeof(int));
        printf("ID do v�rtice : ");
        scanf("%d", pv);
        incluirVertice(grafo, pv, comparaVertice);

        mostrarGrafo(grafo, imprimeVertice);
        break;

      case 3:

        printf("\nID do v�rtice origem : ");
        scanf("%d", &vOrigem);
        printf("\nID do v�rtice destino : ");
        scanf("%d", &vDestino);
        incluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

        mostrarGrafo(grafo, imprimeVertice);
        break;

      case 4:
        printf("ID do v�rtice a ser exclu�do: ");
        scanf("%d", &vOrigem);

        excluirVertice(grafo, &vOrigem, comparaVertice);

        mostrarGrafo(grafo, imprimeVertice);
        break;

      case 5:
        printf("\nID do v�rtice origem : ");
        scanf("%d", &vOrigem);
        printf("\nID do v�rtice destino : ");
        scanf("%d", &vDestino);
        excluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

        mostrarGrafo(grafo, imprimeVertice);
        break;

      case 6:
        mostrarGrafo(grafo, imprimeVertice);
        break;

      case 7:
        buscaEmProfundidade(grafo, comparaVertice,
                            imprimeVerticeSemAdjacencias);
        break;

      case 8:
        // Come�a a busca em amplitude a partir do primeiro v�rtice
        if (grafo->listaVertices->primeiro != NULL) {
          buscaAmplitude(grafo, comparaVertice, imprimeVerticeLargura);
        } else {
          printf("O grafo est� vazio!\n");
        }
        break;
      case 9:
        printf("\nID do v�rtice origem : ");
        scanf("%d", &vOrigem);
        printf("\nID do v�rtice destino : ");
        scanf("%d", &vDestino);

        int result = existeCaminho(grafo, &vOrigem, &vDestino, comparaVertice);
        // existe um caminho
        if (result != 0)
          printf("Existe caminho!");
        else
          printf("N�o existe caminho!");

        break;

      case 10:
        printf("\nID do vertice origem : ");
        scanf("%d", &vOrigem);
        printf("\nID do vertice destino : ");
        scanf("%d", &vDestino);

        pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino, comparaVertice,
                                     alocaInfoVertice);
        if (caminho->quantidade > 0) {
          printf("\n Existe um caminho: ");
          imprimirLista(caminho, imprimeVerticeSemAdjacencias);
        } else
          printf("\n *** NaO existe um caminho. *** ");
        break;

      case 11:
        result = ehHamilton(grafo, comparaInt);
        if (result == 0) {
          printf("\n   Grafo eh hamiltoniano");
        } else
          printf("\n   Nao hamiltoniano");
        break;

      case 12:
        result = ehEuleriano(grafo, comparaInt, imprimeVerticeSemAdjacencias);
        if (result == 1)
          printf("\n   O grafo e eulariano");
        else
          printf("\n  O grafo nao e euleriano");
        break;

      case 13:
        chamadaConexo(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
        break;

      case 14:
        result =
            chamadaConexo(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
        if (result == 0) {
          printf("\n   Grafo nao e bipartido\n");
        } else {
          result = acharBi(grafo, comparaInt, imprimeInt);
          if (result == 1) {
            printf("\n   Grafo e bipartido\n");
          } else
            printf("\n   Grafo nao e bipartido\n");
        }
        break;

      case 15:
        coloracao(grafo, 3);
        break;
      case 16:
        emparelhamentoBuscaLocal(grafo, comparaVertice);
        break;
    
    }

  } while (opcao != 0);
}
