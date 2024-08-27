#ifndef DISTANCIALEVENSHTEIN_H_INCLUDED
#define DISTANCIALEVENSHTEIN_H_INCLUDED

int distanciaLevenshtein(const char* palavra1, const char* palavra2) {
  int len1 = strlen(palavra1);
  int len2 = strlen(palavra2);
  int matriz[len1 + 1][len2 + 1];

  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      if (i == 0) {
        matriz[i][j] = j;
      } else if (j == 0) {
        matriz[i][j] = i;
      } else if (palavra1[i - 1] == palavra2[j - 1]) {
        matriz[i][j] = matriz[i - 1][j - 1];
      } else {
        int insert = matriz[i][j - 1] + 1;
        int delete = matriz[i - 1][j] + 1;
        int replace = matriz[i - 1][j - 1] + 1;
        matriz[i][j] = fmin(insert, fmin(delete, replace));
      }
    }
  }

  return matriz[len1][len2];
}

#endif  // DISTANCIALEVENSHTEIN_H_INCLUDED
