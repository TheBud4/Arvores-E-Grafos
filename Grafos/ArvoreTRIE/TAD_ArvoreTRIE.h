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

#endif // TAD_ARVORETRIE_H_INCLUDED
