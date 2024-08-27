#ifndef CARREGARDICIONARIO_H_INCLUDED
#define CARREGARDICIONARIO_H_INCLUDED

void carregarDicionario(Noh** raiz, const char* caminhoDicionario) {

  FILE* arquivo = fopen(caminhoDicionario, "r");

  if (arquivo == NULL) {
    printf("Erro ao abrir o dicionario.\n");
    return;
  }


  char palavra[256];

  while (fgets(palavra, sizeof(palavra), arquivo)) {
    palavra[strcspn(palavra, "\n")] = 0;
    incluirInfoTRIE(raiz, palavra);
  }

  fclose(arquivo);
}

#endif  // CARREGARDICIONARIO_H_INCLUDED
