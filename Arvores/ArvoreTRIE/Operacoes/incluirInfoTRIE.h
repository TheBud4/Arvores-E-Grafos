#ifndef INCLUIRINFOTRIE_H_INCLUDED
#define INCLUIRINFOTRIE_H_INCLUDED

bool incluirInfoTRIE(Noh **raiz, char *textoComSinal) {
  if (*raiz == NULL) {
    *raiz = criarNoh();
  }

  //printf("Chegou aqui incluir 1\n");
  unsigned char *texto = (unsigned char *)textoComSinal;
  Noh *temp = *raiz;
  int tamanho = strlen(textoComSinal);

  for (int i = 0; i < tamanho; i++) {
    // if (texto[i] < 0 || texto[i] >= NUM_CHARS) {
    //   printf("Caracter fora do limite: %d\n", texto[i]);
    //   return false;  // Tratar ou ignorar caracteres inv�lidos
    // }
    if (temp->filhos[texto[i]] == NULL) {
      //printf("Chegou aqui incluir 2\n");
      temp->filhos[texto[i]] = criarNoh();
    }
    temp = temp->filhos[texto[i]];
  }
  //printf("Chegou aqui incluir 3\n");
  if (temp->terminal) {
    //printf("Chegou aqui incluir 4\n");
    return false;
  } else {
    //printf("Chegou aqui incluir 5\n");
    temp->terminal = true;
    return true;
  }
}

#endif  // INCLUIRINFOTRIE_H_INCLUDED
