#ifndef NOHTRIE_H_INCLUDED
#define NOHTRIE_H_INCLUDED

#define NUM_CHARS 256

typedef struct Noh {
  struct Noh* filhos[NUM_CHARS];
  bool terminal;
} Noh;

Noh* criarNoh() {
  Noh* novoNoh = malloc(sizeof(Noh));

  if (novoNoh == NULL) {
    printf("Erro ao alocar memoria para Noh");
    return novoNoh;
  }

  for (int i = 0; i < NUM_CHARS; i++) {
    novoNoh->filhos[i] = NULL;
  }

  novoNoh->terminal = false;
  return novoNoh;
}

#endif  // NOHTRIE_H_INCLUDED
