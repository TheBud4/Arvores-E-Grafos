#ifndef BUSCARSUGESTOESTRIE_H_INCLUDED
#define BUSCARSUGESTOESTRIE_H_INCLUDED

void buscarSugestoesTRIE(Noh* noh, unsigned char* prefixo, int tamanhoPrefixo,
                         char* palavraOriginal, int distanciaMaxima,
                         int* distanciaAtual, char** sugestoes,
                         int* contadorSugestoes) {
  if (noh == NULL || *contadorSugestoes >= 3) return;

  if (noh->terminal && *distanciaAtual <= distanciaMaxima) {
    sugestoes[*contadorSugestoes] = strdup((char*)prefixo);
    (*contadorSugestoes)++;
  }

  if (tamanhoPrefixo > strlen(palavraOriginal)) return;

  for (int i = 0; i < NUM_CHARS; i++) {
    if (noh->filhos[i] != NULL) {
      int novaDistancia =
          *distanciaAtual + (palavraOriginal[tamanhoPrefixo] != i);
      if (novaDistancia <= distanciaMaxima) {
        prefixo[tamanhoPrefixo] = i;
        buscarSugestoesTRIE(noh->filhos[i], prefixo, tamanhoPrefixo + 1,
                            palavraOriginal, distanciaMaxima, &novaDistancia,
                            sugestoes, contadorSugestoes);
      }
    }
  }
}

#endif  // BUSCARSUGESTOESTRIE_H_INCLUDED
