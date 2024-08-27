#ifndef EXCLUIRINFOTRIE_H_INCLUDED
#define EXCLUIRINFOTRIE_H_INCLUDED

/*----------------------------*/
bool nohTemFilhos(Noh *noh) {
  if (noh == NULL) return false;

  for (int i = 0; i < NUM_CHARS; i++) {
    if (noh->filhos[i] != NULL) {
      return true;
    }
  }
  return false;
}
/*----------------------------*/
Noh *excluirInfoTRIERecursivo(Noh *noh, unsigned char *texto, bool *deletado) {
  if (noh == NULL) return noh;

  if (*texto == '\0') {
    if (noh->terminal) {
      noh->terminal = false;
      *deletado = true;

      if (nohTemFilhos(noh) == false) {
        free(noh);
        noh = NULL;
      }
    }
    return noh;
  }

  noh->filhos[texto[0]] =
      excluirInfoTRIERecursivo(noh->filhos[texto[0]], texto + 1, deletado);

  if (*deletado && nohTemFilhos(noh) == false && noh->terminal == false) {
    free(noh);
    noh = NULL;
  }
  return noh;
}

bool excluirInfoTRIE(Noh **raiz, char *textoComSinal) {
  unsigned char *texto = (unsigned char *)textoComSinal;
  bool resultado = false;

  if (*raiz == NULL) return false;

  *raiz = excluirInfoTRIERecursivo(*raiz, texto, &resultado);
  return resultado;
}

#endif  // EXCLUIRINFOTRIE_H_INCLUDED
