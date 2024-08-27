#ifndef INCLUIRINFOTRIE_H_INCLUDED
#define INCLUIRINFOTRIE_H_INCLUDED

bool incluirInfoTRIE(Noh **raiz, char *textoComSinal) {
    
  if (*raiz == NULL) {
    *raiz = criarNoh();
  }

  unsigned char *texto = (unsigned char *)textoComSinal;
  Noh *temp = *raiz;
  int tamanho = strlen(textoComSinal);

  for (int i = 0; i < tamanho; i++) {
    if (texto[i] < 0 || texto[i] >= NUM_CHARS) {
      printf("Caracter fora do limite: %d\n", texto[i]);
      return false;
    }
    if (temp->filhos[texto[i]] == NULL) {
      temp->filhos[texto[i]] = criarNoh();
    }
    temp = temp->filhos[texto[i]];
  }
  if (temp->terminal) {
    return false;
  } else {
    temp->terminal = true;
    return true;
  }
}

#endif  // INCLUIRINFOTRIE_H_INCLUDED
