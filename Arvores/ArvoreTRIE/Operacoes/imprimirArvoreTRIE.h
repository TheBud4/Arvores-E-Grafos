#ifndef IMPRIMIRARVORETRIE_H_INCLUDED
#define IMPRIMIRARVORETRIE_H_INCLUDED
// Nesse procedimento ele retorna as palavras presentes na árvore
// Não imprime uma estrutura de árvore
// Se sobrar tempo eu tento
void imprimirArvoreTRIERecursivo(Noh *noh, unsigned char *prefixo, int tamanho)
{
    unsigned char novoPrefixo[tamanho+2];
    memcpy(novoPrefixo, prefixo, tamanho);
    novoPrefixo[tamanho+1]= 0 ;

    if(noh->terminal)
    {
        printf("Palavra: %s\n", prefixo);
    }

    for(int i = 0; i < NUM_CHARS; i++)
    {
        if(noh->filhos[i] != NULL)
        {
            novoPrefixo[tamanho] = i;
            imprimirArvoreTRIERecursivo(noh->filhos[i], novoPrefixo, tamanho+1);
        }
    }
}


void imprimirArvoreTRIE(Noh *raiz)
{
    if(raiz == NULL)
    {
        printf("Arvore vazia\n");
        return;
    }
    unsigned char prefixo[1] = {0};
    imprimirArvoreTRIERecursivo(raiz, prefixo, 0);
}

#endif // IMPRIMIRARVORETRIE_H_INCLUDED
