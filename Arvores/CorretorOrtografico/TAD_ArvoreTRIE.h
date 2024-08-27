#ifndef TAD_ARVORETRIE_H_INCLUDED
#define TAD_ARVORETRIE_H_INCLUDED
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */
typedef struct Noh Noh;
//typedef Noh* pNoh;

/* descritor da arvore */
// Não tenho por enquanto

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
Noh* criarNoh();

bool incluirInfoTRIE(Noh**, char*);
void imprimirArvoreTRIE(Noh*);
bool buscarInfoTRIE(Noh*, char*);
bool excluirInfoTRIE(Noh**, char*);
void buscarSugestoesTRIE(Noh*, unsigned char*, int, char*, int, int*, char**, int*);
void corrigirPalavra(Noh*, char*);
int distanciaLevenshtein(const char*, const char*);
void carregarDicionario(Noh**, const char*);

#endif // TAD_ARVORETRIE_H_INCLUDED
