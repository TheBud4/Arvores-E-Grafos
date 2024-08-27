#ifndef CORRIGIRPALAVRA_H_INCLUDED
#define CORRIGIRPALAVRA_H_INCLUDED

void corrigirPalavra(Noh* raiz, char* palavra)
{
    int distanciaMaxima = 2; // Ajustar a distância conforme necessário
    char* sugestoes[3] = {NULL, NULL, NULL};
    int contadorSugestoes = 0;
    unsigned char prefixo[strlen(palavra) + 1];
    int distanciaAtual = 0;

    buscarSugestoesTRIE(raiz, prefixo, 0, palavra, distanciaMaxima, &distanciaAtual, sugestoes, &contadorSugestoes);

    if (contadorSugestoes == 0)
    {
        printf("Nenhuma sugestão encontrada.\n");
        return;
    }

    printf("Sugestões:\n");
    for (int i = 0; i < contadorSugestoes; i++)
    {
        printf("%d: %s\n", i + 1, sugestoes[i]);
    }

    int escolha;
    printf("Escolha uma sugestão (1-%d): ", contadorSugestoes);
    scanf("%d", &escolha);

    if (escolha >= 1 && escolha <= contadorSugestoes)
    {
        strcpy(palavra, sugestoes[escolha - 1]);
        printf("Palavra corrigida: %s\n", palavra);
    }
    else
    {
        printf("Escolha inválida.\n");
    }

    for (int i = 0; i < contadorSugestoes; i++)
    {
        free(sugestoes[i]);
    }
}

#endif // CORRIGIRPALAVRA_H_INCLUDED
