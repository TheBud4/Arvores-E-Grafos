#include "./ArvoreTRIE.h"

int main() {
  Noh *raiz = NULL;
  // ATENCAO !!!!
  carregarDicionario(&raiz, "../dicionairo.txt");
  char palavra[256];

  printf("Digite uma palavra para verificar: ");
  scanf("%s", palavra);

  if (incluirInfoTRIE(&raiz, palavra)) {
    corrigirPalavra(raiz, palavra);
  } else {
    printf("Palavra ja esta correta.\n");
  }

  return 0;
}
